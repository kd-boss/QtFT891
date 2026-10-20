#include "QtFT891.h"
#include <QLineEdit>
#include <QDial>
#include <QSpinBox>

void QtFT891::CreateConnections()
{
	//Serial Port
	connect(m_radio, &QSerialPort::readyRead, this, &QtFT891::OnRadioRead);
	connect(m_radio, &QSerialPort::aboutToClose, this, &QtFT891::OnPortClosing);
	

	connect(ui.cbAmDialStep, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMDailStepActivated);
	connect(ui.cbAmChStep, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMChStepActivated);

	//AM TAB START
	connect(ui.cbAMMicSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMMicSelectActivated);
	connect(ui.cbAMPTT, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMPTTActivated);
	connect(ui.cbAMHCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMHCutSlopeActivated);
	connect(ui.cbAMLCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAMLCutSlopeActivated);
	//AM TAB END

	//Combo Boxes
	connect(ui.cbMicLow, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbMicLowActivated);
	connect(ui.cbMicMid, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbMicMidActivated);
	connect(ui.cbMicHigh, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbMicHighActivated);
	connect(ui.cbProcLow, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbProcLowActivated);
	connect(ui.cbProcMid, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbProcMidActivated);
	connect(ui.cbProcHigh, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbProcHighActivated);
	connect(ui.cbScopeSpan, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbScopeSpanActivated);
	connect(ui.cbSpectrumScopeStartCycle, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbcbSpectrumScopeStartCycleActivated);

	connect(ui.cbMode, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbModeActivated);
	connect(ui.cbBand, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbBandActivated);
	connect(ui.cbWidth, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbWidthActivated);
	connect(ui.cbAGCFunc, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAGCFuncActivated);
	connect(ui.cbAPO, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbAPOActivated);
	connect(ui.cbPeakHold, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPeakHoldActivated);

	connect(ui.cbCWAutoMode, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWAutoModeActivated);
	connect(ui.cbCWBFO, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWBFOActivated);
	connect(ui.cbCWBkInType, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWBkInTypeActivated);
	connect(ui.cbWaveShape, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbWaveShapeActivated);
	connect(ui.cbCWFreqDisplay, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWFreqDisplayActivated);
	connect(ui.cbCWPCKeying, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWPCKeyingActivated);
	connect(ui.cbCWQSKDelayTime, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWQSKDelayTimeActivated);
	connect(ui.cbCWLCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWLCutSlopeActivated);
	connect(ui.cbCWHCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCWHCutSlopeActivated);
	connect(ui.cbNumberFormat, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbNumberFormatActivated);
	connect(ui.cbDATALCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATALCutSlopeActivated);
	connect(ui.cbDATAHCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATAHCutSlopeActivated);
	connect(ui.cbDataMode, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATAModeActivated);
	connect(ui.cbPskTone, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPSKToneActivated);
	connect(ui.cbDataInSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATAInSelectActivated);
	connect(ui.cbDataPTT, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATAPTTSelectActivated);
	connect(ui.cbDataBFO, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDATABFOActivated);
	connect(ui.cbMeterType, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbMeterTypeActivated);
	connect(ui.cbRepeaterOffset, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRepeaterOffsetActivated);
	connect(ui.cbDCSCode, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDCSCodeActivated);
	connect(ui.cbCTCSSTone, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCTCSSToneActivated);
	connect(ui.cbPktPttSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPktPttSelectActivated);
	connect(ui.cbFMMicSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbFMMicSelectActivated);
	connect(ui.cbDCSPolarity, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbDCSPolarityActivated);
	connect(ui.cbRTTYBfo, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYBfoActivated);
	connect(ui.cbRTTYHCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYHCutSlopeActivated);
	connect(ui.cbRTTYLCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYLCutSlopeActivated);
	connect(ui.cbRTTYShiftFeq, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYShiftFreqActivated);
	connect(ui.cbPolarityR, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPolarityRActivated);
	connect(ui.cbPolarityT, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPolarityTActivated);
	connect(ui.cbRTTYMarkFreq, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYMarkFreqActivated);
	connect(ui.cbRTTYShiftPort, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRTTYShiftPortActivated);
	connect(ui.cbSSBBfo, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBBfoActivated);
	connect(ui.cbSSBHCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBHCutSlopeActivated);
	connect(ui.cbSSBLCutSlope, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBLCutSlopeActivated);
	connect(ui.cbSSBMicSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBMicSelectActivated);
	connect(ui.cbSSBPTTSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBPTTSelectActivated);
	connect(ui.cbSSBTxBPF, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbSSBTxBPFActivated);
	connect(ui.cbTunerSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbTunerSelectActivated);
	connect(ui.cbVoxSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbVoxSelectActivated);
	connect(ui.cbApfWidth, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbApfWidthActivated);
	
	
	connect(ui.cbCATTOT, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbCATTOTActivated);
	connect(ui.cbRFSQLvr, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbRFSQLvActivated);
	connect(ui.cbNBWidth, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbNBWidthActivated);
	connect(ui.cbNBRejection, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbNBRejectionActivated);
	connect(ui.cbPopupMenu, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbPoupMenuActivated);
	connect(ui.cbClarSelect, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &QtFT891::on_cbClarSelectActivated);

	connect(ui.sbContestNumber,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbContestNumber_valueChanged);	
	connect(ui.spbxKeySpeed, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_spbxKeySpeed_valueChanged);
	connect(ui.sbDataVoxDelay, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_spDataVoxDelayValueChanged);
	connect(ui.sbOtherDISP, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbOtherDISP_valueChanged);
	connect(ui.sbOtherShift, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbOtherSHIFTValueChanged);
	connect(ui.sbBeconInterval, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbBeconInterval_valueChanged);
	connect(ui.sbRefReqAdj, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbRefReqAdj_valueChanged);
	connect(ui.sbVoxDelay, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbVoxDelay_valueChanged);
	connect(ui.sbVoxDelay, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &QtFT891::on_sbVoxDelay_valueChanged);
	connect(ui.dial_Clarifier, &QDial::valueChanged, this, &QtFT891::on_dial_Clarifier_valueChanged);
	connect(ui.tabWidget, &QTabWidget::tabBarClicked, this, &QtFT891::on_uitabClicked);
	connect(ui.dial_VFOA, &QDial::valueChanged, this, &QtFT891::on_dial_VFOA_valueChanged);
	connect(ui.dial_VFOB, &QDial::valueChanged, this, &QtFT891::on_dial_VFOB_valueChanged);
	connect(&m_timer, &QTimer::timeout, this, &QtFT891::on_timerTimeout);
}