#pragma once
#include "ui_ManualNotch.h"
#include "Cat.h"
#include <QGraphicsLineItem>

class ManualNotchUI : public QDialog
{
	Q_OBJECT
public:
	ManualNotchUI(const QObject* parent);
	~ManualNotchUI();

	void SetLevel(int level);
	int GetLevel();
	void SetWidth(Yaesu::Commands::FT891::IFNotchWidth val);


	void drawScene();
	QLineF rightLine;
	QLineF leftLine;
	QLineF leftDiag;
	QLineF rightDiag;
	QLineF centerVert;
	QLineF nonotch;
	QBrush solidb;
	QBrush solidr;
	QPen solidBlack;
	QPen solidRed;

signals:
	void on_level_changed(int val);
	void on_contour_freq_changed(int val);
private:
	Ui::ManualNotchClass ui;
	std::unique_ptr<QGraphicsScene> m_scene;
	friend class QtFT891;
	Yaesu::Commands::FT891::IFNotchWidth m_notchWidth;
	bool m_ContourOn = false;
	float m_ContourLevel = 0.0;
	float m_CountourWidth = 0.0;
	bool m_NotchOn = false;
	QtFT891* m_parent = nullptr;
private slots:
	void on_hsNotchFreq_valueChanged(int val);
	void on_cbIFNotchActivated(int val);
};