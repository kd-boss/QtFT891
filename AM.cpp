#include "QtFT891.h"
#include <fmt/core.h>



void QtFT891::on_lvlAMLCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (100 + (val * 50))) : "OFF/100Hz";
	if (amtabloaded && m_radio->isOpen())
	{
		ui.lblLcutStart->setText(freq.c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMLowCutFreq(static_cast<Yaesu::Commands::FT891::FreqLowCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAMHCutFreq_valueChanged(int val)
{
	std::string freq = val > 0 ? fmt::format("{:d}Hz", (700 + (val * 50))) : "OFF/700Hz";
	if (amtabloaded && m_radio->isOpen())
	{
		ui.lblHcutStart->setText(freq.c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMHighCutFreq(static_cast<Yaesu::Commands::FT891::FreqHighCutValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAMMicGain_valueChanged(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		ui.lblAmMicGain->setText(fmt::format("Mic Gain: {:d}", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMMicGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAMDataGain_valueChanged(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		ui.lblAmDataGain->setText(fmt::format("Data Gain: {:d}", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMDataGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlAMOutLevel_valueChanged(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		ui.lblAmOutLevel->setText(fmt::format("Out Level: {:d}", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMMicSelectActivated(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMMicSelect(static_cast<Yaesu::Commands::FT891::AudioInputValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMPTTActivated(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMPTTSelect(static_cast<Yaesu::Commands::FT891::PTTSelectValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMLCutSlopeActivated(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMLowCutSlope(static_cast<Yaesu::Commands::FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbAMHCutSlopeActivated(int val)
{
	if (amtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetAMHighCutSlope(static_cast<Yaesu::Commands::FT891::FreqSlopeValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


