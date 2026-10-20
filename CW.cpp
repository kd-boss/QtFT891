#include "QtFT891.h"
#include <fmt/core.h>


void QtFT891::on_spbxKeySpeed_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::KeyerSpeed::Set(static_cast<FT891::KeyerSpeedVal>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkCWSpot_stateChanged(int val)
{
	using namespace Yaesu::Commands;
	auto cmd = FT891::CWSpot::Set(static_cast<Yaesu::Commands::FT891::CWSpotState>(val > 0 ? 1 : 0));
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_chkbxKeyerEnable_stateChanged(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{

		auto cmd = FT891::Keyer::Set(static_cast<FT891::KeyerValue>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_chkbxBreakIn_stateChanged(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		
		auto cmd = FT891::BreakIn::Set(static_cast<FT891::BreakInState>((val > 0 ? 1 : 0)));
		 m_radio->write(cmd.c_str(), cmd.length());
		 m_radio->flush();
	}
	
}

void QtFT891::on_cbCWLCutSlopeActivated(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}", (100 + (val * 50))) : "Off";
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblLcutStart_CW->setText(freq.c_str());
		auto cmd = FT891::Menu::SetCWLowCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWHCutSlopeActivated(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}", (700 + (val * 50))) : "Off";
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblHcutStart_CW->setText(freq.c_str());
		auto cmd = FT891::Menu::SetCWHighCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWAutoModeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWAutoMode(static_cast<FT891::CwAutoModeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWBFOActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWBFO(static_cast<FT891::BfoValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWBkInTypeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWBreakkInType(static_cast<FT891::CwBreakInType>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbWaveShapeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWWaveShape(static_cast<FT891::CwWaveShapeValue>(val + 1));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWFreqDisplayActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWFreqDisplay(static_cast<FT891::CwFreqDisplayValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWPCKeyingActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetPCKeying(static_cast<FT891::PCKeyingValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCWQSKDelayTimeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetQSKDelayTime(static_cast<FT891::QskDelayTimeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlCWLCutFreq_valueChanged(int val)
{
	ui.lblLcutStart_CW->setText(val == 0 ? "OFF/100Hz" : fmt::format("{:d}Hz", (100 + (val * 50))).c_str());
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWLowCutFreq(static_cast<FT891::FreqLowCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlCWHCutFreq_valueChanged(int val)
{
	ui.lblHcutStart_CW->setText((val == 0 ? "OFF/700hz" : fmt::format("{:d}Hz", (700 + (val * 50))).c_str()));
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetCWHighCutFreq(static_cast<FT891::FreqHighCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlCWOutLevel_valueChanged(int val)
{

	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblCWOutLevel->setText(fmt::format("Out Level: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetCWOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlCWBKINDelay_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblCWBkInDelay->setText(fmt::format("BK-IN Delay: {:d}ms", val).c_str());
		auto cmd = FT891::Menu::SetCWBreakkInDelay(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlCWWeight_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (cwtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblCWWeight->setText(fmt::format("CW Weight: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetCwWeight(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}