#include "Contour.h"
#include <fmt/core.h>
#include <vector>
#include <sstream>
#include <string>
#include <thread>
#include "QtFT891.h"

ContourUI::ContourUI(const QObject& parent) : QDialog((QWidget*)&parent)
{
	this->parent = (QObject*)&parent;
	ui.setupUi(this);
	solidblackBrush.setColor(Qt::black);
	solidblackBrush.setStyle(Qt::BrushStyle::SolidPattern);
	solidBlackPen.setBrush(solidblackBrush);
	solidBlackPen.setWidth(3);
	solidBlackPen.setStyle(Qt::PenStyle::SolidLine);
	auto rect = ui.graphicsView->geometry();
	m_scene = new QGraphicsScene(rect, this);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

ContourUI::~ContourUI()
{
	((QtFT891*)this->parent)->UpdateContourRecord();
	auto pthis = static_cast<ContourUI*>(this);

	pthis = nullptr;
}

void ContourUI::drawScene()
{
	m_scene->clear();
	float ltop = 0.0f;
	float elipsewidth = 0.0f;
	QRect scenerect;
	scenerect = ui.graphicsView->geometry();
	auto scene = ui.graphicsView->scene();
	ltop = (float)scenerect.top() + ((float)scenerect.height() / 2.0);
	auto elipcenter = ((float)scenerect.width() / (float)(3190)) * (float)ui.hsContourFreq->value();
	elipsewidth = ((float)scenerect.width() / (float)ui.hsContourFreq->maximum()) * ((float)ui.hsContourWidth->value() * 50.0f);
	LeftLine.setLine(0.0f, ltop, elipcenter - (elipsewidth / 2.0), ltop);
	RightLine.setLine(elipcenter + (elipsewidth / 2.0), ltop, scenerect.right() + elipcenter + (elipsewidth / 2.0), ltop);
	QRectF elipsebounds(LeftLine.x2(), ltop - ((((float)scenerect.height() / 40.0f) * (std::abs(ui.vsContourLevel->value()))) / 2.0), elipsewidth, (((float)scenerect.height() / 40.0f) * (std::abs(ui.vsContourLevel->value()))));
	m_scene->addLine(LeftLine);
	auto elipse = m_scene->addEllipse(elipsebounds, solidBlackPen);

	if (ui.vsContourLevel->value() > 0)
	{
		elipse->setStartAngle(180 * 16);
		elipse->setSpanAngle(-180 * 16);
	}
	else
	{
		elipse->setStartAngle(-180 * 16);
		elipse->setSpanAngle(180 * 16);
	}
	
	m_scene->addLine(RightLine);
}

void ContourUI::SetFreq(int val)
{
	if (QApplication::mouseButtons() == Qt::NoButton)
	{
		std::string freq = fmt::format("{:d}Hz", val);
		ui.lblFreq->setText(freq.c_str());
		ui.hsContourFreq->setValue(val);
		
	}
	drawScene();
}

void ContourUI::SetLevel(int val)
{
	if (QApplication::mouseButtons() == Qt::NoButton)
	{
		std::string freq = fmt::format("{:d} db", val);
		ui.lblContourLevel->setText(freq.c_str());
		ui.vsContourLevel->setValue(val);
	}
	drawScene();
}

void ContourUI::SetWidth(int val)
{
	if (QApplication::mouseButtons() == Qt::NoButton)
	{
		std::string freq = fmt::format("{:d}", val);
		ui.lblContourWidth->setText(freq.c_str());
		ui.hsContourWidth->setValue(val);
	}
	drawScene();
}



void ContourUI::on_hsContourFreq_valueChanged(int val)
{
	std::string freq = fmt::format("{:d}Hz", val);
	ui.lblFreq->setText(freq.c_str());	 
	emit on_ContourFrequency_valueChanged(val);	
	drawScene();
}

void ContourUI::on_vsContourLevel_valueChanged(int val)
{
	std::string freq = fmt::format("{:d} db", val);
	ui.lblContourLevel->setText(freq.c_str());
	emit on_ContourLevel_valueChanged(val);	
	drawScene();
}

void ContourUI::on_hsContourWidth_valueChanged(int val)
{
	std::string freq = fmt::format("{:d}", val);
	ui.lblContourWidth->setText(freq.c_str());
	emit on_ContourWidth_valueChanged(val);	
	drawScene();
}

void ContourUI::on_OkButton_clicked()
{
	this->close();
}
