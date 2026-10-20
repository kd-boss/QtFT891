#include "MemoryChannelEditorUI.h"
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include "QtFT891.h"
#include <QKeyEvent>
#include <fmt/format.h>

MemoryChannelEditorUI::MemoryChannelEditorUI(QWidget* parent) : m_model(100,6,this), QDialog(parent)
{
	ui.setupUi(this);
	ui.tableView->setModel(&m_model);
	connect(ui.buttonBox_2, &QDialogButtonBox::clicked, this, &MemoryChannelEditorUI::clicked);
	connect(ui.btnAddRow_2, &QPushButton::clicked, this, &MemoryChannelEditorUI::btnAddRow_2_clicked);
	QList<QString> headers = { "Channel", "Frequency", "Mode", "Operation","Clarifier Enabled","Clarifier Value", "CTCSS Type", "Tag", "Tag Name"};
	m_model.setHorizontalHeaderLabels(headers);
	ui.tableView->installEventFilter(this);
}

MemoryChannelEditorUI::~MemoryChannelEditorUI()
{

}

bool MemoryChannelEditorUI::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* key = reinterpret_cast<QKeyEvent*>(event);
		if ((key->key() == Qt::Key_Enter) || (key->key() == Qt::Key_Return)) {
			btnAddRow_2_clicked();
		}
		else {
			return QObject::eventFilter(obj, event);
		}
		return true;
	}
	else {
		return QObject::eventFilter(obj, event);
	}
	return false;
}

void MemoryChannelEditorUI::btnAddRow_2_clicked()
{

	Yaesu::Commands::FT891::MemoryChannelTagValue val {};
	val.TagString.clear();
	val.MemoryChannel = static_cast<Yaesu::Commands::FT891::MemoryChannelValue>(m_channels.size() + 1);
	AddMemoryChannel(val);

}

void MemoryChannelEditorUI::AddMemoryChannel(Yaesu::Commands::FT891::MemoryChannelTagValue& val)
{
	m_channels.push_back(val);

	std::string dispval = fmt::format("{:d}.{:03}.{:03}", (val.VFOAFreq - (val.VFOAFreq % 1000000)) / 1000000, ((val.VFOAFreq % 1000000) - (val.VFOAFreq % 1000)) / 1000, (val.VFOAFreq % 1000));

	m_model.setItem((quint32)val.MemoryChannel - 1, 0, new QStandardItem(QString::number((quint32)val.MemoryChannel)));
	//m_model.setItem((quint32)val.MemoryChannel - 1, 1,new QStandardItem(QString::number(val.VFOAFreq)));
	ui.tableView->setIndexWidget(m_model.index((quint32)val.MemoryChannel - 1,1), new QLineEdit{ dispval.c_str() ,nullptr});
	ui.tableView->indexWidget(m_model.index((quint32)val.MemoryChannel - 1, 1))->setFocus();
	m_model.setItem((quint32)val.MemoryChannel - 1, 2,new QStandardItem(QString::number((quint32)val.Mode)));	
	auto combox = new QComboBox();
	QStringList items = { "LSB","USB","CW","FM","AM","RTTY_LSB","CW_R","DATA_LSB","RTTY_USB","FM_N","DATA_USB","AM_N" };
	combox->addItems(items);
	int idx = (quint32)val.Mode;
	idx = idx >= 11 ? idx - 2 : idx - 1;
	combox->setCurrentIndex(idx);
	ui.tableView->setIndexWidget(m_model.index((quint32)val.MemoryChannel - 1, 2), combox);

	QStringList operationTypes = {"Simplex", "Plus Shift", "Minus Shift"};
	auto opcombox = new QComboBox();
	opcombox->addItems(operationTypes);
	opcombox->setCurrentIndex((qint32)val.Operation);
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 3), opcombox);
	
	auto clarstate = new QCheckBox(this);
	clarstate->setChecked(val.Clarifier == Yaesu::Commands::FT891::ClarifierState::ON);
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 4), clarstate);

	QValidator* validator = new QIntValidator(-9999, 9999, this);
	auto clarifierval = new QLineEdit(this);
	clarifierval->setValidator(validator);
	clarifierval->setText(QString::number(val.ClarifierFreq));
	clarifierval->setEnabled(clarstate->isChecked());
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 5), clarifierval);
	connect(clarstate, &QCheckBox::stateChanged, clarifierval, &QLineEdit::setEnabled);

	QStringList ctcsstypes = { "OFF","ENC/DEC", "ENC" };
	auto ctcsscombo = new QComboBox();
	ctcsscombo->addItems(ctcsstypes);
	ctcsscombo->setCurrentIndex((qint32)val.CTCSS);
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 6), ctcsscombo);

	auto tagstate = new QCheckBox(this);
	tagstate->setChecked(val.TAG == Yaesu::Commands::FT891::TagValue::ON);
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 7), tagstate);

	auto tagValue = new QLineEdit(this);
	if (tagstate->isChecked()) 
	{
		tagValue->setText(QString(val.TagString.c_str()));
	}
	tagValue->setEnabled(tagstate->isChecked());
	connect(tagstate, &QCheckBox::stateChanged, tagValue, &QLineEdit::setEnabled);
	ui.tableView->setIndexWidget(m_model.index((qint32)val.MemoryChannel - 1, 8), tagValue);
	
}

void MemoryChannelEditorUI::clicked(QAbstractButton* button)
{
	using namespace Yaesu::Commands::FT891;
	auto buttonType = ui.buttonBox_2->standardButton(button);
	auto parent = (QtFT891*)this->parent();
	switch(buttonType)
	{
	case QDialogButtonBox::StandardButton::Ok:
		for (auto val : m_channels) 
		{
			
		 
			qint32 i = (qint32)val.MemoryChannel;
			auto vfoptr = ui.tableView->indexWidget(m_model.index(i  -1 ,1));
			if (vfoptr != nullptr) 
			{
					auto vfofreqptr = qobject_cast<QLineEdit *>(vfoptr);
					auto txt = vfofreqptr->text();
					txt.remove(".");
					val.VFOAFreq = txt.toInt();
			}
			
			if (val.VFOAFreq != 0) {
				int modeval = ((QComboBox*)ui.tableView->indexWidget(m_model.index(i - 1, 2)))->currentIndex();
				//idx = idx >= 11 ? idx - 2 : idx - 1;
				modeval = modeval >= 9 ? modeval += 2 : modeval += 1;
				val.Mode = static_cast<MemoryChannelModeValue>(modeval);
				val.Operation = static_cast<OperationType>(((QComboBox*)ui.tableView->indexWidget(m_model.index(i - 1, 3)))->currentIndex());
				val.Clarifier = static_cast<ClarifierState>(((QCheckBox*)ui.tableView->indexWidget(m_model.index(i -1, 4)))->isChecked() ? 1 : 0);
				val.ClarifierFreq = val.Clarifier == ClarifierState::OFF ? 0 : ((QLineEdit*)ui.tableView->indexWidget(m_model.index( i - 1, 5)))->text().toInt();
				val.CTCSS = static_cast<CTCSSState>(((QComboBox*)ui.tableView->indexWidget(m_model.index(i - 1, 6)))->currentIndex());
				val.TAG = static_cast<TagValue>(((QCheckBox*)ui.tableView->indexWidget(m_model.index(i - 1, 7)))->isChecked() ? 1 : 0);
				if (val.TAG == Yaesu::Commands::FT891::TagValue::ON)
				{
					auto tagstrptr = qobject_cast<QLineEdit *>(ui.tableView->indexWidget(m_model.index(i - 1, 8)));
					auto txt = tagstrptr->text();
					auto arr = txt.toUtf8();
					val.TagString = std::string(arr.constData(), arr.length());
				}
				auto cmd = Yaesu::Commands::FT891::MemoryWriteTag::Set(val);
				
				parent->m_radio->write(cmd.c_str(), cmd.length());
				parent->m_radio->flush();
		
			}
		}
		m_channels.clear();
		m_model.clear();
		this->close();
		break;
	case QDialogButtonBox::StandardButton::Cancel:
		m_channels.clear();
		m_model.clear();
		
		break;
	}
	
}
