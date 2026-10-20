#include "ManualNotchUI.h"
#include <string>
#include <fmt/core.h>
#include <vector>
#include <sstream>
#include <string>
#include <thread>
#include <windows.h>
#include "QtFT891.h"


ManualNotchUI::ManualNotchUI(const QObject* parent) : m_parent((QtFT891*)parent)
{

	ui.setupUi(this);
	solidb.setColor(Qt::black);
	solidr.setColor(Qt::red);
	solidb.setStyle(Qt::BrushStyle::SolidPattern);
	solidr.setStyle(Qt::BrushStyle::SolidPattern);
	solidBlack.setBrush(solidb);
	solidBlack.setWidth(3);
	solidBlack.setStyle(Qt::PenStyle::SolidLine);
	solidRed.setBrush(solidr);
	solidRed.setWidth(3);
	solidRed.setStyle(Qt::PenStyle::SolidLine);
	auto rect = ui.graphicsView->geometry();
	m_scene = std::make_unique<QGraphicsScene>(rect, this);
	ui.graphicsView->setScene(m_scene.get());
	ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	connect(ui.cbIFNotch, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &ManualNotchUI::on_cbIFNotchActivated);
}

ManualNotchUI::~ManualNotchUI()
{
	
}

void ManualNotchUI::SetLevel(int level)
{
	ui.hsNotchFreq->setValue(level);

}

int ManualNotchUI::GetLevel()
{
	return ui.hsNotchFreq->value();
}

void ManualNotchUI::SetWidth(Yaesu::Commands::FT891::IFNotchWidth val)
{
	m_notchWidth = val;
	drawScene();
}


void ManualNotchUI::drawScene()
{

	float notchWidth;
	switch (m_notchWidth)
	{
	case Yaesu::Commands::FT891::IFNotchWidth::NARROW:
		notchWidth = 10.0f;
		break;
	case Yaesu::Commands::FT891::IFNotchWidth::WIDE:
		notchWidth = 20.0f;
		break;
	default:
		notchWidth = 0.0f;
		break;

	}

	float percent = 0.0f;
	float notchCenter = 0.0f;
	float ltop = 0.0f;
	QRect scenerect;
	scenerect = ui.graphicsView->geometry();
	auto scene = ui.graphicsView->scene();
	ltop = (float)scenerect.top() + ((float)scenerect.height() / 2.0);
	centerVert.setLine((float)scenerect.width() / 2.0f, scenerect.bottom(), (float)scenerect.width() / 2.0f, scenerect.top());

	percent = ((float)ui.hsNotchFreq->value() / 320.0f);
	notchCenter = ((float)scenerect.width() * percent);
	
	float leflineRight;

	leflineRight = (notchCenter - notchWidth);
	
	leftLine.setLine(0.0f, ltop, leflineRight, ltop);
	rightLine.setLine(notchCenter + notchWidth, ltop, scenerect.right(), ltop);

	leftDiag.setLine(notchCenter - notchWidth, ltop, notchCenter, scenerect.bottom());
	rightDiag.setLine(notchCenter, scenerect.bottom(), notchCenter + notchWidth, ltop);
	
	scene->clear();
	scene->addLine(leftLine, solidBlack);
	scene->addLine(rightLine, solidBlack);
	
	scene->addLine(rightDiag, solidBlack);
	scene->addLine(leftDiag, solidBlack);

	scene->addLine(centerVert, solidRed);

}

void ManualNotchUI::on_hsNotchFreq_valueChanged(int val)
{
	auto freqstr = fmt::format("{:d}Hz", val * 10);
	ui.lblFreq->setText(freqstr.c_str());

	drawScene();
	if (QApplication::mouseButtons() != Qt::NoButton) {
		emit on_level_changed(val);
	}
}

void ManualNotchUI::on_cbIFNotchActivated(int val)
{
	m_parent->on_cbIFNotchActivated(val);
}

