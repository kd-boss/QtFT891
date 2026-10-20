#include "FTdx5000.h"
#include <fmt/format.h>

namespace Yaesu {
	namespace Commands {
		namespace FTdx5000 {

			std::string VFO_A_TO_B::Set()
			{
				return "AB;";
			}

			std::string ANTENNA_TUNER_CONTROL::Set(AntennaTunerState value)
			{				
				return fmt::format("AC0{:01d};", static_cast<int>(value));
			}

			std::string ANTENNA_TUNER_CONTROL::Read()
			{
				return "AC;";
			}

			AntennaTunerState ANTENNA_TUNER_CONTROL::Answer(std::string data)
			{
				return static_cast<AntennaTunerState>(std::stoi(&data[3]));
			}

			std::string AF_GAIN::Set(AFGainValue value)
			{
				value.value = value.value < 0 ? 0 : value.value;
				value.value = value.value > 255 ? 255 : value.value;

				return fmt::format("AG{:01d}{:03d};", static_cast<int>(value.band), value.value);
			}

			std::string AF_GAIN::Read(MainSubBandValue value)
			{
				return fmt::format("AG{:01d};", static_cast<int>(value));
			}

			AFGainValue AF_GAIN::Answer(std::string data)
			{
				AFGainValue ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.value = std::stoi(data.substr(3,3));
				return ret;
			}

			std::string AUTO_INFORMATION::Set(OnOffValue value)
			{
				return fmt::format("AI{:01d};", static_cast<int>(value));
			}

			std::string AUTO_INFORMATION::Read()
			{
				return "AI;";
			}

			OnOffValue AUTO_INFORMATION::Answer(std::string data)
			{				
				return static_cast<OnOffValue>(std::stoi(&data[2]));
			}

			std::string VFO_TO_MEMORY::Set()
			{
				return "AM;";
			}

			std::string ANTENNA_NUMBER::Set(MainSubBandValue value, AntennaNumber bvalue)
			{
				return fmt::format("AN{:01d}{:01d};", static_cast<int>(value), static_cast<int>(bvalue));
			}

			std::string ANTENNA_NUMBER::Read(MainSubBandValue value)
			{
				return fmt::format("AN{:01d};", static_cast<int>(value));
			}

			AntennaNumberValue ANTENNA_NUMBER::Answer(std::string data)
			{
				AntennaNumberValue ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.antenna = static_cast<AntennaNumber>(std::stoi(&data[3]));
				ret.rxOnly = static_cast<OnOffValue>(std::stoi(&data[4]));
				return ret;
			}

			std::string VFO_B_TO_VFO_A::Set()
			{
				return "BA;";
			}

			std::string AUTO_NOTCH::Set(BandOnOffValue value)
			{
				return fmt::format("BC{:01d}{:01d};", static_cast<int>(value.band), static_cast<int>(value.value));
			}

			std::string AUTO_NOTCH::Read(MainSubBandValue value)
			{
				return fmt::format("BC{:01d};", static_cast<int>(value));
			}

			BandOnOffValue AUTO_NOTCH::Answer(std::string data)
			{
				BandOnOffValue ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.value = static_cast<OnOffValue>(std::stoi(&data[3]));
				return ret;
			}

			std::string BAND_DOWN::Set(MainSubBandValue value)
			{
				return fmt::format("BD{:01d};", static_cast<int>(value));
			}


			std::string BUSY::Read()
			{
				return "BY;";
			}

			BusyValue BUSY::Answer(std::string data)
			{
				BusyValue ret{};
				ret.mainBand = static_cast<OnOffValue>(std::stoi(&data[2]));
				ret.subBand = static_cast<OnOffValue>(std::stoi(&data[3]));
				return ret;
			}

			std::string CLASS_A::Set(BiasValue value)
			{
				switch (value.type)
				{
				case BiasType::Bias_Level:
					return fmt::format("CA{:01d}{:03d};", static_cast<int>(value.type), static_cast<int>(value.value.level));
					break;
				case BiasType::ClassA_OnOff:
					return fmt::format("CA{:01d}{:03d};", static_cast<int>(value.type), static_cast<int>(value.value.onOff));
					break;
				default:
					return "";
				}				
			}

			std::string CLASS_A::Read(BiasType value)
			{
				return fmt::format("CA{:01d};", static_cast<int>(value));
			}

			BiasValue CLASS_A::Answer(std::string data)
			{
				BiasValue ret{};
				ret.type = static_cast<BiasType>(std::stoi(&data[2]));
				switch (ret.type)
				{
				case BiasType::Bias_Level:
					ret.value.level = std::stoi(data.substr(3, 3));
					break;
				case BiasType::ClassA_OnOff:
					ret.value.onOff = static_cast<OnOffValue>(std::stoi(data.substr(3,3)));
					break;
				default:
					ret.value.level = 0;
					ret.value.onOff = OnOffValue::OFF;
					break;
				}
				return ret;
			}

			std::string CHANNEL_UP_DOWN::Set(UpDownValue value)
			{
				return fmt::format("CH{:01d};", static_cast<int>(value));
			}

			std::string CTCSS_TONE_FREQUENCY::Set(CTCSSToneValue value)
			{
				
				return fmt::format("CN{:01d}{:02d};", static_cast<int>(value.band), static_cast<int>(value.tone));
			}

			std::string CTCSS_TONE_FREQUENCY::Read(MainSubBandValue value)
			{
				return fmt::format("CN{:01d};", static_cast<int>(value));
			}

			CTCSSToneValue CTCSS_TONE_FREQUENCY::Answer(std::string data)
			{
				CTCSSToneValue ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.tone = static_cast<CTCSSTone>(std::stoi(data.substr(3, 2)));
				return ret;
			}

			std::string CONTOUR::Set(ContourParam value)
			{
				int val = 0;
				switch (value.type)
				{
				case ContourType::OnOff:
					val = static_cast<int>(value.value.value);
					break;
				case ContourType::Frequency:
					val = value.value.frequency;
					break;

				}
				return fmt::format("CO{:01d}{:01d}{:02d};",
					static_cast<int>(value.band), 
					static_cast<int>(value.type), 
					val);
			}

			std::string CONTOUR::Read(MainSubBandValue band, ContourType type)
			{
				return fmt::format("CO{:01d}{:01d};", static_cast<int>(band), static_cast<int>(type));
			}

			ContourParam CONTOUR::Answer(std::string data)
			{
				ContourParam ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.type = static_cast<ContourType>(std::stoi(&data[3]));
				switch (ret.type)
				{
				case ContourType::OnOff:
					ret.value.value = static_cast<ContourValue>(std::stoi(&data[4]));
					break;
				case ContourType::Frequency:
					ret.value.frequency = std::stoi(data.substr(4, 2));
					break;
				default:
					ret.value.value = ContourValue::OFF;
					ret.value.frequency = 0;
					break;
				}
				return ret;
			}

			std::string CW_SPOT::Set(OnOffValue value)
			{

				return fmt::format("CS{:01d};", static_cast<int>(value));
			}

			std::string CW_SPOT::Read()
			{
				return "CS;";
			}

			OnOffValue CW_SPOT::Answer(std::string data)
			{
				return static_cast<OnOffValue>(std::stoi(&data[2]));
			}

			std::string CTCSS::Set(CTCSSParam value)
			{				
				return fmt::format("CT{:01d}{:01d};", static_cast<int>(value.band), static_cast<int>(value.type));
			}

			std::string CTCSS::Read(MainSubBandValue value)
			{

				return fmt::format("CT{:01d};", static_cast<int>(value));
			}

			CTCSSParam CTCSS::Answer(std::string data)
			{
				CTCSSParam ret{};
				ret.band = static_cast<MainSubBandValue>(std::stoi(&data[2]));
				ret.type = static_cast<CTCSSType>(std::stoi(&data[3]));
				return ret;
			}

			std::string DIMMER::Set(DimmerParam value)
			{
				return fmt::format("DA{:02d}{:02d}{:02d}{:02d};",
					value.VFD_brightness,
					value.METER_brightness,
					value.OLED_brightness,
					value.ELCD_brightness);
			}

			std::string DIMMER::Read()
			{
				return "DA;";
			}

			DimmerParam DIMMER::Answer(std::string data)
			{
				DimmerParam ret{};
				ret.VFD_brightness = std::stoi(data.substr(2, 2));
				ret.METER_brightness = std::stoi(data.substr(4, 2));
				ret.OLED_brightness = std::stoi(data.substr(6, 2));
				ret.ELCD_brightness = std::stoi(data.substr(8, 2));
				return ret;
			}

			std::string MIC_DOWN::Set()
			{
				return "DN;";
			}

			std::string DISPLAY::Set(DisplayType value)
			{
				return fmt::format("DP{:01d};", static_cast<int>(value));
			}

			std::string DISPLAY::Read()
			{
				return "DP;";
			}

			DisplayType DISPLAY::Answer(std::string data)
			{
				return static_cast<DisplayType>(std::stoi(&data[2]));
			}

			std::string DIMMER_SWITCH::Set(OnOffValue value)
			{
				return fmt::format("DS{:01d};", static_cast<int>(value));
			}

			std::string DIMMER_SWITCH::Read()
			{
				return "DS;";
			}

			OnOffValue DIMMER_SWITCH::Answer(std::string data)
			{
				return static_cast<OnOffValue>(std::stoi(&data[2]));
			}

			std::string ENCODER_DOWN::Set(EncoderParam value)
			{
				value.steps = value.steps < 0 ? 0 : value.steps;
				value.steps = value.steps > 99 ? 99 : value.steps;
				return fmt::format("ED{:01d}{:02d};", static_cast<int>(value.encoder), static_cast<int>(value.steps));
			}

			std::string ENCODER_UP::Set(EncoderParam value)
			{
				value.steps = value.steps < 0 ? 0 : value.steps;
				value.steps = value.steps > 99 ? 99 : value.steps;
				return fmt::format("EU{:01d}{:02d};", static_cast<int>(value.encoder), static_cast<int>(value.steps));
			}

			std::string Menu::MAIN_FAST_DELAY::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 4000 ? 4000 : value;
				value = 20 * (value / 20); // round to 20)
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_FAST_DELAY),
					value);
			}

			std::string Menu::MAIN_FAST_DELAY::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_FAST_DELAY));
			}

			int Menu::MAIN_FAST_DELAY::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}

			std::string Menu::MAIN_FAST_HOLD::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 2000 ? 2000 : value;
				value = 20 * (value / 20); // round to 20
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_FAST_HOLD),
					value);
			}

			std::string Menu::MAIN_FAST_HOLD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_FAST_HOLD));
			}

			int Menu::MAIN_FAST_HOLD::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}


			std::string Menu::MAIN_MID_DELAY::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 4000 ? 4000 : value;
				value = 20 * (value / 20); // round to 20)
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_MID_DELAY),
					value);
			}

			std::string Menu::MAIN_MID_DELAY::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_MID_DELAY));
			}

			int Menu::MAIN_MID_DELAY::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}

			std::string Menu::MAIN_MID_HOLD::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 2000 ? 2000 : value;
				value = 20 * (value / 20); // round to 20
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_MID_HOLD),
					value);
			}

			std::string Menu::MAIN_MID_HOLD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_MID_HOLD));
			}

			int Menu::MAIN_MID_HOLD::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}

			std::string Menu::MAIN_SLOW_DELAY::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 4000 ? 4000 : value;
				value = 20 * (value / 20); // round to 20)
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_SLOW_DELAY),
					value);
			}

			std::string Menu::MAIN_SLOW_DELAY::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_SLOW_DELAY));
			}

			int Menu::MAIN_SLOW_DELAY::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}

			std::string Menu::MAIN_SLOW_HOLD::Set(int value)
			{
				value = value < 20 ? 20 : value;
				value = value > 2000 ? 2000 : value;
				value = 20 * (value / 20); // round to 20
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::MAIN_SLOW_HOLD),
					value);
			}

			std::string Menu::MAIN_SLOW_HOLD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MAIN_SLOW_HOLD));
			}

			int Menu::MAIN_SLOW_HOLD::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in ms
			}

			std::string Menu::TFT_COLOR::Set(TFTColor value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::TFT_COLOR),
					static_cast<int>(value));
			}

			std::string Menu::TFT_COLOR::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TFT_COLOR));
			}

			TFTColor Menu::TFT_COLOR::Answer(std::string data)
			{
				return static_cast<TFTColor>(std::stoi(&data[5]));
			}



			std::string Menu::DIMMER_METER::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 15 ? 15 : value;
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::DIMMER_METER),
					value);
			}

			std::string Menu::DIMMER_METER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DIMMER_METER));
			}

			int Menu::DIMMER_METER::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 0-15
			}

			std::string Menu::DIMMER_OLE::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 15 ? 15 : value;
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::DIMMER_OLE),
					value);
			}

			std::string Menu::DIMMER_OLE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DIMMER_OLE));
			}

			int Menu::DIMMER_OLE::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 0-15
			}

			std::string Menu::DIMMER_VFD::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 15 ? 15 : value;
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::DIMMER_VFD),
					value);
			}

			std::string Menu::DIMMER_VFD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DIMMER_VFD));
			}

			int Menu::DIMMER_VFD::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 0-15
			}

			std::string Menu::DIMMER_E_LCD::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 15 ? 15 : value;
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::DIMMER_E_LCD),
					value);
			}

			std::string Menu::DIMMER_E_LCD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DIMMER_E_LCD));
			}

			int Menu::DIMMER_E_LCD::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 0-15
			}

			std::string Menu::BAR_DISPLAY_SELECT::Set(BarDisplayType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::BAR_DISPLAY_SELECT),
					static_cast<int>(value));
			}

			std::string Menu::BAR_DISPLAY_SELECT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::BAR_DISPLAY_SELECT));
			}

			BarDisplayType Menu::BAR_DISPLAY_SELECT::Answer(std::string data)
			{
				return static_cast<BarDisplayType>(std::stoi(&data[5]));
			}

			std::string Menu::SUB_MTR_PEAK_HOLD::Set(PeakHoldTime value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SUB_MTR_PEAK_HOLD),
					static_cast<int>(value));
			}

			std::string Menu::SUB_MTR_PEAK_HOLD::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SUB_MTR_PEAK_HOLD));
			}

			PeakHoldTime Menu::SUB_MTR_PEAK_HOLD::Answer(std::string data)
			{
				return static_cast<PeakHoldTime>(std::stoi(&data[5]));
			}
			
			std::string Menu::ROTATOR_START_UP::Set(RotorStartUpValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::ROTATOR_START_UP),
					static_cast<int>(value));
			}

			std::string Menu::ROTATOR_START_UP::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::ROTATOR_START_UP));
			}

			RotorStartUpValue Menu::ROTATOR_START_UP::Answer(std::string data)
			{
				return static_cast<RotorStartUpValue>(std::stoi(&data[5]));
			}



			std::string Menu::ROTATOR_OFFSET_ADJ::Set(int value)
			{
				value = value < -30 ? -30 : value;
				value = value > 30 ? 30 : value;
				value = 2 * (value / 2); // round to 2
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::ROTATOR_OFFSET_ADJ),
					value);
			}

			std::string Menu::ROTATOR_OFFSET_ADJ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::ROTATOR_OFFSET_ADJ));
			}

			int Menu::ROTATOR_OFFSET_ADJ::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in -30 to 30
			}

			std::string Menu::QMB_MARKER::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::QMB_MARKER),
					static_cast<int>(value));
			}

			std::string Menu::QMB_MARKER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::QMB_MARKER));
			}

			EnableDisableValue Menu::QMB_MARKER::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}



			std::string Menu::LEVEL_INDICATOR::Set(LevelIndicatorType value)
			{
				std::string body;
				body.resize(13,'0');
				switch (value)
				{
				case LevelIndicatorType::CW_PITCH:
					body[0] = '1';
					break;
				case LevelIndicatorType::CW_SPEED:
					body[1] = '1';
					break;
				case LevelIndicatorType::CW_DELAY:
					body[5] = '1';
					break;
				case LevelIndicatorType::VOX_DELAY:
					body[6] = '1';
					break;
				case LevelIndicatorType::RF_POWER:
					body[7] = '1';
					break;
				case LevelIndicatorType::MIC_GAIN:
					body[8] = '1';
					break;
				case LevelIndicatorType::PROCE:
					body[9] = '1';
					break;
				}
				return fmt::format("EX{:03d}{};",
					static_cast<int>(MenuItem::LEVEL_INDICATOR),
					body);

			}

			std::string Menu::LEVEL_INDICATOR::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::LEVEL_INDICATOR));
			}

			LevelIndicatorType Menu::LEVEL_INDICATOR::Answer(std::string data)
			{
				std::string body = data.substr(5, 13);
				if (body[0] == '1') return LevelIndicatorType::CW_PITCH;
				if (body[1] == '1') return LevelIndicatorType::CW_SPEED;
				if (body[5] == '1') return LevelIndicatorType::CW_DELAY;
				if (body[6] == '1') return LevelIndicatorType::VOX_DELAY;
				if (body[7] == '1') return LevelIndicatorType::RF_POWER;
				if (body[8] == '1') return LevelIndicatorType::MIC_GAIN;
				if (body[9] == '1') return LevelIndicatorType::PROCE;
			}

			std::string Menu::INDICATOR::Set(IndicatorType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::INDICATOR),
					static_cast<int>(value));
			}

			std::string Menu::INDICATOR::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::INDICATOR));
			}

			IndicatorType Menu::INDICATOR::Answer(std::string data)
			{
				return static_cast<IndicatorType>(std::stoi(&data[5]));
			}
			
			std::string Menu::SELECT::Set(SelectValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SELECT),
					static_cast<int>(value));
			}

			std::string Menu::SELECT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SELECT));
			}

			SelectValue Menu::SELECT::Answer(std::string data)
			{
				return static_cast<SelectValue>(std::stoi(&data[5]));
			}



			std::string Menu::RX_OUT_LEVEL::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value; // 0-100
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::RX_OUT_LEVEL),
					value);
			}

			std::string Menu::RX_OUT_LEVEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RX_OUT_LEVEL));
			}

			int Menu::RX_OUT_LEVEL::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in 0-100
			}

			std::string Menu::TX_OUT_LEVEL::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value; // 0-100
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::TX_OUT_LEVEL),
					value);
			}

			std::string Menu::TX_OUT_LEVEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TX_OUT_LEVEL));
			}

			int Menu::TX_OUT_LEVEL::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in 0-100
			}
			


			std::string Menu::BEACON_TIME::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 255 ? 255 : value; // 0-255
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::BEACON_TIME),
					value);
			}

			std::string Menu::BEACON_TIME::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::BEACON_TIME));
			}

			int Menu::BEACON_TIME::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in 0-255
			}



			std::string Menu::NUMBER_STYLE::Set(NumberStyle value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::NUMBER_STYLE),
					static_cast<int>(value));
			}

			std::string Menu::NUMBER_STYLE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::NUMBER_STYLE));
			}

			NumberStyle Menu::NUMBER_STYLE::Answer(std::string data)
			{
				return static_cast<NumberStyle>(std::stoi(&data[5]));
			}

			std::string Menu::CONTEST_NUMBER::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 9999 ? 9999 : value; // 0-9999
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::CONTEST_NUMBER),
					value);
			}

			std::string Menu::CONTEST_NUMBER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CONTEST_NUMBER));
			}

			int Menu::CONTEST_NUMBER::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in 0-9999
			}



			std::string Menu::CW_MEMORY_1::Set(KeyerMemoryType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_MEMORY_1),
					static_cast<int>(value));
			}

			std::string Menu::CW_MEMORY_1::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_MEMORY_1));
			}

			KeyerMemoryType Menu::CW_MEMORY_1::Answer(std::string data)
			{
				return static_cast<KeyerMemoryType>(std::stoi(&data[5]));
			}


			std::string Menu::CW_MEMORY_2::Set(KeyerMemoryType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_MEMORY_2),
					static_cast<int>(value));
			}

			std::string Menu::CW_MEMORY_2::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_MEMORY_2));
			}

			KeyerMemoryType Menu::CW_MEMORY_2::Answer(std::string data)
			{
				return static_cast<KeyerMemoryType>(std::stoi(&data[5]));
			}


			std::string Menu::CW_MEMORY_3::Set(KeyerMemoryType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_MEMORY_3),
					static_cast<int>(value));
			}

			std::string Menu::CW_MEMORY_3::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_MEMORY_3));
			}

			KeyerMemoryType Menu::CW_MEMORY_3::Answer(std::string data)
			{
				return static_cast<KeyerMemoryType>(std::stoi(&data[5]));
			}


			std::string Menu::CW_MEMORY_4::Set(KeyerMemoryType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_MEMORY_4),
					static_cast<int>(value));
			}

			std::string Menu::CW_MEMORY_4::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_MEMORY_4));
			}

			KeyerMemoryType Menu::CW_MEMORY_4::Answer(std::string data)
			{
				return static_cast<KeyerMemoryType>(std::stoi(&data[5]));
			}


			std::string Menu::CW_MEMORY_5::Set(KeyerMemoryType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_MEMORY_5),
					static_cast<int>(value));
			}

			std::string Menu::CW_MEMORY_5::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_MEMORY_5));
			}

			KeyerMemoryType Menu::CW_MEMORY_5::Answer(std::string data)
			{
				return static_cast<KeyerMemoryType>(std::stoi(&data[5]));
			}

			std::string Menu::ANT_SELECT::Set(AntSelectType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::ANT_SELECT),
					static_cast<int>(value));
			}

			std::string Menu::ANT_SELECT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::ANT_SELECT));
			}

			AntSelectType Menu::ANT_SELECT::Answer(std::string data)
			{
				return static_cast<AntSelectType>(std::stoi(&data[5]));
			}

			std::string Menu::BEEP_LEVEL::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value; // 0-100
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::BEEP_LEVEL),
					value);
			}

			std::string Menu::BEEP_LEVEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::BEEP_LEVEL));
			}

			int Menu::BEEP_LEVEL::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in 0-100
			}

			std::string Menu::CAT_RATE::Set(CATRate value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CAT_RATE),
					static_cast<int>(value));
			}

			std::string Menu::CAT_RATE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CAT_RATE));
			}

			CATRate Menu::CAT_RATE::Answer(std::string data)
			{
				return static_cast<CATRate>(std::stoi(&data[5]));
			}

			std::string Menu::CAT_TIME_OUT_TIMER::Set(CATTimeoutValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CAT_TIME_OUT_TIMER),
					static_cast<int>(value));
			}

			std::string Menu::CAT_TIME_OUT_TIMER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CAT_TIME_OUT_TIMER));
			}

			CATTimeoutValue Menu::CAT_TIME_OUT_TIMER::Answer(std::string data)
			{
				return static_cast<CATTimeoutValue>(std::stoi(&data[5]));
			}


			std::string Menu::CAT_RTS::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CAT_RTS),
					static_cast<int>(value));
			}

			std::string Menu::CAT_RTS::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CAT_RTS));
			}

			EnableDisableValue Menu::CAT_RTS::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}

			std::string Menu::CAT_DATA_INDICATOR::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CAT_DATA_INDICATOR),
					static_cast<int>(value));
			}

			std::string Menu::CAT_DATA_INDICATOR::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CAT_DATA_INDICATOR));
			}

			EnableDisableValue Menu::CAT_DATA_INDICATOR::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}


			std::string Menu::MEM_GROUP::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::MEM_GROUP),
					static_cast<int>(value));
			}

			std::string Menu::MEM_GROUP::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MEM_GROUP));
			}

			EnableDisableValue Menu::MEM_GROUP::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}

			std::string Menu::QUICK_SPLIT_FREQ::Set(int value)
			{
				value = value < -20 ? -20 : value;
				value = value > 20 ? 20 : value; // -20 to 20
				return fmt::format("EX{:03d}{:+03d};",
					static_cast<int>(MenuItem::QUICK_SPLIT_FREQ),
					value);
			}

			std::string Menu::QUICK_SPLIT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::QUICK_SPLIT_FREQ));
			}

			int Menu::QUICK_SPLIT_FREQ::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in -20 to 20
			}

			std::string Menu::TRACKING::Set(TrackingType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::TRACKING),
					static_cast<int>(value));
			}

			std::string Menu::TRACKING::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TRACKING));
			}

			TrackingType Menu::TRACKING::Answer(std::string data)
			{
				return static_cast<TrackingType>(std::stoi(&data[5]));
			}

			std::string Menu::TIME_OUT_TIMER::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 30 ? 30 : value; // 0-30 minutes
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::TIME_OUT_TIMER),
					value);
			}

			std::string Menu::TIME_OUT_TIMER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TIME_OUT_TIMER));
			}

			int Menu::TIME_OUT_TIMER::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 0-30 minutes
			}

			std::string Menu::TRV_OFFSET_14MHz::Set(int value)
			{
				value = value < 30 ? 30 : value;
				value = value > 46 ? 46 : value; // 30 to 46 MHz
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::TRV_OFFSET_14MHz),
					value);
			}

			std::string Menu::TRV_OFFSET_14MHz::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TRV_OFFSET_14MHz));
			}

			int Menu::TRV_OFFSET_14MHz::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 30 to 46 MHz
			}

			std::string Menu::TRV_OFFSET_28MHz::Set(int value)
			{
				value = value < 30 ? 30 : value;
				value = value > 46 ? 46 : value; // 30 to 46 MHz
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::TRV_OFFSET_28MHz),
					value);
			}

			std::string Menu::TRV_OFFSET_28MHz::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TRV_OFFSET_28MHz));
			}

			int Menu::TRV_OFFSET_28MHz::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 30 to 46 MHz
			}

			std::string Menu::TRV_OFFSET_50MHz::Set(int value)
			{
				value = value < 30 ? 30 : value;
				value = value > 46 ? 46 : value; // 30 to 46 MHz
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::TRV_OFFSET_50MHz),
					value);
			}

			std::string Menu::TRV_OFFSET_50MHz::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::TRV_OFFSET_50MHz));
			}

			int Menu::TRV_OFFSET_50MHz::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2)); // return value in 30 to 46 MHz
			}


			std::string Menu::uTUNE_DIAL_STEP::Set(uTuneDialStep value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::uTUNE_DIAL_STEP),
					static_cast<int>(value));
			}

			std::string Menu::uTUNE_DIAL_STEP::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::uTUNE_DIAL_STEP));
			}

			uTuneDialStep Menu::uTUNE_DIAL_STEP::Answer(std::string data)
			{
				return static_cast<uTuneDialStep>(std::stoi(&data[5]));
			}



			std::string Menu::MIC_SCAN::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::MIC_SCAN),
					static_cast<int>(value));
			}

			std::string Menu::MIC_SCAN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MIC_SCAN));
			}

			EnableDisableValue Menu::MIC_SCAN::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}

			std::string Menu::MIC_SCAN_RESUME::Set(MicScanResumeType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::MIC_SCAN_RESUME),
					static_cast<int>(value));
			}

			std::string Menu::MIC_SCAN_RESUME::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::MIC_SCAN_RESUME));
			}

			MicScanResumeType Menu::MIC_SCAN_RESUME::Answer(std::string data)
			{
				return static_cast<MicScanResumeType>(std::stoi(&data[5]));
			}



			std::string Menu::FREQ_ADJ::Set(int value)
			{
				value = value < -25 ? -25 : value;
				value = value > 25 ? 25 : value; // -25 to 25 Hz
				return fmt::format("EX{:03d}{:+03d};",
					static_cast<int>(MenuItem::FREQ_ADJ),
					value);
			}

			std::string Menu::FREQ_ADJ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FREQ_ADJ));
			}

			int Menu::FREQ_ADJ::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3)); // return value in -25 to 25 Hz
			}



			std::string Menu::AM_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::AM_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::AM_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_LCUT_FREQ));
			}

			FreqLowCutValue Menu::AM_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5, 2))); // return value (OFF, 0.1- 1kHz, 50 Hz per step)
			}

			std::string Menu::AM_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::AM_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::AM_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_LCUT_SLOPE));
			}

			SlopeValue Menu::AM_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::AM_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::AM_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::AM_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_HCUT_FREQ));
			}

			FreqHighCutValue Menu::AM_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::AM_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::AM_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::AM_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_HCUT_SLOPE));
			}

			SlopeValue Menu::AM_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::AM_MIC_GAIN::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 && value < 1000 ? 100 : value;
				value = value > 1000 ? 1000 : value; // 0-1000
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::AM_MIC_GAIN),
					value);

			}

			std::string Menu::AM_MIC_GAIN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_MIC_GAIN));
			}

			int Menu::AM_MIC_GAIN::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4)); // return value in 0-1000
			}

			std::string Menu::AM_MIC_SEL::Set(MicSelectValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::AM_MIC_SEL),
					static_cast<int>(value));
			}

			std::string Menu::AM_MIC_SEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::AM_MIC_SEL));
			}

			MicSelectValue Menu::AM_MIC_SEL::Answer(std::string data)
			{
				return static_cast<MicSelectValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, MIC1, MIC2, MIC3)
			}

			std::string Menu::CW_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::CW_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::CW_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_LCUT_FREQ));
			}

			FreqLowCutValue Menu::CW_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5, 2))); // return value (OFF, 0.1- 1kHz, 50 Hz per step)
			}

			std::string Menu::CW_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::CW_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_LCUT_SLOPE));
			}

			SlopeValue Menu::CW_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::CW_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::CW_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::CW_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_HCUT_FREQ));
			}

			FreqHighCutValue Menu::CW_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::CW_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::CW_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_HCUT_SLOPE));
			}

			SlopeValue Menu::CW_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::F_KEYER_TYPE::Set(KeyerType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::F_KEYER_TYPE),
					static_cast<int>(value));
			}

			std::string Menu::F_KEYER_TYPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::F_KEYER_TYPE));
			}

			KeyerType Menu::F_KEYER_TYPE::Answer(std::string data)
			{
				return static_cast<KeyerType>(std::stoi(&data[5])); // return value in 0-3 (OFF, Bug, Electric, ACS)
			}

			std::string Menu::F_CW_KEYER::Set(KeyerDotDashType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::F_CW_KEYER),
					static_cast<int>(value));
			}

			std::string Menu::F_CW_KEYER::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::F_CW_KEYER));
			}

			KeyerDotDashType Menu::F_CW_KEYER::Answer(std::string data)
			{
				return static_cast<KeyerDotDashType>(std::stoi(&data[5])); // return value in 0-3 (OFF, Dot, Dash, DotDash)
			}

			std::string Menu::CW_AUTO_MODE::Set(CWAutoMode value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_AUTO_MODE),
					static_cast<int>(value));
			}

			std::string Menu::CW_AUTO_MODE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_AUTO_MODE));
			}

			CWAutoMode Menu::CW_AUTO_MODE::Answer(std::string data)
			{
				return static_cast<CWAutoMode>(std::stoi(&data[5]));
			}

			std::string Menu::CW_BFO::Set(BfoValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_BFO),
					static_cast<int>(value));
			}

			std::string Menu::CW_BFO::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_BFO));
			}

			BfoValue Menu::CW_BFO::Answer(std::string data)
			{
				return static_cast<BfoValue>(std::stoi(&data[5])); // return value (USB, LSB, AUTO)
			}

			std::string Menu::CW_BK_IN::Set(BreakInType value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_BK_IN),
					static_cast<int>(value));
			}

			std::string Menu::CW_BK_IN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_BK_IN));
			}

			BreakInType Menu::CW_BK_IN::Answer(std::string data)
			{
				return static_cast<BreakInType>(std::stoi(&data[5])); // return value in 0-3 (OFF, Semi, Full, Auto)
			}

			std::string Menu::CW_WAVE_SHAPE::Set(CWWaveShape value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_WAVE_SHAPE),
					static_cast<int>(value));
			}

			std::string Menu::CW_WAVE_SHAPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_WAVE_SHAPE));
			}

			CWWaveShape Menu::CW_WAVE_SHAPE::Answer(std::string data)
			{
				return static_cast<CWWaveShape>(std::stoi(&data[5])); // return value in 0-3 (OFF, Semi, Full, Auto)
			}

			std::string Menu::CW_WEIGHT::Set(int value)
			{
				value = value < 25 ? 25 : value;
				value = value > 45 ? 45 : value;
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::CW_WEIGHT),
					value);
			}

			std::string Menu::CW_WEIGHT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_WEIGHT));
			}

			int Menu::CW_WEIGHT::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 2));
			}

			std::string Menu::CW_FREQ_DISPLAY::Set(CWFrequencyDisplay value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::CW_FREQ_DISPLAY),
					static_cast<int>(value));
			}

			std::string Menu::CW_FREQ_DISPLAY::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::CW_FREQ_DISPLAY));
			}

			CWFrequencyDisplay Menu::CW_FREQ_DISPLAY::Answer(std::string data)
			{
				return static_cast<CWFrequencyDisplay>(std::stoi(&data[5]));
			}

			std::string Menu::PC_KEYING::Set(EnableDisableValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::PC_KEYING),
					static_cast<int>(value));
			}

			std::string Menu::PC_KEYING::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PC_KEYING));
			}

			EnableDisableValue Menu::PC_KEYING::Answer(std::string data)
			{
				return static_cast<EnableDisableValue>(std::stoi(&data[5]));
			}

			std::string Menu::QSK::Set(QSKDealyValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::QSK),
					static_cast<int>(value));
			}

			std::string Menu::QSK::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::QSK));
			}

			QSKDealyValue Menu::QSK::Answer(std::string data)
			{
				return static_cast<QSKDealyValue>(std::stoi(&data[5]));
			}

			std::string Menu::DATA_IN_SELECT::Set(DataInValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::DATA_IN_SELECT),
					static_cast<int>(value));
			}

			std::string Menu::DATA_IN_SELECT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_IN_SELECT));
			}

			DataInValue Menu::DATA_IN_SELECT::Answer(std::string data)
			{
				return static_cast<DataInValue>(std::stoi(&data[5]));
			}

			std::string Menu::DATA_TX_GAIN::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value;
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::DATA_TX_GAIN),
					value);
			}

			std::string Menu::DATA_TX_GAIN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_TX_GAIN));
			}

			int Menu::DATA_TX_GAIN::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3));
			}

			std::string Menu::DATA_OUT::Set(OutValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::DATA_OUT),
					static_cast<int>(value));
			}

			std::string Menu::DATA_OUT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_OUT));
			}

			OutValue Menu::DATA_OUT::Answer(std::string data)
			{
				return static_cast<OutValue>(std::stoi(&data[5]));
			}

			std::string Menu::DATA_OUT_LEVEL::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value;
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::DATA_OUT_LEVEL),
					value);
			}

			std::string Menu::DATA_OUT_LEVEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_OUT_LEVEL));
			}

			int Menu::DATA_OUT_LEVEL::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3));
			}

			std::string Menu::DATA_VOX_DELAY::Set(int value)
			{
				//0030 3000 10ms step
				value = value < 30 ? 30 : value;
				value = value > 3000 ? 3000 : value;
				value = 10 * (value / 10);
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::DATA_VOX_DELAY),
					value);
			}

			std::string Menu::DATA_VOX_DELAY::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_VOX_DELAY));
			}

			int Menu::DATA_VOX_DELAY::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}

			std::string Menu::DATA_VOX_GAIN::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value;
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::DATA_VOX_GAIN),
					value);
			}

			std::string Menu::DATA_VOX_GAIN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::DATA_VOX_GAIN));
			}

			int Menu::DATA_VOX_GAIN::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3));
			}



			std::string Menu::FM_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::FM_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::FM_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_LCUT_FREQ));
			}

			FreqLowCutValue Menu::FM_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5,2)));
			}

			std::string Menu::FM_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::FM_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::FM_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_LCUT_SLOPE));
			}

			SlopeValue Menu::FM_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::FM_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::FM_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::FM_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_HCUT_FREQ));
			}

			FreqHighCutValue Menu::FM_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::FM_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::FM_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::FM_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_HCUT_SLOPE));
			}

			SlopeValue Menu::FM_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::FM_MIC_GAIN::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 && value != 1000 ? 100 : value;
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::FM_MIC_GAIN),
					value);

			}

			std::string Menu::FM_MIC_GAIN::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_MIC_GAIN));
			}

			int Menu::FM_MIC_GAIN::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}

			std::string Menu::FM_MIC_SEL::Set(MicSelectValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::FM_MIC_SEL),
					static_cast<int>(value));
			}

			std::string Menu::FM_MIC_SEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::FM_MIC_SEL));
			}

			MicSelectValue Menu::FM_MIC_SEL::Answer(std::string data)
			{
				return static_cast<MicSelectValue>(std::stoi(&data[5]));
			}

			std::string Menu::RPT_SHIFT_28MHz::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 1000 ? 1000 : value;
				value = 10 * (value / 10); // 10 Hz steps
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::RPT_SHIFT_28MHz),
					value);
			}

			std::string Menu::RPT_SHIFT_28MHz::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RPT_SHIFT_28MHz));
			}

			int Menu::RPT_SHIFT_28MHz::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}

			std::string Menu::RPT_SHIFT_50MHz::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 4000 ? 4000 : value;
				value = 10 * (value / 10); // 10 Hz steps
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::RPT_SHIFT_50MHz),
					value);
			}

			std::string Menu::RPT_SHIFT_50MHz::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RPT_SHIFT_50MHz));
			}

			int Menu::RPT_SHIFT_50MHz::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}

			std::string Menu::PKT_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::PKT_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::PKT_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_LCUT_FREQ));
			}

			FreqLowCutValue Menu::PKT_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5, 2)));
			}

			std::string Menu::PKT_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::PKT_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::PKT_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_LCUT_SLOPE));
			}

			SlopeValue Menu::PKT_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::PKT_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::PKT_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::PKT_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_HCUT_FREQ));
			}

			FreqHighCutValue Menu::PKT_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::PKT_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::PKT_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::PKT_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_HCUT_SLOPE));
			}

			SlopeValue Menu::PKT_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::PKT_DISP_SSB::Set(int value)
			{
				value = value < -3000 ? -3000 : value;
				value = value > 3000 ? 3000 : value;
				value = (value > 0 ? 10 : -10) * (std::abs(value) / 10);
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::PKT_DISP_SSB),
					value);
			}

			std::string Menu::PKT_DISP_SSB::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_DISP_SSB));
			}

			int Menu::PKT_DISP_SSB::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}

			std::string Menu::PKT_SHIFT_SSB::Set(int value)
			{
				value = value < -3000 ? -3000 : value;
				value = value > 3000 ? 3000 : value;
				value = (value > 0 ? 10 : -10) * (std::abs(value) / 10);
				return fmt::format("EX{:03d}{:04d};",
					static_cast<int>(MenuItem::PKT_SHIFT_SSB),
					value);
			}

			std::string Menu::PKT_SHIFT_SSB::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::PKT_SHIFT_SSB));
			}

			int Menu::PKT_SHIFT_SSB::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 4));
			}


			std::string Menu::RTTY_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::RTTY_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_LCUT_FREQ));
			}

			FreqLowCutValue Menu::RTTY_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5, 2)));
			}

			std::string Menu::RTTY_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::RTTY_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_LCUT_SLOPE));
			}

			SlopeValue Menu::RTTY_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::RTTY_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::RTTY_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_HCUT_FREQ));
			}

			FreqHighCutValue Menu::RTTY_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::RTTY_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::RTTY_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_HCUT_SLOPE));
			}

			SlopeValue Menu::RTTY_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			
			std::string Menu::POLARITY_R::Set(RTTYPolarityValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::POLARITY_R),
					static_cast<int>(value));
			}

			std::string Menu::POLARITY_R::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::POLARITY_R));
			}

			RTTYPolarityValue Menu::POLARITY_R::Answer(std::string data)
			{
				return static_cast<RTTYPolarityValue>(std::stoi(&data[5])); 
			}

			std::string Menu::POLARITY_T::Set(RTTYPolarityValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::POLARITY_T),
					static_cast<int>(value));
			}

			std::string Menu::POLARITY_T::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::POLARITY_T));
			}

			RTTYPolarityValue Menu::POLARITY_T::Answer(std::string data)
			{
				return static_cast<RTTYPolarityValue>(std::stoi(&data[5]));
			}

			std::string Menu::RTTY_OUT::Set(OutValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::RTTY_OUT),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_OUT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_OUT));
			}

			OutValue Menu::RTTY_OUT::Answer(std::string data)
			{
				return static_cast<OutValue>(std::stoi(&data[5]));
			}

			std::string Menu::RTTY_OUT_LEVEL::Set(int value)
			{
				value = value < 0 ? 0 : value;
				value = value > 100 ? 100 : value;
				return fmt::format("EX{:03d}{:03d};",
					static_cast<int>(MenuItem::RTTY_OUT_LEVEL),
					value);
			}

			std::string Menu::RTTY_OUT_LEVEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_OUT_LEVEL));
			}

			int Menu::RTTY_OUT_LEVEL::Answer(std::string data)
			{
				return std::stoi(data.substr(5, 3));
			}

			std::string Menu::RTTY_SHIFT::Set(RTTYShiftFreqValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::RTTY_SHIFT),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_SHIFT::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_SHIFT));
			}

			RTTYShiftFreqValue Menu::RTTY_SHIFT::Answer(std::string data)
			{
				return static_cast<RTTYShiftFreqValue>(std::stoi(&data[5]));
			}

			std::string Menu::RTTY_TONE::Set(RTTYMarkFreq value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::RTTY_TONE),
					static_cast<int>(value));
			}

			std::string Menu::RTTY_TONE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::RTTY_TONE));
			}

			RTTYMarkFreq Menu::RTTY_TONE::Answer(std::string data)
			{
				return static_cast<RTTYMarkFreq>(std::stoi(&data[5]));
			}

			std::string Menu::SSB_LCUT_FREQ::Set(FreqLowCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::SSB_LCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::SSB_LCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_LCUT_FREQ));
			}

			FreqLowCutValue Menu::SSB_LCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqLowCutValue>(std::stoi(data.substr(5, 2)));
			}

			std::string Menu::SSB_LCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SSB_LCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::SSB_LCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_LCUT_SLOPE));
			}

			SlopeValue Menu::SSB_LCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::SSB_HCUT_FREQ::Set(FreqHighCutValue value)
			{
				return fmt::format("EX{:03d}{:02d};",
					static_cast<int>(MenuItem::SSB_HCUT_FREQ),
					static_cast<int>(value));
			}

			std::string Menu::SSB_HCUT_FREQ::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_HCUT_FREQ));
			}

			FreqHighCutValue Menu::SSB_HCUT_FREQ::Answer(std::string data)
			{
				return static_cast<FreqHighCutValue>(std::stoi(data.substr(5, 2))); // return value in 0-99 (OFF, 0.7 - 7kHz, 50 Hz per step)
			}

			std::string Menu::SSB_HCUT_SLOPE::Set(SlopeValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SSB_HCUT_SLOPE),
					static_cast<int>(value));
			}

			std::string Menu::SSB_HCUT_SLOPE::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_HCUT_SLOPE));
			}

			SlopeValue Menu::SSB_HCUT_SLOPE::Answer(std::string data)
			{
				return static_cast<SlopeValue>(std::stoi(&data[5])); // return value in 0-3 (OFF, 6dB/oct, 12dB/oct, 18dB/oct)
			}

			std::string Menu::SSB_MIC_SEL::Set(MicSelectValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SSB_MIC_SELECT),
					static_cast<int>(value));
			}

			std::string Menu::SSB_MIC_SEL::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_MIC_SELECT));
			}

			MicSelectValue Menu::SSB_MIC_SEL::Answer(std::string data)
			{
				return static_cast<MicSelectValue>(std::stoi(&data[5]));
			}
			
			std::string Menu::SSB_TX_BPF::Set(SsbTxBandPathValue value)
			{
				return fmt::format("EX{:03d}{:01d};",
					static_cast<int>(MenuItem::SSB_TX_BPF),
					static_cast<int>(value));
			}

			std::string Menu::SSB_TX_BPF::Read()
			{
				return fmt::format("EX{:03d};", static_cast<int>(MenuItem::SSB_TX_BPF));
			}

			SsbTxBandPathValue Menu::SSB_TX_BPF::Answer(std::string data)
			{
				return static_cast<SsbTxBandPathValue>(std::stoi(&data[5]));
			}


		}
	}
}

