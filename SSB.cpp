#include "QtFT891.h"
#include <fmt/core.h>

void QtFT891::on_lvlSSBLCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz",(100 + (val * 50))) : "OFF/100Hz";
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		ui.lblLcutStart_SSB->setText(freq.c_str());
		auto cmd = FT891::Menu::SetSSBLowCutFreq(static_cast<FT891::FreqLowCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlSSBHCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (700 + (val * 50))) : "OFF/700Hz";
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		ui.lblHcutStart_SSB->setText(freq.c_str());
		auto cmd = FT891::Menu::SetSSBHighCutFreq(static_cast<FT891::FreqHighCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBHCutSlopeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBHighCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBLCutSlopeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBLowCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}

void QtFT891::on_lvlSSBOut_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		ui.lblSSBOut->setText(fmt::format("Out Level: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetSSBOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBMicSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBMicSelect(static_cast<FT891::AudioInputValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBBfoActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBBFO(static_cast<FT891::BfoValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBPTTSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBPTTSelect(static_cast<FT891::PTTSelectValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbSSBTxBPFActivated(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetSSBTxBPF(static_cast<FT891::SSBTXBandPassValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlSSBMicGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		ui.lblSSBMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetSSBMicGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlSSBDataGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (ssbtabloaded && m_radio->isOpen())
	{
		ui.lblSSBDataGain->setText(fmt::format("Data Gain: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetSSBDataGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}