#include "QtFT891.h"
#include "Cat.h"
#include <string>
#include <fmt/core.h>
#include <vector>
#include <sstream>
#include <string>
#include <thread>
#include <windows.h>


void QtFT891::on_Volume_valueChanged(int val)
{
    if (m_radio->isOpen())
    {    
            auto cat = Yaesu::Commands::FT891::VolumeLevel::Set(val);
			
            m_radio->write(cat.c_str(), cat.length());        
    }
}

void QtFT891::on_RFGain_valueChanged(int val)
{
    if (m_radio->isOpen())
    {
        auto cat = Yaesu::Commands::FT891::RFGain::Set(val);
		
        m_radio->write(cat.c_str(), cat.length());
    }
}

void QtFT891::on_Squelch_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cat = Yaesu::Commands::FT891::SquelchLevel::Set(val);
		
		m_radio->write(cat.c_str(), cat.length());
	}
}

void QtFT891::OnMicGainChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cat = Yaesu::Commands::FT891::MicGain::Set(val);
		
		m_radio->write(cat.c_str(), cat.length());
	}
}

void QtFT891::on_MON_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
        Yaesu::Commands::FT891::MonitorLevelValue mv;
        mv.f = Yaesu::Commands::FT891::MonitorFunction::MontiorLevel;
        mv.val.iVal = val;
		auto cat = Yaesu::Commands::FT891::MonitorLevel::Set(mv);
		
		m_radio->write(cat.c_str(), cat.length());
	}
}

void QtFT891::on_DNR_valueChanged(int val)
{
	if (ui.DNR->isVisible())
	{
		auto cat = Yaesu::Commands::FT891::NoiseReductionLevel::Set(val);
		
		m_radio->write(cat.c_str(), cat.length());
		if (bandChanged) {
			if (!receivedInformation) {
				UpdateBandModeRecord(-1,-1);
			}
		}
		else {
			UpdateBandModeRecord(-1,-1);
		}
	}
	
}

void QtFT891::on_NBLvl_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cat = Yaesu::Commands::FT891::NoiseBlankerLevel::Set(val);
		
		m_radio->write(cat.c_str(), cat.length());
	}
}

void QtFT891::on_MemoryEditor_destroyed(QObject* obj)
{
	obj = nullptr;
	m_editor = nullptr;
}

void QtFT891::on_ckMox_stateChanged(int val)
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		auto cmd = FT891::MoxSet::Set(static_cast<FT891::MoxSetVal>(val > 0 ? 1 : 0));
		
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_ckAPF_stateChanged(int val)
{
	auto chkstate = val > 0;
	ui.label_4->setEnabled(chkstate);
	ui.cbApfWidth->setEnabled(chkstate);
	ui.lblAPFPeak->setEnabled(chkstate);
	ui.lvlAPF->setEnabled(chkstate);
	ui.lblApfLevelValue->setEnabled(chkstate);
}

void QtFT891::on_ContourFrequency_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		Yaesu::Commands::FT891::ContourValue cval;
		cval.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;
		cval.Value.Freq = val;
		auto cmd = Yaesu::Commands::FT891::Contour::Set(cval);
		
		m_radio->write(cmd.c_str(), cmd.length());
		contour_freq = val;
	}
}

void QtFT891::on_ContourLevel_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetCountourLevel(val);
		
		m_radio->write(cmd.c_str(), cmd.length());
		contour_level = val;
	}
}

void QtFT891::on_ContourWidth_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetCountourWidth(val);
		m_radio->write(cmd.c_str(), cmd.length());
		contour_width = val;
	}
}

void QtFT891::on_btnQSPL_clicked()
{
	using namespace Yaesu::Commands;
	std::string cmd;

	auto pal = ui.btnQSPL->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	if (bgcolor != QColor("green"))
	{

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnQSPL->setAutoFillBackground(true);
		ui.btnQSPL->setPalette(pal);
		ui.btnQSPL->repaint();
		VFOBPrevFreq = VFOBFreq;
		cmd = "QS;";
	
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnQSPL->setAutoFillBackground(true);
		ui.btnQSPL->setPalette(pal);
		ui.btnQSPL->repaint();
		cmd = FT891::Split::Set(FT891::SplitValue::OFF);
		cmd += FT891::VFO_B_FREQ::Set(VFOBPrevFreq);
	}
	if (m_radio->isOpen() && cmd.length() > 0)
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}

}
void QtFT891::on_btnSPL_clicked()
{
	using namespace Yaesu::Commands;
	std::string cmd;

	auto pal = ui.btnSPL->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	if (bgcolor != QColor("green") && bgcolor != QColor("blue"))
	{

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnSPL->setAutoFillBackground(true);
		ui.btnSPL->setPalette(pal);
		ui.btnSPL->repaint();
		cmd += FT891::Split::Set(FT891::SplitValue::ON);
		
	}
	else if (bgcolor == QColor("green"))
	{
		pal.setColor(QPalette::Button, QColor("blue"));
		ui.btnSPL->setAutoFillBackground(true);
		ui.btnSPL->setPalette(pal);
		ui.btnSPL->repaint();		
		cmd = FT891::VFO_A_TO_VFO_B::Set();
		cmd += FT891::VFO_B_FREQ::Set(ui.VFOB->text().remove('.').toInt() + 4000);
		cmd += FT891::Split::Set(FT891::SplitValue::ON_5KU);
	}
	else if (bgcolor == QColor("blue"))
	{
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnSPL->setAutoFillBackground(true);
		ui.btnSPL->setPalette(pal);
		ui.btnSPL->repaint();
		cmd = FT891::VFO_A_TO_VFO_B::Set();
		cmd += FT891::Split::Set(FT891::SplitValue::OFF);
	}

	if (m_radio->isOpen() && cmd.length() > 0)
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
}

void QtFT891::on_btnSwapVandM_clicked()
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::VFO_A_toMemoryChannel::Set();
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnMemEdit_clicked()
{
	
	using namespace Yaesu::Commands;
	if (m_readingMemoryChannels == false)
	{
		m_channels.clear();
		m_readingMemoryChannels = true;
		if (!m_editor)
		{

			m_editor = new MemoryChannelEditorUI(this);
			m_editor->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
			connect(m_editor, &QWidget::destroyed, this, &QtFT891::on_MemoryEditor_destroyed);
		}

		m_editor->setModal(true);	
		m_editor->show();
		auto chan = static_cast<FT891::MemoryChannelValue>(1);
		auto cmd = FT891::MemoryWriteTag::Read(chan);
		if (m_radio->isOpen())
		{
			m_radio->write(cmd.c_str(), cmd.length());
			
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::on_btnNotch_clicked()
{

	auto pal = ui.btnNotch->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	if (bgcolor != QColor("green"))
	{
		
		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnNotch->setAutoFillBackground(true);
		ui.btnNotch->setPalette(pal);
		ui.btnNotch->repaint();
		Yaesu::Commands::FT891::ManualNotchValue val;
		val.Command = Yaesu::Commands::FT891::NotchCommandType::ON_OFF;
		val.Value.state = Yaesu::Commands::FT891::NotchState::ON;
		auto cmd = Yaesu::Commands::FT891::ManualNotch::Set(val);
		m_radio->write(cmd.c_str(), cmd.length());
		
		cmd = Yaesu::Commands::FT891::ManualNotch::Read(Yaesu::Commands::FT891::NotchCommandType::ON_OFF);
		m_radio->write(cmd.c_str(), cmd.length());
		
		cmd = Yaesu::Commands::FT891::ManualNotch::Read(Yaesu::Commands::FT891::NotchCommandType::LEVEL);
		m_radio->write(cmd.c_str(), cmd.length());
		
		cmd = Yaesu::Commands::FT891::Menu::ReadIFNotchWidth();
		m_radio->write(cmd.c_str(), cmd.length());

	}
	else
	{
	
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnNotch->setAutoFillBackground(true);
		ui.btnNotch->setPalette(pal);
		ui.btnNotch->repaint();
		Yaesu::Commands::FT891::ManualNotchValue val;
		val.Command = Yaesu::Commands::FT891::NotchCommandType::ON_OFF;
		val.Value.state = Yaesu::Commands::FT891::NotchState::OFF;
		auto cmd = Yaesu::Commands::FT891::ManualNotch::Set(val);
		m_radio->write(cmd.c_str(), cmd.length());
	
		cmd = Yaesu::Commands::FT891::ManualNotch::Read(Yaesu::Commands::FT891::NotchCommandType::ON_OFF);
	
		m_radio->write(cmd.c_str(), cmd.length());
		
	}
}

void QtFT891::on_cbApfWidthActivated(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAPFWidth(static_cast<Yaesu::Commands::FT891::APFWidthValue>(val));
	
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbClarSelectActivated(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetClarSelect(static_cast<Yaesu::Commands::FT891::ClarSelectValue>(val));
	
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbModeActivated(int val)
{
	if (ui.cbMode->hasFocus())
	{
		ui.chkbxKeyerEnable->setEnabled(false);
		using namespace Yaesu::Commands::FT891;
		if (m_radio->isOpen())
		{
			currentMode = val;
			std::string cmd;
			modeChanged = true;
			switch (val)
			{
			case 0://"LSB", 0, O
				cmd = Menu::SetSSBBFO(BfoValue::LSB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::SSB_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());

				break;
			case 1://"USB", 0, O
				cmd = Menu::SetSSBBFO(BfoValue::USB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::SSB_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 2:	//"SSB-AUTO",	
				cmd = Menu::SetSSBBFO(BfoValue::AUTO);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::SSB_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 3://"CW-L",0,On
				ui.chkbxKeyerEnable->setEnabled(true);
				cmd = Menu::SetCWBFO(BfoValue::LSB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::CW);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 4://"CW-U", 0 ,
				ui.chkbxKeyerEnable->setEnabled(true);
				cmd = Menu::SetCWBFO(BfoValue::USB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::CW);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 5://"CW-AUTO", 
				ui.chkbxKeyerEnable->setEnabled(true);
				cmd = Menu::SetCWBFO(BfoValue::AUTO);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::CW_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());

				break;
			case 6:	//R-L
				cmd = Menu::SetRTTYBFO(DataBfoValue::LSB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::RTTY_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 7://R-U
				cmd = Menu::SetRTTYBFO(DataBfoValue::USB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::RTTY_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 8:	//D-U		
				cmd = Menu::SetDATABFO(DataBfoValue::USB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::DATA_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 9://D-L

				cmd = Menu::SetDATABFO(DataBfoValue::LSB);
				m_radio->write(cmd.c_str(), cmd.length());
				cmd = OperatingMode::Set(ModeValue::DATA_BFOA);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 10:
				cmd = OperatingMode::Set(ModeValue::AM);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 11: //AM
				cmd = OperatingMode::Set(ModeValue::AM_N);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 12: //FM
				cmd = OperatingMode::Set(ModeValue::FM);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			case 13: // FM_N
				cmd = OperatingMode::Set(ModeValue::FM_N);
				m_radio->write(cmd.c_str(), cmd.length());
				break;
			}
			m_radio->flush();
			
		
		}
	}
}

void QtFT891::on_cbScopeSpanActivated(int val)
{
	using namespace Yaesu::Commands;
	auto cmd = FT891::Menu::SetSCPSpanFreq(static_cast<FT891::SCPSpanFreqValue>(val));
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
}

void QtFT891::on_cbcbSpectrumScopeStartCycleActivated(int val)
{
	using namespace Yaesu::Commands;
	auto cmd = FT891::Menu::SetSCPStartCycle(static_cast<FT891::SCPStartCycleValue>(val));
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
}

void QtFT891::on_ckClarEnabled_stateChanged(int val)
{
	bool state = false;
	if (val > 0)
	{
		state = true;
	}
	else
	{
		state = false;
	}
	ui.label_15->setEnabled(state);
	ui.cbClarSelect->setEnabled(state);
	ui.lblClarifierValue->setEnabled(state);
	ui.dial_Clarifier->setEnabled(state);
	ui.btnClearClarifier->setEnabled(state);

	auto cmd = Yaesu::Commands::FT891::Clarifier::Set(static_cast<Yaesu::Commands::FT891::ClarifierState>(state));
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_ckIFShift_stateChanged(int val)
{
	if (val > 0)
	{
		ui.hsIFShift->setEnabled(true);
	}
	else
	{
		ui.ckIFShift->setText("IFShift");
	}
	auto cmd = Yaesu::Commands::FT891::IF_SHIFT::Set(static_cast<Yaesu::Commands::FT891::IfShiftValue>(val > 0 ? val - 1 : val), ui.hsIFShift->value());
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_hsIFShift_valueChanged(int val)
{
	if (!(val % 20))
	{
		auto state = static_cast<Yaesu::Commands::FT891::IfShiftValue>((int)ui.ckIFShift->isChecked());
		ui.ckIFShift->setText(fmt::format("IFShift: {:d}", val).c_str());
		auto cmd = Yaesu::Commands::FT891::IF_SHIFT::Set(state, val);
		if (m_radio->isOpen())
		{
			m_radio->write(cmd.c_str(), cmd.length());
		}
	}
	else
	{
		auto remainder = std::abs(val % 20);
		val += val > 0 ? 20 - remainder : - (20 - remainder);
		ui.hsIFShift->setValue(val);
	}
	
}

void QtFT891::on_cbWidthActivated(int val)
{
	if (ui.cbWidth->hasFocus()) {
		
		Yaesu::Commands::FT891::WidthValue v;
		v.State = Yaesu::Commands::FT891::WidthState::ON;
		switch (ui.cbMode->currentIndex())
		{
		case 0:
		case 1:
		case 2:
			v.WidthCommand = (NarrowState == Yaesu::Commands::FT891::NarrowValue::ON ? 0 : 9) + val;
			break;
		default:
			v.WidthCommand = (NarrowState == Yaesu::Commands::FT891::NarrowValue::ON ? 0 : 10) + val;
			break;
		}
		
		std::string cmd = Yaesu::Commands::FT891::Width::Set(v);
		if (m_radio->isOpen())
		{
			m_radio->write(cmd.c_str(), cmd.length());
		}

		currentMode = ui.cbMode->currentIndex();
		currentBand = ui.cbBand->currentIndex();
		
		ui.cbWidth->clear();
		CalculateWidth(v);			
		
	
	}
}

void QtFT891::on_cbBandActivated(int val)
{
	currentBand = val;
	using namespace Yaesu::Commands;
	if (ui.cbBand->hasFocus()) {
		std::string cmd = Yaesu::Commands::FT891::BandSelect::Set(static_cast<Yaesu::Commands::FT891::Band>(val));
		if (m_radio->isOpen())
		{
				cbbandChanged = true;
				m_radio->write(cmd.c_str(), cmd.length());
				bandChanged = true;									
				this->currentBand = ui.cbBand->currentIndex();
				//UpdateFromBandModeRecord(this->currentBand, this->currentMode);
				
							
		}		
	}
}

void QtFT891::on_lvlAPF_valueChanged(int val)
{
	ui.lblApfLevelValue->setText(std::to_string(((val - 25) * 10)).c_str());
	Yaesu::Commands::FT891::ContourValue cv{};
	cv.Type = Yaesu::Commands::FT891::ContourType::APFFrequency;
	cv.Value.Freq = val;
	auto cmd = Yaesu::Commands::FT891::Contour::Set(cv);
	
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlProcLowWidth_valueChanged(int val)
{
	ui.lblProcLowWidth->setText(fmt::format("Width: {:d}", val).c_str());
	std::string cmd = Yaesu::Commands::FT891::Menu::SetPEQ1Bwth(val);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlProcMidWidth_valueChanged(int val)
{
	ui.lbllvlProcMidWidth->setText(fmt::format("Width: {:d}", val).c_str());
	std::string cmd = Yaesu::Commands::FT891::Menu::SetPEQ2Bwth(val);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlProcHighWidth_valueChanged(int val)
{
	ui.lbllvlMicLowWidth_6->setText(fmt::format("Width: {:d}", val).c_str());
	std::string cmd = Yaesu::Commands::FT891::Menu::SetPEQ3Bwth(val);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbTunerSelectActivated(int val)
{
	if (m_radio->isOpen())
	{
		std::string cmd = Yaesu::Commands::FT891::Menu::SetTunerSelect(static_cast<Yaesu::Commands::FT891::TunerSelectValue>(val));
	
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbNBWidthActivated(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetNbWidth(static_cast<Yaesu::Commands::FT891::NBWidthValue>(val));
	
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbNBRejectionActivated(int val)
{
	if (m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetNbRejection(static_cast<Yaesu::Commands::FT891::NBRejectionValue>(val));
		
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_dial_VFOA_valueChanged(int val)
{
	bool fast = ui.btnFST->palette().color(QPalette::Button) == QColor("green");
	int lower = 0;
	switch (ui.cbMode->currentIndex())
	{
	case 0:
	case 1:
	{
		switch (ui.cbSSBDialStep->currentIndex())
		{
		case 0:
			lower = 2;
			break;
		case 1:
			lower = 5;
			break;
		case 2:
			lower = 10;
			break;
		}
	}
	break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	{
		switch (ui.cbDialDialStep->currentIndex())
		{
		case 0:
			lower = 2;
			break;
		case 1:
			lower = 5;
			break;
		case 2:
			lower = 10;
			break;
		}
	}
	break;
	case 10:
	case 11:
	{
		switch (ui.cbAmDialStep->currentIndex())
		{
		case 0:
			lower = 10;
			break;
		case 1:
			lower = 100;
			break;
		}
	}
	break;
	case 12:
	case 13:
	{
		switch (ui.cbFmDialStep->currentIndex())
		{
		case 0:
			lower = 2;
			break;
		case 1:
			lower = 5;
			break;
		case 2:
			lower = 10;
			break;
		}
	}
	}

	int overall = (fast ? 100 : lower);
	

	if (dialA == 0)
	{
		dialA = val;
		if (fast) VFOAFreq -= VFOAFreq % overall;
		VFOAFreq += overall;
	}
	if (dialA < val) {
		VFOAFreq += overall;
		if (fast) VFOAFreq -= VFOAFreq % overall;
		dialA = val;
	}
	if (dialA > val)
	{
		VFOAFreq -= overall;
		if (fast) VFOAFreq -= VFOAFreq % overall;
		dialA = val;
	}

	if (m_radio->isOpen())
	{
		
			std::string cmd = Yaesu::Commands::FT891::VFO_A_FREQ::Set(VFOAFreq);

			m_radio->write(cmd.c_str(), cmd.length());
		
		
	}
}

void QtFT891::on_dial_VFOB_valueChanged(int val)
{
	bool fast = ui.btnFST->palette().color(QPalette::Button) == QColor("green");
	bool cw = ui.lblVFOBMode->text().contains("CW");
	int lower = (cw ? 5 : 10);
	int overall = (fast ? 100 : lower);
	if (dialB == 0)
	{
		dialB = val;
		VFOBFreq += overall;
	}
	if (dialB < val) {
		VFOBFreq += overall;
		dialB = val;
	}
	if (dialB > val)
	{
		VFOBFreq -= overall;
		dialB = val;
	}

	if (m_radio->isOpen())
	{
			std::string cmd = Yaesu::Commands::FT891::VFO_B_FREQ::Set(VFOBFreq);

			m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlMicLow_valueChanged(int val)
{

	
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ1Level(val);
	
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow->setText(std::to_string(val).c_str());
	}
}

void QtFT891::on_lvlMicMid_valueChanged(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ2Level(val);
		
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow_2->setText(std::to_string(val).c_str());
	}
}

void QtFT891::on_lvlMicHigh_valueChanged(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ3Level(val);
	
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow_3->setText(std::to_string(val).c_str());
	}
}

void QtFT891::on_lvlMicLowWidth_valueChanged(int val)
{
	ui.lbllvlMicLowWidth->setText(fmt::format("Width: {:d}", val).c_str());
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ1Bwth(val);
		
		m_radio->write(cmd.c_str(), cmd.length());
		
	}
}

void QtFT891::on_lvlMicMidWidth_valueChanged(int val)
{
	ui.lbllvlMicLowWidth_2->setText(fmt::format("Width: {:d}", val).c_str());
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ2Bwth(val);
		
		m_radio->write(cmd.c_str(), cmd.length());
		
	}
}

void QtFT891::on_lvlMicHighWidth_valueChanged(int val)
{
	ui.lbllvlMicLowWidth_3->setText(fmt::format("Width: {:d}", val).c_str());
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ3Bwth(val);
		m_radio->write(cmd.c_str(), cmd.length());
		
	}
}

void QtFT891::on_lvlProcLow_valueChanged(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ1Level(val);
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow_4->setText(std::to_string(val).c_str());

	}
}

void QtFT891::on_lvlProcMid_valueChanged(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ2Level(val);
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow_5->setText(std::to_string(val).c_str());
	}
}

void QtFT891::on_lvlProcHigh_valueChanged(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ3Level(val);
		m_radio->write(cmd.c_str(), cmd.length());
		ui.lbl0MicLow_6->setText(std::to_string(val).c_str());
	}
}

void QtFT891::on_hsNotchLevelValueChanged(int val)
{
	using namespace Yaesu::Commands::FT891;
	if (m_radio->isOpen())
	{
		ManualNotchValue lval;
		lval.Command = NotchCommandType::LEVEL;
		lval.Value.iValue = val;
		auto cmd = Yaesu::Commands::FT891::ManualNotch::Set(lval);
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbMeterTypeActivated(int val)
{
	if (m_radio->isOpen()) 
	{
		m_meterType = static_cast<Yaesu::Commands::FT891::MeterType>(val);
		if (m_transmitting) 
		{
			ui.lblS1->setVisible(false);
			ui.lblS3->setVisible(false);
			ui.lblS5->setVisible(false);
			ui.lblS7->setVisible(false);
			ui.lblS9->setVisible(false);
			ui.lblS20db->setVisible(false);
			ui.lblS40db->setVisible(false);
			ui.lblS60->setVisible(false);
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
				break;
			case Yaesu::Commands::FT891::MeterType::ALC:
				ui.lblS1->setVisible(false);
				ui.lblS3->setVisible(false);
				ui.lblS5->setVisible(false);
				ui.lblS7->setVisible(false);
				ui.lblS9->setVisible(false);
				ui.lblS20db->setVisible(false);
				ui.lblS40db->setVisible(false);
				ui.lblS60->setVisible(false);


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
				ui.lblComp_0->setVisible(false);
				ui.lblComp_5->setVisible(false);
				ui.lblComp_10->setVisible(false);
				ui.lblComp_15->setVisible(false);
				ui.lblComp_20->setVisible(false);
				ui.lblComp_25->setVisible(false);
				ui.lblComp_30->setVisible(false);
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
				break;
			case Yaesu::Commands::FT891::MeterType::PO:
				ui.lbl0watt->setVisible(true);
				ui.lbl10watt->setVisible(true);
				ui.lbl20watt->setVisible(true);
				ui.lbl50watt->setVisible(true);
				ui.lbl100watt->setVisible(true);
				ui.lbl150watt->setVisible(true);

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
				break;
			case Yaesu::Commands::FT891::MeterType::SWR:
				ui.lbl1swr->setVisible(true);
				ui.lbl2swr->setVisible(true);
				ui.lbl3swr->setVisible(true);
				ui.lblinfswr->setVisible(true);
				ui.lbl1_5swr->setVisible(true);

				ui.lbl0watt->setVisible(false);
				ui.lbl10watt->setVisible(false);
				ui.lbl20watt->setVisible(false);
				ui.lbl50watt->setVisible(false);
				ui.lbl100watt->setVisible(false);
				ui.lbl150watt->setVisible(false);

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
				break;
			case Yaesu::Commands::FT891::MeterType::ID:
				ui.lbl0A->setVisible(true);
				ui.lbl5A->setVisible(true);
				ui.lbl10A->setVisible(true);
				ui.lbl15A->setVisible(true);
				ui.lbl20A->setVisible(true);
				ui.lbl25A->setVisible(true);
				ui.lbl30A->setVisible(true);

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

				ui.gvALC->setVisible(false);

				ui.lblComp_0->setVisible(false);
				ui.lblComp_5->setVisible(false);
				ui.lblComp_10->setVisible(false);
				ui.lblComp_15->setVisible(false);
				ui.lblComp_20->setVisible(false);
				ui.lblComp_25->setVisible(false);
				ui.lblComp_30->setVisible(false);
				break;
			default:
				break;
			}
		}
		else
		{
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
		}
		auto cmd = Yaesu::Commands::FT891::MeterSW::Set(m_meterType);
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_dial_Clarifier_valueChanged(int val)
{
	if (QApplication::mouseButtons() != Qt::NoButton)
	{

		if (m_ClarifierOffset == 0 && val == 0)
		{
			auto cmd = Yaesu::Commands::FT891::Clarifier::Set(Yaesu::Commands::FT891::ClarifierState::OFF);
			if (m_radio->isOpen())
			{
				m_radio->write(cmd.c_str(), cmd.length());
			}
		}
		else if (m_ClarifierOffset < val)
		{
			auto cmd = Yaesu::Commands::FT891::ClarUp::Set(5);
			if (m_radio->isOpen())
			{
				m_radio->write(cmd.c_str(), cmd.length());
			}
		}
		else if (m_ClarifierOffset > val)
		{
			auto cmd = Yaesu::Commands::FT891::ClarDown::Set(5);
			if (m_radio->isOpen())
			{
				m_radio->write(cmd.c_str(), cmd.length());
			}
		}
	
	}
}

void QtFT891::on_btnClearClarifier_clicked()
{
	auto cmd = Yaesu::Commands::FT891::ClarClear::Set();
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbIFNotchActivated(int val)
{
	if (m_radio->isOpen())
	{
		auto notchtype = static_cast<Yaesu::Commands::FT891::IFNotchWidth>(val);
		auto cmd = Yaesu::Commands::FT891::Menu::SetIFNotchWidth(notchtype);
		m_radio->write(cmd.c_str(), cmd.length());
		if (mui)
		{
			mui->SetWidth(notchtype);
		}
	}
}

void QtFT891::on_cbMicLowActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ1Freq(static_cast<Yaesu::Commands::FT891::EQ1FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbMicMidActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ2Freq(static_cast<Yaesu::Commands::FT891::EQ2FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbMicHighActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEQ3Freq(static_cast<Yaesu::Commands::FT891::EQ3FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbProcLowActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ1Freq(static_cast<Yaesu::Commands::FT891::EQ1FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbProcMidActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ2Freq(static_cast<Yaesu::Commands::FT891::EQ2FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbProcHighActivated(int val)
{
	if (txeqtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPEQ3Freq(static_cast<Yaesu::Commands::FT891::EQ3FreqValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_uitabClicked(int val)
{
	if (ui.tabWidget->tabText(val) == "Output Power")
	{
		if (!powertabloaded)
		{
			LoadPowerTab();
			
		}
	} 
	else if (ui.tabWidget->tabText(val) == "Misc")
	{
		if (!misctabloaded)
		{
			LoadMiscTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "TX EQ")
	{
		if (!txeqtabloaded)
		{
			LoadTXEqTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "AM")
	{
		if (!amtabloaded)
		{
			LoadAMTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "CW")
	{
		if (ui.cbMode->currentIndex() >= 3 && ui.cbMode->currentIndex() <= 5)
		{
			ui.chkbxKeyerEnable->setEnabled(true);
			//ui.chkbxBreakIn->setEnabled(true);
		}
		else
		{
			ui.chkbxKeyerEnable->setEnabled(false);
			//ui.chkbxBreakIn->setEnabled(false);
		}
		if (!cwtabloaded)
		{
			LoadCWTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "Contesting")
	{
		if (!contestingtabloaded)
		{
			LoadContestingTab();
			
		}
		if (ui.cbMode->currentIndex() > 3 && ui.cbMode->currentIndex() <= 5)
		{
			ui.gpDVS->setEnabled(false);
			ui.gpmemkeyer->setEnabled(true);
		}
		else {

			ui.gpDVS->setEnabled(true);
			ui.gpmemkeyer->setEnabled(false);
		}
	}
	else if (ui.tabWidget->tabText(val) == "DATA")
	{
		if (!datatabloaded)
		{
			LoadDataTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "FM")
	{
			fmtabloaded = false;
			LoadFMTab();
		
	}
	else if (ui.tabWidget->tabText(val) == "RTTY")
	{
		if (!rttytabloaded)
		{
			LoadRTTYTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "SSB")
	{
		if (!ssbtabloaded)
		{
			LoadSSBTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "Vox")
	{
		if (!voxloaded)
		{
			LoadVoxTab();
		}
	}
	else if (ui.tabWidget->tabText(val) == "Firmware")
	{
		LoadFirmware();
	}
}

void QtFT891::on_btnTune_clicked()
{
	auto cmd = Yaesu::Commands::FT891::AntennaTunerControl::Set(Yaesu::Commands::FT891::TunerState::StartStop);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnAtoB_clicked()
{
	auto cmd = Yaesu::Commands::FT891::VFO_A_TO_VFO_B::Set();
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
	UpdateFromBandModeRecord(this->currentBand, this->currentMode);
}

void QtFT891::on_btnAtoM_clicked()
{
	auto cmd = Yaesu::Commands::FT891::VFO_A_To_Memory::Set();
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnTNR_clicked()
{
    QPalette pal = ui.btnTNR->palette();
    QColor bgcolor = pal.color(QPalette::Button);
    std::string cmd;
    if ( bgcolor != QColor("green")) {
       
        pal.setColor(QPalette::Button, QColor("green"));
        ui.btnTNR->setAutoFillBackground(true);
        ui.btnTNR->setPalette(pal);
        ui.btnTNR->repaint();
       
       cmd = Yaesu::Commands::FT891::AntennaTunerControl::Set(Yaesu::Commands::FT891::TunerState::ON);
    }
    else {
		pal.setColor(QPalette::Button,defaultbg);
		ui.btnTNR->setAutoFillBackground(true);
		ui.btnTNR->setPalette(pal);
		ui.btnTNR->repaint();
        cmd = Yaesu::Commands::FT891::AntennaTunerControl::Set(Yaesu::Commands::FT891::TunerState::OFF);
    }
    if (m_radio->isOpen())
    {
        m_radio->write(cmd.c_str(), cmd.length());
    }
}

void QtFT891::on_btnVox_clicked()
{
	QPalette pal = ui.btnVox->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnVox->setAutoFillBackground(true);
		ui.btnVox->setPalette(pal);
		ui.btnVox->repaint();

		cmd = Yaesu::Commands::FT891::VoxStatus::Set(Yaesu::Commands::FT891::VoxStatusValue::ON);
		
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnVox->setAutoFillBackground(true);
		ui.btnVox->setPalette(pal);
		ui.btnVox->repaint();
		cmd = Yaesu::Commands::FT891::VoxStatus::Set(Yaesu::Commands::FT891::VoxStatusValue::OFF);
		
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnScan_clicked()
{
	using namespace Yaesu::Commands;
	QPalette pal = ui.btnScan->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnScan->setAutoFillBackground(true);
		ui.btnScan->setPalette(pal);
		ui.btnScan->repaint();
		FT891::ScanState state = ui.rbScanUp->isChecked() ? FT891::ScanState::UP : FT891::ScanState::DOWN;
		cmd = Yaesu::Commands::FT891::Scan::Set(state);;
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnScan->setAutoFillBackground(true);
		ui.btnScan->setPalette(pal);
		ui.btnScan->repaint();
		FT891::ScanState state =  FT891::ScanState::OFF;
		cmd = Yaesu::Commands::FT891::Scan::Set(state);
		
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_ckTXWatch_stateChanged(int val)
{
	using namespace Yaesu::Commands;
	std::string cmd;
	if (val > 0)
	{
		cmd = FT891::TXW::Set(FT891::TXWValue::ON);
	}
	else
	{
		cmd = FT891::TXW::Set(FT891::TXWValue::OFF);
	}
	if (m_radio->isOpen())
	{
		
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnEQ_clicked()
{
	QPalette pal = ui.btnEQ->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnEQ->setAutoFillBackground(true);
		ui.btnEQ->setPalette(pal);
		ui.btnEQ->repaint();
		Yaesu::Commands::FT891::SpeechProcessorSetting setting;
		setting.state = Yaesu::Commands::FT891::SpeechProcessorState::ON;
		setting.type = Yaesu::Commands::FT891::SpeechProcessorType::ParametricEqualizer;
		cmd = Yaesu::Commands::FT891::SpeechProcessor::Set(setting);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnEQ->setAutoFillBackground(true);
		ui.btnEQ->setPalette(pal);
		ui.btnEQ->repaint();
		Yaesu::Commands::FT891::SpeechProcessorSetting setting;
		setting.state = Yaesu::Commands::FT891::SpeechProcessorState::OFF;
		setting.type = Yaesu::Commands::FT891::SpeechProcessorType::ParametricEqualizer;
		cmd = Yaesu::Commands::FT891::SpeechProcessor::Set(setting);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnPRC_clicked()
{

	QPalette pal = ui.btnPRC->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnPRC->setAutoFillBackground(true);
		ui.btnPRC->setPalette(pal);
		ui.btnPRC->repaint();
        Yaesu::Commands::FT891::SpeechProcessorSetting setting;
        setting.state = Yaesu::Commands::FT891::SpeechProcessorState::ON;
        setting.type = Yaesu::Commands::FT891::SpeechProcessorType::Processor;
		cmd = Yaesu::Commands::FT891::SpeechProcessor::Set(setting);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnPRC->setAutoFillBackground(true);
		ui.btnPRC->setPalette(pal);
		ui.btnPRC->repaint();
		Yaesu::Commands::FT891::SpeechProcessorSetting setting;
		setting.state = Yaesu::Commands::FT891::SpeechProcessorState::OFF;
		setting.type = Yaesu::Commands::FT891::SpeechProcessorType::Processor;
		cmd = Yaesu::Commands::FT891::SpeechProcessor::Set(setting);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnMON_clicked()
{
	QPalette pal = ui.btnMON->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnMON->setAutoFillBackground(true);
		ui.btnMON->setPalette(pal);
		ui.btnMON->repaint();
		Yaesu::Commands::FT891::MonitorLevelValue setting;
		setting.f = Yaesu::Commands::FT891::MonitorFunction::MontiorOnOff;
		setting.val.iVal = 1;
		cmd = Yaesu::Commands::FT891::MonitorLevel::Set(setting);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnMON->setAutoFillBackground(true);
		ui.btnMON->setPalette(pal);
		ui.btnMON->repaint();

		Yaesu::Commands::FT891::MonitorLevelValue setting;
        setting.f = Yaesu::Commands::FT891::MonitorFunction::MontiorOnOff;
        setting.val.iVal = 0;
		cmd = Yaesu::Commands::FT891::MonitorLevel::Set(setting);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnPWR_clicked()
{
	QPalette pal = ui.btnPWR->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("red")) {

        PowerOn();
     

       // Init();
	}
	else {
        PowerOff();
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnPWR->setAutoFillBackground(true);
		ui.btnPWR->setPalette(pal);
	
	}
	
}

void QtFT891::on_btnAB_clicked()
{
	receivedInformation = false;
    auto cmd = Yaesu::Commands::FT891::SwapVfo::Set();
    if (m_radio->isOpen())
    {
        m_radio->write(cmd.c_str(), cmd.length());
        m_radio->flush();
    }
	
	
}

void QtFT891::on_btnBtoA_clicked()
{
	auto cmd = Yaesu::Commands::FT891::VFO_B_TO_VFO_A::Set();
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
	UpdateFromBandModeRecord(this->currentBand, this->currentMode);
}

void QtFT891::on_btnIPO_clicked()
{
	QPalette pal = ui.btnIPO->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnIPO->setAutoFillBackground(true);
		ui.btnIPO->setPalette(pal);
		ui.btnIPO->repaint();
        cmd = Yaesu::Commands::FT891::PreAmp::Set(Yaesu::Commands::FT891::PreAmpValue::IPO);
		
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnIPO->setAutoFillBackground(true);
		ui.btnIPO->setPalette(pal);
		ui.btnIPO->repaint();
        cmd = Yaesu::Commands::FT891::PreAmp::Set(Yaesu::Commands::FT891::PreAmpValue::AMP);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
   
}

void QtFT891::on_btnATT_clicked()
{
	QPalette pal = ui.btnATT->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnATT->setAutoFillBackground(true);
		ui.btnATT->setPalette(pal);
		ui.btnATT->repaint();
		cmd = Yaesu::Commands::FT891::RFAttenuator::Set(Yaesu::Commands::FT891::RfAttenuatorState::ON);

	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnATT->setAutoFillBackground(true);
		ui.btnATT->setPalette(pal);
		ui.btnATT->repaint();
        cmd = Yaesu::Commands::FT891::RFAttenuator::Set(Yaesu::Commands::FT891::RfAttenuatorState::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}

}

void QtFT891::on_btnNAR_clicked()
{
	QPalette pal = ui.btnNAR->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnNAR->setAutoFillBackground(true);
		ui.btnNAR->setPalette(pal);
		ui.btnNAR->repaint();
        
		cmd = Yaesu::Commands::FT891::Narrow::Set(Yaesu::Commands::FT891::NarrowValue::ON);

	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnNAR->setAutoFillBackground(true);
		ui.btnNAR->setPalette(pal);
		ui.btnNAR->repaint();
        cmd = Yaesu::Commands::FT891::Narrow::Set(Yaesu::Commands::FT891::NarrowValue::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		/*cmd = Yaesu::Commands::FT891::Width::Read();
		m_radio->write(cmd.c_str(), cmd.length());*/
	}

}

void QtFT891::on_btnNB_clicked()
{
	QPalette pal = ui.btnNB->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnNB->setAutoFillBackground(true);
		ui.btnNB->setPalette(pal);
		ui.btnNB->repaint();
        
		cmd = Yaesu::Commands::FT891::NoiseBlankerStatus::Set(Yaesu::Commands::FT891::NoiseBlankerStatusValue::ON);

	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnNB->setAutoFillBackground(true);
		ui.btnNB->setPalette(pal);
		ui.btnNB->repaint();
		cmd = Yaesu::Commands::FT891::NoiseBlankerStatus::Set(Yaesu::Commands::FT891::NoiseBlankerStatusValue::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnLOCK_clicked()
{
	QPalette pal = ui.btnLOCK->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {
		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnLOCK->setAutoFillBackground(true);
		ui.btnLOCK->setPalette(pal);
		ui.btnLOCK->repaint();
		cmd = Yaesu::Commands::FT891::VFODialLock::Set(Yaesu::Commands::FT891::DialLockValue::ON);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnLOCK->setAutoFillBackground(true);
		ui.btnLOCK->setPalette(pal);
		ui.btnLOCK->repaint();
		cmd = Yaesu::Commands::FT891::VFODialLock::Set(Yaesu::Commands::FT891::DialLockValue::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnFST_clicked()
{
	QPalette pal = ui.btnFST->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {

		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnFST->setAutoFillBackground(true);
		ui.btnFST->setPalette(pal);
		ui.btnFST->repaint();
		cmd = Yaesu::Commands::FT891::FAST_STEP::Set(Yaesu::Commands::FT891::VFOFastStepValue::ON);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnFST->setAutoFillBackground(true);
		ui.btnFST->setPalette(pal);
		ui.btnFST->repaint();
		cmd = Yaesu::Commands::FT891::FAST_STEP::Set(Yaesu::Commands::FT891::VFOFastStepValue::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnDNR_clicked()
{
	QPalette pal = ui.btnDNR->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {
		dnr_enabled = 1;
		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnDNR->setAutoFillBackground(true);
		ui.btnDNR->setPalette(pal);
		ui.btnDNR->repaint();
		cmd = Yaesu::Commands::FT891::NoiseReduction::Set(Yaesu::Commands::FT891::NoiseReductionValue::ON);
	}
	else {
		dnr_enabled = 0;
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnDNR->setAutoFillBackground(true);
		ui.btnDNR->setPalette(pal);
		ui.btnDNR->repaint();
		cmd = Yaesu::Commands::FT891::NoiseReduction::Set(Yaesu::Commands::FT891::NoiseReductionValue::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
	UpdateBandModeRecord();
}

void QtFT891::on_btnDNF_clicked()
{
	QPalette pal = ui.btnDNF->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {
		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnDNF->setAutoFillBackground(true);
		ui.btnDNF->setPalette(pal);
		ui.btnDNF->repaint();
		cmd = Yaesu::Commands::FT891::AutoNotch::Set(Yaesu::Commands::FT891::NotchState::ON);
	}
	else {
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnDNF->setAutoFillBackground(true);
		ui.btnDNF->setPalette(pal);
		ui.btnDNF->repaint();
		cmd = Yaesu::Commands::FT891::AutoNotch::Set(Yaesu::Commands::FT891::NotchState::OFF);
	}
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
	UpdateBandModeRecord();
}

void QtFT891::on_btnContour_clicked()
{
	QPalette pal = ui.btnContour->palette();
	QColor bgcolor = pal.color(QPalette::Button);
	std::string cmd;
	if (bgcolor != QColor("green")) {
		pal.setColor(QPalette::Button, QColor("green"));
		ui.btnContour->setAutoFillBackground(true);
		ui.btnContour->setPalette(pal);
		ui.btnContour->repaint();
		Yaesu::Commands::FT891::ContourValue type;
		type.Type = Yaesu::Commands::FT891::ContourType::ContourOnOff;
		type.Value.state = Yaesu::Commands::FT891::ContourState::ON;
	    cmd = Yaesu::Commands::FT891::Contour::Set(type);
		std::vector<std::string> cmds;
		cmds.emplace_back(cmd);
		
		if(!UpdateFromContourRecord())
		{
			cmds.emplace_back(Yaesu::Commands::FT891::Contour::Read(type));
			Yaesu::Commands::FT891::ContourValue cval;
			cval.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;
			cmds.emplace_back(Yaesu::Commands::FT891::Contour::Read(cval));
			cmds.emplace_back(Yaesu::Commands::FT891::Menu::ReadCountourLevel());
			cmds.emplace_back(Yaesu::Commands::FT891::Menu::ReadCountourWidth());
		}
		if (m_radio->isOpen())
		{
			for (auto cmd : cmds) 
			{
				m_radio->write(cmd.c_str(), cmd.length());
				m_radio->flush();
				std::this_thread::sleep_for(std::chrono::microseconds(20));
			}
		}
	}
	else
	{
		pal.setColor(QPalette::Button, defaultbg);
		ui.btnContour->setAutoFillBackground(true);
		ui.btnContour->setPalette(pal);
		ui.btnContour->repaint();
		Yaesu::Commands::FT891::ContourValue type;
		type.Type = Yaesu::Commands::FT891::ContourType::ContourOnOff;
		type.Value.state = Yaesu::Commands::FT891::ContourState::OFF;
		cmd = Yaesu::Commands::FT891::Contour::Set(type);
		if (m_radio->isOpen())
		{
			m_radio->write(cmd.c_str(), cmd.length());
		}
	}
}

void QtFT891::OnPortClosing()
{
	this->close();
}

void QtFT891::on_VFO_returnPressed()
{
	int vfoval = ui.VFO->text().remove('.').toInt();
	std::string cmd = Yaesu::Commands::FT891::VFO_A_FREQ::Set(vfoval);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
		cmd = Yaesu::Commands::FT891::INFORMATION::Read();
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_VFOB_returnPressed()
{
	unsigned int vfoval = ui.VFOB->text().remove('.').toUInt();
	auto cmd = Yaesu::Commands::FT891::VFO_B_FREQ::Set(vfoval);
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
		cmd = Yaesu::Commands::FT891::OppositeBandInformation::Read();
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnZeroIn_clicked()
{
	using namespace Yaesu::Commands;
	auto cmd = FT891::ZeroIn::Set();
	if (m_radio->isOpen())
	{
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_pbPortSettings_clicked()
{
	PortSettings* settings = new PortSettings(this);
	settings->setModal(true);
	settings->setCATPort(m_radio->portName());
	settings->setCatRate(QString::number(m_radio->baudRate()));
	
	if (settings->exec() == QDialog::DialogCode::Accepted)
	{
		qint32 rate = settings->GetCatRate();
		QString port = QString(settings->getCATPort().constData());
		UpdatePortSettings(port, rate);
		auto e = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::OFF);
		m_radio->write(e.c_str(), e.length());
		m_radio->flush();
		m_radio->waitForReadyRead();
		Init();
	}
	else {
		
	}

}

void QtFT891::on_btnUp_clicked()
{
	std::string cmd = Yaesu::Commands::FT891::Channel_Up_Down::Set(Yaesu::Commands::FT891::UpDownState::UP);
	m_radio->write(cmd.c_str(), cmd.length());
	m_radio->flush();
}

void QtFT891::on_btnDn_clicked()
{
	std::string cmd = Yaesu::Commands::FT891::Channel_Up_Down::Set(Yaesu::Commands::FT891::UpDownState::DOWN);
	m_radio->write(cmd.c_str(), cmd.length());
	m_radio->flush();
}

void QtFT891::ReadPowerSwitch()
{
	readingPower = true;
	std::string buff;
	//write dummy data to the rig to put it in the error state
	buff = "aslkdfk;";
	m_radio->write(buff.c_str(), buff.length());
	m_radio->flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(1400));
	//request the power switch state
	auto pstate = Yaesu::Commands::FT891::PowerSwitch::Read();
	m_radio->write(pstate.c_str(), pstate.length());
	m_radio->flush();

}

void QtFT891::PowerOn()
{
	if (m_radio->isOpen())
	{
		std::string buff;
		//write dummy data to the rig to put it in the error state
		buff = "aslkdfk;";
		auto ret = m_radio->write(buff.c_str(), buff.length());
		m_radio->waitForBytesWritten(500);
		std::this_thread::sleep_for(std::chrono::milliseconds(1100)); //wait at least one second but not more than two. 
		//tell it to turn on. 
		buff = Yaesu::Commands::FT891::PowerSwitch::Set(Yaesu::Commands::FT891::PowerSwitchValue::ON);

		m_radio->write(buff.c_str(), buff.length());
		m_radio->flush();
		m_radio->waitForReadyRead(1400);
		ReadPowerSwitch();
	}
	else
	{
		OutputDebugStringW(L"Failed to open port!");
	}
}

void QtFT891::PowerOff()
{
	std::string buff;
	//write dummy data to the rig to put it in the error state

	//tell it to turn on. 
	buff = Yaesu::Commands::FT891::PowerSwitch::Set(Yaesu::Commands::FT891::PowerSwitchValue::OFF);
	m_radio->write(buff.c_str(), buff.length());
	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); //wait at least one second but not more than two. 
   
	buff = "aslkdfk;";
	m_radio->write(buff.c_str(), buff.length());
	ui.VFO->clear();
	ui.VFOB->clear();
	ui.cbWidth->clear();
	ui.Volume->setValue(ui.Volume->minimum());
	ui.Squelch->setValue(ui.Squelch->minimum());
	ui.RFGain->setValue(ui.RFGain->minimum());
	ui.NBLvl->setValue(ui.NBLvl->minimum());
	ui.MON->setValue(ui.MON->minimum());
	ui.DNR->setValue(ui.DNR->minimum());
	ui.Comp->setValue(ui.Comp->minimum());
	ui.MicGain->setValue(ui.MicGain->minimum());
	
	m_radio->clear(QSerialPort::Direction::Input);

	ProcessCommmand("RM0000");
}

void QtFT891::Init()
{
	using namespace Yaesu::Commands;
    if (m_radio->isOpen())
    {
	
		ui.statusBar->showMessage("Reading the radio's current state", 5000);
       		
		loadingInit = true;
		this->setEnabled(false);
		
		auto e = Yaesu::Commands::FT891::INFORMATION::Read();
		m_radio->write(e.c_str(), e.length());
		m_radio->flush();
	
    }
}

void QtFT891::SetBand()
{
	int tmp = ui.cbBand->currentIndex();
	if ((VFOAFreq >= 1800000) && (VFOAFreq <= 2000000))
	{
		ui.cbBand->setCurrentIndex(0);
	}
	else if ((VFOAFreq >= 3500000) && (VFOAFreq <= 4000000))
	{
		ui.cbBand->setCurrentIndex(1);
	}
	else if ((VFOAFreq >= 5300000) && (VFOAFreq <= 5405000))
	{
		ui.cbBand->setCurrentIndex(2);
	}
	else if ((VFOAFreq >= 7000000) && (VFOAFreq <= 7300000))
	{
		ui.cbBand->setCurrentIndex(3);
	}
	else if ((VFOAFreq >= 10100000) && (VFOAFreq <= 10150000))
	{
		ui.cbBand->setCurrentIndex(4);
	}
	else if ((VFOAFreq >= 14000000) && (VFOAFreq <= 14350000))
	{
		ui.cbBand->setCurrentIndex(5);
	}
	else if ((VFOAFreq >= 18068000) && (VFOAFreq <= 18168000))
	{
		ui.cbBand->setCurrentIndex(6);
	}
	else if ((VFOAFreq >= 21000000) && (VFOAFreq <= 21450000))
	{
		ui.cbBand->setCurrentIndex(7);
	}
	else if ((VFOAFreq >= 24890000) && (VFOAFreq <= 24990000))
	{
		ui.cbBand->setCurrentIndex(8);
	}
	else if ((VFOAFreq >= 28000000) && (VFOAFreq <= 29700000))
	{
		ui.cbBand->setCurrentIndex(9);
	}
	else if ((VFOAFreq >= 50000000) && (VFOAFreq <= 54000000))
	{
		ui.cbBand->setCurrentIndex(10);
	}
	else
	{
		ui.cbBand->setCurrentIndex(11);
	}
	currentBand = ui.cbBand->currentIndex();
	bandChanged = tmp != currentBand;
}

void QtFT891::CalculateMode(Yaesu::Commands::FT891::ModeValue v)
{
	using namespace Yaesu::Commands::FT891;
	switch (v)
	{
	case ModeValue::SSB_BFOA: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		ui.btnVox->setVisible(true);
		switch (m_ssbbfo)
		{
		case BfoValue::USB: {
			currentMode = 1;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::USB;

		}
						  break;
		case BfoValue::LSB: {
			currentMode = 0;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::LSB;
		}
						  break;
		case BfoValue::AUTO:
			if (VFOAFreq >= 10000000)
			{
				currentMode = 2;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::USB;
			}
			else
			{
				currentMode = 2;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::LSB;
			}
			break;
		}
		ui.bnZeroIn->setVisible(false);
	}
		break;
	case ModeValue::SSB_BFOB: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		ui.btnVox->setVisible(true);
		switch (m_ssbbfo)
		{
		case BfoValue::USB: {
			currentMode = 1;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::USB;
		}
						  break;
		case BfoValue::LSB: {
			currentMode = 0;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::LSB;
		}
						  break;
		case BfoValue::AUTO:
		{

			if (VFOAFreq >= 10000000)
			{
				currentMode = 2;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::USB;
			}
			else
			{
				currentMode = 2;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::LSB;
			}
		}
		break;
		}
		ui.bnZeroIn->setVisible(false);
	}
		break;
	case ModeValue::CW:
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		switch (m_cwbfo)
		{
		case BfoValue::USB: {
			currentMode = 4;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW;
		}
			break;
		case BfoValue::LSB: {
			currentMode = 3;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW_R;
		}
			break;
		case BfoValue::AUTO:			
			if (VFOAFreq >= 10000000)
			{
				currentMode = 5;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW;
			}
			else
			{
				currentMode = 5;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW_R;
			}
			break;
		}
		ui.bnZeroIn->setVisible(true);
		ui.btnVox->setVisible(false);
		break;
	case ModeValue::CW_BFOA:
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		switch (m_cwbfo)
		{
		case BfoValue::USB:
			currentMode = 4;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW;
			break;
		case BfoValue::LSB:
			currentMode = 3;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW_R;
			break;
		case BfoValue::AUTO:						
			if (VFOAFreq >= 10000000)
			{

				currentMode = 5;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW;
			}
			else
			{
				currentMode = 5;
			
				currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::CW_R;
			}
			break;
		}
		ui.bnZeroIn->setVisible(true);
		ui.btnVox->setVisible(false);
		break;
	case ModeValue::FM: {
		currentMode = 12;
	
		currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::FM;
		ui.cbWidth->setEnabled(false);
		ui.lbcbWidth->setEnabled(false);
		ui.btnVox->setVisible(true);
	}
		break;
	case ModeValue::FM_N: {
		ui.cbWidth->setEnabled(false);
		ui.lbcbWidth->setEnabled(false);
		currentMode = 13;
	
		ui.btnVox->setVisible(true);
		currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::FM_N;
	}
		break;
	case ModeValue::AM: {
		ui.cbWidth->setEnabled(false);
		ui.lbcbWidth->setEnabled(false);
		currentMode = 10;
	
		ui.btnVox->setVisible(true);
		currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::AM;
	}
		break;
	case ModeValue::AM_N: {
		ui.cbWidth->setEnabled(false);
		ui.lbcbWidth->setEnabled(false);
		ui.btnVox->setVisible(true);
		currentMode = 11;
	
		currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::AM_N;
	}
		break;
	case ModeValue::DATA_BFOB: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(false);
		ui.btnVox->setVisible(true);
		switch (m_databfo)
		{
		case DataBfoValue::USB: {
			currentMode = 8;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::DATA_USB;
		}
			break;
		case DataBfoValue::LSB: {
			currentMode = 9;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::DATA_LSB;
		}
			break;
		}
		ui.bnZeroIn->setVisible(false);
	}
		break;
	case ModeValue::DATA_BFOA: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		switch (m_databfo)
		{
		case DataBfoValue::USB: {
			currentMode = 8;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::DATA_USB;
		}
			break;
		case DataBfoValue::LSB: {
			currentMode = 9;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::DATA_LSB;
		}
			break;
		}
		ui.bnZeroIn->setVisible(false);
		ui.btnVox->setVisible(true);
	}
		break;
	case ModeValue::RTTY_BFOB: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		ui.btnVox->setVisible(true);
		switch (m_rttybfo)
		{
		case DataBfoValue::LSB: {
			currentMode = 6;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::RTTY_LSB;
		}
			break;
		case DataBfoValue::USB: {
			currentMode = 7;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::RTTY_USB;
		}
			break;
		}
		ui.bnZeroIn->setVisible(false);
	}
		break;
	case ModeValue::RTTY_BFOA: {
		ui.cbWidth->setEnabled(true);
		ui.lbcbWidth->setEnabled(true);
		ui.btnVox->setVisible(true);
		switch (m_rttybfo)
		{
		case DataBfoValue::USB: {
			currentMode = 7;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::RTTY_USB;
		}
							  break;
		case DataBfoValue::LSB: {
			currentMode = 6;
		
			currentMemoryMode = Yaesu::Commands::FT891::MemoryChannelModeValue::RTTY_LSB;
		}
							  break;
		}
		ui.bnZeroIn->setVisible(false);
	}
		break;

	}
	ui.cbMode->setCurrentIndex(currentMode);
}

void QtFT891::CalculateWidth(Yaesu::Commands::FT891::WidthValue wv)
{
	int currentMode = ui.cbMode->currentIndex();
	int currentBand = ui.cbBand->currentIndex();
	bool narrow = NarrowState == Yaesu::Commands::FT891::NarrowValue::ON;
	
		ui.cbWidth->clear();

		ui.cbWidth->setEnabled(true);
		switch (currentMode)
		{
		case 0:
		case 1:
		case 2:
			if (wv.WidthCommand <= 9 && narrow) {
				widthValues = {
					"200 Hz", //0
					"400 Hz", //1
					"600 Hz", //2 
					"850 Hz", //3
					"1100 Hz",//4
					"1350 Hz",//5
					"1500 Hz",//6
					"1650 Hz",//7
					"1800 Hz" //8
				};
				wdefault = 6;
				WidthOffset = 1;
			}
			else if (wv.WidthCommand >= 9 && !narrow) {
				widthValues = {
				"1800 Hz",
				"1950 Hz",
				"2100 Hz",
				"2200 Hz",
				"2300 Hz",
				"2400 Hz",
				"2500 Hz",
				"2600 Hz",
				"2700 Hz",
				"2800 Hz",
				"2900 Hz",
				"3000 Hz",
				"3200 Hz"
				};
				wdefault = 5;
				WidthOffset = 9;
			}
			break;
		case 3:
		case 4:
		case 5:
			if (narrow)
			{
				widthValues = {
					"50 Hz",
					"100 Hz",
					"150 Hz",
					"200 Hz",
					"250 Hz",
					"300 Hz",
					"350 Hz",
					"400 Hz",
					"450 Hz",
					"500 Hz"
				};
				wdefault = 9;
				WidthOffset = 1;
			}
			else
			{
				widthValues = {
					"500 Hz",
					"800 Hz",
					"1200 Hz",
					"1400 Hz",
					"1700 Hz",
					"2000 Hz",
					"2400 Hz",
					"3000 Hz"
				};
				wdefault = 6;
				WidthOffset = 10;
			}
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			if (narrow)
			{
				widthValues = {
					"50 Hz",
					"100 Hz",
					"150 Hz",
					"200 Hz",
					"250 Hz",
					"300 Hz",
					"350 Hz",
					"400 Hz",
					"450 Hz",
					"500 Hz"
				};
				wdefault = 5;
				WidthOffset = 1;
			}
			else
			{
				widthValues = {
					"500 Hz",
					"800 Hz",
					"1200 Hz",
					"1400 Hz",
					"1700 Hz",
					"2000 Hz",
					"2400 Hz",
					"3000 Hz"
				};
				wdefault = 0;
				WidthOffset = 10;
			}
			break;
		}

		ui.cbWidth->addItems(widthValues);
		auto cal = wv.WidthCommand - WidthOffset;
		currentWidth = cal;
		
		ui.cbWidth->setFocus();
		ui.cbWidth->setCurrentIndex(currentWidth);
		ui.cbWidth->repaint();
		UpdateBandModeRecord(currentBand, currentMode);
			
		
		
}

void QtFT891::LoadPowerTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{

		std::vector<std::string> cmds;
		
	
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}


void QtFT891::LoadMiscTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		this->loadingMisc = true;
		
		
		
	}
}

void QtFT891::LoadTXEqTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		loadingEQ = true;

		std::vector<std::string> cmds;
		
		//m_radio->write(e.c_str(), e.length());
		//m_radio->flush();
		
	}
}

void QtFT891::LoadAMTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadAMLowCutFreq());
		cmds.emplace_back(FT891::Menu::ReadAMLowCutSlope());
		cmds.emplace_back(FT891::Menu::ReadAMHighCutFreq());
		cmds.emplace_back(FT891::Menu::ReadAMHighCutSlope());
		cmds.emplace_back(FT891::Menu::ReadAMMicSelect());
		cmds.emplace_back(FT891::Menu::ReadAMPTTSelect());
		cmds.emplace_back(FT891::Menu::ReadAMMicGain());
		cmds.emplace_back(FT891::Menu::ReadAMDataGain());
		cmds.emplace_back(FT891::Menu::ReadAMOutLevel());
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadContestingTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::KeyerMemory::Read(1));
		cmds.emplace_back(FT891::KeyerMemory::Read(2));
		cmds.emplace_back(FT891::KeyerMemory::Read(3));
		cmds.emplace_back(FT891::KeyerMemory::Read(4));
		cmds.emplace_back(FT891::KeyerMemory::Read(5));
		cmds.emplace_back(FT891::Menu::ReadDvsTxOutLevel());
		cmds.emplace_back(FT891::Menu::ReadDvsRxOutLevel());
		
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadCWTab()
{
	using namespace Yaesu::Commands;
	
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		if (ui.cbMode->currentIndex() >= 3 && ui.cbMode->currentIndex() <= 5)
		{
			
			cmds.emplace_back(FT891::BreakIn::Read());
			cmds.emplace_back(FT891::Keyer::Read());
			cmds.emplace_back(FT891::KeyPitch::Read());
		}
		cmds.emplace_back(FT891::Menu::ReadCWHighCutFreq());
		cmds.emplace_back(FT891::Menu::ReadCWLowCutFreq());
		cmds.emplace_back(FT891::Menu::ReadCWHighCutSlope());
		cmds.emplace_back(FT891::Menu::ReadCWLowCutSlope());
		cmds.emplace_back(FT891::Menu::ReadCWAutoMode());
		cmds.emplace_back(FT891::Menu::ReadCWBFO());
		cmds.emplace_back(FT891::Menu::ReadCWWaveShape());
		cmds.emplace_back(FT891::Menu::ReadCWFreqDisplay());
		cmds.emplace_back(FT891::Menu::ReadPCKeying());
		cmds.emplace_back(FT891::Menu::ReadQSKDelayTime());
		cmds.emplace_back(FT891::Menu::ReadCWBreakInDelay());
		cmds.emplace_back(FT891::Menu::ReadKeyerType());
		cmds.emplace_back(FT891::Menu::ReadCWOutLevel());
		cmds.emplace_back(FT891::CWSpot::Read());
	
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
		
	}
}

void QtFT891::LoadDataTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadDATALowCutFreq());
		cmds.emplace_back(FT891::Menu::ReadDATAHighCutFreq());
		cmds.emplace_back(FT891::Menu::ReadDATALowCutSlope());
		cmds.emplace_back(FT891::Menu::ReadDATAHighCutSlope());
		cmds.emplace_back(FT891::Menu::ReadOtherDisp());
		cmds.emplace_back(FT891::Menu::ReadDataAntiVoxGain());
		cmds.emplace_back(FT891::Menu::ReadDATAMicGain());

		cmds.emplace_back(FT891::Menu::ReadOtherShift());
		cmds.emplace_back(FT891::Menu::ReadDataMode());
		cmds.emplace_back(FT891::Menu::ReadPSKTone());
		cmds.emplace_back(FT891::Menu::ReadDATAInSelect());
		cmds.emplace_back(FT891::Menu::ReadDATAPTTSelect());
		cmds.emplace_back(FT891::Menu::ReadDATABFO());
		cmds.emplace_back(FT891::Menu::ReadDATAOutLevel());
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			m_radio->flush();
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadVoxTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
	
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadFMTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadFMMicSelect());
		cmds.emplace_back(FT891::Menu::ReadPktPTTSelect());
		cmds.emplace_back(FT891::Menu::ReadRptShift28MHZ());
		cmds.emplace_back(FT891::Menu::ReadRptShift50MHZ());
		cmds.emplace_back(FT891::Menu::ReadFMOutLevel());
		cmds.emplace_back(FT891::Menu::ReadFMMicGain());
		cmds.emplace_back(FT891::Menu::ReadDCSPolarity());
		cmds.emplace_back(FT891::OffSet::Read());
		cmds.emplace_back(FT891::CTCSSToneFrequency::Read(FT891::CTCSSModeType::CTCSS));
		cmds.emplace_back(FT891::CTCSSToneFrequency::Read(FT891::CTCSSModeType::DCS));
		cmds.emplace_back(FT891::CTCSS::Read());
		cmds.emplace_back(FT891::Menu::ReadFMDataGain());
		cmds.emplace_back(FT891::OffSet::Read());
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadRTTYTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadRTTYHighCutFreq());
		cmds.emplace_back(FT891::Menu::ReadRTTYLowCutFreq());
		cmds.emplace_back(FT891::Menu::ReadRTTYHighCutSlope());
		cmds.emplace_back(FT891::Menu::ReadRTTYLowCutSlope());
		cmds.emplace_back(FT891::Menu::ReadRTTYShiftFreq());
		cmds.emplace_back(FT891::Menu::ReadRTTYPolarityR());
		cmds.emplace_back(FT891::Menu::ReadRTTYPolarityT());
		cmds.emplace_back(FT891::Menu::ReadRTTYShiftPort());
		cmds.emplace_back(FT891::Menu::ReadRTTYOutLevel());
		cmds.emplace_back(FT891::Menu::ReadRTTYBFO());
		cmds.emplace_back(FT891::Menu::ReadRTTYMarkFreq());
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::LoadSSBTab()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadSSBLowCutFreq());
		cmds.emplace_back(FT891::Menu::ReadSSBLowCutSlope());
		cmds.emplace_back(FT891::Menu::ReadSSBHighCutFreq());
		cmds.emplace_back(FT891::Menu::ReadSSBHighCutSlope());
		cmds.emplace_back(FT891::Menu::ReadSSBMicSelect());
		cmds.emplace_back(FT891::Menu::ReadSSBPTTSelect());
		cmds.emplace_back(FT891::Menu::ReadSSBTxBPF());
		cmds.emplace_back(FT891::Menu::ReadSSBMicGain());
		cmds.emplace_back(FT891::Menu::ReadSSBDataGain());
		cmds.emplace_back(FT891::Menu::ReadSSBBFO());
		cmds.emplace_back(FT891::Menu::ReadSSBOutLevel());
		
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
			
		}
	}
}

void QtFT891::LoadFirmware()
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		std::vector<std::string> cmds;
		cmds.emplace_back(FT891::Menu::ReadMainVersion());
		cmds.emplace_back(FT891::Menu::ReadDSPVersion());
		cmds.emplace_back(FT891::Menu::ReadLCDVersion());
		
		for (auto e : cmds)
		{
			m_radio->write(e.c_str(), e.length());
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	}
}

void QtFT891::on_timerTimeout()
{
	ui.btnCh1Load->setEnabled(true);
	ui.btnCh2Load->setEnabled(true);
	ui.btnCh3Load->setEnabled(true);
	ui.btnCh4Load->setEnabled(true);
	ui.btnCh5Load->setEnabled(true);
	ui.btnCh1Play->setEnabled(true);
	ui.btnCh2Play->setEnabled(true);
	ui.btnCh3Play->setEnabled(true);
	ui.btnCh4Play->setEnabled(true);
	ui.btnCh5Play->setEnabled(true);
	ui.btnCh1Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
	ui.btnCh2Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
	ui.btnCh3Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
	ui.btnCh4Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
	ui.btnCh5Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
	ui.btnCh1Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
	ui.btnCh2Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
	ui.btnCh3Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
	ui.btnCh4Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
	ui.btnCh5Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
	auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
	m_radio->write(cmd.c_str(), cmd.length());
	cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
	m_radio->write(cmd.c_str(), cmd.length());
	m_timer.stop();
}

QtFT891::QtFT891(QWidget* parent)
	: QMainWindow(parent),
	db(nullptr),
	dnr_enabled(0),
	bandChanged(false),
	receivedInformation(false),
	wdefault(0),
	currentMode(0),
	VFOAFreq(0),
	WidthOffset(0),
	currentMemoryMode(Yaesu::Commands::FT891::MemoryChannelModeValue::LSB),
	powertabloaded(false),
	currentWidth(0),
	currentBand(0),
	widthClicked(false),
	misctabloaded(false),
	m_timer(this),
	prevcmd("")
{
	ui.setupUi(this);
	ui.lbl0A->setGeometry(ui.gv_meter->x(), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 16, 16);
	ui.lbl5A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 1) - (ui.lbl0A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 16, 16);
	ui.lbl10A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 2) - (ui.lbl5A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl15A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 3) - (ui.lbl10A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl20A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 4) - (ui.lbl15A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl25A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 5) - (ui.lbl20A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl30A->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width() / 6) * 6) - (ui.lbl25A->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 35, 16);


	ui.lbl0watt->setGeometry(ui.gv_meter->x(), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 16, 16);
	ui.lbl10watt->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.235294119) - (ui.lbl10watt->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl20watt->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.349019617) - (ui.lbl20watt->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl50watt->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.596078455) - (ui.lbl50watt->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lbl100watt->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.819607854) - (ui.lbl100watt->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 31, 16);
	ui.lbl150watt->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) - (ui.lbl100watt->width() / 2)), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 50, 16);

	ui.lblComp_0->setGeometry(ui.gv_meter->x(), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 16, 16);
	ui.lblComp_5->setGeometry(ui.gv_meter->x() + (ui.gv_meter->width() * 0.15) - (ui.lblComp_5->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lblComp_10->setGeometry(ui.gv_meter->x() + (ui.gv_meter->width() * 0.30) - (ui.lblComp_10->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lblComp_15->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.45) - (ui.lblComp_15->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lblComp_20->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.60) - (ui.lblComp_20->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lblComp_25->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width()) * 0.75) - (ui.lblComp_25->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), 21, 16);
	ui.lblComp_30->setGeometry(ui.gv_meter->x() + ((ui.gv_meter->width())) - (ui.lblComp_30->width() / 2), ui.gv_meter->y() - (ui.gv_meter->height() + 2), ui.lblComp_30->width(), 16);

	ui.gvALC->setGeometry(ui.gv_meter->x(), ui.gv_meter->y() - (ui.gv_meter->height() + 2), (ui.gv_meter->width() * 145.0f / 255.0f) , ui.gvALC->height());



	ui.lblComp_0->setVisible(false);
	ui.lblComp_5->setVisible(false);
	ui.lblComp_10->setVisible(false);
	ui.lblComp_15->setVisible(false);
	ui.lblComp_20->setVisible(false);
	ui.lblComp_25->setVisible(false);
	ui.lblComp_30->setVisible(false);
	ui.lbl1swr->setVisible(false);
	ui.lbl2swr->setVisible(false);
	ui.lbl3swr->setVisible(false);
	ui.lblinfswr->setVisible(false);
	ui.lbl1_5swr->setVisible(false);
	ui.lbl0watt->setVisible(false);
	ui.lbl10watt->setVisible(false);
	ui.lbl20watt->setVisible(false);
	ui.lbl50watt->setVisible(false);
	ui.lbl100watt->setVisible(false);
	ui.lbl150watt->setVisible(false);
	ui.gvALC->setVisible(false);
	ui.lbl0A->setVisible(false);
	ui.lbl5A->setVisible(false);
	ui.lbl10A->setVisible(false);
	ui.lbl15A->setVisible(false);
	ui.lbl20A->setVisible(false);
	ui.lbl25A->setVisible(false);
	ui.lbl30A->setVisible(false);

	ui.hsIFShift->setEnabled(false);

	ui.label_15->setEnabled(false);
	ui.cbClarSelect->setEnabled(false);
	ui.dial_Clarifier->setEnabled(false);
	ui.lblClarifierValue->setEnabled(false);
	ui.btnClearClarifier->setEnabled(false);

	StartDatabase();
    this->smeter_pen = new QPen(QColor("black"));
	this->white_pen = new QPen(QColor("white"));
    this->smeter_brush = new QBrush(QColor("black"));
    this->white = new QBrush(QColor("white"));
    auto geo = ui.gv_meter->geometry();
    
    auto scene = new QGraphicsScene(ui.gv_meter->contentsRect());
    scene->setBackgroundBrush(*white);
    ui.gv_meter->setScene(scene);
	ui.gv_meter->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.gv_meter->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	auto alcscene = new QGraphicsScene(ui.gvALC->contentsRect());
	QBrush background{ this->palette().color(QPalette::Window) };
	alcscene->setBackgroundBrush(background);
	ui.gvALC->setScene(alcscene);
	ui.gvALC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.gvALC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	auto increment = geo.width()  / 7;
	auto divisor = 2;
	ui.lblS1->setGeometry(geo.left() + (geo.width() * 0.0470588244) - (ui.lblS1->width() / divisor), 145, ui.lblS1->width(), ui.lblS1->height());
	ui.lblS3->setGeometry(geo.left() + (geo.width() * 0.160784319) - (ui.lblS3->width() / divisor), 145, ui.lblS3->width(), ui.lblS3->height());
	ui.lblS5->setGeometry(geo.left() + (geo.width() * 0.254901975) - (ui.lblS5->width() / divisor), 145, ui.lblS5->width(), ui.lblS5->height());
	ui.lblS7->setGeometry(geo.left() + (geo.width() * 0.372549019) - (ui.lblS7->width() / divisor), 145, ui.lblS7->width(), ui.lblS7->height());
	ui.lblS9->setGeometry(geo.left() + (geo.width() * 0.509803921) - (ui.lblS9->width() / divisor), 145, ui.lblS9->width(), ui.lblS9->height());
	ui.lblS20db->setGeometry(geo.left() + (geo.width() * 0.666666667) - (ui.lblS20db->width() / divisor), 145, ui.lblS20db->width(), ui.lblS20db->height());
	ui.lblS40db->setGeometry(geo.left() + (geo.width() * 0.80392156862) - (ui.lblS40db->width() / divisor), 145, ui.lblS40db->width(), ui.lblS40db->height());
	ui.lblS60->setGeometry(geo.left() + geo.width() - (ui.lblS60->width() / divisor), 145, ui.lblS60->width(), ui.lblS60->height());

	CreateConnections();
	ui.cbBand->ensurePolished();
	ui.cbMode->ensurePolished();
	ui.cbWidth->ensurePolished();
	ui.cbTunerSelect->ensurePolished();

	ui.cbTunerSelect->addItem("OFF", { (uint)Yaesu::Commands::FT891::TunerSelectValue::OFF });
	ui.cbTunerSelect->addItem("EXTERNAL", { (uint)Yaesu::Commands::FT891::TunerSelectValue::EXTERNAL });
	ui.cbTunerSelect->addItem("ATAS", { (uint)Yaesu::Commands::FT891::TunerSelectValue::ATAS });
	ui.cbTunerSelect->addItem("LAMP", { (uint)Yaesu::Commands::FT891::TunerSelectValue::LAMP });

	defaultbg = this->palette().color(QPalette::Button); 
	buttonStyle = ui.btnPWR->styleSheet();
	ui.statusBar->clearMessage();
	if (m_radio) {
		if (m_radio->isOpen()) {
			auto cmd = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::OFF);
			m_radio->write(cmd.c_str(), cmd.length());
			ui.statusBar->showMessage("Reading Radio Power Status..", 1000);
			bandChanged = false;
			ReadPowerSwitch();
			
			//Init();

		}
		else {
			ui.statusBar->showMessage("Failed to initialize the com port!");
		}
	}
}

QtFT891::~QtFT891()
{
	if (m_radio->isOpen()) {
		auto cmd = Yaesu::Commands::FT891::AutoInformation::Set(Yaesu::Commands::FT891::InformationState::OFF);
		m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	}
}


PortSettings::PortSettings(QtFT891* parent /*= nullptr*/)
{

    ui.setupUi(this);
	QSerialPortInfo info{};

	ports = info.availablePorts();
	for (auto& e : ports)
	{
		ui.comboBox->addItem(e.portName());
	}

	auto rates = info.standardBaudRates();
	for (auto& p : rates)
	{
		if (p <= 38400 && p >= 4800 && p != 14400) {
			ui.comboBox_2->addItem(fmt::format("{:d}", p).c_str());
		}
	}
	
}

PortSettings::~PortSettings()
{

}

void PortSettings::setCATPort(const QString& port)
{
	ui.comboBox->setCurrentText(port);
}

void PortSettings::setCatRate(const QString& rate)
{
	ui.comboBox_2->setCurrentText(rate);
}

QString PortSettings::getCATPort()
{
	int itemindex = ui.comboBox->currentIndex();
	auto port = ui.comboBox->itemText(itemindex);
	return port;
}

int PortSettings::GetCatRate()
{
	int itemindex = ui.comboBox_2->currentIndex();
	auto rate = ui.comboBox_2->itemText(itemindex);
	return rate.toInt();
}

