#include "QtFT891.h"



void QtFT891::on_lvldvsRx_valueChanged(int val)
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetDvsRxOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lvldvsTx_valueChanged(int val)
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetDvsTxOutLevel(val);
		 m_radio->write(cmd.c_str(), cmd.length());

	}
}

void QtFT891::on_cbNumberFormatActivated(int val)
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetNumberStyle(static_cast<Yaesu::Commands::FT891::NumberStyleValue>(val));
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_sbContestNumber_valueChanged(int val)
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto cmd = Yaesu::Commands::FT891::Menu::SetContestNumber(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_btnCh1Load_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh1Load->icon().pixmap(ui.btnCh1Load->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Record)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);

			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);

			ui.btnCh1Load->setIcon(QIcon(R"~(:\QtFT891\StopRecording)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH1);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
		

		}
		else {
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
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh2Load_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh2Load->icon().pixmap(ui.btnCh2Load->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Record)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);

			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh2Load->setIcon(QIcon(R"~(:\QtFT891\StopRecording)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH2);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
	

		}
		else {
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh2Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh3Load_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh3Load->icon().pixmap(ui.btnCh3Load->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Record)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh3Load->setIcon(QIcon(R"~(:\QtFT891\StopRecording)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH3);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
	

		}
		else {
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh3Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh4Load_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh4Load->icon().pixmap(ui.btnCh4Load->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Record)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh4Load->setIcon(QIcon(R"~(:\QtFT891\StopRecording)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH4);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
		

		}
		else {
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh4Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh5Load_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh5Load->icon().pixmap(ui.btnCh5Load->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Record)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh5Load->setIcon(QIcon(R"~(:\QtFT891\StopRecording)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH5);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_radio->flush();
			m_timer.start(std::chrono::milliseconds(20000));

		}
		else {
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh5Load->setIcon(QIcon(R"~(:\QtFT891\Record)~"));
			auto cmd = Yaesu::Commands::FT891::LoadMessage::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh1Play_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh1Play->icon().pixmap(ui.btnCh1Play->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Play)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh1Play->setIcon(QIcon(R"~(:\QtFT891\Stop)~"));
		
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH1);
			 m_radio->write(cmd.c_str(), cmd.length());
			
		}
		else
		{
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh1Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
		
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh2Play_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh2Play->icon().pixmap(ui.btnCh2Play->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Play)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh2Play->setIcon(QIcon(R"~(:\QtFT891\Stop)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH2);
			 m_radio->write(cmd.c_str(), cmd.length());
		
		}
		else
		{
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh2Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh3Play_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh3Play->icon().pixmap(ui.btnCh3Play->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Play)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh3Play->setIcon(QIcon(R"~(:\QtFT891\Stop)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH3);
			 m_radio->write(cmd.c_str(), cmd.length());
	
		}
		else
		{
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh3Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh4Play_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh4Play->icon().pixmap(ui.btnCh4Play->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Play)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh5Play->setEnabled(false);
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh4Play->setIcon(QIcon(R"~(:\QtFT891\Stop)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH4);
			 m_radio->write(cmd.c_str(), cmd.length());
		
		}
		else
		{
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh5Play->setEnabled(true);
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh4Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
		
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}

void QtFT891::on_btnCh5Play_clicked()
{
	if (contestingtabloaded && m_radio->isOpen())
	{
		auto current = ui.btnCh5Play->icon().pixmap(ui.btnCh5Play->icon().actualSize(QSize(48, 48)));
		auto test = QPixmap(R"~(:\QtFT891\Play)~");
		if (current.toImage() == test.toImage())
		{
			ui.btnCh1Play->setEnabled(false);
			ui.btnCh2Play->setEnabled(false);
			ui.btnCh4Play->setEnabled(false);
			ui.btnCh3Play->setEnabled(false);
			ui.btnCh1Load->setEnabled(false);
			ui.btnCh2Load->setEnabled(false);
			ui.btnCh3Load->setEnabled(false);
			ui.btnCh4Load->setEnabled(false);
			ui.btnCh5Load->setEnabled(false);
			ui.btnCh5Play->setIcon(QIcon(R"~(:\QtFT891\Stop)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::CH5);
			 m_radio->write(cmd.c_str(), cmd.length());
		
		}
		else
		{
			ui.btnCh1Play->setEnabled(true);
			ui.btnCh2Play->setEnabled(true);
			ui.btnCh4Play->setEnabled(true);
			ui.btnCh3Play->setEnabled(true);
			ui.btnCh1Load->setEnabled(true);
			ui.btnCh2Load->setEnabled(true);
			ui.btnCh3Load->setEnabled(true);
			ui.btnCh4Load->setEnabled(true);
			ui.btnCh5Load->setEnabled(true);
			ui.btnCh5Play->setIcon(QIcon(R"~(:\QtFT891\Play)~"));
			
			auto cmd = Yaesu::Commands::FT891::PlayBack::Set(Yaesu::Commands::FT891::DVSRecordingValue::STOP);
			 m_radio->write(cmd.c_str(), cmd.length());
			m_timer.stop();
		}
	}
}


void QtFT891::on_lnMemKey_1_returnPressed()
{
	using namespace Yaesu::Commands;
	FT891::KeyerMemoryValue val;
	val.ChannelNumber = 1;
	val.Message = ui.lnMemKey_1->text().remove("\r\n").toStdString().substr(0, 50);
	val.Message.push_back('}');
	if (m_radio->isOpen())
	{
		auto cmd = FT891::KeyerMemory::Set(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}

}

void QtFT891::on_lnMemKey_2_returnPressed()
{
	using namespace Yaesu::Commands;
	FT891::KeyerMemoryValue val;
	val.ChannelNumber = 2;
	val.Message = ui.lnMemKey_2->text().remove("\r\n").toStdString().substr(0, 50);
	val.Message.push_back('}');
	if (m_radio->isOpen())
	{
		auto cmd = FT891::KeyerMemory::Set(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lnMemKey_3_returnPressed()
{
	using namespace Yaesu::Commands;
	FT891::KeyerMemoryValue val;
	val.ChannelNumber = 3;
	val.Message = ui.lnMemKey_3->text().remove("\r\n").toStdString().substr(0, 50);
	val.Message.push_back('}');
	if (m_radio->isOpen())
	{
		auto cmd = FT891::KeyerMemory::Set(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lnMemKey_4_returnPressed()
{
	using namespace Yaesu::Commands;
	FT891::KeyerMemoryValue val;
	val.ChannelNumber = 4;
	val.Message = ui.lnMemKey_4->text().remove("\r\n").toStdString().substr(0, 50);
	val.Message.push_back('}');
	if (m_radio->isOpen())
	{
		auto cmd = FT891::KeyerMemory::Set(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_lnMemKey_5_returnPressed()
{
	using namespace Yaesu::Commands;
	FT891::KeyerMemoryValue val;
	val.ChannelNumber = 5;
	val.Message = ui.lnMemKey_5->text().remove("\r\n").toStdString().substr(0, 50);
	val.Message.push_back('}');
	if (m_radio->isOpen())
	{
		auto cmd = FT891::KeyerMemory::Set(val);
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnMkPlay_clicked()
{
	using namespace Yaesu::Commands;
	if (contestingtabloaded && m_radio->isOpen())
	{
		std::string cmd;
		if (ui.cbMK->currentIndex() == 0) {
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Memory1);
		}
		else
		{
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Message1);
		}
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnMkPlay_2_clicked()
{
	using namespace Yaesu::Commands;
	if (contestingtabloaded && m_radio->isOpen())
	{
		std::string cmd;
		if (ui.cbMK_2->currentIndex() == 0) {
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Memory2);
		}
		else
		{
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Message2);
		}
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnMkPlay_3_clicked()
{
	using namespace Yaesu::Commands;
	if (contestingtabloaded && m_radio->isOpen())
	{
		std::string cmd;
		if (ui.cbMK_3->currentIndex() == 0) {
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Memory3);
		}
		else
		{
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Message3);
		}
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnMkPlay_4_clicked()
{
	using namespace Yaesu::Commands;
	if (contestingtabloaded && m_radio->isOpen())
	{
		std::string cmd;
		if (ui.cbMK_4->currentIndex() == 0) {
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Memory4);
		}
		else
		{
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Message4);
		}
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}

void QtFT891::on_bnMkPlay_5_clicked()
{
	using namespace Yaesu::Commands;
	if (contestingtabloaded && m_radio->isOpen())
	{
		std::string cmd;
		if (ui.cbMK_5->currentIndex() == 0) {
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Memory5);
		}
		else
		{
			cmd = FT891::CWKeyingPlayback::Set(FT891::KeyerMemoryChannel::Message5);
		}
		 m_radio->write(cmd.c_str(), cmd.length());
	}
}
