#include "QtFT891.h"
#include <fmt/core.h>
#include <windows.h>
#include <iostream>
#include <memory>
#include <fmt/format.h>

Yaesu::Commands::FT891::CommandType QtFT891::CommandType(const std::string& cmdtype)
{
	try
	{
		char first = cmdtype[0];
		char last = cmdtype[1];
		switch (first)
		{
		case 'A':
			switch (last)
			{
			case 'I':
				return Yaesu::Commands::FT891::CommandType::AI;
			case 'C':
				return Yaesu::Commands::FT891::CommandType::AC;
				break;
			case 'G':
				return Yaesu::Commands::FT891::CommandType::AG;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'B':
			switch (last)
			{
			case 'C':
				return Yaesu::Commands::FT891::CommandType::BC;
				break;
			case 'I':
				return Yaesu::Commands::FT891::CommandType::BI;
				break;
			case 'P':
				return Yaesu::Commands::FT891::CommandType::BP;
				break;
			case 'Y':
				return Yaesu::Commands::FT891::CommandType::BY;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'C':
			switch (last)
			{
			case 'F':
				return Yaesu::Commands::FT891::CommandType::CF;
				break;
			case 'N':
				return Yaesu::Commands::FT891::CommandType::CN;
				break;
			case 'O':
				return Yaesu::Commands::FT891::CommandType::CO;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::CS;
				break;
			case 'T':
				return Yaesu::Commands::FT891::CommandType::CT;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'D':
			switch (last)
			{
			case 'A':
				return Yaesu::Commands::FT891::CommandType::DA;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'E':
			switch (last)
			{
			case 'X':
				return Yaesu::Commands::FT891::CommandType::EX;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'F':
			switch (last)
			{
			case 'A':
				return Yaesu::Commands::FT891::CommandType::FA;
				break;
			case 'B':
				return Yaesu::Commands::FT891::CommandType::FB;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::FS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'G':
			switch (last)
			{
			case 'T':
				return Yaesu::Commands::FT891::CommandType::GT;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'I':
			switch (last)
			{
			case 'D':
				return Yaesu::Commands::FT891::CommandType::ID;
				break;
			case 'F':
				return Yaesu::Commands::FT891::CommandType::IF;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::IS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'K':
			switch (last)
			{
			case 'M':
				return Yaesu::Commands::FT891::CommandType::KM;
				break;
			case 'P':
				return Yaesu::Commands::FT891::CommandType::KP;
				break;
			case 'R':
				return Yaesu::Commands::FT891::CommandType::KR;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::KS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'L':
			switch (last)
			{
			case 'K':
				return Yaesu::Commands::FT891::CommandType::LK;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'M':
			switch (last)
			{
			case 'C':
				return Yaesu::Commands::FT891::CommandType::MC;
				break;
			case 'D':
				return Yaesu::Commands::FT891::CommandType::MD;
				break;
			case 'G':
				return Yaesu::Commands::FT891::CommandType::MG;
				break;
			case 'L':
				return Yaesu::Commands::FT891::CommandType::ML;
				break;
			case 'R':
				return Yaesu::Commands::FT891::CommandType::MR;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::MS;
				break;
			case 'T':
				return Yaesu::Commands::FT891::CommandType::MT;
				break;
			case 'W':
				return Yaesu::Commands::FT891::CommandType::MW;
				break;
			case 'X':
				return Yaesu::Commands::FT891::CommandType::MX;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'N':
			switch (last)
			{
			case 'A':
				return Yaesu::Commands::FT891::CommandType::NA;
				break;
			case 'B':
				return Yaesu::Commands::FT891::CommandType::NB;
				break;
			case 'L':
				return Yaesu::Commands::FT891::CommandType::NL;
				break;
			case 'R':
				return Yaesu::Commands::FT891::CommandType::NR;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'O':
			switch (last)
			{
			case 'I':
				return Yaesu::Commands::FT891::CommandType::OI;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::OS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'P':
			switch (last)
			{
			case 'A':
				return Yaesu::Commands::FT891::CommandType::PA;
				break;
			case 'B':
				return Yaesu::Commands::FT891::CommandType::PB;
				break;
			case 'C':
				return Yaesu::Commands::FT891::CommandType::PC;
				break;
			case 'L':
				return Yaesu::Commands::FT891::CommandType::PL;
				break;
			case 'R':
				return Yaesu::Commands::FT891::CommandType::PR;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::PS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'R':
			switch (last)
			{
			case 'A':
				return Yaesu::Commands::FT891::CommandType::RA;
				break;
			case 'G':
				return Yaesu::Commands::FT891::CommandType::RG;
				break;
			case 'I':
				return Yaesu::Commands::FT891::CommandType::RI;
				break;
			case 'L':
				return Yaesu::Commands::FT891::CommandType::RL;
				break;
			case 'M':
				return Yaesu::Commands::FT891::CommandType::RM;
				break;
			case 'S':
				return Yaesu::Commands::FT891::CommandType::RS;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'S':
			switch (last)
			{
			case 'C':
				return Yaesu::Commands::FT891::CommandType::SC;
				break;
			case 'D':
				return Yaesu::Commands::FT891::CommandType::SD;
				break;
			case 'H':
				return Yaesu::Commands::FT891::CommandType::SH;
				break;
			case 'M':
				return Yaesu::Commands::FT891::CommandType::SM;
				break;
			case 'Q':
				return Yaesu::Commands::FT891::CommandType::SQ;
				break;
			case 'T':
				return Yaesu::Commands::FT891::CommandType::ST;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'T':
			switch (last)
			{
			case 'S':
				return Yaesu::Commands::FT891::CommandType::TS;
				break;
			case 'X':
				return Yaesu::Commands::FT891::CommandType::TX;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		case 'U':
			switch (last)
			{
			case 'L':
				return Yaesu::Commands::FT891::CommandType::UL;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			
			}
			break;
		case 'V':
			switch (last)
			{
			case 'D':
				return Yaesu::Commands::FT891::CommandType::VD;
				break;
			case 'G':
				return Yaesu::Commands::FT891::CommandType::VG;
				break;
			case 'X':
				return Yaesu::Commands::FT891::CommandType::VX;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			
			}
			break;
		case '?':
			switch (last)
			{
			case ';':
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			default:
				return Yaesu::Commands::FT891::CommandType::UN;
				break;
			}
			break;
		default:
			return Yaesu::Commands::FT891::CommandType::UN;
			break;
		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return Yaesu::Commands::FT891::CommandType::UN;
	}
	
}

void QtFT891::ProcessCommmand(std::string cmd)
{
	auto commandtype = QtFT891::CommandType(cmd);
	switch (commandtype)
	{
	case Yaesu::Commands::FT891::CommandType::AC:
	{
		if (cbbandChanged && !loadingfromdb)
		{
			cbbandChanged = false;
			UpdateFromBandModeRecord(this->currentBand, this->currentMode);
			auto e = Yaesu::Commands::FT891::Width::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}

		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			auto val = Yaesu::Commands::FT891::AntennaTunerControl::Answer(cmd);
			QPalette pal = ui.btnTNR->palette();
			switch (val)
			{
			case Yaesu::Commands::FT891::TunerState::OFF:
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnTNR->setAutoFillBackground(true);
				ui.btnTNR->setPalette(pal);
				ui.btnTNR->repaint();

				break;
			case Yaesu::Commands::FT891::TunerState::ON:
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnTNR->setAutoFillBackground(true);
				ui.btnTNR->setPalette(pal);
				ui.btnTNR->repaint();
				break;
			}

			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::VolumeLevel::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}

		}
		if (loadingfromdb)
		{
			loadingfromdb = false;
			this->setEnabled(true);
			if (m_autoInfoState == Yaesu::Commands::FT891::InformationState::OFF) {
				auto e = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::ON);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::AG:
		if (QApplication::mouseButtons() == Qt::NoButton) {
			ui.Volume->setValue(Yaesu::Commands::FT891::VolumeLevel::Answer(cmd));
			if (loadingInit)
			{			
				auto e = Yaesu::Commands::FT891::AutoNotch::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			
		}
		break;
	case Yaesu::Commands::FT891::CommandType::AI:
	{
		Yaesu::Commands::FT891::InformationState val = Yaesu::Commands::FT891::AutoInformation::Answer(cmd);
		m_autoInfoState = val;
		switch (m_autoInfoState)
		{
		case Yaesu::Commands::FT891::InformationState::OFF:
		{
			if (!loadingInit) {
				auto lcmd = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::ON);
				m_radio->write(lcmd.c_str(), lcmd.length());
			} 
		}
		break;
		case Yaesu::Commands::FT891::InformationState::ON:
			if (loadingInit)
			{
				auto lcmd = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::OFF);
				m_radio->write(lcmd.c_str(), lcmd.length());
				m_radio->flush();
			}
			break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::AutoNotch::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::BC:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			auto state = Yaesu::Commands::FT891::AutoNotch::Answer(cmd);
			QPalette pal = ui.btnDNF->palette();
			switch (state)
			{
			case Yaesu::Commands::FT891::NotchState::OFF:
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnDNF->setAutoFillBackground(true);
				ui.btnDNF->setPalette(pal);
				ui.btnDNF->repaint();
				break;
			case Yaesu::Commands::FT891::NotchState::ON:
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnDNF->setAutoFillBackground(true);
				ui.btnDNF->setPalette(pal);
				ui.btnDNF->repaint();
				break;
			default:
				break;
			}
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::BreakIn::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::BI:
		if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
		{
			auto state = Yaesu::Commands::FT891::BreakIn::Answer(cmd);
			fromraadio = true;
			ui.chkbxBreakIn->setChecked(static_cast<int>(state) > 0);
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::ManualNotch::Read(Yaesu::Commands::FT891::NotchCommandType::ON_OFF);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		break;
	case Yaesu::Commands::FT891::CommandType::BP:
	{
		auto val = Yaesu::Commands::FT891::ManualNotch::Answer(cmd);
		if (val.Command == Yaesu::Commands::FT891::NotchCommandType::LEVEL)
		{
			if (mui) {

				if (QApplication::mouseButtons() == Qt::NoButton) {
					mui->SetLevel(val.Value.iValue);
				}
			}

		}
		if (val.Command == Yaesu::Commands::FT891::NotchCommandType::ON_OFF)
		{
			switch (val.Value.state)
			{
			case Yaesu::Commands::FT891::NotchState::ON:
				if (!mui)
				{
					mui = new ManualNotchUI(this);
					mui->setAttribute(Qt::WA_DeleteOnClose);
					auto conneciton = connect(mui, &ManualNotchUI::on_level_changed, this, &QtFT891::on_hsNotchLevelValueChanged);
					auto e = Yaesu::Commands::FT891::ManualNotch::Read(Yaesu::Commands::FT891::NotchCommandType::LEVEL);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
					mui->show();

				}

				break;
			case Yaesu::Commands::FT891::NotchState::OFF:
				mui = nullptr;
				break;
			}
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Clarifier::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::BY:
	{
		auto val = Yaesu::Commands::FT891::Busy::Answer(cmd);
		switch (val)
		{
		case Yaesu::Commands::FT891::BusyState::OFF:
		{
			auto pal = ui.lblBusyIndicator->palette();
			pal.setColor(QPalette::Window, defaultbg);

			ui.lblBusyIndicator->setAutoFillBackground(true);
			ui.lblBusyIndicator->setPalette(pal);
			ui.lblBusyIndicator->repaint();

		}
		break;
		case Yaesu::Commands::FT891::BusyState::ON:
		{
			auto pal = ui.lblBusyIndicator->palette();
			pal.setColor(QPalette::Window, Qt::blue);

			ui.lblBusyIndicator->setAutoFillBackground(true);
			ui.lblBusyIndicator->setPalette(pal);
			ui.lblBusyIndicator->repaint();
		}
		break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Clarifier::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::CF:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			Yaesu::Commands::FT891::ClarifierState val = Yaesu::Commands::FT891::Clarifier::Answer(cmd);
			switch (val)
			{
			case Yaesu::Commands::FT891::ClarifierState::OFF:
			{

				ui.ckClarEnabled->setChecked(false);
			}
			break;
			case Yaesu::Commands::FT891::ClarifierState::ON:
			{
				ui.ckClarEnabled->setChecked(true);
			}
			break;
			default:
				break;
			}
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::CTCSSToneFrequency::Read(Yaesu::Commands::FT891::CTCSSModeType::CTCSS);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::CN:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			Yaesu::Commands::FT891::CTCSSToneFreqencyValue val = Yaesu::Commands::FT891::CTCSSToneFrequency::Answer(cmd);
			switch (val.Mode)
			{
			case Yaesu::Commands::FT891::CTCSSModeType::CTCSS:
				ui.cbCTCSSTone->setCurrentIndex(val.Value);
				//fmtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::CTCSSToneFrequency::Read(Yaesu::Commands::FT891::CTCSSModeType::DCS);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
				break;
			case Yaesu::Commands::FT891::CTCSSModeType::DCS:
				ui.cbDCSCode->setCurrentIndex(val.Value);
				fmtabloaded = true;
				if (loadingInit)
				{
					Yaesu::Commands::FT891::ContourValue cv;
					cv.Type = Yaesu::Commands::FT891::ContourType::ContourOnOff;

					auto e = Yaesu::Commands::FT891::Contour::Read(cv);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
				break;
			default:
				break;
			}
		}
		if (loadingInit)
		{
			Yaesu::Commands::FT891::ContourValue cv;
			cv.Type = Yaesu::Commands::FT891::ContourType::ContourOnOff;
			cv.Value.state = Yaesu::Commands::FT891::ContourState::OFF;
			auto e = Yaesu::Commands::FT891::Contour::Read(cv);
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::CO:
	{
		auto val = Yaesu::Commands::FT891::Contour::Answer(cmd);
		switch (val.Type)
		{
		case Yaesu::Commands::FT891::ContourType::ContourOnOff:
		{
			if (val.Value.state == Yaesu::Commands::FT891::ContourState::ON)
			{

				contour_enabled = 1;
				auto pal = ui.btnContour->palette();
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnContour->setAutoFillBackground(true);
				ui.btnContour->setPalette(pal);
				ui.btnContour->repaint();

				if (!cui)
				{

					cui = new ContourUI(*this);
					Yaesu::Commands::FT891::ContourValue cv;
					cv.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;
					auto lcmd = Yaesu::Commands::FT891::Contour::Read(cv);
					m_radio->write(lcmd.c_str(), lcmd.length());
					connect(cui, &ContourUI::on_ContourFrequency_valueChanged, this, &QtFT891::on_ContourFrequency_valueChanged);
					connect(cui, &ContourUI::on_ContourLevel_valueChanged, this, &QtFT891::on_ContourLevel_valueChanged);
					connect(cui, &ContourUI::on_ContourWidth_valueChanged, this, &QtFT891::on_ContourWidth_valueChanged);
					cui->setAttribute(Qt::WA_DeleteOnClose);
					cui->show();

				}
			}
			else
			{
				auto pal = ui.btnContour->palette();
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnContour->setAutoFillBackground(true);
				ui.btnContour->setPalette(pal);
				ui.btnContour->repaint();

				contour_enabled = 0;
				cui = nullptr;

			}
			if (loadingInit)
			{
				Yaesu::Commands::FT891::ContourValue cv;
				cv.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;

				auto e = Yaesu::Commands::FT891::Contour::Read(cv);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		}
		case Yaesu::Commands::FT891::ContourType::ContourFrequency:
			if (cui)
			{
				contour_freq = val.Value.Freq;
				cui->SetFreq(val.Value.Freq);
				cui->drawScene();
			}
			if (ui.cbMode->currentIndex() >= 3 && ui.cbMode->currentIndex() <= 5)
			{
				if (loadingInit)
				{
					Yaesu::Commands::FT891::ContourValue cv;
					cv.Type = Yaesu::Commands::FT891::ContourType::APFOnOff;

					auto e = Yaesu::Commands::FT891::Contour::Read(cv);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			else
			{
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::CWSpot::Read();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}

			}
			break;
		case Yaesu::Commands::FT891::ContourType::APFOnOff:
		{
			ui.ckAPF->setChecked(val.Value.state == Yaesu::Commands::FT891::ContourState::ON);
			auto chkstate = ui.ckAPF->isChecked();
			ui.label_4->setEnabled(chkstate);
			ui.cbApfWidth->setEnabled(chkstate);
			ui.lblAPFPeak->setEnabled(chkstate);
			ui.lvlAPF->setEnabled(chkstate);
			ui.lblApfLevelValue->setEnabled(chkstate);
			if (loadingInit)
			{
				Yaesu::Commands::FT891::ContourValue cv;
				cv.Type = Yaesu::Commands::FT891::ContourType::APFFrequency;

				auto e = Yaesu::Commands::FT891::Contour::Read(cv);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		break;
		case Yaesu::Commands::FT891::ContourType::APFFrequency:
		{
			ui.lvlAPF->setValue(val.Value.Freq);
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::CWSpot::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}

		break;

		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::CS:
	{
		using namespace Yaesu::Commands;
		FT891::CWSpotState val = FT891::CWSpot::Answer(cmd);
		switch (val)
		{
		case Yaesu::Commands::FT891::CWSpotState::OFF:
			ui.chkCWSpot->setChecked(false);
			break;
		case Yaesu::Commands::FT891::CWSpotState::ON:
			ui.chkCWSpot->setChecked(true);
			break;
		default:
			break;
		}
		if (loadingInit) {

			auto e = Yaesu::Commands::FT891::CTCSS::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::CT:
	{
		using namespace Yaesu::Commands;
		FT891::CTCSSState val = FT891::CTCSS::Answer(cmd);
		switch (val)
		{
		case Yaesu::Commands::FT891::CTCSSState::CTCSS_OFF:
			ui.rbCTCSSOFF->setChecked(true);
			break;
		case Yaesu::Commands::FT891::CTCSSState::CTCSS_ENC_DEC_ON:
			ui.rbCTCSSENCDECON->setChecked(true);
			break;
		case Yaesu::Commands::FT891::CTCSSState::CTCSS_ENC_ON:
			ui.rbCTCSSENCON->setChecked(true);
			break;
		case Yaesu::Commands::FT891::CTCSSState::CTCSS_DCS_ON:
			ui.rbDCSON->setChecked(true);
			break;
		default:
			break;
		}
		//fmtabloaded = true;
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Dimmer::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::DA:
	{
		using namespace Yaesu::Commands;
		FT891::DimmerValues val = FT891::Dimmer::Answer(cmd);
		ui.lvlBacklight->setValue(val.BacklightLevel);
		ui.lvlLCD->setValue(val.LCD_Level);
		ui.lvlContrast->setValue(val.LCD_Contrast);
		ui.lvlTxBusy->setValue(val.TX_Indicator);
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Menu::ReadAgcFastDelay();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::EX:
	{
		int val = 0;
		Yaesu::Commands::FT891::MenuFunction mf = (Yaesu::Commands::FT891::MenuFunction)std::stoi(cmd.substr(2, 4));
		switch (mf)
		{
		case Yaesu::Commands::FT891::MenuFunction::AGC_FAST_DELAY:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerAgcFastDelay(cmd);
				ui.lvlAGCFast->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAgcMidDelay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AGC_MID_DELAY:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerAgcMidDelay(cmd);
				ui.lvlAGCMid->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAgcSlowDelay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AGC_SLOW_DELAY:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerAgcSlowDelay(cmd);
				ui.lvlAGCSlow->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadLcdContrast();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::LCD_CONTRAST:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerLcdContrast(cmd);
				ui.lvlContrast->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadBackliteDimmer();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DIMMER_BACKLIT:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerBackliteDimmer(cmd);
				ui.lvlBacklight->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadLcdDimmer();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DIMMER_LCD:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerLcdDimmer(cmd);
				ui.lvlLCD->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadTxBusyDimmer();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DIMMER_TX_BUSY:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerTxBusyDimmer(cmd);
				ui.lvlTxBusy->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPeakHold();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::PEAK_HOLD:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto peakhold = Yaesu::Commands::FT891::Menu::AnswerPeakHold(cmd);
				ui.cbPeakHold->setCurrentIndex(static_cast<int>(peakhold));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadZinLed();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::ZIN_LED:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerZinLed(cmd);
				ui.chkbxZinLed->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPopupMenuStyle();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::POPUP_MENU:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPopupMenuStyle(cmd);
				ui.cbPopupMenu->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDvsRxOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DVS_RX_OUT_LVL:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				contestingtabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerDvsRxOutLevel(cmd);
				ui.lvldvsRx->setValue(val);
				if (loadingInit)
				{
					std::string e = Yaesu::Commands::FT891::Menu::ReadDvsTxOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DVS_TX_OUT_LVL:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerDvsTxOutLevel(cmd);
				ui.lvldvsTx->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadKeyerType();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::KEYER_TYPE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerKeyerType(cmd);
				ui.cbCWKeyerType->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadKeyerDotDash();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::KEYER_DOT_DASH_ORDER:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerKeyerDotDash(cmd);
				ui.cbCWKeyerDotDash->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCwWeight();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_WEIGHT:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCwWeight(cmd);
				ui.lblCWWeight->setText(fmt::format("CW Weight: {:d}", val).c_str());
				ui.lvlCWWeight->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadBeaconInterval();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::BEACON_INTERVAL:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerBeaconInterval(cmd);
				if (val == 0)
				{
					ui.sbBeconInterval->setSpecialValueText("OFF");
				}
				else
				{
					ui.sbBeconInterval->setValue(val);
				}
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadNumberStyle();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}

			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::NUMBER_STYLE:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerNumberStyle(cmd);
				ui.cbNumberFormat->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadContestNumber();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CONTEST_NUMBER:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerContestNumber(cmd);
				ui.sbContestNumber->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWMemory1();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_MEMORY_1:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWMemory1(cmd);
				ui.cbMK->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWMemory2();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_MEMORY_2:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWMemory2(cmd);
				ui.cbMK_2->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWMemory3();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_MEMORY_3:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWMemory3(cmd);
				ui.cbMK_3->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWMemory4();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_MEMORY_4:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWMemory4(cmd);
				ui.cbMK_4->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWMemory5();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_MEMORY_5:
			if (!contestingtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWMemory5(cmd);
				ui.cbMK_5->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadNbWidth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::NB_WIDTH:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerNbWidth(cmd);
				ui.cbNBWidth->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadNbRejection();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::NB_REJECTION:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerNbRejection(cmd);
				ui.cbNBRejection->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadNbLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::NB_LEVEL:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerNbLevel(cmd);
				ui.NBLvl->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadBeepLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::BEEP_LEVEL:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerBeepLevel(cmd);
				ui.lvlBeep->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRfSqlVr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RF_SQL_VR:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.cbRFSQLvr->setCurrentIndex(static_cast<int>(Yaesu::Commands::FT891::Menu::AnswerRfSqlVr(cmd)));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCatRate();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CAT_RATE:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto port = m_radio->portName();
				auto sval = Yaesu::Commands::FT891::Menu::AnswerCatRate(cmd);
				switch (sval)
				{
				case Yaesu::Commands::FT891::CatRateValue::_4800bps:
					//UpdatePortSettings(port, 4800);
					m_radio->setBaudRate(4800);
					break;
				case Yaesu::Commands::FT891::CatRateValue::_9600bps:
					//UpdatePortSettings(port, 9600);
					m_radio->setBaudRate(9600);
					break;
				case Yaesu::Commands::FT891::CatRateValue::_19200bps:
					//UpdatePortSettings(port, 19200);
					m_radio->setBaudRate(19200);
					break;
				case Yaesu::Commands::FT891::CatRateValue::_38400bps:
					//UpdatePortSettings(port, 38400);
					m_radio->setBaudRate(38400);
					break;
				default:
					break;
				}
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCatTOT();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CAT_TOT:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = static_cast<int>(Yaesu::Commands::FT891::Menu::AnswerCatTOT(cmd));
				ui.cbCATTOT->setCurrentIndex(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCatRTS();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CAT_RTS:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.chkbxCatRTS->setChecked(Yaesu::Commands::FT891::Menu::AnswerCatRTS(cmd) == Yaesu::Commands::FT891::EnableDisableValue::ENABLE);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadMemGroup();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::MEM_GROUP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerMemGroup(cmd);
				ui.chkbxMemGroup->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMSetting();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_SETTING:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFMSetting(cmd);
				ui.chkbxFMSetting->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRecSetting();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::REC_SETTING:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRecSetting(cmd);
				ui.chkbxRECSettings->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadATASSetting();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::ATAS_SETTING:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerATASSetting(cmd);
				ui.chkbxATAS->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadQuickSplitFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::QUICK_SPL_FREQ:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerQuickSplitFreq(cmd);
				ui.sbQuickSplit->setValue(val);
				ui.sbQuickSplit->repaint();
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadTXTOT();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::TX_TOT:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerTXTOT(cmd);
				ui.lvlTxTOT->setValue(val);
				misctabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadMicScan();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::MIC_SCAN:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerMicScan(cmd);
				ui.chkbxMicScan->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadMicScanResume();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::MIC_SCAN_RESUME:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerMicScanResume(cmd);
				ui.cbMicScanResume->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRefFreqAdjust();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::REF_FEQ_ADJ:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRefFreqAdjust(cmd);
				ui.sbRefReqAdj->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadClarSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CLAR_SELECT:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerClarSelect(cmd);
				ui.cbClarSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadApo();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::APO:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerApo(cmd);
				ui.cbAPO->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFanControl();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FAN_CONTROL:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFanControl(cmd);
				ui.chkbxFan->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMLowCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_LCUT_FREQ:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMLowCutFreq(cmd);
				ui.lvlAMLCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMLowCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_LCUT_SLOPE:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMLowCutSlope(cmd);
				ui.cbAMLCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMHighCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_HCUT_FREQ:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMHighCutFreq(cmd);
				ui.lvlAMHCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMHighCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_HCUT_SLOPE:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMHighCutSlope(cmd);
				ui.cbAMHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMMicSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_MIC_SELECT:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMMicSelect(cmd);
				ui.cbAMHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_OUT_LEVEL:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMOutLevel(cmd);
				ui.lblAmOutLevel->setText(fmt::format("Out Level: {:d}", val).c_str());
				ui.lvlAMOutLevel->setValue(static_cast<int>(val));
				//amtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMPTTSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_PTT_SELECT:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMPTTSelect(cmd);
				ui.cbAMPTT->setCurrentIndex(static_cast<int>(val));
				//amtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWLowCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_LCUT_FREQ:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerCWLowCutFreq(cmd);
				ui.lvlCWLCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWLowCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_LCUT_SLOPE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWLowCutSlope(cmd);
				ui.cbCWLCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWHighCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_HCUT_FREQ:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerCWHighCutFreq(cmd);
				ui.lvlCWHCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWHighCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_HCUT_SLOPE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWHighCutSlope(cmd);
				ui.cbCWHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_OUT_LEVEL:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				cwtabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWOutLevel(cmd);
				ui.lblCWOutLevel->setText(fmt::format("Out Level: {:d}", val).c_str());
				ui.lvlCWOutLevel->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWAutoMode();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_AUTO_MODE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWAutoMode(cmd);
				ui.cbCWAutoMode->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWBFO();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_BFO:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				m_cwbfo = Yaesu::Commands::FT891::Menu::AnswerCWBFO(cmd);
				ui.cbCWBFO->setCurrentIndex(static_cast<int>(m_cwbfo));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWBreakInType();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_BK_IN_TYPE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWBreakInType(cmd);
				ui.cbCWBkInType->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWBreakInDelay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_BK_IN_DELAY:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWBreakInDelay(cmd);
				ui.lblCWBkInDelay->setText(fmt::format("BK-IN Delay: {:d}ms", val).c_str());
				ui.lvlCWBKINDelay->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWWaveShape();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_WAVE_SHAPE:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWWaveShape(cmd);
				ui.cbWaveShape->setCurrentIndex(static_cast<int>(val) - 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCWFreqDisplay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CW_FREQ_DISPLAY:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCWFreqDisplay(cmd);
				ui.cbCWFreqDisplay->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPCKeying();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::PC_KEYING:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPCKeying(cmd);
				ui.cbCWPCKeying->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadQSKDelayTime();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::QSK_DELAY_TIME:
			if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerQSKDelayTime(cmd);
				ui.cbCWQSKDelayTime->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDataMode();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_MODE:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDataMode(cmd);
				ui.cbDataMode->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPSKTone();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::PSK_TONE:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPSKTone(cmd);
				ui.cbPskTone->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadOtherDisp();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::OTHER_DISP:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerOtherDisp(cmd);

				ui.sbOtherDISP->setValue(val);
				if (ui.sbOtherDISP->value() != val)
				{
					OutputDebugString("this is bullshit!");
				}
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadOtherShift();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::OTHER_SHIFT:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerOtherShift(cmd);

				ui.sbOtherShift->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATALowCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_LCUT_FREQ:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATALowCutFreq(cmd);
				ui.lvlDATALCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATALowCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_LCUT_SLOPE:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATALowCutSlope(cmd);
				ui.cbDATALCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAHighCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_HCUT_FREQ:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAHighCutFreq(cmd);
				ui.lvlDATAHCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAHighCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_HCUT_SLOPE:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAHighCutSlope(cmd);
				ui.cbDATAHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAInSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_IN_SELECT:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAInSelect(cmd);
				ui.cbDataInSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAPTTSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_PTT_SELECT:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAPTTSelect(cmd);
				ui.cbDataPTT->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_OUT_LEVEL:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				datatabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAOutLevel(cmd);
				ui.lvlDATAOut->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATABFO();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_BFO:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				m_databfo = Yaesu::Commands::FT891::Menu::AnswerDATABFO(cmd);
				ui.cbDataBFO->setCurrentIndex(static_cast<int>(m_databfo));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMMicSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_MIC_SELECT:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFMMicSelect(cmd);
				ui.cbFMMicSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_OUT_LEVEL:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFMOutLevel(cmd);
				ui.lblFMOut->setText(fmt::format("FM OUT: {:d}", val).c_str());
				ui.lvlFMOut->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPktPTTSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::PKT_PTT_SELECT:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPktPTTSelect(cmd);
				ui.cbPktPttSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRptShift28MHZ();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RPT_SHIFT_28MHZ:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRptShift28MHZ(cmd);
				ui.sb28mhzShift->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRptShift50MHZ();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RPT_SHIFT_50MHZ:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRptShift50MHZ(cmd);
				ui.sb50mhzShift->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDCSPolarity();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DCS_POLARITY:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDCSPolarity(cmd);
				ui.cbDCSPolarity->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYLowCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_LCUT_FREQ:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYLowCutFreq(cmd);
				ui.lvlRTTYLCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYLowCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_LCUT_SLOPE:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYLowCutSlope(cmd);
				ui.cbRTTYLCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYHighCutFreq();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_HCUT_FREQ:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYHighCutFreq(cmd);
				ui.lvlRTTYHCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYHighCutSlope();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_HCUT_SLOPE:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYHighCutSlope(cmd);
				ui.cbRTTYHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYShiftPort();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_SHIFT_PORT:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYShiftPort(cmd);
				ui.cbRTTYShiftPort->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYPolarityR();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_POLARITY_R:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYPolarityR(cmd);
				ui.cbPolarityR->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYPolarityT();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_POLARITY_T:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYPolarityT(cmd);
				ui.cbPolarityT->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYOutLevel();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_OUT_LEVEL:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYOutLevel(cmd);
				ui.lblRTTYOut->setText(fmt::format("Out Level: {:d}", val).c_str());
				ui.lvlRTTYOut->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYShiftFreq();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_SHIFT_FREQ:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYShiftFreq(cmd);
				ui.cbRTTYShiftFeq->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYMarkFreq();

					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_MARK_FREQ:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				rttytabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerRTTYMarkFreq(cmd);
				ui.cbRTTYMarkFreq->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{

					auto e = Yaesu::Commands::FT891::Menu::ReadRTTYBFO();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::RTTY_BFO:
			if (!rttytabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				m_rttybfo = Yaesu::Commands::FT891::Menu::AnswerRTTYBFO(cmd);
				ui.cbRTTYBfo->setCurrentIndex(static_cast<int>(m_rttybfo));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBLowCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}

			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_LCUT_FREQ:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBLowCutFreq(cmd);
				ui.lvlSSBLCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBLowCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_LCUT_SLOPE:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBLowCutSlope(cmd);
				ui.cbSSBLCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBHighCutFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_HCUT_FREQ:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBHighCutFreq(cmd);
				ui.lvlSSBHCutFreq->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBHighCutSlope();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_HCUT_SLOPE:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBHighCutSlope(cmd);
				ui.cbSSBHCutSlope->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBMicSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_MIC_SELECT:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBMicSelect(cmd);
				ui.cbSSBMicSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBOutLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_OUT_LEVEL:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ssbtabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBOutLevel(cmd);
				ui.lblSSBOut->setText(fmt::format("Out Level: {:d}", val).c_str());
				ui.lvlSSBOut->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBBFO();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_BFO:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				m_ssbbfo = Yaesu::Commands::FT891::Menu::AnswerSSBBFO(cmd);
				ui.cbSSBBfo->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBPTTSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_PTT_SELECT:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBPTTSelect(cmd);
				ui.cbSSBPTTSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBTxBPF();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_TX_BPF:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBTxBPF(cmd);
				ui.cbSSBTxBPF->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAPFWidth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::APF_WIDTH:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAPFWidth(cmd);
				ui.cbApfWidth->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadCountourLevel();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CONTOUR_LEVEL:
			if (cui)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCountourLevel(cmd);
				contour_level = val;
				cui->SetLevel(val);
				cui->drawScene();

			}
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::Menu::ReadCountourWidth();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::CONTOUR_WIDTH:
			if (cui)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerCountourWidth(cmd);
				cui->SetWidth(val);
				cui->drawScene();
				contour_width = val;
			}
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::Menu::ReadIFNotchWidth();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::IF_NOTCH_WIDTH:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerIFNotchWidth(cmd);
				m_notchWidth = val;
				if (mui)
				{
					mui->SetWidth(val);
				}
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSCPStartCycle();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SCP_START_CYCLE:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSCPStartCycle(cmd);
				ui.cbSpectrumScopeStartCycle->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSCPSpanFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SCP_SPAN_FREQ:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSCPSpanFreq(cmd);
				ui.cbScopeSpan->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadQuickDial();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::QUICK_DIAL:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerQuickDial(cmd);
				ui.cbQuickDialStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBDialStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_DIAL_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBDialStep(cmd);
				ui.cbSSBDialStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMDialStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_DIAL_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMDialStep(cmd);
				ui.cbAmDialStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMDialStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();

				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_DIAL_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFMDialStep(cmd);
				ui.cbFmDialStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDialStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DIAL_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDialStep(cmd);
				ui.cbDialDialStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAmChStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_CH_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAmChStep(cmd);
				ui.cbAmChStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFmChStep();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_CH_STEP:
			if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFmChStep(cmd);
				ui.cbFmChStep->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ1Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ1_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ1Freq(cmd);
				ui.cbMicLow->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ1Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ1_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ1Level(cmd);
				ui.lvlMicLow->setValue(static_cast<int>(val));
				ui.lbl0MicLow->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ1Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ1_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ1Bwth(cmd);
				ui.lvlMicLowWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ2Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ2_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ2Freq(cmd);
				ui.cbMicMid->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ2Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ2_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ2Level(cmd);
				ui.lvlMicMid->setValue(static_cast<int>(val));
				ui.lbl0MicLow_2->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ2Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ2_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ2Bwth(cmd);
				ui.lvlMicMidWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ3Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ3_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ3Freq(cmd);
				ui.cbMicHigh->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ3Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ3_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ3Level(cmd);
				ui.lvlMicHigh->setValue(static_cast<int>(val));
				ui.lbl0MicLow_3->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEQ3Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EQ3_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEQ3Bwth(cmd);
				ui.lvlMicHighWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ1Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ1_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ1Freq(cmd);
				ui.cbProcLow->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ1Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ1_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ1Level(cmd);
				ui.lvlProcLow->setValue(static_cast<int>(val));
				ui.lbl0MicLow_4->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ1Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ1_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ1Bwth(cmd);
				ui.lvlProcLowWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ2Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ2_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ2Freq(cmd);
				ui.cbProcMid->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ2Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ2_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ2Level(cmd);
				ui.lvlProcMid->setValue(static_cast<int>(val));
				ui.lbl0MicLow_5->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ2Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ2_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ2Bwth(cmd);
				ui.lvlProcMidWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ3Freq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ3_FREQ:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ3Freq(cmd);
				ui.cbProcHigh->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ3Level();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ3_LEVEL:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ3Level(cmd);
				ui.lvlProcHigh->setValue(static_cast<int>(val));
				ui.lbl0MicLow_6->setText(std::to_string(val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadPEQ3Bwth();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::P_EQ3_BWTH:
			if (!txeqtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				txeqtabloaded = true;
				auto val = Yaesu::Commands::FT891::Menu::AnswerPEQ3Bwth(cmd);
				ui.lvlProcHighWidth->setValue(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadHfSsbPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::HF_SSB_PWR:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton) {
				val = Yaesu::Commands::FT891::Menu::AnswerHfSsbPwr(cmd);
				ui.lvlHFSSBPower->setValue(val);
				ui.lblHFSSB->setText(fmt::format("SSB: {:d}", val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadHfAmPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::HF_AM_PWR:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerHfAmPwr(cmd);
				ui.lvlHFAMPower->setValue(val);
				ui.lblHFAM->setText(fmt::format("AM: {:d}", val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadHfPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::HF_PWR:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::AnswerHfPwr(cmd);
				ui.lvlHFPower->setValue(val);
				ui.lblHFPOWER->setText(fmt::format("CW/Data: {:d}", val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::Read50mSsbPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_POWER_50M:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::Answer50mSsbPwr(cmd);
				ui.lvlVHFSSBPower->setValue(val);
				ui.lblVHFSSB->setText(fmt::format("SSB: {:d}", val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::Read50mAmPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_POWER_50M:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::Answer50mAmPwr(cmd);
				ui.lvlVHFAMPower->setValue(val);
				ui.lblVHFAM->setText(fmt::format("AM: {:d}", val).c_str());
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::Read50mPwr();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::VHF_PWR:
			if (!powertabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				val = Yaesu::Commands::FT891::Menu::Answer50mPwr(cmd);
				ui.lvlVHFPower->setValue(val);
				ui.lblVHFPWR->setText(fmt::format("CW/Data: {:d}", val).c_str());
				powertabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBMicGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_MIC_GAIN:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBMicGain(cmd);
				ui.lblSSBMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
				ui.lvlSSBMicGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMMicGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_MIC_GAIN:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMMicGain(cmd);
				ui.lblAmMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
				ui.lvlAMMicGain->setValue(val);
				//amtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMMicGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_MIC_GAIN:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerFMMicGain(cmd);
				ui.lblFMMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
				ui.lvlFMMicGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDATAMicGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_MIC_GAIN:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDATAMicGain(cmd);
				ui.lblDataMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
				ui.lvlDataMicGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadSSBDataGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::SSB_DATA_GAIN:
			if (!ssbtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerSSBDataGain(cmd);
				ui.lblSSBDataGain->setText(fmt::format("Data Gain: {:d}", val).c_str());
				ui.lvlSSBDataGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAMDataGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::AM_DATA_GAIN:
			if (!amtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerAMDataGain(cmd);
				ui.lblAmDataGain->setText(fmt::format("Data Gain: {:d}", val).c_str());
				ui.lvlAMDataGain->setValue(val);
				amtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadFMDataGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::FM_DATA_GAIN:
			if (!fmtabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{

				auto val = Yaesu::Commands::FT891::Menu::AnswerFMDataGain(cmd);
				ui.lblFMDataGain->setText(fmt::format("Data Gain: {:d}", val).c_str());
				ui.lvlFMDataGain->setValue(val);
				//fmtabloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDataDataGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_GAIN:
			if (!datatabloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDataDataGain(cmd);
				ui.lblDataGain->setText(fmt::format("DATA GAIN: {:d}", val).c_str());
				ui.lvlDataGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadTunerSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::TUNER_SELECT:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.cbTunerSelect->setCurrentIndex(static_cast<int>(Yaesu::Commands::FT891::Menu::AnswerTunerSelect(cmd)));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadVoxSelect();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::VOX_SELECT:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerVoxSelect(cmd);
				ui.cbVoxSelect->setCurrentIndex(static_cast<int>(val));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadVoxGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::VOX_GAIN:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.VoxLevel->setValue(Yaesu::Commands::FT891::Menu::AnswerVoxGain(cmd));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadVoxDelay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::VOX_DELAY:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.sbVoxDelay->setValue(Yaesu::Commands::FT891::Menu::AnswerVoxDelay(cmd));
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadAntiVoxGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::ANTI_VOX_GAIN:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				ui.AntiVox->setValue(Yaesu::Commands::FT891::Menu::AnswerAntiVoxGain(cmd));
				voxloaded = true;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDataVoxGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_VOX_GAIN:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDataVoxGain(cmd);
				ui.lblDataVoxGain->setText(fmt::format("Vox Gain: {:d}", val).c_str());
				ui.lvlDataVoxGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDataVoxDelay();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_VOX_DELAY:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDataVoxDelay(cmd);
				ui.sbDataVoxDelay->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadDataAntiVoxGain();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::DATA_ANTIVOX_GAIN:
			if (!voxloaded || QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerDataAntiVoxGain(cmd);
				ui.lblDataAntiVoxGain->setText(fmt::format("Anti Vox Gain: {:d}", val).c_str());
				ui.lvlDataAntiVoxGain->setValue(val);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadEmergencyFreq();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::EMERGENCY_FREQ:
			if (QApplication::mouseButtons() == Qt::NoButton)
			{
				auto val = Yaesu::Commands::FT891::Menu::AnswerEmergencyFreq(cmd);
				ui.chkbxEmergencyFreq->setChecked(static_cast<int>(val) == 1);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::Menu::ReadMainVersion();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
		case Yaesu::Commands::FT891::MenuFunction::MAIN_VERSION:
		{
			auto val = Yaesu::Commands::FT891::Menu::AnswerMainVersion(cmd);
			ui.lblMain->setText(val.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::Menu::ReadDSPVersion();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		break;
		case Yaesu::Commands::FT891::MenuFunction::DSP_VERSION:
		{
			auto val = Yaesu::Commands::FT891::Menu::AnswerDSPVersion(cmd);
			ui.lblDSP->setText(val.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::Menu::ReadLCDVersion();

				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		break;
		case Yaesu::Commands::FT891::MenuFunction::LCD_VERSION:
		{
			auto val = Yaesu::Commands::FT891::Menu::AnswerLCDVersion(cmd);
			ui.lblLCD->setText(val.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::VFO_A_FREQ::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::FA:
	{
		using namespace Yaesu::Commands;
		int freq = FT891::VFO_A_FREQ::Answer(cmd);
		std::string dispval = fmt::format("{:d}.{:03}.{:03}", (freq - (freq % 1000000)) / 1000000, ((freq % 1000000) - (freq % 1000)) / 1000, (freq % 1000));
		if (ui.VFOType->text() == "A") {
			ui.VFO->setText(dispval.c_str());

		}
		else
		{
			ui.VFOB->setText(dispval.c_str());

		}
		if (!receivedInformation && !loadingInit)
		{
			auto e = Yaesu::Commands::FT891::INFORMATION::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::VFO_B_FREQ::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::FB:
	{
		using namespace Yaesu::Commands;
		int freq = FT891::VFO_A_FREQ::Answer(cmd);
		std::string dispval = fmt::format("{:d}.{:03}.{:03}", (freq - (freq % 1000000)) / 1000000, ((freq % 1000000) - (freq % 1000)) / 1000, (freq % 1000));
		ui.VFOB->setText(dispval.c_str());
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::FAST_STEP::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::FS:
	{
		if (QApplication::mouseButtons() == Qt::NoButton) {
			auto val = Yaesu::Commands::FT891::FAST_STEP::Answer(cmd);
			QPalette pal = ui.btnFST->palette();
			switch (val)
			{
			case Yaesu::Commands::FT891::VFOFastStepValue::OFF:
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnFST->setAutoFillBackground(true);
				ui.btnFST->setPalette(pal);
				ui.btnFST->repaint();
				break;
			case Yaesu::Commands::FT891::VFOFastStepValue::ON:
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnFST->setAutoFillBackground(true);
				ui.btnFST->setPalette(pal);
				ui.btnFST->repaint();
				break;
			default:
				break;
			}
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::AGC_FUNCTION::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::GT:
	{
		auto val = Yaesu::Commands::FT891::AGC_FUNCTION::Answer(cmd);
		if (!misctabloaded || QApplication::mouseButtons() == Qt::NoButton)
		{
			int ival;
			using namespace Yaesu::Commands::FT891;
			switch (val)
			{

			case AGCReadValue::OFF:
				ival = 0;
				break;
			case AGCReadValue::FAST:
				ival = 1;
				break;
			case AGCReadValue::MID:
				ival = 2;
				break;
			case AGCReadValue::SLOW:
				ival = 3;
				break;
			case AGCReadValue::AUTO_FAST:
				ival = 4;
				break;
			case AGCReadValue::AUTO_MID:
				ival = 4;
				break;
			case AGCReadValue::AUTO_SLOW:
				ival = 4;
				break;
			}


			ui.cbAGCFunc->setCurrentIndex(ival);
			ui.cbAGCFunc->repaint();

			if (loadingInit)
			{
				auto e = Yaesu::IDENTIFICATION::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();

			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::ID:
	{
		Yaesu::RigType val = Yaesu::IDENTIFICATION::Answer(cmd);
		switch (val)
		{
		case Yaesu::RigType::FT891:
			break;
		case Yaesu::RigType::FT991A:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FT991A, this application isn't compatible with that radio. Please select the correct port.", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX101D:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX101D, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX101MP:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX101MP, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX10:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX10, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FT450D:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FT450D, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FT710:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FT710, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX1200:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX1200, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX1200_FFT:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX1200 with FFT installed, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX3000:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX3000, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		case Yaesu::RigType::FTDX5000:
		{
			QMessageBox box{ QMessageBox::Information, "QtFT891", "You have selected an FTDX5000, this application isn't compatible with that radio", QMessageBox::Ok | QMessageBox::Abort, this };
			auto result = box.exec();
			switch (result)
			{
			case QMessageBox::Ok:
				if (m_radio->isOpen())
				{
					m_radio->close();
					this->on_pbPortSettings_clicked();
				}
				break;
			case QMessageBox::Abort:
				this->close();
				break;
			}
		}
		break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::IF_SHIFT::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::IF:
	{

		Yaesu::Commands::FT891::InformationValue iv = Yaesu::Commands::FT891::INFORMATION::Answer(cmd);
		VFOAFreq = iv.VFOAFreq;
		CalculateMode(iv.Mode);
		m_ClarifierOffset = iv.ClarifierFreq;
		ui.lblClarifierValue->setText(fmt::format("{:d}Hz", m_ClarifierOffset).c_str());

		if (QApplication::mouseButtons() == Qt::NoButton) {
			if (ui.cbBand->isVisible()) {
				SetBand();
			}
		}
		if (bandChanged && !loadingInit) {
			receivedInformation = true;
			loadingfromdb = true;
			UpdateFromBandModeRecord(this->currentBand, this->currentMode);
			bandChanged = false;
		}

		std::string dispval = fmt::format("{:d}.{:03}.{:03}", (iv.VFOAFreq - (iv.VFOAFreq % 1000000)) / 1000000, ((iv.VFOAFreq % 1000000) - (iv.VFOAFreq % 1000)) / 1000, (iv.VFOAFreq % 1000));

		ui.VFO->setText(dispval.c_str());


		switch (iv.VFO)
		{
		case Yaesu::Commands::FT891::VFOChannelTypeValue::VFO:
		{
			ui.VFOType->setText("A");
			ui.lblB->setText("B");
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::Memory:
		{
			std::string lblval = fmt::format("M{:d}", static_cast<int>(iv.MemoryChannel));
			ui.VFOType->setText(lblval.c_str());
			cmd = Yaesu::Commands::FT891::MemoryWriteTag::Read(iv.MemoryChannel);
			m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::MemoryTune:
		{
			ui.VFOType->setText("MT");
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::HOME:
		{
			ui.VFOType->setText("HOME");
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::PMS:
		{
			ui.VFOType->setText("PMS");
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::QuickMemoryBank:
		{
			auto disp = fmt::format("QMB {:03}", static_cast<int>(iv.MemoryChannel));
			ui.VFOType->setText(disp.c_str());
		}
		break;
		case Yaesu::Commands::FT891::VFOChannelTypeValue::QMB_MT:
		{
			ui.VFOType->setText("QMT");
		}
		break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::OppositeBandInformation::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::IS:
	{
		auto val = Yaesu::Commands::FT891::IF_SHIFT::Answer(cmd);
		if (QApplication::mouseButtons() == Qt::NoButton) {
			ui.ckIFShift->setChecked(val.State == Yaesu::Commands::FT891::IfShiftValue::ON);
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyerMemory::Read(1);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::KM:
	{
		auto val = Yaesu::Commands::FT891::KeyerMemory::Answer(cmd);
		val.Message = val.Message.substr(0, val.Message.length() - 1);
		switch (val.ChannelNumber)
		{
		case 1:
			ui.lnMemKey_1->setText(val.Message.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyerMemory::Read(2);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case 2:
			ui.lnMemKey_2->setText(val.Message.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyerMemory::Read(3);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case 3:
			ui.lnMemKey_3->setText(val.Message.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyerMemory::Read(4);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case 4:
			ui.lnMemKey_4->setText(val.Message.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyerMemory::Read(5);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		case 5:
			ui.lnMemKey_5->setText(val.Message.c_str());
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::KeyPitch::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
			break;
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::KP:
	{
		using namespace Yaesu::Commands;
		FT891::KeyPitchValue val = FT891::KeyPitch::Answer(cmd);
		ui.vsKeyPitch->setValue(300 + static_cast<int>(val));
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Keyer::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::KR:
	{
		if (!cwtabloaded || QApplication::mouseButtons() == Qt::NoButton)
		{
			auto state = Yaesu::Commands::FT891::Keyer::Answer(cmd);
			ui.chkbxKeyerEnable->setChecked(state == Yaesu::Commands::FT891::KeyerValue::ON);
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::KeyerSpeed::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::KS:
	{
		if (!cwtabloaded && QApplication::mouseButtons() == Qt::NoButton && !ui.spbxKeySpeed->hasFocus())
		{
			auto speed = Yaesu::Commands::FT891::KeyerSpeed::Answer(cmd);
			ui.spbxKeySpeed->setValue(static_cast<int>(speed) + 4);
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::VFODialLock::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::LK:
	{

		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			QPalette pal = ui.btnLOCK->palette();
			QColor bgcolor = pal.color(QPalette::Button);

			auto val = Yaesu::Commands::FT891::VFODialLock::Answer(cmd);
			switch (val)
			{
			case Yaesu::Commands::FT891::DialLockValue::OFF:
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnLOCK->setAutoFillBackground(true);
				ui.btnLOCK->setPalette(pal);
				ui.btnLOCK->repaint();
				break;
			case Yaesu::Commands::FT891::DialLockValue::ON:
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnLOCK->setAutoFillBackground(true);
				ui.btnLOCK->setPalette(pal);
				ui.btnLOCK->repaint();
				break;
			default:
				break;
			}
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::OperatingMode::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::LM:
		break;
	case Yaesu::Commands::FT891::CommandType::MC:
		break;
	case Yaesu::Commands::FT891::CommandType::MD:
	{
		using namespace Yaesu::Commands::FT891;
		//modeChanged = false;
		auto mode = Yaesu::Commands::FT891::OperatingMode::Answer(cmd);
		CalculateMode(mode);
		if (mode == ModeValue::AM || mode == ModeValue::AM_N || mode == ModeValue::FM || mode == ModeValue::FM_N || mode == ModeValue::SSB_BFOA || mode == ModeValue::SSB_BFOB)
		{
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::MicGain::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
		else
		{
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::MonitorLevel::Read(MonitorFunction::MontiorOnOff);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::MG:
	{
		using namespace Yaesu::Commands::FT891;
		if (QApplication::mouseButtons() == Qt::NoButton) {
			ui.MicGain->setValue(Yaesu::Commands::FT891::MicGain::Answer(cmd));
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::MonitorLevel::Read(MonitorFunction::MontiorOnOff);
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::ML:
	{
		using namespace Yaesu::Commands::FT891;
		if (QApplication::mouseButtons() == Qt::NoButton) {
			auto  lval = Yaesu::Commands::FT891::MonitorLevel::Answer(cmd);
			if (lval.f == Yaesu::Commands::FT891::MonitorFunction::MontiorOnOff) {
				this->monitoron = lval.val.eVal == Yaesu::Commands::FT891::MonitorOnOffValue::ON;
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::MonitorLevel::Read(MonitorFunction::MontiorLevel);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			else
			{
				ui.MON->setValue(lval.val.iVal);
				if (loadingInit)
				{
					auto e = Yaesu::Commands::FT891::MeterSW::Read();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::MR:
		break;
	case Yaesu::Commands::FT891::CommandType::MS:
	{
		m_meterType = Yaesu::Commands::FT891::MeterSW::Answer(cmd);

		ui.cbMeterType->setCurrentIndex(static_cast<int>(m_meterType));
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::MoxSet::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::MT:
	{
		auto channel = Yaesu::Commands::FT891::MemoryWriteTag::Answer(cmd);

		if (this->m_readingMemoryChannels)
		{
			channel.MemoryChannel = static_cast<Yaesu::Commands::FT891::MemoryChannelValue>(m_channel);
			m_channels.push_back(channel);
			if (m_editor) {
				m_editor->AddMemoryChannel(channel);
			}
			m_channel++;
			if (m_channel <= 99)
			{
				auto lcmd = Yaesu::Commands::FT891::MemoryWriteTag::Read(static_cast<Yaesu::Commands::FT891::MemoryChannelValue>(m_channel));
				if (m_radio->isOpen())
				{
					m_radio->write(lcmd.c_str(), lcmd.length());
					std::this_thread::sleep_for(std::chrono::microseconds(20));
				}
			}
			else {
				m_readingMemoryChannels = false;

				m_channel = 1;
			}
		}
		else
		{
			if (channel.TAG == Yaesu::Commands::FT891::TagValue::ON)
			{

				ui.VFO->setText(QString(channel.TagString.c_str()).trimmed());
			}
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::MW:
		break;
	case Yaesu::Commands::FT891::CommandType::MX:
	{
		using namespace Yaesu::Commands;
		FT891::MoxSetVal  val = FT891::MoxSet::Answer(cmd);
		switch (val)
		{
		case Yaesu::Commands::FT891::MoxSetVal::OFF:
			ui.ckMox->setChecked(false);
			break;
		case Yaesu::Commands::FT891::MoxSetVal::ON:
			ui.ckMox->setChecked(true);
			break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Narrow::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::NA:
	{
		auto val = Yaesu::Commands::FT891::Narrow::Answer(cmd);
		NarrowState = val;
		QPalette pal = ui.btnNAR->palette();
		switch (val)
		{
		case Yaesu::Commands::FT891::NarrowValue::ON:
			pal.setColor(QPalette::Button, QColor("green"));
			ui.btnNAR->setAutoFillBackground(true);
			ui.btnNAR->setPalette(pal);
			ui.btnNAR->repaint();
			break;

		case Yaesu::Commands::FT891::NarrowValue::OFF:
			pal.setColor(QPalette::Button, defaultbg);
			ui.btnNAR->setAutoFillBackground(true);
			ui.btnNAR->setPalette(pal);
			ui.btnNAR->repaint();
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::NoiseBlankerStatus::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::NB:
	{
		auto val = Yaesu::Commands::FT891::NoiseBlankerStatus::Answer(cmd);
		QPalette pal = ui.btnNB->palette();
		switch (val)
		{
		case Yaesu::Commands::FT891::NoiseBlankerStatusValue::ON:
			pal.setColor(QPalette::Button, QColor("green"));
			ui.btnNB->setAutoFillBackground(true);
			ui.btnNB->setPalette(pal);
			ui.btnNB->repaint();
			break;
		case Yaesu::Commands::FT891::NoiseBlankerStatusValue::OFF:
			pal.setColor(QPalette::Button, defaultbg);
			ui.btnNB->setAutoFillBackground(true);
			ui.btnNB->setPalette(pal);
			ui.btnNB->repaint();
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::NoiseBlankerLevel::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::NL:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			auto val = Yaesu::Commands::FT891::NoiseBlankerLevel::Answer(cmd);
			ui.NBLvl->setValue(val);
			ui.NBLvl->repaint();
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::NoiseReduction::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::NR:
	{
		if (loadingfromdb) {
			this->setEnabled(true);
			loadingfromdb = false;
		}
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			auto val = Yaesu::Commands::FT891::NoiseReduction::Answer(cmd);
			dnr_enabled = static_cast<int>(val);
			if (dnr_enabled)
			{
				QPalette pal = ui.DNR->palette();
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnDNR->setAutoFillBackground(true);
				ui.btnDNR->setPalette(pal);
				ui.btnDNR->repaint();

			}
			else
			{
				QPalette pal = ui.DNR->palette();
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnDNR->setAutoFillBackground(true);
				ui.btnDNR->setPalette(pal);
				ui.btnDNR->repaint();
			}
		}
		if (loadingInit)
		{
			UpdateBandModeRecord(currentBand, currentMode);
			auto e = Yaesu::Commands::FT891::OffSet::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::OI:
	{
		hist.push_back(cmd);
		if (VFOAFreq == VFOBFreq) {
			SetBand();

		}
		Yaesu::Commands::FT891::OppositeInformationValue ov = Yaesu::Commands::FT891::OppositeBandInformation::Answer(cmd);
		VFOBFreq = ov.VFOBFreq;

		std::string dispval = fmt::format("{:d}.{:03}.{:03}", (VFOBFreq - (VFOBFreq % 1000000)) / 1000000, ((VFOBFreq % 1000000) - (VFOBFreq % 1000)) / 1000, (VFOBFreq % 1000));
		ui.VFOB->setText(dispval.c_str());



		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::AntennaTunerControl::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::OS:
	{
		using namespace Yaesu::Commands;
		FT891::OperationType val = FT891::OffSet::Answer(cmd);
		ui.cbRepeaterOffset->setCurrentIndex((int)val);
		ui.cbRepeaterOffset->repaint();
		//fmtabloaded = true;
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::PreAmp::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::PA:
	{
		auto val = Yaesu::Commands::FT891::PreAmp::Answer(cmd);
		QPalette pal = ui.btnIPO->palette();
		switch (val)
		{
		case Yaesu::Commands::FT891::PreAmpValue::IPO:
			pal.setColor(QPalette::Button, QColor("green"));
			ui.btnIPO->setAutoFillBackground(true);
			ui.btnIPO->setPalette(pal);
			ui.btnIPO->repaint();
			break;
		case Yaesu::Commands::FT891::PreAmpValue::AMP:
			pal.setColor(QPalette::Button, defaultbg);
			ui.btnIPO->setAutoFillBackground(true);
			ui.btnIPO->setPalette(pal);
			ui.btnIPO->repaint();
			break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::PowerControl::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::PB:
		break;
	case Yaesu::Commands::FT891::CommandType::PC:
	{
		if (QApplication::mouseButtons() == Qt::MouseButton::NoButton) {
			using namespace Yaesu::Commands;
			int val = FT891::PowerControl::Answer(cmd);
			ui.lvlHFPower->setValue(val);
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::SpeechProcessorLevel::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::PL:
	{
		using namespace Yaesu::Commands;
		int val = FT891::SpeechProcessorLevel::Answer(cmd);
		ui.Comp->setValue(val);
		if (loadingInit)
		{
			auto type = FT891::SpeechProcessorType::ParametricEqualizer;
			auto e = Yaesu::Commands::FT891::SpeechProcessor::Read(type);
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::PR:
	{
		using namespace Yaesu::Commands;
		FT891::SpeechProcessorSetting val = FT891::SpeechProcessor::Answer(cmd);
		switch (val.type)
		{
		case FT891::SpeechProcessorType::ParametricEqualizer:
		{
			switch (val.state)
			{
			case FT891::SpeechProcessorState::OFF:
			{
				QPalette pal = ui.btnEQ->palette();
				QColor bgcolor = pal.color(QPalette::Button);
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnEQ->setAutoFillBackground(true);
				ui.btnEQ->setPalette(pal);
				ui.btnEQ->repaint();
				if (loadingInit)
				{
					auto type = FT891::SpeechProcessorType::Processor;
					auto e = Yaesu::Commands::FT891::SpeechProcessor::Read(type);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
			case FT891::SpeechProcessorState::ON:
			{
				QPalette pal = ui.btnEQ->palette();
				QColor bgcolor = pal.color(QPalette::Button);
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnEQ->setAutoFillBackground(true);
				ui.btnEQ->setPalette(pal);
				ui.btnEQ->repaint();
				if (loadingInit)
				{
					auto type = FT891::SpeechProcessorType::Processor;
					auto e = Yaesu::Commands::FT891::SpeechProcessor::Read(type);
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
			default:
				break;
			}
			break;

		}
		case FT891::SpeechProcessorType::Processor:
		{
			switch (val.state)
			{
			case FT891::SpeechProcessorState::OFF:
			{
				QPalette pal = ui.btnPRC->palette();
				QColor bgcolor = pal.color(QPalette::Button);
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnPRC->setAutoFillBackground(true);
				ui.btnPRC->setPalette(pal);
				ui.btnPRC->repaint();
				if (loadingInit)
				{

					auto e = Yaesu::Commands::FT891::RFAttenuator::Read();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
			case FT891::SpeechProcessorState::ON:
			{
				QPalette pal = ui.btnPRC->palette();
				QColor bgcolor = pal.color(QPalette::Button);
				pal.setColor(QPalette::Button, QColor("green"));
				ui.btnPRC->setAutoFillBackground(true);
				ui.btnPRC->setPalette(pal);
				ui.btnPRC->repaint();
				if (loadingInit)
				{

					auto e = Yaesu::Commands::FT891::RFAttenuator::Read();
					m_radio->write(e.c_str(), e.length());
					m_radio->flush();
				}
			}
			break;
			default:
				break;
			}

		}
		break;
		default:
			break;
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::PS:
	{
		auto state = Yaesu::Commands::FT891::PowerSwitch::Answer(cmd);
		QPalette pal = ui.btnPWR->palette();
		switch (state)
		{
		case Yaesu::Commands::FT891::PowerSwitchValue::ON:
			if (!loadingInit)
			{
				readingPower = false;
				
				//m_radio->waitForReadyRead();
				Init();
			}
			pal.setColor(QPalette::Button, QColor("red"));
			ui.btnPWR->setAutoFillBackground(true);
			ui.btnPWR->setPalette(pal);
			ui.btnPWR->update();
			break;
		case Yaesu::Commands::FT891::PowerSwitchValue::OFF: {
			if (readingPower)
			{
				readingPower = false;
				ui.statusBar->clearMessage();
			}
			pal.setColor(QPalette::Button, defaultbg.value());

			ui.btnPWR->setAutoFillBackground(true);
			ui.btnPWR->setPalette(pal);
			ui.btnPWR->update();
		}
														  break;
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::RA:
	{
		auto val = Yaesu::Commands::FT891::RFAttenuator::Answer(cmd);
		QPalette pal = ui.btnATT->palette();
		switch (val)
		{
		case Yaesu::Commands::FT891::RfAttenuatorState::ON:
			pal.setColor(QPalette::Button, QColor("green"));
			ui.btnATT->setAutoFillBackground(true);
			ui.btnATT->setPalette(pal);
			ui.btnATT->repaint();
			break;
		case Yaesu::Commands::FT891::RfAttenuatorState::OFF:
			pal.setColor(QPalette::Button, defaultbg);
			ui.btnATT->setAutoFillBackground(true);
			ui.btnATT->setPalette(pal);
			ui.btnATT->repaint();
			break;

		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::RFGain::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::RG:
	{
		if (QApplication::mouseButtons() == Qt::NoButton) {
			ui.RFGain->setValue(Yaesu::Commands::FT891::RFGain::Answer(cmd));
			
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::NoiseReductionLevel::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::RI:
	{
		auto val = Yaesu::Commands::FT891::RadioInformation::Answer(cmd);
		switch (val.Type)
		{
		case Yaesu::Commands::FT891::InformationType::HI_SWR:
			switch (val.Value)
			{
			case Yaesu::Commands::FT891::InformationState::ON:
				break;
			case Yaesu::Commands::FT891::InformationState::OFF:
				break;
			}
			break;
		case Yaesu::Commands::FT891::InformationType::PLAY:
			switch (val.Value)
			{
			case Yaesu::Commands::FT891::InformationState::ON:
				break;
			case Yaesu::Commands::FT891::InformationState::OFF:
				ui.btnCh1Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
				ui.btnCh2Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
				ui.btnCh3Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
				ui.btnCh4Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
				ui.btnCh5Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
				break;
			}
			break;
		case Yaesu::Commands::FT891::InformationType::REC:
			switch (val.Value)
			{
			case Yaesu::Commands::FT891::InformationState::ON:
				break;
			case Yaesu::Commands::FT891::InformationState::OFF:
				break;
			}
			break;
		case Yaesu::Commands::FT891::InformationType::RX_LED:
			switch (val.Value)
			{
			case Yaesu::Commands::FT891::InformationState::ON:
				break;
			case Yaesu::Commands::FT891::InformationState::OFF:
				break;
			}
			break;
		case Yaesu::Commands::FT891::InformationType::TX_LED:
			switch (val.Value)
			{
			case Yaesu::Commands::FT891::InformationState::ON:
				break;
			case Yaesu::Commands::FT891::InformationState::OFF:
				break;
			}
			break;

		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::RM:
	{
		try
		{
			auto scene = ui.gv_meter->scene();
			if (scene != nullptr)
			{
				for (auto a : scene->items())
				{
					scene->removeItem(a);
					delete a;
				}
				scene->setBackgroundBrush(*white);
				scene->clear();
				auto rm = Yaesu::Commands::FT891::ReadMeter::Answer(cmd);

				QRect smetergeo = ui.gv_meter->contentsRect();
				scene->setSceneRect(smetergeo);

				double width = 0.0;
				float percent = (float)rm.Value / 255.0f;
				Yaesu::Commands::FT891::ReadMeterType recType;
				if (m_transmitting) {
					switch (rm.Type)
					{
					case Yaesu::Commands::FT891::ReadMeterType::AutoA:
						switch (m_meterType)
						{
						case Yaesu::Commands::FT891::MeterType::COMP:
							recType = Yaesu::Commands::FT891::ReadMeterType::COMP;
							//width = (float)scene->width() * percent;
							break;
						case Yaesu::Commands::FT891::MeterType::ALC:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::ALC;
							break;
						case Yaesu::Commands::FT891::MeterType::PO:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::PO;
							break;
						case Yaesu::Commands::FT891::MeterType::SWR:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::SWR;
							break;
						case Yaesu::Commands::FT891::MeterType::ID:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::ID;
							break;
						}
						cmd = Yaesu::Commands::FT891::ReadMeter::Read(recType);
						m_radio->write(cmd.c_str(), cmd.length());
						m_radio->flush();

						break;
					case Yaesu::Commands::FT891::ReadMeterType::AutoB:
						switch (m_meterType)
						{
						case Yaesu::Commands::FT891::MeterType::COMP:
							recType = Yaesu::Commands::FT891::ReadMeterType::COMP;
							//width = (float)scene->width() * percent;
							break;
						case Yaesu::Commands::FT891::MeterType::ALC:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::ALC;
							break;
						case Yaesu::Commands::FT891::MeterType::PO:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::PO;
							break;
						case Yaesu::Commands::FT891::MeterType::SWR:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::SWR;
							break;
						case Yaesu::Commands::FT891::MeterType::ID:
							//width = (float)scene->width() * percent;
							recType = Yaesu::Commands::FT891::ReadMeterType::ID;
							break;
						}
						cmd = Yaesu::Commands::FT891::ReadMeter::Read(recType);
						m_radio->write(cmd.c_str(), cmd.length());
						m_radio->flush();
						break;
					default:
						recType = rm.Type;

					}
				}
				else
				{
					recType = rm.Type;
					ui.gvALC->setVisible(false);
				}

				if (recType == rm.Type ) {
					switch (rm.Type) {
					case Yaesu::Commands::FT891::ReadMeterType::S:
						width = (float)scene->width() * percent;
						if (percent > 0.34 + previousPercent && previousPercent > 0.0) {
							auto lcmd = Yaesu::Commands::FT891::Busy::Read();
							m_radio->write(lcmd.c_str(), lcmd.length());
						}
						else
						{
							auto pal = ui.lblBusyIndicator->palette();
							pal.setColor(QPalette::Window, defaultbg);

							ui.lblBusyIndicator->setAutoFillBackground(true);
							ui.lblBusyIndicator->setPalette(pal);
							ui.lblBusyIndicator->repaint();
						}
						previousPercent = percent;
						break;
					case Yaesu::Commands::FT891::ReadMeterType::AutoA:
					{


							width = (float)scene->width() * percent;
							if (percent > 0.034 + previousPercent && previousPercent > 0.0) {
								auto lcmd = Yaesu::Commands::FT891::Busy::Read();
								m_radio->write(lcmd.c_str(), lcmd.length());
							}
							else
							{
								auto pal = ui.lblBusyIndicator->palette();
								pal.setColor(QPalette::Window, defaultbg);

								ui.lblBusyIndicator->setAutoFillBackground(true);
								ui.lblBusyIndicator->setPalette(pal);
								ui.lblBusyIndicator->repaint();
							}
							previousPercent = percent;
						
					}
					break;
					case Yaesu::Commands::FT891::ReadMeterType::AutoB:
						width = (float)scene->width() * percent;
						if (percent > 0.034 + previousPercent && previousPercent > 0.0) {
							auto lcmd = Yaesu::Commands::FT891::Busy::Read();
							m_radio->write(lcmd.c_str(), lcmd.length());
						}
						else
						{
							auto pal = ui.lblBusyIndicator->palette();
							pal.setColor(QPalette::Window, defaultbg);

							ui.lblBusyIndicator->setAutoFillBackground(true);
							ui.lblBusyIndicator->setPalette(pal);
							ui.lblBusyIndicator->repaint();
						}
						previousPercent = percent;
						
						
						break;
					case Yaesu::Commands::FT891::ReadMeterType::COMP:
						width = (float)scene->width() * percent;
						break;
					case Yaesu::Commands::FT891::ReadMeterType::ALC:
						ui.gvALC->setVisible(true);
						{
							
							auto scene = ui.gvALC->scene();
							if (scene != nullptr && scene->items().count() == 0)
							{
								smeter_pen->setWidth(5);
							
								auto geo = ui.gvALC->contentsRect();

								QLine leftSide = QLine{ 0,0,0,geo.height() - 2 };
								scene->addLine(leftSide, *smeter_pen);
								QLine bottomLine = QLine(0, geo.height() - 2, geo.width(), geo.height() - 2);
								scene->addLine(bottomLine, *smeter_pen);
								QLine rightSide{ geo.width(),0,geo.width(), geo.height() - 2 };
								scene->addLine(rightSide, *smeter_pen);
								scene->update();
									
								
							}
						}
						width = (float)scene->width() * percent;
						break;
					case Yaesu::Commands::FT891::ReadMeterType::PO:
						percent = (float)rm.Value / 255;
						width = (float)scene->width() * percent;
						break;
					case Yaesu::Commands::FT891::ReadMeterType::SWR:
						width = (float)scene->width() * percent;
						break;
					case Yaesu::Commands::FT891::ReadMeterType::ID:
						width = (float)scene->width() * percent;
						break;
					default:
						if (percent > 0.05 + previousPercent) {
							auto lcmd = Yaesu::Commands::FT891::Busy::Read();
							m_radio->write(lcmd.c_str(), lcmd.length());
						}
						else
						{
							auto pal = ui.lblBusyIndicator->palette();
							pal.setColor(QPalette::Window, defaultbg);

							ui.lblBusyIndicator->setAutoFillBackground(true);
							ui.lblBusyIndicator->setPalette(pal);
							ui.lblBusyIndicator->repaint();
						}
						previousPercent = percent;
						break;
					}

					meter.setTopLeft(smetergeo.topLeft());

					meter.setWidth(width);
					meter.setHeight((float)smetergeo.height());


					scene->addRect(meter, *smeter_pen, *smeter_brush);

					scene->update();
				}
			}

		}
		catch (std::bad_alloc& e)
		{
			OutputDebugString(e.what());
		}
		catch (std::exception& e)
		{
			OutputDebugString(e.what());
		}


	}
	break;
	case Yaesu::Commands::FT891::CommandType::RL:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			ui.DNR->setValue(Yaesu::Commands::FT891::NoiseReductionLevel::Answer(cmd));
			if (loadingInit)
			{
				UpdateBandModeRecord(currentBand, currentMode);
				auto e = Yaesu::Commands::FT891::Scan::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}


	}
	break;
	case Yaesu::Commands::FT891::CommandType::RS:
	{
		using namespace Yaesu::Commands;
		FT891::RadioStatusValue rs = Yaesu::Commands::FT891::RadioStatus::Answer(cmd);

		switch (rs)
		{
		case FT891::RadioStatusValue::MENU:
			ui.statusBar->showMessage("Menu Mode Activated!", 1000);
			break;
		case FT891::RadioStatusValue::NORMAL:
			ui.statusBar->showMessage("Normal Mode Activated!", 1000);
			break;
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SC:
	{
		using namespace Yaesu::Commands;
		FT891::ScanState state = FT891::Scan::Answer(cmd);
		switch (state)
		{
		case Yaesu::Commands::FT891::ScanState::OFF:
		{
			auto platte = ui.btnScan->palette();
			platte.setColor(QPalette::Button, defaultbg);
			ui.btnScan->setAutoFillBackground(true);
			ui.btnScan->setPalette(platte);
			ui.btnScan->repaint();

		}
		break;
		case Yaesu::Commands::FT891::ScanState::UP:
		{
			auto platte = ui.btnScan->palette();
			platte.setColor(QPalette::Button, QColor("green"));
			ui.btnScan->setAutoFillBackground(true);
			ui.btnScan->setPalette(platte);
			ui.btnScan->repaint();
			ui.rbScanUp->setChecked(true);
		}
		break;
		case Yaesu::Commands::FT891::ScanState::DOWN:
			auto platte = ui.btnScan->palette();
			platte.setColor(QPalette::Button, QColor("green"));
			ui.btnScan->setAutoFillBackground(true);
			ui.btnScan->setPalette(platte);
			ui.btnScan->repaint();
			ui.rbScanDown->setChecked(true);
			break;
		}
		if (loadingInit)
		{
			auto cmd = FT891::CWBreakInDelay::Read();
			m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SD:
	{
		using namespace Yaesu::Commands;
		int delayval = FT891::CWBreakInDelay::Answer(cmd);
		ui.lvlCWBKINDelay->setValue(delayval);
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::Width::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SH:
	{

		if (ui.cbWidth->isVisible()) {
			if (!cbbandChanged) {
				auto WidthVal = Yaesu::Commands::FT891::Width::Answer(cmd);
				CalculateWidth(WidthVal);
				if (bandChanged) {
					if (receivedInformation) {

						bandChanged = false; receivedInformation = false;
						if (!loadingfromdb) {

							UpdateFromBandModeRecord(this->currentBand, this->currentMode);
						}
						else
						{
							loadingfromdb = false;
						}
					}
				}
				else if (modeChanged)
				{
					if (!loadingfromdb) {

						UpdateFromBandModeRecord(this->currentBand, this->currentMode);
						modeChanged = false;
					}
					else
					{
						loadingfromdb = false;
					}
				}
			}
			else {
				cmd = Yaesu::Commands::FT891::AntennaTunerControl::Read();
				m_radio->write(cmd.c_str(), cmd.length());
				m_radio->flush();
			}
		}
		if (loadingInit)
		{
			UpdateBandModeRecord(currentBand, currentMode);
			auto e = Yaesu::Commands::FT891::SquelchLevel::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SM:
	{
		auto val = Yaesu::Commands::FT891::SMeterReading::Answer(cmd);
		auto scene = ui.gv_meter->scene();
		if (scene != nullptr)
		{
			for (auto a : scene->items())
			{
				scene->removeItem(a);
				delete a;
			}
			scene->setBackgroundBrush(*white);
			scene->clear();
			auto rm = Yaesu::Commands::FT891::ReadMeter::Answer(cmd);

			QRect smetergeo = ui.gv_meter->geometry();
			scene->setSceneRect(smetergeo);


			double width;
			float percent = (float)rm.Value / 255.0f;
			auto mt = ui.cbMeterType->currentText();
			if (mt == "SWR") {
				width = (float)smetergeo.width() * percent;
			}
			else if (mt == "ID")
			{
				width = (float)smetergeo.width() * percent;
			}
			else if (mt == "ALC")
			{
				width = (float)smetergeo.width() * percent;
			}
			else if (mt == "COMP")
			{
				width = (float)smetergeo.width() * percent;
			}
			width = (float)smetergeo.width() * percent;
			meter.setLeft((float)smetergeo.left());
			meter.setTop((float)smetergeo.top());
			meter.setWidth(width);
			meter.setHeight((float)smetergeo.height());

			scene->addRect(meter, *smeter_pen, *smeter_brush);
			scene->update();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SQ:
	{
		if (QApplication::mouseButtons() == Qt::NoButton) {
			ui.Squelch->setValue(Yaesu::Commands::FT891::SquelchLevel::Answer(cmd));
			if (loadingInit)
			{
				auto e = Yaesu::Commands::FT891::Split::Read();
				m_radio->write(e.c_str(), e.length());
				m_radio->flush();
			}
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::ST:
	{
		using namespace Yaesu::Commands;
		FT891::SplitValue val = FT891::Split::Answer(cmd);
		switch (val)
		{
		case Yaesu::Commands::FT891::SplitValue::OFF:
		{
			ui.ckTXWatch->setEnabled(false);
		}
		break;
		case Yaesu::Commands::FT891::SplitValue::ON:
		{
			ui.ckTXWatch->setEnabled(true);
		}
		break;
		case Yaesu::Commands::FT891::SplitValue::ON_5KU:
		{
			ui.ckTXWatch->setEnabled(true);
		}
		break;
		default:
			break;
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::VoxDelayTime::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::SV:
		break;
	case Yaesu::Commands::FT891::CommandType::TS:
		break;
	case Yaesu::Commands::FT891::CommandType::TX:
	{

		auto ret = Yaesu::Commands::FT891::TxSet::Answer(cmd);
		switch (ret)
		{
		case Yaesu::Commands::FT891::TxSetValue::RadioTxOff_CatTxOff:
			m_transmitting = false;
			ui.lblS1->setVisible(true);
			ui.lblS3->setVisible(true);
			ui.lblS5->setVisible(true);
			ui.lblS7->setVisible(true);
			ui.lblS9->setVisible(true);
			ui.lblS20db->setVisible(true);
			ui.lblS40db->setVisible(true);
			ui.lblS60->setVisible(true);

			ui.lbl0watt->setVisible(false);
			ui.lbl10watt->setVisible(false);
			ui.lbl20watt->setVisible(false);
			ui.lbl50watt->setVisible(false);
			ui.lbl100watt->setVisible(false);
			ui.lbl150watt->setVisible(false);

			ui.lbl1swr->setVisible(false);
			ui.lbl2swr->setVisible(false);
			ui.lbl3swr->setVisible(false);
			ui.lblinfswr->setVisible(false);
			ui.lbl1_5swr->setVisible(false);

			ui.lbl0A->setVisible(false);
			ui.lbl5A->setVisible(false);
			ui.lbl10A->setVisible(false);
			ui.lbl15A->setVisible(false);
			ui.lbl20A->setVisible(false);
			ui.lbl25A->setVisible(false);
			ui.lbl30A->setVisible(false);
			ui.gvALC->setVisible(false);

			ui.lblComp_0->setVisible(false);
			ui.lblComp_5->setVisible(false);
			ui.lblComp_10->setVisible(false);
			ui.lblComp_15->setVisible(false);
			ui.lblComp_20->setVisible(false);
			ui.lblComp_25->setVisible(false);
			ui.lblComp_30->setVisible(false);
			{
				auto pal = ui.lblBusyIndicator->palette();
				pal.setColor(QPalette::Window, defaultbg);

				ui.lblBusyIndicator->setAutoFillBackground(true);
				ui.lblBusyIndicator->setPalette(pal);
				ui.lblBusyIndicator->repaint();
			}
			ui.gvALC->setVisible(false);
			break;
		case Yaesu::Commands::FT891::TxSetValue::RadioTxOff_CatTxOn:
			m_transmitting = true;
			ui.lblS1->setVisible(false);
			ui.lblS3->setVisible(false);
			ui.lblS5->setVisible(false);
			ui.lblS7->setVisible(false);
			ui.lblS9->setVisible(false);
			ui.lblS20db->setVisible(false);
			ui.lblS40db->setVisible(false);
			ui.lblS60->setVisible(false);
			{
				auto pal = ui.lblBusyIndicator->palette();
				pal.setColor(QPalette::Window, Qt::red);

				ui.lblBusyIndicator->setAutoFillBackground(true);
				ui.lblBusyIndicator->setPalette(pal);
				ui.lblBusyIndicator->repaint();
			}
			switch (m_meterType)
			{
			case Yaesu::Commands::FT891::MeterType::COMP:
				break;
			case Yaesu::Commands::FT891::MeterType::ALC:
				ui.gvALC->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::PO:
				ui.lbl0watt->setVisible(true);
				ui.lbl10watt->setVisible(true);
				ui.lbl20watt->setVisible(true);
				ui.lbl50watt->setVisible(true);
				ui.lbl100watt->setVisible(true);
				ui.lbl150watt->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::SWR:
				ui.lbl1swr->setVisible(true);
				ui.lbl2swr->setVisible(true);
				ui.lbl3swr->setVisible(true);
				ui.lblinfswr->setVisible(true);
				ui.lbl1_5swr->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::ID:
				ui.lbl0A->setVisible(true);
				ui.lbl5A->setVisible(true);
				ui.lbl10A->setVisible(true);
				ui.lbl15A->setVisible(true);
				ui.lbl20A->setVisible(true);
				ui.lbl25A->setVisible(true);
				ui.lbl30A->setVisible(true);
				break;
			default:
				break;
			}
			break;
		case Yaesu::Commands::FT891::TxSetValue::RadioTxOn_CatTxOff:
			m_transmitting = true;
			ui.lblS1->setVisible(false);
			ui.lblS3->setVisible(false);
			ui.lblS5->setVisible(false);
			ui.lblS7->setVisible(false);
			ui.lblS9->setVisible(false);
			ui.lblS20db->setVisible(false);
			ui.lblS40db->setVisible(false);
			ui.lblS60->setVisible(false);
			{
				auto pal = ui.lblBusyIndicator->palette();
				pal.setColor(QPalette::Window, Qt::red);

				ui.lblBusyIndicator->setAutoFillBackground(true);
				ui.lblBusyIndicator->setPalette(pal);
				ui.lblBusyIndicator->repaint();
			}
			switch (m_meterType)
			{
			case Yaesu::Commands::FT891::MeterType::COMP:
				ui.lblComp_0->setVisible(true);
				ui.lblComp_5->setVisible(true);
				ui.lblComp_10->setVisible(true);
				ui.lblComp_15->setVisible(true);
				ui.lblComp_20->setVisible(true);
				ui.lblComp_25->setVisible(true);
				ui.lblComp_30->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::ALC:
				ui.gvALC->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::PO:
				ui.lbl0watt->setVisible(true);
				ui.lbl10watt->setVisible(true);
				ui.lbl20watt->setVisible(true);
				ui.lbl50watt->setVisible(true);
				ui.lbl100watt->setVisible(true);
				ui.lbl150watt->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::SWR:
				ui.lbl1swr->setVisible(true);
				ui.lbl2swr->setVisible(true);
				ui.lbl3swr->setVisible(true);
				ui.lblinfswr->setVisible(true);
				ui.lbl1_5swr->setVisible(true);
				break;
			case Yaesu::Commands::FT891::MeterType::ID:
				ui.lbl0A->setVisible(true);
				ui.lbl5A->setVisible(true);
				ui.lbl10A->setVisible(true);
				ui.lbl15A->setVisible(true);
				ui.lbl20A->setVisible(true);
				ui.lbl25A->setVisible(true);
				ui.lbl30A->setVisible(true);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::UL:
	{
		using namespace Yaesu::Commands;
		FT891::LockValue v = FT891::PLLUnlockStatus::Answer(cmd);
		switch (v)
		{
		case Yaesu::Commands::FT891::LockValue::Locked:
			ui.statusBar->showMessage("PLL Locked", 2000);
			break;
		case Yaesu::Commands::FT891::LockValue::Unlocked:
		{
			ui.statusBar->clearMessage();
			ui.statusBar->showMessage("PLL Unlocked!", 5000);
		}
		break;
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::VD:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			ui.sbVoxDelay->setValue(Yaesu::Commands::FT891::VoxDelayTime::Answer(cmd));
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::VoxGain::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}

	}
	break;
	case Yaesu::Commands::FT891::CommandType::VG:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			ui.VoxLevel->setValue(Yaesu::Commands::FT891::VoxGain::Answer(cmd));
		}
		if (loadingInit)
		{
			auto e = Yaesu::Commands::FT891::VoxStatus::Read();
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::VX:
	{
		if (QApplication::mouseButtons() == Qt::NoButton)
		{
			auto val = Yaesu::Commands::FT891::VoxStatus::Answer(cmd);
			switch (val)
			{
			case Yaesu::Commands::FT891::VoxStatusValue::OFF:
			{
				QPalette pal = ui.btnVox->palette();
				pal.setColor(QPalette::Button, defaultbg);
				ui.btnVox->setAutoFillBackground(true);
				ui.btnVox->setPalette(pal);
				ui.btnVox->repaint();
			}
			break;
			case Yaesu::Commands::FT891::VoxStatusValue::ON:
			{
				QPalette pal = ui.btnVox->palette();
				QColor bgcolor = pal.color(QPalette::Button);
				if (bgcolor != QColor("green")) {

					pal.setColor(QPalette::Button, QColor("green"));
					ui.btnVox->setAutoFillBackground(true);
					ui.btnVox->setPalette(pal);
					ui.btnVox->repaint();
				}
			}
			break;
			default:
				break;
			}
		}
		if (loadingInit)
		{
			ui.statusBar->clearMessage();
			loadingInit = false;
			UpdateFromBandModeRecord(this->currentBand, this->currentMode);
			
		}
	}
	break;
	case Yaesu::Commands::FT891::CommandType::UN:
		if (this->m_readingMemoryChannels)
		{
			m_channel++;
			if (m_channel <= 99)
			{
				auto lcmd = Yaesu::Commands::FT891::MemoryWriteTag::Read(static_cast<Yaesu::Commands::FT891::MemoryChannelValue>(m_channel));
				if (m_radio->isOpen())
				{
					m_radio->write(lcmd.c_str(), lcmd.length());
					std::this_thread::sleep_for(std::chrono::microseconds(20));
				}
			}
			else {
				m_readingMemoryChannels = false;
				m_channel = 1;
			}
		}
		else {

			if (prevcmd.length() > 0) {
				std::string mess = fmt::format("unknown after {:s} was sent!\r\n", prevcmd);
				OutputDebugString(mess.c_str());
			}

		}
		break;
	}
}

void QtFT891::OnRadioRead()
{

	bool receivedIF = false;
	bool receivedOI = false;

	while (m_radio->bytesAvailable()) {
		auto arr = m_radio->readAll();
		int index = arr.indexOf('\0');
		while (index != -1 && index != arr.length() - 1)
		{
			arr.remove(index, 1);
			index = arr.indexOf('\0');
		}
		auto block = arr.constData();
		
		m_buffer.append(block);
	}

	std::size_t pos = 0;
	
	while ((pos = m_buffer.find_first_of(";")) != std::string::npos)
	{

		std::string cmd = m_buffer.substr(0, (pos + 1));
		
		auto displycmd = fmt::format("{:s}\r\n", cmd);
		OutputDebugStringA(displycmd.c_str());
		m_buffer = m_buffer.erase(0, pos + 1);		
		ProcessCommmand(cmd);
		prevcmd = cmd;
	}
}
