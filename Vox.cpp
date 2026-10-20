#include "QtFT891.h"
#include <fmt/core.h>


void QtFT891::on_cbVoxSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		auto cmd = FT891::Menu::SetVoxSelect(static_cast<FT891::VoxSelectValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlDataVoxGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if ( m_radio->isOpen())
	{
		ui.lblDataVoxGain->setText(fmt::format("Vox Gain: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetDataVoxGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlDataAntiVoxGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		ui.lblDataAntiVoxGain->setText(fmt::format("Anti Vox Gain: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetDataAntiVoxGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_spDataVoxDelayValueChanged(int val)
{
	using namespace Yaesu::Commands;
	if (m_radio->isOpen())
	{
		//ui.lblDataVoxDelay ->setText(fmt::format("Vox Delay: {:d}", val).c_str());
		auto cmd = FT891::Menu::SetDataVoxDelay(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_VoxLevel_valueChanged(int val)
{

	if (m_radio->isOpen())
	{
		ui.lblVoxLevel->setText(fmt::format("Vox Gain: {:d}", val).c_str());
		auto cat = Yaesu::Commands::FT891::VoxGain::Set(val);
		m_radio->write(cat.c_str(), cat.length());
	}
}

void QtFT891::on_sbVoxDelay_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		auto cat = Yaesu::Commands::FT891::VoxDelayTime::Set(val);
		m_radio->write(cat.c_str(), cat.length());
	}
}


void QtFT891::on_AntiVox_valueChanged(int val)
{
	if (m_radio->isOpen())
	{
		ui.lblAntiVox->setText(fmt::format("Anti Vox Gain: {:d}", val).c_str());
		auto cat = Yaesu::Commands::FT891::Menu::SetAntiVoxGain(val);
		m_radio->write(cat.c_str(), cat.length());
	}
}