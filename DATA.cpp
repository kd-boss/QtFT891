#include "QtFT891.h"
#include <fmt/core.h>


void QtFT891::on_lvlDataMicGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblDataMicGain->setText(fmt::format("Mic GAIN: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetDATAMicGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}


void QtFT891::on_lvlDataGain_valueChanged(int val)
{
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblDataGain->setText(fmt::format("DATA GAIN: {:d}", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetDataDataGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlDATALCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (100 + (val * 50))) : "OFF/100Hz";
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblLcutStart_DATA->setText(freq.c_str());
		auto cmd = FT891::Menu::SetDATALowCutFreq(static_cast<FT891::FreqLowCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlDATAHCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (700 + (val * 50))) : "OFF/700Hz";
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblHcutStart_DATA->setText(freq.c_str());
		auto cmd = FT891::Menu::SetDATAHighCutFreq(static_cast<FT891::FreqHighCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_sbOtherDISP_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetOtherDisp(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}

void QtFT891::on_sbOtherSHIFTValueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		
		auto cmd = FT891::Menu::SetOtherShift(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
	
}

void QtFT891::on_lvlDATAOut_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		ui.lblDataOutValue->setText(std::to_string(val).c_str());
		auto cmd = FT891::Menu::SetDATAOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
	else
	{
		ui.lvlDATAOut->setValue(0);
	}
}

void QtFT891::on_cbDATAModeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDataMode(static_cast<FT891::DataModeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPSKToneActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetPSKTone(static_cast<FT891::PSKToneValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDATAInSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDATAInSelect(static_cast<FT891::AudioInputValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDATAPTTSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDATAPTTSelect(static_cast<FT891::PTTSelectValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDATABFOActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDATABFO(static_cast<FT891::DataBfoValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
void QtFT891::on_cbDATALCutSlopeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDATALowCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDATAHCutSlopeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (datatabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDATAHighCutSlope(static_cast<FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
