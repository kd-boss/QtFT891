#include "QtFT891.h"
#include <fmt/core.h>

void QtFT891::on_lvlHFSSBPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblHFSSB->setText(fmt::format("SSB: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetHfSsbPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlHFAMPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblHFAM->setText(fmt::format("AM: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetHfAmPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlHFPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblHFPOWER->setText(fmt::format("CW/Data: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::SetHfPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlVHFSSBPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblVHFSSB->setText(fmt::format("SSB: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::Set50mSsbPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlVHFAMPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblVHFAM->setText(fmt::format("AM: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::Set50mAmPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlVHFPower_valueChanged(int val)
{
	if (m_radio->isOpen() && powertabloaded)
	{
		ui.lblVHFPWR->setText(fmt::format("CW/DATA: {:d} ", val).c_str());
		auto cmd = Yaesu::Commands::FT891::Menu::Set50mPwr(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}