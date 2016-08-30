/* Includes ------------------------------------------------------------------*/
#include "CanopenDictConfig.h"
#include "applicfg.h"
#include "TestMaster.h"
#include "can.h"
#include "ObjDict.h"
#include "dcf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*Froward declaration*/
//#define POWER_ON sendSDO_1(d,MOTOR_1,len_16, 0x6040, 0x00,0x06);
//#define POWER_OFF sendSDO_1(d,MOTOR_1,len_16, 0x6040, 0x00,0x0f);
//#define SELECT_SPPED_MODE sendSDO_1(d,MOTOR_1,len_8,  0x6060, 0x00,0x03);

unsigned char nodeID=16;
void delay1ms(void)
    {      unsigned char a,b,c;     for(c=50;c>0;c--)  for(b=200;b>0;b--)             for(a=2;a>0;a--); }
/**
  * @brief  Master_heartbeatError.
  * @param  d:CANOpen object dictionary. heartbeatID:Node id
  * @retval None
  */
void Master_heartbeatError(CO_Data* d, UNS8 heartbeatID)
{
    motor[heartbeatID-1].initStatus = 0; //离线之后
    motor[heartbeatID-1].HeartbeatError = 1;
  //  MSG_USER(0, "Master_heartbeatError %d\n", heartbeatID);
   printf("Master_heartbeatError %d\n",heartbeatID);
}

UNS8 Get_HeartbetError(UNS8 heartbeatID)
{
     return motor[heartbeatID-1].HeartbeatError;
}
UNS8 Clean_HeartbetError(UNS8 heartbeatID)
{
    motor[heartbeatID-1].HeartbeatError = 0x00;
}
/**
  * @brief  Master_initialisation.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_initialisation(CO_Data* d)
{
//    UNS32 TPDO1_COBID = 0x0181;
//    UNS32 RPDO1_COBID = 0x0201;
//    UNS32 TPDO2_COBID = 0x0182;
//    UNS32 RPDO2_COBID = 0x0281;
//    UNS32 size =   sizeof(UNS32);
//    UNS8  unsize = sizeof(UNS8);
//    UNS8  TpdoTransmissionType = 0;

//    TpdoTransmissionType = TpdoTransmissionType;
//    MSG_USER(0, "Master_initialisation",0);

//    /*****************************************
//     * Define RPDOs to match slave ID=2 TPDOs*
//     *****************************************/
//    writeLocalDict( d, /*CO_Data* d*/
//            0x1400, /*UNS16 index*/
//            0x01, /*UNS8 subind*/
//            &RPDO1_COBID, /*void * pSourceData,*/
//            &size, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */
//    TpdoTransmissionType = TRANS_SYNC_ACYCLIC;
//    writeLocalDict( d, /*CO_Data* d*/
//            0x1400, /*UNS16 index*/
//            0x02, /*UNS8 subind*/
//            &TpdoTransmissionType, /*void * pSourceData,*/
//            (UNS32*)&unsize, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */

//    writeLocalDict( d, /*CO_Data* d*/
//            0x1401, /*UNS16 index*/
//            0x01, /*UNS8 subind*/
//            &RPDO2_COBID, /*void * pSourceData,*/
//            &size, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */
//    TpdoTransmissionType = TRANS_SYNC_ACYCLIC;
//    writeLocalDict( d, /*CO_Data* d*/
//            0x1401, /*UNS16 index*/
//            0x02, /*UNS8 subind*/
//            &TpdoTransmissionType, /*void * pSourceData,*/
//            (UNS32*)&unsize, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */

//    writeLocalDict( d, /*CO_Data* d*/
//            0x1800, /*UNS16 index*/
//            0x01, /*UNS8 subind*/
//            &TPDO1_COBID, /*void * pSourceData,*/
//            &size, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */
//    TpdoTransmissionType = TRANS_SYNC_MIN;
//    writeLocalDict( d, /*CO_Data* d*/
//            0x1800, /*UNS16 index*/
//            0x02, /*UNS8 subind*/
//            &TpdoTransmissionType, /*void * pSourceData,*/
//            (UNS32*)&unsize, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */

//    writeLocalDict( d, /*CO_Data* d*/
//            0x1801, /*UNS16 index*/
//            0x01, /*UNS8 subind*/
//            &TPDO2_COBID, /*void * pSourceData,*/
//            &size, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */
//    TpdoTransmissionType = TRANS_SYNC_MIN;
//    writeLocalDict( d, /*CO_Data* d*/
//            0x1801, /*UNS16 index*/
//            0x02, /*UNS8 subind*/
//            &TpdoTransmissionType, /*void * pSourceData,*/
//            (UNS32*)&unsize, /* UNS8 * pExpectedSize*/
//            RW);  /* UNS8 checkAccess */

}

/**
  * @brief  Master_preOperational.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_preOperational(CO_Data* d)
{
    MSG_USER(0, "Master_preOperational",0);
}
/**
  * @brief  Master_preOperational.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_operational(CO_Data* d)
{
//	UNS32 SyncTimePeriod = 1000;
//	UNS32 size = sizeof(SyncTimePeriod);subindex
//
//	writeLocalDict( d, /*CO_Data* d*/
//			0x1006, /*UNS16 index*/
//			0x00, /*UNS8 subind*/
//			&SyncTimePeriod, /*void * pSourceData,*/
//			&size, /* UNS8 * pExpectedSize*/
//			RW);  /* UNS8 checkAccess */
//	stopSYNC(d);
//	startSYNC(d);
//	setTimer(100);
////	TIM_Cmd(TIM4, ENABLE);
    MSG_USER(0x00, "--------------------------------Master_operational---------------------",0);
}
/**
  * @brief  Master_stopped.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_stopped(CO_Data* d)
{
    MSG_USER(0, "Master_stopped",0);
}

/**
  * @brief  Master_post_sync.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_post_sync(CO_Data* d)
{

//	ControlWordAxis1 = 0x0f;
//	InterpolationDataAxis1 = 100;
//
//	ControlWordAxis2 = 0x0f;
//	InterpolationDataAxis2 = 100;
    MSG_USER(0, "Master_post_sync",0);
}
/**
  * @brief  Master_post_emcy.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_post_emcy(CO_Data* d, UNS8 nodeID, UNS16 errCode, UNS8 errReg)
{
    //MSG_USER(0, "Master received EMCY message. Node: %2.2x  ErrorCode: %4.4x  ErrorRegister: %2.2x\n", nodeID, errCode, errReg);
    MSG_USER(0, "Master received EMCY message. Node: %2.2x  ErrorCode: %4.4x  ErrorRegister: %2.2x\n", nodeID);
}
/**
  * @brief  Master_post_TPDO.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void Master_post_TPDO(CO_Data* d)
{

}

/**
  * @brief  Master_post_SlaveBootup.
  * @param  d:CANOpen object dictionary.nodeId:Node id newNodeState:Slave change state
  * @retval None
  */
void Master_post_SlaveBootup(CO_Data* d, UNS8 nodeId)
{
         // ConfigureSlaveNode(d,nodeid);
    Clean_HeartbetError(nodeId);
    if(nodeId == 0x04)//mtzhuji
    {
        masterSendNMTstateChange (d, nodeId, NMT_Start_Node);
        d->NMTable[nodeId] = Operational;
    }
           ConfigureSlaveNode(d,nodeId);
      //  check_and_start_node(d,nodeid);
      //  masterSendNMTstateChange (d, nodeid, NMT_Start_Node);
        MSG_USER(0, "Master_post_SlaveBootup %d", nodeId);
}

void Master_post_SlaveStateChange(CO_Data* d, UNS8 nodeId, e_nodeState newNodeState)
{
        static UNS8 NodeIdNum = 0;
        if (newNodeState == Operational)
        {
                NodeIdNum++;
                if (NodeIdNum == MAX_CAN_BUS_ID)
                {
                        NodeIdNum = 0;
                        setState(d, Operational);
                        MSG_USER(0x0000,"ENTER MASTER_Operational",0);
                }
        }
}



/**
  * @brief  CANOpenMasterInit.
  * @param  d:CANOpen object dictionary.
  * @retval None
  */
void CANOpenMasterInit(CO_Data* d)
{
    d->heartbeatError = Master_heartbeatError;
    d->initialisation = Master_initialisation;
    d->preOperational = Master_preOperational;
    d->operational = Master_operational;
    d->stopped = Master_stopped;
    d->post_sync = Master_post_sync;
    d->post_TPDO = Master_post_TPDO;
    d->post_emcy             = Master_post_emcy;
    d->post_SlaveBootup      = Master_post_SlaveBootup;
    d->post_SlaveStateChange = Master_post_SlaveStateChange;
    Init_MOTOR();
}
/**
  * @brief  CanopenInit
  * @param  NONE
  * @retval NONECofig_MOTOR_test motor[heartbeatID-1].HeartbeatError = 1;
  */
void CanopenInit(void)
{
    UNS32 i;
//
//	initTimer();
//	CANOpenMasterObject->canHandle = CAN1;

//	setState(CANOpenMasterObject,Initialisation);
//	setNodeId (CANOpenMasterObject, 127);
     CANOpenMasterInit(&ObjDict_Data);

     setNodeId(&ObjDict_Data, nodeID);
     setState(&ObjDict_Data, Initialisation);

    for(i=0; i<65536; i++);
    for(i=0; i<65536; i++);
    for(i=0; i<65536; i++);
    for(i=0; i<65536; i++);
    for(i=0; i<65536; i++);

    setState(&ObjDict_Data, Operational);
    MSG_USER(0x00,"CanopenInit_OK!",0);
}
/******************* (C) COPYRIGHT 2015 Personal Electronics *****END OF FILE****/
