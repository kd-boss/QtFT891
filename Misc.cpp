#include "QtFT891.h"


void QtFT891::on_cbAGCFuncActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::AGC_FUNCTION::Set(static_cast<Yaesu::Commands::FT891::AGCSetValue>(val));
		m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPeakHoldActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPeakHold(static_cast<Yaesu::Commands::FT891::PeakHoldType>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAPOActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetApo(static_cast<Yaesu::Commands::FT891::APOValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxATAS_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetATASSetting(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxFMSetting_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetFMSetting(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxMemGroup_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetMemGroup(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}

void QtFT891::on_chkbxRECSettings_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetRecSetting(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxZinLed_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetZinLed(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxEmergencyFreq_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetEmergencyFreq(static_cast<Yaesu::Commands::FT891::EnableDisableValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxFan_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetFanControl(static_cast<Yaesu::Commands::FT891::FanControlValue>(val > 0 ? 1 : 0));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxMicScan_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetMicScan(static_cast<Yaesu::Commands::FT891::EnableDisableValue>(val > 0 ? 1 : 0));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlBacklight_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetBackliteDimmer(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlContrast_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetLcdContrast(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlLCD_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetLcdDimmer(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAGCFast_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAgcFastDelay(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAGCMid_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAgcMidDelay(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAGCSlow_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAgcSlowDelay(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlTxBusy_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetTxBusyDimmer(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlBeep_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetBeepLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlTxTOT_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetTxTOT(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMDailStepActivated(int val)
{
	using namespace Yaesu::Commands;
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMDialStep(static_cast<FT891::AMDialStep>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMChStepActivated(int val)
{
	using namespace Yaesu::Commands;
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAmChStep(static_cast<FT891::AMChannelStepValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCATTOTActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetCatTOT(static_cast<Yaesu::Commands::FT891::CatTOTValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxCatRTS_stateChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetCatRTS(static_cast<Yaesu::Commands::FT891::EnableDisableValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRFSQLvActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetRfSqlVr(static_cast<Yaesu::Commands::FT891::RfSqlVrValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPoupMenuActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetPopupMenuStyle(static_cast<Yaesu::Commands::FT891::PopUpMenuStyle>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_sbBeconInterval_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetBeaconInterval(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbMicScanResumeActivated(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetMicScanResume(static_cast<Yaesu::Commands::FT891::MicScanResumeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_sbRefReqAdj_valueChanged(int val)
{
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetRefFreqAdjust(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_sbQuickSplit_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (misctabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetQuickSplitFreq(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
