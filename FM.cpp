#include "QtFT891.h"
#include <fmt/core.h>


void QtFT891::on_rbDCSON_toggled()
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::CTCSS::Set(FT891::CTCSSState::CTCSS_DCS_ON);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_rbCTCSSENCON_toggled()
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::CTCSS::Set(FT891::CTCSSState::CTCSS_ENC_ON);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_rbCTCSSENCDECON_toggled()
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::CTCSS::Set(FT891::CTCSSState::CTCSS_ENC_DEC_ON);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_rbCTCSSOFF_toggled()
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::CTCSS::Set(FT891::CTCSSState::CTCSS_OFF);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbFMMicSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetFMMicSelect(static_cast<FT891::AudioInputValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbPktPttSelectActivated(int val)
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetPktPTTSelect(static_cast<FT891::PTTSelectValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbCTCSSToneActivated(int val )
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		FT891::CTCSSToneFreqencyValue lval;
		lval.Mode = FT891::CTCSSModeType::CTCSS;
		lval.Value = val;
		auto cmd = FT891::CTCSSToneFrequency::Set(lval);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDCSCodeActivated(int val)
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		FT891::CTCSSToneFreqencyValue lval;
		lval.Mode = FT891::CTCSSModeType::DCS;
		lval.Value = val;
		auto cmd = FT891::CTCSSToneFrequency::Set(lval);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbRepeaterOffsetActivated(int val)
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::OffSet::Set(static_cast<FT891::OperationType>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvlFMOut_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	ui.lblFMOut->setText(fmt::format("FM OUT : {:d}", val).c_str());
	if (fmtabloaded && m_radio->isOpen())
	{
	
		auto cmd = FT891::Menu::SetFMOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}


void QtFT891::on_lvlFMMicGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	ui.lblFMMicGain->setText(fmt::format("Mic Gain : {:d}", val).c_str());
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetFMMicGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_cbDCSPolarityActivated(int val)
{
	using namespace Yaesu::Commands;
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetDCSPolarity(static_cast<FT891::DCSPolarityValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}



void QtFT891::on_lvlFMDataGain_valueChanged(int val)
{
	using namespace Yaesu::Commands;
	ui.lblFMDataGain->setText(fmt::format("Data Gain : {:d}", val).c_str());
	if (fmtabloaded && m_radio->isOpen() && sender() != nullptr)
	{
		auto cmd = FT891::Menu::SetFMDataGain(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
