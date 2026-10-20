#include "QtFT891.h"
#include <fmt/core.h>
#include <QStandardPaths>
#include <QDir>
#include <windows.h>
#include <string>


void QtFT891::StartDatabase()
{

		std::string spath;
		spath = QStandardPaths::locate(QStandardPaths::GenericConfigLocation, "", QStandardPaths::LocateOption::LocateDirectory).toUtf8().operator const char *();
		
		QString appdataFinal = spath.c_str();
	
		QDir path;
		path.setPath(appdataFinal);
		if (!path.exists("QtFT891"))
		{
			if (path.mkdir("QtFT891"))
			{
				spath += "QtFT891/state.db";
			}
		}
		else {
			spath += "QtFT891/state.db";
		}
		
	auto res = sqlite3_open(spath.c_str(), &db);
		if (res != SQLITE_OK)
		{
			OutputDebugStringA("failed to open database");
		}
		sqlite3_exec(db, R"~(
CREATE TABLE IF NOT EXISTS port_settings (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
	port_name varchar(20),
	baud_rate int
);
)~",
nullptr,
nullptr,
nullptr);

		sqlite3_exec(db, R"~(
CREATE TABLE IF NOT EXISTS band_mode_settings(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	band int default 0,
	mode int default 0,
	dnr_enabled int default 0,
	dnr_value int default 0,
	width_value int default 0
	
);
)~",
nullptr,
nullptr,
nullptr);
		sqlite3_exec(db, R"~(
CREATE TABLE IF NOT EXISTS contour_settings(
id INTEGER PRIMARY KEY AUTOINCREMENT,
	contour_enabled int default 0,
	contour_level int default 0,
	contour_freq int default 0,
	contour_width int default 0
);
)~",
nullptr,
nullptr,
nullptr);

		std::string sql = "select * from port_settings where id = 1;";
		sqlite3_stmt* stmt;
		sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
		bool done = false;
		QString port;
		int baudrate = 0;
		while (!done)
		{
			switch (sqlite3_step(stmt))
			{
			case SQLITE_ROW:
			{
				port = (char*)sqlite3_column_text(stmt, 1);
				baudrate = sqlite3_column_int(stmt, 2);
			}
			break;
			case SQLITE_DONE:
			{
				done = true;
			}
			break;
			}
		}
		sqlite3_finalize(stmt);

		if (port.isEmpty())
		{
			try {
				PortSettings* dlg = new PortSettings(this);
				if (dlg->exec() == QDialog::Accepted)
				{
					port = dlg->getCATPort();
					baudrate = dlg->GetCatRate();
					m_radio = new QSerialPort(port);
					m_radio->setBaudRate(baudrate);
					m_radio->open(QSerialPort::OpenModeFlag::ReadWrite);
					if (m_radio->isOpen())
					{
						sql = fmt::format("insert into port_settings(port_name, baud_rate) values('{:s}',{:d})", port.toUtf8().operator const char* (), baudrate);
						sqlite3_exec(db, sql.c_str(), nullptr,
							nullptr,
							nullptr);
					}
				}
				else
				{					
					sqlite3_close(db);
					QFile f(spath.c_str());
					f.remove(spath.c_str());
					exit(EXIT_FAILURE);
					
				}
			}
			catch (std::exception& e)
			{
				OutputDebugStringA(e.what());
			}
		}
		else
		{
			m_radio = new QSerialPort(port);
			m_radio->setBaudRate(baudrate);
			m_radio->open(QSerialPort::OpenModeFlag::ReadWrite);
		}
	
}

void QtFT891::UpdateContourRecord()
{
	auto sql = fmt::format("select COUNT(*) from contour_settings;");
	sqlite3_stmt* stmt;
	sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
	bool done = false;
	QString port;
	int count = 0;
	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
		{
			count = sqlite3_column_int(stmt, 0);
		}
		break;
		case SQLITE_DONE:
		{
			done = true;
		}
		break;
		}
	}
	sqlite3_finalize(stmt);
    
	if (count > 0)
	{
		auto sql = fmt::format(R"~(
update contour_settings 
set
contour_enabled = {:d},
contour_level = {:d},
contour_freq  = {:d},
contour_width = {:d}
where id = 1;
 ;)~", contour_enabled, contour_level, contour_freq, contour_width);
       sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
	}
	else
	{
		auto sql = fmt::format(R"~(
insert into contour_settings(contour_enabled, contour_level,contour_freq, contour_width) values({:d},{:d},{:d},{:d});
)~", contour_enabled, contour_level, contour_freq, contour_width);
		sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
	}
}

bool QtFT891::UpdateFromContourRecord()
{
	auto sql = fmt::format("select COUNT(*) from contour_settings;");
	sqlite3_stmt* stmt;
	sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
	bool done = false;
	QString port;
	int count = 0;
	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
		{
			count = sqlite3_column_int(stmt, 0);
		}
		break;
		case SQLITE_DONE:
		{
			done = true;
		}
		break;
		}
	}
	sqlite3_finalize(stmt);
	if (count > 0) {
		auto sql = fmt::format("select contour_enabled, contour_level,contour_freq, contour_width from contour_settings where id = (select id from contour_settings limit 1);");
		sqlite3_stmt* stmt;
		sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
		bool done = false;
		QString port;
		int count = 0;
		while (!done)
		{
			switch (sqlite3_step(stmt))
			{
			case SQLITE_ROW:
			{
				contour_enabled = sqlite3_column_int(stmt, 0);
				contour_level = sqlite3_column_int(stmt, 1);
				contour_freq = sqlite3_column_int(stmt, 2);
				contour_width = sqlite3_column_int(stmt, 3);

			}
			break;
			case SQLITE_DONE:
			{
				done = true;
			}
			break;
			}
		}
		sqlite3_finalize(stmt);


		Yaesu::Commands::FT891::ContourValue cv;
		cv.Type = Yaesu::Commands::FT891::ContourType::ContourOnOff;
		cv.Value.state = contour_enabled == 1 ? Yaesu::Commands::FT891::ContourState::ON : Yaesu::Commands::FT891::ContourState::OFF;
		std::string cmd = Yaesu::Commands::FT891::Contour::Set(cv);
		 m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
		cv.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;
		cv.Value.Freq = contour_freq;
		cmd = Yaesu::Commands::FT891::Contour::Set(cv);
		 m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
		cmd = Yaesu::Commands::FT891::Menu::SetCountourWidth(contour_width);
		 m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
		cmd = Yaesu::Commands::FT891::Menu::SetCountourLevel(contour_level);
		 m_radio->write(cmd.c_str(), cmd.length());
		m_radio->flush();
	
		std::vector<std::string> cmds;
	
		Yaesu::Commands::FT891::ContourValue cval;
		cval.Type = Yaesu::Commands::FT891::ContourType::ContourFrequency;
		cmds.emplace_back(Yaesu::Commands::FT891::Contour::Read(cval));
		cmds.emplace_back(Yaesu::Commands::FT891::Menu::ReadCountourLevel());
		cmds.emplace_back(Yaesu::Commands::FT891::Menu::ReadCountourWidth());
		if (m_radio->isOpen())
		{
			for (auto cmd : cmds) {
				 m_radio->write(cmd.c_str(), cmd.length());
				m_radio->flush();
				std::this_thread::sleep_for(std::chrono::microseconds(20));
			}
		}
		return true;
	}
	else
	{
		return false;
	}

}

void QtFT891::UpdatePortSettings(QString Port, int BaudRate)
{
	
	std::string sql = fmt::format("update port_settings set port_name = '{:s}', baud_rate = {:d} where id = 1", Port.toUtf8().operator const char *(), BaudRate);
	sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

bool QtFT891::BandModeRecordExists(int band, int mode)
{

	std::lock_guard<std::mutex> lock(m_sql);
	std::string sql = fmt::format("select count(*) from band_mode_settings where band = {:d} and mode = {:d};",
		(band == -1 ? ui.cbBand->currentIndex() : band), (mode == -1 ? ui.cbMode->currentIndex() : mode));
	sqlite3_stmt* stmt;
	sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
	bool done = false;
	QString port;
	int count = 0;
	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
		{
			count = sqlite3_column_int(stmt, 0);
		}
		break;
		case SQLITE_DONE:
		{
			done = true;
		}
		break;
		}
	}
	sqlite3_finalize(stmt);
	return count > 0;
}

void QtFT891::UpdateBandModeRecord(int band, int mode)
{

	if (ui.cbBand->currentIndex() >= 0 && ui.cbMode->currentIndex() >= 0) {
		if (!BandModeRecordExists(band, mode))
		{
			CreateBandModeRecord(band, mode);
		}
		else
		{
			std::lock_guard<std::mutex> lock(m_sql);
			int dnrval = ui.DNR->value();
			int width = ui.cbWidth->currentIndex();
			currentBand = (band == -1 ? ui.cbBand->currentIndex() : band);
			currentMode = (mode == -1 ? ui.cbMode->currentIndex() : mode);
			std::string sql = fmt::format("update band_mode_settings set dnr_enabled = {:d}, dnr_value = {:d}, width_value = {:d} where band = {:d} and mode = {:d};",
				dnr_enabled,
				dnrval,
				width,
				currentBand,
				currentMode);
			sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
		}

	}

}

void QtFT891::CreateBandModeRecord(int band, int mode)
{

	std::lock_guard<std::mutex> lock(m_sql);

	std::string sql = fmt::format("insert into band_mode_settings(band, mode, dnr_enabled, dnr_value, width_value) values({:d},{:d},{:d},{:d},{:d});",
		(band == -1 ? ui.cbBand->currentIndex() : band),
		(mode == -1 ? ui.cbMode->currentIndex() : mode),
		dnr_enabled,
		ui.DNR->value(),
		ui.btnContour->palette().color(QPalette::Button) == QColor("green"),
		ui.cbWidth->currentIndex());
	sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);


}

void QtFT891::UpdateFromBandModeRecord(int band, int mode)
{

	

	loadingfromdb = true;
	ui.statusBar->showMessage("Updating radio from Database", 1000);
	if (!BandModeRecordExists(band, mode))
	{
		CreateBandModeRecord(band, mode);
		return;
	}
	std::lock_guard<std::mutex> lock(m_sql);
	std::string sql = fmt::format("select * from band_mode_settings where band = {:d} and mode = {:d};",
		(band == -1 ? ui.cbBand->currentIndex() : band),
		(mode == -1 ? ui.cbMode->currentIndex() : mode));
	sqlite3_stmt* stmt;
	sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, nullptr);
	bool done = false;

	std::string cmd;
	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
		{
			switch ((mode == -1 ? ui.cbMode->currentIndex() : mode))
			{
			case 0:
			case 1:
			case 2:
				WidthOffset = (NarrowState == Yaesu::Commands::FT891::NarrowValue::ON ? 0 : 9);
				break;
			default:
				WidthOffset = (NarrowState == Yaesu::Commands::FT891::NarrowValue::ON ? 0 : 10);
			}
			if (!loadingInit) {
				OutputDebugStringA("Update from database: BEGIN\r\n");
				int dnrvalue = sqlite3_column_int(stmt, 4);
				cmd = Yaesu::Commands::FT891::NoiseReductionLevel::Set(dnrvalue);
				OutputDebugStringA(fmt::format("Sending {}\r\n", cmd).c_str());
				m_radio->write(cmd.c_str(), cmd.length());
				int widthidx = sqlite3_column_int(stmt, 5);
				if (widthidx > 0) {
					Yaesu::Commands::FT891::WidthValue wv;
					wv.State = Yaesu::Commands::FT891::WidthState::ON;
					wv.WidthCommand = widthidx + WidthOffset;
					cmd = Yaesu::Commands::FT891::Width::Set(wv);
					OutputDebugStringA(fmt::format("Sending {}\r\n", cmd).c_str());
					m_radio->write(cmd.c_str(), cmd.length());
					m_radio->flush();
					ui.cbWidth->setCurrentIndex(widthidx);
				}

				if (sqlite3_column_int(stmt, 3) == 1)
				{

					dnr_enabled = 1;

					cmd = Yaesu::Commands::FT891::NoiseReduction::Set(Yaesu::Commands::FT891::NoiseReductionValue::ON);
					OutputDebugStringA(fmt::format("Sending {}\r\n", cmd).c_str());
					m_radio->write(cmd.c_str(), cmd.length());
					m_radio->flush();
				}
				cmd = Yaesu::Commands::FT891::AntennaTunerControl::Read();			
				m_radio->write(cmd.c_str(), cmd.length());
				m_radio->flush();
				
							
			}
		}
		break;
		case SQLITE_DONE:
		{
			done = true;
		}
		break;
		}
	}
	sqlite3_finalize(stmt);
	

}