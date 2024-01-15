#define RADIO_HOPE_RFM69_H_
#define TRIS_SDI1   TRIS_SDI_RF
#define RPIN_SDI1   RPIN_SDI_RF
#define TRIS_SDO1   TRIS_SDO_RF
#define RPOUT_SDO1  RPOUT_SDO_RF
#define TRIS_CSB1   TRIS_SEL_RF
#define RPOUT_CSB1  RPOUT_SEL_RF
#define RFXNCS      SEL_RF
#define TRIS_RFXNCS TRIS_SEL_RF
#define PIN_RFXNCS  PIN_SEL_RF
#define LAT_RFXNCS  LAT_SEL_RF
#define TRIS_SCX1   TRIS_SCLK_RF
#define RPOUT_SCX1  RPOUT_SCLK_RF
#define TRIS_RFXReset TRIS_RESET_RF
#define RFXReset  RESET_RF
#define PIN_RFXReset PIN_RESET_RF
#define LAT_RFXReset LAT_RESET_RF
#define TRIS_RFXIRQ TRIS_IRQ_RF
#define RFXNIRQ   IRQ_RF
#define PIN_RFXNIRQ PIN_IRQ_RF
#define RegFifo         0x00
#define RegOpMode        0x01 // SequencerOff:0|ListenOn:0|ListenAbort:0|Mode:01|unused:00
#define SecuencerOff       0x80
#define ListenOn          0x40
#define ListenAbort        0x20
#define ModeSLEEP          0x00
#define ModeSTDBY          0x04
#define ModeFS           0x08
#define ModeTX           0x0C
#define ModeRX           0x10
#define RegDataModul     0x02
#define RegBitrateMsb     0x03
#define RegBitrateLsb     0x04
#define RegFdevMsb      0x05
#define RegFdevLsb      0x06
#define RegFrfMsb        0x07
#define RegFrfMid        0x08
#define RegFrfLsb        0x09
#define RegOsc1         0x0A
#define RegAfcCtrl      0X0B
#define Reserved0C      0X0C
#define RegListen1      0x0D //ListenResolIdle:10|ListenResolRx:00|ListenCriteria:0|ListenEnd:01|UnUsed:0
#define RegListen2      0x0E // Duration of the Idle phase in Listen mode:0xF5
#define RegListen3      0x0F // Duration of the Rx phase in Listen mode  :0x20
#define RegVersion      0x10 // Version code of the chip. Bits 7-4 give the full revision number; bits 3-0 give the metal mask revision number
#define RegPaLevel      0X11
#define RegPaRamp        0X12
#define RegOcp         0X13
#define Reserved14      0X14
#define Reserved15      0X15
#define Reserved16      0X16
#define Reserved17      0X17
#define RegLna         0X18
#define RegRxBw         0X19
#define RegAfcBw        0X1A
#define RegOokPeak      0x1B
#define RegOokAvg        0X1C
#define RegOokFix        0X1D
#define RegAfcFei        0X1E
#define RegAfcMsb        0X1F
#define RegAfcLsb        0X20
#define RegFeiMsb        0X21
#define RegFeiLsb        0X22
#define RegRssiConfig     0X23
#define RegRssiValue     0X24
#define RegDioMapping1   0X25
#define RegDioMapping2   0X26
#define RegIrqFlags1     0X27
#define RegIrqFlags2     0X28
#define RegRssiThresh     0x29
#define RegRxTimeout1     0X2A // Timeout duration between Rx request and RSSI detection
#define RegRxTimeout2     0X2B // Timeout duration between RSSI detection and PayloadReady
#define RegPreambleMsb   0x2C // Preamble length, MSB
#define RegPreambleLsb   0x2D // Preamble length, LSB
#define RegSyncConfig     0X2E
#define RegSyncValue1     0X2F
#define RegSyncValue2     0X30
#define RegSyncValue3     0X31
#define RegSyncValue4     0X32
#define RegSyncValue5     0X33
#define RegSyncValue6     0X34
#define RegSyncValue7     0X35
#define RegSyncValue8     0X36
#define RegPacketConfig1  0X37
#define RegPayloadLength  0X38
#define RegNodeAdrs      0X39
#define RegBroadcastAdrs  0X3A
#define RegAutoModes     0X3B
#define RegFifoThresh     0X3C
#define RegPacketConfig2  0X3D
#define RegAesKey1      0X3E
#define RegTemp1        0X4E
#define RegTemp2        0X4F
#define RegTestLna      0X58
#define RegTestPa1      0X5A
#define RegTestPa2      0x5C
#define RegTestDagc      0x6F
#define RadioFreqBuf_Addr 1
#define RadioRateBuf_Addr 3
#define maxMsgLength 50
const uint16_t RFM69HFreqTbl[4][3] =
{
  {0x074e, 0x08c0, 0x0900}, //315MHz
  {0x076c, 0x0880, 0x0900}, //434MHz
  {0x07d9, 0x0800, 0x0900}, //868MHz
  {0x07e4, 0x08c0, 0x0900}  //915MHz
};
const uint16_t RFM69HRateTbl[4][2] =
{
  {0x0368, 0x042B},         //BR=1.2K BW=83.333K
  {0x0334, 0x0415},         //BR=2.4K BW=83.333K
  {0x031A, 0x040B},         //BR=4.8K BW=83.333K
  {0x030D, 0x0405}          //BR=9.6K BW=83.333K
};
const uint16_t RFM69HPowerTbl[4] =
{
  0x117F,                   //20dbm
  0x117C,                   //17dbm
  0x1179,                   //14dbm
  0x1176                    //11dbm
};
const uint16_t RFM69HConfigTbl[23] =
{
  0x0200,                   //RegDataModul, FSK Packet
  0x0502,                   //RegFdevMsb, 241*61Hz = 35KHz
  0x0641,                   //RegFdevLsb
  0x1952,                   //RegRxBw , RxBW, 83KHz
  0x2980,          			    // RssiThreshold -64
  0x2C00,                   //RegPreambleMsb
  0x2D05,                   //RegPreambleLsb, 5Byte Preamble
  0x2E90,                   //enable Sync.Word, 0+1=1bytes
  0x2FAA,                   //0xAA, SyncWord = aa
  0x302D,                   //0x2D
  0x31D4,                   //0xD4
  0x32BB,                   //0xBB
  0x33CC,                   //0xCC
  0x34DD,                   //0xDD
  0x35EE,                   //0xEE
  0x36FF,                   //0xFF
  0x3794,					          //Variable length CRC ON address y broadcast filtering
  0x3800 + maxMsgLength + 3,//bytes + 1 address rx + addtx +ack
  0x3C8F,                   //RegFiFoThresh
  0x1888,                   //RegLNA, 200R
  0x582D,                   //RegTestLna, increase sensitivity with LNA (Note: consumption also increase!)
  0x6F30,                   //RegTestDAGC, Improved DAGC
  0x0104                    //Enter standby mode
};
const uint16_t RFM69HRxTbl[7] =
{
  0x119F,                   //PA0 enable
  0x2571,		   				      //DIO3-RSSI
  0x2677,                   //DIO Mapping for Rx DIO4-RSSI DIO5-ModeReady
  0x1310,                   //OCP enabled
  0x5A55,                   //Normal and Rx
  0x5C70,                   //Normal and Rx
  0x0110                    //Enter Rx mode
};
const uint16_t RFM69HTxTbl[6] =
{
  0x2500,                   //DIO Mapping for Tx
  0x2677,                   //DIO Mapping for Tx DIO5-ModeReady
  0x130F,                   //Disable OCP
  0x5A5D,                   //High power mode
  0x5C7C,                   //High power mode
  0x010C                    //Enter Tx mode
};
const uint16_t RFM69ListenTable[5] = {
  0x0DE0,                   // Idle resolution 262mS,Rx resolution time 4.1ms sin sync
  0x0E10,                   //Idle time 2620ms																								XXXXX
  0x0F01,                   //Rx time 4,1ms																										XXXXX
  0x2A10,                   //|
  0x2B10                    //| total Rx time 105mS
};
union Radio_Status_U
{
	uint16_t w;
	uint8_t b[2];
};
uint16_t Radio_getStatus(void);
#define RFM69_ModeReady  0x8000
#define RFM69_RxReady  0x4000
#define RFM69_TxReady  0x2000
#define RFM69_PllLock  0x1000
#define RFM69_RssiThres  0x0800
#define RFM69_TimeOut  0x0400
#define RFM69_AutoMode  0x0200
#define RFM69_SyncAddrMatch 0x0100
#define RFM69_FifoFull  0x0080
#define RFM69_FifoNotEmpty 0x0040
#define RFM69_FifoLevel  0x0020
#define RFM69_FifoOverrun 0x0010
#define RFM69_PacketSent 0x0008
#define RFM69_PayloadReady 0x0004
#define RFM69_CrcOk   0x0002
#define Radio_isModeReady(status)   ((status & RFM69_ModeReady   ) == RFM69_ModeReady  )
#define Radio_isRxReady(status)   ((status & RFM69_RxReady  ) == RFM69_RxReady   )
#define Radio_isTxReady(status)   ((status & RFM69_TxReady  ) == RFM69_TxReady   )
#define Radio_isPllLock(status)   ((status & RFM69_PllLock   ) == RFM69_PllLock   )
#define Radio_isRssiThres(status)   ((status & RFM69_RssiThres   ) == RFM69_RssiThres  )
#define Radio_isTimeOut(status)   ((status & RFM69_TimeOut   ) == RFM69_TimeOut   )
#define Radio_isAutoMode(status)   ((status & RFM69_AutoMode   ) == RFM69_AutoMode  )
#define Radio_isSyncAddrMatch(status)  ((status & RFM69_SyncAddrMatch  ) == RFM69_SyncAddrMatch)
#define Radio_isFifoFull(status)   ((status & RFM69_FifoFull  ) == RFM69_FifoFull  )
#define Radio_isFifoNotEmpty(status)  ((status & RFM69_FifoNotEmpty ) == RFM69_FifoNotEmpty )
#define Radio_isFifoLevel(status)   ((status & RFM69_FifoLevel  ) == RFM69_FifoLevel )
#define Radio_isFifoOverrun(status)  ((status & RFM69_FifoOverrun ) == RFM69_FifoOverrun )
#define Radio_isPacketSent(status)   ((status & RFM69_PacketSent  ) == RFM69_PacketSent )
#define Radio_isPayloadReady(status)  ((status & RFM69_PayloadReady ) == RFM69_PayloadReady )
#define Radio_isCrcOk(status)    ((status & RFM69_CrcOk   ) == RFM69_CrcOk  )
void Radio_Encrypt(uint8_t* ptrClave);
void Radio_Config();
void Radio_EntryStandby(void);
void Radio_EntryRx(void);
void Radio_EntryTx(void);
void Radio_ClearFIFO(void);
void Radio_Sleep(void);
void Radio_Standby(void);
uint8_t Radio_Read(uint8_t* buffer);
void Radio_Transmit(uint8_t* buffer, uint8_t length);
void Radio_spiBurstWrite(uint8_t addr, uint8_t *ptr, uint8_t length);
void Radio_spiBurstRead(uint8_t addr, uint8_t *ptr, uint8_t length);
uint8_t Radio_spiReadCMD(uint8_t addr);
void Radio_spiWriteCMD(uint8_t addr, uint8_t data);
uint8_t Radio_spiWriteRead(uint8_t byte);
void RF_Init();
