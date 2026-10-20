#include "QtFT891.h"
#include <fmt/core.h>

void QtFT891::on_cbRTTYLCutSlopeActivated(int val)
{
	
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
	
		auto cmd = FT891::Menu::SetRTTYLowCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRTTYHCutSlopeActivated(int val)
{

	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		
		auto cmd = FT891::Menu::SetRTTYHighCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlRTTYLCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (100 + (val * 50))) : "OFF/100Hz";
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		ui.lblLcutStart_DATA_2->setText(freq.c_str());
		auto cmd = FT891::Menu::SetRTTYLowCutFreq(static_cast<FT891::FreqLowCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlRTTYHCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (700 + (val * 50))) : "OFF/700Hz";
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		ui.lblHcutStart_DATA_2->setText(freq.c_str());
		auto cmd = FT891::Menu::SetRTTYHighCutFreq(static_cast<FT891::FreqHighCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlRTTYOut_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYOutLevel(val);
		ui.lblRTTYOut->setText(fmt::format("Out Level: {:d}", val).c_str());
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_cbRTTYShiftPortActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYShiftPort(static_cast<FT891::RTTYShiftPortValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPolarityRActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYPolarityR(static_cast<FT891::RTTYPolarityValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPolarityTActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYPolarityT(static_cast<FT891::RTTYPolarityValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRTTYShiftFreqActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYShiftFreq(static_cast<FT891::RTTYShiftFreqValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRTTYMarkFreqActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYMarkFreq(static_cast<FT891::RTTYMarkFreq>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRTTYBfoActivated(int val)
{
	using namespace Yaesu::Commands;
	if (rttytabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetRTTYBFO(static_cast<FT891::DataBfoValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
