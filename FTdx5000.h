#pragma once
#include "Cat.h"

namespace Yaesu {
	namespace Commands {
		namespace FTdx5000 {

			using Yaesu::Common::OnOffValue;
			using Yaesu::Common::EnableDisableValue;
			using Yaesu::Common::UpDownValue;
			using Yaesu::Common::VoxSelectValue;
			using Yaesu::Common::FreqLowCutValue;
			using Yaesu::Common::FreqHighCutValue;
			using Yaesu::Common::KeyerMemoryChannel;
			using Yaesu::Common::KeyerMemoryType;
			using Yaesu::Common::RTTYPolarityValue;
			using Yaesu::Common::RTTYShiftFreqValue;
			using Yaesu::Common::RTTYMarkFreq;
			using Yaesu::Common::PTTSelectValue;
			using Yaesu::Common::APFWidthValue;
			using Yaesu::Common::IFNotchWidth;
			using Yaesu::Common::MeterHoldType;
			using Yaesu::Common::KeyerDotDashType;
			using Yaesu::Common::KeyerMemoryType;
			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;
			using Yaesu::Common::BaudotCodeStandard;
			using Yaesu::Common::CTCSSTone;
			using Yaesu::Common::NumberStyle;
			using Yaesu::Common::MicScanResumeType;
			using Yaesu::Common::SlopeValue;

			enum class CWAutoMode : int
			{
				OFF,
				M_50,
				ON
			};

			enum class BfoValue : int
			{
				USB,
				LSB,
				AUTO
			};

			enum class CWFrequencyDisplay : int
			{
				DIRECT_FREQ,
				PITCH_OFFSET
			};

			enum class BreakInType : int
			{
				SEMI,
				FULL
			};
		
			enum class CWWaveShape : int
			{
				msec_1,
				msec_2,
				msec_4,
				msec_6
			};

			enum class KeyerType : int
			{
				OFF,
				BUG,
				ELEKEY,
				ACS
			};

			enum class CATRate : int
			{
				bps_4800,
				bps_9600,
				bps_19200,
				bps_38400
			};

			enum class CATTimeoutValue : int
			{
				msec_10,
				msec_100,
				msec_1000,
				msec_3000
			};

			enum class AntennaTunerState : int
			{
				Off,
				On,
				Start
			};

			enum class MainSubBandValue : int
			{
				Main,
				Sub
			};

			enum class EncoderValue : int
			{
				Main_Encoder,
				Sub_Encoder,
				Main_Select,
				Sub_Select
			};
			
			enum class AntennaNumber : int
			{
				ANT_1,
				ANT_2,
				ANT_3,
				ANT_4,
				ANT_RX
			};

			enum class BiasType : int
			{
				ClassA_OnOff,
				Bias_Level
			};

			enum class ContourType : int
			{
				OnOff,
				Frequency
			};

			enum class ContourValue : int
			{
				OFF,
				CONTOUR_ON,
				APF_ON
			};

			enum class CTCSSType : int
			{
				OFF,
				ENC_DEC,
				ENC
			};

			enum class DisplayType : int
			{
				World_Clock,
				Band_Scope,
				AF_Oscilloscope,
				Log_Book,
				Temparature_SWR,
				Rotator,
				Memory_Channel_List
			};

			enum class TFTColor : int
			{
				COOL_BLUE,
				CONTRAST_BLUE,
				FLASH_WHITE,
				CONTRAST_UMBER,
				UMBER
			};

			enum class BarDisplayType : int
			{
				CLAR,
				CW_TUNE
			};

			enum class PeakHoldTime : int
			{
				OFF,
				sec_0_5,
				sec_1,
				sec_2
			};

			enum class RotorStartUpValue : int
			{
				deg_0,
				deg_90,
				deg_180,
				deg_270
			};
			enum class LevelIndicatorType : int
			{
				CW_PITCH,
				CW_SPEED,
				CW_DELAY,
				VOX_DELAY,
				RF_POWER,
				MIC_GAIN,
				PROCE
			};

			enum class IndicatorType : int
			{
				VFD,
				OEL
			};

			enum class SelectValue : int
			{
				PTN1,
				PTN2
			};

			enum class AntSelectType : int
			{
				BAND,
				STACK
			};

			enum class TrackingType : int
			{
				OFF,
				BAND,
				FREQ
			};

			enum class uTuneDialStep : int
			{
				DIAL_STEP_2,
				DIAL_STEP_1,
				OFF
			};

			enum class MicSelectValue : int
			{
				FRONT,
				DATA,
				PC
			};

			enum class QSKDealyValue : int
			{
				msec_15,
				msec_20,
				msec_25,
				msec_30
			};

			enum class DataInValue : int
			{
				DATA,
				PC
			};

			enum class OutValue : int
			{
				VFO_A,
				VFO_B
			};

			enum class CWShapeValue : int
			{
				SOFT,
				SHARP
			};
			enum class CWSlopeValue : int
			{
				STEEP,
				MEDIUM,
				GENTLE
			};

			enum class SsbTxBandPathValue : int
			{
				Hz_50_3000,
				Hz_100_2900,
				Hz_200_2800,
				Hz_300_2700,
				Hz_400_2600,
				Hz_3000
			};

			enum class MenuItem : int
			{
				MAIN_FAST_DELAY = 1,
				MAIN_FAST_HOLD,
				MAIN_MID_DELAY,
				MAIN_MID_HOLD,
				MAIN_SLOW_DELAY,
				MAIN_SLOW_HOLD,
				TFT_COLOR,
				DIMMER_METER,
				DIMMER_VFD,
				DIMMER_OLE,
				DIMMER_E_LCD,
				BAR_DISPLAY_SELECT,
				SUB_MTR_PEAK_HOLD,
				ROTATOR_START_UP,
				ROTATOR_OFFSET_ADJ,
				QMB_MARKER,
				LEVEL_INDICATOR,
				INDICATOR,
				SELECT,
				RX_OUT_LEVEL,
				TX_OUT_LEVEL,
				BEACON_TIME,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				CW_MEMORY_1,
				CW_MEMORY_2,
				CW_MEMORY_3,
				CW_MEMORY_4,
				CW_MEMORY_5,
				ANT_SELECT,
				BEEP_LEVEL,
				CAT_RATE,
				CAT_TIME_OUT_TIMER,
				CAT_RTS,
				CAT_DATA_INDICATOR,
				MEM_GROUP,
				QUICK_SPLIT_FREQ,
				TRACKING,
				TIME_OUT_TIMER,
				TRV_OFFSET_14MHz,
				TRV_OFFSET_28MHz,
				TRV_OFFSET_50MHz,
				uTUNE_DIAL_STEP,
				MIC_SCAN,
				MIC_SCAN_RESUME,
				FREQ_ADJ,
				AM_LCUT_FREQ,
				AM_LCUT_SLOPE,
				AM_HCUT_FREQ,
				AM_HCUT_SLOPE,
				AM_MIC_GAIN,
				AM_MIC_SEL,
				CW_LCUT_FREQ,
				CW_LCUT_SLOPE,
				CW_HCUT_FREQ,
				CW_HCUT_SLOPE,
				F_KEYER_TYPE,
				F_CW_KEYER,
				R_KEYER_TYPE,
				R_CW_KEYER,
				CW_AUTO_MODE,
				CW_BFO,
				CW_BK_IN,
				CW_WAVE_SHAPE,
				CW_WEIGHT,
				CW_FREQ_DISPLAY,
				PC_KEYING,
				QSK,
				DATA_IN_SELECT,
				DATA_TX_GAIN,
				DATA_OUT,
				DATA_OUT_LEVEL,
				DATA_VOX_DELAY,
				DATA_VOX_GAIN,
				FM_LCUT_FREQ,
				FM_LCUT_SLOPE,
				FM_HCUT_FREQ,
				FM_HCUT_SLOPE,
				FM_MIC_GAIN,
				FM_MIC_SEL,
				RPT_SHIFT_28MHz,
				RPT_SHIFT_50MHz,
				PKT_LCUT_FREQ,
				PKT_LCUT_SLOPE,
				PKT_HCUT_FREQ,
				PKT_HCUT_SLOPE,
				PKT_DISP_SSB,
				PKT_SHIFT_SSB,
				RTTY_LCUT_FREQ,
				RTTY_LCUT_SLOPE,
				RTTY_HCUT_FREQ,
				RTTY_HCUT_SLOPE,
				POLARITY_R,
				POLARITY_T,
				RTTY_OUT,
				RTTY_OUT_LEVEL,
				RTTY_SHIFT,
				RTTY_TONE,
				SSB_LCUT_FREQ,
				SSB_LCUT_SLOPE,
				SSB_HCUT_FREQ,
				SSB_HCUT_SLOPE,
				SSB_MIC_SELECT,
				SSB_TX_BPF,
				LSB_RX_CARRIER,
				USB_RX_CARRIER,
				AGC_SLOPE,
				HEADPHONE_MIX,
				IF_OUT,
				MAIN_NB_LEVEL,
				MAIN_NB_WIDTH,
				APF_WIDTH,
				MAIN_CONTOUR_LEVEL,
				MAIN_CONTOUR_WIDTH,
				IF_NOTCH_WIDTH,
				MAIN_CW_SHAPE,
				MAIN_CW_SLOPE,
				MAIN_PSK_SHAPE,
				MAIN_PSK_SLOPE,
				MAIN_RTY_SHAPE,
				MAIN_RTY_SLOPE,
				MAIN_SSB_SHAPE,
				MAIN_SSB_SLOPE,
				SUB_CW_SHAPE,
				SUB_CW_SLOPE,
				SUB_PSK_SHAPE,
				SUB_PSK_SLOPE,
				SUB_RTY_SHAPE,
				SUB_RTY_SLOPE,
				SUB_SSB_SHAPE,
				SUB_SSB_SLOPE,
				FIX_180_METERS,
				FIX_80_METERS,
				FIX_60_METERS,
				FIX_40_METERS,
				FIX_30_METERS,
				FIX_20_METERS,
				FIX_17_METERS,
				FIX_15_METERS,
				FIX_12_METERS,
				FIX_10_METERS,
				FIX_6_METERS,
				DIAL_STEP,
				DIAL_CW_FINE,
				UP_DOWN_STEP,
				AM_CH_STEP,
				FM_CH_STEP,
				AM_DIAL_LOCK,
				FM_DIAL_LOCK,
				FM_DIAL_STEP,
				MY_BAND,
				PRMTRC_EQ1_FREQ,
				PRMTRC_EQ1_LEVEL,
				PRMTRC_EQ1_BWTH,
				PRMTRC_EQ2_FREQ,
				PRMTRC_EQ2_LEVEL,
				PRMTRC_EQ2_BWTH,
				PRMTRC_EQ3_FREQ,
				PRMTRC_EQ3_LEVEL,
				PRMTRC_EQ3_BWTH,
				P_PRMTRC_EQ1_FREQ,
				P_PRMTRC_EQ1_LEVEL,
				P_PRMTRC_EQ1_BWTH,
				P_PRMTRC_EQ2_FREQ,
				P_PRMTRC_EQ2_LEVEL,
				P_PRMTRC_EQ2_BWTH,
				P_PRMTRC_EQ3_FREQ,
				P_PRMTRC_EQ3_LEVEL,
				P_PRMTRC_EQ3_BWTH,		
				FINAL_BIAS,
				TX_MAX_POWER,
				TX_PWR_CONTROL,
				EXT_AMP_TX_GND,
				EXT_AMP_TUNING_PWR,
				VOX_SELECT,
				ANTI_VOX_GAIN,
				EMERGENCY_FREQ_TX
			};


			struct EncoderParam
			{
				EncoderValue encoder;
			
				int steps; // Number of steps to move
			};

			struct CTCSSParam
			{
				MainSubBandValue band;
				CTCSSType type;
			};

			struct ContourParam
			{
				MainSubBandValue band;
				ContourType type;
				union Value
				{
					ContourValue value;
					int frequency; // Frequency in Hz
				} value;
			};

			struct BiasValue
			{
				BiasType type;
				union Value
				{
					OnOffValue onOff; // Class A On/Off
					int level; // Bias Level 0-100
				} value;
			};

			struct AntennaNumberValue
			{
				MainSubBandValue band;
				AntennaNumber antenna;
				OnOffValue rxOnly; // RX Only
			};

			struct AFGainValue
			{
				MainSubBandValue band;
				int value; // 0-255
			};

			struct BandOnOffValue
			{
				MainSubBandValue band;
				OnOffValue value; // On or Off
			};

			struct BusyValue
			{
				OnOffValue mainBand;
				OnOffValue subBand;
			};

			struct CTCSSToneValue
			{
				MainSubBandValue band;
				CTCSSTone tone;
			};

			struct DimmerParam
			{
				int VFD_brightness; // 0-15
				int METER_brightness; // 0-15
				int OLED_brightness; // 0-15
				int ELCD_brightness; // 0-15
			};

			class VFO_A_TO_B
			{
			public:
				static std::string Set( );				
			};

			class ANTENNA_TUNER_CONTROL
			{
			public:
				static std::string Set(AntennaTunerState value);
				static std::string Read();
				static AntennaTunerState Answer(std::string data);
			};

			class AF_GAIN
			{
			public:
				static std::string Set(AFGainValue value);
				static std::string Read(MainSubBandValue value);
				static AFGainValue Answer(std::string data);
			};

			class AUTO_INFORMATION
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class VFO_TO_MEMORY
			{
			public:
				static std::string Set();
			};

			class ANTENNA_NUMBER
			{
			public:
				static std::string Set(MainSubBandValue value, AntennaNumber bvalue);
				static std::string Read(MainSubBandValue value);
				static AntennaNumberValue Answer(std::string data);
			};

			class VFO_B_TO_VFO_A
			{
			public:
				static std::string Set();
			};

			class AUTO_NOTCH
			{
			public:
				static std::string Set(BandOnOffValue value);
				static std::string Read(MainSubBandValue value);
				static BandOnOffValue Answer(std::string data);
			};

			class BAND_DOWN
			{
			public:
				static std::string Set(MainSubBandValue value);
			};

			class BUSY
			{
			public:				
				static std::string Read();
				static BusyValue Answer(std::string data);
			};

			class CLASS_A
			{
			public:
				static std::string Set(BiasValue value);
				static std::string Read(BiasType value);
				static BiasValue Answer(std::string data);
			};

			class CHANNEL_UP_DOWN
			{
			public:
				static std::string Set(UpDownValue value);
			
			};

			class CTCSS_TONE_FREQUENCY
			{
			public:
				static std::string Set(CTCSSToneValue value);
				static std::string Read(MainSubBandValue value);
				static CTCSSToneValue Answer(std::string data);
			};

			class CONTOUR
			{
			public:
				static std::string Set(ContourParam value);
				static std::string Read(MainSubBandValue value, ContourType type);
				static ContourParam Answer(std::string data);
			};

			class CW_SPOT
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class CTCSS
			{
			public:
				static std::string Set(CTCSSParam value);
				static std::string Read(MainSubBandValue value);
				static CTCSSParam Answer(std::string data);
			};

			class DIMMER
			{
			public:
				static std::string Set(DimmerParam value);
				static std::string Read();
				static DimmerParam Answer(std::string data);
			};

			class MIC_DOWN
			{
			public:
				static std::string Set();
			};

			class DISPLAY
			{
			public:
				static std::string Set(DisplayType value);
				static std::string Read();
				static DisplayType Answer(std::string data);
			};

			class DIMMER_SWITCH
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ENCODER_DOWN
			{
			public:
				static std::string Set(EncoderParam value);
			
			};
			class ENCODER_UP
			{
			public:
				static std::string Set(EncoderParam value);

			};

			class Menu
			{
			public:

				class MAIN_FAST_DELAY
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class MAIN_FAST_HOLD
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class MAIN_MID_DELAY
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};
				class MAIN_MID_HOLD
				{
					public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};
				class MAIN_SLOW_DELAY
				{
					public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};
				class MAIN_SLOW_HOLD
				{
					public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class TFT_COLOR
				{
				public:
					static std::string Set(TFTColor value);
					static std::string Read();
					static TFTColor Answer(std::string data);
				};


				class DIMMER_METER
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class DIMMER_VFD
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class DIMMER_OLE
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class DIMMER_E_LCD
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class BAR_DISPLAY_SELECT
				{
				public:
					static std::string Set(BarDisplayType value);
					static std::string Read();
					static BarDisplayType Answer(std::string data);
				};


				class SUB_MTR_PEAK_HOLD
				{
				public:
					static std::string Set(PeakHoldTime value);
					static std::string Read();
					static PeakHoldTime Answer(std::string data);
				};

				class ROTATOR_START_UP
				{
				public:
					static std::string Set(RotorStartUpValue value);
					static std::string Read();
					static RotorStartUpValue Answer(std::string data);
				};


				class ROTATOR_OFFSET_ADJ
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class QMB_MARKER
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};


				class LEVEL_INDICATOR
				{
				public:
					static std::string Set(LevelIndicatorType value);
					static std::string Read();
					static LevelIndicatorType Answer(std::string data);
				};


				class INDICATOR
				{
				public:
					static std::string Set(IndicatorType value);
					static std::string Read();
					static IndicatorType Answer(std::string data);
				};

				class SELECT
				{
				public:
					static std::string Set(SelectValue value);
					static std::string Read();
					static SelectValue Answer(std::string data);
				};

				class RX_OUT_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class TX_OUT_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class BEACON_TIME
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class NUMBER_STYLE
				{
				public:		
					static std::string Set(NumberStyle value);
					static std::string Read();
					static NumberStyle Answer(std::string data);
				};

				class CONTEST_NUMBER
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class CW_MEMORY_1
				{
				public:
					static std::string Set(KeyerMemoryType value);
					static std::string Read();
					static KeyerMemoryType Answer(std::string data);
				};

				class CW_MEMORY_2
				{
				public:
					static std::string Set(KeyerMemoryType value);
					static std::string Read();
					static KeyerMemoryType Answer(std::string data);
				};

				class CW_MEMORY_3
				{
				public:
					static std::string Set(KeyerMemoryType value);
					static std::string Read();
					static KeyerMemoryType Answer(std::string data);
				};

				class CW_MEMORY_4
				{
				public:
					static std::string Set(KeyerMemoryType value);
					static std::string Read();
					static KeyerMemoryType Answer(std::string data);
				};

				class CW_MEMORY_5
				{
				public:
					static std::string Set(KeyerMemoryType value);
					static std::string Read();
					static KeyerMemoryType Answer(std::string data);
				};


				class ANT_SELECT
				{
				public:
					static std::string Set(AntSelectType value);
					static std::string Read();
					static AntSelectType Answer(std::string data);
				};


				class BEEP_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class CAT_RATE
				{
				public:
					static std::string Set(CATRate value);
					static std::string Read();
					static CATRate Answer(std::string data);
				};


				class CAT_TIME_OUT_TIMER
				{
				public:
					static std::string Set(CATTimeoutValue value);
					static std::string Read();
					static CATTimeoutValue Answer(std::string data);
				};


				class CAT_RTS
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};

				class CAT_DATA_INDICATOR
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};


				class MEM_GROUP
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};


				class QUICK_SPLIT_FREQ
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class TRACKING
				{
				public:
					static std::string Set(TrackingType value);
					static std::string Read();
					static TrackingType Answer(std::string data);
				};


				class TIME_OUT_TIMER
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class TRV_OFFSET_14MHz
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class TRV_OFFSET_28MHz
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class TRV_OFFSET_50MHz
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class uTUNE_DIAL_STEP
				{
				public:
					static std::string Set(uTuneDialStep value);
					static std::string Read();
					static uTuneDialStep Answer(std::string data);
				};


				class MIC_SCAN
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};


				class MIC_SCAN_RESUME
				{
				public:
					static std::string Set(MicScanResumeType value);
					static std::string Read();
					static MicScanResumeType Answer(std::string data);
				};


				class FREQ_ADJ
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};



				class AM_LCUT_FREQ
				{
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};
				

				class AM_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class AM_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class AM_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};
				


				class AM_MIC_GAIN
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class AM_MIC_SEL
				{
				public:
					static std::string Set(MicSelectValue value);
					static std::string Read();
					static MicSelectValue Answer(std::string data);
				};

				class CW_LCUT_FREQ
				{
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};


				class CW_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class CW_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class CW_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class F_KEYER_TYPE
				{
				public:
					static std::string Set(KeyerType value);
					static std::string Read();
					static KeyerType Answer(std::string data);
				};


				class F_CW_KEYER
				{
				public:
					static std::string Set(KeyerDotDashType value);
					static std::string Read();
					static KeyerDotDashType Answer(std::string data);
				};


				class R_KEYER_TYPE
				{
				public:
					static std::string Set(KeyerType value);
					static std::string Read();
					static KeyerType Answer(std::string data);
				};

				class R_CW_KEYER
				{
				public:
					static std::string Set(KeyerDotDashType value);
					static std::string Read();
					static KeyerDotDashType Answer(std::string data);
				};
				

				class CW_AUTO_MODE
				{
				public:
					static std::string Set(CWAutoMode value);
					static std::string Read();
					static CWAutoMode Answer(std::string data);
				};


				class CW_BFO
				{
				public:
					static std::string Set(BfoValue value);
					static std::string Read();
					static BfoValue Answer(std::string data);
				};


				class CW_BK_IN
				{
				public:
					static std::string Set(BreakInType value);
					static std::string Read();
					static BreakInType Answer(std::string data);
				};


				class CW_WAVE_SHAPE
				{
				public:
					static std::string Set(CWWaveShape value);
					static std::string Read();
					static CWWaveShape Answer(std::string data);
				};


				class CW_WEIGHT
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class CW_FREQ_DISPLAY
				{
				public:
					static std::string Set(CWFrequencyDisplay value);
					static std::string Read();
					static CWFrequencyDisplay Answer(std::string data);
				};

				class PC_KEYING
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};


				class QSK
				{
				public:
					static std::string Set(QSKDealyValue value);
					static std::string Read();
					static QSKDealyValue Answer(std::string data);
				};


				class DATA_IN_SELECT
				{
				public:
					static std::string Set(DataInValue value);
					static std::string Read();
					static DataInValue Answer(std::string data);
				};


				class DATA_TX_GAIN
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class DATA_OUT
				{
				public:
					static std::string Set(OutValue value);
					static std::string Read();
					static OutValue Answer(std::string data);
				};


				class DATA_OUT_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class DATA_VOX_DELAY
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class DATA_VOX_GAIN
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class FM_LCUT_FREQ
				{	
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};


				class FM_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class FM_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class FM_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class FM_MIC_GAIN
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class FM_MIC_SEL
				{
				public:
					static std::string Set(MicSelectValue value);
					static std::string Read();
					static MicSelectValue Answer(std::string data);
				};


				class RPT_SHIFT_28MHz
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class RPT_SHIFT_50MHz
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class PKT_LCUT_FREQ
				{
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};


				class PKT_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class PKT_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class PKT_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class PKT_DISP_SSB
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class PKT_SHIFT_SSB
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class RTTY_LCUT_FREQ
				{
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};


				class RTTY_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class RTTY_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class RTTY_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class POLARITY_R
				{
				public:
					static std::string Set(RTTYPolarityValue value);
					static std::string Read();
					static RTTYPolarityValue Answer(std::string data);
				};

				class POLARITY_T
				{
				public:
					static std::string Set(RTTYPolarityValue value);
					static std::string Read();
					static RTTYPolarityValue Answer(std::string data);
				};


				class RTTY_OUT
				{
				public:
					static std::string Set(OutValue value);
					static std::string Read();
					static OutValue Answer(std::string data);
				};


				class RTTY_OUT_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class RTTY_SHIFT
				{
				public:
					static std::string Set(RTTYShiftFreqValue value);
					static std::string Read();
					static RTTYShiftFreqValue Answer(std::string data);
				};
				

				class RTTY_TONE
				{
				public:
					static std::string Set(RTTYMarkFreq value);
					static std::string Read();
					static RTTYMarkFreq Answer(std::string data);
				};


				class SSB_LCUT_FREQ
				{
				public:
					static std::string Set(FreqLowCutValue value);
					static std::string Read();
					static FreqLowCutValue Answer(std::string data);
				};


				class SSB_LCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};


				class SSB_HCUT_FREQ
				{
				public:
					static std::string Set(FreqHighCutValue value);
					static std::string Read();
					static FreqHighCutValue Answer(std::string data);
				};


				class SSB_HCUT_SLOPE
				{
				public:
					static std::string Set(SlopeValue value);
					static std::string Read();
					static SlopeValue Answer(std::string data);
				};

				class SSB_MIC_SEL
				{
				public:
					static std::string Set(MicSelectValue value);
					static std::string Read();
					static MicSelectValue Answer(std::string data);
				};


				class SSB_TX_BPF
				{
				public:
					static std::string Set(SsbTxBandPathValue value);
					static std::string Read();
					static SsbTxBandPathValue Answer(std::string data);
				};

			};			
		}
	}
}
