#pragma once
#pragma once
#include "ui_Contour.h"
#include "Cat.h"
#include <QGraphicsLineItem>
#include <QPointer>
#include <QPen>
#include <QDialog>



class ContourUI : public QDialog
{
	Q_OBJECT
public:
	ContourUI(const QObject& parent);
	~ContourUI();

	void SetFreq(int val);
	void SetLevel(int val);
	void SetWidth(int val);

	void drawScene();
	QLineF LeftLine;
	QLineF RightLine;	
	QBrush solidblackBrush;
	QPen solidBlackPen;

	QObject* parent;
signals:
	void on_ContourFrequency_valueChanged(int val);
	void on_ContourLevel_valueChanged(int val);
	void on_ContourWidth_valueChanged(int val);

private:
	int m_freq;
	int m_level;
	int m_width;
	Ui::ContourUI ui;
	QPointer<QGraphicsScene> m_scene;
	QGraphicsEllipseItem elipse;
private slots:
	void on_hsContourFreq_valueChanged(int val);
	void on_vsContourLevel_valueChanged(int val);
	void on_hsContourWidth_valueChanged(int val);
	void on_OkButton_clicked();
};

