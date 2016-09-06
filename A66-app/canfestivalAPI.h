#ifndef __CANFESTIVALAPI__
#define __CANFESTIVALAPI__
#include "applicfg.h"

#define MAX_MOTOR_NUM 4
//传输标志

#define SUCCESS_SEND  0x03
#define FAIL_SEND     0x02
#define RUN_SEND      0x01
#define NO_SEND     0x00
#define WAIT_FREE_SEND 0x04
typedef enum enum_status {
    SDO_free                     =0x00,
    SDO_ConfigureSlaveNode_check		= 0x01,
    SDO_Set_postion_speed_check	    = 0x02,
    SDO_Write_One_check                       = 0x03,
    SDO_Write_Multi_check                       = 0x04,
     SDO_Read_One_check                        = 0x05,
    SDO_Read_Multi_check                        =0x06

} motor_sdo_status;


typedef struct {
    UNS8 motorId;

    UNS8 initStatus;
    UNS8  Set_motor_step;
    UNS8  isSendSDOBusy;
    UNS8 initStep;
    UNS8  Write_multi_step;
    UNS8  Read_multi_step;
    motor_sdo_status  SDO_status; //sdo

/******读取所需*****/
    UNS8  RX_buf[4]; //回调的时候读取buf
    UNS32 RX_size;  // 接受到数据的大小
    UNS32 RX_DATA[11]; // 合并buf中的数据
    UNS8  RX_state ;

/***写入多个数数据标志***/
    UNS8 Wrte_Multi_Finsh_state;
    UNS8 Write_One_Finsh_state;
    UNS8 Read_one_state;

    UNS8 Read_Multi_Finsh_state;

/*****错误标志****/
    UNS8 HeartbeatError;
    UNS32 SendCountError;
    UNS32 ReadCountError;




} S_motor;
typedef struct {

    UNS16 Index;
    UNS8  Subindex;
    UNS8  Count;
    UNS32 Data;
} S_Data;
typedef struct {
    UNS8  Cmd_num;
    S_Data data[10];
} S_Data_trans;

/***********statusWord**************/
#define STATUS_MASK            0x6f
#define Not_ready_to_switch_on 0x00
#define SWITCH_ON_DISABLED     0x40
#define Ready_to_switch_on     0x21
#define Swiched_on             0x23
#define Operation_enabled      0x27
#define Quick_stop_active      0x07
#define Fault_reaction_active  0x0f
#define Fault                  0x08

/***********controlWord**************/
#define CONTROL_MASK           0x8f
#define SHUT_DOWN              0x06
#define SWITCH_ON              0x07
#define ENABLE_OPERATION_SWITCH_ON 0x0f
#define DISABLE_VOLTAGE        0x00
#define QUICK_STOP             0x02
#define DISABLE_OPERATION
#define ENABLE_OPERATION
#define FAULT_RESET

#define CONTROL_INDEX 0x6040
#define STATUS_INDEX  0x6041

#define MODES_OF_OPERATION 0x6060

#define TARGET_POSITON     0x607A
#define PROFILE_VELOCITY   0x6081
extern S_motor motor[MAX_MOTOR_NUM];
extern S_Data_trans Write_Multi_buf;
extern S_Data_trans set_Postion_Speed_buf[4];
extern S_Data_trans Config_valve_buf;
extern S_Data_trans Adjust_ManualDate;
extern S_Data_trans SystemSet_Motor;
extern S_Data_trans HomingModeDate[3];
extern S_Data_trans SystemSet_MT;
extern int ManualDat;

long Get_MOTOR_Demand_Postion(UNS8 motor_id);

UNS16 Get_MOTOR_StatusWord(UNS8 motor_id);


void Init_MOTOR(void);
void read_One_Data(UNS8 nodeId, UNS16 Index,UNS8 Subindex);
UNS8 Read_MOTOR_MSG(UNS8 nodeId);

UNS8 Set_Motor_Speed_Postion_Rel(UNS8 nodeId,UNS32 speed,UNS32 postion);
UNS8 Set_Motor_Speed_Postion_Abs(UNS8 nodeId,UNS32 speed,UNS32 postion);
UNS8 Stop_MOTOR(UNS8 nodeId);

UNS8 Write_MOTOR_One_Data(UNS8 nodeId, UNS16 Index,UNS8 Subindex,UNS8 count,UNS8 data);

UNS8 Write_MOTOR_Multi_Data(S_Data_trans *buf,UNS8 nodeId);
UNS8 Read_MOTOR_Multi_Data(S_Data_trans *buf,UNS8 nodeId);
#endif


