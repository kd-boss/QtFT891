#ifndef CAT_H
#define CAT_H
#include <string>
#include <exception>
#include <stdexcept>
#include <type_traits>


namespace Yaesu
{
	enum class RigType : int
	{
		FT450D = 244, //
		FTDX5000 = 362, 
		FTDX3000 = 462,
		FTDX1200_FFT = 582,
		FTDX1200 = 583,
		FT891 = 650, //
		FT991A = 670, //
		FTDX101D = 681, //
		FTDX101MP = 682, //
		FTDX10 = 761, //
		FT710 = 800 //
	};

	class IDENTIFICATION
	{
	public:
		static std::string Read();
		static Yaesu::RigType Answer(std::string data);
	};

	namespace Common {

		enum class SlopeValue : int	{_6db, _18db };
		enum class NumberStyle : int {_1290, AUNO, AUNT,A2NO, A2NT,_12NO, _12NT };
		enum class MicScanResumeType : int { PAUSE, TIME };
		enum class OnOffValue { OFF, ON };
		enum class EnableDisableValue { DISABLE, ENABLE };
		enum class UpDownValue : int { UP, DOWN };
		enum class VoxSelectValue : int { MIC, DATA };
		enum class FreqLowCutValue : int {
			OFF, _100hz, _150hz, _200hz, _250hz, _300hz, _350hz, _400hz, _450hz, _500hz,
			_550hz, _600hz, _650hz, _700hz, _750hz, _800hz, _850hz, _900hz, _950hz, _1000hz,
		};
		enum class FreqHighCutValue : int {
			OFF, _700hz, _750hz, _800hz, _850hz, _900hz, _950hz, _1000hz, _1050hz, _1100hz, _1150hz,
			_2000hz, _2050hz, _2100hz, _2150hz, _2200hz, _2250hz, _2300hz, _2350hz, _2400hz, _2450hz,
			_2500hz, _2550hz, _2600hz, _2650hz, _2700hz, _2750hz, _2800hz, _2850hz, _2900hz, _2950hz,
			_3000hz, _3050hz, _3100hz, _3150hz, _3200hz, _3250hz, _3300hz, _3350hz, _3400hz, _3450hz,
			_3500hz, _3550hz, _3600hz, _3650hz, _3700hz, _3750hz, _3800hz, _3850hz, _3900hz, _3950hz, _4000hz
		};
		enum class KeyerMemoryChannel {
			Memory1 = 1, Memory2, Memory3, Memory4, Memory5,
			Message1, Message2, Message3, Message4, Message5
		};
		enum class RTTYPolarityValue : int { NORMAL, REVERSE };
		enum class RTTYShiftFreqValue : int { _170hz, _200hz, _425hz, _850hz };
		enum class RTTYMarkFreq : int { _1275hz, _2125hz };
		enum class PTTSelectValue : int { DAKY, RTS, DTR };
		enum class APFWidthValue : int { NARROW, MEDIUM, WIDE };
		enum class IFNotchWidth : int { NARROW, WIDE };
		enum class MeterHoldType : int { OFF, _0_5s, _1s, _2s };
		enum class KeyerType : int { OFF, BUG, ELEKEY_A, ELEKEY_B, ELEKEY_Y, ACS };
		enum class KeyerDotDashType : int { NORMAL, REVERSED };
		enum class KeyerMemoryType : int { TEXT, MESSAGE };
		enum class EQ1FreqValue : int {
			OFF, _100Hz, _200Hz, _300Hz, _400Hz, _500Hz, _600Hz, _700Hz
		};
		enum class EQ2FreqValue : int {
			OFF, _700Hz, _800Hz, _900Hz, _1000Hz, _1100Hz, _1200Hz, _1300Hz, _1400Hz, _1500Hz
		};
		enum class EQ3FreqValue : int {
			OFF, _1500Hz, _1600Hz, _1700Hz, _1800Hz, _1900Hz, _2000Hz, _2100Hz, _2200Hz, _2300Hz,
			_2400Hz, _2500Hz, _2600Hz, _2700Hz, _2800Hz, _2900Hz, _3000Hz, _3100Hz, _3200Hz
		};
		enum class BaudotCodeStandard : int {
			CCITT, US
		};
		enum class CTCSSTone : int
		{
			Tone_67_0,
			Tone_69_3,
			Tone_71_9,
			Tone_74_4,
			Tone_77_0,
			Tone_79_7,
			Tone_82_5,
			Tone_85_4,
			Tone_88_5,
			Tone_91_5,
			Tone_94_8,
			Tone_97_4,
			Tone_100_0,
			Tone_103_5,
			Tone_107_2,
			Tone_110_9,
			Tone_114_8,
			Tone_118_8,
			Tone_123_0,
			Tone_127_3,
			Tone_131_8,
			Tone_136_5,
			Tone_141_3,
			Tone_146_2,
			Tone_151_4,
			Tone_156_7,
			Tone_159_8,
			Tone_162_2,
			Tone_165_5,
			Tone_167_9,
			Tone_171_3,
			Tone_173_8,
			Tone_177_3,
			Tone_179_9,
			Tone_183_5,
			Tone_186_2,
			Tone_189_9,
			Tone_192_8,
			Tone_196_6,
			Tone_199_5,
			Tone_203_5,
			Tone_206_5,
			Tone_210_7,
			Tone_218_1,
			Tone_225_7,
			Tone_229_1,
			Tone_233_6,
			Tone_241_8,
			Tone_250_3,
			Tone_254_1
		};
	};

	namespace Commands
	{	
		namespace FT450D
		{
			using Yaesu::Common::EnableDisableValue;
			using Yaesu::Common::RTTYShiftFreqValue;
			using Yaesu::Common::RTTYPolarityValue;
			using Yaesu::Common::RTTYMarkFreq;
			using Yaesu::Common::CTCSSTone;
			using Yaesu::Common::OnOffValue;

			enum class AntennaTunerValue : int
			{
				OFF,
				ON,
				Start
			};

			
			enum class VFOValue : int
			{
				VFO_A,
				VFO_B
			};

			enum class BEEPFrequencyValue : int
			{
				_440hz,
				_880hz,
				_1760hz
			};

			enum class MenuFunction : int
			{
				EXT_MENU = 1,
				AM_FM_DIAL,
				APO_TIME,
				BEACON_TIME,
				BEACON_TEXT,
				BEEP_TONE,
				BEEP_VOLUME,
				CAT_RTS,
				CAT_TIME_OUT_TIME,
				CAT_RATE,
				CLAR_DIAL_SELECT,
				CLOCK_SHIFT,
				DISP_CONTRAST,
				CW_AUTO_MODE,
				CW_BFO,
				CW_DELAY,
				CW_KEY_REVERSE,
				CW_QSK,
				CW_PADDLE,
				CW_PITCH,
				CW_SPEED,
				CW_SIDE_TONE,
				CW_TRAINING,
				CW_WEIGHT,
				DATA_DISP,
				DATA_MODE,
				DIAL_STEP = 29,
				DIG_VOX,
				EMERGENCY,
				KEY_HOLD_TIME,
				LOCK_MODE,
				M_TUNE,
				MEMORY_GROUP,
				MEMORY_TAG,
				MIC_EQ,
				MIC_GAIN,
				MIC_AUTO_SCAN,
				MY_BAND,
				MY_MODE,
				MIC_DOWN_PG,
				MIC_FAST_PG,
				MIC_UP_PG,
				METER_PEAK_HOLD,
				PANNEL_CUSTOM_SWITCH,
				QUICK_SPLIT_FREQ,
				RF_POWER_SET,
				REPEATER_SHIFT_DIRECTION,
				REPEATER_SHIFT_OFFSET,
				RTTY_SHIFT,
				RTTY_TONE,
				RTTY_RX_POLARITY,
				RTTY_TX_POLARITY,
				SCAN_RESUME,
				SEL_DIAL_MODE,
				SQL_TYPE,
				SQL_RF_GAIN,
				STBY_BEEP,
				TONE_FREQ,
				TOT_TIME,
				TUNER_ATAS,
				VOX_DELAY,
				VOX_GAIN
			};

			enum class ClarDialValue : int
			{
				DIAL,
				SEL
			};

			enum class BFOValue : int
			{
				USB,
				LSB,
				AUTO
			};

			enum class ReverseValue : int
			{
				NORMAL,
				REVERSE
			};

			enum class DataModeValue
			{
				RTTY,
				USER_L,
				USER_U
			};

			enum class DialStepValue : int
			{
				Hz_1,
				Hz_10,
				Hz_20,
				Hz_100,
				Hz_200
			};

			enum class RepeaterShiftDirection : int
			{
				SIMPLEX,
				PLUS_SHIFT,
				MINUS_SHIFT
			};
			
			enum class DialType : int
			{
				CW_SidetoneLevel,
				CW_KeyerSpeed,
				KHz_100_Step,
				Mhz_1_Step,
				MIC_GAIN,
				RF_Power
			};

			enum class SqlTypeValue : int
			{
				OFF,
				ENC,
				ENC_DEC
			};

			enum class SqlRfGainFunction : int
			{
				SQL,
				RF_GAIN
			};

			enum class TunerType : int
			{
				ATAS,
				EXT_ATU,
				INT_ATU,
				INTRASTU,
				F_TRANS
			};

			enum class MyBandValue : int
			{
				meters_160_OFF,
				meters_160_ON,
				meters_80_OFF = 10,
				meters_80_ON,
				meters_40_OFF = 30,
				meters_40_ON,
				meters_30_OFF = 40,
				meters_30_ON,
				meters_20_OFF = 50,
				meters_20_ON,
				meters_17_OFF = 60,
				meters_17_ON,
				meters_15_OFF = 70,
				meters_15_ON,
				meters_12_OFF = 80,
				meters_12_ON,
				meters_10_OFF = 90,
				meters_10_ON,
				meters_6_OFF = 100,
				meters_6_ON
			};

			enum class MyBandModeValue : int
			{
				LSB_OFF = 10,
				LSB_ON,
				USB_OFF = 20,
				USB_ON,
				CW_OFF = 30,
				CW_ON,
				FM_OFF = 40,
				FM_ON,
				AM_OFF = 50,
				AM_ON,
				DATA_RTTY_LSB_OFF = 60,
				DATA_RTTY_LSB_ON,
				CW_R_OFF = 70,
				CW_R_ON,
				USER_L_OFF = 80,
				USER_L_ON,
				NA_OFF = 100,
				NA,
				FM_N_OFF = 200,
				FM_N_ON,
				USER_U_OFF = 300,
				USER_U_ON
			};

			enum class ButtonFunction : int
			{
				MONI,
				N_A,
				PB,
				PLAY1,
				PLAY2,
				PLAY3,
				QSPL,
				SPOT,
				SQL_OFF,
				SWR,
				TXW,
				VCC,
				VOICE2,
				VM1MONI,
				VM1REC,
				VM1TX,
				VM2MONI,
				VM2REC,
				VM2TX,
				DOWN,
				VAST,
				UP,
				DSP,
				IPO_ATT,
				NV,
				AGC,
				MODEDN,
				MODEUP,
				DSP_SEL,
				KEYER,
				CLAR,
				BANDDN,
				BANDUP,
				A_eqauals_B,
				A_B_Swap,
				LOCK,
				TUNE,
				VOICE,
				MW,
				V_M_Toggle,
				HOME,
				RCL,
				VOX,
				STO,
				STEP,
				SPLIT,
				PMS,
				SCAN,
				MENU,
				DIMMER,
				MTR
			};

			enum class BeepVolumeValue : int
			{
				FIX_0,
				FIX_1,
				FIX_2,
				FIX_3,
				FIX_4,
				FIX_5,
				FIX_6,
				FIX_7,
				FIX_8,
				FIX_9,
				FIX_10,
				FIX_11,
				FIX_12,
				FIX_13,
				FIX_14,
				FIX_15,
				FIX_16,
				FIX_17,
				FIX_18,
				FIX_19,
				FIX_20,
				FIX_21,
				FIX_22,
				FIX_23,
				FIX_24,
				FIX_25,
				FIX_26,
				FIX_27,
				FIX_28,
				FIX_29,
				FIX_30,
				FIX_31,
				FIX_32,
				FIX_33,
				FIX_34,
				FIX_35,
				FIX_36,
				FIX_37,
				FIX_38,
				FIX_39,
				FIX_40,
				FIX_41,
				FIX_42,
				FIX_43,
				FIX_44,
				FIX_45,
				FIX_46,
				FIX_47,
				FIX_48,
				FIX_49,
				FIX_50,
				FIX_51,
				FIX_52,
				FIX_53,
				FIX_54,
				FIX_55,
				FIX_56,
				FIX_57,
				FIX_58,
				FIX_59,
				FIX_60,
				FIX_61,
				FIX_62,
				FIX_63,
				FIX_64,
				FIX_65,
				FIX_66,
				FIX_67,
				FIX_68,
				FIX_69,
				FIX_70,
				FIX_71,
				FIX_72,
				FIX_73,
				FIX_74,
				FIX_75,
				FIX_76,
				FIX_77,
				FIX_78,
				FIX_79,
				FIX_80,
				FIX_81,
				FIX_82,
				FIX_83,
				FIX_84,
				FIX_85,
				FIX_86,
				FIX_87,
				FIX_88,
				FIX_89,
				FIX_90,
				FIX_91,
				FIX_92,
				FIX_93,
				FIX_94,
				FIX_95,
				FIX_96,
				FIX_97,
				FIX_98,
				FIX_99,
				FIX_100,
				LNK_Neg50,
				LNK_Neg49,
				LNK_Neg48,
				LNK_Neg47,
				LNK_Neg46,
				LNK_Neg45,
				LNK_Neg44,
				LNK_Neg43,
				LNK_Neg42,
				LNK_Neg41,
				LNK_Neg40,
				LNK_Neg39,
				LNK_Neg38,
				LNK_Neg37,
				LNK_Neg36,
				LNK_Neg35,
				LNK_Neg34,
				LNK_Neg33,
				LNK_Neg32,
				LNK_Neg31,
				LNK_Neg30,
				LNK_Neg29,
				LNK_Neg28,
				LNK_Neg27,
				LNK_Neg26,
				LNK_Neg25,
				LNK_Neg24,
				LNK_Neg23,
				LNK_Neg22,
				LNK_Neg21,
				LNK_Neg20,
				LNK_Neg19,
				LNK_Neg18,
				LNK_Neg17,
				LNK_Neg16,
				LNK_Neg15,
				LNK_Neg14,
				LNK_Neg13,
				LNK_Neg12,
				LNK_Neg11,
				LNK_Neg10,
				LNK_Neg9,
				LNK_Neg8,
				LNK_Neg7,
				LNK_Neg6,
				LNK_Neg5,
				LNK_Neg4,
				LNK_Neg3,
				LNK_Neg2,
				LNK_Neg1,
				LNK_0,
				LNK_1,
				LNK_2,
				LNK_3,
				LNK_4,
				LNK_5,
				LNK_6,
				LNK_7,
				LNK_8,
				LNK_9,
				LNK_10,
				LNK_11,
				LNK_12,
				LNK_13,
				LNK_14,
				LNK_15,
				LNK_16,
				LNK_17,
				LNK_18,
				LNK_19,
				LNK_20,
				LNK_21,
				LNK_22,
				LNK_23,
				LNK_24,
				LNK_25,
				LNK_26,
				LNK_27,
				LNK_28,
				LNK_29,
				LNK_30,
				LNK_31,
				LNK_32,
				LNK_33,
				LNK_34,
				LNK_35,
				LNK_36,
				LNK_37,
				LNK_38,
				LNK_39,
				LNK_40,
				LNK_41,
				LNK_42,
				LNK_43,
				LNK_44,
				LNK_45,
				LNK_46,
				LNK_47,
				LNK_48,
				LNK_49,
				LNK_50
			};

			enum class SideToneVolumeValue : int
			{
				FIX_0,
				FIX_1,
				FIX_2,
				FIX_3,
				FIX_4,
				FIX_5,
				FIX_6,
				FIX_7,
				FIX_8,
				FIX_9,
				FIX_10,
				FIX_11,
				FIX_12,
				FIX_13,
				FIX_14,
				FIX_15,
				FIX_16,
				FIX_17,
				FIX_18,
				FIX_19,
				FIX_20,
				FIX_21,
				FIX_22,
				FIX_23,
				FIX_24,
				FIX_25,
				FIX_26,
				FIX_27,
				FIX_28,
				FIX_29,
				FIX_30,
				FIX_31,
				FIX_32,
				FIX_33,
				FIX_34,
				FIX_35,
				FIX_36,
				FIX_37,
				FIX_38,
				FIX_39,
				FIX_40,
				FIX_41,
				FIX_42,
				FIX_43,
				FIX_44,
				FIX_45,
				FIX_46,
				FIX_47,
				FIX_48,
				FIX_49,
				FIX_50,
				FIX_51,
				FIX_52,
				FIX_53,
				FIX_54,
				FIX_55,
				FIX_56,
				FIX_57,
				FIX_58,
				FIX_59,
				FIX_60,
				FIX_61,
				FIX_62,
				FIX_63,
				FIX_64,
				FIX_65,
				FIX_66,
				FIX_67,
				FIX_68,
				FIX_69,
				FIX_70,
				FIX_71,
				FIX_72,
				FIX_73,
				FIX_74,
				FIX_75,
				FIX_76,
				FIX_77,
				FIX_78,
				FIX_79,
				FIX_80,
				FIX_81,
				FIX_82,
				FIX_83,
				FIX_84,
				FIX_85,
				FIX_86,
				FIX_87,
				FIX_88,
				FIX_89,
				FIX_90,
				FIX_91,
				FIX_92,
				FIX_93,
				FIX_94,
				FIX_95,
				FIX_96,
				FIX_97,
				FIX_98,
				FIX_99,
				FIX_100,
				LNK_Neg50,
				LNK_Neg49,
				LNK_Neg48,
				LNK_Neg47,
				LNK_Neg46,
				LNK_Neg45,
				LNK_Neg44,
				LNK_Neg43,
				LNK_Neg42,
				LNK_Neg41,
				LNK_Neg40,
				LNK_Neg39,
				LNK_Neg38,
				LNK_Neg37,
				LNK_Neg36,
				LNK_Neg35,
				LNK_Neg34,
				LNK_Neg33,
				LNK_Neg32,
				LNK_Neg31,
				LNK_Neg30,
				LNK_Neg29,
				LNK_Neg28,
				LNK_Neg27,
				LNK_Neg26,
				LNK_Neg25,
				LNK_Neg24,
				LNK_Neg23,
				LNK_Neg22,
				LNK_Neg21,
				LNK_Neg20,
				LNK_Neg19,
				LNK_Neg18,
				LNK_Neg17,
				LNK_Neg16,
				LNK_Neg15,
				LNK_Neg14,
				LNK_Neg13,
				LNK_Neg12,
				LNK_Neg11,
				LNK_Neg10,
				LNK_Neg9,
				LNK_Neg8,
				LNK_Neg7,
				LNK_Neg6,
				LNK_Neg5,
				LNK_Neg4,
				LNK_Neg3,
				LNK_Neg2,
				LNK_Neg1,
				LNK_0,
				LNK_1,
				LNK_2,
				LNK_3,
				LNK_4,
				LNK_5,
				LNK_6,
				LNK_7,
				LNK_8,
				LNK_9,
				LNK_10,
				LNK_11,
				LNK_12,
				LNK_13,
				LNK_14,
				LNK_15,
				LNK_16,
				LNK_17,
				LNK_18,
				LNK_19,
				LNK_20,
				LNK_21,
				LNK_22,
				LNK_23,
				LNK_24,
				LNK_25,
				LNK_26,
				LNK_27,
				LNK_28,
				LNK_29,
				LNK_30,
				LNK_31,
				LNK_32,
				LNK_33,
				LNK_34,
				LNK_35,
				LNK_36,
				LNK_37,
				LNK_38,
				LNK_39,
				LNK_40,
				LNK_41,
				LNK_42,
				LNK_43,
				LNK_44,
				LNK_45,
				LNK_46,
				LNK_47,
				LNK_48,
				LNK_49,
				LNK_50
			};

			enum class CATTimeOutValue : int
			{
				_10ms,
				_100ms,
				_1000ms,
				_3000ms
			};

			enum class CATRateValue : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps,
				DATA
			};

			enum class CWQskRateValue : int
			{
				ms_15,
				ms_20,
				ms_25,
				ms_30
			};

			enum class KeyerInputValue : int
			{
				Key,
				Microphone
			};

			enum class CWPitchValue : int
			{

				Hz_400,
				Hz_500,
				Hz_600,
				Hz_700,
				Hz_800,

			};

			enum class CWTrainingValue : int
			{
				Numeric,
				Alphabetic,
				Mixed
			};

			enum class DataDisplayValue : int
			{
				Hz_Neg_300,
				Hz_Neg_299,
				Hz_Neg_298,
				Hz_Neg_297,
				Hz_Neg_296,
				Hz_Neg_295,
				Hz_Neg_294,
				Hz_Neg_293,
				Hz_Neg_292,
				Hz_Neg_291,
				Hz_Neg_290,
				Hz_Neg_289,
				Hz_Neg_288,
				Hz_Neg_287,
				Hz_Neg_286,
				Hz_Neg_285,
				Hz_Neg_284,
				Hz_Neg_283,
				Hz_Neg_282,
				Hz_Neg_281,
				Hz_Neg_280,
				Hz_Neg_279,
				Hz_Neg_278,
				Hz_Neg_277,
				Hz_Neg_276,
				Hz_Neg_275,
				Hz_Neg_274,
				Hz_Neg_273,
				Hz_Neg_272,
				Hz_Neg_271,
				Hz_Neg_270,
				Hz_Neg_269,
				Hz_Neg_268,
				Hz_Neg_267,
				Hz_Neg_266,
				Hz_Neg_265,
				Hz_Neg_264,
				Hz_Neg_263,
				Hz_Neg_262,
				Hz_Neg_261,
				Hz_Neg_260,
				Hz_Neg_259,
				Hz_Neg_258,
				Hz_Neg_257,
				Hz_Neg_256,
				Hz_Neg_255,
				Hz_Neg_254,
				Hz_Neg_253,
				Hz_Neg_252,
				Hz_Neg_251,
				Hz_Neg_250,
				Hz_Neg_249,
				Hz_Neg_248,
				Hz_Neg_247,
				Hz_Neg_246,
				Hz_Neg_245,
				Hz_Neg_244,
				Hz_Neg_243,
				Hz_Neg_242,
				Hz_Neg_241,
				Hz_Neg_240,
				Hz_Neg_239,
				Hz_Neg_238,
				Hz_Neg_237,
				Hz_Neg_236,
				Hz_Neg_235,
				Hz_Neg_234,
				Hz_Neg_233,
				Hz_Neg_232,
				Hz_Neg_231,
				Hz_Neg_230,
				Hz_Neg_229,
				Hz_Neg_228,
				Hz_Neg_227,
				Hz_Neg_226,
				Hz_Neg_225,
				Hz_Neg_224,
				Hz_Neg_223,
				Hz_Neg_222,
				Hz_Neg_221,
				Hz_Neg_220,
				Hz_Neg_219,
				Hz_Neg_218,
				Hz_Neg_217,
				Hz_Neg_216,
				Hz_Neg_215,
				Hz_Neg_214,
				Hz_Neg_213,
				Hz_Neg_212,
				Hz_Neg_211,
				Hz_Neg_210,
				Hz_Neg_209,
				Hz_Neg_208,
				Hz_Neg_207,
				Hz_Neg_206,
				Hz_Neg_205,
				Hz_Neg_204,
				Hz_Neg_203,
				Hz_Neg_202,
				Hz_Neg_201,
				Hz_Neg_200,
				Hz_Neg_199,
				Hz_Neg_198,
				Hz_Neg_197,
				Hz_Neg_196,
				Hz_Neg_195,
				Hz_Neg_194,
				Hz_Neg_193,
				Hz_Neg_192,
				Hz_Neg_191,
				Hz_Neg_190,
				Hz_Neg_189,
				Hz_Neg_188,
				Hz_Neg_187,
				Hz_Neg_186,
				Hz_Neg_185,
				Hz_Neg_184,
				Hz_Neg_183,
				Hz_Neg_182,
				Hz_Neg_181,
				Hz_Neg_180,
				Hz_Neg_179,
				Hz_Neg_178,
				Hz_Neg_177,
				Hz_Neg_176,
				Hz_Neg_175,
				Hz_Neg_174,
				Hz_Neg_173,
				Hz_Neg_172,
				Hz_Neg_171,
				Hz_Neg_170,
				Hz_Neg_169,
				Hz_Neg_168,
				Hz_Neg_167,
				Hz_Neg_166,
				Hz_Neg_165,
				Hz_Neg_164,
				Hz_Neg_163,
				Hz_Neg_162,
				Hz_Neg_161,
				Hz_Neg_160,
				Hz_Neg_159,
				Hz_Neg_158,
				Hz_Neg_157,
				Hz_Neg_156,
				Hz_Neg_155,
				Hz_Neg_154,
				Hz_Neg_153,
				Hz_Neg_152,
				Hz_Neg_151,
				Hz_Neg_150,
				Hz_Neg_149,
				Hz_Neg_148,
				Hz_Neg_147,
				Hz_Neg_146,
				Hz_Neg_145,
				Hz_Neg_144,
				Hz_Neg_143,
				Hz_Neg_142,
				Hz_Neg_141,
				Hz_Neg_140,
				Hz_Neg_139,
				Hz_Neg_138,
				Hz_Neg_137,
				Hz_Neg_136,
				Hz_Neg_135,
				Hz_Neg_134,
				Hz_Neg_133,
				Hz_Neg_132,
				Hz_Neg_131,
				Hz_Neg_130,
				Hz_Neg_129,
				Hz_Neg_128,
				Hz_Neg_127,
				Hz_Neg_126,
				Hz_Neg_125,
				Hz_Neg_124,
				Hz_Neg_123,
				Hz_Neg_122,
				Hz_Neg_121,
				Hz_Neg_120,
				Hz_Neg_119,
				Hz_Neg_118,
				Hz_Neg_117,
				Hz_Neg_116,
				Hz_Neg_115,
				Hz_Neg_114,
				Hz_Neg_113,
				Hz_Neg_112,
				Hz_Neg_111,
				Hz_Neg_110,
				Hz_Neg_109,
				Hz_Neg_108,
				Hz_Neg_107,
				Hz_Neg_106,
				Hz_Neg_105,
				Hz_Neg_104,
				Hz_Neg_103,
				Hz_Neg_102,
				Hz_Neg_101,
				Hz_Neg_100,
				Hz_Neg_99,
				Hz_Neg_98,
				Hz_Neg_97,
				Hz_Neg_96,
				Hz_Neg_95,
				Hz_Neg_94,
				Hz_Neg_93,
				Hz_Neg_92,
				Hz_Neg_91,
				Hz_Neg_90,
				Hz_Neg_89,
				Hz_Neg_88,
				Hz_Neg_87,
				Hz_Neg_86,
				Hz_Neg_85,
				Hz_Neg_84,
				Hz_Neg_83,
				Hz_Neg_82,
				Hz_Neg_81,
				Hz_Neg_80,
				Hz_Neg_79,
				Hz_Neg_78,
				Hz_Neg_77,
				Hz_Neg_76,
				Hz_Neg_75,
				Hz_Neg_74,
				Hz_Neg_73,
				Hz_Neg_72,
				Hz_Neg_71,
				Hz_Neg_70,
				Hz_Neg_69,
				Hz_Neg_68,
				Hz_Neg_67,
				Hz_Neg_66,
				Hz_Neg_65,
				Hz_Neg_64,
				Hz_Neg_63,
				Hz_Neg_62,
				Hz_Neg_61,
				Hz_Neg_60,
				Hz_Neg_59,
				Hz_Neg_58,
				Hz_Neg_57,
				Hz_Neg_56,
				Hz_Neg_55,
				Hz_Neg_54,
				Hz_Neg_53,
				Hz_Neg_52,
				Hz_Neg_51,
				Hz_Neg_50,
				Hz_Neg_49,
				Hz_Neg_48,
				Hz_Neg_47,
				Hz_Neg_46,
				Hz_Neg_45,
				Hz_Neg_44,
				Hz_Neg_43,
				Hz_Neg_42,
				Hz_Neg_41,
				Hz_Neg_40,
				Hz_Neg_39,
				Hz_Neg_38,
				Hz_Neg_37,
				Hz_Neg_36,
				Hz_Neg_35,
				Hz_Neg_34,
				Hz_Neg_33,
				Hz_Neg_32,
				Hz_Neg_31,
				Hz_Neg_30,
				Hz_Neg_29,
				Hz_Neg_28,
				Hz_Neg_27,
				Hz_Neg_26,
				Hz_Neg_25,
				Hz_Neg_24,
				Hz_Neg_23,
				Hz_Neg_22,
				Hz_Neg_21,
				Hz_Neg_20,
				Hz_Neg_19,
				Hz_Neg_18,
				Hz_Neg_17,
				Hz_Neg_16,
				Hz_Neg_15,
				Hz_Neg_14,
				Hz_Neg_13,
				Hz_Neg_12,
				Hz_Neg_11,
				Hz_Neg_10,
				Hz_Neg_9,
				Hz_Neg_8,
				Hz_Neg_7,
				Hz_Neg_6,
				Hz_Neg_5,
				Hz_Neg_4,
				Hz_Neg_3,
				Hz_Neg_2,
				Hz_Neg_1,
				Hz_0,
				Hz_1,
				Hz_2,
				Hz_3,
				Hz_4,
				Hz_5,
				Hz_6,
				Hz_7,
				Hz_8,
				Hz_9,
				Hz_10,
				Hz_11,
				Hz_12,
				Hz_13,
				Hz_14,
				Hz_15,
				Hz_16,
				Hz_17,
				Hz_18,
				Hz_19,
				Hz_20,
				Hz_21,
				Hz_22,
				Hz_23,
				Hz_24,
				Hz_25,
				Hz_26,
				Hz_27,
				Hz_28,
				Hz_29,
				Hz_30,
				Hz_31,
				Hz_32,
				Hz_33,
				Hz_34,
				Hz_35,
				Hz_36,
				Hz_37,
				Hz_38,
				Hz_39,
				Hz_40,
				Hz_41,
				Hz_42,
				Hz_43,
				Hz_44,
				Hz_45,
				Hz_46,
				Hz_47,
				Hz_48,
				Hz_49,
				Hz_50,
				Hz_51,
				Hz_52,
				Hz_53,
				Hz_54,
				Hz_55,
				Hz_56,
				Hz_57,
				Hz_58,
				Hz_59,
				Hz_60,
				Hz_61,
				Hz_62,
				Hz_63,
				Hz_64,
				Hz_65,
				Hz_66,
				Hz_67,
				Hz_68,
				Hz_69,
				Hz_70,
				Hz_71,
				Hz_72,
				Hz_73,
				Hz_74,
				Hz_75,
				Hz_76,
				Hz_77,
				Hz_78,
				Hz_79,
				Hz_80,
				Hz_81,
				Hz_82,
				Hz_83,
				Hz_84,
				Hz_85,
				Hz_86,
				Hz_87,
				Hz_88,
				Hz_89,
				Hz_90,
				Hz_91,
				Hz_92,
				Hz_93,
				Hz_94,
				Hz_95,
				Hz_96,
				Hz_97,
				Hz_98,
				Hz_99,
				Hz_100,
				Hz_101,
				Hz_102,
				Hz_103,
				Hz_104,
				Hz_105,
				Hz_106,
				Hz_107,
				Hz_108,
				Hz_109,
				Hz_110,
				Hz_111,
				Hz_112,
				Hz_113,
				Hz_114,
				Hz_115,
				Hz_116,
				Hz_117,
				Hz_118,
				Hz_119,
				Hz_120,
				Hz_121,
				Hz_122,
				Hz_123,
				Hz_124,
				Hz_125,
				Hz_126,
				Hz_127,
				Hz_128,
				Hz_129,
				Hz_130,
				Hz_131,
				Hz_132,
				Hz_133,
				Hz_134,
				Hz_135,
				Hz_136,
				Hz_137,
				Hz_138,
				Hz_139,
				Hz_140,
				Hz_141,
				Hz_142,
				Hz_143,
				Hz_144,
				Hz_145,
				Hz_146,
				Hz_147,
				Hz_148,
				Hz_149,
				Hz_150,
				Hz_151,
				Hz_152,
				Hz_153,
				Hz_154,
				Hz_155,
				Hz_156,
				Hz_157,
				Hz_158,
				Hz_159,
				Hz_160,
				Hz_161,
				Hz_162,
				Hz_163,
				Hz_164,
				Hz_165,
				Hz_166,
				Hz_167,
				Hz_168,
				Hz_169,
				Hz_170,
				Hz_171,
				Hz_172,
				Hz_173,
				Hz_174,
				Hz_175,
				Hz_176,
				Hz_177,
				Hz_178,
				Hz_179,
				Hz_180,
				Hz_181,
				Hz_182,
				Hz_183,
				Hz_184,
				Hz_185,
				Hz_186,
				Hz_187,
				Hz_188,
				Hz_189,
				Hz_190,
				Hz_191,
				Hz_192,
				Hz_193,
				Hz_194,
				Hz_195,
				Hz_196,
				Hz_197,
				Hz_198,
				Hz_199,
				Hz_200,
				Hz_201,
				Hz_202,
				Hz_203,
				Hz_204,
				Hz_205,
				Hz_206,
				Hz_207,
				Hz_208,
				Hz_209,
				Hz_210,
				Hz_211,
				Hz_212,
				Hz_213,
				Hz_214,
				Hz_215,
				Hz_216,
				Hz_217,
				Hz_218,
				Hz_219,
				Hz_220,
				Hz_221,
				Hz_222,
				Hz_223,
				Hz_224,
				Hz_225,
				Hz_226,
				Hz_227,
				Hz_228,
				Hz_229,
				Hz_230,
				Hz_231,
				Hz_232,
				Hz_233,
				Hz_234,
				Hz_235,
				Hz_236,
				Hz_237,
				Hz_238,
				Hz_239,
				Hz_240,
				Hz_241,
				Hz_242,
				Hz_243,
				Hz_244,
				Hz_245,
				Hz_246,
				Hz_247,
				Hz_248,
				Hz_249,
				Hz_250,
				Hz_251,
				Hz_252,
				Hz_253,
				Hz_254,
				Hz_255,
				Hz_256,
				Hz_257,
				Hz_258,
				Hz_259,
				Hz_260,
				Hz_261,
				Hz_262,
				Hz_263,
				Hz_264,
				Hz_265,
				Hz_266,
				Hz_267,
				Hz_268,
				Hz_269,
				Hz_270,
				Hz_271,
				Hz_272,
				Hz_273,
				Hz_274,
				Hz_275,
				Hz_276,
				Hz_277,
				Hz_278,
				Hz_279,
				Hz_280,
				Hz_281,
				Hz_282,
				Hz_283,
				Hz_284,
				Hz_285,
				Hz_286,
				Hz_287,
				Hz_288,
				Hz_289,
				Hz_290,
				Hz_291,
				Hz_292,
				Hz_293,
				Hz_294,
				Hz_295,
				Hz_296,
				Hz_297,
				Hz_298,
				Hz_299,
				Hz_300
			};

			enum class KeyHoldTimeValue : int
			{
				ms_500,
				sec_1,
				sec_1_5,
				sec_2
			};

			enum class LockModeValue : int
			{
				Frequency,
				Panel,
				ALL
			};

			enum class MemoryTagValue : int
			{
				OFF,
				NAME
			};

			enum class MicGainValue : int
			{
				LOW,
				NORMAL,
				HIGH
			};

			enum class MyModeValue : int
			{
				LSB_OFF = 0x10,
				LSB_ON,
				USB_OFF = 0x20,
				USB_ON,
				CW_OFF = 0x30,
				CW_ON,
				FM_OFF = 0x40,
				FM_ON,
				AM_OFF = 0x50,
				AM_ON,
				DATA_LSB_OFF = 0x60,
				DATA_LSB_ON,
				CW_R_OFF = 0x70,
				CW_R_ON,
				USER_LSB_OFF = 0x80,
				USER_LSB_ON,
				DATA_USB_OFF = 0x90,
				DATA_USB_ON,
				N_A = 0xA0,
				N_A_B,
				FM_N_OFF = 0xB0,
				FM_N_ON,
				USER_USB_OFF = 0xC0,
				USER_USB_ON
			};

			enum class MicButtonFunction : int
			{
				MONI, //Activates the Monitor function.
				N_A, // No Function.
				P_B, //Activates the Digital Voice Recorder.
				PLAY1, //Send the CW message, which is memorized in BEACON TEXT 1.
				PLAY2, //Send the CW message, which is memorized in BEACON TEXT 2.
				PLAY3, //Send the CW message, which is memorized in BEACON TEXT 3.
				QSPL, //Activates Quick Split Operation
				SPOT, //Generates a CW Spot Tone when using CW mode.
				SQLOFF, //Opens the noise squelch.
				SWR, //Transmits a 10 watts carrier(CW mode) to measure the SWR ratio.
				TXW, //Monitor the transmit frequency when Split Frequency operation is engaged.
				VCC, //Display the DC supply voltage.
				VOICE2, //Announces the current S - meter reading, operating frequency(with resolution to the displayed 100 Hz digit), and operating mode.
				VM1MONI, //Play back the voice message, which is memorized in Voice Memory 1.
				VM1REC, //Store the voice message into Voice Memory 1.
				VM1TX, //Send the voice message, which is memorized in Voice Memory 1.
				VM2MONI, //Play back the voice message, which is memorized in Voice Memory 2.
				VM2REC, //Store the voice message into Voice Memory 2.
				VM2TX, //Send the voice message, which is memorized in Voice Memory 2.
				DOWN, //Decreases the VFO frequency by one step or moves the memory channel to the next - lowest channel.
				FAST, //Set to the same function as the front panel's[FAST] button.
				UP, //Increases the VFO frequency by one step or moves the memory channel to the next - highest channel.
				DSP, //Set to the same function as the front panel's[DSP] button.
				IPO_ATT, //Set to the same function as the front panels[IPO_ATT] button.
				NB, //Set, // to the same function as the front panel’s[NB] button.
				AGC, //Set to the same function as the front panel’s[AGC] button.
				MODEDN, //Set to the same function as the front panel’s[MODE] button.
				MODEUP, //Set to the same function as the front panel’s[MODE] button.
				DSP_SEL, //Set to the same function as the front panel’s[DSP_SEL] button.
				KEYER, //Set to the same function as the front panel’s[KEYER] button.
				CLAR, //Set to the same function as the front panel’s[CLAR] button.
				BANDDN, //Set to the same function as the front panel’s[BAND] button.
				BANDUP, //Set to the same function as the front panel’s[BAND] button.
				A_eq_B, //Set to the same function as the front panel’s[A = B] button.
				A_B, //Set to the same function as the front panel’s[A_B] button.
				LOCK, //Set to the same function as the front panel’s[LOCK] button.
				TUNE, //Set to the same function as the front panel’s[TUNE] button.
				VOICE, //Announce the current operating frequency(with resolution to the displayed 100 Hz digit) and operating mode.
				MW, //Copies the current operating data from the VFO into the currently selected memory channel.
				V_M, //Toggles frequency control between VFO and memory system.
				HOME, //Recall the “Home”(favorite frequency) channel.
				RCL, //Recall the QMB(Quick Memory Bank) memory.
				VOX, //Activate the VOX(automatic voice - actuated transmitter switching) feature.
				STO, //Copies operating data into QMB(Quick Memory Bank) Memory.
				STEP, //Enables the setting of the frequency step of the[DSP_SEL] knob by the[DSP_SEL] knob.
				SPLIT, //Activates split frequency operation between VFO - A and VFO - B.
				PMS, //Engages Programmable Memory Scan(PMS).
				SCAN, //Initiates the upward scanning of VFO frequencies or memory channels.
				MENU, //Engage the “Menu” mode.
				DIMMER, //Enables adjustment of the display dimmer level by the[DSP_SEL] knob.
				MTR //Change the meter function in the transmit mode.
			};

			enum class SelDialModeValue : int
			{
				CW_Sidetone_Level,
				CW_KEYER_Speed,
				KHz_100_Step,
				MHz_1_Step,
				MIC_GAIN_Set,
				RF_Power_Set
			};

			enum class SqlRfGainEncoderType : int
			{
				SQL,
				RF_GAIN
			};

			enum class TunerTypeValue : int
			{
				ATAS,
				EXTERNAL_ATU,
				INTERNAL_ATU,
				INTRATU,
				F_TRANS
			};

			enum class ContourType : int
			{
				OnOff,
				Frequency
			};

			enum class ContourOnOffValue : int
			{
				ON_neg12dB = -2,
				ON_neg6dB,
				OFF,
				ON_6dB,
				ON_12dB
			};

			enum class ContourFrequencyValue : int
			{
				Hz_250,
				Hz_500,
				kHz_1,
				kHz_2,
				kHz_4
			};

			enum class BandValue : int
			{
				meters_160,
				meters_80,
				meters_40 = 3,
				meters_30,
				meters_20,
				meters_17,
				meters_15,
				meters_12,
				meters_10,
				meters_6,
				GEN
			};

			enum class UpDownValue : int
			{
				UP,
				DOWN
			};

			enum class CTCSSState : int
			{
				OFF,
				ENC_DEC_ON,
				ENC_ON
			};

			enum class TxVfoValue : int
			{
				VFO_A,
				VFO_B
			};
		
			enum class ManualNotchType : int
			{
				ON_OFF,
				NotchPoisition
			};

			enum class AGCTypeValue : int
			{
				OFF,
				FAST,
				SLOW_1,
				SLOW_2,
				AUTO
			};

			enum class MemoryChannelValue
			{
				_1 = 1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				_100,
				_101,
				_102,
				_103,
				_104,
				_105,
				_106,
				_107,
				_108,
				_109,
				_110,
				_111,
				_112,
				_113,
				_114,
				_115,
				_116,
				_117,
				_118,
				_119,
				_120,
				_121,
				_122,
				_123,
				_124,
				_125,
				_126,
				_127,
				_128,
				_129,
				_130,
				_131,
				_132,
				_133,
				_134,
				_135,
				_136,
				_137,
				_138,
				_139,
				_140,
				_141,
				_142,
				_143,
				_144,
				_145,
				_146,
				_147,
				_148,
				_149,
				_150,
				_151,
				_152,
				_153,
				_154,
				_155,
				_156,
				_157,
				_158,
				_159,
				_160,
				_161,
				_162,
				_163,
				_164,
				_165,
				_166,
				_167,
				_168,
				_169,
				_170,
				_171,
				_172,
				_173,
				_174,
				_175,
				_176,
				_177,
				_178,
				_179,
				_180,
				_181,
				_182,
				_183,
				_184,
				_185,
				_186,
				_187,
				_188,
				_189,
				_190,
				_191,
				_192,
				_193,
				_194,
				_195,
				_196,
				_197,
				_198,
				_199,
				_200,
				_201,
				_202,
				_203,
				_204,
				_205,
				_206,
				_207,
				_208,
				_209,
				_210,
				_211,
				_212,
				_213,
				_214,
				_215,
				_216,
				_217,
				_218,
				_219,
				_220,
				_221,
				_222,
				_223,
				_224,
				_225,
				_226,
				_227,
				_228,
				_229,
				_230,
				_231,
				_232,
				_233,
				_234,
				_235,
				_236,
				_237,
				_238,
				_239,
				_240,
				_241,
				_242,
				_243,
				_244,
				_245,
				_246,
				_247,
				_248,
				_249,
				_250,
				_251,
				_252,
				_253,
				_254,
				_255,
				_256,
				_257,
				_258,
				_259,
				_260,
				_261,
				_262,
				_263,
				_264,
				_265,
				_266,
				_267,
				_268,
				_269,
				_270,
				_271,
				_272,
				_273,
				_274,
				_275,
				_276,
				_277,
				_278,
				_279,
				_280,
				_281,
				_282,
				_283,
				_284,
				_285,
				_286,
				_287,
				_288,
				_289,
				_290,
				_291,
				_292,
				_293,
				_294,
				_295,
				_296,
				_297,
				_298,
				_299,
				_300,
				_301,
				_302,
				_303,
				_304,
				_305,
				_306,
				_307,
				_308,
				_309,
				_310,
				_311,
				_312,
				_313,
				_314,
				_315,
				_316,
				_317,
				_318,
				_319,
				_320,
				_321,
				_322,
				_323,
				_324,
				_325,
				_326,
				_327,
				_328,
				_329,
				_330,
				_331,
				_332,
				_333,
				_334,
				_335,
				_336,
				_337,
				_338,
				_339,
				_340,
				_341,
				_342,
				_343,
				_344,
				_345,
				_346,
				_347,
				_348,
				_349,
				_350,
				_351,
				_352,
				_353,
				_354,
				_355,
				_356,
				_357,
				_358,
				_359,
				_360,
				_361,
				_362,
				_363,
				_364,
				_365,
				_366,
				_367,
				_368,
				_369,
				_370,
				_371,
				_372,
				_373,
				_374,
				_375,
				_376,
				_377,
				_378,
				_379,
				_380,
				_381,
				_382,
				_383,
				_384,
				_385,
				_386,
				_387,
				_388,
				_389,
				_390,
				_391,
				_392,
				_393,
				_394,
				_395,
				_396,
				_397,
				_398,
				_399,
				_400,
				_401,
				_402,
				_403,
				_404,
				_405,
				_406,
				_407,
				_408,
				_409,
				_410,
				_411,
				_412,
				_413,
				_414,
				_415,
				_416,
				_417,
				_418,
				_419,
				_420,
				_421,
				_422,
				_423,
				_424,
				_425,
				_426,
				_427,
				_428,
				_429,
				_430,
				_431,
				_432,
				_433,
				_434,
				_435,
				_436,
				_437,
				_438,
				_439,
				_440,
				_441,
				_442,
				_443,
				_444,
				_445,
				_446,
				_447,
				_448,
				_449,
				_450,
				_451,
				_452,
				_453,
				_454,
				_455,
				_456,
				_457,
				_458,
				_459,
				_460,
				_461,
				_462,
				_463,
				_464,
				_465,
				_466,
				_467,
				_468,
				_469,
				_470,
				_471,
				_472,
				_473,
				_474,
				_475,
				_476,
				_477,
				_478,
				_479,
				_480,
				_481,
				_482,
				_483,
				_484,
				_485,
				_486,
				_487,
				_488,
				_489,
				_490,
				_491,
				_492,
				_493,
				_494,
				_495,
				_496,
				_497,
				_498,
				_499,
				_500,
				P1L,
				P1U,
				P2L,
				P2U
			};

			enum class ModeValue : int
			{
				LSB = 1,
				USB,
				CW,
				FM,
				AM,
				DATA_L,
				CW_R,
				USER_L,
				DATA_U,
				FM_N,
				USER_U

			};

			enum class VFOType : int
			{
				VFO,
				MEMORY,
				MEMORY_TUNE,
				QUICK_MEMORY_BANK
			};

			enum BeaconTextChannel : int
			{
				BEACON_TEXT_1 = 1,
				BEACON_TEXT_2,
				BEACON_TEXT_3
			};

			enum class KeyPitchValue : int
			{
				Hz_400 = 2,
				Hz_500 = 4,
				Hz_600 = 6,
				Hz_700 = 8,
				Hz_800 = 10
			};

			enum class MessageSource : int
			{
				VOICE_MEMORY,
				DIGITAL_VOICE_RECORDER
			};

			enum class VoiceMemoryState : int
			{
				STOP,
				MEMORY_1,
				MEMORY_2
			};

			enum class DigitalVoiceRecorderState : int
			{
				STOP,
				START,
			};

			enum class ModeKeyValue : int
			{
				MODE_UP = 7,
				MODE_DOWN,
				REVERSE
			};

			enum class MeterType : int
			{
				ALC = 1,
				PO,
				SWR
			};

			enum class NarrowType : int
			{
				Medium,
				Narrow
			};

			enum class PlayBackType : int
			{
				STOP,
				VOICE_MEMORY_1,
				VOICE_MEMORY_2,
				DIGITAL_VOICE_RECORDER = 6
			};

			enum class RadioInformationType : int
			{
				HIGH_SWR,
				MIC_EQ,
				REC,
				PLAY
			};

			enum class ReadMeterType : int
			{
				METER_SWITCH,
				S_METER,
				ALC_METER,
				PO_METER,
				SWR_METER
			};

			enum class RadioStatusValue : int
			{
				NORMAL,
				MENU_MODE
			};

			enum class ScanStatusValue : int
			{
				OFF,
				SCAN_UP,
				SCAN_DOWN
			};

			enum class WidthType : int
			{
				Narrow,
				Normal,
				Wide
			};

			enum class TxSetValue : int
			{
				RADIO_TX_OFF_CAT_TX_OFF,
				RADIO_TX_OFF_CAT_TX_ON,
				RADIO_TX_ON_CAT_TX_OFF
			};

			enum class PLLLockState : int
			{
				LOCKED,
				UNLOCKED
			};

			struct WidthValue
			{
				WidthType type;
				int value;
			};

			struct ReadMeterValue
			{
				ReadMeterType type;
				int value;
			};

			union LoadMessageState
			{
				VoiceMemoryState voiceMemory;
				DigitalVoiceRecorderState digitalVoiceRecorder;
			};

			struct LoadMessageValue
			{
				MessageSource source;
				LoadMessageState state;
			};

			union ManualNotchValue
			{
				OnOffValue state;
				int value;
			};

			struct ManualNotchParam
			{
				ManualNotchType type;
				ManualNotchValue value;
			};

			struct Information
			{
				MemoryChannelValue memoryChannel;
				int VFO_Frequency;
				int ClarifierFrequency;
				OnOffValue RX_ClarifierState;
				OnOffValue TX_ClarifierState;
				ModeValue mode;
				VFOType vfoType;
				CTCSSState ctcssState;
				CTCSSTone ctcssTone;
				RepeaterShiftDirection shiftDirection;
			};

			struct KeyerMemoryValue
			{
				BeaconTextChannel beaconText;
				std::string text;
			};

			struct RadioInformaitonValue
			{
				RadioInformationType type;
				OnOffValue state;
			};

			class ANTENNA_TUNER_CONTROL
			{
			public:
				static std::string Set(AntennaTunerValue value);
				static std::string Read();
				static AntennaTunerValue Answer(std::string data);
			};

			class AF_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AUTO_INFORMATION
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class BAND_DOWN
			{
			public:
				static std::string Set(VFOValue value);
			};

			class BREAK_IN
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class MANUAL_NOTCH
			{
			public:
				static std::string Set(ManualNotchParam value);
				static std::string Read(ManualNotchType);
				static ManualNotchParam Answer(std::string data);
			};

			class BAND_SELECT
			{
			public:
				static std::string Set(BandValue value);

			};

			class BAND_UP
			{
			public:
				static std::string Set();

			};

			class BUSY
			{
			public:
				std::string Read();
				OnOffValue Answer(std::string data);
			};

			class CHANNEL_UP_DOWN
			{
			public:
				static std::string Set(UpDownValue value);

			};

			class CTCSS_TONE_FREQUENCY
			{
			public:
				static std::string Set(CTCSSTone value);
				static std::string Read();
				static CTCSSTone Answer(std::string data);
			};

			union ContourValue
			{
				ContourOnOffValue OnOff;
				ContourFrequencyValue frequency;
			};

			struct ContourParam
			{
				ContourType type;
				ContourValue value;
			};

			class CONTOUR
			{
			public:
				static std::string Set(ContourParam value);
				static std::string Read(ContourType type);
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
				static std::string Set(CTCSSState value);
				static std::string Read();
				static CTCSSState Answer(std::string data);
			};

			class DIMMER
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class MIC_DOWN
			{
			public:
				static std::string Set();
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
				static std::string Set(int value);

			};

			class ENCODER_UP
			{
			public:
				static std::string Set(int value);

			};

			class Menu
			{
			public:

				class EXT_MNU
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class AM_FM_DIAL
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};

				class APO_TIME
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

				class BEACON_TEXT
				{
				public:
					static std::string Set(std::string value);
					static std::string Read();
					static std::string Answer(std::string data);
				};

				class BEEP_TONE
				{
				public:
					static std::string Set(BEEPFrequencyValue value);
					static std::string Read();
					static BEEPFrequencyValue Answer(std::string data);
				};

				class BEEP_VOLUME
				{
				public:
					static std::string Set(BeepVolumeValue value);
					static std::string Read();
					static BeepVolumeValue Answer(std::string data);
				};

				class CAT_RTS
				{
				public:
					static std::string Set(EnableDisableValue value);
					static std::string Read();
					static EnableDisableValue Answer(std::string data);
				};

				class CAT_TIMEOUT
				{
				public:
					static std::string Set(CATTimeOutValue value);
					static std::string Read();
					static CATTimeOutValue Answer(std::string data);
				};

				class CAT_RATE
				{
				public:
					static std::string Set(CATRateValue value);
					static std::string Read();
					static CATRateValue Answer(std::string data);
				};

				class CLAR_DIAL_SELECT
				{
				public:
					static std::string Set(ClarDialValue value);
					static std::string Read();
					static ClarDialValue Answer(std::string data);
				};

				class CLOCK_SHIFT
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class DISPLAY_CONTRAST
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class CW_AUTO_MODE
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class CW_BFO
				{
				public:
					static std::string Set(BFOValue value);
					static std::string Read();
					static BFOValue Answer(std::string data);
				};

				class CW_DELAY
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class CW_KEY_REVERSE
				{
				public:
					static std::string Set(ReverseValue value);
					static std::string Read();
					static ReverseValue Answer(std::string data);
				};

				class CW_QSK
				{
				public:
					static std::string Set(CWQskRateValue value);
					static std::string Read();
					static CWQskRateValue Answer(std::string data);
				};

				class CW_PADDEL
				{
				public:
					static std::string Set(KeyerInputValue value);
					static std::string Read();
					static KeyerInputValue Answer(std::string data);
				};

				class CW_PITCH
				{
				public:
					static std::string Set(CWPitchValue value);
					static std::string Read();
					static CWPitchValue Answer(std::string data);
				};

				class CW_SPEED
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class CW_SIDE_TONE
				{
				public:
					static std::string Set(SideToneVolumeValue value);
					static std::string Read();
					static SideToneVolumeValue Answer(std::string data);
				};

				class CW_TRAINING
				{
				public:
					static std::string Set(CWTrainingValue value);
					static std::string Read();
					static CWTrainingValue Answer(std::string data);
				};

				class CW_WEIGHT
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class DATA_DISPLAY
				{
				public:
					static std::string Set(DataDisplayValue value);
					static std::string Read();
					static DataDisplayValue Answer(std::string data);
				};

				class DATA_MODE
				{
				public:
					static std::string Set(DataModeValue value);
					static std::string Read();
					static DataModeValue Answer(std::string data);
				};

				class DIAL_STEP
				{
				public:
					static std::string Set(DialStepValue value);
					static std::string Read();
					static DialStepValue Answer(std::string data);
				};

				class DIGITAL_VOX
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class EMERGENCY
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class KEY_HOLD_TIME
				{
				public:
					static std::string Set(KeyHoldTimeValue value);
					static std::string Read();
					static KeyHoldTimeValue Answer(std::string data);
				};

				class LOCK_MODE
				{
				public:
					static std::string Set(LockModeValue value);
					static std::string Read();
					static LockModeValue Answer(std::string data);
				};

				class M_TUNE
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class MEMORY_GROUP
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class MEMORY_TAG
				{
				public:
					static std::string Set(MemoryTagValue value);
					static std::string Read();
					static MemoryTagValue Answer(std::string data);
				};

				class MIC_EQ
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class MIC_GAIN
				{
				public:
					static std::string Set(MicGainValue value);
					static std::string Read();
					static MicGainValue Answer(std::string data);
				};

				class MIC_AUTO_SCAN
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class MY_BAND
				{
				public:
					static std::string Set(MyBandValue value);
					static std::string Read();
					static MyBandValue Answer(std::string data);
				};

				class MY_MODE
				{
				public:
					static std::string Set(MyModeValue value);
					static std::string Read();
					static MyModeValue Answer(std::string data);
				};

				class MIC_DOWN_PG
				{
				public:
					static std::string Set(MicButtonFunction value);
					static std::string Read();
					static MicButtonFunction Answer(std::string data);
				};

				class MIC_FAST_PG
				{
				public:
					static std::string Set(MicButtonFunction value);
					static std::string Read();
					static MicButtonFunction Answer(std::string data);
				};

				class MIC_UP_PG
				{
				public:
					static std::string Set(MicButtonFunction value);
					static std::string Read();
					static MicButtonFunction Answer(std::string data);
				};

				class METER_PEAK_HOLD
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class PANNEL_CUSTOM_SWITCH
				{
				public:
					static std::string Set(MicButtonFunction value);
					static std::string Read();
					static MicButtonFunction Answer(std::string data);
				};

				class QUICK_SPLIT_FREQ
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class RF_POWER
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class REPEATER_SHIFT
				{
				public:
					static std::string Set(RepeaterShiftDirection value);
					static std::string Read();
					static RepeaterShiftDirection Answer(std::string data);
				};

				class REPEATER_SHIFT_OFFSET
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

				class RTTY_RX_POLARITY
				{
				public:
					static std::string Set(RTTYPolarityValue value);
					static std::string Read();
					static RTTYPolarityValue Answer(std::string data);
				};

				class RTTY_TX_POLARITY
				{
				public:
					static std::string Set(RTTYPolarityValue value);
					static std::string Read();
					static RTTYPolarityValue Answer(std::string data);
				};

				class SCAN_RESUME
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class SEL_DIAL_MODE
				{
				public:
					static std::string Set(SelDialModeValue value);
					static std::string Read();
					static SelDialModeValue Answer(std::string data);
				};

				class SQL_TYPE
				{
				public:
					static std::string Set(SqlTypeValue value);
					static std::string Read();
					static SqlTypeValue Answer(std::string data);
				};

				class SQL_RFGAIN_ENCODER
				{
				public:
					static std::string Set(SqlRfGainEncoderType value);
					static std::string Read();
					static SqlRfGainEncoderType Answer(std::string data);
				};

				class STANDBY_BEEP
				{
				public:
					static std::string Set(OnOffValue value);
					static std::string Read();
					static OnOffValue Answer(std::string data);
				};

				class TONE_FREQ
				{
				public:
					static std::string Set(CTCSSTone value);
					static std::string Read();
					static CTCSSTone Answer(std::string data);
				};

				class TOT_TIME
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class TUNER_TYPE
				{
				public:
					static std::string Set(TunerTypeValue value);
					static std::string Read();
					static TunerTypeValue Answer(std::string data);
				};


				class VOX_DELAY_TIME
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class VOX_GAIN
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};
			};

			class FREQUENCY_VFO_A
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FREQUENCY_VFO_B
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FAST_STEP
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class FUNCTION_TX
			{
			public:
				static std::string Set(TxVfoValue value);
				static std::string Read();
				static TxVfoValue Answer(std::string data);
			};

			class AGC_FUNCTION
			{
			public:
				static std::string Set(AGCTypeValue value);
				static std::string Read();
				static AGCTypeValue Answer(std::string data);
			};

			class INFORMATION
			{
			public:
				static std::string Read();
				static Information Answer(std::string data);
			};

			class IF_SHIFT
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class KEYER_MEMORY
			{
			public:
				static std::string Set(KeyerMemoryValue value);
				static std::string Read(BeaconTextChannel value);
				static KeyerMemoryValue Answer(std::string data);
			};

			class KEYER_PITCH
			{
			public:
				static std::string Set(KeyPitchValue value);
				static std::string Read();
				static KeyPitchValue Answer(std::string data);
			};

			class KEYER
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class KEY_SPEED
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class CW_KEYING
			{
			public:
				static std::string Set(BeaconTextChannel value);
			};

			class LOCK
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class LOAD_MESSAGE
			{
			public:
				static std::string Set(LoadMessageValue value);
				static std::string Read(MessageSource value);
				static LoadMessageValue Answer(std::string data);
			};

			class MEMORY_CHANNEL
			{
			public:
				static std::string Set(MemoryChannelValue value);
				static std::string Read();
				static MemoryChannelValue Answer(std::string data);
			};

			class MODE
			{
			public:
				static std::string Set(ModeValue value);
				static std::string Read();
				static ModeValue Answer(std::string data);
			};

			class MIC_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class MODE_KEY
			{
			public:
				static std::string Set(ModeKeyValue value);
			};

			class MONITOR_LEVEL
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class MEMORY_CHANNEL_READ
			{
			public:

				static std::string Read(MemoryChannelValue value);
				static Information Answer(std::string data);
			};

			class METER_SW
			{
			public:
				static std::string Set(MeterType value);
				static std::string Read();
				static MeterType Answer(std::string data);
			};

			class MEMORY_CHANNEL_WRITE
			{
			public:
				static std::string Set(Information value);
			};

			class NARROW
			{
			public:
				static std::string Set(NarrowType value);
				static std::string Read();
				static NarrowType Answer(std::string data);
			};

			class NOISE_BLANKER
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class NOISE_REDUCTION
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class OPPOSITE_BAND_INFORMATION
			{
			public:
				static std::string Read();
				static Information Answer(std::string data);
			};

			class OFFSET
			{
			public:
				static std::string Set(RepeaterShiftDirection value);
				static std::string Read();
				static RepeaterShiftDirection Answer(std::string data);
			};

			class PRE_AMP
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class PLAYBACK
			{
			public:
				static std::string Set(PlayBackType value);
				static std::string Read();
				static PlayBackType Answer(std::string data);
			};

			class POWER_CONTROL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class POWER_SWITCH
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class QMB_STORE
			{
			public:
				static std::string Set();
			};

			class QMB_RECALL
			{
			public:
				static std::string Set();
			};

			class QUICK_SPLIT
			{
			public:
				static std::string Set();
			};

			class RF_ATTENUATOR
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class CLAR_CLEAR
			{
			public:
				static std::string Set();
			};

			class CLARIFIER_MINUS_OFFSET
			{
			public:
				static std::string Set(int value);

			};

			class RF_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class RADIO_INFORMATION
			{
			public:
				static std::string Read(RadioInformationType value);
				static RadioInformaitonValue Answer(std::string data);
			};

			class NOISE_REDUCTION_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class READ_METER
			{
			public:

				static std::string Read(ReadMeterType value);
				static ReadMeterValue Answer(std::string data);
			};

			class POWER_ON_RESET
			{
			public:
				static std::string Set();
				static std::string Read();
				static void Answer(std::string data);
			};

			class RADIO_STATUS
			{
			public:

				static std::string Read();
				static RadioStatusValue Answer(std::string data);
			};

			class CLAR
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class CLARIFIER_PLUS_OFFSET
			{
			public:
				static std::string Set(int value);

			};

			class SCAN
			{
			public:
				static std::string Set(ScanStatusValue value);
				static std::string Read();
				static ScanStatusValue Answer(std::string data);
			};

			class CW_BREAKIN_DELAY
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class WIDTH
			{
			public:
				static std::string Set(WidthValue value);
				static std::string Read();
				static WidthValue Answer(std::string data);
			};

			class S_METER
			{
			public:
				static std::string Read();
				static int Answer(std::string data);
			};

			class SQUELCH_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class STEP
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class SWAP_VFO
			{
			public:
				static std::string Set();
			};


			class TXW
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class TX_SET
			{
			public:
				static std::string Set(TxSetValue value);
				static std::string Read();
				static TxSetValue Answer(std::string data);
			};

			class PLL_UNLOCK_STATUS
			{
			public:

				static std::string Read();
				static PLLLockState Answer(std::string data);
			};


			class MIC_UP
			{
			public:
				static std::string Set();

			};


			class VOX_DELAY_TIME
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class VOX_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class VM_KEY
			{
			public:
				static std::string Set();
			};

			class VOICE
			{
			public:
				static std::string Set(VoiceMemoryState value);
				static std::string Read();
				static VoiceMemoryState Answer(std::string data);
			};

			class VFO_SELECT
			{
			public:
				static std::string Set(VFOValue value);
				static std::string Read();
				static VFOValue Answer(std::string data);
			};

			class VFO_TO_VFO
			{
			public:
				static std::string Set();

			};

			class VOX_STATUS
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

		}
		
		namespace FT991A
		{
			using Yaesu::Common::OnOffValue;
			using Yaesu::Common::EnableDisableValue;
			using Yaesu::Common::UpDownValue;
			using Yaesu::Common::VoxSelectValue;
			using Yaesu::Common::FreqLowCutValue;
			using Yaesu::Common::FreqHighCutValue;
			using Yaesu::Common::KeyerMemoryChannel;
			using Yaesu::Common::RTTYPolarityValue;
			using Yaesu::Common::RTTYShiftFreqValue;
			using Yaesu::Common::RTTYMarkFreq;
			using Yaesu::Common::PTTSelectValue;
			using Yaesu::Common::APFWidthValue;
			using Yaesu::Common::IFNotchWidth;
			using Yaesu::Common::MeterHoldType;
			using Yaesu::Common::KeyerType;
			using Yaesu::Common::KeyerDotDashType;
			using Yaesu::Common::KeyerMemoryType;
			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;
			using Yaesu::Common::BaudotCodeStandard;

			enum class PreampType
			{
				IPO,
				AMP1,
				AMP2
			};

            enum class ClarModeType : int
            {
                RX,
                TX,
                TRX
            };

			enum class DVSRecordingValue
			{
				STOP,
				CH1,
				CH2,
				CH3,
				CH4,
				CH5
			};

			using Yaesu::Common::VoxSelectValue;

            enum class PKTMode : int
            {
                _1200bps,
                _9600bps
            };

            enum class CwBreakInType : int
            {
                SEMI,
                FULL
            };

            enum class CWAutoModeType
            {
                OFF,
                _50Mhz,
                ON
            };
			
			using Yaesu::Common::KeyerMemoryChannel;
			

			enum class TunerSelectValue : int
			{
				OFF,
				EXTERNAL,
				ATAS,
				LAMP
			};

			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;

			
			using Yaesu::Common::RTTYPolarityValue;
		
			using Yaesu::Common::RTTYShiftFreqValue;

			using Yaesu::Common::RTTYMarkFreq;

			enum class AMSTxModeValue : int
			{
				AUTO,
				MANUAL,
				DN,
				VW,
				ANALOG
			};

			enum class GMDisplayType : int
			{
				DISTANCE,
				STRENGTH
			};

			enum class DistanceType : int
			{
				km,
				mile
			};

			enum class PCKeyingValue : int
			{
				OFF,
				DKAY,
				RTS,
				DTR
			};

			enum class KeyPitchValue
			{
				_300Hz,
				_310Hz,
				_320Hz,
				_330Hz,
				_340Hz,
				_350Hz,
				_360Hz,
				_370Hz,
				_380Hz,
				_390Hz,
				_400Hz,
				_410Hz,
				_420Hz,
				_430Hz,
				_440Hz,
				_450Hz,
				_460Hz,
				_470Hz,
				_480Hz,
				_490Hz,
				_500Hz,
				_510Hz,
				_520Hz,
				_530Hz,
				_540Hz,
				_550Hz,
				_560Hz,
				_570Hz,
				_580Hz,
				_590Hz,
				_600Hz,
				_610Hz,
				_620Hz,
				_630Hz,
				_640Hz,
				_650Hz,
				_660Hz,
				_670Hz,
				_680Hz,
				_690Hz,
				_700Hz,
				_710Hz,
				_720Hz,
				_730Hz,
				_740Hz,
				_750Hz,
				_760Hz,
				_770Hz,
				_780Hz,
				_790Hz,
				_800Hz,
				_810Hz,
				_820Hz,
				_830Hz,
				_840Hz,
				_850Hz,
				_860Hz,
				_870Hz,
				_880Hz,
				_890Hz,
				_900Hz,
				_910Hz,
				_920Hz,
				_930Hz,
				_940Hz,
				_950Hz,
				_960Hz,
				_970Hz,
				_980Hz,
				_990Hz,
				_1000Hz,
				_1010Hz,
				_1020Hz,
				_1030Hz,
				_1040Hz,
				_1050Hz

			};

			enum class PSKToneValue : int
			{
				_1000hz,
				_1500hz,
				_2000hz
			};

			enum class CWWaveShapeValue : int
			{
				_1msec,
				_2msec,
				_4msec,
				_6msec
			};

			enum class CWFreqDisplayValue : int
			{
				FREQ,
				PITCH
			};

			enum class QskDelayTimeValue : int
			{
				_15msec,
				_20msec,
				_25msec,
				_30msec
			};

			enum class AGCSetValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO
			};

			enum class AGCStateValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO_FAST,
				AUTO_MID,
				AUTO_SLOW
			};

	        enum class MenuFunction : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				HOME,
				MY_CALL_INDICATION,
				DISPLAY_COLOR,
				DIMMER_LED,
				DIMMER_TFT,
				BAR_MTR_PEAK_HOLD,
				DVS_RX_OUT_LEVEL,
				DVS_TX_OUT_LEVEL,
				KEYER_TYPE,
				KEYER_DOTDASH,
				CW_WEIGHT,
				BEACON_INTERVAL,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				CW_MEMORY_1,
				CW_MEMORY_2,
				CW_MEMORY_3,
				CW_MEMORY_4,
				CW_MEMORY_5,
				NB_WIDTH,
				NB_REJECTION,
				NB_LEVEL,
				BEEP_LEVEL,
				TIME_ZONE,
				GPS_RS232_SELECT,
				RS232_RATE,
				RS232_TIME_OUT_TIMER,
				CAT_RATE,
				CAT_TIME_OUT_TIMER,
				CAT_RTS,
				MEM_GROUP,
                QUICK_SPLIT_FREQ,
				TX_TOT,
				MIC_SCAN,
				MIC_SCAN_RESUME,
                REF_FREQ_ADJ,
				CLAR_MODE_SELECT,
				AM_LCUT_FREQ,
				AM_LCUT_SLOPE,
				AM_HCUT_FREQ,
				AM_HCUT_SLOPE,
				AM_MIC_SELECT,
                AM_OUT_LEVEL,
				AM_PTT_SELECT,
				AM_PORT_SELECT,
				AM_DATA_GAIN,
				CW_LCUT_FREQ,
				CW_LCUT_SLOPE,
				CW_HCUT_FREQ,
				CW_HCUT_SLOPE,
				CW_OUT_LEVEL,
				CW_AUTO_MODE,
				CW_BK_IN_TYPE,
				CW_BK_IN_DELAY,
				CW_WAVE_SHAPE,
				CW_FREQ_DISPLAY,
				PC_KEYING,
				QSK_DELAY_TIME,
				DATA_MODE,
				PSK_TONE,
				OTHER_DISP,
				OTHER_SHIFT,
				DATA_LCUT_FREQ,
				DATA_LCUT_SLOPE,
				DATA_HCUT_FREQ,
				DATA_HCUT_SLOPE,
				DATA_IN_SELECT,
				DATA_PTT_SELECT,
				DATA_PORT_SELECT,
				DATA_OUT_LEVEL,
				FM_MIC_SELECT,
				FM_OUT_LEVEL,
				FM_PKT_PTT_SELECT,				
				FM_PKT_PORT_SELECT,
				FM_PKT_TX_GAIN,
				FM_PKT_MODE,
				RPT_SHIFT_28MHZ,
				RPT_SHIFT_50MHZ,
				RPT_SHIFT_144MHZ,
				RPT_SHIFT_430MHZ,
				ARS_144MHZ,
				ARS_430MHZ,
				DCS_POLARITY,
				RADIO_ID,
				GM_DISPLAY,
				DISTANCE,
				AMS_TX_MODE,
				STANDBY_BEEP,
				RTTY_LCUT_FREQ,
				RTTY_LCUT_SLOPE,
				RTTY_HCUT_FREQ,
				RTTY_HCUT_SLOPE,
				RTTY_SHIFT_PORT,
                RTTY_POLARITY_RX,
                RTTY_POLARITY_TX,
				RTTY_OUT_LEVEL,
				RTTY_SHIFT_FREQ,
				RTTY_MARK_FREQ,
				SSB_LCUT_FREQ,
				SSB_LCUT_SLOPE,
				SSB_HCUT_FREQ,
				SSB_HCUT_SLOPE,
				SSB_MIC_SELECT,
                SSB_OUT_LEVEL,
				SSB_PTT_SELECT,
				SSB_PORT_SELECT,
				SSB_TX_BPF,
				APF_WIDTH,
                COUNTOUR_LEVEL,
                COUNTOUR_WIDTH,
				IF_NOTCH_WIDTH,
				SCP_DISPLAY_MODE,
				SCP_SPAN_FREQ,
                SPECTRUM_COLOR,
				WATERFALL_COLOR,
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
				TX_MAX_POWER_HF,
				TX_MAX_POWER_50MHZ,
				TX_MAX_POWER_144MHZ,
				TX_MAX_POWER_430MHZ,
				TUNER_SELECT,
				VOX_SELECT,
				VOX_GAIN,
				VOX_DELAY,
				ANTI_VOX_GAIN,
				DATA_VOX_GAIN,
				DATA_VOX_DELAY,
				ANTI_DVOX_GAIN,
				EMERGENCY_FREQ_TX,
				PRT_WIRES_FREQ,
				PRESET_FREQUENCY,
				SEARCH_SETUP,
				WIRES_DG_ID

			};

			enum class MemoryChannelValue
			{
				_1 = 1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				P1L,
				P1U,
				P2L,
				P2U,
				P3L,
				P3U,
				P4L,
				P4U,
				P5L,
				P5U,
				P6L,
				P6U,
				P7L,
				P7U,
				P8L,
				P8U,
				P9L,
				P9U
			};

			enum class InformationState : int
			{
				OFF,
				ON
			};

			using Yaesu::Common::OnOffValue;
			
            
			using Yaesu::Common::EnableDisableValue;

			using Yaesu::Common::UpDownValue;

			enum class DataMode : int
			{
				PSK,
				OTHER
			};

			enum class AntennaTunerControlValue : int
			{
				OFF,
				ON,
				StartStop
			};

			enum class ManualNotchType : int
			{
				OnOff,
				Level
			};

			enum class SearchSetupType : int
			{
				HISTORY,
				ACTIVITY
			};
			
			enum class CWKeyingPlaybackValue : int
			{
				Memory1 = 1,
				Memory2,
				Memory3,
				Memory4,
				Memory5,
				Message1,
				Message2,
				Message3,
				Message4,
				Message5
			};

			enum class Band : int
			{
				_180m,
				_80m,
				_60m,
				_40m,
				_30m,
				_20m,
				_17m,
				_15m,
				_12m,
				_10m,
				_6m,
				GEN,
				MW,
				AIR = 14,
				_2m,
				_70cm
			};

			enum class FreqSlopeValue : int
			{
				DbOct_6,
				DbOct_18
			};

			using Yaesu::Common::FreqHighCutValue;
			
			using Yaesu::Common::FreqLowCutValue;
			
			using Yaesu::Common::APFWidthValue;

			
			
			enum class CTCSSToneType : int
			{
				CTCSS,
				DCS
			};
			
			using Yaesu::Common::IFNotchWidth;

		
            enum class HomeFunction : int
			{
				SCOPE,
				FUNCTION
			};

			enum class DisplayColorType
			{
				BLUE,
				GRAY,
				GREEN,
				ORANGE,
				PURPLE,
				RED,
				SKY_BLUE
			};

			
			enum class NumberStyleType : int
			{
			   _1290,
			   AUNO,
			   AUNT,
			   A2NO,
			   A2NT,
			   _12NO,
			   _12NT
			};

		
			enum class NbWidthType : int
			{
				_1ms,
				_3ms,
				_10ms
			};

			enum class CatRate : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum class CatTOT : int
			{
				_10msec,
				_100msec,
				_1000msec,
				_3000msec
			};

			enum class MicScanResumeValue : int
			{
				PAUSE,
				TIME
			};
		
			enum class ClarifierState : int
			{
				OFF,
				ON
			};

			enum class CountourType : int
			{
				CONTOUR_ONOFF,
				CONTOUR_FREQ,
				APF_ONOFF,
				APF_FREQ
			};
			
			enum class CTCSSType : int
			{
				CTCSS_OFF,
				CTCSS_ENC_DEC,
				CTCSS_ENC,
				DCS_ENC_DEC,
				DCS_ENC
			};

			using Yaesu::Common::PTTSelectValue;

			enum class ShiftPortValue : int
			{
				SHIFT,
				DTR,
				RTS
			};

			enum class ModulationSource : int
			{
				MIC,
				REAR
			};

			enum class RearSelect : int
			{
				DATA,
				USB
			};

			enum class DateTimeType : int
			{
				Date,
				Time,
				TimeZone
			};
			
			enum class DCSPolarityValue : int
			{
				Tn_Rn,
				Tn_Riv,
				Tiv_Rn,
				Tiv_Riv
			};

			struct DateTimeValue
			{
				DateTimeType Type{};
				std::string Value{};
			};
			
			enum class CwMemoryType : int
			{
				TEXT,
				MESSAGE
			};

			enum class SSBTXBandPassValue : int
			{
				_100_3000,
				_100_2900,
				_200_2800,
				_300_2700,
				_400_2600
			};
            
			enum class GpsSelectType : int
            {
                GPS1,
                GPS2,
                RS232C
            };
			
			enum class ScopeDisplayMode : int
			{
				SPECTRUM,
				WATERFALL
			};
			
			enum class ScopeSpan : int
			{
				_50kHz  = 3,
				_100kHz,
				_200kHz,
				_500kHz,
				_1000kHz
			};
			
			enum class SpectrumColor : int
			{
				BLUE,
				GRAY,
				GREEN,
				ORANGE,
				PURPLE,
				RED,
				SKY_BLUE
			};
            
			enum class EncoderType : int
            {
                MAIN,
                SUB,
                MULTI = 8
            };
            
			enum class NBRejectionType : int
            {
                _10db,
                _30db,
                _50db
            };
			
			enum class WaterfallColor : int
			{
				BLUE,
				GRAY,
				GREEN,
				ORANGE,
				PURPLE,
				RED,
				SKY_BLUE,
				MULTI
			};
			
			enum class WiresDGID : int
			{
				AUTO,
				DG_ID1, 
				DG_ID2, 
				DG_ID3, 
				DG_ID4, 
				DG_ID5, 
				DG_ID6, 
				DG_ID7, 
				DG_ID8, 
				DG_ID9, 
				DG_ID10, 
				DG_ID11, 
				DG_ID12, 
				DG_ID13, 
				DG_ID14, 
				DG_ID15, 
				DG_ID16, 
				DG_ID17, 
				DG_ID18, 
				DG_ID19, 
				DG_ID20, 
				DG_ID21, 
				DG_ID22, 
				DG_ID23, 
				DG_ID24, 
				DG_ID25, 
				DG_ID26, 
				DG_ID27, 
				DG_ID28, 
				DG_ID29, 
				DG_ID30, 
				DG_ID31, 
				DG_ID32, 
				DG_ID33, 
				DG_ID34, 
				DG_ID35, 
				DG_ID36, 
				DG_ID37, 
				DG_ID38, 
				DG_ID39, 
				DG_ID40, 
				DG_ID41, 
				DG_ID42, 
				DG_ID43, 
				DG_ID44, 
				DG_ID45, 
				DG_ID46, 
				DG_ID47, 
				DG_ID48, 
				DG_ID49, 
				DG_ID50, 
				DG_ID51, 
				DG_ID52, 
				DG_ID53, 
				DG_ID54, 
				DG_ID55, 
				DG_ID56, 
				DG_ID57, 
				DG_ID58, 
				DG_ID59, 
				DG_ID60, 
				DG_ID61, 
				DG_ID62, 
				DG_ID63, 
				DG_ID64, 
				DG_ID65, 
				DG_ID66, 
				DG_ID67, 
				DG_ID68, 
				DG_ID69, 
				DG_ID70, 
				DG_ID71, 
				DG_ID72, 
				DG_ID73, 
				DG_ID74, 
				DG_ID75, 
				DG_ID76, 
				DG_ID77, 
				DG_ID78, 
				DG_ID79, 
				DG_ID80, 
				DG_ID81, 
				DG_ID82, 
				DG_ID83, 
				DG_ID84, 
				DG_ID85, 
				DG_ID86, 
				DG_ID87, 
				DG_ID88, 
				DG_ID89, 
				DG_ID90, 
				DG_ID91, 
				DG_ID92, 
				DG_ID93, 
				DG_ID94, 
				DG_ID95, 
				DG_ID96, 
				DG_ID97, 
				DG_ID98, 
				DG_ID99
			};

			enum class WiresFreqencyType : int
			{
				MANUAL,
				PRESET
			};

			enum class ModeValue : int
			{
				LSB = 1,
				USB,
				CW_U,
				FM,
				AM,
				RTTY_LSB,
				CW_L,
				DATA_LSB,
				RTTY_USB,
				DATA_FM,
				FM_N,
				DATA_USB,
				AM_N,
				C4FM
			};

			enum class VFOChannelTypeValue : int
			{
				VFO,
				Memory,
				MemoryTune,
				QuickMemeoryBank,
				QuickMemoryBankManualTune,
				PMS,
				HOME
			};
			
			enum class CTCSSState : int
			{
				OFF,
				CTCSS_ENC_DEC,
				CTCSS_ENC,
				DCS_ENC_DEC,
				DCS_ENC
			};
			
			enum class OperationType : int
			{
				Simplex,
				PlusShift,
				MinusShift
			};

			enum class MonitorFunction : int
			{
				OnOff,
				Level
			};

			enum class SpeechProcessorType : int
			{
				SpeechProcessor,
				ParametricMicrophoneEqualizer
			};

			enum class MeterType : int
			{
				COMP,
				ALC,
				PO,
				SQR,
				ID,
				VDD
			};

			union ManualNotchValue
			{
				int Frequency;
				OnOffValue State;
			};

			struct MonitorLevelValue
			{

				MonitorFunction f{};
				union Value
				{
					OnOffValue eVal;
					int iVal;
				};
				Value val{};
			};

			struct KeyerMemoryValue
			{
				KeyerMemoryChannel Channel{};
				std::string Message{};
			};

			struct MemoryChannelTag
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState RxClarifier{};
				ClarifierState TxClarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
				std::string Tag{};
			};

			struct InformationValue
			{
				MemoryChannelValue MemoryChannel;
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState RxClarifier{};
				ClarifierState TxClarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct OppositeInformationValue
			{
				MemoryChannelValue MemoryChannel;
				int VFOBFreq{};
				int ClarifierFreq{};
				ClarifierState RxClarifier{};
				ClarifierState TxClarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct CTCSSToneValue
			{
				CTCSSToneType Type{};
				int Value{};
			};

			struct ManualNotchValueType
			{
				ManualNotchType Type{};
				ManualNotchValue Value{};
			};

			class VFO_A_To_VFO_B
			{
			public:
				static std::string Set();
			};

			class AntennaTunerControl
			{
			public:
				static std::string Set(AntennaTunerControlValue value);
				static std::string Read();
				static AntennaTunerControlValue Answer(std::string data);
			};

			class AF_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AutoInformation
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class VFO_A_To_Memory
			{
			public:
				static std::string Set();
			};

			class VFO_B_To_VFO_A
			{
			public:
				static std::string Set();
			};

			class AutoNotch
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class BandDown
			{
			public:
				static std::string Set();
			};

			class BreakIn
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ManualNotch
			{
			public:
				static std::string Set(ManualNotchValueType value);
				static std::string Read(ManualNotchType);
				static ManualNotchValueType Answer(std::string data);
			};

			class BandSelect
			{
			public:
				static std::string Set(Band value);
			};

			class BandUp
			{
			public:
				static std::string Set();
			};

			class Busy
			{
			public:
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ChannelUpDown
			{
			public:
				static std::string Set(UpDownValue value);
			};

			class CTCSSToneFrequency
			{
			  public:
			static std::string Set(CTCSSToneValue value);
			static std::string Read(CTCSSToneType);
			static CTCSSToneValue Answer(std::string data);
			};
					
			union CountourState
			{
				OnOffValue CountourState;
				int CountourFrequency;
				OnOffValue APFState;
				int APFFrequency;
            };
			
			struct CountourValue
			{
				CountourType Type;
				CountourState Value;
			};

			class Countour
			{
			  public:
            static std::string Set(CountourValue value);
			static std::string Read(CountourType);
            static CountourValue Answer(std::string data);
			};
			
			class CWSpot
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
	
			class CTCSS
			{
			  public:
			static std::string Set(CTCSSType value);
			static std::string Read();
			static CTCSSType Answer(std::string data);
			};
						
			struct DimmerValue
			{
				int LED;
				int TFT;
			};

			class DIMMER
			{
			  public:
			static std::string Set(DimmerValue value);
			static std::string Read();
			static DimmerValue Answer(std::string data);
			};
			
			class MIC_DWN
			{
			  public:
			static std::string Set();
			};

			class DateAndTime
			{
			  public:
            static std::string Set(DateTimeValue value);
			static std::string Read(DateTimeType);
            static DateTimeValue Answer(std::string data);
			};
			
			struct EncoderValue 
			{
				EncoderType Type;
				int Steps;
			};

			class EncoderDown
			{
			  public:
			static std::string Set(EncoderValue value);
			};
			
			class ENT_KEY
			{
				public:
			static std::string Set();
			};

			class EncoderUp
			{
				public:
                static std::string Set(EncoderValue value);
            };

			class Menu
			{
				public:
				class AGC_FAST_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class AGC_MID_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class AGC_SLOW_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class HOME_FUNCTION
				{
				  public:
                static std::string Set(HomeFunction value);
				static std::string Read();
                static HomeFunction Answer(std::string data);
				};
				
				class MY_CALL_INDICATION
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class DISPLAY_COLOR
				{
				  public:
				static std::string Set(DisplayColorType value);
				static std::string Read();
				static DisplayColorType Answer(std::string data);
				};
				
				class DIMMER_LED
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class DIMMER_TFT
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

				class BAR_MTR_PEAK_HOLD
				{
				  public:
				static std::string Set(MeterHoldType value);
				static std::string Read();
				static MeterHoldType Answer(std::string data);
				};
				
				class DVS_RX_OUT_LEVEL
				{
				  public:
                static std::string Set(int value);
				static std::string Read();
                static int Answer(std::string data);
				};
				
				class DVS_TX_OUT_LEVEL
				{
				  public:
                static std::string Set(int value);
				static std::string Read();
                static int Answer(std::string data);
				};
				
				class KEYER_TYPE
				{
				  public:
				static std::string Set(KeyerType value);
				static std::string Read();
				static KeyerType Answer(std::string data);
				};
				
				class KEYER_DOTDASH
				{
				  public:
				static std::string Set(KeyerDotDashType value);
				static std::string Read();
				static KeyerDotDashType Answer(std::string data);
				};
				
				class CW_WEIGHT
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class BEACON_INTERVAL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class NUMBER_STYLE
				{
				  public:
				static std::string Set(NumberStyleType value);
				static std::string Read();
				static NumberStyleType Answer(std::string data);
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
				static std::string Set(CwMemoryType value);
				static std::string Read();
				static CwMemoryType Answer(std::string data);
				};
				
				class CW_MEMORY_2
				{
				  public:
				static std::string Set(CwMemoryType value);
				static std::string Read();
				static CwMemoryType Answer(std::string data);
				};

				class CW_MEMORY_3
				{
				  public:
				static std::string Set(CwMemoryType value);
				static std::string Read();
				static CwMemoryType Answer(std::string data);
				};

				class CW_MEMORY_4
				{
				  public:
				static std::string Set(CwMemoryType value);
				static std::string Read();
				static CwMemoryType Answer(std::string data);
				};

				class CW_MEMORY_5
				{
				  public:
				static std::string Set(CwMemoryType value);
				static std::string Read();
				static CwMemoryType Answer(std::string data);
				};

				class NB_WIDTH
				{
				  public:
				static std::string Set(NbWidthType value);
				static std::string Read();
				static NbWidthType Answer(std::string data);
				};
				


				class NB_REJECTION
				{
				  public:
				static std::string Set(NBRejectionType value);
				static std::string Read();
				static NBRejectionType Answer(std::string data);
				};
				
				class NB_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class BEEP_LEVEL
				{
				  public:
                static std::string Set(int value);
				static std::string Read();
                static int Answer(std::string data);
				};
				
				class TIME_ZONE
				{
				  public:
				static std::string Set(std::string value);
				static std::string Read();
				static std::string Answer(std::string data);
				};
				


				class GPS_RS232_SELECT
				{
				  public:
				static std::string Set(GpsSelectType value);
				static std::string Read();
				static GpsSelectType Answer(std::string data);
				};
				
				class RS232_RATE
				{
				  public:
				static std::string Set(CatRate value);
				static std::string Read();
				static CatRate Answer(std::string data);
				};
				
				class RS232_TOT
				{
				  public:
				static std::string Set(CatTOT value);
				static std::string Read();
				static CatTOT Answer(std::string data);
				};
				
				class CAT_RATE
				{
				  public:
				static std::string Set(CatRate value);
				static std::string Read();
				static CatRate Answer(std::string data);
				};
				
				class CAT_TOT
				{
				  public:
				static std::string Set(CatTOT value);
				static std::string Read();
				static CatTOT Answer(std::string data);
				};
				
				class CAT_RTS
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
				
				class TX_TOT
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
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
				static std::string Set(MicScanResumeValue value);
				static std::string Read();
				static MicScanResumeValue Answer(std::string data);
				};
				
				class REF_FREQ_ADJ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				

				class CLAR_MODE_SELECT
				{
				  public:
				static std::string Set(ClarModeType value);
				static std::string Read();
				static ClarModeType Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
				};
				
				class AM_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class AM_PTT_SELECT
				{
				  public:
				static std::string Set(PTTSelectValue value);
				static std::string Read();
				static PTTSelectValue Answer(std::string data);
				};
				
				class AM_PORT_SELECT
				{
				  public:
				static std::string Set(RearSelect value);
				static std::string Read();
				static RearSelect Answer(std::string data);
				};
				
				class AM_DATA_GAIN
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
				};
				
				class CW_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

				class CW_AUTO_MODE
				{
				  public:
				static std::string Set(CWAutoModeType value);
				static std::string Read();
				static CWAutoModeType Answer(std::string data);
				};
				

				class CW_BK_IN_TYPE
				{
				  public:
				static std::string Set(CwBreakInType value);
				static std::string Read();
				static CwBreakInType Answer(std::string data);
				};
				
				class CW_BK_IN_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
			
				class CW_WAVE_SHAPE
				{
				  public:
				static std::string Set(CWWaveShapeValue value);
				static std::string Read();
				static CWWaveShapeValue Answer(std::string data);
				};
				
				class CW_FREQ_DISPLAY
				{
				  public:
                static std::string Set(CWFreqDisplayValue value);
				static std::string Read();
                static CWFreqDisplayValue Answer(std::string data);
				};
				
				class PC_KEYING
				{
				  public:
				static std::string Set(PCKeyingValue value);
				static std::string Read();
				static PCKeyingValue Answer(std::string data);
				};
				
				class QSK_DELAY_TIME
				{
				  public:
				static std::string Set(QskDelayTimeValue value);
				static std::string Read();
				static QskDelayTimeValue Answer(std::string data);
				};
				
				class DATA_MODE
				{
				  public:
				static std::string Set(DataMode value);
				static std::string Read();
				static DataMode Answer(std::string data);
				};

				class PSK_TONE
				{
				  public:
                static std::string Set(PSKToneValue value);
				static std::string Read();
                static PSKToneValue Answer(std::string data);
				};
				
				class OTHER_DISP
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class OTHER_SHIFT
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class DATA_LCUT_FREQ
				{
				  public:
				static std::string Set(FreqLowCutValue value);
				static std::string Read();
				static FreqLowCutValue Answer(std::string data);
				};
				
				class DATA_LCUT_SLOPE
				{
				  public:
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
				};
				
				class DATA_HCUT_FREQ
				{
				  public:
				static std::string Set(FreqHighCutValue value);
				static std::string Read();
				static FreqHighCutValue Answer(std::string data);
				};
				
				class DATA_HCUT_SLOPE
				{
				  public:
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
				};
			
				class DATA_IN_SELECT
				{
				  public:
				static std::string Set( ModulationSource value);
				static std::string Read();
				static ModulationSource Answer(std::string data);
				};

				class DATA_PTT_SELECT
				{
				  public:
				static std::string Set(PTTSelectValue value);
				static std::string Read();
				static PTTSelectValue Answer(std::string data);
				};
				
				class DATA_PORT_SELECT
				{
				  public:
				static std::string Set(RearSelect value);
				static std::string Read();
				static RearSelect Answer(std::string data);
				};
				
				class DATA_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class FM_MIC_SELECT
				{
				  public:
				static std::string Set(ModulationSource value);
				static std::string Read();
				static ModulationSource Answer(std::string data);
				};
				
				class FM_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				
				class FM_PKT_PTT_SELECT
				{
				  public:
				static std::string Set(PTTSelectValue value);
				static std::string Read();
				static PTTSelectValue Answer(std::string data);
				};
				
				class FM_PKT_PORT_SELECT
				{
				  public:
				static std::string Set(RearSelect value);
				static std::string Read();
				static RearSelect Answer(std::string data);
				};
				
				
				class FM_PKT_TX_GAIN
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				

				class FM_PKT_MODE
				{
				  public:
				static std::string Set(PKTMode value);
				static std::string Read();
				static PKTMode Answer(std::string data);
				};

				class RPT_SHIFT_28MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

				class RPT_SHIFT_50MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

				class RPT_SHIFT_144MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class RPT_SHIFT_430MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class ARS_144MHZ
				{
				  public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
				};
				
				class ARS_430MHZ
				{
				  public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
				};
			
				class DCS_POLARITY
				{
				  public:
				static std::string Set(DCSPolarityValue value);
				static std::string Read();
				static DCSPolarityValue Answer(std::string data);
				};
				
				class RADIO_ID
				{
				  public:				
				static std::string Read();
				static std::string Answer(std::string data);
				};
				
				class GM_DISPLAY
				{
				  public:
				static std::string Set(GMDisplayType value);
				static std::string Read();
				static GMDisplayType Answer(std::string data);
				};
							
				class DISTANCE
				{
				  public:
				static std::string Set(DistanceType value);
				static std::string Read();
				static DistanceType Answer(std::string data);
				};
				
				class AMS_TX_MODE
				{
				  public:
				static std::string Set(AMSTxModeValue value);
				static std::string Read();
				static AMSTxModeValue Answer(std::string data);
				};
				
				class STANDBY_BEEP
				{
				  public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
				};
				
				class RTTY_SHIFT_PORT
				{
				  public:
				static std::string Set(ShiftPortValue value);
				static std::string Read();
				static ShiftPortValue Answer(std::string data);
				};
				
				class RTTY_POLARITY_RX
				{
				  public:
				static std::string Set(RTTYPolarityValue value);
				static std::string Read();
				static RTTYPolarityValue Answer(std::string data);
				};
				
				class RTTY_POLARITY_TX
				{
				  public:
				static std::string Set(RTTYPolarityValue value);
				static std::string Read();
				static RTTYPolarityValue Answer(std::string data);
				};
				
				class RTTY_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class RTTY_SHIFT_FREQ
				{
				  public:
				static std::string Set(RTTYShiftFreqValue value);
				static std::string Read();
				static RTTYShiftFreqValue Answer(std::string data);
				};
				
				class RTTY_MARK_FREQ
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
				static std::string Set(FreqSlopeValue value);
				static std::string Read();
				static FreqSlopeValue Answer(std::string data);
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
					static std::string Set(FreqSlopeValue);
					static std::string Read();
					static FreqSlopeValue Answer(std::string data);
				};

				class SSB_MIC_SELECT
				{
				  public:
				static std::string Set(ModulationSource value);
				static std::string Read();
				static ModulationSource Answer(std::string data);
				};
				
				class SSB_OUT_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class SSB_PTT_SELECT
				{
				  public:
				static std::string Set(PTTSelectValue value);
				static std::string Read();
				static PTTSelectValue Answer(std::string data);
				};
				
				class SSB_PORT_SELECT
				{
				  public:
				static std::string Set(RearSelect value);
				static std::string Read();
				static RearSelect Answer(std::string data);
				};
				class SSB_TX_BPF
				{
				  public:
				static std::string Set(SSBTXBandPassValue value);
				static std::string Read();
				static SSBTXBandPassValue Answer(std::string data);
				};
				
				class APF_WIDTH
				{
				  public:
				static std::string Set(APFWidthValue value);
				static std::string Read();
				static APFWidthValue Answer(std::string data);
				};
				
				class COUNTOUR_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class COUNTOUR_WIDTH
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
		
				class IF_NOTCH_WIDTH
				{
				  public:
				static std::string Set(IFNotchWidth value);
				static std::string Read();
				static IFNotchWidth Answer(std::string data);
				};
				
				class SCP_DISPLAY_MODE
				{
				  public:
				static std::string Set(ScopeDisplayMode value);
				static std::string Read();
				static ScopeDisplayMode Answer(std::string data);
				};
				
				class SCP_SPAN_FREQ
				{
				  public:
				static std::string Set(ScopeSpan value);
				static std::string Read();
				static ScopeSpan Answer(std::string data);
				};
				
				class SPECTRUM_COLOR
				{
				  public:
				static std::string Set(SpectrumColor value);
				static std::string Read();
				static SpectrumColor Answer(std::string data);
				};
				
				class WATERFALL_COLOR
				{
				  public:
				static std::string Set(WaterfallColor value);
				static std::string Read();
				static WaterfallColor Answer(std::string data);
				};
				
				class PRMTRC_EQ1_FREQ
				{
				  public:
				static std::string Set(EQ1FreqValue value);
				static std::string Read();
				static EQ1FreqValue Answer(std::string data);
				};
				
				class PRMTRC_EQ1_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class PRMTRC_EQ1_BWTH
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class PRMTRC_EQ2_FREQ
				{
				  public:
				static std::string Set(EQ2FreqValue value);
				static std::string Read();
				static EQ2FreqValue Answer(std::string data);
				};
				
                class PRMTRC_EQ2_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
                class PRMTRC_EQ2_BWTH
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
                class PRMTRC_EQ3_FREQ
				{
				  public:
				static std::string Set(EQ3FreqValue value);
				static std::string Read();
				static EQ3FreqValue Answer(std::string data);
				};
				
                class PRMTRC_EQ3_LEVEL
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
                class PRMTRC_EQ3_BWTH
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

			
				class P_PRMTRC_EQ1_FREQ
				{
				public:
					static std::string Set(EQ1FreqValue value);
					static std::string Read();
					static EQ1FreqValue Answer(std::string data);
				};

				class P_PRMTRC_EQ1_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class P_PRMTRC_EQ1_BWTH
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class P_PRMTRC_EQ2_FREQ
				{
				public:
					static std::string Set(EQ2FreqValue value);
					static std::string Read();
					static EQ2FreqValue Answer(std::string data);
				};

				class P_PRMTRC_EQ2_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class P_PRMTRC_EQ2_BWTH
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class P_PRMTRC_EQ3_FREQ
				{
				public:
					static std::string Set(EQ3FreqValue value);
					static std::string Read();
					static EQ3FreqValue Answer(std::string data);
				};

				class P_PRMTRC_EQ3_LEVEL
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};

				class P_PRMTRC_EQ3_BWTH
				{
				public:
					static std::string Set(int value);
					static std::string Read();
					static int Answer(std::string data);
				};


				class TX_MAX_POWER_HF
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				
				class TX_MAX_POWER_50MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class TX_MAX_POWER_144MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class TX_MAX_POWER_430MHZ
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};

				class TUNER_SELECT
				{
				  public:
				static std::string Set(TunerSelectValue value);
				static std::string Read();
				static TunerSelectValue Answer(std::string data);
				};
			
				class VOX_SELECT
				{
				  public:
				static std::string Set(VoxSelectValue value);
				static std::string Read();
				static VoxSelectValue Answer(std::string data);
				};
				
				class VOX_GAIN
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class VOX_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class ANTI_VOX_GAIN
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
				
				class DATA_VOX_DELAY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class ANTI_DVOX_GAIN
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				
				class EMERGENCY_FREQ_TX
				{
				  public:
				static std::string Set(EnableDisableValue value);
				static std::string Read();
				static EnableDisableValue Answer(std::string data);
				};
				
				class PRT_WIRES_FREQ
				{
				  public:
				static std::string Set(WiresFreqencyType value);
				static std::string Read();
				static WiresFreqencyType Answer(std::string data);
				};
				
				class PRESET_FREQUENCY
				{
				  public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
				};
				
				class SEARCH_SETUP
				{
				  public:
				static std::string Set(SearchSetupType value);
				static std::string Read();
				static SearchSetupType Answer(std::string data);
				};
				
				class WIRES_DG_ID
				{
				  public:
				static std::string Set(WiresDGID value);
				static std::string Read();
				static WiresDGID Answer(std::string data);
				};
									
			}; //end Menu

			class FrequencyVFOA
			{
				public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};
			
			class FrequencyVFOB
			{
				public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FastStep
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			enum class FunctionTxValue
			{
				VFOA,
				VFOB
			};

			class FunctionTX
			{
			  public:
			static std::string Set(FunctionTxValue value);
			static std::string Read();
			static FunctionTxValue Answer(std::string data);
			};
			
			class AGCFunction
			{
			  public:
			static std::string Set(FT991A::AGCSetValue value);
			static std::string Read();
			static FT991A::AGCStateValue Answer(std::string data);
			};

		    class Information
			 {
			   public:
			 
			 static std::string Read();
			 static InformationValue Answer(std::string data);
			 };
			
			class IF_Shift
			 {
			   public:
			 static std::string Set(int value);
			 static std::string Read();
			 static int Answer(std::string data);
			 };
			
			class KeyerMemory
			 {
			   public:
			 static std::string Set(KeyerMemoryValue value);
			 static std::string Read(KeyerMemoryChannel);
			 static KeyerMemoryValue Answer(std::string data);
			 };
			
			class KeyPitch
			 {
			   public:
			 static std::string Set(KeyPitchValue value);
			 static std::string Read();
			 static KeyPitchValue Answer(std::string data);
			 };
			
			class Keyer
			 {
			   public:
			 static std::string Set(OnOffValue value);
			 static std::string Read();
			 static OnOffValue Answer(std::string data);
			 };

			class KeySpeed
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class CWKeying
			{
			  public:
			static std::string Set(CWKeyingPlaybackValue value);
	
			};
			
			class Lock
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class LoadMessage
			{
			  public:
			static std::string Set(DVSRecordingValue value);
			static std::string Read();
			static DVSRecordingValue Answer(std::string data);
			};
			
			class MemoryChannel_To_VFOA
			{
			  public:
			static std::string Set();
			};

			class MemoryChannel
			{
			  public:
			static std::string Set(MemoryChannelValue value);
			static std::string Read();
			static MemoryChannelValue Answer(std::string data);
			};
			
			class OperatingMode
			{
			  public:
			static std::string Set(ModeValue value);
			static std::string Read();
			static ModeValue Answer(std::string data);
			};
			
			class MicGain
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class MonitorLevel
			{
			  public:
			static std::string Set(MonitorLevelValue value);
			static std::string Read(MonitorFunction);
			static MonitorLevelValue Answer(std::string data);
			};
			
			class MemoryChannelRead
			{
			  public:
			
			static std::string Read(MemoryChannelValue val);
			static MemoryChannelTag Answer(std::string data);
			};
			
			class MeterSW
			{
			  public:
			static std::string Set(MeterType value);
			static std::string Read();
			static MeterType Answer(std::string data);
			};
			
			class MemoryChannelWriteTag
			{
			  public:
			static std::string Set(MemoryChannelTag value);
			static std::string Read(MemoryChannelValue);
			static MemoryChannelTag Answer(std::string data);
			};
			
			class MemoryChannelWrite
			{
			  public:
			static std::string Set(MemoryChannelTag value);

			};
			
			class MoxSet
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class Narrow
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class NoiseBlankerStatus
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class NoiseBlankerLevel
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class NoiseReduction
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class OppisateBandInformation
			{
			  public:
			
			static std::string Read();
			static OppositeInformationValue Answer(std::string data);
			};
			
			class Offset
			{
			  public:
			static std::string Set(OperationType value);
			static std::string Read();
			static OperationType Answer(std::string data);
			};
			
			class PreAmp
			{
			  public:
			static std::string Set(FT991A::PreampType value);
			static std::string Read();
			static PreampType Answer(std::string data);
			};
			
			class PlayBack
			{
			  public:
			static std::string Set(DVSRecordingValue value);
			static std::string Read();
			static DVSRecordingValue Answer(std::string data);
			};
			
			class PowerControl
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class SpeechProcessorLevel
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};

			struct SpeechProcessorSetting
			{
				SpeechProcessorType Type;
				OnOffValue State;
			};

			class SpeechProcessor
			{
			  public:
			static std::string Set(SpeechProcessorSetting value);
			static std::string Read(SpeechProcessorType);
			static SpeechProcessorSetting Answer(std::string data);
			};
			
			class PowerSwitch
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class QMB_Store
			{
				public:
				static std::string Set();
			};

			class QMB_Recall
			{
				public:
				static std::string Set();
			};

			class QuickSplit
			{
				public:
				static std::string Set();
			};

			class RFAttenuator
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class ClarClear
			{
			  public:
			static std::string Set();
			};
			
			class ClarDown
			{
			  public:
			static std::string Set(int value);
			};
			
			class RFGain
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			enum class RadioInformationType : int
			{
				HIGH_SWR = 0,
				REC = 3,
				PLAY,
				VFO_A_TX,
				VFO_B_TX,
				VFO_A_RX,
				TX_LED = 10
			};

			struct RadioInformationValue 
			{
				RadioInformationType Type;
				OnOffValue State;
			};

			class RadioInformation
			{
			  public:
			
			static std::string Read(RadioInformationType type);
			static RadioInformationValue Answer(std::string data);
			};
			
			class NoiseReductionLevel	
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			enum class ReadMeterType : int
			{
				FrontPanelMeterDep,
				S,
				FrontPanelMeterDependancy,
				COMP,
				ALC,
				PO,
				SWR,
				ID,
				VDD
			};

			struct ReadMeterValue 
			{
				ReadMeterType Type;
				int Value;
			};

			class ReadMeter
			{
			  public:
			
			static std::string Read(ReadMeterType);
			static ReadMeterValue Answer(std::string data);
			};

			enum class RadioStatusType : int
			{
				NORMAL,
				MENU
			};

			class RadioStatus
			{
			  public:
			
			static std::string Read();
			static RadioStatusType Answer(std::string data);
			};
			
			class RXClarifier
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class RXClarifierPlusOffset
			{
			  public:
			static std::string Set(int value);
			
			};
			
			enum class ScanType : int
			{
				OFF,
				UP,
				DOWN
			};

			class Scan
			{
			  public:
			static std::string Set(ScanType value);
			static std::string Read();
			static ScanType Answer(std::string data);
			};
			
			class Width
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class SMeterReading
			{
			  public:
			
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class SquelchLevel
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class SwapVFO
			{
			  public:
			static std::string Set();
			
			};

			class TXW
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			enum class TXSetType : int
			{
				RadioTxOff_CatTxOff,
				RadioTxOff_CatTxOn,
				RadioTxOn_CatTxOff
			};

			class TXSet
			{
			  public:
			static std::string Set(TXSetType value);
			static std::string Read();
			static TXSetType Answer(std::string data);
			};
			
			enum class PLLLockType : int
			{
				LOCKED,
				UNLOCKED	
			};

			class PLLUnlockStatus
			{
			  public:
				
			static std::string Read();
			static PLLLockType Answer(std::string data);
			};
			
			class UP
			{
			  public:
			static std::string Set();
			
			};

			class VoxDelayTime
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class VoxGain
			{
			  public:
			static std::string Set(int value);
			static std::string Read();
			static int Answer(std::string data);
			};
			
			class VFOA_To_Memory
			{
			  public:
			static std::string Set();
			};
			
			class VoxStatus
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class TXClarifier
			{
			  public:
			static std::string Set(OnOffValue value);
			static std::string Read();
			static OnOffValue Answer(std::string data);
			};
			
			class ZeroIn
			{
			  public:
			static std::string Set();
			};
			
		};

		namespace FTDX101
		{
			enum class CommandType : int
			{				
				AC_AntennaTunerControl,
				AG_AF_Gain,
				AI_AutoInformation,				
				AN_AntennaNumber,
				AO_AMC_OutputLevel,
				BC_AutoNotch,
				BI_BreakIn,
				BP_ManualNotch,				
				BY_Busy,
				CN_CTCSS_DCS_Number,
				CO_Contour,
				CS_CW_Spot,
				CT_CTCSS,
				DA_Dimmer,
				DT_DateAndTime,
				EM_EncodeMemory,
				EX_Menu,
				FA_FrequencyMain,
				FB_FrequencySub,
				FN_FineTuning,
				FR_FunctionRX,
				FS_FastStep,
				FT_FunctionTX,
				GT_AGCFunction,
				ID_Identification,
				IF_Information,
				IS_IF_Shift,
				KM_KeyerMemory,
				KP_KeyerPitch,
				KR_Keyer,
				KS_KeySpeed,
				LK_Lock,
				LM_LoadMessage,
				MC_MemoryChannel,
				MD_Mode,
				MG_MicGain,
				ML_MonitorLevel,
				MR_MemoryRead,
				MS_MeterSwitch,
				MT_MemoryChannelWriteTag,
				MW_MemoryChannelWrite,
				MX_MoxSet,
				NA_Narrow,
				NB_NoiseBlanker,
				NL_NoiseBlankerLevel,
				NR_NoiseReduction,
				OI_OppositeBandInformation,
				OS_RepeaterOffset,
				PA_Preamp_IPO,
				PB_PlayBack,
				PC_PowerControl,
				PL_SpeechProceesorLevel,
				PR_SpeechProcessor,
				PS_PowerSwitch,
				RA_RFAttenuator,
				RF_RoofingFilter,
				RG_RFGain,
				RI_RadioInformation,
				RL_NoiseReductionLevel,
				RM_ReadMeter,
				RS_RadioStatus,
				RT_Clar,
				SC_Scan,
				SD_SemiBreakInDelay,
				SF_SubDial,
				SH_Width,
				SM_SMeter,
				SQ_SquelchLevel,
				ST_Split,
				SS_SpectrumScope,
				SY_Sync,
				TX_TxSet,
				UL_Unlock,
				VD_VoxDealyTime,
				VG_VoxGain,
				VS_VFOSelect,
				VT_VCT_VCTune,
				VX_VOX,
				XT_TXClar,
				Unknown
			};

            enum class PolarityValue : int
            {
                NOR,
                REV
            };

			using Yaesu::Common::RTTYPolarityValue;

			enum class MainSubValue : int
			{
				MAIN,
				SUB
			};

			enum class AntennaNumberSelection : int
			{
				ANT1 = 1,
				ANT2,
				ANT3
			};

			enum class TunerState : int
			{
				OFF,
				ON,
				StartStop
			};

			enum class InformationState : int
			{
				OFF,
				ON
			};

			using Yaesu::Common::OnOffValue;
			
			using Yaesu::Common::EnableDisableValue;

			using Yaesu::Common::UpDownValue;

			enum class ManualNotchValueType : int
			{
				State,
				Level
			};

			enum class BandSelectValue : int
			{
				_160M,
				_80M,
				_60M,
				_40M,
				_30M,
				_20M,
				_17M,
				_15M,
				_12M,
				_10M,
				_6M,
				GEN,
				MW,
				_4M = 17
			};

			enum class ContourRequestType
			{
				OnOffState,
				Frequency,
				APF_OnOff,
				APF_Frequency
			};

			enum class CTCSSType : int
			{
				OFF,
				ENC_DEC,
				ENC
			};

			enum class DateTimeType : int
			{
				DATE,
				TIME
			};

			enum class EncoderType : int
			{
				MAIN,
				MPVD,
				MIC_SPEED,
				PROC_PITCH,
				MAIN_NOTCH,
				MAIN_CONT,
				SUB_NOTCH,
				SUB_CONT,
				MULTI
			};

			enum class EncodeFormat
			{
				RTTY,
				DATA
			};

			enum class ClarifierType : int
			{
				Setting,
				Frequency
			};

			enum class MenuGroup : int
			{
				RadioSettings = 1,
				CWSettings,
				OperationSetting,
				DisplaySetting,
				ExtensionSetting
			};

			enum class RadioSettingsType : int
			{
				ModeSSB = 1,
				ModeAM,
				ModeFM,
				ModePSK_Data,
				ModeRTTY,
				ENC_DEC_PSK,
				ENC_DEC_RTTY
			};

			enum class SSBSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				REAR_SELECT,
				RPORT_GAIN,
				RPPT_SELECT
			};

			enum class AMSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				MicGain,
				REAR_SELECT,
				RPORT_GAIN,
				RPPT_SELECT
			};

			enum class FMSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				MOD_SOURCE,
				MicGain,
				REAR_SELECT,
				RPORT_GAIN,
				RPPT_SELECT,
				RPT_SHIFT_28,
				RPT_SHIFT_50
			};

			enum class PSKDataSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				DATA_MODE,
				OTHER_SHIFT,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				REAR_SELECT,
				RPORT_GAIN,
				RPPT_SELECT
			};

			enum class RTTYSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				POLARITY_RX,
				POLARITY_TX,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				SHIFT_PORT,
				MARK_FREQUENCY,
				SHIFT_FREQUENCY
			};

			enum class CWSettingsType : int
			{
				ModeCW = 1,
				Keyer,
				Decode_CW
			};

			enum class ModeCWSettings : int
			{
				AGC_FAST_DELAY = 1,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				OUT_SELECT,
				OUT_LEVEL,
				AUTO_MODE,
				BKIN_TYPE,
				BKIN_DELAY,
				WAVE_SHAPE,
				FREQ_DISPLAY,
				PC_KEYING,
				QSK_DELAY_TIME,
				INDICATOR
			};

			enum class BreakInType : int
			{
				SEMI,
				FULL
			};

			enum class AutoModeValue : int
			{
				OFF,
				_50Mhz,
				ON
			};

			enum class WaveShapeValue : int
			{
				_1msec,
				_2msec,
				_4msec,
				_6msec
			};

			enum class FreqDisplayValue : int
			{
				DIRECT_FREQ,
				PITCH_OFFSET
			};

			enum class PCKeyingValue : int
			{
				OFF,
				DKAY,
				RTS,
				DTR
			};

			enum class QSKDelayTime : int
			{
				_15msec,
				_20msec,
				_25msec,
				_30msec
			};

			enum class KeyerSettings : int
			{
				F_KEYER_TYPE,
				F_KEYER_DOTDASH,
				R_KEYER_TYPE,
				R_KEYER_DOTDASH,
				WEIGHT,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				MEMORY_1,
				MEMORY_2,
				MEMORY_3,
				MEMORY_4,
				MEMORY_5,
				REPEAT_INTERVAL
			};

			enum class DecodeCWSettings : int
			{
				DECODE_BW
			};

			enum class OperationSettingType : int
			{
				General = 1,
				RX_DSP,
				TX_Audio,
				TX_General,
				Tuning
			};

			enum class DisplaySettingType : int
			{
				Display = 1,
				Scope,
				Ext_Monitor
			};

			enum class ExtensionSettingType : int
			{
				DateTime,
				SDCard,
				SOFT_VERSION,
				CALIBRATION,
				Reset
			};

			using Yaesu::Common::FreqHighCutValue;

			using Yaesu::Common::FreqLowCutValue;

			using Yaesu::Common::SlopeValue;
			
			enum class TXBandPassValue : int
			{
				_50_3050,
				_100_2900,
				_200_2800,
				_300_2700,
				_400_2600
			};

			enum class ModulationSource : int
			{
				MIC,
				REAR
			};

			enum class RearSelect : int
			{
				DATA,
				USB
			};

			enum class RPTTSelectValue : int
			{
				DAKY,
				RTS,
				DTR
			};

			enum class DataMode : int
			{
				PSK,
				OTHERS
			};

			enum class RTTYShiftPortValue : int
			{
				SHIFT,
				DTR,
				RTS
			};

			using Yaesu::Common::RTTYShiftFreqValue;

			using Yaesu::Common::RTTYMarkFreq;

			enum EncDecPskSettings : int
			{
				PSK_MODE,
				DECODE_AFC_RANGE,
				POLARITY_RX,
				POLARITY_TX,
				TX_LEVEL
			};

			enum EncDecRTTYSettings : int
			{
				RX_USOS,
				TX_USOS,
				RX_NEW_LINE,
				TX_AUTO_CR_LF,
				TX_DIDDLE,
				BAUDOT_COODE
			};

			enum PSKModeValue : int
			{
				BPSK,
				QPSK
			};

			enum DecodeAfcRangeValue
			{
				_8,
				_1_5,
				_30
			};

			enum class TXDiddleValue : int
			{
				OFF,
				BLANK,
				LTRS
			};

			using Yaesu::Common::BaudotCodeStandard;
			
			enum class NewLineCode : int
			{
				CR_or_CF_or_CRLF,
				CR_LF_CRLF
			};

			enum class KeyerType : int
			{
				OFF,
				BUG,
				ELEKEY_A,
				ELEKEY_B,
				ELEKEY_Y,
				ACS
			};

			enum class DotDashType : int
			{
				NOR,
				REV
			};

			using Yaesu::Common::NumberStyle;


			enum class CWMemoryType : int
			{
				TEXT,
				MESSAGE
			};

			enum class CWDecodeBW : int
			{
				_25,
				_50,
				_100,
				_250
			};

			enum class HeadPhoneMixValue : int
			{
				SEPARATE,
				COMBINE_1,
				COMBINE_2
			};

			enum class ANT3Selection : int
			{
				TRX,
				RX
			};

			enum class NBWidth : int
			{
				_1ms,
				_3ms,
				_10ms
			};

			enum class NBRejectionValue : int
			{
				_10db,
				_30db,
				_50db
			};

			enum class VRType : int
			{
				RF,
				SQL
			};

			enum class TunerRS232Select : int
			{
				TUNER,
				RS232C
			};

			enum class RS232CRate : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum class RS232CTimeOutValue : int
			{
				_10ms,
				_100ms,
				_1000ms,
				_3000ms
			};

			enum CATRateValue : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum CATTimeOutValue : int
			{
				_10ms,
				_100ms,
				_1000ms,
				_3000ms
			};

			enum class CATRtsValue : int
			{
				DISABLE,
				ENABLE
			};

			enum class QMBChValue : int
			{
				_5ch,
				_10ch
			};
			using Yaesu::Common::MicScanResumeType;
			

			enum class SubDialKnob : int
			{
				MPVD,
				MULTI
			};

			enum class CSDialType : int
			{
				RF_POWER,
				MONI_LEVEL,
				DNR_LEVEL,
				NB_LEVEL,
				VOX_GAIN,
				VOX_DELAY,
				ANTI_VOX,
				STEP_DIAL,
				MEM_CH,
				GROUP,
				R_FIL
			};

			enum class KeyboardLangaugeValue : int
			{
				JAPANESE,
				ENGLISH_US,
				ENGLISH_UK,
				FRENCH,
				FRENCH_CA,
				GERMAN,
				PORTUGUESE,
				PORTUGUESE_BR,
				SPANISH,
				SPANISH_LATAM,
				ITALIAN
			};

			using Yaesu::Common::APFWidthValue;

			using Yaesu::Common::IFNotchWidth;

			enum class ProcType : int
			{
				COMP,
				AMC
			};

			enum class AMCReleaseTime : int
			{
				FAST,
				MID,
				SLOW
			};

			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;

			enum class GeneralSettings : int
			{
				DECODE_RX_SELECT = 1,
				HEADPHONE_MIX,
				ANT3_SELECT,
				NB_WIDTH,
				NB_REJECTION,
				BEEP_LEVEL,
				RFSQL_VR,
				TUNER_RS232_SELECT,
				RS232C_RATE,
				RS232C_TIME_OUT,
				CAT_RATE,
				CAT_TIMEOUT,
				CAT_RTS,
				QMB_CH,
				MEM_GROUP,
				QUICK_SPLIT_INPUT,
				QUICK_SPLIT_FREQ,
				TX_TIME_OUT_TIMER,
				MIC_SCAN,
				MIC_SCAN_RESUME,
				REF_FREQ_ADJ,
				CS_DIAL,
				KEYBOARD_LANGUAGE
			};

			enum class RX_DSPSettings : int
			{
				APF_WIDTH = 1,
				CONTOUR_LEVEL,
				CONTOUR_WIDTH,
				DNR_LEVEL,
				IF_NOTCH_WIDTH,

			};

			enum class TXAudioSettings : int
			{
				PROC_TYPE = 1,
				AMC_RELEASE_TIME,
				EQ1_FREQ,
				EQ1_LEVEL,
				EQ1_BWDTH,
				EQ2_FREQ,
				EQ2_LEVEL,
				EQ2_BWDTH,
				EQ3_FREQ,
				EQ3_LEVEL,
				EQ3_BWDTH,
				PEQ1_FREQ,
				PEQ1_LEVEL,
				PEQ1_BWDTH,
				PEQ2_FREQ,
				PEQ2_LEVEL,
				PEQ2_BWDTH,
				PEQ3_FREQ,
				PEQ3_LEVEL,
				PEQ3_BWDTH
			};

			enum class TXGeneralSettings : int
			{
				MAX_POWER_HF = 1,
				MAX_POWER_50M,
				MAX_POWER_70M,
				MAX_POWER_AM,
				VOX_SELECT,
				DATA_VOX_GAIN,
				EMERGENCY_FREQ_TX
			};

			enum class TuningSettings : int
			{
				SSB_CW_DIAL_STEP = 1,
				RTTY_PSK_DIAL_STEP,
				CH_STEP,
				AM_CH_STEP,
				FM_CH_STEP,
				MAIN_STEPS_PER_REV,
				MPVD_STEPS_PER_REV
			};

			enum class CallSignTime : int
			{
				OFF,
				_0_5s,
				_1s,
				_2s,
				_3s,
				_5s
			};

			enum class MemoryChannelValue
			{
				_1 = 1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				P1L,
				P1U,
				P2L,
				P2U,
				P3L,
				P3U,
				P4L,
				P4U,
				P5L,
				P5U,
				P6L,
				P6U,
				P7L,
				P7U,
				P8L,
				P8U,
				P9L,
				P9U,
				_5351_5mhz = 501,
				_5354mhz,
				_5357mhz,
				_5360mhz,
				_5363mhz,
				_5366mhz,
				EMG = 600

			};

			enum class KeyPitchValue
			{
				_300Hz,
				_310Hz,
				_320Hz,
				_330Hz,
				_340Hz,
				_350Hz,
				_360Hz,
				_370Hz,
				_380Hz,
				_390Hz,
				_400Hz,
				_410Hz,
				_420Hz,
				_430Hz,
				_440Hz,
				_450Hz,
				_460Hz,
				_470Hz,
				_480Hz,
				_490Hz,
				_500Hz,
				_510Hz,
				_520Hz,
				_530Hz,
				_540Hz,
				_550Hz,
				_560Hz,
				_570Hz,
				_580Hz,
				_590Hz,
				_600Hz,
				_610Hz,
				_620Hz,
				_630Hz,
				_640Hz,
				_650Hz,
				_660Hz,
				_670Hz,
				_680Hz,
				_690Hz,
				_700Hz,
				_710Hz,
				_720Hz,
				_730Hz,
				_740Hz,
				_750Hz,
				_760Hz,
				_770Hz,
				_780Hz,
				_790Hz,
				_800Hz,
				_810Hz,
				_820Hz,
				_830Hz,
				_840Hz,
				_850Hz,
				_860Hz,
				_870Hz,
				_880Hz,
				_890Hz,
				_900Hz,
				_910Hz,
				_920Hz,
				_930Hz,
				_940Hz,
				_950Hz,
				_960Hz,
				_970Hz,
				_980Hz,
				_990Hz,
				_1000Hz,
				_1010Hz,
				_1020Hz,
				_1030Hz,
				_1040Hz,
				_1050Hz

			};

			enum class KeyerSpeedVal
			{
				_4wpm = 4,
				_5wpm,
				_6wpm,
				_7wpm,
				_8wpm,
				_9wpm,
				_10wpm,
				_11wpm,
				_12wpm,
				_13wpm,
				_14wpm,
				_15wpm,
				_16wpm,
				_17wpm,
				_18wpm,
				_19wpm,
				_20wpm,
				_21wpm,
				_22wpm,
				_23wpm,
				_24wpm,
				_25wpm,
				_26wpm,
				_27wpm,
				_28wpm,
				_29wpm,
				_30wpm,
				_31wpm,
				_32wpm,
				_33wpm,
				_34wpm,
				_35wpm,
				_36wpm,
				_37wpm,
				_38wpm,
				_39wpm,
				_40wpm,
				_41wpm,
				_42wpm,
				_43wpm,
				_44wpm,
				_45wpm,
				_46wpm,
				_47wpm,
				_48wpm,
				_49wpm,
				_50wpm,
				_51wpm,
				_52wpm,
				_53wpm,
				_54wpm,
				_55wpm,
				_56wpm,
				_57wpm,
				_58wpm,
				_59wpm,
				_60wpm
			};

			enum class ScreenSaverTime : int
			{
				OFF,
				_15min,
				_30min,
				_60min
			};

			enum class FREQ_STYLEValue : int
			{
				LIGHT,
				BOLD
			};

			enum class RBWValue
			{
				HIGH,
				MID,
				LOW
			};

			enum class ScopeCTRValue : int
			{
				FILTER,
				CAR_POINT
			};

			enum class ScopeSensitivityValue : int
			{
				NORMAL,
				HIGH
			};

			enum class PixelValue : int
			{
				_800x400,
				_800x600
			};

			enum class DisplaySettings : int
			{
				MY_CALL = 1,
				MY_CALL_TIME,
				SCREEN_SAVER,
				TFT_CONTRAST,
				DIMMER_TFT,
				DIMMER_LED,
				MOUSE_POINTER_SPEED,
				FREQ_STYLE
			};

			enum class ScopeSettings : int
			{
				RBW = 1,
				SCOPE_CTR,
				DISP_SENSISITIVITY_2D,
				DISP_SENSISITIVITY_3DSS
			};

			enum class EXT_MonitorSettings : int
			{
				EXT_DISPLAY = 1,
				PIXEL
			};

			enum class SSBDialStepValue : int
			{
				_5Hz,
				_10Hz
			};

			enum class RTTYPSKDialStepValue : int
			{
				_5Hz,
				_10Hz
			};

			enum class CH_StepValue : int
			{
				_1kHz,
				_2_5kHz
			};

			enum class AMCHStepValue : int
			{
				_2_5Khz,
				_5kHz,
				_9kHz,
				_10kHz,
				_12_5kHz,
				_25kHz
			};

			enum class FMCHStepValue : int
			{
				_5kHz,
				_6_25kHz,
				_10kHz,
				_12_5kHz,
				_20kHz,
				_25kHz
			};

			enum class MainStepsPerRev : int
			{
				_250,
				_500,
				_1000
			};

			enum class MPVDStepsPerRev : int
			{
				_200,
				_500
			};

			using Yaesu::Common::VoxSelectValue;

			enum class RXValue : int
			{
				RX,
				MUTE
			};

			enum class FastStepState : int
			{
				MainOFF,
				MainON,
				SubOFF,
				SubOn,
				MainOffSubOff,
				MainOnSubOff,
				MainOffSubOn,
				MainOnSubOn
			};

			enum class AGCSetValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO
			};

			enum class AGCStateValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO_FAST,
				AUTO_MID,
				AUTO_SLOW
			};

			enum class ClarifierState : int
			{
				OFF,
				ON
			};

			enum class ModeValue : int
			{
				LSB = 1,
				USB,
				CW_U,
				FM,
				AM,
				RTTY_L,
				CW_L,
				DATA_L,
				RTTY_U,
				DATA_FM,
				FM_N,
				DATA_U,
				AM_N,
				PKT,
				DATA_FM_N
			};

			enum class VFOChannelTypeValue : int
			{
				VFO,
				Memory,
				MemoryTune,
				QuckMemeoryBank,
				PMS = 5
			};

			enum class CTCSSState : int
			{
				OFF,
				CTCSS_ENC_DEC,
				CTCSS_ENC
			};

			enum class OperationType : int
			{
				Simplex,
				PlusShift,
				MinusShift
			};

			using Yaesu::Common::KeyerMemoryChannel;

			enum class LockType : int
			{
				MainDialOff,
				MainDialOn,
				SubDialOff,
				SubDialOn,
				MainDialOffSubDialOff,
				MainDialOnSubDialOff,
				MainDialOffSubDialOn,
				MainDialOnSubDialOn
			};

			enum class LoadMessageChannel : int
			{
				StopRecording,
				Channel1,
				Channel2,
				Channel3,
				Channel4,
				Channel5
			};

			enum class MonitorRequestType : int
			{
				MONITOR_ONOFF,
				MonitorLevel
			};

			enum class MainMeterType : int
			{
				POW,
				COMP,
				TEMP
			};

			enum class SubMeterType : int
			{
				ALC,
				VDD,
				ID,
				SWR
			};

			enum class PreampType
			{
				IPO,
				AMP1,
				AMP2
			};
			
			enum class DVSPlayBackMode : int
			{
				Stop,
				Channel1,
				Channel2,
				Channel3,
				Channel4,
				Channel5
			};
			
			enum class SpeechProcessorType : int
			{
				SpeechProcessor,
				ParametricMicrophoneEqualizer
			};
			
			enum class AttenuatorType : int
			{
				OFF,
				_6dB,
				_12dB,
				_18dB
			};
			
			enum class RoofingFilterType : int
			{
				_12kHz = 1,
				_3kHz,
				_1_2kHz,
				_600Hz,
				_300Hz
			};
			
			enum class RadioInformationType : int
			{
				HI_SWR,
				REC = 3,
				PLAY
			};
			
			enum class ReadMeterType : int
			{
				Both,
				S_Main,
				S_Sub,
				COMP,
				ALC,
				PO,
				SWR,
				IDD,
				VDD,
				TEMP
			};
			
			enum class RadioMode : int
			{
				Normal,
				Menu
			};

			enum class MPVDDialType : int
			{
				CLAR = 1,
				VCT,
				SUB,
				CS
			};

			enum class MULTIDialType : int
			{
				RF_POWER,
				MONI_LEVEL,
				DNR_LEVEL,
				NB_LEVEL,
				VOX_GAIN,
				VOX_DELAY,
				ANTI_VOX,
				STE_DIAL,
				MEM_CH,
				GROUP,
				R_FIL,
				SPEED,
				PEAK,
				COLOR,
				LEVEL
			};
	
			union DialType
			{
				MPVDDialType MPVD;
				MULTIDialType MULTI;
			};

			struct MonitorLevelValue
			{

				MonitorRequestType Type{};
				union Value
				{
					OnOffValue eValue;
					int iValue;
				};
				Value Value{};
			};

			struct SubDialValue
			{
				SubDialKnob Dial{};
				DialType Type{};
			};
			
			struct SpeechProcessorValue
			{
				SpeechProcessorType Type{};
				OnOffValue State{};
			};

			struct AttenuatorValue
			{
				MainSubValue Band{};
				AttenuatorType Type{};
			};

			struct RoofingFilterValue
			{
				MainSubValue Band{};
				RoofingFilterType Type{};
			};

			struct RFGainValue
			{
				MainSubValue Band{};
				int Level{};
			};

			struct RadioInformationValue
			{
				RadioInformationType Type{};
				OnOffValue State{};
			};

			struct NoiseReductionValue
			{
				MainSubValue Band{};
				OnOffValue State{};
			};

			struct NoseReductionLevelValue
			{
				MainSubValue Band{};
				int Level{};
			};

			struct ReadMeterValue
			{
				ReadMeterType Type{};
				int LeftSide{};
				int RightSide{};
			};

			struct OppositeInformation
			{
				MemoryChannelValue MemoryChannel{};
				int VFOBFreq{};
				int ClarifierFreq{};
				OnOffValue RIT{};
				OnOffValue XIT{};
				ModeValue Mode{};
				VFOChannelTypeValue VFOType{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct PreAmpValue
			{
				MainSubValue Band{};
				PreampType Value{};
			};

			struct OffsetValue
			{
				MainSubValue Band{};
				OperationType State{};
			};

			struct MeterTypeValue
			{
				MainMeterType Main{};
				SubMeterType Sub{};
			};

			struct ModeSettingValue
			{
				MainSubValue Band{};
				ModeValue Mode{};
			};

			struct KeyerMemoryValue
			{
				int ChannelNumber{};
				std::string Message{};
			};

			struct AGCSetFunction
			{
				MainSubValue Band{};
				AGCSetValue Value{};
			};

			struct AGCState
			{
				MainSubValue Band{};
				AGCStateValue Value{};
			};

			struct FunctionRXValue
			{
				RXValue Main{};
				RXValue Sub{};
			};

			struct NarrowValue
			{
				MainSubValue Band{};
				OnOffValue State{};
			};

			struct VolumeValue
			{
				MainSubValue band{};
				int VolumeLevel{};
			};

			struct AntennaNumberValue
			{
				MainSubValue band{};
				AntennaNumberSelection value{};
			};

			struct AutoNotchValue
			{
				MainSubValue band{};
				OnOffValue state{};
			};

			struct CTCSSToneValue
			{
				MainSubValue band{};
				int value{};
			};

			struct ManualNotchValue
			{
				MainSubValue band{};
				ManualNotchValueType type{};
				int value{};
			};

			struct BusyStateValue
			{
				MainSubValue band{};
				OnOffValue state{};
			};

			struct ContourStateValue
			{
				MainSubValue band{};
				ContourRequestType type{};
				int RequestValue{};
			};

			struct CTCSSStateValue
			{
				MainSubValue band{};
				CTCSSType type{};
			};

			struct DimmerValue
			{
				int TFTBrightness{};
				int LEDIndicatorBrightness{};
			};

			struct DateTimeValue
			{
				DateTimeType type{};
				std::string value{};
			};

			struct EncoderValue
			{
				EncoderType type{};
				int value{};
			};

			struct EncodeMemoryValue
			{
				EncodeFormat format{};
				int channel{};
				std::string message{};
			};

			struct NoiseBlankerValue
			{
				MainSubValue Band{};
				OnOffValue State{};
			};

			class MainToSub
			{
			public:
				static std::string Set();
			};

			struct MemoryChannelReadValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				OnOffValue RIT{};
				OnOffValue XIT{};
				ModeValue Mode{};
				VFOChannelTypeValue ChannelType{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct MemoryChannelTagValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				OnOffValue RIT{};
				OnOffValue XIT{};
				ModeValue Mode{};
				VFOChannelTypeValue ChannelType{};
				CTCSSState CTCSS{};
				OperationType Operation{};
				std::string Tag{};
			};

			struct ClarifierValue
			{
				MainSubValue Band{};
				ClarifierType Type{};
				union value {
					OnOffValue RXOnOff;
					OnOffValue TXOnOff;
					int Frequency;
				};
				value Value{};
			};

			class AntennaTunerControl
			{
			public:
				static std::string Set(TunerState);
				static std::string Read();
				static TunerState Answer(const std::string &);
			};

			class VolumeLevel
			{
			public:
				static std::string Set(MainSubValue, int Value);
				static std::string Read(MainSubValue);
				static VolumeValue Answer(std::string data);
			};

			class AutoInformation
			{
			public:
				static std::string Set(InformationState Value);
				static std::string Read();
				static InformationState Answer(std::string data);
			};

			class MainBandToMemoryChannel
			{
			public:
				static std::string Set();
			};

			class AntennaNumber
			{
			public:
				static std::string Set(MainSubValue, AntennaNumberSelection);
				static std::string Set(AntennaNumberValue);
				static std::string Read(MainSubValue);
				static AntennaNumberValue Answer(std::string data);
			};

			class AMCOutputLevel
			{
			public:
				static std::string Set(int);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SubBandToMainBand
			{
			public:
				static std::string Set();
			};

			class AutoNotch
			{

			public:
				static std::string Set(MainSubValue, OnOffValue);
				static std::string Set(AutoNotchValue);
				static std::string Read(MainSubValue);
				static AutoNotchValue Answer(std::string data);
			};

			class BandDown
			{
			public:
				static std::string Set(MainSubValue);
			};

			class BreakIn
			{
			public:
				static std::string Set(OnOffValue);
				static std::string Read();
				static OnOffValue Answer(std::string);
			};

			class SubBandToMemoryChannel
			{
			public:
				static std::string Set();
			};

			class ManualNotch
			{
			public:
				static std::string Set(MainSubValue, ManualNotchValueType, int);
				static std::string Set(ManualNotchValue);
				static std::string Read(ManualNotchValue);
				static std::string Read(MainSubValue, ManualNotchValueType);
				static ManualNotchValue Answer(std::string data);
			};

			class ChannelUpDown
			{
			public:
				static std::string Set(UpDownValue);
			};

			class CTCSSToneFrequency
			{
				static std::string Set(MainSubValue, int);
				static std::string Read(MainSubValue);
				static CTCSSToneValue Answer(std::string data);
			};

			class BandSelect
			{
			public:
				static std::string Set(BandSelectValue);
			};

			class BandUp
			{
			public:
				static std::string Set(MainSubValue);
			};

			class Busy
			{
			public:
				static std::string Read();
				static BusyStateValue Answer(std::string data);
			};

			class Contour
			{
			public:
				static std::string Set(ContourStateValue);
				static std::string Set(MainSubValue, ContourRequestType, int);
				static std::string Read(ContourStateValue);
				static std::string Read(MainSubValue, ContourRequestType);
				static ContourStateValue Answer(std::string data);
			};

			class CWSpot
			{
			public:
				static std::string Set(OnOffValue);
				static std::string Read();
				OnOffValue Answer(std::string);
			};

			class CTCSS
			{
			public:
				static std::string Set(CTCSSStateValue);
				static std::string Set(MainSubValue, CTCSSType);
				static std::string Read(CTCSSStateValue);
				static std::string Read(MainSubValue);
				static CTCSSStateValue Answer(std::string);
			};

			class Dimmer
			{
			public:
				static std::string Set(DimmerValue);
				static std::string Set(int, int);
				static std::string Read();
				DimmerValue Answer(std::string);
			};

			class MicDown
			{
			public:
				static std::string Set();
			};

			class DateAndTime
			{
			public:
				static std::string Set(DateTimeType, std::string);
				static std::string Set(DateTimeValue);
				static std::string Read(DateTimeType);
				static std::string Read(DateTimeValue);
				DateTimeValue Answer(std::string data);
			};

			class EncoderDown
			{
			public:
				static std::string Set(EncoderValue);
				static std::string Set(EncoderType, int);
			};

			class EnocdeMemory
			{
			public:
				static std::string Set(EncodeMemoryValue);
				static std::string Set(EncodeFormat, int, std::string);
				static std::string Read(EncodeMemoryValue);
				static std::string Read(EncodeFormat, int);
				static EncodeMemoryValue Answer(std::string);
			};

			class Encode
			{
			public:
				static std::string Set(EncodeFormat, int);
			};

			class EncoderUp
			{
			public:
				static std::string Set(EncoderValue);
				static std::string Set(EncoderType, int);
			};

			class ClarifierOnOff
			{
			public:
				static std::string Set(ClarifierValue value);
				static std::string Read(ClarifierValue value);
				static ClarifierValue Answer(std::string data);
			};

			class Menu
			{

			public:
				class RadioSetting
				{
				public:
					class SSB
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int level);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};
						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelect value);
							static std::string Read();
							static RearSelect Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};
					};

					class AM
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int level);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};
						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelect value);
							static std::string Read();
							static RearSelect Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};
					};

					class FM
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int level);
							static std::string Read();
							static int Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};

						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelect value);
							static std::string Read();
							static RearSelect Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};
						class RPT_SHIFT_28
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPT_SHIFT_50
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};

					class PSK_DATA
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class DATA_MODE
						{
						public:
							static std::string Set(DataMode value);
							static std::string Read();
							static DataMode Answer(std::string data);
						};

						class OTHER_SHIFT
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						
						class OTHER_DISP
						{
						  public:
						static std::string Set(int value);
						static std::string Read();
						static int Answer(std::string data);
						};
						
						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int level);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};

						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelect value);
							static std::string Read();
							static RearSelect Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};
					};

					class RTTY
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class POLARITY_RX
						{
						public:
							static std::string Set(RTTYPolarityValue value);
							static std::string Read();
							static RTTYPolarityValue Answer(std::string data);
						};

						class POLARITY_TX
						{
						public:
							static std::string Set(RTTYPolarityValue value);
							static std::string Read();
							static RTTYPolarityValue Answer(std::string data);
						};

						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class SHIFT_PORT
						{
						public:
							static std::string Set(RTTYShiftPortValue value);
							static std::string Read();
							static RTTYShiftPortValue Answer(std::string data);
						};

						class SHIFT_FREQ
						{
						public:
							static std::string Set(RTTYShiftFreqValue value);
							static std::string Read();
							static RTTYShiftFreqValue Answer(std::string data);
						};
					};

					class ENC_DEC_PSK
					{
					public:
						class PSK_MODE
						{
						public:
							static std::string Set(PSKModeValue value);
							static std::string Read();
							static PSKModeValue Answer(std::string data);
						};

						class DECODE_AFC_RANGE
						{
						public:
							static std::string Set(DecodeAfcRangeValue value);
							static std::string Read();
							static DecodeAfcRangeValue Answer(std::string data);
						};

						class POLARITY_RX
						{
						public:
							static std::string Set(RTTYPolarityValue value);
							static std::string Read();
							static RTTYPolarityValue Answer(std::string data);
						};

						class POLARITY_TX
						{
						public:
							static std::string Set(RTTYPolarityValue value);
							static std::string Read();
							static RTTYPolarityValue Answer(std::string data);
						};

						class TX_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};

					class ENC_DEC_RTTY
					{
					public:
						class RX_USOS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class TX_USOS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class RX_NEW_LINE_CODE
						{
						public:
							static std::string Set(NewLineCode value);
							static std::string Read();
							static NewLineCode Answer(std::string data);
						};

						class TX_AUTO_CRLF
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class TX_DIDDLE
						{
						public:
							static std::string Set(TXDiddleValue value);
							static std::string Read();
							static TXDiddleValue Answer(std::string data);
						};

						class BAUDOT_CODE
						{
						public:
							static std::string Set(BaudotCodeStandard value);
							static std::string Read();
							static BaudotCodeStandard Answer(std::string data);
						};
					};
				};

				class CWSetting
				{
				public:
					class ModeCW
					{
					public:
						class AGC_Fast_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Mid_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_Slow_Delay
						{
						public:
							static std::string Set(int msec);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_Freq
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_Freq
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_Slope
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class OUT_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class OUT_LEVEL
						{
						public:
							static std::string Set(int level);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AUTO_MODE
						{
						public:
							static std::string Set(AutoModeValue value);
							static std::string Read();
							static AutoModeValue Answer(std::string data);
						};

						class BKIN_TYPE
						{
						public:
							static std::string Set(BreakInType value);
							static std::string Read();
							static BreakInType Answer(std::string data);
						};

						class BKIN_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class WAVE_SHAPE
						{
						public:
							static std::string Set(WaveShapeValue value);
							static std::string Read();
							static WaveShapeValue Answer(std::string data);
						};

						class FREQ_DISPLAY
						{
						public:
							static std::string Set(FreqDisplayValue value);
							static std::string Read();
							static FreqDisplayValue Answer(std::string data);
						};

						class PC_KEYING
						{
						public:
							static std::string Set(PCKeyingValue value);
							static std::string Read();
							static PCKeyingValue Answer(std::string data);
						};

						class QSK_DELAY_TIME
						{
						public:
							static std::string Set(QSKDelayTime value);
							static std::string Read();
							static QSKDelayTime Answer(std::string data);
						};

						class INDICATOR
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};
					};
					class Keyer
					{
					public:
						class FKEYER_TYPE
						{
						public:
							static std::string Set(KeyerType value);
							static std::string Read();
							static KeyerType Answer(std::string data);
						};
						class FKEYER_DOTDASH
						{
						public:
							static std::string Set(DotDashType value);
							static std::string Read();
							static DotDashType Answer(std::string data);
						};
						class RKEYER_TYPE
						{
						public:
							static std::string Set(KeyerType value);
							static std::string Read();
							static KeyerType Answer(std::string data);
						};
						class RKEYER_DOTDASH
						{
						public:
							static std::string Set(DotDashType value);
							static std::string Read();
							static DotDashType Answer(std::string data);
						};
						class CW_WEIGHT
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
						class MEMORY_1
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class MEMORY_2
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class MEMORY_3
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class MEMORY_4
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class MEMORY_5
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class REPEAT_INTERVAL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
					class Decoder
					{
					public:
						class DECODE_BW
						{
						public:
							static std::string Set(CWDecodeBW value);
							static std::string Read();
							static CWDecodeBW Answer(std::string data);
						};
					};
				};

				class OperationSetting
				{
				public:
					class General
					{
					public:
						class DECODE_RX_SELECT
						{
						public:
							static std::string Set(MainSubValue value);
							static std::string Read();
							static MainSubValue Answer(std::string data);
						};

						class HEADPHONE_MIX
						{
						public:
							static std::string Set(HeadPhoneMixValue value);
							static std::string Read();
							static HeadPhoneMixValue Answer(std::string data);
						};

						class ANT3_SELECT
						{
						public:
							static std::string Set(ANT3Selection value);
							static std::string Read();
							static ANT3Selection Answer(std::string data);
						};

						class NB_WIDTH
						{
						public:
							static std::string Set(NBWidth value);
							static std::string Read();
							static NBWidth Answer(std::string data);
						};

						class NB_REJECTION
						{
						public:
							static std::string Set(NBRejectionValue value);
							static std::string Read();
							static NBRejectionValue Answer(std::string data);
						};

						class BEEP_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RF_SQL_VR
						{
						public:
							static std::string Set(VRType value);
							static std::string Read();
							static VRType Answer(std::string data);
						};

						class TUNER_232C_SELECT
						{
						public:
							static std::string Set(TunerRS232Select value);
							static std::string Read();
							static TunerRS232Select Answer(std::string data);
						};

						class RS232_RATE
						{
						public:
							static std::string Set(RS232CRate value);
							static std::string Read();
							static RS232CRate Answer(std::string data);
						};

						class RS232_TIME_OUT_TIMER
						{
						public:
							static std::string Set(RS232CTimeOutValue value);
							static std::string Read();
							static RS232CTimeOutValue Answer(std::string data);
						};

						class CAT_RATE
						{
						public:
							static std::string Set(CATRateValue value);
							static std::string Read();
							static CATRateValue Answer(std::string data);
						};

						class CAT_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CATTimeOutValue value);
							static std::string Read();
							static CATTimeOutValue Answer(std::string data);
						};

						class CAT_RTS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class QMB_CH
						{
						public:
							static std::string Set(QMBChValue value);
							static std::string Read();
							static QMBChValue Answer(std::string data);
						};

						class MEM_GROUP
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class QUICK_SPLIT_INPUT
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

						class TX_TIME_OUT_TIMER
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
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

						class REF_FREQ_ADJ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class CS_DIAL
						{
						public:
							static std::string Set(CSDialType value);
							static std::string Read();
							static CSDialType Answer(std::string data);
						};

						class KEYBOARD_LANGUAGE
						{
						public:
							static std::string Set(KeyboardLangaugeValue value);
							static std::string Read();
							static KeyboardLangaugeValue Answer(std::string data);
						};
					};
					class RX_DSP
					{
					public:
						class APF_WIDTH
						{
						public:
							static std::string Set(APFWidthValue value);
							static std::string Read();
							static APFWidthValue Answer(std::string data);
						};

						class CONTOUR_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class CONTOUR_WIDTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class DNR_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class IF_NOTCH_WIDTH
						{
						public:
							static std::string Set(IFNotchWidth value);
							static std::string Read();
							static IFNotchWidth Answer(std::string data);
						};
					};
					class TX_AUDIO
					{
					public:
						class PROC_TYPE
						{
						public:
							static std::string Set(ProcType value);
							static std::string Read();
							static ProcType Answer(std::string data);
						};

						class AMC_RELEASE_TIME
						{
						public:
							static std::string Set(AMCReleaseTime value);
							static std::string Read();
							static AMCReleaseTime Answer(std::string data);
						};

						class EQ1_FREQ
						{
						public:
							static std::string Set(EQ1FreqValue value);
							static std::string Read();
							static EQ1FreqValue Answer(std::string data);
						};

						class EQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EQ2_FREQ
						{
						public:
							static std::string Set(EQ2FreqValue value);
							static std::string Read();
							static EQ2FreqValue Answer(std::string data);
						};

						class EQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EQ3_FREQ
						{
						public:
							static std::string Set(EQ3FreqValue value);
							static std::string Read();
							static EQ3FreqValue Answer(std::string data);
						};

						class EQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ1_FREQ
						{
						public:
							static std::string Set(EQ1FreqValue value);
							static std::string Read();
							static EQ1FreqValue Answer(std::string data);
						};

						class PEQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ2_FREQ
						{
						public:
							static std::string Set(EQ2FreqValue value);
							static std::string Read();
							static EQ2FreqValue Answer(std::string data);
						};

						class PEQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ3_FREQ
						{
						public:
							static std::string Set(EQ3FreqValue value);
							static std::string Read();
							static EQ3FreqValue Answer(std::string data);
						};

						class PEQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PEQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
					class TX_GENERAL
					{
					public:
						class MAX_POWER_HF
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class MAX_POWER_50M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class MAX_POWER_70M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class MAX_POWER_AM
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class VOX_SELECT
						{
						public:
							static std::string Set(VoxSelectValue value);
							static std::string Read();
							static VoxSelectValue Answer(std::string data);
						};

						class DATA_VOX_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class EMERGENCY_FREQ_TX
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};
					};
					class TUNING
					{
					public:
						class SSB_CW_DIAL_STEP
						{
						public:
							static std::string Set(SSBDialStepValue value);
							static std::string Read();
							static SSBDialStepValue Answer(std::string data);
						};

						class RTTY_PSK_DIAL_STEP
						{
						public:
							static std::string Set(RTTYPSKDialStepValue value);
							static std::string Read();
							static RTTYPSKDialStepValue Answer(std::string data);
						};

						class CH_STEP
						{
						public:
							static std::string Set(CH_StepValue value);
							static std::string Read();
							static CH_StepValue Answer(std::string data);
						};

						class AM_CH_STEP
						{
						public:
							static std::string Set(AMCHStepValue value);
							static std::string Read();
							static AMCHStepValue Answer(std::string data);
						};

						class FM_CH_STEP
						{
						public:
							static std::string Set(FMCHStepValue value);
							static std::string Read();
							static FMCHStepValue Answer(std::string data);
						};

						class MAIN_STEPS_PER_REV
						{
						public:
							static std::string Set(MainStepsPerRev value);
							static std::string Read();
							static MainStepsPerRev Answer(std::string data);
						};

						class MPVD_STEPS_PRE_REV
						{
						public:
							static std::string Set(MPVDStepsPerRev value);
							static std::string Read();
							static MPVDStepsPerRev Answer(std::string data);
						};
					};
				};

				class DisplaySetting
				{
				public:
					class DISPLAY
					{
					public:
						class MY_CALL
						{
						public:
							static std::string Set(std::string value);
							static std::string Read();
							static std::string Answer(std::string data);
						};

						class MY_CALL_TIME
						{
						public:
							static std::string Set(CallSignTime value);
							static std::string Read();
							static CallSignTime Answer(std::string data);
						};

						class SCREEN_SAVER
						{
						public:
							static std::string Set(ScreenSaverTime value);
							static std::string Read();
							static ScreenSaverTime Answer(std::string data);
						};

						class TFT_CONTRAST
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class DIMMER_TFT
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class DIMMER_LED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class MOUSE_POINTER_SPEED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class FREQ_STYLE
						{
						public:
							static std::string Set(FREQ_STYLEValue value);
							static std::string Read();
							static FREQ_STYLEValue Answer(std::string data);
						};
					};
					class SCOPE
					{
					public:
						class RBW
						{
						public:
							static std::string Set(RBWValue value);
							static std::string Read();
							static RBWValue Answer(std::string data);
						};

						class SCOPE_CTR
						{
						public:
							static std::string Set(ScopeCTRValue value);
							static std::string Read();
							static ScopeCTRValue Answer(std::string data);
						};

						class DISP_SENSITIVITY_2D
						{
						public:
							static std::string Set(ScopeSensitivityValue value);
							static std::string Read();
							static ScopeSensitivityValue Answer(std::string data);
						};

						class DISP_SENSITIVITY_3DSS
						{
						public:
							static std::string Set(ScopeSensitivityValue value);
							static std::string Read();
							static ScopeSensitivityValue Answer(std::string data);
						};
					};
					class EXT_MONITOR
					{
					public:
						class EXT_DISPLAY
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class PIXEL
						{
						public:
							static std::string Set(PixelValue value);
							static std::string Read();
							static PixelValue Answer(std::string data);
						};
					};
				};
			};

			class Frequency_Main
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class Frequency_Sub
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FineTuning
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class FunctionRX
			{
			public:
				static std::string Set(FunctionRXValue value);
				static std::string Set(RXValue main, RXValue sub);
				static std::string Read();
				static FunctionRXValue Answer(std::string data);
			};

			class FastStep
			{
			public:
				static std::string Set(FastStepState value);
				static std::string Read();
				static FastStepState Answer(std::string data);
			};

			enum class TxSet : int
			{
				MainTxOnOff,
				SUBTxOnOff,
				MainTx,
				SubTx
			};

			class FunctionTx
			{
			public:
				static std::string Set(TxSet value);
				static std::string Read();
				static MainSubValue Answer(std::string data);
			};

			class AGCFunction
			{
			public:
				static std::string Set(AGCSetFunction value);
				static std::string Read(MainSubValue value);
				static AGCState Answer(std::string data);
			};

			class IDENTIFICATION
			{
			public:
				static std::string Read();
				static Yaesu::RigType Answer(std::string data);
			};

			struct InformationValue
			{
				MemoryChannelValue MemoryChannel;
				int VFOAFreq;
				int ClarifierFreq;
				ClarifierState RxClarifier;
				ClarifierState TxClarifier;
				ModeValue Mode;
				VFOChannelTypeValue VFO;
				CTCSSState CTCSS;
				OperationType Operation;
			};

			class INFORMATION
			{
			public:
				static std::string Read();
				static InformationValue Answer(std::string data);
			};

			struct IFShiftValue
			{
				MainSubValue Band;
				int Value;
			};

			class IF_SHIFT
			{
			public:
				static std::string Set(MainSubValue Band, int value);
				static std::string Set(IFShiftValue value);
				static std::string Read();
				static IFShiftValue Answer(std::string data);
			};

			class KEYER_MEMORY
			{
			public:
				static std::string Set(KeyerMemoryValue value);
				static std::string Read(int channelNum);
				static KeyerMemoryValue Answer(std::string data);
			};

			class KeyPitch
			{
			public:
				static std::string Set(KeyPitchValue value);
				static std::string Read();
				static KeyPitchValue Answer(std::string data);
			};

			class Keyer
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class KeySpeed
			{
			public:
				static std::string Set(KeyerSpeedVal value);
				static std::string Read();
				static KeyerSpeedVal Answer(std::string data);
			};

			class CW_Keying
			{
			public:
				static std::string Set(KeyerMemoryChannel value);
			};

			class Lock
			{
			public:
				static std::string Set(LockType value);
				static std::string Read();
				static LockType Answer(std::string data);
			};

			class LoadMessage
			{
			public:
				static std::string Set(LoadMessageChannel value);
				static std::string Read();
				static LoadMessageChannel Answer(std::string data);
			};

			class MemoryChannelToMain
			{
			public:
				std::string Set();
			};

			class MemoryChannelToSub
			{
			public:
				std::string Set();
			};

			class MemoryChannelSelection
			{
			public:
				static std::string Set(MemoryChannelValue value);
				static std::string Read();
				static MemoryChannelValue Answer(std::string data);
			};

			class OperatingMode
			{
			public:
				static std::string Set(ModeSettingValue value);
				static std::string Set(MainSubValue Band, ModeValue Mode);
				static std::string Read(MainSubValue Band);
				static ModeSettingValue Answer(std::string data);
			};

			class MicGain
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class MonitorLevel
			{
			public:
				static std::string Set(MonitorLevelValue value);
				static std::string Read(MonitorRequestType value);
				static MonitorLevelValue Answer(std::string data);
			};

			class MemoryChannel
			{
			public:
				static std::string Set(MemoryChannelReadValue value);
				static std::string Read(MemoryChannelValue channel);
				static MemoryChannelReadValue Answer(std::string data);
			};

			class MeterSW
			{
			public:
				static std::string Set(MeterTypeValue value);
				static std::string Read();
				static MeterTypeValue Answer(std::string data);
			};

			class MemoryChannelTag
			{
			public:
				static std::string Set(MemoryChannelTagValue value);
				static std::string Read(MemoryChannelValue channel);
				static MemoryChannelTagValue Answer(std::string data);
			};

			class Mox
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class Narrow
			{
			public:
				static std::string Set(NarrowValue value);
				static std::string Read(MainSubValue band);
				static NarrowValue Answer(std::string data);
			};

			class NoiseBlanker
			{
			public:
				static std::string Set(NoiseBlankerValue value);
				static std::string Read(MainSubValue band);
				static NoiseBlankerValue Answer(std::string data);
			};

			class NoiseBlankerLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class NoiseReduction
			{
			public:
				static std::string Set(NoiseReductionValue value);
				static std::string Read(MainSubValue band);
				static NoiseReductionValue Answer(std::string data);
			};

			class OppisateBandInformation
			{
			public:
				static std::string Read();
				static FTDX101::OppositeInformation Answer(std::string data);
			};

			class Offset
			{
			public:
				static std::string Set(OffsetValue value);
				static std::string Read(MainSubValue band);
				static OffsetValue Answer(std::string data);
			};

			class PreAmp
			{
			public:
				static std::string Set(PreAmpValue value);
				static std::string Read(MainSubValue band);
				static PreAmpValue Answer(std::string data);
			};

			class PlayBack
			{
			public:
				static std::string Set(DVSPlayBackMode value);
				static std::string Read();
				static DVSPlayBackMode Answer(std::string data);
			};

			class PowerControl
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SpeechProcessorLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SpeechProcessor
			{
			public:
				static std::string Set(SpeechProcessorValue value);
				static std::string Read(SpeechProcessorType type);
				static SpeechProcessorValue Answer(std::string data);
			};

			class PowerSwitch
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class QMBStore
			{
			public:
				static std::string Set();
			};

			class QMBRecall
			{
			public:
				static std::string Set();
			};

			class QuickSplit
			{
			public:
				static std::string Set();
			};

			class RFAttenuator
			{
			public:
				static std::string Set(AttenuatorValue value);
				static std::string Read(MainSubValue band);
				static AttenuatorValue Answer(std::string data);
			};

			class ClaifierClear
			{
			public:
				static std::string Set();
			};

			class ClarifierDown
			{
			public:
				static std::string Set(int freq);
			};

			class RoofingFilter
			{
			public:
				static std::string Set(RoofingFilterValue value);
				static std::string Read(MainSubValue band);
				static RoofingFilterValue Answer(std::string data);
			};

			class RFGain
			{
			public:
				static std::string Set(RFGainValue value);
				static std::string Read(MainSubValue band);
				static RFGainValue Answer(std::string data);
			};

			class RadioInformation
			{
			public:
				static std::string Read(RadioInformationType);
				static RadioInformationValue Answer(std::string data);
			};

			class NoiseReductionLevel
			{
			public:
				static std::string Set(NoseReductionLevelValue value);
				static std::string Read(MainSubValue band);
				static NoseReductionLevelValue Answer(std::string data);
			};

			class ReadMeter
			{
			public:
				static std::string Read(ReadMeterType);
				static ReadMeterValue Answer(std::string data);
			};

			class RadioStatus
			{
			public:
				static std::string Read();
				static RadioMode Answer(std::string data);
			};

			class Clarifier
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ClarifierPlusOffset
			{
			public:
				static std::string Set(int value);
			};

			enum class ScanType : int
			{
				OFF,
				UP,
				DOWN
			};

			class Scan
			{
			public:
				static std::string Set(ScanType value);
				static std::string Read();
				static ScanType Answer(std::string data);
			};

			class VoxStatus
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class TxClarifier
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ZeroIn
			{
			public:
				static std::string Set();
			};

			class ClarifierClear
			{
			public:
				static std::string Set();
			};

			class SubDial
			{
			public:
				static std::string Set(SubDialValue value);
				static std::string Read(SubDialKnob type);
				static SubDialValue Answer(std::string data);
			};

			struct WidthValue
			{
				MainSubValue Band;
				int Width;
			};

			class Width
			{
			public:
				static std::string Set(WidthValue value);
				static std::string Read(MainSubValue Band);
				static WidthValue Answer(std::string data);
			};

			struct SMeterValue
			{
				MainSubValue Band;
				int Value;
			};

			struct SquelchValue
			{
				MainSubValue Band;
				int Value;
			};

			class S_MeterReading
			{
			public:
				static std::string Read(MainSubValue Band);
				static SMeterValue Answer(std::string data);
			};

			class SquelchLevel
			{
			public:
				static std::string Set(SquelchValue value);
				static std::string Read(MainSubValue Band);
				static SquelchValue Answer(std::string data);
			};

			enum class SpectrumScopeFunction : int
			{
				SPEED,
				PEAK,
				MARKER,
				COLOR,
				LEVEL,
				SPAN
			};

			enum class SpectrumScopeSpeedValue : int
			{
				SLOW1,
				SLOW2,
				FAST1,
				FAST2,
				FAST3
			};

			enum class SpectrumScopePeakValue : int
			{
				LV1,
				LV2,
				LV3,
				LC4,
				LV5
			};

			enum class SpectrumScopeMarkerValue : int
			{
				On,
				Off
			};

			enum class SpectrumScopeDirectSampelingValue : int
			{
				COLOR1,
				COLOR2,
				COLOR3,
				COLOR4,
				COLOR5,
				COLOR6,
				COLOR7,
				COLOR8,
				COLOR9,
				COLOR10,
				COLOR11
			};

			enum class SepctrumScopeNarrowBandValue : int
			{
				COLOR12,
				COLOR13,
				COLOR14,
				COLOR15,
				COLOR16,
				COLOR17,
				COLOR18
			};

			enum class SpectrumScopeNarrowBandEnableValue : int
			{
				Off,
				On
			};

			enum class SpectrumScopeSpanValue : int
			{
				_1kHz,
				_2kHz,
				_10kHz,
				_20kHz,
				_50kHz,
				_100kHz,
				_200kHz,
				_300kHz,
				_500kHz,
				_1MHz
			};

			struct ColorType
			{
				SpectrumScopeDirectSampelingValue DIRECT_SAMPELING;
				SepctrumScopeNarrowBandValue NARROW_BAND;
				SpectrumScopeNarrowBandEnableValue NARROW_ENABLE;
			};

			union SpectrumScopeValueType
			{
				ColorType Colors;
				SpectrumScopeSpeedValue Speed;
				SpectrumScopePeakValue Peak;
				SpectrumScopeMarkerValue Marker;
				SpectrumScopeSpanValue Span;
				float Level;
			};

			struct SpectrumScopeAnswerType
			{
				MainSubValue Band;
				SpectrumScopeFunction Function;
				SpectrumScopeValueType Value;
			};

			class SpectrumScope
			{
			public:
				static std::string Read();
				static std::string Set(MainSubValue, SpectrumScopeFunction, SpectrumScopeValueType);
				static SpectrumScopeAnswerType Answer(std::string);
			};

			enum class SplitType : int
			{
				OFF,
				ON,
				ON_5kHz
			};

			class Split
			{
			public:
				static std::string Read();
				static std::string Set(SplitType);
				static SplitType Answer(std::string);
			};

			class SwapVFO
			{
			public:
				static std::string Set();
			};

			enum class SyncType : int
			{
				OFF,
				ON,
				ON_COPY
			};

			class SYNC
			{
			public:
				static std::string Read();
				static std::string Set(SyncType);
				static SyncType Answer(std::string);
			};

			enum class TxSetValue : int
			{
				RADIO_OFF_CAT_OFF,
				RADIO_OFF_CAT_ON,
				RADIO_ON_CAT_OFF
			};

			class TXSet
			{
			public:
				static std::string Set(TxSetValue);
				static std::string Read();
				static TxSetValue Answer(std::string);
			};

			enum class PllLockState : int
			{
				LOCKED,
				UNLOCKED
			};

			class PllUnlockStatus
			{
			public:
				static std::string Read();
				static PllLockState Answer(std::string);
			};

			class MicUP
			{
			public:
				static std::string Set();
			};

			class VoxDelayTime
			{
			public:
				static std::string Set(int Delay);
				static std::string Read();
				static int Answer(std::string);
			};

			class VoxGain
			{
			public:
				static std::string Set(int level);
				static std::string Read();
				static int Answer(std::string);
			};

			class VFOSelect
			{
			public:
				static std::string Set(MainSubValue);
				static std::string Read();
				static MainSubValue Answer(std::string);
			};

		};

		namespace FT891
		{
			using Yaesu::Common::KeyerMemoryChannel;
			using Yaesu::Common::PTTSelectValue;
			using Yaesu::Common::RTTYPolarityValue;
			using Yaesu::Common::RTTYShiftFreqValue;
			using Yaesu::Common::RTTYMarkFreq;
			using Yaesu::Common::FreqLowCutValue;
			using Yaesu::Common::FreqHighCutValue;
			using Yaesu::Common::EnableDisableValue;
			using Yaesu::Common::APFWidthValue;
			using Yaesu::Common::IFNotchWidth;
			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;
			using Yaesu::Common::VoxSelectValue;

			enum class CommandType : int
			{
				
				AC ,
				AG ,
				AI ,			
				BC ,
				BI ,
				BP ,
				BY ,
				CF ,
				CN ,
				CO ,
				CS ,
				CT ,
				DA ,
				EX ,
				FA ,
				FB,
				FS ,
				GT ,
				ID ,
				IF ,
				IS ,
				KM ,
				KP ,
				KR ,
				KS,
				LK ,
				LM ,
				MC ,
				MD,
				MG ,
				ML ,
				MR ,
				MS,
				MT,
				MW ,
				MX ,
				NA ,
				NB,
				NL ,
				NR ,
				OI ,
				OS ,
				PA ,
				PB,
				PC,
				PL ,
				PR ,
				PS,
				RA ,
				RG ,
				RI ,			
				RL,	
				RM,
				RS,
				SC,
				SD ,
				SH ,
				SM ,
				SQ ,
				ST ,
				SV ,
				TS ,
				TX ,
				UL ,
				VD ,
				VG ,
				VX ,
				UN 
			};

			enum class Band : int
			{
				m160 = 0,
				m80 = 1,
				m60 = 2,
				m40 = 3,
				m30 = 4,
				m20 = 5,
				m17 = 6,
				m15 = 7,
				m12 = 8,
				m10 = 9,
				m6 = 10,
				GEN = 11,
				MW = 12
			};

			enum class InformationState : int
			{
				OFF,
				ON
			};

			enum class TunerState : int
			{
				OFF,
				ON,
				StartStop
			};

			enum class NotchState
			{
				OFF,
				ON
			};

			enum class BreakInState : int
			{
				OFF,
				ON
			};

			enum class CTCSSState
			{
				CTCSS_OFF,
				CTCSS_ENC_DEC_ON,
				CTCSS_ENC_ON,
				CTCSS_DCS_ON
			};

			enum class CWSpotState : int
			{
				OFF,
				ON
			};

			enum class EncoderType : int
			{
				MAIN_ENCODER,
				MULTI_FUNCTION = 8
			};

			enum class MenuFunction : int
			{
				AGC_FAST_DELAY = 101,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCD_CONTRAST = 201,
				DIMMER_BACKLIT,
				DIMMER_LCD,
				DIMMER_TX_BUSY,
				PEAK_HOLD,
				ZIN_LED,
				POPUP_MENU,
				DVS_RX_OUT_LVL = 301,
				DVS_TX_OUT_LVL,
				KEYER_TYPE = 401,
				KEYER_DOT_DASH_ORDER,
				CW_WEIGHT,
				BEACON_INTERVAL,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				CW_MEMORY_1,
				CW_MEMORY_2,
				CW_MEMORY_3,
				CW_MEMORY_4,
				CW_MEMORY_5,
				NB_WIDTH = 501,
				NB_REJECTION,
				NB_LEVEL,
				BEEP_LEVEL,
				RF_SQL_VR,
				CAT_RATE,
				CAT_TOT,
				CAT_RTS,
				MEM_GROUP,
				FM_SETTING,
				REC_SETTING,
				ATAS_SETTING,
				QUICK_SPL_FREQ,
				TX_TOT,
				MIC_SCAN,
				MIC_SCAN_RESUME,
				REF_FEQ_ADJ,
				CLAR_SELECT,
				APO,
				FAN_CONTROL,
				AM_LCUT_FREQ = 601,
				AM_LCUT_SLOPE,
				AM_HCUT_FREQ,
				AM_HCUT_SLOPE,
				AM_MIC_SELECT,
				AM_OUT_LEVEL,
				AM_PTT_SELECT,
				CW_LCUT_FREQ = 701,
				CW_LCUT_SLOPE,
				CW_HCUT_FREQ,
				CW_HCUT_SLOPE,
				CW_OUT_LEVEL,
				CW_AUTO_MODE,
				CW_BFO,
				CW_BK_IN_TYPE,
				CW_BK_IN_DELAY,
				CW_WAVE_SHAPE,
				CW_FREQ_DISPLAY,
				PC_KEYING,
				QSK_DELAY_TIME,
				DATA_MODE = 801,
				PSK_TONE,
				OTHER_DISP,
				OTHER_SHIFT,
				DATA_LCUT_FREQ,
				DATA_LCUT_SLOPE,
				DATA_HCUT_FREQ,
				DATA_HCUT_SLOPE,
				DATA_IN_SELECT,
				DATA_PTT_SELECT,
				DATA_OUT_LEVEL,
				DATA_BFO,
				FM_MIC_SELECT = 901,
				FM_OUT_LEVEL,
				PKT_PTT_SELECT,
				RPT_SHIFT_28MHZ,
				RPT_SHIFT_50MHZ,
				DCS_POLARITY,
				RTTY_LCUT_FREQ = 1001,
				RTTY_LCUT_SLOPE,
				RTTY_HCUT_FREQ,
				RTTY_HCUT_SLOPE,
				RTTY_SHIFT_PORT,
				RTTY_POLARITY_R,
				RTTY_POLARITY_T,
				RTTY_OUT_LEVEL,
				RTTY_SHIFT_FREQ,
				RTTY_MARK_FREQ,
				RTTY_BFO,
				SSB_LCUT_FREQ = 1101,
				SSB_LCUT_SLOPE,
				SSB_HCUT_FREQ,
				SSB_HCUT_SLOPE,
				SSB_MIC_SELECT,
				SSB_OUT_LEVEL,
				SSB_BFO,
				SSB_PTT_SELECT,
				SSB_TX_BPF,
				APF_WIDTH = 1201,
				CONTOUR_LEVEL,
				CONTOUR_WIDTH,
				IF_NOTCH_WIDTH,
				SCP_START_CYCLE = 1301,
				SCP_SPAN_FREQ,
				QUICK_DIAL = 1401,
				SSB_DIAL_STEP,
				AM_DIAL_STEP,
				FM_DIAL_STEP,
				DIAL_STEP,
				AM_CH_STEP,
				FM_CH_STEP,
				EQ1_FREQ = 1501,
				EQ1_LEVEL,
				EQ1_BWTH,
				EQ2_FREQ,
				EQ2_LEVEL,
				EQ2_BWTH,
				EQ3_FREQ,
				EQ3_LEVEL,
				EQ3_BWTH,
				P_EQ1_FREQ,
				P_EQ1_LEVEL,
				P_EQ1_BWTH,
				P_EQ2_FREQ,
				P_EQ2_LEVEL,
				P_EQ2_BWTH,
				P_EQ3_FREQ,
				P_EQ3_LEVEL,
				P_EQ3_BWTH,
				HF_SSB_PWR = 1601,
				HF_AM_PWR,
				HF_PWR,
				SSB_POWER_50M,
				AM_POWER_50M,
				VHF_PWR,
				SSB_MIC_GAIN,
				AM_MIC_GAIN,
				FM_MIC_GAIN,
				DATA_MIC_GAIN,
				SSB_DATA_GAIN,
				AM_DATA_GAIN,
				FM_DATA_GAIN,
				DATA_GAIN,
				TUNER_SELECT,
				VOX_SELECT,
				VOX_GAIN,
				VOX_DELAY,
				ANTI_VOX_GAIN,
				DATA_VOX_GAIN,
				DATA_VOX_DELAY,
				DATA_ANTIVOX_GAIN,
				EMERGENCY_FREQ,
				RESET = 1701,
				MAIN_VERSION = 1801,
				DSP_VERSION,
				LCD_VERSION
			};

			enum class PeakHoldType : int
			{
				OFF,
				sec05,
				sec10,
				sec20
			};

			enum class PopUpMenuStyle
			{
				UPPER,
				LOWER
			};

			enum class KeyerTypeValue : int
			{
				OFF,
				BUG,
				ELEKEY_A,
				ELEKEY_B,
				ELEKEY_Y,
				ACS

			};

			enum class KeyerDotDashValue : int
			{
				NOR,
				REV
			};

			enum class NumberStyleValue : int
			{
				_1290,
				AUNO,
				AUNT,
				A2NO,
				A2NT,
				_12NO,
				_12NT
			};

			enum class CWMemoryTypeValue : int
			{
				TEXT,
				MESSAGE
			};

			enum class NBWidthValue : int
			{
				msec1,
				msec3,
				msec10
			};

			enum class NBRejectionValue : int
			{
				db10,
				db30,
				db50
			};

			enum class RfSqlVrValue : int
			{
				RF,
				SQL
			};

			enum class CatRateValue : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum class CatTOTValue : int
			{
				_10msec,
				_100msec,
				_1000msec,
				_3000msec
			};

			enum class MicScanResumeValue : int
			{
				PAUSE,
				TIME
			};

			enum class ClarSelectValue : int
			{
				RX,
				TX,
				TRX
			};

			enum class APOValue : int
			{
				OFF,
				hr1,
				hr2,
				hr4,
				hr6,
				hr8,
				hr10,
				hr12
			};

			enum class FanControlValue : int
			{
				NORMAL,
				CONTEST
			};

			enum class FreqSlopeValue : int
			{
				DbOct_6,
				DbOct_18
			};

			enum class CwAutoModeValue : int
			{
				OFF,
				_50M,
				ON
			};

			enum class BfoValue : int
			{
				USB,
				LSB,
				AUTO
			};

			enum class CwBreakInType : int
			{
				SEMI,
				FULL
			};

			enum class CwWaveShapeValue : int
			{
				_2msec = 1,
				_4msec
			};

			enum class CwFreqDisplayValue : int
			{
				FREQ,
				PITCH
			};

			enum class PCKeyingValue : int
			{
				OFF,
				DKAY,
				RTS,
				DTR
			};

			enum class QskDelayTimeValue : int
			{
				_15msec,
				_20msec,
				_25msec,
				_30msec
			};

			enum class DataModeValue : int
			{
				PSK,
				OTHERS
			};

			enum class PSKToneValue : int
			{
				_1000hz,
				_1500hz,
				_2000hz
			};

			enum class AudioInputValue : int
			{
				MIC,
				REAR
			};

			enum class DCSPolarityValue : int
			{
				Tn_Rn,
				Tn_Riv,
				Tiv_Rn,
				Tiv_Riv
			};

			enum class RTTYShiftPortValue : int
			{
				SHIFT,
				DTR,
				RTS
			};

			enum class DataBfoValue : int
			{
				USB,
				LSB
			};

			enum class SSBTXBandPassValue : int
			{
				_100_3000,
				_100_2900,
				_200_2800,
				_300_2700,
				_400_2600
			};

			enum class SCPStartCycleValue : int
			{
				OFF,
				_3sec,
				_5sec,
				_10sec
			};

			enum class SCPSpanFreqValue : int
			{
				_37_5khz,
				_75khz,
				_150khz,
				_375khz,
				_750khz
			};

			enum class QuickDialValue : int
			{
				_50khz,
				_100khz,
				_500khz
			};

			enum class SSBDialStep : int
			{
				_2hz,
				_5hz,
				_10hz
			};

			enum class AMDialStep : int
			{
				_10Hz,
				_100Hz
			};

			enum class FMDialStep : int
			{
				_10Hz,
				_100Hz
			};

			enum class DialStep : int
			{
				_2hz,
				_5hz,
				_10hz
			};

			enum class AMChannelStepValue : int
			{
				_2_5khz,
				_5khz,
				_9khz,
				_10khz,
				_12_5khz,
				_25khz
			};

			enum class FMChannelStepValue : int
			{
				_5kHz,
				_6_26kHz,
				_10kHz,
				_12_5kHz,
				_15kHz,
				_20kHz,
				_25kHz
			};

			enum class TunerSelectValue : int
			{
				OFF,
				EXTERNAL,
				ATAS,
				LAMP
			};

			

			enum class ResetValue : int
			{
				ALL,
				DATA,
				FUNC
			};

			enum class NotchCommandType
			{
				ON_OFF,
				LEVEL
			};

			enum class CTCSSModeType : int
			{
				CTCSS,
				DCS
			};

			enum class ContourType : int
			{
				ContourOnOff,
				ContourFrequency,
				APFOnOff,
				APFFrequency
			};

			enum class ContourState
			{
				OFF,
				ON
			};

			enum class VFOFastStepValue
			{
				OFF,
				ON
			};

			enum class AGCSetValue
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO
			};

			enum class AGCReadValue
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO_FAST,
				AUTO_MID,
				AUTO_SLOW
			};

			enum class KeyPitchValue
			{
				_300Hz,
				_310Hz,
				_320Hz,
				_330Hz,
				_340Hz,
				_350Hz,
				_360Hz,
				_370Hz,
				_380Hz,
				_390Hz,
				_400Hz,
				_410Hz,
				_420Hz,
				_430Hz,
				_440Hz,
				_450Hz,
				_460Hz,
				_470Hz,
				_480Hz,
				_490Hz,
				_500Hz,
				_510Hz,
				_520Hz,
				_530Hz,
				_540Hz,
				_550Hz,
				_560Hz,
				_570Hz,
				_580Hz,
				_590Hz,
				_600Hz,
				_610Hz,
				_620Hz,
				_630Hz,
				_640Hz,
				_650Hz,
				_660Hz,
				_670Hz,
				_680Hz,
				_690Hz,
				_700Hz,
				_710Hz,
				_720Hz,
				_730Hz,
				_740Hz,
				_750Hz,
				_760Hz,
				_770Hz,
				_780Hz,
				_790Hz,
				_800Hz,
				_810Hz,
				_820Hz,
				_830Hz,
				_840Hz,
				_850Hz,
				_860Hz,
				_870Hz,
				_880Hz,
				_890Hz,
				_900Hz,
				_910Hz,
				_920Hz,
				_930Hz,
				_940Hz,
				_950Hz,
				_960Hz,
				_970Hz,
				_980Hz,
				_990Hz,
				_1000Hz,
				_1010Hz,
				_1020Hz,
				_1030Hz,
				_1040Hz,
				_1050Hz

			};

			enum class KeyerSpeedVal
			{
				_4wpm = 4,
				_5wpm,
				_6wpm,
				_7wpm,
				_8wpm,
				_9wpm,
				_10wpm,
				_11wpm,
				_12wpm,
				_13wpm,
				_14wpm,
				_15wpm,
				_16wpm,
				_17wpm,
				_18wpm,
				_19wpm,
				_20wpm,
				_21wpm,
				_22wpm,
				_23wpm,
				_24wpm,
				_25wpm,
				_26wpm,
				_27wpm,
				_28wpm,
				_29wpm,
				_30wpm,
				_31wpm,
				_32wpm,
				_33wpm,
				_34wpm,
				_35wpm,
				_36wpm,
				_37wpm,
				_38wpm,
				_39wpm,
				_40wpm,
				_41wpm,
				_42wpm,
				_43wpm,
				_44wpm,
				_45wpm,
				_46wpm,
				_47wpm,
				_48wpm,
				_49wpm,
				_50wpm,
				_51wpm,
				_52wpm,
				_53wpm,
				_54wpm,
				_55wpm,
				_56wpm,
				_57wpm,
				_58wpm,
				_59wpm,
				_60wpm
			};

			enum class DVSRecordingValue
			{
				STOP,
				CH1,
				CH2,
				CH3,
				CH4,
				CH5
			};

			enum class MonitorFunction : int
			{
				MontiorOnOff,
				MontiorLevel
			};

			enum class MeterType
			{
				COMP,
				ALC,
				PO,
				SWR,
				ID
			};

			enum class TagValue
			{
				OFF,
				ON
			};

			enum class VFOChannelTypeValue
			{
				VFO,
				Memory,
				MemoryTune,
				QuickMemoryBank,
				QMB_MT,
				PMS,
				HOME
			};

			enum class OperationType
			{
				Simplex,
				PlusShift,
				MinusShift
			};

			enum class ModeValue
			{
				SSB_BFOA = 1,
				SSB_BFOB,
				CW,
				FM,
				AM,
				RTTY_BFOA,
				CW_BFOA,
				DATA_BFOA,
				RTTY_BFOB,
				FM_N = 11,
				DATA_BFOB,
				AM_N
			};

			enum class UpDownState
			{
				UP,
				DOWN
			};

			enum class IfShiftValue
			{
				OFF,
				ON
			};

			enum class SpeechProcessorType
			{
				Processor,
				ParametricEqualizer
			};

			enum class SpeechProcessorState
			{
				OFF,
				ON
			};

			enum PowerSwitchValue
			{
				OFF,
				ON
			};

			enum class ReadMeterType
			{
				AutoA,
				S,
				AutoB,
				COMP,
				ALC,
				PO,
				SWR,
				ID
			};

			enum class RadioStatusValue
			{
				NORMAL,
				MENU
			};

			enum class ScanState
			{
				OFF,
				UP,
				DOWN
			};

			enum class WidthState : int
			{
				OFF,
				ON
			};

			enum class MemoryChannelModeValue : int
			{
				LSB = 1,
				USB,
				CW,
				FM,
				AM,
				RTTY_LSB,
				CW_R,
				DATA_LSB,
				RTTY_USB,
				FM_N = 11,
				DATA_USB,
				AM_N
			};

			enum class MemoryChannelValue
			{
				_1 = 1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				P1L,
				P1U,
				P2L,
				P2U,
				P3L,
				P3U,
				P4L,
				P4U,
				P5L,
				P5U,
				P6L,
				P6U,
				P7L,
				P7U,
				P8L,
				P8U,
				P9L,
				P9U,
				_5351_5mhz = 501,
				_5354mhz,
				_5357mhz,
				_5360mhz,
				_5363mhz,
				_5366mhz,
				EMG = 600

			};

			enum class InformationType
			{
				HI_SWR,
				REC = 3,
				PLAY,
				TX_LED = 10,
				RX_LED
			};

			enum class RfAttenuatorState
			{
				OFF,
				ON
			};

			enum class BusyState
			{
				OFF,
				ON
			};

			enum class ClarifierState : int
			{
				OFF,
				ON
			};

			enum class MonitorOnOffValue : int
			{
				OFF,
				ON
			};

			enum class DialLockValue
			{
				OFF,
				ON
			};

			enum class KeyerValue
			{
				OFF,
				ON
			};

			enum class MoxSetVal
			{
				OFF,
				ON
			};

			enum class NarrowValue
			{
				OFF,
				ON
			};

			enum class NoiseBlankerStatusValue
			{
				OFF,
				ON
			};

			enum class NoiseReductionValue : int
			{
				OFF,
				ON
			};

			enum class PreAmpValue
			{
				IPO,
				AMP
			};

			enum class SplitValue
			{
				OFF,
				ON,
				ON_5KU

			};

			enum class TXWValue
			{
				OFF,
				ON
			};

			enum class TxSetValue
			{
				RadioTxOff_CatTxOff,
				RadioTxOff_CatTxOn,
				RadioTxOn_CatTxOff
			};

			enum class LockValue
			{
				Locked,
				Unlocked
			};

			enum class VoxStatusValue
			{
				OFF,
				ON
			};

			std::string DisplayMonitorFunction(MonitorFunction v);
			std::string DisplayNotchState(NotchState v);
			std::string DisplayKeyerMemory(KeyerMemoryChannel v);
			std::string DisplayInformationState(InformationState v);
			std::string DisplayBreakInState(BreakInState v);
			std::string DisplayCTCSSState(CTCSSState v);
			std::string DisplayCwSpotState(CWSpotState v);
			std::string DisplayMemoryChannelValue(MemoryChannelValue v);
			std::string DisplayInformationType(InformationType v);
			std::string DisplayBusyState(BusyState v);
			std::string DisplayClarifierState(ClarifierState v);
			std::string DisplayDialLockValue(DialLockValue v);
			std::string DisplayKeyerValue(KeyerValue v);
			std::string DisplayVFOChannelType(VFOChannelTypeValue v);
			std::string DisplayOperationType(OperationType v);
			std::string DisplayModeValue(ModeValue v);
			std::string DisplayMonitorOnOffValue(MonitorOnOffValue v);
			std::string DisplayTagValue(TagValue v);
			std::string DisplayRFAttenuatorState(RfAttenuatorState v);
			std::string DisplayIfShift(IfShiftValue v);
			std::string DisplaySpeechProcessorType(SpeechProcessorType v);
			std::string DisplaySpeechProcessorState(SpeechProcessorState v);
			std::string DisplayPowerSwitch(PowerSwitchValue v);
			std::string DisplayReadMeterType(ReadMeterType v);
			std::string DisplayRadioStatus(RadioStatusValue v);
			std::string DisplayMemoryChannelModeValue(MemoryChannelModeValue v);
			std::string DisplayScanState(ScanState v);
			std::string DisplayWidthState(WidthState v);
			std::string DisplayMenuFunction(MenuFunction f);
			std::string DisplayTunerSelect(TunerSelectValue v);
			std::string DisplayEQ3Value(EQ3FreqValue v);
			std::string DisplayEQ2Value(EQ2FreqValue v);
			std::string DisplayEQ1Value(EQ1FreqValue v);
			std::string DisplayFMChStep(FMChannelStepValue v);
			std::string DisplayAMChStep(AMChannelStepValue v);
			std::string DisplayDialStep(DialStep v);
			std::string DisplayAmFMDialStep(FMDialStep v);
			std::string DisplayAmFMDialStep(AMDialStep v);
			std::string DisplaySSBDialStep(SSBDialStep v);
			std::string DisplayQuickDial(QuickDialValue v);
			std::string DisplaySCPSpanFreq(SCPSpanFreqValue v);
			std::string DisplaySCPStart(SCPStartCycleValue v);
			std::string DisplayAPWidth(APFWidthValue v);
			std::string DisplaySSBTxBandPass(SSBTXBandPassValue v);
			std::string DisplayRTTYMarkFreq(RTTYMarkFreq v);
			std::string DisplayRTTYShiftFreq(RTTYShiftFreqValue v);
			std::string DisplayRTTYShiftPort(RTTYShiftPortValue v);
			std::string DisplayDCSPolarity(DCSPolarityValue v);
			std::string DisplayPSKTone(PSKToneValue v);
			std::string DisplayQskDelay(QskDelayTimeValue v);
			std::string DisplayBFO(DataBfoValue v);
			std::string DisplayPCKeying(PCKeyingValue v);
			std::string DisplayBFO(BfoValue v);
			std::string DisplayCwAutoMode(CwAutoModeValue v);
			std::string DisplayPTTSelect(PTTSelectValue v);
			std::string DisplayFreqHighCut(FreqHighCutValue v);
			std::string DisplayFreqLowCut(FreqLowCutValue v);
			std::string DisplayClarSelect(ClarSelectValue v);
			std::string DisplayAPO(APOValue v);
			std::string DisplayCatTOT(CatTOTValue v);
			std::string DisplayCatRate(CatRateValue v);
			std::string DisplayNbRejection(NBRejectionValue v);
			std::string DisplayNbWidth(NBWidthValue v);
			std::string DisplayNumberStyle(NumberStyleValue v);
			std::string DisplayBeaconInterval(int i);
			std::string DisplayPeakHold(PeakHoldType t);
			std::string DisplayEnableDisable(EnableDisableValue v);
			std::string DisplayKeyerType(KeyerTypeValue v);
			std::string DisplayBand(Band v);
			std::string DisplayCwWeight(int weight);
			std::string DisplayFrequency(int freq);

			struct ManualNotchValue
			{
				NotchCommandType Command{};
				union Value
				{
					NotchState state;
					int iValue;
				};
				Value Value{};
			};

			struct CTCSSToneFreqencyValue
			{
				CTCSSModeType Mode{};
				int Value{};
			};

			struct DimmerValues
			{
				int LCD_Contrast{};
				int BacklightLevel{};
				int LCD_Level{};
				int TX_Indicator{};
			};

			struct ContourValue
			{
				ContourType Type{};
				union Value
				{
					ContourState state;
					int Freq;
				};
				Value Value{};
			};

			struct InformationValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct OppositeInformationValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOBFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct IfShiftResultValue
			{
				IfShiftValue State{};
				int Frequency{};
			};

			struct KeyerMemoryValue
			{
				int ChannelNumber{};
				std::string Message{};
			};

			struct MonitorLevelValue
			{

				MonitorFunction f{};
				union Value
				{
					MonitorOnOffValue eVal;
					int iVal;
				};
				Value val{};
			};

			struct MemoryChannelTagValue
			{
				
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				MemoryChannelModeValue Mode{};
				CTCSSState CTCSS{};
				OperationType Operation{};
				TagValue TAG{};
				std::string TagString{};
			};

			struct MemoryChannelWriteValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				MemoryChannelModeValue Mode{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct MemoryChannelReadValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				VFOChannelTypeValue ChannelType{};
				ClarifierState Clarifier{};
				MemoryChannelModeValue Mode{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct SpeechProcessorSetting
			{
				SpeechProcessorType type;
				SpeechProcessorState state;
			};

			struct RadioInfoVal
			{
				InformationType Type;
				InformationState Value;
			};

			struct MeterVal
			{
				ReadMeterType Type;
				int Value;
			};

			struct WidthValue
			{
				WidthState State;
				int WidthCommand;
			};

			class VFO_A_TO_VFO_B
			{
			public:
				static std::string Set();
			};

			class AntennaTunerControl
			{
			public:
				static std::string Set(TunerState state);
				static std::string Read();
				static TunerState Answer(std::string data);
			};

			class VolumeLevel
			{
			public:
				static std::string Set(int Value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AutoInformation
			{
			public:
				static std::string Set(InformationState Value);
				static std::string Read();
				static InformationState Answer(std::string data);
			};

			class VFO_A_To_Memory
			{
			public:
				static std::string Set();
			};

			class VFO_B_TO_VFO_A
			{
			public:
				static std::string Set();
			};

			class AutoNotch
			{
			public:
				static std::string Set(NotchState Value);
				static std::string Read();
				static NotchState Answer(std::string data);
			};

			class BandDown
			{
			public:
				static std::string Set();
			};

			class BreakIn
			{
			public:
				static std::string Set(BreakInState Value);
				static std::string Read();
				static BreakInState Answer(std::string data);
			};

			class ManualNotch
			{
			public:
				static std::string Set(ManualNotchValue val);
				static std::string Read(NotchCommandType val);
				static ManualNotchValue Answer(std::string data);
			};

			class BandSelect
			{
			public:
				static std::string Set(Band Value);
			};

			class BandUP
			{
			public:
				static std::string Set();
			};

			class Busy
			{
			public:
				static std::string Read();

				static BusyState Answer(std::string data);
			};

			class Clarifier
			{
			public:
				static std::string Set(ClarifierState Value);
				static std::string Read();
				static ClarifierState Answer(std::string data);
			};

			class Channel_Up_Down
			{
			public:
				static std::string Set(UpDownState Value);
			};

			class CTCSSToneFrequency
			{
			public:
				static std::string Set(CTCSSToneFreqencyValue val);
				static std::string Read(CTCSSModeType mode);
				static CTCSSToneFreqencyValue Answer(std::string data);
			};

			class Contour
			{
			public:
				static std::string Set(ContourValue Type);
				static std::string Read(ContourValue Type);
				static ContourValue Answer(std::string data);
			};

			class CWSpot
			{
			public:
				static std::string Set(CWSpotState Value);
				static std::string Read();
				static CWSpotState Answer(std::string data);
			};

			class CTCSS
			{
			public:
				static std::string Set(CTCSSState Value);
				static std::string Read();
				static CTCSSState Answer(std::string data);
			};

			class Dimmer
			{
			public:
				static std::string set(DimmerValues val);
				static std::string Read();
				static DimmerValues Answer(std::string data);
			};

			class Mic_Down
			{
			public:
				static std::string Set();
			};

			class EncoderDown
			{
			public:
				static std::string Set(EncoderType enc, int Steps);
			};

			class EnterKey
			{
			public:
				static std::string Set();
			};

			class EncoderUp
			{
			public:
				static std::string Set(EncoderType enc, int Steps);
			};

			class BadMenuItemException : public std::runtime_error
			{
				MenuFunction _s;

			public:
				BadMenuItemException(MenuFunction s) : std::runtime_error("Bad Menu Function Parse!")
				{
					_s = s;
				}

				 MenuFunction ParsedFunction() const { return _s; }
			};

			class Menu
			{
				static std::string set(std::string s);

			public:
				static std::string SetAgcFastDelay(int msecs);

				static std::string ReadAgcFastDelay();

				static int AnswerAgcFastDelay(std::string dat);

				static std::string SetAgcMidDelay(int msecs);

				static std::string ReadAgcMidDelay();

				static int AnswerAgcMidDelay(std::string dat);

				static std::string SetAgcSlowDelay(int msecs);

				static std::string ReadAgcSlowDelay();

				static int AnswerAgcSlowDelay(std::string dat);

				static std::string SetLcdContrast(int level);

				static std::string ReadLcdContrast();

				static int AnswerLcdContrast(std::string data);

				static std::string SetBackliteDimmer(int level);

				static std::string ReadBackliteDimmer();

				static int AnswerBackliteDimmer(std::string data);

				static std::string SetLcdDimmer(int level);

				static std::string ReadLcdDimmer();

				static int AnswerLcdDimmer(std::string data);

				static std::string SetTxBusyDimmer(int level);

				static std::string ReadTxBusyDimmer();

				static int AnswerTxBusyDimmer(std::string data);

				static std::string SetPeakHold(PeakHoldType value);

				static std::string ReadPeakHold();

				static PeakHoldType AnswerPeakHold(std::string data);

				static std::string SetZinLed(EnableDisableValue value);

				static std::string ReadZinLed();

				static EnableDisableValue AnswerZinLed(std::string data);

				static std::string SetPopupMenuStyle(PopUpMenuStyle style);

				static std::string ReadPopupMenuStyle();

				static PopUpMenuStyle AnswerPopupMenuStyle(std::string data);

				static std::string SetDvsRxOutLevel(int Level);

				static std::string ReadDvsRxOutLevel();

				static int AnswerDvsRxOutLevel(std::string data);

				static std::string SetDvsTxOutLevel(int Level);

				static std::string ReadDvsTxOutLevel();

				static int AnswerDvsTxOutLevel(std::string data);

				static std::string SetKeyerType(KeyerTypeValue val);

				static std::string ReadKeyerType();

				static KeyerTypeValue AnswerKeyerType(std::string data);

				static std::string SetKeyerDotDash(KeyerDotDashValue val);

				static std::string ReadKeyerDotDash();

				static KeyerDotDashValue AnswerKeyerDotDash(std::string data);

				static std::string SetCwWeight(int Weight);

				static std::string ReadCwWeight();

				static int AnswerCwWeight(std::string data);

				static std::string SetBeaconInterval(int value);

				static std::string ReadBeaconInterval();

				static int AnswerBeaconInterval(std::string data);

				static std::string SetNumberStyle(NumberStyleValue val);

				static std::string ReadNumberStyle();

				static NumberStyleValue AnswerNumberStyle(std::string data);

				static std::string SetContestNumber(int Value);

				static std::string ReadContestNumber();

				static int AnswerContestNumber(std::string data);

				static std::string SetCWMemory1(CWMemoryTypeValue val);

				static std::string ReadCWMemory1();

				static CWMemoryTypeValue AnswerCWMemory1(std::string data);

				static std::string SetCWMemory2(CWMemoryTypeValue val);

				static std::string ReadCWMemory2();

				static CWMemoryTypeValue AnswerCWMemory2(std::string data);

				static std::string SetCWMemory3(CWMemoryTypeValue val);

				static std::string ReadCWMemory3();

				static CWMemoryTypeValue AnswerCWMemory3(std::string data);

				static std::string SetCWMemory4(CWMemoryTypeValue val);

				static std::string ReadCWMemory4();

				static CWMemoryTypeValue AnswerCWMemory4(std::string data);

				static std::string SetCWMemory5(CWMemoryTypeValue val);

				static std::string ReadCWMemory5();

				static CWMemoryTypeValue AnswerCWMemory5(std::string data);

				static std::string SetNbWidth(NBWidthValue value);

				static std::string ReadNbWidth();

				static NBWidthValue AnswerNbWidth(std::string data);

				static std::string SetNbRejection(NBRejectionValue value);

				static std::string ReadNbRejection();

				static NBRejectionValue AnswerNbRejection(std::string data);

				static std::string SetNbLevel(int level);

				static std::string ReadNbLevel();

				static int AnswerNbLevel(std::string data);

				static std::string SetBeepLevel(int level);

				static std::string ReadBeepLevel();

				static int AnswerBeepLevel(std::string data);

				static std::string SetRfSqlVr(RfSqlVrValue val);

				static std::string ReadRfSqlVr();

				static RfSqlVrValue AnswerRfSqlVr(std::string data);

				static std::string SetCatRate(CatRateValue val);

				static std::string ReadCatRate();

				static CatRateValue AnswerCatRate(std::string data);

				static std::string SetCatTOT(CatTOTValue val);

				static std::string ReadCatTOT();

				static CatTOTValue AnswerCatTOT(std::string data);

				static std::string SetCatRTS(EnableDisableValue val);

				static std::string ReadCatRTS();

				static EnableDisableValue AnswerCatRTS(std::string data);

				static std::string SetMemGroup(EnableDisableValue val);

				static std::string ReadMemGroup();

				static EnableDisableValue AnswerMemGroup(std::string data);

				static std::string SetFMSetting(EnableDisableValue val);

				static std::string ReadFMSetting();

				static EnableDisableValue AnswerFMSetting(std::string data);

				static std::string SetRecSetting(EnableDisableValue val);

				static std::string ReadRecSetting();

				static EnableDisableValue AnswerRecSetting(std::string data);

				static std::string SetATASSetting(EnableDisableValue val);

				static std::string ReadATASSetting();

				static EnableDisableValue AnswerATASSetting(std::string data);

				static std::string SetQuickSplitFreq(int val);

				static std::string ReadQuickSplitFreq();

				static int AnswerQuickSplitFreq(std::string data);

				static std::string SetTxTOT(int val);

				static std::string ReadTXTOT();

				static int AnswerTXTOT(std::string data);

				static std::string SetMicScan(EnableDisableValue val);

				static std::string ReadMicScan();

				static EnableDisableValue AnswerMicScan(std::string data);

				static std::string SetMicScanResume(MicScanResumeValue val);

				static std::string ReadMicScanResume();

				static MicScanResumeValue AnswerMicScanResume(std::string data);

				static std::string SetRefFreqAdjust(int val);

				static std::string ReadRefFreqAdjust();

				static int AnswerRefFreqAdjust(std::string data);

				static std::string SetClarSelect(ClarSelectValue val);

				static std::string ReadClarSelect();

				static ClarSelectValue AnswerClarSelect(std::string data);

				static std::string SetApo(APOValue val);

				static std::string ReadApo();

				static APOValue AnswerApo(std::string data);

				static std::string SetFanControl(FanControlValue val);

				static std::string ReadFanControl();

				static FanControlValue AnswerFanControl(std::string data);

				static std::string SetAMLowCutFreq(FreqLowCutValue val);

				static std::string ReadAMLowCutFreq();

				static FreqLowCutValue AnswerAMLowCutFreq(std::string data);

				static std::string SetAMLowCutSlope(FreqSlopeValue val);

				static std::string ReadAMLowCutSlope();

				static FreqSlopeValue AnswerAMLowCutSlope(std::string data);

				static std::string SetAMHighCutFreq(FreqHighCutValue val);

				static std::string ReadAMHighCutFreq();

				static FreqHighCutValue AnswerAMHighCutFreq(std::string data);

				static std::string SetAMHighCutSlope(FreqSlopeValue val);

				static std::string ReadAMHighCutSlope();

				static FreqSlopeValue AnswerAMHighCutSlope(std::string data);

				static std::string SetAMMicSelect(AudioInputValue val);

				static std::string ReadAMMicSelect();

				static AudioInputValue AnswerAMMicSelect(std::string data);

				static std::string SetAMOutLevel(int val);

				static std::string ReadAMOutLevel();

				static int AnswerAMOutLevel(std::string data);

				static std::string SetAMMicLevel(int val);

				static std::string ReadAMMicLevel();

				static int AnswerAMMicLevel(std::string data);

				static std::string SetAMPTTSelect(PTTSelectValue val);

				static std::string ReadAMPTTSelect();

				static PTTSelectValue AnswerAMPTTSelect(std::string data);

				static std::string SetCWLowCutFreq(FreqLowCutValue val);

				static std::string ReadCWLowCutFreq();

				static FreqLowCutValue AnswerCWLowCutFreq(std::string data);

				static std::string SetCWLowCutSlope(FreqSlopeValue val);

				static std::string ReadCWLowCutSlope();

				static FreqSlopeValue AnswerCWLowCutSlope(std::string data);

				static std::string SetCWHighCutFreq(FreqHighCutValue val);

				static std::string ReadCWHighCutFreq();

				static FreqHighCutValue AnswerCWHighCutFreq(std::string data);

				static std::string SetCWHighCutSlope(FreqSlopeValue val);

				static std::string ReadCWHighCutSlope();

				static FreqSlopeValue AnswerCWHighCutSlope(std::string data);

				static std::string SetCWOutLevel(int val);

				static std::string ReadCWOutLevel();

				static int AnswerCWOutLevel(std::string data);

				static std::string SetCWAutoMode(CwAutoModeValue val);

				static std::string ReadCWAutoMode();

				static CwAutoModeValue AnswerCWAutoMode(std::string data);

				static std::string SetCWBFO(BfoValue val);

				static std::string ReadCWBFO();

				static BfoValue AnswerCWBFO(std::string data);

				static std::string SetCWBreakkInType(CwBreakInType val);

				static std::string ReadCWBreakInType();

				static CwBreakInType AnswerCWBreakInType(std::string data);

				static std::string SetCWBreakkInDelay(int val);

				static std::string ReadCWBreakInDelay();

				static int AnswerCWBreakInDelay(std::string data);

				static std::string SetCWWaveShape(CwWaveShapeValue val);

				static std::string ReadCWWaveShape();

				static CwWaveShapeValue AnswerCWWaveShape(std::string data);

				static std::string SetCWFreqDisplay(CwFreqDisplayValue val);

				static std::string ReadCWFreqDisplay();

				static CwFreqDisplayValue AnswerCWFreqDisplay(std::string data);

				static std::string SetPCKeying(PCKeyingValue val);

				static std::string ReadPCKeying();

				static PCKeyingValue AnswerPCKeying(std::string data);

				static std::string SetQSKDelayTime(QskDelayTimeValue val);

				static std::string ReadQSKDelayTime();

				static QskDelayTimeValue AnswerQSKDelayTime(std::string data);

				static std::string SetDataMode(DataModeValue val);

				static std::string ReadDataMode();

				static DataModeValue AnswerDataMode(std::string data);

				static std::string SetPSKTone(PSKToneValue val);

				static std::string ReadPSKTone();

				static PSKToneValue AnswerPSKTone(std::string data);

				static std::string SetOtherDisp(int val);

				static std::string ReadOtherDisp();

				static int AnswerOtherDisp(std::string data);

				static std::string SetOtherShift(int val);

				static std::string ReadOtherShift();

				static int AnswerOtherShift(std::string data);

				static std::string SetDATALowCutFreq(FreqLowCutValue val);

				static std::string ReadDATALowCutFreq();

				static FreqLowCutValue AnswerDATALowCutFreq(std::string data);

				static std::string SetDATALowCutSlope(FreqSlopeValue val);

				static std::string ReadDATALowCutSlope();

				static FreqSlopeValue AnswerDATALowCutSlope(std::string data);

				static std::string SetDATAHighCutFreq(FreqHighCutValue val);

				static std::string ReadDATAHighCutFreq();

				static FreqHighCutValue AnswerDATAHighCutFreq(std::string data);

				static std::string SetDATAHighCutSlope(FreqSlopeValue val);

				static std::string ReadDATAHighCutSlope();

				static FreqSlopeValue AnswerDATAHighCutSlope(std::string data);

				static std::string SetDATAInSelect(AudioInputValue val);

				static std::string ReadDATAInSelect();

				static AudioInputValue AnswerDATAInSelect(std::string data);

				static std::string SetDATAPTTSelect(PTTSelectValue val);

				static std::string ReadDATAPTTSelect();

				static PTTSelectValue AnswerDATAPTTSelect(std::string data);

				static std::string SetDATAOutLevel(int val);

				static std::string ReadDATAOutLevel();

				static int AnswerDATAOutLevel(std::string data);

				static std::string SetDATABFO(DataBfoValue val);

				static std::string ReadDATABFO();

				static DataBfoValue AnswerDATABFO(std::string data);

				static std::string SetFMMicSelect(AudioInputValue val);

				static std::string ReadFMMicSelect();

				static AudioInputValue AnswerFMMicSelect(std::string data);

				static std::string SetFMOutLevel(int val);

				static std::string ReadFMOutLevel();

				static int AnswerFMOutLevel(std::string data);

				static std::string SetPktPTTSelect(PTTSelectValue val);

				static std::string ReadPktPTTSelect();

				static PTTSelectValue AnswerPktPTTSelect(std::string data);

				static std::string SetRptShift28MHZ(int val);

				static std::string ReadRptShift28MHZ();

				static int AnswerRptShift28MHZ(std::string data);

				static std::string SetRptShift50MHZ(int val);

				static std::string ReadRptShift50MHZ();

				static int AnswerRptShift50MHZ(std::string data);

				static std::string SetDCSPolarity(DCSPolarityValue val);

				static std::string ReadDCSPolarity();

				static DCSPolarityValue AnswerDCSPolarity(std::string data);

				static std::string SetRTTYLowCutFreq(FreqLowCutValue val);

				static std::string ReadRTTYLowCutFreq();

				static FreqLowCutValue AnswerRTTYLowCutFreq(std::string data);

				static std::string SetRTTYLowCutSlope(FreqSlopeValue val);

				static std::string ReadRTTYLowCutSlope();

				static FreqSlopeValue AnswerRTTYLowCutSlope(std::string data);

				static std::string SetRTTYHighCutFreq(FreqHighCutValue val);

				static std::string ReadRTTYHighCutFreq();

				static FreqHighCutValue AnswerRTTYHighCutFreq(std::string data);

				static std::string SetRTTYHighCutSlope(FreqSlopeValue val);

				static std::string ReadRTTYHighCutSlope();

				static FreqSlopeValue AnswerRTTYHighCutSlope(std::string data);

				static std::string SetRTTYShiftPort(RTTYShiftPortValue val);

				static std::string ReadRTTYShiftPort();

				static RTTYShiftPortValue AnswerRTTYShiftPort(std::string data);

				static std::string SetRTTYPolarityR(RTTYPolarityValue val);

				static std::string ReadRTTYPolarityR();

				static RTTYPolarityValue AnswerRTTYPolarityR(std::string data);

				static std::string SetRTTYPolarityT(RTTYPolarityValue val);

				static std::string ReadRTTYPolarityT();

				static RTTYPolarityValue AnswerRTTYPolarityT(std::string data);

				static std::string SetRTTYOutLevel(int val);

				static std::string ReadRTTYOutLevel();

				static int AnswerRTTYOutLevel(std::string data);

				static std::string SetRTTYShiftFreq(RTTYShiftFreqValue val);

				static std::string ReadRTTYShiftFreq();

				static RTTYShiftFreqValue AnswerRTTYShiftFreq(std::string data);

				static std::string SetRTTYMarkFreq(RTTYMarkFreq val);

				static std::string ReadRTTYMarkFreq();

				static RTTYMarkFreq AnswerRTTYMarkFreq(std::string data);

				static std::string SetRTTYBFO(DataBfoValue val);

				static std::string ReadRTTYBFO();

				static DataBfoValue AnswerRTTYBFO(std::string data);

				static std::string SetSSBLowCutFreq(FreqLowCutValue val);

				static std::string ReadSSBLowCutFreq();

				static FreqLowCutValue AnswerSSBLowCutFreq(std::string data);

				static std::string SetSSBLowCutSlope(FreqSlopeValue val);

				static std::string ReadSSBLowCutSlope();

				static FreqSlopeValue AnswerSSBLowCutSlope(std::string data);

				static std::string SetSSBHighCutFreq(FreqHighCutValue val);

				static std::string ReadSSBHighCutFreq();

				static FreqHighCutValue AnswerSSBHighCutFreq(std::string data);

				static std::string SetSSBHighCutSlope(FreqSlopeValue val);

				static std::string ReadSSBHighCutSlope();

				static FreqSlopeValue AnswerSSBHighCutSlope(std::string data);

				static std::string SetSSBMicSelect(AudioInputValue val);

				static std::string ReadSSBMicSelect();

				static AudioInputValue AnswerSSBMicSelect(std::string data);

				static std::string SetSSBOutLevel(int val);

				static std::string ReadSSBOutLevel();

				static int AnswerSSBOutLevel(std::string data);

				static std::string SetSSBBFO(BfoValue val);

				static std::string ReadSSBBFO();

				static BfoValue AnswerSSBBFO(std::string data);

				static std::string SetSSBPTTSelect(PTTSelectValue val);

				static std::string ReadSSBPTTSelect();

				static PTTSelectValue AnswerSSBPTTSelect(std::string data);

				static std::string SetSSBTxBPF(SSBTXBandPassValue val);

				static std::string ReadSSBTxBPF();

				static SSBTXBandPassValue AnswerSSBTxBPF(std::string data);

				static std::string SetAPFWidth(APFWidthValue val);

				static std::string ReadAPFWidth();

				static APFWidthValue AnswerAPFWidth(std::string data);

				static std::string SetCountourLevel(int val);

				static std::string ReadCountourLevel();

				static int AnswerCountourLevel(std::string data);

				static std::string SetCountourWidth(int val);

				static std::string ReadCountourWidth();

				static int AnswerCountourWidth(std::string datadata);

				static std::string SetIFNotchWidth(IFNotchWidth val);

				static std::string ReadIFNotchWidth();

				static IFNotchWidth AnswerIFNotchWidth(std::string data);

				static std::string SetSCPStartCycle(SCPStartCycleValue val);

				static std::string ReadSCPStartCycle();

				static SCPStartCycleValue AnswerSCPStartCycle(std::string data);

				static std::string SetSCPSpanFreq(SCPSpanFreqValue val);

				static std::string ReadSCPSpanFreq();

				static SCPSpanFreqValue AnswerSCPSpanFreq(std::string data);

				static std::string SetQuickDial(QuickDialValue val);

				static std::string ReadQuickDial();

				static QuickDialValue AnswerQuickDial(std::string data);

				static std::string SetAMDialStep(AMDialStep val);

				static std::string ReadAMDialStep();

				static AMDialStep AnswerAMDialStep(std::string data);

				static std::string SetSSBDialStep(SSBDialStep val);

				static std::string ReadSSBDialStep();

				static SSBDialStep AnswerSSBDialStep(std::string data);

				static std::string SetFMDialStep(FMDialStep val);

				static std::string ReadFMDialStep();

				static FMDialStep AnswerFMDialStep(std::string data);

				static std::string SetDialStep(DialStep val);

				static std::string ReadDialStep();

				static DialStep AnswerDialStep(std::string data);

				static std::string SetAmChStep(AMChannelStepValue val);

				static std::string ReadAmChStep();

				static AMChannelStepValue AnswerAmChStep(std::string data);

				static std::string SetFmChStep(FMChannelStepValue val);

				static std::string ReadFmChStep();

				static FMChannelStepValue AnswerFmChStep(std::string data);

				static std::string SetEQ1Freq(EQ1FreqValue val);

				static std::string ReadEQ1Freq();

				static EQ1FreqValue AnswerEQ1Freq(std::string data);

				static std::string SetEQ1Level(int val);

				static std::string ReadEQ1Level();

				static int AnswerEQ1Level(std::string data);

				static std::string SetEQ1Bwth(int val);

				static std::string ReadEQ1Bwth();

				static int AnswerEQ1Bwth(std::string data);

				static std::string SetEQ2Freq(EQ2FreqValue val);

				static std::string ReadEQ2Freq();

				static EQ2FreqValue AnswerEQ2Freq(std::string data);

				static std::string SetEQ2Level(int val);

				static std::string ReadEQ2Level();

				static int AnswerEQ2Level(std::string data);

				static std::string SetEQ2Bwth(int val);

				static std::string ReadEQ2Bwth();

				static int AnswerEQ2Bwth(std::string data);

				static std::string SetEQ3Freq(EQ3FreqValue val);

				static std::string ReadEQ3Freq();

				static EQ3FreqValue AnswerEQ3Freq(std::string data);

				static std::string SetEQ3Level(int val);

				static std::string ReadEQ3Level();

				static int AnswerEQ3Level(std::string data);

				static std::string SetEQ3Bwth(int val);

				static std::string ReadEQ3Bwth();

				static int AnswerEQ3Bwth(std::string data);

				static std::string SetPEQ1Freq(EQ1FreqValue val);

				static std::string ReadPEQ1Freq();

				static EQ1FreqValue AnswerPEQ1Freq(std::string data);

				static std::string SetPEQ1Level(int val);

				static std::string ReadPEQ1Level();

				static int AnswerPEQ1Level(std::string data);

				static std::string SetPEQ1Bwth(int val);

				static std::string ReadPEQ1Bwth();

				static int AnswerPEQ1Bwth(std::string data);

				static std::string SetPEQ2Freq(EQ2FreqValue val);

				static std::string ReadPEQ2Freq();

				static EQ2FreqValue AnswerPEQ2Freq(std::string data);

				static std::string SetPEQ2Level(int val);

				static std::string ReadPEQ2Level();

				static int AnswerPEQ2Level(std::string data);

				static std::string SetPEQ2Bwth(int val);

				static std::string ReadPEQ2Bwth();

				static int AnswerPEQ2Bwth(std::string data);

				static std::string SetPEQ3Freq(EQ3FreqValue val);

				static std::string ReadPEQ3Freq();

				static EQ3FreqValue AnswerPEQ3Freq(std::string data);

				static std::string SetPEQ3Level(int val);

				static std::string ReadPEQ3Level();

				static int AnswerPEQ3Level(std::string data);

				static std::string SetPEQ3Bwth(int val);

				static std::string ReadPEQ3Bwth();

				static int AnswerPEQ3Bwth(std::string data);

				static std::string SetHfSsbPwr(int val);

				static std::string ReadHfSsbPwr();

				static int AnswerHfSsbPwr(std::string data);

				static std::string SetHfAmPwr(int val);

				static std::string ReadHfAmPwr();

				static int AnswerHfAmPwr(std::string data);

				static std::string SetHfPwr(int val);

				static std::string ReadHfPwr();

				static int AnswerHfPwr(std::string data);

				static std::string Set50mSsbPwr(int val);

				static std::string Read50mSsbPwr();

				static int Answer50mSsbPwr(std::string data);

				static std::string Set50mAmPwr(int val);

				static std::string Read50mAmPwr();

				static int Answer50mAmPwr(std::string data);

				static std::string Set50mPwr(int val);

				static std::string Read50mPwr();

				static int Answer50mPwr(std::string data);

				static std::string SetSSBMicGain(int val);

				static std::string ReadSSBMicGain();

				static int AnswerSSBMicGain(std::string data);

				static std::string SetAMMicGain(int val);

				static std::string ReadAMMicGain();

				static int AnswerAMMicGain(std::string data);

				static std::string SetFMMicGain(int val);

				static std::string ReadFMMicGain();

				static int AnswerFMMicGain(std::string data);

				static std::string SetDATAMicGain(int val);

				static std::string ReadDATAMicGain();

				static int AnswerDATAMicGain(std::string data);

				static std::string SetSSBDataGain(int val);

				static std::string ReadSSBDataGain();

				static int AnswerSSBDataGain(std::string data);

				static std::string SetAMDataGain(int val);

				static std::string ReadAMDataGain();

				static int AnswerAMDataGain(std::string data);

				static std::string SetFMDataGain(int val);

				static std::string ReadFMDataGain();

				static int AnswerFMDataGain(std::string data);

				static std::string SetDataDataGain(int val);

				static std::string ReadDataDataGain();

				static int AnswerDataDataGain(std::string data);

				static std::string SetTunerSelect(TunerSelectValue val);

				static std::string ReadTunerSelect();

				static TunerSelectValue AnswerTunerSelect(std::string data);

				static std::string SetVoxSelect(VoxSelectValue val);

				static std::string ReadVoxSelect();

				static VoxSelectValue AnswerVoxSelect(std::string data);

				static std::string SetVoxGain(int val);

				static std::string ReadVoxGain();

				static int AnswerVoxGain(std::string data);

				static std::string SetVoxDelay(int val);

				static std::string ReadVoxDelay();

				static int AnswerVoxDelay(std::string data);

				static std::string SetAntiVoxGain(int val);

				static std::string ReadAntiVoxGain();

				static int AnswerAntiVoxGain(std::string data);

				static std::string SetDataVoxGain(int val);

				static std::string ReadDataVoxGain();

				static int AnswerDataVoxGain(std::string data);

				static std::string SetDataVoxDelay(int val);

				static std::string ReadDataVoxDelay();

				static int AnswerDataVoxDelay(std::string data);

				static std::string SetDataAntiVoxGain(int val);

				static std::string ReadDataAntiVoxGain();

				static int AnswerDataAntiVoxGain(std::string data);

				static std::string SetEmergencyFreq(EnableDisableValue val);

				static std::string ReadEmergencyFreq();

				static EnableDisableValue AnswerEmergencyFreq(std::string data);

				static std::string SetReset(ResetValue val);

				static std::string ReadMainVersion();

				static std::string AnswerMainVersion(std::string data);

				static std::string ReadDSPVersion();

				static std::string AnswerDSPVersion(std::string data);

				static std::string ReadLCDVersion();

				static std::string AnswerLCDVersion(std::string data);
			}; // end class Menu

			class VFO_A_FREQ
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class VFO_B_FREQ
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FAST_STEP
			{
			public:
				static std::string Set(VFOFastStepValue val);
				static std::string Read();
				static VFOFastStepValue Answer(std::string data);
			};

			class AGC_FUNCTION
			{
			public:
				static std::string Set(AGCSetValue val);
				static std::string Read();
				static AGCReadValue Answer(std::string data);
			};

			class IDENTIFICATION
			{
			public:
				static std::string Read();
				static Yaesu::RigType Answer(std::string data);
			};

			class INFORMATION
			{
			public:
				static std::string Read();
				static InformationValue Answer(std::string data);
			};

			class IF_SHIFT
			{
			public:
				static std::string Set(IfShiftValue val, int freq);
				static std::string Read();
				static IfShiftResultValue Answer(std::string data);
			};

			class KeyerMemory
			{
			public:
				static std::string Set(KeyerMemoryValue val);
				static std::string Read(int MemoryChannel);
				static KeyerMemoryValue Answer(std::string data);
			};

			class KeyPitch
			{
			public:
				static std::string Set(KeyPitchValue val);
				static std::string Read();
				static KeyPitchValue Answer(std::string data);
			};

			class Keyer
			{
			public:
				static std::string Set(KeyerValue val);
				static std::string Read();
				static KeyerValue Answer(std::string data);
			};

			class KeyerSpeed
			{
			public:
				static std::string Set(KeyerSpeedVal val);
				static std::string Read();
				static KeyerSpeedVal Answer(std::string data);
			};

			class CWKeyingPlayback
			{
			public:
				static std::string Set(KeyerMemoryChannel Val);
			};

			class VFODialLock
			{
			public:
				static std::string Set(DialLockValue val);
				static std::string Read();
				static DialLockValue Answer(std::string data);
			};

			class LoadMessage
			{
			public:
				static std::string Set(DVSRecordingValue val);
				static std::string Read();
				static DVSRecordingValue Answer(std::string data);
			};

			class MemoryChannelToVFOA
			{
			public:
				static std::string Set();
			};

			class MemoryChannel
			{
			public:
				static std::string Set(MemoryChannelValue val);
				static std::string Read();
				static MemoryChannelValue Answer(std::string data);
			};

			class OperatingMode
			{
			public:
				static std::string Set(ModeValue val);
				static std::string Read();
				static ModeValue Answer(std::string data);
			};

			class MicGain
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class MonitorLevel
			{
			public:
				static std::string Set(MonitorLevelValue val);
				static std::string Read(MonitorFunction val);
				static MonitorLevelValue Answer(std::string data);
			};

			class MemoryChannelRead
			{
			public:
				static std::string Read(MemoryChannelValue val);
				static MemoryChannelReadValue Answer(std::string data);
			};

			class MeterSW
			{
			public:
				static std::string Set(MeterType val);
				static std::string Read();
				static MeterType Answer(std::string data);
			};

			class MemoryWriteTag
			{
			public:
				static std::string Set(MemoryChannelTagValue val);
				static std::string Read(MemoryChannelValue val);
				static MemoryChannelTagValue Answer(std::string data);
			};

			class MemoryChannelWrite
			{
			public:
				static std::string Set(MemoryChannelWriteValue val);
			};

			class MoxSet
			{
			public:
				static std::string Set(MoxSetVal val);
				static std::string Read();
				static MoxSetVal Answer(std::string data);
			};

			class Narrow
			{
			public:
				static std::string Set(NarrowValue val);
				static std::string Read();
				static NarrowValue Answer(std::string data);
			};

			class NoiseBlankerStatus
			{
			public:
				static std::string Set(NoiseBlankerStatusValue val);
				static std::string Read();
				static NoiseBlankerStatusValue Answer(std::string data);
			};

			class NoiseBlankerLevel
			{
			public:
				/// <param name="val"> - Values between 0 and 10</param>
				/// <returns>std::string</returns>
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class NoiseReduction
			{
			public:
				static std::string Set(NoiseReductionValue val);
				static std::string Read();
				static NoiseReductionValue Answer(std::string data);
			};

			class OppositeBandInformation
			{
			public:
				static std::string Read();
				static OppositeInformationValue Answer(std::string data);
			};

			class OffSet
			{
			public:
				static std::string Set(OperationType val);
				static std::string Read();
				static OperationType Answer(std::string data);
			};

			class PreAmp
			{
			public:
				static std::string Set(PreAmpValue val);
				static std::string Read();
				static PreAmpValue Answer(std::string data);
			};

			class PlayBack
			{
			public:
				static std::string Set(DVSRecordingValue val);
				static std::string SetB(int val);
				static std::string Read();
				static DVSRecordingValue Answer(std::string data);
			};

			class PowerControl
			{
			public:
				/// <param name="val"> - Values between 0 and 100</param>
				/// <returns>std::string</returns>
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SpeechProcessorLevel
			{
			public:
				/// <param name="val"> - Values between 0 and 100</param>
				/// <returns>std::string</returns>
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SpeechProcessor
			{
			public:
				static std::string Set(SpeechProcessorSetting val);
				static std::string Read(SpeechProcessorType state);
				static SpeechProcessorSetting Answer(std::string data);
			};

			class PowerSwitch
			{
			public:
				static std::string Set(PowerSwitchValue val);
				static std::string Read();
				static PowerSwitchValue Answer(std::string data);
			};

			class QMBStore
			{
			public:
				static std::string Set();
			};

			class QMBRecall
			{
			public:
				static std::string Set();
			};

			class QMBSplit
			{
			public:
				static std::string Set();
			};

			class RFAttenuator
			{
			public:
				static std::string Set(RfAttenuatorState val);
				static std::string Read();
				static RfAttenuatorState Answer(std::string data);
			};

			class ClarClear
			{
			public:
				static std::string Set();
			};

			class ClarDown
			{
			public:
				/// <param name="val">Values between 0 and 9999.</param>
				/// <returns></returns>
				static std::string Set(int val);
			};

			class ClarUp
			{
			public:
				static std::string Set(int val);
			};

			class RFGain
			{
			public:
				/// <param name="val"> - Values between 0 and 30</param>
				/// <returns></returns>
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class RadioInformation
			{
			public:
				enum class StateType : int
				{
					HI_SWR,
					REC = 3,
					PLAY,
					TX_LED = 10,
					RX_LED = 11
				};
				enum class Value : int
				{
					OFF,
					ON
				};
				static std::string Read(StateType type);
				static RadioInfoVal Answer(std::string data);
			};

			class NoiseReductionLevel
			{
			public:
				static std::string Set(int Val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class ReadMeter
			{
			public:
				static std::string Read(ReadMeterType type);
				static MeterVal Answer(std::string data);
			};

			class RadioStatus
			{
			public:
				static std::string Read();
				static RadioStatusValue Answer(std::string data);
			};

			class RxClarifierPlusOffset
			{
			public:
				static std::string Set(int val);
			};

			class Scan
			{
			public:
				static std::string Set(ScanState val);
				static std::string Read();
				static ScanState Answer(std::string data);
			};

			class CWBreakInDelay
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class Width
			{
			public:
				static std::string Set(WidthValue val);
				static std::string Read();
				static WidthValue Answer(std::string data);
			};

			class SMeterReading
			{
			public:
				static std::string Read();
				static int Answer(std::string data);
			};

			class SquelchLevel
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class Split
			{
			public:
				static std::string Set(SplitValue val);
				static std::string Read();
				static SplitValue Answer(std::string data);
			};

			class SwapVfo
			{
			public:
				static std::string Set();
			};

			class TXW
			{
			public:
				static std::string Set(TXWValue val);
				static std::string Read();
				static TXWValue Answer(std::string data);
			};

			class TxSet
			{
			public:
				static std::string Set(TxSetValue val);
				static std::string Read();
				static TxSetValue Answer(std::string data);
			};

			class PLLUnlockStatus
			{
			public:
				static std::string Read();
				static LockValue Answer(std::string data);
			};

			class Up
			{
			public:
				static std::string Set();
			};

			class VoxDelayTime
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class VoxGain
			{
			public:
				static std::string Set(int val);
				static std::string Read();
				static int Answer(std::string data);
			};

			class VFO_A_toMemoryChannel
			{
			public:
				static std::string Set();
			};

			class VoxStatus
			{
			public:
				static std::string Set(VoxStatusValue val);
				static std::string Read();
				static VoxStatusValue Answer(std::string data);
			};

			class ZeroIn
			{
			public:
				static std::string Set();
			};
		
		}; // end FT891

		namespace FTDX10
		{
			enum class TunerState : int
			{
				OFF,
				ON,
				StartStop
			};

			using Yaesu::Common::OnOffValue;

			enum class EnabledDisabledValue : int
			{
				DISABLE,
				ENABLE
			};

			enum class PSKModeValue : int
			{
				BPSK,
				QPSK
			};

			enum class TXDiddleValue :int
			{
				OFF,
				BLANK,
				LTRS
			};

			enum class BaudotCodeType : int
			{
				CCIT,
				US
			};

			enum class CWAutoModeValue : int
			{
				OFF,
				_50Mhz,
				ON
			};

			enum class CwFrequencyDisplayType : int
			{
				DIRECT_FREQ,
				PITCH_OFFSET
			};

			enum class PskToneValue : int
			{
				_1000Hz,
				_1500Hz,
				_2000hz
			};

			enum class MainSubValue :int
			{
				MAIN,
				SUB
			};

			enum class ManualNotchType : int
			{
				OnOff,
				Frequency
			};


			enum class Band : int
			{
				_160_Meters,
				_80_Meters,
				_60_Meters,
				_40_Meters,
				_30_Meters,
				_20_Meters,
				_17_Meters,
				_15_Meters,
				_12_Meters,
				_10_Meters,
				_6_Meters,
				GEN,
				MW
			};

			enum class ChannelDirection : int
			{
				UP,
				DOWN
			};


			struct ManualNotchValue
			{
				union value
				{
					OnOffValue State;
					int Frequency;
				};
				ManualNotchType Type;
				value Value;
			};

			class AF_GAIN
			{
			public:
				static std::string Set(int Value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class AutoInformation
			{
			public:
				static std::string Set(OnOffValue);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class VFO_A_TO_VFO_B
			{
			public:
				static std::string Set();
			};

			class AntennaTunerControl
			{
			public:
				static std::string Set(TunerState value);
				static std::string Read();
				static TunerState Answer(std::string data);
			};


			class VFO_A_toMemoryChannel
			{
			public:
				static std::string Set();
			};

			class AMCOutPutLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AntiVoxLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class VFO_B_TO_VFO_A
			{
			public:
				static std::string Set();
			};



			class AutoNotch
			{
			public:
				static std::string Set(OnOffValue);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class BandDown
			{
			public:
				static std::string Set(MainSubValue value);

			};


			class BreakIn
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class VFO_B_toMemoryChannel
			{
			public:
				static std::string Set();

			};


			class ManualNotch
			{
			public:
				static std::string Set(ManualNotchValue value);
				static std::string Read(ManualNotchType Type);
				static ManualNotchValue Answer(std::string data);
			};


			class BandSelect
			{
			public:
				static std::string Set(Band value);

			};


			class BandUp
			{
			public:
				static std::string Set(MainSubValue value);

			};

			class Busy
			{
			public:
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum class ClarifierType : int
			{
				Setting,
				Frequency
			};

			struct ClarifierValue
			{
				MainSubValue Band;
				ClarifierType Type;
				union value {
					OnOffValue RXOnOff;
					OnOffValue TXOnOff;
					int Frequency;
				};
				value Value;
			};



			class ClarifierOnOff
			{
			public:
				static std::string Set(ClarifierValue value);
				static std::string Read(ClarifierValue value);
				static ClarifierValue Answer(std::string data);
			};


			class ChannelUpDown
			{
			public:
				static std::string Set(ChannelDirection value);
			};

			struct CTCSSToneValue
			{
				MainSubValue Band;
				int Value;
			};


			class CTCSSToneFrequency
			{
			public:
				static std::string Set(CTCSSToneValue value);
				static std::string Read(MainSubValue value);
				static CTCSSToneValue Answer(std::string data);
			};

			enum class ContourType : int
			{
				OnOff,
				Freq,
				APFOnOff,
				APFFreq
			};

			struct ContourValue
			{
				ContourType Type;
				union value
				{
					OnOffValue OnOff;
					int Frequency;
				};

				value Value;
			};


			class Countour
			{
			public:
				static std::string Set(ContourValue value);
				static std::string Read(ContourType type);
				static ContourValue Answer(std::string data);
			};


			class CWSpot
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum class CTCSSStateType : int
			{
				OFF,
				ENC_DEC,
				ENC
			};

			struct CTCSSStateValue
			{
				MainSubValue Band;
				CTCSSStateType Type;
			};


			class CTCSS
			{
			public:
				static std::string Set(CTCSSStateValue value);
				static std::string Read(MainSubValue value);
				static CTCSSStateValue Answer(std::string data);
			};

			struct DimmerValue
			{
				int TFTContrast;
				int TFTBrightness;
				int LEDBrightness;
			};


			class Dimmer
			{
			public:
				static std::string Set(DimmerValue value);
				static std::string Read();
				static DimmerValue Answer(std::string data);
			};


			class MicDown
			{
			public:
				static std::string Set();
			};

			enum class DateTimeType : int
			{
				Date,
				Time
			};


			struct DateAndTimeValue
			{
				DateTimeType Type;
				std::string Value;
			};


			class DateAndTime
			{
			public:
				static std::string Set(DateAndTimeValue value);
				static std::string Read(DateTimeType value);
				static DateAndTimeValue Answer(std::string data);
			};

			enum class EncoderType : int
			{
				MainEncoder,
				MPVDKnob,
				MainNotchEncoder = 4,
				MainContourEncoder,
				MULTIKnob = 8
			};

			struct EncoderValue
			{
				EncoderType Type;
				int Value = 1;
			};

			class EncoderDown
			{
			public:
				static std::string Set(EncoderValue value);

			};


			class EncoderUp
			{
			public:
				static std::string Set(EncoderValue value);

			};

			enum class MenuGroup : int
			{
				RadioSettings = 1,
				CWSettings,
				OperationSetting,
				DisplaySetting,
				ExtensionSetting
			};

			enum class OperationSettingGroup : int
			{
				GENERAL = 1,
				RX_DSP,
				TX_AUDIO,
				TX_GENERAL,
				TUNING
			};

			enum class GeneralFunctions : int
			{
				NB_WIDTH = 1,
				NB_REJECTION,
				BEEP_LEVEL,
				RF_SQL_VR,
				TUNER_SELECT,
				RS232C_RATE,
				RS232C_TIMEOUT_TIMER,
				CAT_RATE,
				CAT_TIMEOUT_TIMER,
				CAT_RTS,
				QMB_CH,
				MEM_GORUP,
				QUICK_SPLIT_INPUT,
				QUCK_SPLIT_FREQ,
				SPLIT_FREQ_DISPLAY,
				TX_TIMEOUT_TIMER,
				MIC_SCAN,
				MIC_SCAN_RESUME,
				REF_FREQ_ADJ,
				KEYBOARD_LANGUAGE
			};

			enum class RX_DSP_Functions : int
			{
				APF_WIDTH = 1,
				CONTOUR_LEVEL,
				CONTOUR_WIDTH,
				IF_NOTCH_WIDTH
			};

			enum class TX_AUDIO_Functions : int
			{
				AMC_RELEASE_TIME = 1,
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
				P_PRMTRC_EQ3_BWTH
			};

			enum class DisplaySettingGroup : int
			{
				DISPLAY = 1,
				SCOPE,
				EXT_MONITOR
			};

			enum class RadioSettingsType : int
			{
				ModeSSB = 1,
				ModeAM,
				ModeFM,
				ModePSK_Data,
				ModeRTTY,
				ENC_DEC_PSK,
				ENC_DEC_RTTY
			};

			enum class SSBFunction : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				SSB_OUT_LEVEL,
				TX_BPF_SEL,
				SSB_MOD_SOURCE,
				REAR_SELECT,
				REAR_PORT_GAIN,
				REAR_PORT_PTT
			};


			enum class AMFunction : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				AM_OUT_LEVEL,
				TX_BPF_SEL,
				AM_MOD_SOURCE,
				MIC_GAIN,
				REAR_SELECT,
				REAR_PORT_GAIN,
				REAR_PORT_PTT
			};


			enum class FMFunction : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				FM_OUT_LEVEL,
				FM_MOD_SOURCE,
				MIC_GAIN,
				REAR_SELECT,
				REAR_PORT_GAIN,
				REAR_PORT_PTT,
				RPT_SHIFT_28,
				RPT_SHIFT_50,
				RPT,
				TONE_FREQ,
				TONE_ENC
			};

			enum class CwBreakInType : int
			{
				SEMI,
				FULL
			};

			enum CWWaveShapeValue : int
			{
				msec_1,
				msec_2,
				msec_4,
				msec_6
			};


			enum class DATAFunction : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				PSK_TONE,
				DATA_SHIFT,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				DATA_OUT_LEVEL,
				TX_BPF_SEL,
				DATA_MOD_SOURCE,
				REAR_SELECT,
				REAR_PORT_GAIN,
				REAR_PORT_PTT
			};

			enum class ShiftPortValue : int
			{
				SHIFT,
				DTR,
				RTS
			};

			enum class RTTYFunction : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				POLARITY_RX,
				POLARITY_TX,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				RTTY_OUT_LEVEL,
				SHIFT_PORT,
				MARK_FREQUENCY,
				SHIFT_FREQUENCY
			};

			enum PSKEncDecFunction : int
			{
				PSK_MODE = 1,
				DECODE_AFC_RANGE,
				QPSK_POLARITY_RX,
				QPSK_POLARITY_TX,
				PSK_TX_LEVEL
			};

			enum RTTYEncDecFunction : int
			{
				RX_USOS = 1,
				TX_USOS,
				RX_NEW_LINE_CODE,
				TX_AUTO_CRLF,
				TX_DIDDLE,
				BAUDOT_CODE
			};

			enum class PolarityValue
			{
				NOR,
				REV
			};

			enum class RepeaterOffset : int
			{
				Negative,
				Simplex,
				Postive
			};

			enum class SlopeValue : int
			{
				_6db,
				_18db
			};

			enum class ModulationSource : int
			{
				MIC,
				REAR
			};

			enum class RearSelectValue : int
			{
				DATA,
				USB
			};

			using Yaesu::Common::PTTSelectValue;

			enum class ToneEncodingValue
			{
				OFF,
				ENC,
				TSQ
			};

			using Yaesu::Common::EnableDisableValue;

			enum class NewLineCode : int
			{
				CR_or_CF_or_CRLF,
				CR_LF_CRLF
			};

			enum class TxDiddleValue : int
			{
				OFF,
				BLANK,
				LTRS
			};
			enum class CwFreqDisplayValue : int
			{
				FREQ,
				PITCH
			};

			enum class PCKeyingValue
			{
				OFF,
				DAKY,
				RTS,
				DTR
			};

			enum class QSKDelayValue
			{
				msec_15,
				msec_20,
				msec_25,
				msec_30
			};

			enum class KeyerType : int
			{
				OFF,
				BUG,
				ELEKEY_A,
				ELEKEY_B,
				ELEKEY_Y,
				ACS
			};

			enum class DotDashType : int
			{
				NOR,
				REV
			};

			enum class NumberStyleValue : int
			{
				_1290,
				AUNO,
				AUNT,
				A2NO,
				A2NT,
				_12NO,
				_12NT
			};

			enum class CWMemoryType : int
			{
				TEXT,
				MESSAGE
			};

			enum class CWDecodeBW : int
			{
				Hz_25,
				Hz_50,
				Hz_100,
				Hz_250
			};
			enum class NBRejectionValue : int
			{
				_10db,
				_30db,
				_50db
			};

			enum class VRType : int
			{
				RF,
				SQL
			};

			enum class TunerSelectValue : int
			{
				INT,
				EXT1,
				EXT2,
				EXT3
			};

			enum class RS232CRate : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum class RS232CTimeOutValue : int
			{
				_10ms,
				_100ms,
				_1000ms,
				_3000ms
			};

			enum CATRateValue : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps
			};

			enum CATTimeOutValue : int
			{
				_10ms,
				_100ms,
				_1000ms,
				_3000ms
			};

			enum class CATRtsValue : int
			{
				DISABLE,
				ENABLE
			};

			enum class QMBChValue : int
			{
				_5ch,
				_10ch
			};

			enum class MicScanResumeType : int
			{
				PAUSE,
				TIME
			};

			enum class CWSettingsType
			{
				ModeCW = 1,
				Keyer,
				DECODE_CW
			};

			enum class ModeCWSettings : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOP,
				HCUT_FREQ,
				HCUT_SLOPE,
				CW_OUT_LEVEL,
				CW_AUTO_MODE,
				CW_BK_IN_TYPE,
				CW_WAVE_SHAPE,
				CW_FREQ_DISPLAY,
				PC_KEYING,
				QSK_DELAY_TIME,
				CW_INDICATOR
			};

			enum class ModeFMSettings : int
			{
				AF_TREBLE_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOP,
				HCUT_FREQ,
				HCUT_SLOPE,
				FM_OUT_LEVEL,
				FM_MOD_SOURCE,
				MIC_GAIN,
				REAR_SELECT,
				RPT_SHIFT_28MHz,
				RPT_SHIFT_50MHz,
				RPT,
				TONE_FREQ,
				ENC_DEC
			};

			enum class KeyerSettings : int
			{
				KEYER_TYPE = 1,
				KEYER_DOT_DASH,
				CW_WEIGHT,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				CW_MEMORY_1,
				CW_MEMORY_2,
				CW_MEMORY_3,
				CW_MEMORY_4,
				CW_MEMORY_5,
				REPEAT_INTERVAL
			};



			enum class TX_GENERAL_Functions : int
			{
				HF_MAX_POWER = 1,
				_50M_MAX_POWER,
				_70M_MAX_POWER,
				AM_MAX_POWER,
				VOX_SELECT,
				DATA_VOX_GAIN,
				EMERGENCY_FREQ_TX
			};

			enum class TUNING_Functions : int
			{
				SSB_CW_DIAL_STEP = 1,
				RTTY_PSK_DIAL_STEP,
				CH_STEP,
				AM_CH_STEP,
				FM_CH_STEP,
				MAIN_STEPS_PER_REV,
				MPVD_STEPS_PER_REV

			};

			/*enum class DisplaySettingGroup : int
			{
				DISPLAY = 1,
				SCOPE,
				EXT_MONITOR
			};*/

			enum class DisplayGroupFunctions : int
			{
				MY_CALL = 1,
				MY_CALL_TIME,
				SCREEN_SAVER,
				DIMMER_LED,
				MOUSE_POINTER_SPEED
			};

			enum class ScopeGroupFunctions : int
			{
				RBW = 1,
				SCOPE_CTR,
				DISP_SENSITIVITY_2D,
				DISP_SENSITIVITY_3DSS
			};

			enum class EXT_MONITOR_Functions : int
			{
				EXT_DISPLAY = 1,
				PIXEL
			};

			enum class AMCReleaseTimeValue : int
			{
				FAST,
				MID,
				SLOW
			};

			enum class DecodeCWSettings : int
			{
				CW_DECODE_BW = 1
			};

			using Yaesu::Common::FreqHighCutValue;

			/*enum class FreqHighCutValue : int
			{
				OFF,
				_700hz,
				_750hz,
				_800hz,
				_850hz,
				_900hz,
				_950hz,
				_1000hz,
				_1050hz,
				_1100hz,
				_1150hz,
				_2000hz,
				_2050hz,
				_2100hz,
				_2150hz,
				_2200hz,
				_2250hz,
				_2300hz,
				_2350hz,
				_2400hz,
				_2450hz,
				_2500hz,
				_2550hz,
				_2600hz,
				_2650hz,
				_2700hz,
				_2750hz,
				_2800hz,
				_2850hz,
				_2900hz,
				_2950hz,
				_3000hz,
				_3050hz,
				_3100hz,
				_3150hz,
				_3200hz,
				_3250hz,
				_3300hz,
				_3350hz,
				_3400hz,
				_3450hz,
				_3500hz,
				_3550hz,
				_3600hz,
				_3650hz,
				_3700hz,
				_3750hz,
				_3800hz,
				_3850hz,
				_3900hz,
				_3950hz,
				_4000hz
			};*/

			using Yaesu::Common::FreqLowCutValue;
			/*enum class FreqLowCutValue : int
			{
				OFF,
				_100hz,
				_150hz,
				_200hz,
				_250hz,
				_300hz,
				_350hz,
				_400hz,
				_450hz,
				_500hz,
				_550hz,
				_600hz,
				_650hz,
				_700hz,
				_750hz,
				_800hz,
				_850hz,
				_900hz,
				_950hz,
				_1000hz,

			};
*/

			enum class NBWidth : int
			{
				_1ms,
				_3ms,
				_10ms
			};

			using Yaesu::Common::APFWidthValue;

			using Yaesu::Common::IFNotchWidth;

			enum FunctionTXBandValue : int
			{
				MAIN,
				SUB
			};

			struct MenuFunction
			{
				MenuGroup group;
				int category;
				int function;
			};

			using Yaesu::Common::EQ1FreqValue;
			using Yaesu::Common::EQ2FreqValue;
			using Yaesu::Common::EQ3FreqValue;
			using Yaesu::Common::VoxSelectValue;


			enum class MyCallTimeOutValue : int {
				OFF,
				s0_5,
				s1,
				s2,
				s3,
				s5
			};

			enum class ScreenSaverValue : int {
				OFF,
				minutes_15,
				minutes_30,
				minutes_60
			};

			enum class RBWValue : int {
				HIGH,
				MID,
				LOW
			};

			enum class ScopeCTRValue : int {
				FILTER,
				CAR_POINT
			};

			enum class SensitivityValue : int {
				NORMAL,
				HI
			};
			enum class PixelValue : int {
				x800_400,
				x800_600
			};

			enum class DialStepValue : int {
				Hz_5,
				Hz_10
			};

			enum class ChannelStepValue : int {
				kHz_1,
				kHz_2_5,
				kHz_5,
				kHz_10
			};

			enum class AMChannelStepValue : int {
				kHz_2_5,
				kHz_5,
				kHz_9,
				kHz_10,
				kHz_12_5,
				kHz_25
			};

			enum class FMChannelStepValue : int {
				kHz_5,
				kHz_6_25,
				kHz_10,
				kHz_12_5,
				kHz_20,
				kHz_25
			};

			enum class MainStepsPerRevValue : int {
				steps_250,
				steps_500,
				steps_1000
			};

			enum class MPVDStepsPerRevValue : int {
				steps_250,
				steps_500
			};

			enum class CTCSSTone : int
			{
				Tone_67_0,
				Tone_69_3,
				Tone_71_9,
				Tone_74_4,
				Tone_77_0,
				Tone_79_7,
				Tone_82_5,
				Tone_85_4,
				Tone_88_5,
				Tone_91_5,
				Tone_94_8,
				Tone_97_4,
				Tone_100_0,
				Tone_103_5,
				Tone_107_2,
				Tone_110_9,
				Tone_114_8,
				Tone_118_8,
				Tone_123_0,
				Tone_127_3,
				Tone_131_8,
				Tone_136_5,
				Tone_141_3,
				Tone_146_2,
				Tone_151_4,
				Tone_156_7,
				Tone_159_8,
				Tone_162_2,
				Tone_165_5,
				Tone_167_9,
				Tone_171_3,
				Tone_173_8,
				Tone_177_3,
				Tone_179_9,
				Tone_183_5,
				Tone_186_2,
				Tone_189_9,
				Tone_192_8,
				Tone_196_6,
				Tone_199_5,
				Tone_203_5,
				Tone_206_5,
				Tone_210_7,
				Tone_218_1,
				Tone_225_7,
				Tone_229_1,
				Tone_233_6,
				Tone_241_8,
				Tone_250_3,
				Tone_254_1
			};

			class Menu
			{
			public:
				MenuFunction GetFunction(const std::string&);
				class RadioSetting
				{

				public:
					class ModeSSB
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};



						class LCUT_FREQ
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class SSB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class SSB_MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};


						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelectValue value);
							static std::string Read();
							static RearSelectValue Answer(std::string data);
						};


						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPTT_SELECT
						{
						public:
							static std::string Set(PTTSelectValue value);
							static std::string Read();
							static PTTSelectValue Answer(std::string data);
						};


					};
					class ModeAM
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class AM_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AM_MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};


						class MIC_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelectValue value);
							static std::string Read();
							static RearSelectValue Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPTT_SELECT
						{
						public:
							static std::string Set(PTTSelectValue value);
							static std::string Read();
							static PTTSelectValue Answer(std::string data);
						};


					};
					class ModeFM
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class FM_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};



						class FM_MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};


						class MIC_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelectValue value);
							static std::string Read();
							static RearSelectValue Answer(std::string data);
						};

						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPTT_SELECT
						{
						public:
							static std::string Set(PTTSelectValue value);
							static std::string Read();
							static PTTSelectValue Answer(std::string data);
						};


						class RPT_SHIFT_28
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPT_SHIFT_50
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPT
						{
						public:
							static std::string Set(RepeaterOffset value);
							static std::string Read();
							static RepeaterOffset Answer(std::string data);
						};


						class TONE_FREQ
						{
						public:
							static std::string Set(CTCSSTone value);
							static std::string Read();
							static CTCSSTone Answer(std::string data);
						};

						class TONE_ENCODING
						{
						public:
							static std::string Set(ToneEncodingValue value);
							static std::string Read();
							static ToneEncodingValue Answer(std::string data);
						};


					};
					class ModePSK_DATA
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class PSK_TONE
						{
						public:
							static std::string Set(PskToneValue value);
							static std::string Read();
							static PskToneValue Answer(std::string data);
						};


						class DATA_SHIFT
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class DATA_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class TX_BPF_SEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class DATA_MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSource value);
							static std::string Read();
							static ModulationSource Answer(std::string data);
						};


						class REAR_SELECT
						{
						public:
							static std::string Set(RearSelectValue value);
							static std::string Read();
							static RearSelectValue Answer(std::string data);
						};


						class RPORT_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RPTT_SELECT
						{
						public:
							static std::string Set(PTTSelectValue value);
							static std::string Read();
							static PTTSelectValue Answer(std::string data);
						};

					};
					class ModeRTTY
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};




						class POLARITY_RX
						{
						public:
							static std::string Set(PolarityValue value);
							static std::string Read();
							static PolarityValue Answer(std::string data);
						};


						class POLARITY_TX
						{
						public:
							static std::string Set(PolarityValue value);
							static std::string Read();
							static PolarityValue Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class RTTY_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MARK_FREQUENCY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class SHIFT_FREQUENCY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


					};
					class EMC_DEC_PSK
					{
					public:
						class PSK_MODE
						{
						public:
							static std::string Set(PSKModeValue value);
							static std::string Read();
							static PSKModeValue Answer(std::string data);
						};


						class DECODE_AFC_RANGE
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class QPSK_POLARITY_RX
						{
						public:
							static std::string Set(PolarityValue value);
							static std::string Read();
							static PolarityValue Answer(std::string data);
						};

						class QPSK_POLARITY_TX
						{
						public:
							static std::string Set(PolarityValue value);
							static std::string Read();
							static PolarityValue Answer(std::string data);
						};


						class PSK_TX_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
					class ENC_DEC_RTTY
					{
					public:

						class RX_USOS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};

						class TX_USOS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};


						class RX_NEW_LINE_CODE
						{
						public:
							static std::string Set(NewLineCode value);
							static std::string Read();
							static NewLineCode Answer(std::string data);
						};


						class TX_AUTO_CRLF
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};


						class TX_DIDDLE
						{
						public:
							static std::string Set(TxDiddleValue value);
							static std::string Read();
							static TxDiddleValue Answer(std::string data);
						};


						class BAUDOT_CODE
						{
						public:
							static std::string Set(BaudotCodeType value);
							static std::string Read();
							static BaudotCodeType Answer(std::string data);
						};

					};
				};

				class CWSetting
				{
				public:
					class Mode
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class LCUT_FREQ
						{
						public:
							static std::string Set(FreqLowCutValue value);
							static std::string Read();
							static FreqLowCutValue Answer(std::string data);
						};

						class LCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class HCUT_FREQ
						{
						public:
							static std::string Set(FreqHighCutValue value);
							static std::string Read();
							static FreqHighCutValue Answer(std::string data);
						};

						class HCUT_SLOP
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};

						class CW_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class CW_AUTO_MODE
						{
						public:
							static std::string Set(CWAutoModeValue value);
							static std::string Read();
							static CWAutoModeValue Answer(std::string data);
						};


						class CW_BREAKIN_TYPE
						{
						public:
							static std::string Set(CwBreakInType value);
							static std::string Read();
							static CwBreakInType Answer(std::string data);
						};


						class CW_WAVE_SHAPE
						{
						public:
							static std::string Set(CWWaveShapeValue value);
							static std::string Read();
							static CWWaveShapeValue Answer(std::string data);
						};


						class CW_FREQ_DISPLAY
						{
						public:
							static std::string Set(CwFreqDisplayValue value);
							static std::string Read();
							static CwFreqDisplayValue Answer(std::string data);
						};


						class PC_KEYING
						{
						public:
							static std::string Set(PCKeyingValue value);
							static std::string Read();
							static PCKeyingValue Answer(std::string data);
						};


						class QSK_DELAY_TIME
						{
						public:
							static std::string Set(QSKDelayValue value);
							static std::string Read();
							static QSKDelayValue Answer(std::string data);
						};


						class CW_INDICATOR
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};

					};
					class Keyer
					{
					public:

						class KEYER_TYPE
						{
						public:
							static std::string Set(KeyerType value);
							static std::string Read();
							static KeyerType Answer(std::string data);
						};


						class KEYER_DOT_DASH
						{
						public:
							static std::string Set(DotDashType value);
							static std::string Read();
							static DotDashType Answer(std::string data);
						};


						class CW_WEIGHT
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class NUMBER_STYLE
						{
						public:
							static std::string Set(NumberStyleValue value);
							static std::string Read();
							static NumberStyleValue Answer(std::string data);
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
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_2
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_3
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_4
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_5
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};


						class REPEAT_INTERVAL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
					class DECODE
					{
					public:
						class CW_DECODE_BW
						{
						public:
							static std::string Set(CWDecodeBW value);
							static std::string Read();
							static CWDecodeBW Answer(std::string data);
						};
					};
				};

				class OperationSetting
				{
				public:
					class General
					{
					public:

						class NB_WIDTH
						{
						public:
							static std::string Set(NBWidth value);
							static std::string Read();
							static NBWidth Answer(std::string data);
						};


						class NB_REJECTION
						{
						public:
							static std::string Set(NBRejectionValue value);
							static std::string Read();
							static NBRejectionValue Answer(std::string data);
						};


						class BEEP_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RF_SQL_VR
						{
						public:
							static std::string Set(VRType value);
							static std::string Read();
							static VRType Answer(std::string data);
						};


						class TUNER_SELECT
						{
						public:
							static std::string Set(TunerSelectValue value);
							static std::string Read();
							static TunerSelectValue Answer(std::string data);
						};


						class RS232C_RATE
						{
						public:
							static std::string Set(RS232CRate value);
							static std::string Read();
							static RS232CRate Answer(std::string data);
						};


						class RS232C_TIMOUT_TIMER
						{
						public:
							static std::string Set(RS232CTimeOutValue value);
							static std::string Read();
							static RS232CTimeOutValue Answer(std::string data);
						};


						class CAT_RATE
						{
						public:
							static std::string Set(CATRateValue value);
							static std::string Read();
							static CATRateValue Answer(std::string data);
						};


						class CAT_TIMEOUT_TIMER
						{
						public:
							static std::string Set(CATTimeOutValue value);
							static std::string Read();
							static CATTimeOutValue Answer(std::string data);
						};


						class CAT_RTS
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};


					};
					class RX_DSP
					{
					public:

						class APF_WIDTH
						{
						public:
							static std::string Set(APFWidthValue value);
							static std::string Read();
							static APFWidthValue Answer(std::string data);
						};

						class CONTOUR_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class CONTOUR_WIDTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class IF_NOTCH_WIDTH
						{
						public:
							static std::string Set(IFNotchWidth value);
							static std::string Read();
							static IFNotchWidth Answer(std::string data);
						};
					};
					class TX_AUDIO
					{
					public:

						class AMC_RELEASE_TIME
						{
						public:
							static std::string Set(AMCReleaseTimeValue value);
							static std::string Read();
							static AMCReleaseTimeValue Answer(std::string data);
						};



						class PRMTRC_EQ1_FREQ
						{
						public:
							static std::string Set(EQ1FreqValue value);
							static std::string Read();
							static EQ1FreqValue Answer(std::string data);
						};


						class PRMTRC_EQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class PRMTRC_EQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ2_FREQ
						{
						public:
							static std::string Set(EQ2FreqValue value);
							static std::string Read();
							static EQ2FreqValue Answer(std::string data);
						};

						class PRMTRC_EQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class PRMTRC_EQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ3_FREQ
						{
						public:
							static std::string Set(EQ3FreqValue value);
							static std::string Read();
							static EQ3FreqValue Answer(std::string data);
						};

						class PRMTRC_EQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class PRMTRC_EQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class P_PRMTRC_EQ1_FREQ
						{
						public:
							static std::string Set(EQ1FreqValue value);
							static std::string Read();
							static EQ1FreqValue Answer(std::string data);
						};


						class P_PRMTRC_EQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class P_PRMTRC_EQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ2_FREQ
						{
						public:
							static std::string Set(EQ2FreqValue value);
							static std::string Read();
							static EQ2FreqValue Answer(std::string data);
						};

						class P_PRMTRC_EQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class P_PRMTRC_EQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ3_FREQ
						{
						public:
							static std::string Set(EQ3FreqValue value);
							static std::string Read();
							static EQ3FreqValue Answer(std::string data);
						};

						class P_PRMTRC_EQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class P_PRMTRC_EQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

					};
					class TX_GENERAL
					{
					public:

						class MAX_POWER_HF
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_50M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_70M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_AM
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class VOX_SELECT
						{
						public:
							static std::string Set(VoxSelectValue value);
							static std::string Read();
							static VoxSelectValue Answer(std::string data);
						};


						class DATA_VOX_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class EMERGENCY_FREQ_TX
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};
					};
					class TUNING
					{
					public:

						class SSB_CW_DIAL_STEP
						{
						public:
							static std::string Set(DialStepValue value);
							static std::string Read();
							static DialStepValue Answer(std::string data);
						};

						class RTTY_PSK_DIAL_STEP
						{
						public:
							static std::string Set(DialStepValue value);
							static std::string Read();
							static DialStepValue Answer(std::string data);
						};


						class CH_STEP
						{
						public:
							static std::string Set(ChannelStepValue value);
							static std::string Read();
							static ChannelStepValue Answer(std::string data);
						};


						class AM_CH_STEP
						{
						public:
							static std::string Set(AMChannelStepValue value);
							static std::string Read();
							static AMChannelStepValue Answer(std::string data);
						};


						class FM_CH_STEP
						{
						public:
							static std::string Set(FMChannelStepValue value);
							static std::string Read();
							static FMChannelStepValue Answer(std::string data);
						};


						class MAIN_STEPS_PER_REV
						{
						public:
							static std::string Set(MainStepsPerRevValue value);
							static std::string Read();
							static MainStepsPerRevValue Answer(std::string data);
						};


						class MPVD_STEPS_PER_REV
						{
						public:
							static std::string Set(MPVDStepsPerRevValue value);
							static std::string Read();
							static MPVDStepsPerRevValue Answer(std::string data);
						};
					};

				};


				class DisplaySetting
				{
				public:
					class DISPLAY
					{
					public:

						class MY_CALL
						{
						public:
							static std::string Set(std::string value);
							static std::string Read();
							static std::string Answer(std::string data);
						};


						class MY_CALL_TIME
						{
						public:
							static std::string Set(MyCallTimeOutValue value);
							static std::string Read();
							static MyCallTimeOutValue Answer(std::string data);
						};


						class SCREEN_SAVER
						{
						public:
							static std::string Set(ScreenSaverValue value);
							static std::string Read();
							static ScreenSaverValue Answer(std::string data);
						};


						class DIMMER_LED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MOUSE_POINTER_SPEED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
					class SCOPE
					{
					public:

						class RBW
						{
						public:
							static std::string Set(RBWValue value);
							static std::string Read();
							static RBWValue Answer(std::string data);
						};


						class SCOPE_CTR
						{
						public:
							static std::string Set(ScopeCTRValue value);
							static std::string Read();
							static ScopeCTRValue Answer(std::string data);
						};


						class DISP_SENSITIVITY_2D
						{
						public:
							static std::string Set(SensitivityValue value);
							static std::string Read();
							static SensitivityValue Answer(std::string data);
						};

						class DISP_SENSITIVITY_3DSS
						{
						public:
							static std::string Set(SensitivityValue value);
							static std::string Read();
							static SensitivityValue Answer(std::string data);
						};

					};
					class EXT_MONITOR
					{
					public:

						class EXT_DISPLAY
						{
						public:
							static std::string Set(EnableDisableValue value);
							static std::string Read();
							static EnableDisableValue Answer(std::string data);
						};


						class PIXEL
						{
						public:
							static std::string Set(PixelValue value);
							static std::string Read();
							static PixelValue Answer(std::string data);
						};
					};
				};

				class ExtensionSetting
				{
				public:

				};
			};



			class FREQUENCY_VFO_A
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class FREQUENCY_VFO_B
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class FINE_TUNING
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class FUNCTION_TX
			{
			public:
				static std::string Set(FunctionTXBandValue value);
				static std::string Read();
				static FunctionTXBandValue Answer(std::string data);
			};

			enum class AgcFunctionValue : int {
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO
			};

			enum class AgcSettingResult : int {
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO_FAST,
				AUTO_MID,
				AUTO_SLOW
			};


			class AGC_FUNCTION
			{
			public:
				static std::string Set(AgcFunctionValue value);
				static std::string Read();
				static AgcSettingResult Answer(std::string data);
			};
			enum class MemoryChannelValue
			{
				_1 = 1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				P1L,
				P1U,
				P2L,
				P2U,
				P3L,
				P3U,
				P4L,
				P4U,
				P5L,
				P5U,
				P6L,
				P6U,
				P7L,
				P7U,
				P8L,
				P8U,
				P9L,
				P9U,
				_5351_5mhz = 501,
				_5354mhz,
				_5357mhz,
				_5360mhz,
				_5363mhz,
				_5366mhz,
				EMG = 600

			};
			enum class ClarifierState : int
			{
				OFF,
				ON
			};

			enum class ModeValue
			{
				LSB = 1,
				USB,
				CW_U,
				FM,
				AM,
				RTTY_L,
				CW_L,
				DATA_L,
				RTTY_U,
				DATA_FM,
				FM_N,
				DATA_U,
				AM_N,
				PSK,
				DATA_FM_N
			};

			enum class VFOChannelTypeValue : int
			{
				VFO,
				Memory,
				MemoryTune,
				QuickMemoryBank,
				PMS = 5

			};

			enum class CTCSSState : int
			{
				OFF,
				CTCSS_ENC_DEC,
				CTCSS_ENC
			};

			enum class OperationType : int
			{
				Simplex,
				PlusShift,
				MinusShift
			};

			struct InformationValue
			{
				MemoryChannelValue MemoryChannel;
				int VFOAFreq;
				int ClarifierFreq;
				ClarifierState RxClarifier;
				ClarifierState TxClarifier;
				ModeValue Mode;
				VFOChannelTypeValue VFO;
				CTCSSState CTCSS;
				OperationType Operation;
			};


			class INFORMATION
			{
			public:
				static std::string Read();
				static InformationValue Answer(std::string data);
			};


			class IF_SHIFT
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			struct KeyerMemoryValue
			{
				int MemoryChannelNumber;
				std::string Message;
			};


			class KEYER_MEMORY
			{
			public:
				static std::string Set(KeyerMemoryValue value);
				static std::string Read(int Channel);
				static KeyerMemoryValue Answer(std::string data);
			};


			class KEY_PITCH
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class KEYER
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class KEY_SPEED
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class CwKeyingValue : int
			{
				Memory_1 = 1,
				Memory_2,
				Memory_3,
				Memory_4,
				Memory_5,
				Message_1,
				Message_2,
				Message_3,
				Message_4,
				Message_5
			};


			class CW_KEYING
			{
			public:
				static std::string Set(CwKeyingValue value);

			};


			class LOCK
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum DVSValue : int {
				Stop,
				CH1,
				CH2,
				CH3,
				CH4,
				CH5
			};


			class LOAD_MESSAGE
			{
			public:
				static std::string Set(DVSValue value);
				static std::string Read();
				static DVSValue Answer(std::string data);
			};


			class MEMORY_CHANNEL_TO_VFO_A
			{
			public:
				static std::string Set();
			};

			class MEMORY_CHANNEL_TO_VFO_B
			{
			public:
				static std::string Set();
			};


			class MEMORY_CHANNEL
			{
			public:
				static std::string Set(MemoryChannelValue value);
				static std::string Read();
				static MemoryChannelValue Answer(std::string data);
			};

			struct OperatingModeValue
			{
				MainSubValue Band;
				ModeValue Mode;
			};


			class OPERATING_MODE
			{
			public:
				static std::string Set(OperatingModeValue value);
				static std::string Read(MainSubValue value);
				static OperatingModeValue Answer(std::string data);
			};


			class MIC_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class MonitorLevelType : int
			{
				ON_OFF,
				LEVEL
			};

			struct MonitorLevelValue
			{
				MonitorLevelType Type;
				union {
					OnOffValue e_value;
					int i_value;
				} Value;
			};


			class MONITOR_LEVEL
			{
			public:
				static std::string Set(MonitorLevelValue value);
				static std::string Read(MonitorLevelType value);
				static MonitorLevelValue Answer(std::string data);
			};

			enum class MemoryChannelType : int
			{
				VFO,
				Memory
			};

			struct MemoryChannel
			{
				MemoryChannelValue	Channel;
				int Frequency;
				int Clarifier;
				OnOffValue RXClarifier;
				OnOffValue TXClarifier;
				ModeValue Mode;
				MemoryChannelType Type;
				CTCSSState CTCSS;
				OperationType Operation;
			};

			struct MemoryChannelTag
			{
				MemoryChannelValue	Channel;
				int Frequency;
				int Clarifier;
				OnOffValue RXClarifier;
				OnOffValue TXClarifier;
				ModeValue Mode;
				MemoryChannelType Type;
				CTCSSState CTCSS;
				OperationType Operation;
				std::string TAG;
			};

			class MEMORY_CHANNEL_READ
			{
			public:

				static std::string Read(MemoryChannelValue channel);
				static MemoryChannel Answer(std::string data);
			};

			enum class MeterType : int
			{
				PO,
				COMP,
				ALC,
				VDD,
				ID,
				SWR
			};

			class METER_SW
			{
			public:
				static std::string Set(MeterType value);
				static std::string Read();
				static MeterType Answer(std::string data);
			};


			class MEMORY_CHANNEL_TAG
			{
			public:
				static std::string Set(MemoryChannelTag value);
				static std::string Read(MemoryChannelValue value);
				static MemoryChannelTag Answer(std::string data);
			};


			class MEMORY_CHANNEL_WRITE
			{
			public:
				static std::string Set(MemoryChannel value);
			};


			class MOX_SET
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class NARROW
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class NOISE_BLANKER_STATUS
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class NOISE_BLANKER_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class NOISE_REDUCTION
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class OPPOSITE_BAND_INFORMATION
			{
			public:

				static std::string Read();
				static InformationValue Answer(std::string data);
			};

			struct RepeaterShiftValue {
				MainSubValue Band;
				OperationType Operation;
			};

			class REPEATER_SHIFT
			{
			public:
				static std::string Set(RepeaterShiftValue value);
				static std::string Read(MainSubValue value);
				static RepeaterShiftValue Answer(std::string data);
			};

			enum class PreAmpType : int
			{
				IPO,
				AMP_1,
				AMP_2
			};

			class PRE_AMP
			{
			public:
				static std::string Set(PreAmpType value);
				static std::string Read();
				static PreAmpType Answer(std::string data);
			};

			class PLAY_BACK
			{
			public:
				static std::string Set(DVSValue value);
				static std::string Read();
				static DVSValue Answer(std::string data);
			};

			class POWER_CONTROL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class SPEECH_PROCESSOR_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SpeechProcessorType : int
			{
				SpeechProcessor,
				ParametricMicrophoneEqualizer
			};

			struct SpeechProcessorValue
			{
				SpeechProcessorType Type;
				OnOffValue State;
			};

			class SPEECH_PROCESSOR
			{
			public:
				static std::string Set(SpeechProcessorValue value);
				static std::string Read(SpeechProcessorType value);
				static SpeechProcessorValue Answer(std::string data);
			};

			class POWER_SWITCH
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class QMB_STORE
			{
			public:
				static std::string Set();
			};

			class QMB_RECALL
			{
			public:
				static std::string Set();
			};

			class QMB_SPLIT
			{
			public:
				static std::string Set();
			};

			enum class RFAttenuatorValue : int
			{
				OFF,
				db_6,
				db_12,
				db_18
			};

			class RF_ATTENUATOR
			{
			public:
				static std::string Set(RFAttenuatorValue value);
				static std::string Read();
				static RFAttenuatorValue Answer(std::string data);
			};

			class CLAR_CLEAR
			{
			public:
				static std::string Set();
			};

			class CLAR_DOWN
			{
			public:
				static std::string Set(int Hz);
			};

			enum RoofingFilterValue
			{
				kHz_12 = 1,
				kHz_3,
				Hz_500 = 4,
				Hz_300
			};

			class ROOFING_FILTER
			{
			public:
				static std::string Set(RoofingFilterValue value);
				static std::string Read();
				static RoofingFilterValue Answer(std::string data);
			};

			class RF_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class RadioInformationType : int
			{
				HIGH_SWR,
				REC = 3,
				PLAY,
				NO_TX = 13
			};

			struct RadioInformationValue
			{
				RadioInformationType Type;
				OnOffValue State;
			};

			class RADIO_INFORMATION
			{
			public:
				static std::string Read(RadioInformationType type);
				static RadioInformationValue Answer(std::string data);
			};

			class NOISE_REDUCTION_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class ReadMeterType : int
			{
				CURRENT,
				S,
				COMP = 3,
				ALC,
				PO,
				SWR,
				IDD,
				VDD
			};

			struct ReadMeterValue
			{
				ReadMeterType Type;
				int value;
			};

			class READ_METER
			{
			public:

				static std::string Read(ReadMeterType type);
				static ReadMeterValue Answer(std::string data);
			};

			enum class RadioStatusValue : int
			{
				NORMAL_MODE,
				MENU_MODE
			};

			class RADIO_STATUS
			{
			public:

				static std::string Read();
				static RadioStatusValue Answer(std::string data);
			};

			class CLAR
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class RX_CLARIFIER_PLUS_OFFSET
			{
			public:
				static std::string Set(int value);
			};

			enum class ScanType : int
			{
				OFF,
				UP,
				DOWN
			};

			class SCAN
			{
			public:
				static std::string Set(ScanType value);
				static std::string Read();
				static ScanType Answer(std::string data);
			};

			enum class CWBreakInDelayValue : int {
				msec_30,
				msec_50,
				msec_100,
				msec_150,
				msec_200,
				msec_250,
				msec_300,
				msec_400,
				msec_500,
				msec_600,
				msec_700,
				msec_800,
				msec_900,
				msec_1000,
				msec_1100,
				msec_1200,
				msec_1300,
				msec_1400,
				msec_1500,
				msec_1600,
				msec_1700,
				msec_1800,
				msec_1900,
				msec_2000,
				msec_2100,
				msec_2200,
				msec_2300,
				msec_2400,
				msec_2500,
				msec_2600,
				msec_2700,
				msec_2800,
				msec_2900,
				msec_3000
			};

			class CW_BREAK_IN_DELAY_TIME
			{
			public:
				static std::string Set(CWBreakInDelayValue value);
				static std::string Read();
				static CWBreakInDelayValue Answer(std::string data);
			};

			enum class SubDialKnob : int
			{
				MPVD,
				FUNC
			};

			enum class SubDialMPVDFunction : int
			{
				CLAR = 1,
				SUB = 3,
				CS,
				STEP = 8,
				MCH
			};

			enum class SubDialFUNFunction : int
			{
				RF_POWER,
				MONI_LEVEL,
				VOX_GAIN = 4,
				VOX_DELAY,
				ANTI_VOX,
				GROUP = 9,
				PEAK = 12,
				COLOR,
				S_LEVEL,
				PROC_LEVEL,
				MIC_GAIN,
				CW_SPEED,
				CW_PITCH,
				BK_IN_DELAY,
				AMC_LEVEL,
				CONTRAST = 22,
				DIMMER
			};

			struct SubDialValue
			{
				SubDialKnob Knob;
				union {
					SubDialMPVDFunction as_MPVD;
					SubDialFUNFunction as_FUNC;
				} KnobValue;
			};

			class SUB_DIAL_FUNCTION
			{
			public:
				static std::string Set(SubDialValue value);
				static std::string Read(SubDialKnob value);
				static SubDialValue Answer(std::string data);
			};

			class WIDTH
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class S_METER_READING
			{
			public:

				static std::string Read();
				static int Answer(std::string data);
			};

			class SQUELCH_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SpectrumScopeAspect : int
			{
				SPEED,
				PEAK,
				MARKER,
				COLOR,
				LEVEL,
				SPAN,
				MODE,
				OSCILLOSCOPE,
				HOLD
			};

			enum class SpectrumScopeSpeedValue : int
			{
				SLOW1,
				SLOW2,
				FAST1,
				FAST2,
				FAST3
			};

			enum class SpectrumScopePeakValue : int
			{
				LV1,
				LV2,
				LV3,
				LV4,
				LV5
			};

			enum class SpectrumScopeColorValue : int
			{
				COLOR_1,
				COLOR_2,
				COLOR_3,
				COLOR_4,
				COLOR_5,
				COLOR_6,
				COLOR_7,
				COLOR_8,
				COLOR_9,
				COLOR_10,
				COLOR_11
			};

			enum class SpectrumScopeSpanValue : int
			{
				kHz_1,
				kHz_2,
				kHz_5,
				kHz_10,
				kHz_20,
				kHz_50,
				kHz_100,
				kHz_200,
				kHz_500,
				MHz_1
			};

			enum class SpectrumScopeModeValue : int
			{
				CENTER_3DSS,
				CURSOR_3DSS,
				FIX_3DSS,
				CENTER_L_WF,
				CENTER_N_WF,
				CENTER_S_WF,
				CURSOR_L_WF,
				CURSOR_N_WF,
				CURSOR_S_WF,
				FIX_L_WF,
				FIX_N_WF,
				FIX_S_WF
			};

			enum class SpectrumScopeOscilloscpeFFTATTValue : int
			{
				ATT_0db,
				ATT_10db,
				ATT_20db,
			};

			enum class SpectrumScopeOscilloscopeOSCATTValue : int
			{
				ATT_0db,
				ATT_10db,
				ATT_20db
			};

			enum class SpectrumScopeOscilloscopeOSCTimeValue : int
			{
				msec_1,
				msec_3,
				msec_10,
				msec_30,
				msec_100,
				msec_300
			};

			struct SpectrumScopeValue
			{
				SpectrumScopeAspect Type;
				union {
					struct {
						SpectrumScopeOscilloscpeFFTATTValue att_fft;
						SpectrumScopeOscilloscopeOSCATTValue att_osc;
						SpectrumScopeOscilloscopeOSCTimeValue time_osc;
					} v_oscilloscope;
					SpectrumScopeSpeedValue v_speed;
					SpectrumScopePeakValue v_peak;
					OnOffValue v_marker;
					SpectrumScopeColorValue v_color;
					int v_level;
					SpectrumScopeSpanValue v_span;
					SpectrumScopeModeValue v_mode;
					OnOffValue v_hold;
				} Value;
			};

			class SPECTRUM_SCOPE
			{
			public:
				static std::string Set(SpectrumScopeValue value);
				static std::string Read(SpectrumScopeAspect Type);
				static SpectrumScopeValue Answer(std::string data);
			};

			enum class SplitValue : int
			{
				OFF,
				ON,
				kh5_up
			};

			class SPLIT
			{
			public:
				static std::string Set(SplitValue value);
				static std::string Read();
				static SplitValue Answer(std::string data);
			};

			class SWAP_VFO
			{
			public:
				static std::string Set();
			};

			class TXW
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum class TxSetValue : int
			{
				Radio_Off_Cat_Off,
				Radio_Off_Cat_On,
				Radio_On_Cat_Off
			};

			class TX_SET
			{
			public:
				static std::string Set(TxSetValue value);
				static std::string Read();
				static TxSetValue Answer(std::string data);
			};

			class MIC_UP
			{
			public:
				static std::string Set();
			};

			enum class VoxDelayTime : int
			{
				msec_30,
				msec_50,
				msec_100,
				msec_150,
				msec_200,
				msec_250,
				msec_300,
				msec_400,
				msec_500,
				msec_600,
				msec_700,
				msec_800,
				msec_900,
				msec_1000,
				msec_1100,
				msec_1200,
				msec_1300,
				msec_1400,
				msec_1500,
				msec_1600,
				msec_1700,
				msec_1800,
				msec_1900,
				msec_2000,
				msec_2100,
				msec_2200,
				msec_2300,
				msec_2400,
				msec_2500,
				msec_2600,
				msec_2700,
				msec_2800,
				msec_2900,
				msec_3000
			};

			class VOX_DELAY
			{
			public:
				static std::string Set(VoxDelayTime value);
				static std::string Read();
				static VoxDelayTime Answer(std::string data);
			};

			class VOX_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class MAIN_TO_MEM
			{
			public:
				static std::string Set();

			};

			enum class VFOSelectValue : int
			{
				VFO_A,
				VFO_B
			};

			class TX_CLAR
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class ZERO_IN
			{
			public:
				static std::string Set();

			};
		}; // end FTDX10

		namespace FT710
		{
			enum class AntennaTunerType : int
			{
				internal_external = 0,
				ATAS = 2
			};

			enum class AntennaTunerState : int
			{
				OFF,
				ON,
				Start
			};

			enum class AntennaTunerFunction : int
			{
				Stop,
				FrequencyUp,
				FrequencyDown,
				Start
			};

			using Yaesu::Common::OnOffValue;

			enum class AESSFunction : int
			{
				Level = 1,
				CutOffFrequency
			};

			enum class AESSCutOffFrequency : int
			{
				_700Hz = 1,
				_1000Hz
			};

			enum class MainSubValue : int
			{
				MainBand = 0,
				SubBand
			};

			enum class ManualNotchFunction : int
			{
				OnOff,
				Frequency
			};

			enum class BandValue : int
			{
				_160m = 0,
				_80m,
				_60m,
				_40m,
				_30m,
				_20m,
				_17m,
				_15m,
				_12m,
				_10m,
				_6m,
				_70m
			};

			enum class ClarifierFunction : int
			{
				Setting,
				Frequency
			};

			using Yaesu::Common::UpDownValue;

			enum class CountourFunction : int
			{
				ContourOnOff,
				ContourFrequency,
				APFOnOff,
				APFFrequency
			};

			enum class CTCSSFunction : int
			{
				OFF,
				ENC_ON_DEC_ON,
				ENC_ON_DEC_OFF
			};

			enum class MenuGroup : int
			{
				RadioSetting = 1,
				CWSetting,
				OperationSetting,
				DisplaySetting,
				ExtensionSetting = 6,

			};

			enum class RadioSettingsGroup : int
			{
				Mode_SSB = 1,
				Mode_AM,
				Mode_FM,
				Mode_PSK_DATA,
				Mode_RTTY
			};

			enum class CWSettingsGroup : int
			{
				Mode_CW = 1,
				Keyer
			};

			enum class OperationSettingsGroup : int
			{
				General = 1,
				RX_DSP,
				TX_AUDIO,
				TX_GENERAL,
				TUNING
			};

			enum class DisplaySettingsGroup : int
			{
				Display = 1,
				Scope,
				VFO_IND_COLOR,
				EXT_Monitor
			};

			enum class ModeSSBMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				USB_MOD_GAIN,
				REAR_MOD_GAIN,
				RPTT_SELECT,
				NAR_WIDTH,
				CW_AUTO_MODE
			};

			enum class ModeAMMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				USB_MOD_GAIN,
				REAR_MOD_GAIN,
				RPTT_SELECT
			};


			enum class ModeFMMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				USB_MOD_GAIN,
				REAR_MOD_GAIN,
				RPTT_SELECT,
				RPT_SHIFT,
				RPT_SHIFT_28,
				RPT_SHIFT_50,
				ENC_DEC,
				TONE_FREQ
			};

			enum class ModePSK_DATAMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				USB_MOD_GAIN,
				REAR_MOD_GAIN,
				RPTT_SELECT,
				NAR_WIDTH,
				PSK_TONE,
				DATA_SHIFT
			};

			enum class ModeRTTYMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				RPTT_SELECT,
				NAR_WIDTH,
				MARK_FREQUENCY,
				SHIFT_FREQUENCY,
				POLARITY_TX
			};

			enum class ModeCWMenuFunction : int
			{
				AF_TREBEL_GAIN = 1,
				AF_MIDDLE_TONE_GAIN,
				AF_BASS_GAIN,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				RPTT_SELECT,
				NAR_WIDTH,
				PC_KEYING,
				CW_BK_IN_TYPE,
				CW_WAVE_SHAPE,
				CW_FREQ_DISPLAY,
				QSK_DELAY_TIME,
				CW_INDICATOR
			};

			enum class KeyerMenuFunction : int
			{
				KEYER_TYPE = 1,
				KEYER_DOT_DASH,
				CW_WEIGHT,
				NUMBER_STYLE,
				CONTEST_NUMBER,
				CW_MEMORY_1,
				CW_MEMORY_2,
				CW_MEMORY_3,
				CW_MEMORY_4,
				CW_MEMORY_5,
				REPEAT_INTERVAL
			};

			enum class GeneralMenuFunction : int
			{
				BEEP_LEVEL = 1,
				RF_SQL_VR,
				TUN_LIN_PORT_SELECT,
				TUNER_TYPE_SELECT,
				CAT_1_RATE,
				CAT_1_TIME_OUT_TIMER,
				CAT_1_CAT_3_STOP_BIT,
				CAT_2_RATE,
				CAT_2_TIME_OUT_TIMER,
				CAT_3_RATE,
				CAT_3_TIME_OUT_TIMER,
				QMB_CH,
				BAND_STACK,
				MEM_GROUP,
				TX_TIME_OUT_TIMER,
				MIC_SCAN,
				MIC_SCAN_RESUME,
				REF_FREQ_ADJ,
				KEYBOARD_LANGUAGE,
				MIC_P1,
				MIC_P2,
				MIC_P3,
				MIC_P4,
				MIC_UP,
				MIC_DOWN,
				SCU_LAN10
			};

			enum class RX_DSP_MenuFunctions : int
			{
				IF_NOTCH_WIDTH = 1,
				NB_REJECTION,
				NB_WIDTH,
				APF_WIDTH,
				CONTOUR_LEVEL,
				CONTOUR_WIDTH
			};

			enum class TXAudioMenuFunctions : int
			{
				AMC_RELEASE_TIME = 1,
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
				P_PRMTRC_EQ3_BWTH
			};

			enum class TXGeneralMenuFunctions : int
			{
				HF_MAX_POWER = 1,
				_50M_MAX_POWER,
				_70M_MAX_POWER,
				AM_MAX_POWER,
				VOX_SELECT,
				EMERGENCY_FREQ_TX,
				TX_INHIBIT,
				METER_DETECTOR
			};

			enum class TuningMenuFunctions : int
			{
				SSB_CW_DIAL_STEP = 1,
				RTTY_PSK_DIAL_STEP,
				CH_STEP,
				AM_CH_STEP,
				FM_CH_STEP,
				MAIN_STEPS_PER_REV
			};


			enum class DisplayMenuFunctions : int
			{
				MY_CALL = 1,
				MY_CALL_TIME,
				POP_UP_TIME,
				SCREEN_SAVER,
				DIMMER_LED,
				MOUSE_POINTER_SPEED
			};

			enum class ScopeMenuFunctions : int
			{
				RBW = 1,
				SCOPE_CTR,
				DISP_SENSITIVITY_2D,
				DISP_SENSITIVITY_3DSS
			};

			enum class ColorMenuFunctions : int
			{
				VMI_COLOR_VFO_A = 1,
				VMI_COLOR_VFO_B,
				VMI_COLOR_MEMORY,
				VMI_COLOR_CLAR,
			};

			enum class ExternalMonitorMenuFunctions : int
			{
				EXT_DISPLAY = 1,
				PIXEL
			};

			enum class ExtensionSettingGroup : int
			{
				PRESET1 = 1,
				PRESET2,
				PRESET3,
				PRESET4,
				PRESET5
			};

			enum class PresetMenuFunction : int
			{
				PRESET_NAME = 1,
				CAT_1_RATE,
				CAT_1_TIME_OUT_TIMER,
				CAT_1_CAT_3_STOP_BIT,
				AGC_FAST_DELAY,
				AGC_MID_DELAY,
				AGC_SLOW_DELAY,
				LCUT_FREQ,
				LCUT_SLOPE,
				HCUT_FREQ,
				HCUT_SLOPE,
				USB_OUT_LEVEL,
				REAR_OUT_LEVEL,
				TX_BPF_SEL,
				MOD_SOURCE,
				USB_MOD_GAIN,
				REAR_MOD_GAIN,
				RPTT_SELECT
			};

			enum class VoxSelectValue : int
			{
				MIC,
				USB,
				REAR
			};

			enum class MeterDetectorValue : int
			{
				AVERAGE,
				PEAK
			};

			enum class AMCReleaseTimeValue : int
			{
				FAST,
				MID,
				SLOW
			};

			enum class EQ1FrequencyValue : int
			{
				OFF,
				_100,
				_200,
				_300,
				_400,
				_500,
				_600,
				_700
			};

			enum class EQ2FrequencyValue : int
			{
				OFF,
				_700,
				_800,
				_900,
				_1000,
				_1100,
				_1200,
				_1300,
				_1400,
				_1500
			};

			enum class EQ3FrequencyValue : int
			{
				OFF,
				_1500,
				_1600,
				_1700,
				_1800,
				_1900,
				_2000,
				_2100,
				_2200,
				_2300,
				_2400,
				_2500,
				_2600,
				_2700,
				_2800,
				_2900,
				_3000,
				_3100,
				_3200
			};

			using Yaesu::Common::IFNotchWidth;

			enum class NBWidthValue : int
			{
				NARROW,
				MEDIUM,
				WIDE
			};

			enum class NBRejectionValue : int
			{
				LOW,
				MID,
				HIGH
			};

			using Yaesu::Common::APFWidthValue;

			enum class RF_SQL_VRValue : int
			{
				RF,
				SQL,
				SQL_FM
			};

			enum class TunerLinPortValue :int
			{
				EXT_TUNER,
				LINEAR,
				CAT_3,
				GPO
			};

			enum class TunerTypeValue : int
			{
				INT,
				INT_FAST,
				EXT,
				ATAS
			};

			enum class CAT_Rate : int
			{
				_4800bps,
				_9600bps,
				_19200bps,
				_38400bps,
				_115200bps
			};

			enum class CAT_TimeOutValue :int
			{
				_10msec,
				_100msec,
				_1000msec,
				_3000msec
			};

			enum class CAT_StopBitType : int
			{
				_1_bit,
				_2_bit
			};

			enum class QMBChannelValue : int
			{
				_5ch,
				_10ch
			};

			enum class TimeOutValue : int
			{
				OFF,
				_1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30
			};

			enum class ScanResumeType : int
			{
				PAUSE,
				TIME
			};

			enum class KeyboardLanguageType : int
			{
				JAPANESE,
				ENGLISH_US,
				ENGLISH_UK,
				FRENCH,
				FRENCH_CA,
				GERMAN,
				PORTUGUESE,
				PORTUGUESE_BR,
				SPANISH,
				SPANISH_LATAM,
				ITALIAN
			};

			enum class MicButtonType : int
			{
				LOCK,
				QMB,
				A_B,
				V_M,
				TUNER,
				VOX_MOX,
				MODE,
				ZIN_SPOT,
				SPLIT,
				FINE,
				NAR,
				NB,
				DNR,
				FREQ_UP,
				FREQ_DOWN,
				BAND_UP,
				BAND_DOWN,
				ATT,
				IPO,
				DNF,
				AGC
			};

			enum class SlopeValue : int
			{
				_6dBoct,
				_18dBoct
			};

			enum class DialStepValue : int
			{
				_5Hz,
				_10Hz,
				_20Hz
			};

			enum class ChannelStepValue : int
			{
				_1Khz,
				_2_5Khz,
				_5Khz,
				_10Khz
			};

			enum class AMChannelStepValue : int
			{
				_2_5Khz,
				_5Khz,
				_10Khz
			};

			enum class FMChannelStepValue : int
			{
				_5Khz,
				_6_25Khz,
				_10Khz,
				_12_5Khz,
				_25Khz
			};

			enum class StepsPerRevValue : int
			{
				_50,
				_100,
				_200
			};

			enum class MyCallTimeValue : int
			{
				OFF,
				Sec_1,
				Sec_2,
				Sec_3,
				Sec_4,
				Sec_5
			};

			enum class PopUpTimeValue : int
			{
				FAST,
				MID,
				SLOW
			};


			enum class ScreenSaverValue : int
			{
				OFF,
				minutes_15,
				minutes_30,
				minutes_60
			};

			enum class RBWTimeValue : int
			{
				HIGH,
				MID,
				LOW
			};

			enum class ScopeCenterValue : int
			{
				FILTER,
				CARRIER_POINT
			};

			enum class DisplaySensitivityValue : int
			{
				NORMAL,
				HI
			};

			enum class TriColorValue : int
			{
				BLUE,
				GREEN,
				WHITE,
				NONE
			};

			enum class SingleColorValue : int
			{
				RED,
				NONE
			};

			enum class PixelValue : int
			{
				_800x480,
				_800x600
			};

			enum class HCutFreq : int
			{
				OFF,
				_700Hz,
				_750Hz,
				_800Hz,
				_850Hz,
				_900Hz,
				_950Hz,
				_1000Hz,
				_1050Hz,
				_1100Hz,
				_1150Hz,
				_1200Hz,
				_1250Hz,
				_1300Hz,
				_1350Hz,
				_1400Hz,
				_1450Hz,
				_1500Hz,
				_1550Hz,
				_1600Hz,
				_1650Hz,
				_1700Hz,
				_1750Hz,
				_1800Hz,
				_1850Hz,
				_1900Hz,
				_1950Hz,
				_2000Hz,
				_2050Hz,
				_2100Hz,
				_2150Hz,
				_2200Hz,
				_2250Hz,
				_2300Hz,
				_2350Hz,
				_2400Hz,
				_2450Hz,
				_2500Hz,
				_2550Hz,
				_2600Hz,
				_2650Hz,
				_2700Hz,
				_2750Hz,
				_2800Hz,
				_2850Hz,
				_2900Hz,
				_2950Hz,
				_3000Hz,
				_3050Hz,
				_3100Hz,
				_3150Hz,
				_3200Hz,
				_3250Hz,
				_3300Hz,
				_3350Hz,
				_3400Hz,
				_3450Hz,
				_3500Hz,
				_3550Hz,
				_3600Hz,
				_3650Hz,
				_3700Hz,
				_3750Hz,
				_3800Hz,
				_3850Hz,
				_3900Hz,
				_3950Hz,
				_4000Hz
			};

			enum class LCUTFreq : int
			{
				OFF,
				_100Hz,
				_150Hz,
				_200Hz,
				_250Hz,
				_300Hz,
				_350Hz,
				_400Hz,
				_450Hz,
				_500Hz,
				_550Hz,
				_600Hz,
				_650Hz,
				_700Hz,
				_750Hz,
				_800Hz,
				_850Hz,
				_900Hz,
				_950Hz,
				_1000Hz
			};

			enum class RPTTSelectValue : int
			{
				OFF,
				RTS,
				DTR,
				DAKY
			};

			enum class NarrowWidthValue : int
			{
				_300Hz,
				_400Hz,
				_600Hz,
				_850Hz,
				_1100Hz,
				_1200Hz,
				_1500Hz,
				_1650Hz,
				_1800Hz,
				_1950Hz,
				_2100Hz,
				_2250Hz,
				_2400Hz,
				_2450Hz,
				_2500Hz,
				_2600Hz,
				_2700Hz,
				_2800Hz,
				_2900Hz,
				_3000Hz,
				_3200Hz,
				_3500Hz,
				_4000Hz
			};

			enum class PSKToneValue : int
			{
				_1000Hz,
				_1500Hz,
				_2000Hz
			};

			enum class DataWidthValue : int
			{
				_50,
				_100,
				_150,
				_200,
				_250,
				_300,
				_350,
				_400,
				_450,
				_500,
				_600,
				_800,
				_1200,
				_1400,
				_1700,
				_2000,
				_2400,
				_3000,
				_3200,
				_3500,
				_4000
			};


			enum class TXBandPassValue : int
			{
				_50_3050,
				_100_2900,
				_200_2800,
				_300_2700,
				_400_2600
			};

			enum class CWAutoModeValue : int
			{
				OFF,
				_50Mhz,
				ON
			};

			enum class ModulationSourceValue : int
			{
				MIC,
				USB,
				REAR,
				AUTO
			};

			enum class RepeaterShiftValue : int
			{
				NegativeOffset,
				Simplex,
				PositiveOffset
			};

			enum class EncoderTypeValue : int
			{
				OFF,
				ENC,
				TSQ
			};

			enum class CTCSSTone : int
			{
				Tone_67_0,
				Tone_69_3,
				Tone_71_9,
				Tone_74_4,
				Tone_77_0,
				Tone_79_7,
				Tone_82_5,
				Tone_85_4,
				Tone_88_5,
				Tone_91_5,
				Tone_94_8,
				Tone_97_4,
				Tone_100_0,
				Tone_103_5,
				Tone_107_2,
				Tone_110_9,
				Tone_114_8,
				Tone_118_8,
				Tone_123_0,
				Tone_127_3,
				Tone_131_8,
				Tone_136_5,
				Tone_141_3,
				Tone_146_2,
				Tone_151_4,
				Tone_156_7,
				Tone_159_8,
				Tone_162_2,
				Tone_165_5,
				Tone_167_9,
				Tone_171_3,
				Tone_173_8,
				Tone_177_3,
				Tone_179_9,
				Tone_183_5,
				Tone_186_2,
				Tone_189_9,
				Tone_192_8,
				Tone_196_6,
				Tone_199_5,
				Tone_203_5,
				Tone_206_5,
				Tone_210_7,
				Tone_218_1,
				Tone_225_7,
				Tone_229_1,
				Tone_233_6,
				Tone_241_8,
				Tone_250_3,
				Tone_254_1
			};

			enum class MarkFrequency : int
			{
				_1275Hz = 1,
				_2125Hz
			};

			enum class ShiftFrequency : int
			{
				_170Hz = 1,
				_200Hz,
				_425Hz,
				_850Hz
			};

			enum class Polarity_TX : int
			{
				NOR,
				REV
			};

			enum class CWBreakInType : int
			{
				SEMI,
				FULL
			};

			enum class CWWaveShape : int
			{
				_4msec,
				_6msec,
				_8msec
			};

			enum class CWFreqencyDisplayValue : int
			{
				DirectFrequency,
				PitchOffset
			};

			enum class QSKDelayTimeValue : int
			{
				_15msec,
				_20msec,
				_25msec,
				_30msec
			};

			enum class KeyerTypeValue : int
			{
				OFF,
				BUG,
				ELEKEY_A,
				ELEKEY_B,
				ELEKEY_Y,
				ACS
			};

			enum class KeyerDotDashValue : int
			{
				NOR,
				REV
			};

			enum class CWWeightValue : int
			{
				_25 = 25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45
			};

			enum class NumberStyleValue : int
			{
				_1290,
				AUNO,
				AUNT,
				A2NO,
				A2NT,
				_12NO,
				_12NT
			};

			enum class CWMemoryType : int
			{
				TEXT,
				MESSAGE
			};

			enum class FineTuningValue : int
			{
				OFF,
				ON,
				FAST
			};

			enum class HighLowValue : int
			{
				LOW,
				HIGH
			};

			struct GPOutParam
			{
				HighLowValue A;
				HighLowValue B;
				HighLowValue C;
				HighLowValue D;
			};

			struct CTCSSParam
			{
				MainSubValue band;
				CTCSSFunction function;
			};

			struct DimmerParam
			{
				int TFT_Contrast;
				int TFT_Brightness;
				int LED_Indicators_Brightness;
			};

			union CountourValue
			{
				OnOffValue State;
				int Frequency;
			};

			struct ContourParam
			{
				CountourFunction function;
				CountourValue value;
			};

			struct ClarifierSetting
			{
				OnOffValue RX;
				OnOffValue TX;
			};

			union ClarifierValue
			{
				ClarifierSetting setting;
				int frequency;
			};

			struct ClarifierParam
			{
				MainSubValue Band;
				ClarifierFunction Function;
				ClarifierValue Value;
			};

			struct ClarifierReadParam
			{
				MainSubValue Band;
				ClarifierFunction Function;
			};

			union ManualNotchValue
			{
				OnOffValue OnOff;
				int Frequency;
			};

			union AESSValue
			{
				int Level;
				AESSCutOffFrequency CutOff;
			};

			struct ManualNotchParam
			{
				ManualNotchFunction function;
				ManualNotchValue value;
			};

			struct AESSParam
			{
				AESSFunction function;
				AESSValue value;
			};

			struct AntennaTunerParam
			{
				AntennaTunerType type;
				AntennaTunerState state;
				AntennaTunerFunction function;
			};

			class VFO_A_TO_VFO_B
			{
			public:
				static std::string Set();
			};

			class AntennaTunerControl
			{
			public:
				static std::string Set(AntennaTunerParam value);
				static std::string Read();
				static AntennaTunerParam Answer(std::string data);
			};

			class AF_Gain
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AutoInformation
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(const std::string& data);
			};

			class VFO_A_TO_MemoryChannel
			{
			public:
				static std::string Set();
			};

			class AMCOutputLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class AESS
			{
			public:
				static std::string Set(AESSParam value);
				static std::string Read(AESSFunction value);
				static AESSParam Answer(std::string data);
			};

			class AntiVoxLevel
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			class VFO_B_TO_VFO_A
			{
			public:
				static std::string Set();
			};

			class AutoNotch
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class BandDown
			{
			public:
				static std::string Set(MainSubValue value);
			};

			class BreakIn
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class VFO_B_ToMemoryChannel
			{
			public:
				static std::string Set();
			};

			class ManualNotch
			{
			public:
				static std::string Set(ManualNotchParam value);
				static std::string Read(ManualNotchFunction value);
				static ManualNotchParam Answer(std::string data);
			};

			class BandSelect
			{
			public:
				static std::string Set(BandValue value);
			};

			class BandUp
			{
			public:
				static std::string Set(MainSubValue value);
			};

			class ClarifierOnOff
			{
			public:
				static std::string Set(ClarifierParam value);
				static std::string Read(ClarifierReadParam value);
				static ClarifierParam Answer(std::string data);
			};

			class ChannelUpDown
			{
			public:
				static std::string Set(UpDownValue value);
			};

			struct CTCSSToneValue
			{
				MainSubValue Band;
				CTCSSTone Tone;
			};

			class CTCSSToneFrequency
			{
			public:
				static std::string Set(CTCSSToneValue value);
				static std::string Read(MainSubValue value);
				static CTCSSToneValue Answer(std::string data);
			};

			class Contour
			{
			public:
				static std::string Set(ContourParam value);
				static std::string Read(CountourFunction value);
				static ContourParam Answer(std::string data);
			};

			class CWSpot
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
				static std::string Read(MainSubValue value);
				static CTCSSParam Answer(std::string data);
			};

			class Dimmer
			{
			public:
				static std::string Set(DimmerParam value);
				static std::string Read();
				static DimmerParam Answer(std::string data);
			};

			class MicDown
			{
			public:
				static std::string Set();
			};

			enum class DateTimeType
			{
				Date,
				Time
			};

			struct DateTimeParam
			{
				DateTimeType type;
				std::string value;
			};


			class DateTime
			{
			public:
				static std::string Set(DateTimeParam value);
				static std::string Read(DateTimeType value);
				static DateTimeParam Answer(std::string data);
			};


			class Menu
			{
			public:
				class RadioSetting
				{
				public:
					class ModeSSB
					{
					public:

						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

						class NAR_WIDTH
						{
						public:
							static std::string Set(NarrowWidthValue value);
							static std::string Read();
							static NarrowWidthValue Answer(std::string data);
						};

						class CW_AUTO_MODE
						{
						public:
							static std::string Set(CWAutoModeValue value);
							static std::string Read();
							static CWAutoModeValue Answer(std::string data);
						};
					};

					class ModeAM
					{
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};

					class ModeFM
					{
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};


						class RPT_SHIFT
						{
						public:
							static std::string Set(RepeaterShiftValue value);
							static std::string Read();
							static RepeaterShiftValue Answer(std::string data);
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


						class ENC_DEC
						{
						public:
							static std::string Set(EncoderTypeValue value);
							static std::string Read();
							static EncoderTypeValue Answer(std::string data);
						};


						class TONE_FREQ
						{
						public:
							static std::string Set(CTCSSTone value);
							static std::string Read();
							static CTCSSTone Answer(std::string data);
						};
					};

					class ModePSK_DATA
					{
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};


						class NAR_WIDTH
						{
						public:
							static std::string Set(DataWidthValue value);
							static std::string Read();
							static DataWidthValue Answer(std::string data);
						};


						class PSK_TONE
						{
						public:
							static std::string Set(PSKToneValue value);
							static std::string Read();
							static PSKToneValue Answer(std::string data);
						};


						class DATA_SHIFT
						{
						public:
							///<summary>Shift values are a multiple of 10. 
							///Set will ensure the data sent to the radio is a multiple of 10
							///and will not exceed the maximum of 3000 or the minimum of 0.  
							/// </summary>
							static std::string Set(int value);
							/// <summary>
							/// Creates the request for the DATA SHIFT value from the radio.
							/// </summary>
							/// <returns>std::string containing the request data</returns>
							static std::string Read();
							/// <summary>
							/// Parses the response from the radio, and provides the shift value
							/// </summary>
							/// <param name="data">Pass the data received from the radio in this paramater</param>
							/// <returns>an int with the value stored in the radio</returns>
							static int Answer(std::string data);
						};

					};

					class ModeRTTY
					{
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

						class NAR_WIDTH
						{
						public:
							static std::string Set(DataWidthValue value);
							static std::string Read();
							static DataWidthValue Answer(std::string data);
						};


						class MARK_FREQUENCY
						{
						public:
							static std::string Set(MarkFrequency value);
							static std::string Read();
							static MarkFrequency Answer(std::string data);
						};


						class SHIFT_FREQUENCY
						{
						public:
							static std::string Set(ShiftFrequency value);
							static std::string Read();
							static ShiftFrequency Answer(std::string data);
						};


						class POLARITY_TX
						{
						public:
							static std::string Set(Polarity_TX value);
							static std::string Read();
							static Polarity_TX Answer(std::string data);
						};


					};

				};

				class CWSetting
				{
				public:
					class ModeCW
					{
					public:
						class AF_TREBEL_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_MIDDLE_TONE_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AF_BASS_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

						class NAR_WIDTH
						{
						public:
							static std::string Set(DataWidthValue value);
							static std::string Read();
							static DataWidthValue Answer(std::string data);
						};


						class PC_KEYING
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};



						class CW_BK_IN_TYPE
						{
						public:
							static std::string Set(CWBreakInType value);
							static std::string Read();
							static CWBreakInType Answer(std::string data);
						};


						class CW_WAVE_SHAPE
						{
						public:
							static std::string Set(CWWaveShape value);
							static std::string Read();
							static CWWaveShape Answer(std::string data);
						};

						class CW_FREQ_DISPLAY
						{
						public:
							static std::string Set(CWFreqencyDisplayValue value);
							static std::string Read();
							static CWFreqencyDisplayValue Answer(std::string data);
						};

						class QSK_DELAY_TIME
						{
						public:
							static std::string Set(QSKDelayTimeValue value);
							static std::string Read();
							static QSKDelayTimeValue Answer(std::string data);
						};

						class CW_INDICATOR
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};
					};

					class Keyer
					{

						class KEYER_TYPE
						{
						public:
							static std::string Set(KeyerTypeValue value);
							static std::string Read();
							static KeyerTypeValue Answer(std::string data);
						};


						class KEYER_DOT_DASH
						{
						public:
							static std::string Set(KeyerDotDashValue value);
							static std::string Read();
							static KeyerDotDashValue Answer(std::string data);
						};


						class CW_WEIGHT
						{
						public:
							static std::string Set(CWWeightValue value);
							static std::string Read();
							static CWWeightValue Answer(std::string data);
						};


						class NUMBER_STYLE
						{
						public:
							static std::string Set(NumberStyleValue value);
							static std::string Read();
							static NumberStyleValue Answer(std::string data);
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
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};


						class CW_MEMORY_2
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_3
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_4
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};

						class CW_MEMORY_5
						{
						public:
							static std::string Set(CWMemoryType value);
							static std::string Read();
							static CWMemoryType Answer(std::string data);
						};


						class REPEAT_INTERVAL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};
				};

				class OperationSetting
				{
				public:
					class GENERAL
					{
					public:

						class BEEP_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class RF_SQL_VR
						{
						public:
							static std::string Set(RF_SQL_VRValue value);
							static std::string Read();
							static RF_SQL_VRValue Answer(std::string data);
						};


						class TUN_LIN_PORT_SELECT
						{
						public:
							static std::string Set(TunerLinPortValue value);
							static std::string Read();
							static TunerLinPortValue Answer(std::string data);
						};


						class TUNER_TYPE_SELECT
						{
						public:
							static std::string Set(TunerTypeValue value);
							static std::string Read();
							static TunerTypeValue Answer(std::string data);
						};


						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};


						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};


						class CAT_2_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};

						class CAT_2_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_3_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};

						class CAT_3_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue	 value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};


						class QMB_CH
						{
						public:
							static std::string Set(QMBChannelValue value);
							static std::string Read();
							static QMBChannelValue Answer(std::string data);
						};


						class BAND_STACK
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};

						class MEM_GROUP
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};


						class TX_TIME_OUT_TIMER
						{
						public:
							static std::string Set(TimeOutValue value);
							static std::string Read();
							static TimeOutValue Answer(std::string data);
						};

						class MIC_SCAN
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};


						class MIC_SCAN_RESUME
						{
						public:
							static std::string Set(ScanResumeType value);
							static std::string Read();
							static ScanResumeType Answer(std::string data);
						};


						class REF_FREQ_ADJ
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class KEYBOARD_LANGUAGE
						{
						public:
							static std::string Set(KeyboardLanguageType value);
							static std::string Read();
							static KeyboardLanguageType Answer(std::string data);
						};


						class MIC_P1
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};

						class MIC_P2
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};
						class MIC_P3
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};
						class MIC_P4
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};

						class MIC_UP
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};

						class MIC_DOWN
						{
						public:
							static std::string Set(MicButtonType value);
							static std::string Read();
							static MicButtonType Answer(std::string data);
						};


						class SCU_LAN10
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};
					};

					class RX_DSP
					{
					public:

						class IF_NOTCH_WIDTH
						{
						public:
							static std::string Set(IFNotchWidth value);
							static std::string Read();
							static IFNotchWidth Answer(std::string data);
						};


						class NB_REJECTION
						{
						public:
							static std::string Set(NBRejectionValue value);
							static std::string Read();
							static NBRejectionValue Answer(std::string data);
						};


						class NB_WIDTH
						{
						public:
							static std::string Set(NBWidthValue value);
							static std::string Read();
							static NBWidthValue Answer(std::string data);
						};


						class APF_WIDTH
						{
						public:
							static std::string Set(APFWidthValue value);
							static std::string Read();
							static APFWidthValue Answer(std::string data);
						};


						class CONTOUR_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class CONTOUR_WIDTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};

					class TX_AUDIO
					{
					public:

						class AMC_RELEASE_TIME
						{
						public:
							static std::string Set(AMCReleaseTimeValue value);
							static std::string Read();
							static AMCReleaseTimeValue Answer(std::string data);
						};


						class PRMTRC_EQ1_FREQ
						{
						public:
							static std::string Set(EQ1FrequencyValue value);
							static std::string Read();
							static EQ1FrequencyValue Answer(std::string data);
						};

						class PRMTRC_EQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ2_FREQ
						{
						public:
							static std::string Set(EQ2FrequencyValue value);
							static std::string Read();
							static EQ2FrequencyValue Answer(std::string data);
						};

						class PRMTRC_EQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ3_FREQ
						{
						public:
							static std::string Set(EQ3FrequencyValue value);
							static std::string Read();
							static EQ3FrequencyValue Answer(std::string data);
						};

						class PRMTRC_EQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class PRMTRC_EQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class P_PRMTRC_EQ1_FREQ
						{
						public:
							static std::string Set(EQ1FrequencyValue value);
							static std::string Read();
							static EQ1FrequencyValue Answer(std::string data);
						};

						class P_PRMTRC_EQ1_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ1_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ2_FREQ
						{
						public:
							static std::string Set(EQ2FrequencyValue value);
							static std::string Read();
							static EQ2FrequencyValue Answer(std::string data);
						};

						class P_PRMTRC_EQ2_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ2_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ3_FREQ
						{
						public:
							static std::string Set(EQ3FrequencyValue value);
							static std::string Read();
							static EQ3FrequencyValue Answer(std::string data);
						};

						class P_PRMTRC_EQ3_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class P_PRMTRC_EQ3_BWTH
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

					};

					class TX_GENERAL
					{
					public:

						class MAX_POWER_HF
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_50M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_70M
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MAX_POWER_AM
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class VOX_SELECT
						{
						public:
							static std::string Set(VoxSelectValue value);
							static std::string Read();
							static VoxSelectValue Answer(std::string data);
						};


						class EMERGENCY_FREQ_TX
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};


						class TX_INHIBIT
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};


						class METER_DETECTOR
						{
						public:
							static std::string Set(MeterDetectorValue value);
							static std::string Read();
							static MeterDetectorValue Answer(std::string data);
						};
					};

					class TUNING
					{
					public:


						class SSB_CW_DIALSTEP
						{
						public:
							static std::string Set(DialStepValue value);
							static std::string Read();
							static DialStepValue Answer(std::string data);
						};


						class RTTY_PSK_DIAL_STEP
						{
						public:
							static std::string Set(DialStepValue value);
							static std::string Read();
							static DialStepValue Answer(std::string data);
						};


						class CH_STEP
						{
						public:
							static std::string Set(ChannelStepValue value);
							static std::string Read();
							static ChannelStepValue Answer(std::string data);
						};


						class AM_CH_STEP
						{
						public:
							static std::string Set(AMChannelStepValue value);
							static std::string Read();
							static AMChannelStepValue Answer(std::string data);
						};


						class FM_CH_STEP
						{
						public:
							static std::string Set(FMChannelStepValue value);
							static std::string Read();
							static FMChannelStepValue Answer(std::string data);
						};


						class MAIN_STEPS_PER_REV
						{
						public:
							static std::string Set(StepsPerRevValue value);
							static std::string Read();
							static StepsPerRevValue Answer(std::string data);
						};
					};
				};

				class DisplaySetting
				{
				public:
					class DISPLAY
					{
					public:

						class MY_CALL
						{
						public:
							static std::string Set(std::string value);
							static std::string Read();
							static std::string Answer(std::string data);
						};


						class MY_CALL_TIME
						{
						public:
							static std::string Set(MyCallTimeValue value);
							static std::string Read();
							static MyCallTimeValue Answer(std::string data);
						};


						class POP_UP_TIME
						{
						public:
							static std::string Set(PopUpTimeValue value);
							static std::string Read();
							static PopUpTimeValue Answer(std::string data);
						};


						class SCREEN_SAVER
						{
						public:
							static std::string Set(ScreenSaverValue value);
							static std::string Read();
							static ScreenSaverValue Answer(std::string data);
						};


						class DIMMER_LED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class MOUSE_POINTER_SPEED
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
					};

					class SCOPE
					{
					public:

						class RBW
						{
						public:
							static std::string Set(RBWTimeValue	 value);
							static std::string Read();
							static RBWTimeValue Answer(std::string data);
						};


						class SCOPE_CTR
						{
						public:
							static std::string Set(ScopeCenterValue value);
							static std::string Read();
							static ScopeCenterValue Answer(std::string data);
						};


						class DISP_SENSITIVITY_2D
						{
						public:
							static std::string Set(DisplaySensitivityValue value);
							static std::string Read();
							static DisplaySensitivityValue Answer(std::string data);
						};


						class DISP_SENSITIVITY_3DSS
						{
						public:
							static std::string Set(DisplaySensitivityValue value);
							static std::string Read();
							static DisplaySensitivityValue Answer(std::string data);
						};

					};

					class VFO_IND_COLOR
					{
					public:

						class VMI_COLOR_VFO_A
						{
						public:
							static std::string Set(TriColorValue value);
							static std::string Read();
							static TriColorValue Answer(std::string data);
						};


						class VMI_COLOR_VFO_B
						{
						public:
							static std::string Set(TriColorValue value);
							static std::string Read();
							static TriColorValue Answer(std::string data);
						};


						class VMI_COLOR_MEMORY
						{
						public:
							static std::string Set(TriColorValue value);
							static std::string Read();
							static TriColorValue Answer(std::string data);
						};


						class VMI_COLOR_CLAR
						{
						public:
							static std::string Set(SingleColorValue value);
							static std::string Read();
							static SingleColorValue Answer(std::string data);
						};

					};

					class EXT_MONITOR
					{
					public:

						class EXT_DISPLAY
						{
						public:
							static std::string Set(OnOffValue value);
							static std::string Read();
							static OnOffValue Answer(std::string data);
						};


						class PIXEL
						{
						public:
							static std::string Set(PixelValue value);
							static std::string Read();
							static PixelValue Answer(std::string data);
						};

					};
				};

				class ExtensionSetting
				{
				public:
					class PRESET1
					{
					public:
						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};

					class PRESET2
					{
					public:
						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};
					class PRESET3
					{
					public:
						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};
					class PRESET4
					{
					public:
						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};
					class PRESET5
					{
					public:
						class CAT_1_RATE
						{
						public:
							static std::string Set(CAT_Rate value);
							static std::string Read();
							static CAT_Rate Answer(std::string data);
						};


						class CAT_1_TIME_OUT_TIMER
						{
						public:
							static std::string Set(CAT_TimeOutValue value);
							static std::string Read();
							static CAT_TimeOutValue Answer(std::string data);
						};

						class CAT_1_CAT_3_STOP_BIT
						{
						public:
							static std::string Set(CAT_StopBitType value);
							static std::string Read();
							static CAT_StopBitType Answer(std::string data);
						};

						class AGC_FAST_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_MID_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class AGC_SLOW_DELAY
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};
						class LCUT_FREQ
						{
						public:
							static std::string Set(LCUTFreq value);
							static std::string Read();
							static LCUTFreq Answer(std::string data);
						};


						class LCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class HCUT_FREQ
						{
						public:
							static std::string Set(HCutFreq value);
							static std::string Read();
							static HCutFreq Answer(std::string data);
						};


						class HCUT_SLOPE
						{
						public:
							static std::string Set(SlopeValue value);
							static std::string Read();
							static SlopeValue Answer(std::string data);
						};


						class USB_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class REAR_OUT_LEVEL
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};


						class TX_BPF_SELECT
						{
						public:
							static std::string Set(TXBandPassValue value);
							static std::string Read();
							static TXBandPassValue Answer(std::string data);
						};

						class MOD_SOURCE
						{
						public:
							static std::string Set(ModulationSourceValue value);
							static std::string Read();
							static ModulationSourceValue Answer(std::string data);
						};

						class USB_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class REAR_MOD_GAIN
						{
						public:
							static std::string Set(int value);
							static std::string Read();
							static int Answer(std::string data);
						};

						class RPTT_SELECT
						{
						public:
							static std::string Set(RPTTSelectValue value);
							static std::string Read();
							static RPTTSelectValue Answer(std::string data);
						};

					};
				};
			};


			class FREQUENCY_VFO_A
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class FREQUENCY_VFO_B
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class FINE_TUNING
			{
			public:
				static std::string Set(FineTuningValue value);
				static std::string Read();
				static FineTuningValue Answer(std::string data);
			};


			class FUNCTION_TX
			{
			public:
				static std::string Set(MainSubValue value);
				static std::string Read();
				static MainSubValue Answer(std::string data);
			};


			class GP_OUT
			{
			public:
				static std::string Set(GPOutParam value);
				static std::string Read();
				static GPOutParam Answer(std::string data);
			};

			enum class AGCSetValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO
			};

			enum class AGCAnswerValue : int
			{
				OFF,
				FAST,
				MID,
				SLOW,
				AUTO_FAST,
				AUTO_MID,
				AUTO_SLOW
			};


			class AGC_FUNCTION
			{
			public:
				static std::string Set(AGCSetValue value);
				static std::string Read();
				static AGCAnswerValue Answer(std::string data);
			};

			enum class MemoryChannelValue
			{
				_0,
				_1,
				_2,
				_3,
				_4,
				_5,
				_6,
				_7,
				_8,
				_9,
				_10,
				_11,
				_12,
				_13,
				_14,
				_15,
				_16,
				_17,
				_18,
				_19,
				_20,
				_21,
				_22,
				_23,
				_24,
				_25,
				_26,
				_27,
				_28,
				_29,
				_30,
				_31,
				_32,
				_33,
				_34,
				_35,
				_36,
				_37,
				_38,
				_39,
				_40,
				_41,
				_42,
				_43,
				_44,
				_45,
				_46,
				_47,
				_48,
				_49,
				_50,
				_51,
				_52,
				_53,
				_54,
				_55,
				_56,
				_57,
				_58,
				_59,
				_60,
				_61,
				_62,
				_63,
				_64,
				_65,
				_66,
				_67,
				_68,
				_69,
				_70,
				_71,
				_72,
				_73,
				_74,
				_75,
				_76,
				_77,
				_78,
				_79,
				_80,
				_81,
				_82,
				_83,
				_84,
				_85,
				_86,
				_87,
				_88,
				_89,
				_90,
				_91,
				_92,
				_93,
				_94,
				_95,
				_96,
				_97,
				_98,
				_99,
				P1L,
				P1U,
				P2L,
				P2U,
				P3L,
				P3U,
				P4L,
				P4U,
				P5L,
				P5U,
				P6L,
				P6U,
				P7L,
				P7U,
				P8L,
				P8U,
				P9L,
				P9U,
				_5351_5mhz = 501,
				_5354mhz,
				_5357mhz,
				_5360mhz,
				_5363mhz,
				_5366mhz,
				EMG = 600

			};

			enum class ClarifierState : int
			{
				OFF,
				ON
			};

			enum class ModeValue : int
			{
				LSB = 1,
				USB,
				CW_U,
				FM,
				AM,
				RTTY_LSB,
				CW_L,
				DATA_LSB,
				RTTY_USB,
				DATA_FM,
				FM_N,
				DATA_USB,
				AM_N,
				PSK,
				DATA_FM_N
			};

			enum class VFOChannelTypeValue : int
			{
				VFO,
				Memory,
				MemoryTune,
				QuickMemeoryBank,
				PMS = 5,
			};

			enum class CTCSSState : int
			{
				OFF,
				CTCSS_ENC_DEC,
				CTCSS_ENC,
			};

			enum class OperationType : int
			{
				Simplex,
				PlusShift,
				MinusShift
			};

			struct InformationValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOAFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				ClarifierState TXClarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};

			struct OInformationValue
			{
				MemoryChannelValue MemoryChannel{};
				int VFOBFreq{};
				int ClarifierFreq{};
				ClarifierState Clarifier{};
				ClarifierState TXClarifier{};
				ModeValue Mode{};
				VFOChannelTypeValue VFO{};
				CTCSSState CTCSS{};
				OperationType Operation{};
			};
			class INFORMATION
			{
			public:
				static std::string Read();
				static InformationValue Answer(std::string data);
			};


			class IF_SHIFT
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			struct KeyerMemoryValue
			{
				int ChannelNumber{};
				std::string Message{};
			};


			class KEYER_MEMORY
			{
			public:
				static std::string Set(KeyerMemoryValue value);
				static std::string Read(int MemoryChannelNumber);
				static KeyerMemoryValue Answer(std::string data);
			};

			enum class KeyPitchValue
			{
				_300Hz,
				_310Hz,
				_320Hz,
				_330Hz,
				_340Hz,
				_350Hz,
				_360Hz,
				_370Hz,
				_380Hz,
				_390Hz,
				_400Hz,
				_410Hz,
				_420Hz,
				_430Hz,
				_440Hz,
				_450Hz,
				_460Hz,
				_470Hz,
				_480Hz,
				_490Hz,
				_500Hz,
				_510Hz,
				_520Hz,
				_530Hz,
				_540Hz,
				_550Hz,
				_560Hz,
				_570Hz,
				_580Hz,
				_590Hz,
				_600Hz,
				_610Hz,
				_620Hz,
				_630Hz,
				_640Hz,
				_650Hz,
				_660Hz,
				_670Hz,
				_680Hz,
				_690Hz,
				_700Hz,
				_710Hz,
				_720Hz,
				_730Hz,
				_740Hz,
				_750Hz,
				_760Hz,
				_770Hz,
				_780Hz,
				_790Hz,
				_800Hz,
				_810Hz,
				_820Hz,
				_830Hz,
				_840Hz,
				_850Hz,
				_860Hz,
				_870Hz,
				_880Hz,
				_890Hz,
				_900Hz,
				_910Hz,
				_920Hz,
				_930Hz,
				_940Hz,
				_950Hz,
				_960Hz,
				_970Hz,
				_980Hz,
				_990Hz,
				_1000Hz,
				_1010Hz,
				_1020Hz,
				_1030Hz,
				_1040Hz,
				_1050Hz

			};

			class KEY_PITCH
			{
			public:
				static std::string Set(KeyPitchValue value);
				static std::string Read();
				static KeyPitchValue Answer(std::string data);
			};


			class KEYER
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class KEY_SPEED
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			enum class CWKeyingValue : int
			{
				STOP,
				Memory1_playback,
				Memory2_playback,
				Memory3_playback,
				Memory4_playback,
				memory5_playback
			};

			struct CWKeyingParam
			{
				CWMemoryType type;
				CWKeyingValue PlayBackValue;
			};


			class CW_KEYING
			{
			public:
				static std::string Set(CWKeyingParam value);
			};


			class LOCK
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum class LoadMessageType : int
			{
				MESSAGE,
				RECORD
			};

			enum class LoadMessageChannel : int
			{
				STOP,
				CH1,
				CH2,
				CH3,
				CH4,
				CH5
			};

			enum class LoadMessageRecordingValue : int
			{
				STOP,
				START
			};

			union LoadMessageValue
			{
				LoadMessageChannel channel;
				LoadMessageRecordingValue recording;
			};

			struct LoadMessageParam
			{
				LoadMessageType type;
				LoadMessageValue value;
			};


			class LOAD_MESSAGE
			{
			public:
				static std::string Set(LoadMessageParam value);
				static std::string Read(LoadMessageType type);
				static LoadMessageParam Answer(std::string data);
			};


			class MEMORY_CHANNEL_TO_VFO_A
			{
			public:
				static std::string Set();
			};

			class MEMORY_CHANNEL_TO_VFO_B
			{
			public:
				static std::string Set();
			};


			class MEMORY_CHANNEL
			{
			public:
				static std::string Set(MemoryChannelValue value);
				static std::string Read();
				static MemoryChannelValue Answer(std::string data);
			};

			struct OperatingModeParam
			{
				MainSubValue band;
				ModeValue mode;
			};


			class OPERATING_MODE
			{
			public:
				static std::string Set(OperatingModeParam value);
				static std::string Read(MainSubValue band);
				static OperatingModeParam Answer(std::string data);
			};


			class MIC_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			struct MemoryChannel
			{
				MemoryChannelValue channel;
				int Frequency;
				int Clarifier;
				OnOffValue RX_Clarifier;
				OnOffValue TX_CLarifier;
				ModeValue mode;
				VFOChannelTypeValue ChannelType;
				CTCSSState CTCSS_State;
				OperationType Operation;
			};

			class MEMORY_CHANNEL_READ
			{
			public:

				static std::string Read(MemoryChannelValue value);
				static MemoryChannel Answer(std::string data);
			};

			enum class MeterType : int
			{
				PO,
				COMP,
				ALC,
				VDD,
				ID,
				SWR
			};


			class METER_SW
			{
			public:
				static std::string Set(MeterType value);
				static std::string Read();
				static MeterType Answer(std::string data);
			};

			struct MemoryChannelTagParam
			{
				MemoryChannelValue channel;
				OnOffValue TagState;
				std::string tagString;
			};


			class MEMORY_CHANNEL_TAG_WRITE
			{
			public:
				static std::string Set(MemoryChannelTagParam value);
				static std::string Read(MemoryChannelValue channel);
				MemoryChannelTagParam Answer(std::string data);
			};


			class MEMORY_CHANNEL_WRITE
			{
			public:
				static std::string Set(MemoryChannel value);

			};


			class NARROW
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class NOISE_BLANKER
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class NOISE_BLANKER_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class NOISE_REDUCTION
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class OPPOSITE_BAND_INFORMATION
			{
			public:

				static std::string Read();
				static OInformationValue Answer(std::string data);
			};

			struct OffsetParam
			{
				MainSubValue band;
				OperationType operation;
			};

			class OFFSET
			{
			public:
				static std::string Set(OffsetParam value);
				static std::string Read(MainSubValue band);
				static OffsetParam Answer(std::string data);
			};

			enum class PreAmpValue : int
			{
				IPO,
				AMP_1,
				AMP_2
			};


			class PRE_AMP
			{
			public:
				static std::string Set(PreAmpValue value);
				static std::string Read();
				static PreAmpValue Answer(std::string data);
			};


			class PLAY_BACK
			{
			public:
				static std::string Set(LoadMessageChannel value);
				static std::string Read();
				static LoadMessageChannel Answer(std::string data);
			};


			class POWER_CONTROL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class SPEECH_PROCESSOR_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SpeechProcessorType : int
			{
				SpeechProcessor,
				ParametricMicrophoneEqualizer
			};

			struct SpeechProcessorParam
			{
				SpeechProcessorType type;
				OnOffValue state;
			};


			class SPEECH_PROCESSOR
			{
			public:
				static std::string Set(SpeechProcessorParam value);
				static std::string Read(SpeechProcessorType type);
				static SpeechProcessorParam Answer(std::string data);
			};


			class POWER_SWITCH
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class QMB_STORE
			{
			public:
				static std::string Set();
			};

			class QMB_RECALL
			{
			public:
				static std::string Set();
			};

			enum class RFAttenuatorValue : int
			{
				OFF,
				dB6,
				dB12,
				dB18
			};


			class RF_ATTENUATOR
			{
			public:
				static std::string Set(RFAttenuatorValue value);
				static std::string Read();
				static RFAttenuatorValue Answer(std::string data);
			};


			class RF_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SWRStatusValue : int
			{
				Normal,
				Hi_SWR
			};

			enum class RecordingStateValue : int
			{
				Stop,
				Recording,
				Playing
			};

			enum class TransceiverStateValue : int
			{
				RX,
				TX,
				TX_INHIBIT
			};

			enum class AntennaTunerStateValue : int
			{
				Stopped,
				Tuning
			};

			enum class ScanningStateValue : int
			{
				Stopped,
				Scanning,
				Paused
			};

			enum class SquelchStateValue : int
			{
				Closed,
				Open
			};

			struct RadioInformationParam
			{
				SWRStatusValue SWRState;
				RecordingStateValue RecordingState;
				TransceiverStateValue TransceiverState;
				AntennaTunerStateValue AntennaTunerState;
				ScanningStateValue ScanningState;
				SquelchStateValue SquelchState;
			};


			class RADIO_INFORMATION
			{
			public:
				static std::string Read();
				static RadioInformationParam Answer(std::string data);
			};


			class NOISE_REDUCTION_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			enum class ReadMeterType : int
			{
				None,
				S,
				COMP = 3,
				ALC,
				PO,
				SQR,
				IDD,
				VDD
			};

			struct ReadMeterParam
			{
				ReadMeterType meter;
				int value;
			};


			class READ_METER
			{
			public:
				static std::string Read(ReadMeterType meter);
				static ReadMeterParam Answer(std::string data);
			};

			enum class ScanValue : int
			{
				OFF,
				UP,
				DOWN
			};


			class SCAN
			{
			public:
				static std::string Set(ScanValue value);
				static std::string Read();
				static ScanValue Answer(std::string data);
			};


			class CW_BREAK_IN_DELAY_TIME
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SubDialKnob : int
			{
				FUNC,
				DSP
			};

			enum class SubDialFunction : int
			{
				SCOPE_LEVEL = 1,
				PEAK,
				COLOR,
				CONTRAST,
				DIMMER,
				M_GROUP,
				MIC_GAIN,
				PROC_LEVEL,
				AMC_LEVEL,
				VOX_GAIN,
				ANTI_VOX,
				RF_POWER,
				MONI_LEVEL,
				CW_SPEED,
				CW_PITCH,
				BK_DELAY
			};

			enum class SubDialDsp : int
			{
				SHIFT = 1,
				WIDTH,
				NOTCH,
				CONTOUR,
				APF
			};

			union SubDialValue
			{
				SubDialFunction function;
				SubDialDsp dsp;
			};

			struct SubDialParam
			{
				SubDialKnob knob;
				SubDialValue value;
			};


			class SUB_DIAL_FUNCTION
			{
			public:
				static std::string Set(SubDialParam value);
				static std::string Read(SubDialKnob knob);
				static SubDialParam Answer(std::string data);
			};

			class WIDTH
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class S_METER_READING
			{
			public:
				static std::string Read();
				static int Answer(std::string data);
			};


			class SQUELCH_LEVEL
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};

			enum class SpectrumScopeFunction : int
			{
				SPEED,
				PEAK,
				MARKER,
				COLOR,
				LEVEL,
				SPAN,
				MODE,
				AF_FFT_OSCILLOSCOPE
			};

			enum class SpectrumScopeSpeed : int
			{
				SLOW1,
				SLOW2,
				FAST1,
				FAST2,
				FAST3,
				STOP
			};

			enum class SpectrumScopePeak : int
			{
				LVL1,
				LVL2,
				LVL3,
				LVL4,
				LVL5
			};


			enum class SpectrumScopeColor : int
			{
				COLOR_1,
				COLOR_2,
				COLOR_3,
				COLOR_4,
				COLOR_5,
				COLOR_6,
				COLOR_7,
				COLOR_8,
				COLOR_10,
				COLOR_11,
			};

			enum class SpectrumScopeSpan : int
			{
				kHz_1,
				kHz_2,
				kHz_5,
				kHz_10,
				kHz_20,
				kHz_50,
				kHz_100,
				kHz_200,
				kHz_500,
				MHz_1
			};

			enum class SpectrumScopeMode : int
			{
				CENTER_3DSS,
				CURSOR_3DSS,
				FIX_3DSS,
				CENTER_WATERFALL_EXPANDED,
				CENTER_WATERFALL_NORMAL,
				CURSOR_WATERFALL_EXPANDED = 6,
				CURSOR_WATERFALL_NORMAL,
				FIXED_WATERFALL_EXPANDED = 9,
				FIXED_WATERFALL_NORMAL
			};

			enum class SpectrumScopeOscilloscopeType : int
			{
				AF_FFT_0dB,
				AF_FFT_10dB,
				AF_FFT_20dB,
			};

			enum class OSCLevelType : int
			{
				ATT_0dB,
				ATT_10dB,
				ATT_20dB
			};

			enum class OSCTime : int
			{
				msec_1,
				msec_3,
				msec_10,
				msec_30,
				msec_100,
				msec_300
			};

			struct OscilloscopeValue
			{
				SpectrumScopeOscilloscopeType type;
				OSCLevelType level;
				OSCTime time;
			};

			union SpectrumScopeValue
			{
				SpectrumScopeSpeed speed;
				SpectrumScopePeak peak;
				OnOffValue marker;
				SpectrumScopeColor color;
				float level;
				SpectrumScopeSpan span;
				SpectrumScopeMode mode;
				OscilloscopeValue value;
			};

			struct SpectrumScopeParam
			{
				SpectrumScopeFunction function;
				SpectrumScopeValue value;
			};


			class SPECTRUM_SCOPE
			{
			public:
				static std::string Set(SpectrumScopeParam value);
				static std::string Read(SpectrumScopeFunction function);
				static SpectrumScopeParam Answer(std::string data);
			};


			class SPLIT
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			class SWAP_VFO
			{
			public:
				static std::string Set();
			};


			class TXW
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};

			enum class TXSetValue : int
			{
				RADIO_OFF_CAT_OFF,
				RADIO_OFF_CAT_ON,
				RADIO_ON_CAT_OFF
			};


			class TX_SET
			{
			public:
				static std::string Set(TXSetValue value);
				static std::string Read();
				static TXSetValue Answer(std::string data);
			};

			class MIC_UP
			{
			public:
				static std::string Set();
			};

			enum class VoxDealyTimeValue : int
			{
				msec_30,
				msec_50,
				msec_100,
				msec_150,
				msec_200,
				msec_250,
				msec_300,
				msec_310,
				msec_320,
				msec_330,
				msec_340,
				msec_350,
				msec_360,
				msec_370,
				msec_380,
				msec_390,
				msec_400,
				msec_410,
				msec_420,
				msec_430,
				msec_440,
				msec_450,
				msec_460,
				msec_470,
				msec_480,
				msec_490,
				msec_500,
				msec_510,
				msec_520,
				msec_530,
				msec_540,
				msec_550,
				msec_560,
				msec_570,
				msec_580,
				msec_590,
				msec_600,
				msec_610,
				msec_620,
				msec_630,
				msec_640,
				msec_650,
				msec_660,
				msec_670,
				msec_680,
				msec_690,
				msec_700,
				msec_710,
				msec_720,
				msec_730,
				msec_740,
				msec_750,
				msec_760,
				msec_770,
				msec_780,
				msec_790,
				msec_800,
				msec_810,
				msec_820,
				msec_830,
				msec_840,
				msec_850,
				msec_860,
				msec_870,
				msec_880,
				msec_890,
				msec_900,
				msec_910,
				msec_920,
				msec_930,
				msec_940,
				msec_950,
				msec_960,
				msec_970,
				msec_980,
				msec_990,
				msec_1000,
				msec_1010,
				msec_1020,
				msec_1030,
				msec_1040,
				msec_1050,
				msec_1060,
				msec_1070,
				msec_1080,
				msec_1090,
				msec_1100,
				msec_1110,
				msec_1120,
				msec_1130,
				msec_1140,
				msec_1150,
				msec_1160,
				msec_1170,
				msec_1180,
				msec_1190,
				msec_1200,
				msec_1210,
				msec_1220,
				msec_1230,
				msec_1240,
				msec_1250,
				msec_1260,
				msec_1270,
				msec_1280,
				msec_1290,
				msec_1300,
				msec_1310,
				msec_1320,
				msec_1330,
				msec_1340,
				msec_1350,
				msec_1360,
				msec_1370,
				msec_1380,
				msec_1390,
				msec_1400,
				msec_1410,
				msec_1420,
				msec_1430,
				msec_1440,
				msec_1450,
				msec_1460,
				msec_1470,
				msec_1480,
				msec_1490,
				msec_1500,
				msec_1510,
				msec_1520,
				msec_1530,
				msec_1540,
				msec_1550,
				msec_1560,
				msec_1570,
				msec_1580,
				msec_1590,
				msec_1600,
				msec_1610,
				msec_1620,
				msec_1630,
				msec_1640,
				msec_1650,
				msec_1660,
				msec_1670,
				msec_1680,
				msec_1690,
				msec_1700,
				msec_1710,
				msec_1720,
				msec_1730,
				msec_1740,
				msec_1750,
				msec_1760,
				msec_1770,
				msec_1780,
				msec_1790,
				msec_1800,
				msec_1810,
				msec_1820,
				msec_1830,
				msec_1840,
				msec_1850,
				msec_1860,
				msec_1870,
				msec_1880,
				msec_1890,
				msec_1900,
				msec_1910,
				msec_1920,
				msec_1930,
				msec_1940,
				msec_1950,
				msec_1960,
				msec_1970,
				msec_1980,
				msec_1990,
				msec_2000,
				msec_2010,
				msec_2020,
				msec_2030,
				msec_2040,
				msec_2050,
				msec_2060,
				msec_2070,
				msec_2080,
				msec_2090,
				msec_2100,
				msec_2110,
				msec_2120,
				msec_2130,
				msec_2140,
				msec_2150,
				msec_2160,
				msec_2170,
				msec_2180,
				msec_2190,
				msec_2200,
				msec_2210,
				msec_2220,
				msec_2230,
				msec_2240,
				msec_2250,
				msec_2260,
				msec_2270,
				msec_2280,
				msec_2290,
				msec_2300,
				msec_2310,
				msec_2320,
				msec_2330,
				msec_2340,
				msec_2350,
				msec_2360,
				msec_2370,
				msec_2380,
				msec_2390,
				msec_2400,
				msec_2410,
				msec_2420,
				msec_2430,
				msec_2440,
				msec_2450,
				msec_2460,
				msec_2470,
				msec_2480,
				msec_2490,
				msec_2500,
				msec_2510,
				msec_2520,
				msec_2530,
				msec_2540,
				msec_2550,
				msec_2560,
				msec_2570,
				msec_2580,
				msec_2590,
				msec_2600,
				msec_2610,
				msec_2620,
				msec_2630,
				msec_2640,
				msec_2650,
				msec_2660,
				msec_2670,
				msec_2680,
				msec_2690,
				msec_2700,
				msec_2710,
				msec_2720,
				msec_2730,
				msec_2740,
				msec_2750,
				msec_2760,
				msec_2770,
				msec_2780,
				msec_2790,
				msec_2800,
				msec_2810,
				msec_2820,
				msec_2830,
				msec_2840,
				msec_2850,
				msec_2860,
				msec_2870,
				msec_2880,
				msec_2890,
				msec_2900,
				msec_2910,
				msec_2920,
				msec_2930,
				msec_2940,
				msec_2950,
				msec_2960,
				msec_2970,
				msec_2980,
				msec_2990,
				msec_3000
			};


			class VOX_DELAY_TIME
			{
			public:
				static std::string Set(VoxDealyTimeValue value);
				static std::string Read();
				static VoxDealyTimeValue Answer(std::string data);
			};

			enum class FirmwareVersionType : int
			{
				MAIN_CPU,
				DISPLAY_CPU,
				SDR,
				DSP
			};

			struct FirmwareVersionParam
			{
				FirmwareVersionType type;
				int MajorValue;
				int MinorValue;
			};

			class FIRMWARE_VERSION
			{
			public:

				static std::string Read(FirmwareVersionType type);
				static FirmwareVersionParam Answer(std::string data);
			};


			class VOX_GAIN
			{
			public:
				static std::string Set(int value);
				static std::string Read();
				static int Answer(std::string data);
			};


			class VFO_MEMORY_CHANNEL
			{
			public:
				static std::string Set();
			};

			enum class BandVFOValue : int
			{
				MAIN_BAND_VFO_A,
				MAIN_BAND_VFO_B
			};


			class VFO_SELECT
			{
			public:
				static std::string Set(BandVFOValue value);
				static std::string Read();
				static BandVFOValue Answer(std::string data);
			};


			class VOX_STATUS
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class TX_CLAR
			{
			public:
				static std::string Set(OnOffValue value);
				static std::string Read();
				static OnOffValue Answer(std::string data);
			};


			class ZERO_IN
			{
			public:
				static std::string Set();
			};
		}

	};	   // end Commands
};		   // end Yeasu

#endif //CAT_H