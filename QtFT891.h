#pragma once

#define QT_AUTO_SCREEN_SCALE_FACTOR TRUE
#include <QtWidgets/QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDialog>
#include <QSlider>
#include <QComboBox>
#include <QPointer>
#include <QMessageBox>
#include <QTimer>
#include "sqlite3.h"
#include "ui_QtFT891.h"
#include "ui_PortSettings.h"
#include "ManualNotchUI.h"
#include "MemoryChannelEditorUI.h"
#include "Contour.h"
#include "Cat.h"
#include <mutex>
#include <vector>
#include "resource.h"


class PortSettings;

class QtFT891 : public QMainWindow
{
    Q_OBJECT


public:
    QtFT891(QWidget *parent = nullptr);
    ~QtFT891();
  
   
    
   
    void UpdateContourRecord();
private:
    Ui::QtFT891Class ui;
    QSerialPort* m_radio;
    sqlite3* db;
    std::string m_buffer;
    QColor defaultbg;
    QGraphicsRectItem* rectMeter;
    QPen* smeter_pen;
    QPen* white_pen;
    QBrush* smeter_brush;
    QBrush* white;
    QRectF m_georect;
    QTimer m_timer;
    QRectF meter;
    QString buttonStyle = "";
    MemoryChannelEditorUI* m_editor = nullptr;
    void ReadPowerSwitch();
    void PowerOn();
    void PowerOff();
    void Init();
    void SetBand();
    void CalculateMode(Yaesu::Commands::FT891::ModeValue v);
    void CalculateWidth(Yaesu::Commands::FT891::WidthValue wv);
    bool BandModeRecordExists(int = -1, int = -1);
    void UpdateBandModeRecord(int = -1, int = -1);
    void CreateBandModeRecord(int = -1, int = -1);
    void UpdateFromBandModeRecord(int = -1, int = -1);
    
    bool UpdateFromContourRecord();
    void LoadPowerTab();
    void LoadMiscTab();
 
    void LoadTXEqTab();
    void LoadAMTab();
    void LoadContestingTab();
    void LoadCWTab();
    void LoadDataTab();
    void LoadVoxTab();
    void LoadFMTab();
	void LoadRTTYTab();
	void LoadSSBTab();
    void LoadFirmware();
    void CreateConnections();
    void StartDatabase();
    void UpdatePortSettings(QString Port, int BaudRate);
    Yaesu::Commands::FT891::BfoValue m_ssbbfo;
    Yaesu::Commands::FT891::BfoValue m_cwbfo;
    Yaesu::Commands::FT891::DataBfoValue m_databfo;
    Yaesu::Commands::FT891::DataBfoValue m_rttybfo;
    Yaesu::Commands::FT891::NarrowValue NarrowState;
    Yaesu::Commands::FT891::MeterType m_meterType;
    Yaesu::Commands::FT891::InformationState m_autoInfoState = Yaesu::Commands::FT891::InformationState::OFF;
    unsigned int VFOAFreq;
    unsigned int VFOBFreq;
    unsigned int VFOBPrevFreq;
    unsigned int WidthOffset;
    int dnr_enabled;
    int wdefault;
    int currentWidth;
    int currentMode = -1;
    int currentBand;
    int contour_enabled = 0;
    int contour_freq = 0;
    int contour_level = 0;
    int contour_width = 0;
    int dialA = 0; 
    int dialB = 0;
    float previousPercent = 0.0f;
    bool m_readingMemoryChannels = false;
    int m_channel = 1;
    QList<QString> widthValues;
    Yaesu::Commands::FT891::MemoryChannelModeValue currentMemoryMode;
    std::mutex m_sql;
    bool cbbandChanged = false;
    bool bandChanged;
    bool receivedInformation;
    bool widthClicked;
    bool modeChanged;
    bool powertabloaded;
    bool misctabloaded;
    bool txeqtabloaded = false;
    bool amtabloaded = false;
    bool contestingtabloaded = false;
    bool cwtabloaded = false;
    bool fromraadio = false;
    bool datatabloaded = false;
    bool fmtabloaded = false;
    bool rttytabloaded = false;
    bool ssbtabloaded = false;
    bool voxloaded = false;
    bool InformationReceived;
    bool m_transmitting;
    bool monitoron = false;
    bool loadingEQ = false;
    bool loadingMisc = false;
    bool loadingInit = false;
    bool loadingfromdb = false;
    bool readingPower = false;
    bool poweringup = false;
    std::vector<std::string> hist;    
    std::string prevcmd;
    ManualNotchUI* mui = nullptr;
    ContourUI* cui = nullptr;

    int m_ClarifierOffset = 0;
    Yaesu::Commands::FT891::ClarifierState m_ClarifierState = Yaesu::Commands::FT891::ClarifierState::OFF;
    Yaesu::Commands::FT891::IFNotchWidth m_notchWidth;
    std::vector<Yaesu::Commands::FT891::MemoryChannelTagValue> m_channels;
private slots:
    void on_MemoryEditor_destroyed(QObject* obj);
    void on_ckMox_stateChanged(int val);
    void on_ckAPF_stateChanged(int val);
    void on_ContourFrequency_valueChanged(int val);
	void on_ContourLevel_valueChanged(int val);
	void on_ContourWidth_valueChanged(int val);
    void on_btnQSPL_clicked();
    void on_btnSPL_clicked();
    void on_timerTimeout();
    Yaesu::Commands::FT891::CommandType CommandType(const std::string& cmdtype);
    void ProcessCommmand(std::string cmd);
    void OnRadioRead();
	void on_Volume_valueChanged(int val);
	void on_RFGain_valueChanged(int val);
	void on_Squelch_valueChanged(int val);
	void OnMicGainChanged(int val);
	void on_MON_valueChanged(int val);
	void on_DNR_valueChanged(int val);
	void on_NBLvl_valueChanged(int val);
	void on_VoxLevel_valueChanged(int val);
	void on_sbVoxDelay_valueChanged(int val);
    void on_cbVoxSelectActivated(int val);  
    void on_btnSwapVandM_clicked();
    void on_btnMemEdit_clicked();
    void on_btnNotch_clicked();
    void on_cbApfWidthActivated(int val);
    void on_cbClarSelectActivated(int val);
	void on_sbRefReqAdj_valueChanged(int val);
    void on_sbQuickSplit_valueChanged(int val);
    void on_cbMicScanResumeActivated(int val);
	void on_sbBeconInterval_valueChanged(int val);
    void on_AntiVox_valueChanged(int val);
    void on_cbModeActivated(int val);

    void on_cbScopeSpanActivated(int val);
    void on_cbcbSpectrumScopeStartCycleActivated(int val);

    void on_ckClarEnabled_stateChanged(int val);
    void on_ckIFShift_stateChanged(int val);
    void on_cbWidthActivated(int val);
    void on_cbBandActivated(int val);
    void on_lvlHFSSBPower_valueChanged(int val);
    void on_lvlHFAMPower_valueChanged(int val);
    void on_lvlHFPower_valueChanged(int val);
	void on_lvlVHFSSBPower_valueChanged(int val);
	void on_lvlVHFAMPower_valueChanged(int val);
	void on_lvlVHFPower_valueChanged(int val);
    void on_lvlAGCFast_valueChanged(int val);
    void on_lvlAPF_valueChanged(int val);
    void on_lvlAGCMid_valueChanged(int val);
    void on_lvlProcLowWidth_valueChanged(int val);
    void on_lvlProcMidWidth_valueChanged(int val);
    void on_lvlProcHighWidth_valueChanged(int val);

    void on_lvlAGCSlow_valueChanged(int val);
    void on_lvlTxBusy_valueChanged(int val);
    void on_lvlBacklight_valueChanged(int val);
    void on_lvlContrast_valueChanged(int val);
    void on_lvlLCD_valueChanged(int val);
    void on_lvlBeep_valueChanged(int val);
	void on_cbAMDailStepActivated(int val);
    void on_cbPoupMenuActivated(int val);
	void on_cbAMChStepActivated(int val);
    void on_cbTunerSelectActivated(int val);
    void on_cbCATTOTActivated(int val);
    void on_cbNBWidthActivated(int val);
    void on_cbNBRejectionActivated(int val);
    void on_lvlTxTOT_valueChanged(int val);
    void on_dial_VFOA_valueChanged(int val);
    void on_dial_VFOB_valueChanged(int val);
    void on_lvlMicLow_valueChanged(int val);
    void on_lvlMicMid_valueChanged(int val);
    void on_lvlMicHigh_valueChanged(int val);
	void on_lvlMicLowWidth_valueChanged(int val);
	void on_lvlMicMidWidth_valueChanged(int val);
	void on_lvlMicHighWidth_valueChanged(int val);
    void on_lvlProcLow_valueChanged(int val);
    void on_lvlProcMid_valueChanged(int val);
    void on_lvlProcHigh_valueChanged(int val);
    void on_hsIFShift_valueChanged(int val);
    //AM TAB START
    void on_lvlAMLCutFreq_valueChanged(int val);
	void on_lvlAMHCutFreq_valueChanged(int val);
	void on_lvlAMMicGain_valueChanged(int val);
	void on_lvlAMDataGain_valueChanged(int val);
    void on_lvlAMOutLevel_valueChanged(int val);
    void on_cbAMPTTActivated(int val);
    
	void on_cbAMMicSelectActivated(int val);
	void on_cbAMLCutSlopeActivated(int val);
	void on_cbAMHCutSlopeActivated(int val);
    void on_hsNotchLevelValueChanged(int val);
  //  void on_cbMeterType_valueChanged(int val);
    //AM TAB END
    void on_lvldvsRx_valueChanged(int val);
    void on_lvldvsTx_valueChanged(int val);
    void on_lvlCWLCutFreq_valueChanged(int val);
    void on_lvlCWHCutFreq_valueChanged(int val);
    void on_lvlCWOutLevel_valueChanged(int val);
    void on_lvlCWBKINDelay_valueChanged(int val);
    void on_lvlCWWeight_valueChanged(int val);
    //DATA TAB START
    void on_lvlDATAHCutFreq_valueChanged(int val);
    void on_lvlDATALCutFreq_valueChanged(int val);
    void on_sbOtherDISP_valueChanged(int val);
    void on_sbOtherSHIFTValueChanged(int val);
    void on_lvlDATAOut_valueChanged(int val);
    void on_cbDATAModeActivated(int val);
    void on_cbPSKToneActivated(int val);
    void on_cbDATAInSelectActivated(int val);
    void on_cbDATAPTTSelectActivated(int val);
    void on_cbDATABFOActivated(int val);
    void on_cbDATALCutSlopeActivated(int val);
    void on_cbDATAHCutSlopeActivated(int val);
    void on_lvlDataGain_valueChanged(int val);
    void on_lvlDataVoxGain_valueChanged(int val);
    void on_lvlDataAntiVoxGain_valueChanged(int val);
    void on_spDataVoxDelayValueChanged(int val);
    void on_lvlDataMicGain_valueChanged(int val);
    //DATA TAB END
    //FM TAB START
    void on_rbDCSON_toggled();
    void on_rbCTCSSENCON_toggled();
    void on_rbCTCSSENCDECON_toggled();
    void on_rbCTCSSOFF_toggled();
    void on_cbFMMicSelectActivated(int val);
    void on_cbPktPttSelectActivated(int val);
    void on_cbCTCSSToneActivated(int val);
    void on_cbDCSCodeActivated(int val);
    void on_cbRepeaterOffsetActivated(int val);
    void on_lvlFMOut_valueChanged(int val);
    void on_lvlFMMicGain_valueChanged(int val);
    void on_lvlFMDataGain_valueChanged(int val);
  
    void on_cbDCSPolarityActivated(int val);
    //FM TAB END
    //RTTY TAB START
    void on_cbMeterTypeActivated(int val);
    void on_sbContestNumber_valueChanged(int val);
    void on_dial_Clarifier_valueChanged(int val);

    void on_btnClearClarifier_clicked();
    void on_spbxKeySpeed_valueChanged(int val);
    void on_chkCWSpot_stateChanged(int val);
    void on_lvlRTTYLCutFreq_valueChanged(int val);
    void on_lvlRTTYHCutFreq_valueChanged(int val);
    void on_lvlRTTYOut_valueChanged(int val);
    void on_cbRTTYShiftPortActivated(int val);
    void on_cbPolarityRActivated(int val);
    void on_cbPolarityTActivated(int val);
    void on_cbRTTYShiftFreqActivated(int val);
    void on_cbRTTYMarkFreqActivated(int val);
    void on_cbRTTYBfoActivated(int val);
    void on_cbRTTYLCutSlopeActivated(int val);
    void on_cbRTTYHCutSlopeActivated(int val);
    void on_cbIFNotchActivated(int val);
    //RTTY TAB END
    //SSB TAB START
    void on_lvlSSBLCutFreq_valueChanged(int val);
    void on_lvlSSBHCutFreq_valueChanged(int val);
    void on_lvlSSBOut_valueChanged(int val);
    void on_lvlSSBMicGain_valueChanged(int val);
    void on_lvlSSBDataGain_valueChanged(int val);
    void on_cbSSBHCutSlopeActivated(int val);
    void on_cbSSBLCutSlopeActivated(int val);
    void on_cbSSBMicSelectActivated(int val);
    void on_cbSSBBfoActivated(int val);
    void on_cbSSBPTTSelectActivated(int val);
    void on_cbSSBTxBPFActivated(int val);
    //SSB TAB END
    void on_cbCWLCutSlopeActivated(int val);
    void on_cbCWHCutSlopeActivated(int val);
    void on_cbCWAutoModeActivated(int val);
    void on_cbCWBFOActivated(int val);
    void on_cbCWBkInTypeActivated(int val);
    void on_cbWaveShapeActivated(int val);
    void on_cbCWFreqDisplayActivated(int val);
    void on_cbCWPCKeyingActivated(int val);
    void on_cbCWQSKDelayTimeActivated(int val);
    void on_cbMicLowActivated(int val);
    void on_cbMicMidActivated(int val);
    void on_cbMicHighActivated(int val);
	void on_cbProcLowActivated(int val);
	void on_cbProcMidActivated(int val);
	void on_cbProcHighActivated(int val);
    void on_cbAGCFuncActivated(int val);
    void on_cbPeakHoldActivated(int val);
    void on_cbRFSQLvActivated(int val);
    void on_cbAPOActivated(int val);
    void on_cbNumberFormatActivated(int val);
    void on_chkbxATAS_stateChanged(int val);
    void on_chkbxFMSetting_stateChanged(int val);
    void on_chkbxMemGroup_stateChanged(int val);
    void on_chkbxRECSettings_stateChanged(int val);
    void on_chkbxZinLed_stateChanged(int val);
    void on_chkbxEmergencyFreq_stateChanged(int val);
    void on_chkbxFan_stateChanged(int val);
    void on_chkbxMicScan_stateChanged(int val);
    void on_chkbxBreakIn_stateChanged(int val);
    void on_chkbxKeyerEnable_stateChanged(int val);
    void on_chkbxCatRTS_stateChanged(int val);

    void on_uitabClicked(int val);
    void on_btnTune_clicked();
    void on_btnAtoB_clicked();
    void on_btnAtoM_clicked();
  
    void on_btnTNR_clicked();
    void on_btnVox_clicked();
    void on_btnScan_clicked();
    void on_ckTXWatch_stateChanged(int val);
    void on_btnEQ_clicked();
    void on_btnPRC_clicked();
    void on_btnMON_clicked();
    void on_btnPWR_clicked();
    void on_btnAB_clicked();
    void on_btnBtoA_clicked();
    void on_btnIPO_clicked();
    void on_btnATT_clicked();
    void on_btnNAR_clicked();
    void on_btnNB_clicked();
    void on_btnLOCK_clicked();
    void on_btnFST_clicked();
    void on_btnDNR_clicked();
    void on_btnDNF_clicked();
    void on_btnContour_clicked();
    void on_btnCh1Load_clicked();
    void on_btnCh2Load_clicked();
    void on_btnCh3Load_clicked();
    void on_btnCh4Load_clicked();
    void on_btnCh5Load_clicked();
	void on_btnCh1Play_clicked();
	void on_btnCh2Play_clicked();
	void on_btnCh3Play_clicked();
	void on_btnCh4Play_clicked();
	void on_btnCh5Play_clicked();
    void OnPortClosing();
    void on_VFO_returnPressed();
    void on_VFOB_returnPressed();
    void on_lnMemKey_1_returnPressed();
    void on_lnMemKey_2_returnPressed();
    void on_lnMemKey_3_returnPressed();
    void on_lnMemKey_4_returnPressed();
    void on_lnMemKey_5_returnPressed();
    void on_bnMkPlay_clicked();
    void on_bnMkPlay_2_clicked();
    void on_bnMkPlay_3_clicked();
    void on_bnMkPlay_4_clicked();
    void on_bnMkPlay_5_clicked();
    void on_bnZeroIn_clicked();
    void on_pbPortSettings_clicked();
    void on_btnUp_clicked();
    void on_btnDn_clicked();
    friend class ManualNotchUI;
    friend class MemoryChannelEditorUI;
};


class PortSettings : public QDialog
{
	Q_OBJECT
public:
	PortSettings(QtFT891* parent = nullptr);
	~PortSettings();
	QString getCATPort();
	int GetCatRate();
    void setCATPort(const QString& port);
    void setCatRate(const QString& rate);
private:
	Ui::PortSettingsClass ui;
    QList<QSerialPortInfo> ports;

};

