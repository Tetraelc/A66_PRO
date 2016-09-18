/* Includes ------------------------------------------------------------------*/


#include "applicfg.h"
#include "can.h"
#include "ObjDict.h"
#include "canfestivalAPI.h"

/*Froward declaration*/
#define MOTOR_1  0x00
#define MOTOR_2  0x01
#define MOTOR_3  0x02
#define MOTOR_4  0x03

#define YES_BUSY 0x01
#define NO_BUSY  0x00

#define RE_TIME   3
#define len_8    0x01
#define len_16   0x02
#define len_32   0x04
int ManualDat;


extern UNS16 StatusWordAxis1;               //电机1的工作状态
extern INTEGER32 PositionDemandValueAxis1;  //电机1的位置
extern UNS8 ObjDict_obj1280_Node_ID_of_the_SDO_Server ;
// Step counts number of times ConfigureSlaveNode is called
static UNS8 SDO_STEP(CO_Data* d,UNS8 nodeId,S_Data_trans* cmd,UNS8* Step,SDOCallback_t Callback);
static void CheckSDORead(CO_Data* d, UNS8 nodeId);
S_motor motor[MAX_MOTOR_NUM] ; //motor
S_Data_trans init_buf[8] = {{0x08,0x6040,0x00,0x02,0x06,                       //id0x01
                                  0x6040,0x00,0x02,0x0f,
                                  0x1800,0x05,0x02,0x11,//PDO时间
                                  0x1800,0x02,0x01,0xff,//触发模式
                                  0x1017,0x00,0x02,101,
                                  0x605a,0x00,0x02,0x06,
                                  0x6060,0x00,0x01,0x01,
                                  0x6093,0x01,0x04,0x0a},
                            {0x08,0x6040,0x00,0x02,0x06,
                                  0x6040,0x00,0x02,0x0f,
                                  0x1800,0x05,0x02,0x12,
                                  0x1800,0x02,0x01,0xff,//触发模式
                                  0x1017,0x00,0x02,106,
                                  0x605a,0x00,0x02,0x06,
                                  0x6060,0x00,0x01,0x01,
                                  0x6093,0x01,0x04,0x0a},
                            {0x08,0x6040,0x00,0x02,0x06,
                                  0x6040,0x00,0x02,0x0f,
                                  0x1800,0x05,0x02,0x13,
                                  0x1800,0x02,0x01,0xff,//触发模式
                                  0x1017,0x00,0x02,111,
                                  0x605a,0x00,0x02,0x06,
                                  0x6060,0x00,0x01,0x01,
                                  0x6093,0x01,0x04,0x0a},
                           };
//                                  0x607B,0x01,0x04,0xAA,// 最小限位
//                                  0x607B,0x02,0x04,0xAA,// 最大限位
S_Data_trans set_Postion_Speed_buf[4] = {{0x04,0x6040,0x00,0x02,0x0f,
                                           0x607A,0x00,0x04,0x0000, // weizhi
                                           0x6081,0x00,0x04,0x0000, //Speed
                                           0x6040,0x00,0x02,0x7f},
                                        {0x04,0x6040,0x00,0x02,0x0f,
                                           0x607A,0x00,0x04,0x0000, // weizhi
                                           0x6081,0x00,0x04,0x0000, //Speed
                                           0x6040,0x00,0x02,0x7f},
                                        {0x04,0x6040,0x00,0x02,0x0f,
                                           0x607A,0x00,0x04,0x0000, // weizhi
                                           0x6081,0x00,0x04,0x0000, //Speed
                                           0x6040,0x00,0x02,0x7f}};




S_Data_trans Write_Multi_buf       = {0x04,0x6040,0x00,0x02,0x0f,
                                           0x607A,0x00,0x04,0x100000, // weizhi
                                           0x6081,0x00,0x04,0x500, //Speed
                                           0x6040,0x00,0x02,0x7f};
S_Data_trans Home_mode_buf         = {0};

S_Data_trans Config_valve_buf      = {0x09,0x7000,0x02,0x01,0x00,
                                           0x7000,0x03,0x01,0x00,
                                           0x7000,0x04,0x01,0x00,
                                           0x7000,0x05,0x01,0x00,
                                           0x7000,0x06,0x01,0x00,
                                           0x7000,0x07,0x01,0x00,
                                           0x7000,0x08,0x02,0x00,
                                           0x7000,0x09,0x02,0x00,
                                           0x7000,0x01,0x01,0xAA
                                     };

S_Data_trans Adjust_ManualDate[3]    = {{0x05,0x6060,0x00,0x01,0x06,
                                          0x607c,0x00,0x04,0x0,
                                          0x6040,0x00,0x02,0x0f,
                                          0x6040,0x00,0x02,0x7f,
                                          0x6060,0x00,0x01,0x01,},
                                     {0x05,0x6060,0x00,0x01,0x06,
                                           0x607c,0x00,0x04,0x0,
                                           0x6040,0x00,0x02,0x0f,
                                           0x6040,0x00,0x02,0x7f,
                                           0x6060,0x00,0x01,0x01,},
                                     {0x05,0x6060,0x00,0x01,0x06,
                                           0x607c,0x00,0x04,0x0,
                                           0x6040,0x00,0x02,0x0f,
                                           0x6040,0x00,0x02,0x7f,
                                           0x6060,0x00,0x01,0x01,},

                                    };
S_Data_trans SystemSet_MT           = { 0x03,0x7000,0x08,0x02,0x00,
                                             0x7000,0x09,0x02,0x00,
                                             0x7000,0x01,0x01,0xAA,//上面是液压轴
                                       };
S_Data_trans SystemSet_Motor[3]        = { {0x09, 0x607B,0x01,0x04,0xAA,// 最小限位
                                                  0x607B,0x02,0x04,0xAA,// 最大限位
                                                  0x6093,0x01,0x04,0x0a,
                                                  0x6040,0x00,0x02,0x0f,
                                                  0x6060,0x00,0x01,0x06,
                                                  0x607c,0x00,0x04,0x0,
                                                  0x6040,0x00,0x02,0x0f,
                                                  0x6040,0x00,0x02,0x7f,
                                                  0x6060,0x00,0x01,0x01,},
                                        {0x09, 0x607B,0x01,0x04,0xAA,// 最小限位
                                               0x607B,0x02,0x04,0xAA,// 最大限位
                                               0x6093,0x01,0x04,0x0a,
                                               0x6040,0x00,0x02,0x0f,
                                               0x6060,0x00,0x01,0x06,
                                               0x607c,0x00,0x04,0x0,
                                               0x6040,0x00,0x02,0x0f,
                                               0x6040,0x00,0x02,0x7f,
                                               0x6060,0x00,0x01,0x01,},
                                        {0x09, 0x607B,0x01,0x04,0xAA,// 最小限位
                                               0x607B,0x02,0x04,0xAA,// 最大限位
                                               0x6093,0x01,0x04,0x0a,
                                               0x6040,0x00,0x02,0x0f,
                                               0x6060,0x00,0x01,0x06,
                                               0x607c,0x00,0x04,0x0,
                                               0x6040,0x00,0x02,0x0f,
                                               0x6040,0x00,0x02,0x7f,
                                               0x6060,0x00,0x01,0x01,},
                                       };
S_Data_trans HomingModeDate[3]    = {{0x07,0x6060,0x00,0x01,0x06,
                                           0x6098,0x00,0x01,0x02,//正限位开关
                                            0x607c,0x00,0x04,550,// 参考点
                                            0x6099,0x01,0x04,1000,
                                            0x6099,0x02,0x04,50,
                                            0x6040,0x00,0x02,0x0f,
                                            0x6040,0x00,0x02,0x1f,

                                           },//0x6060,0x00,0x01,0x01,
                                     {0x07,
                                           0x6060,0x00,0x01,0x06,
                                           0x6098,0x00,0x01,0x02,//正限位开关
                                            0x607c,0x00,0x04,550,// 参考点
                                            0x6099,0x01,0x04,1000,
                                      0x6099,0x02,0x04,50,
                                           0x6040,0x00,0x02,0x0f,
                                           0x6040,0x00,0x02,0x1f,

                                           },//0x6060,0x00,0x01,0x01,
                                      {0x07,
                                            0x6060,0x00,0x01,0x06,
                                           0x6098,0x00,0x01,0x02,//正限位开关
                                            0x607c,0x00,0x04,550,// 参考点
                                           0x6099,0x01,0x04,1000,
                                       0x6099,0x02,0x04,50,
                                           0x6040,0x00,0x02,0x0f,
                                           0x6040,0x00,0x02,0x1f,

                                          }, //0x6060,0x00,0x01,0x01,
                                     };
S_Data_trans ConfigTest = {0x02,0x7001,0x01,0x01,0x30, //模式为停止
                                0x7001,0x02,0x01,0x00};//写入要阀组输出的数据


/**
  * @brief  鍒濆鍖杕otor
  * @param
  * @retval
  */
void Init_MOTOR(void)
{
    motor[MOTOR_1].motorId = 0x01;
    motor[MOTOR_2].motorId = 0x02;
    motor[MOTOR_3].motorId = 0x03;
    motor[MOTOR_4].motorId = 0x04;
    motor[MOTOR_1].initStep = 0;
    motor[MOTOR_2].initStep = 0;
    motor[MOTOR_3].initStep = 0;
    motor[MOTOR_4].initStep = 0;
//    motor[MOTOR_1].initStatus = 0;
//    motor[MOTOR_2].initStatus = 0;
//    motor[MOTOR_3].initStatus = 0;
//    motor[MOTOR_4].initStatus = 0;
    motor[MOTOR_1].isSendSDOBusy = NO_BUSY;
    motor[MOTOR_2].isSendSDOBusy = NO_BUSY;
    motor[MOTOR_3].isSendSDOBusy = NO_BUSY;
    motor[MOTOR_4].isSendSDOBusy = NO_BUSY;
    motor[MOTOR_1].Set_motor_step = 0;
    motor[MOTOR_2].Set_motor_step = 0;
    motor[MOTOR_3].Set_motor_step = 0;
    motor[MOTOR_4].Set_motor_step = 0;

}
/**
  * @brief  寰楀埌motor鐘舵€?  * @param   motor id濡傛灉杈撳叆
  * @retval status
  */
UNS16 Get_MOTOR_StatusWord(UNS8 motor_id)
{
        UNS16 status = 0x00;

        status = MOTOR_STATUS[motor_id-1]; //& STATUS_MASK);
         MSG_USER(0x8000,"status:",status);
        switch(status)
        {
        case Not_ready_to_switch_on:  MSG_USER(0x8000,"1_Not_ready_to_switch_on",motor_id);  break;

        case SWITCH_ON_DISABLED:      MSG_USER(0x8000, "2_SWITCH_ON_DISABLE"    ,motor_id);  break;

        case Ready_to_switch_on:      MSG_USER(0x8000,"Ready_to_switch_on",motor_id);  break;

        case Swiched_on:              MSG_USER(0x8000,"Swiched_on",motor_id);  break;

        case Operation_enabled:       MSG_USER(0x8000,"Operation_enabled",motor_id);  break;

        case Quick_stop_active:       MSG_USER(0x8000,"Quick_stop_active",motor_id);  break;

        case Fault_reaction_active:   MSG_USER(0x8000,"Fault_reaction_active",motor_id);  break;
        case Fault:                   MSG_USER(0x8000,"Fault",motor_id);  break;

        default:                      MSG_USER(0x8000,"Invalid_data",motor_id);
        }
       MOTOR_STATUS[motor_id-1] = 0;
    return status;
}


/**
  * @brief  鍒濆鍖杕otor鍥炶皟鐢?  * @param   motor id濡傛灉杈撳叆
  * @retval status
  */
static void CheckSDOAndContinue(CO_Data* d, UNS8 nodeId)
{
    UNS32 abortCode;
    if(getWriteResultNetworkDict (d, nodeId, &abortCode) != SDO_FINISHED)
    {
        if(motor[nodeId-1].SDO_status        == SDO_Write_Multi_check)
        {
             MSG_USER(0x00,"Master : Failed SDO_WRITE_Multi_check \n", motor[nodeId-1].initStep);
        }
        else if(motor[nodeId-1].SDO_status   == SDO_Write_One_check)
        {
             motor[nodeId-1].Write_One_Finsh_state = FAIL_SEND;
        }
        MSG_USER(0x00,"Master : Failed in initializing slave \n", motor[nodeId-1].initStep);
        MSG_USER(0x01,"Master : Failed in initializing slave \n", abortCode);
        closeSDOtransfer(d, nodeId, SDO_CLIENT);

        motor[nodeId-1].Wrte_Multi_Finsh_state = FAIL_SEND;
        motor[nodeId-1].Write_multi_step = 0;
        motor[nodeId-1].SDO_status  = SDO_free;

    }
    /* Finalise last SDO transfer with this node */
    else
    {
        MSG_USER(0x9999,"-----------------SDO_SEND_OK____________________________", motor[nodeId-1].initStep);
        closeSDOtransfer(d, nodeId, SDO_CLIENT);

        if(motor[nodeId-1].SDO_status      == SDO_ConfigureSlaveNode_check)
        {
        ConfigureSlaveNode(d, nodeId);
        }
        else if(motor[nodeId-1].SDO_status == SDO_Set_postion_speed_check)
        {
         Send_Motor_Speed_Postion(d, nodeId);
        }
        if(  motor[nodeId-1].SDO_status     == SDO_Write_One_check)
        {
             motor[nodeId-1].Write_One_Finsh_state = SUCCESS_SEND;
             motor[nodeId-1].SDO_status  = SDO_free;
        }
        if( motor[nodeId-1].SDO_status     == SDO_Write_Multi_check)
        {
           Write_Multi_Data(d,nodeId);
           MSG_USER(0x9999,"---------------- SDO_Write_Multi_check___________________________",0);
        }

    }

}


/**
  * @brief  鍐欏叆motor鍥炶皟鐢?  * @param   motor id濡傛灉杈撳叆
  * @retval status
  */
static void CheckSDOWrite(CO_Data* d, UNS8 nodeId)
{
    UNS32 abortCode;
    if(getWriteResultNetworkDict (d, nodeId, &abortCode) != SDO_FINISHED)
    {

        MSG_USER(0x01,"Master : write is fail \n", abortCode);
        closeSDOtransfer(d, nodeId, SDO_CLIENT);
    }
    else
    {
        MSG_USER(0x9999,"-----------------SDO_write_OK____________________________",0);
        closeSDOtransfer(d, nodeId, SDO_CLIENT);
    }

}



UNS8 Write_MOTOR_One_Data(UNS8 nodeId, UNS16 Index,UNS8 Subindex,UNS8 count,UNS8 data)
{
    UNS8 Ret;
    if(motor[nodeId-1].SDO_status == SDO_free)
    {
        Ret = writeNetworkDictCallBack(&ObjDict_Data, /* CO_Data* d*/
                        nodeId, /* UNS8 nodeId*/
                        Index, /* UNS16 index*/
                        Subindex, /* UNS8 subindex*/
                        count, /* UNS8 count*/
                        0, /* UNS8 dataType*/
                        &data,/* void *data*/
                        CheckSDOAndContinue,/* Callback*/
                        0); /* no block mode */
        if(Ret == 0)
        {
            motor[nodeId-1].SDO_status = SDO_Write_One_check;
            motor[nodeId-1].Write_One_Finsh_state = RUN_SEND;
            return 0;
        }
        else
        {
            motor[nodeId-1].SDO_status = SDO_free;
            motor[nodeId-1].Write_One_Finsh_state = FAIL_SEND;
            return 0xff;
        }


    }



    else
        return 0xff;

}

void Write_Multi_Data(CO_Data* d, UNS8 nodeId)
{
     UNS8 reslut ;
     motor[nodeId-1].SDO_status = SDO_Write_Multi_check;

     reslut = SDO_STEP(d,nodeId,ObjDict_Data.sdo_write_multi_buf[nodeId-1],&motor[nodeId-1].Write_multi_step,CheckSDOAndContinue);
    if(reslut == 0)
    {
        MSG_ERR(0x000,"Wrte_Multi_Finsh_state",motor[nodeId-1].Wrte_Multi_Finsh_state);
        motor[nodeId-1].Write_multi_step = 0;
        motor[nodeId-1].SDO_status = SDO_free;
        motor[nodeId-1].Wrte_Multi_Finsh_state = SUCCESS_SEND;
    }
    else if(reslut == 0xff)
    {
        MSG_ERR(0x000,"Wrte_Multi_Finsh_state",motor[nodeId-1].Wrte_Multi_Finsh_state);
        motor[nodeId-1].Write_multi_step = 0;
        motor[nodeId-1].SDO_status = SDO_free;
        motor[nodeId-1].Wrte_Multi_Finsh_state = FAIL_SEND;
    }

}
/*
   0 表示正常发送
   ff表示发送失败
   返回 RUN_SEND正在发送
        SUCESSS_SEND
  */

UNS8 Write_MOTOR_Multi_Data(S_Data_trans *buf,UNS8 nodeId)
{
    ObjDict_Data.sdo_write_multi_buf[nodeId-1] = buf;

    if(motor[nodeId-1].SDO_status == SDO_free) //线路正在发送数据
    {
         motor[nodeId-1].Wrte_Multi_Finsh_state = RUN_SEND;
         MSG_USER(0x8888,"----------Write_MOTOR_Multi_Data-----------",0);
         Write_Multi_Data(&ObjDict_Data, nodeId);
         return 0x00;
    }
    else
    {
        motor[nodeId-1].Wrte_Multi_Finsh_state = FAIL_SEND;
        return 0xFF;
    }
}

void ConfigureSlaveNode(CO_Data* d, UNS8 nodeId)
{
       UNS8 reslut;
       motor[nodeId-1].SDO_status = SDO_ConfigureSlaveNode_check;
       reslut = SDO_STEP(d,nodeId,&init_buf[nodeId-1],&motor[nodeId-1].initStep,CheckSDOAndContinue);
      if(reslut == 0)
     {
      motor[nodeId-1].initStep = 0;
      motor[nodeId-1].initStatus= 1;
      motor[nodeId-1].SDO_status = SDO_free;
      masterSendNMTstateChange (d, nodeId, NMT_Start_Node);
      d->NMTable[nodeId] = Operational;
     }

}
static UNS8 SDO_STEP(CO_Data* d,UNS8 nodeId,S_Data_trans* cmd,UNS8* Step,SDOCallback_t Callback)
{
  UNS8 relsut    = 0;
  UNS16 Index    = cmd->data[*Step].Index;
  UNS8  Subindex = cmd->data[*Step].Subindex;
  UNS8  max_step = cmd->Cmd_num;
  UNS8  Count    = cmd->data[*Step].Count;
  UNS32 Data;
  MSG_USER(0x00,"----------------------step---------------------",0x00);
  if(Count == 0x01)
  {
      Data = (UNS8)cmd->data[*Step].Data;
  }
  if(Count == 0x02)
  {
      Data = (UNS16)cmd->data[*Step].Data;
  }
  if(Count == 0x04)
  {
      Data = (UNS32)cmd->data[*Step].Data;
  }
  (*Step)++;
  MSG_USER(0x00,"----------------------step:---------------------",*Step);
  MSG_USER(0x00,"----------------------maxstep:---------------------",max_step);
  if((*Step) > max_step)
  {
     return 0;
  }
  MSG_USER(0x00,"----------------------step1---------------------",0x00);
  relsut = writeNetworkDictCallBack (d, /*CO_Data* d*/
          nodeId, /*UNS8 nodeId*/
          Index, /*UNS16 index*/
        Subindex, /*UNS8 subindex*/
        Count, /*U0x6040NS8 count*/
        0, /*UNS8 dataType*/
        &Data,/*void *data*/
        Callback, /*SDOCallback_t Callback*/
        0); /* use block mode */
  if(relsut != 0x00)
  return 0xff;
  else
      return 0xAA;
}
long Get_MOTOR_Demand_Postion(UNS8 motor_id)
{
    return MOTOR_POSTION[motor_id -1];

}

UNS8 Read_MOTOR_MSG(UNS8 nodeId)
{
    readNetworkDict(&ObjDict_Data,nodeId,CONTROL_INDEX,0x00,0,0);
    return 0;
}

UNS8 Stop_MOTOR(UNS8 nodeId)
{
   UNS16 quick_stop = 0;
   quick_stop= ( QUICK_STOP);//Get_MOTOR_StatusWord(nodeId) |
   Write_MOTOR_One_Data(nodeId,0x6040,0x00,2,quick_stop);

}
/**
  * @brief  璁剧疆motor浣嶇疆 鍜岄€熷害nodeId
  * @param  motor id
  * @retval status
  */
UNS8 Set_Motor_Speed_Postion_Rel(UNS8 nodeId,UNS32 speed,UNS32 postion)
{
//        static UNS8 wait_send_finish;
//        static UNS8 TransmitError;
//        set_Postion_Speed_buf[nodeId-1].data[1].Data     =  postion;
//        set_Postion_Speed_buf[nodeId-1].data[2].Data     =  speed;
//        set_Postion_Speed_buf[nodeId-1].data[3].Data     =  0x7f;
//        if(wait_send_finish == 0)
//        {
//            if(Write_MOTOR_Multi_Data(&set_Postion_Speed_buf[nodeId-1],nodeId) == 0x00)//发送成功
//            {
//                wait_send_finish  = 1;
//            }
//            else
//            {
//                return FAIL_SEND; //还没出口就失败了
//            }
//        }
//        else if((wait_send_finish == 1) && ((motor[nodeId-1].Wrte_Multi_Finsh_state == SUCCESS_SEND)))
//        {
//                motor[nodeId-1].Wrte_Multi_Finsh_state = NO_SEND;
//                motor[nodeId-1].SDO_status = SDO_free;
//                wait_send_finish = 0;
//                return SUCCESS_SEND;
//        }
//         else if((wait_send_finish == 1) && ((motor[nodeId-1].Wrte_Multi_Finsh_state == FAIL_SEND)))
//        {
//               motor[nodeId-1].Wrte_Multi_Finsh_state = NO_SEND;
//               TransmitError++;
//               wait_send_finish = 0;
//               if(TransmitError >RE_TIME) //重发机制
//               {
//                   TransmitError = 0;
//                   return  FAIL_SEND;
//               }
//        }
//    if(motor[nodeId-1].SDO_status != SDO_free)
//        {
//            return YES_BUSY;
//        }
//    else
//        {
        set_Postion_Speed_buf[nodeId-1].data[1].Data     =  postion;
        set_Postion_Speed_buf[nodeId-1].data[2].Data     =  speed;
        set_Postion_Speed_buf[nodeId-1].data[3].Data     =  0x7f;
        // Send_Motor_Speed_Postion(&ObjDict_Data,nodeId);
        Write_MOTOR_Multi_Data(&set_Postion_Speed_buf[nodeId-1],nodeId);
 //       return NO_BUSY;

//       }

}
UNS8 Set_Motor_Speed_Postion_Abs(UNS8 nodeId,UNS32 speed,UNS32 postion)
{
    if(motor[nodeId-1].SDO_status != SDO_free)
        {
            return YES_BUSY;
        }
    else
        {
        set_Postion_Speed_buf[nodeId-1].data[1].Data     =  postion;
        set_Postion_Speed_buf[nodeId-1].data[2].Data     =  speed;
        set_Postion_Speed_buf[nodeId-1].data[3].Data     =  0x3f;
        // Send_Motor_Speed_Postion(&ObjDict_Data,nodeId);
        Write_MOTOR_Multi_Data(&set_Postion_Speed_buf[nodeId-1],nodeId);
        return NO_BUSY;

        }

}

void Send_Motor_Speed_Postion(CO_Data* d,UNS8 nodeId)
{
    UNS8 reslut;
    motor[nodeId-1].SDO_status = SDO_Set_postion_speed_check;
    reslut = SDO_STEP(d,nodeId,&set_Postion_Speed_buf[nodeId-1],&motor[nodeId-1].Set_motor_step,CheckSDOAndContinue);
    if(reslut == 0)
   {
    motor[nodeId-1].Set_motor_step = 0;
    motor[nodeId-1].SDO_status = SDO_free;
   }
}

/******************读取函数******************************/
void read_One_Data(UNS8 nodeId, UNS16 Index,UNS8 Subindex)
{
    UNS8 Ret = 0;
    if(motor[nodeId-1].SDO_status == SDO_free)
    {
    motor[nodeId-1].Read_one_state = RUN_SEND;
    motor[nodeId-1].SDO_status  = SDO_Read_One_check;
    motor[nodeId-1].Read_multi_step = 0;  //为了和多个传输公用
    Ret = readNetworkDictCallback(&ObjDict_Data, /* CO_Data* d*/
                   nodeId, /* UNS8 nodeId*/
                   Index, /* UNS16 index*/
                   Subindex, /* UNS8 subindex*/
                   0, /* UNS8 dataType*/
                   CheckSDORead,/* Callback*/
                   0); /* no blockCheckSDOAndContinue mode */
    if(Ret == 0xff)//发送失败
    {
        motor[nodeId-1].Read_one_state = FAIL_SEND;
        motor[nodeId-1].SDO_status  = SDO_free;
        MSG_USER(0x0000,"no send to",0x000);
    }
    }
}


static UNS8 SDO_Read_STEP(CO_Data* d,UNS8 nodeId,S_Data_trans* cmd,UNS8* Step,SDOCallback_t Callback)
{
  UNS8 Ret = 0;
  UNS16 Index    = cmd->data[*Step].Index;
  UNS8  Subindex = cmd->data[*Step].Subindex;
  UNS8  max_step = cmd->Cmd_num;
  MSG_USER(0x00,"----------------------step---------------------",0x00);

  MSG_USER(0x00,"----------------------step:---------------------",*Step);
  MSG_USER(0x00,"----------------------maxstep:---------------------",max_step);
  (*Step)++;
  if((*Step) > max_step)
  {
     return 0;
  }
  MSG_USER(0x00,"----------------------step1---------------------",0x00);
  Ret=readNetworkDictCallback(d, /*CO_Data* d*/
        nodeId, /*UNS8 nodeId*/
        Index, /*UNS16 index*/
        Subindex, /*UNS8 subindex*/
        0, /*UNS8 dataType*/
        Callback, /*SDOCallback_t Callback*/
        0); /* use block mode */
  if(Ret)
  return 0xff;
  else
      return 0xAA;
}
void Read_Multi_data(CO_Data* d,UNS8 nodeId)
{
    UNS8 reslut ;
    motor[nodeId-1].SDO_status = SDO_Read_Multi_check;
    reslut = SDO_Read_STEP(d,nodeId,ObjDict_Data.sdo_read_multi_buf[nodeId-1],&motor[nodeId-1].Read_multi_step,CheckSDORead);
    if(reslut == 0x00)
    {
        MSG_USER(0x000,"read to successd------------------------",0x0);
        motor[nodeId-1].Read_multi_step = 0;
        motor[nodeId-1].SDO_status = SDO_free;
        motor[nodeId-1].Read_Multi_Finsh_state = SUCCESS_SEND;
    }
    if(reslut == 0xff)
    {
        MSG_USER(0x000,"read to fail---------------------------",0x0);
        motor[nodeId-1].Read_multi_step = 0;
        motor[nodeId-1].SDO_status = SDO_free;
        motor[nodeId-1].Read_Multi_Finsh_state = FAIL_SEND;
    }

}
/*
   00;
   FF;
  */

UNS8 Read_MOTOR_Multi_Data(S_Data_trans *buf,UNS8 nodeId)
{
    ObjDict_Data.sdo_read_multi_buf[nodeId-1] = buf;

    if(motor[nodeId-1].SDO_status == SDO_free)
    {
      motor[nodeId-1].Read_Multi_Finsh_state = RUN_SEND;
      Read_Multi_data(&ObjDict_Data, nodeId);
      return 0;
    }
    else
        return 0xff;
}

/**
  * @brief  璇诲彇motor鍥炶皟鐢?  * @param   motor id濡傛灉杈撳叆
  * @retval status
  */

static void CheckSDORead(CO_Data* d, UNS8 nodeId)
{
    UNS32 abortCode;
    UNS8 i = 0;
    motor[nodeId-1].RX_size = 4;
    motor[nodeId-1].RX_buf[0]  = 0;
    motor[nodeId-1].RX_buf[1]  = 0;
    motor[nodeId-1].RX_buf[2]  = 0;
    motor[nodeId-1].RX_buf[3]  = 0;


    if(getReadResultNetworkDict (d, nodeId, &motor[nodeId-1].RX_buf, &motor[nodeId-1].RX_size, &abortCode)  != SDO_FINISHED)
    {
        MSG_USER(0x01,"Master : CheckSDORead to fail \n", abortCode);



        if(motor[nodeId-1].SDO_status  == SDO_Read_Multi_check)
        {
             motor[nodeId-1].Read_Multi_Finsh_state = FAIL_SEND;
             motor[nodeId-1].Read_multi_step = 0 ;
              MSG_USER(0x01,"Master : Read_multi_state to fail \n", 0);
      }
        if(motor[nodeId-1].SDO_status  == SDO_Read_One_check)
        {
             motor[nodeId-1].Read_one_state = FAIL_SEND;
             MSG_USER(0x01,"Master : Read_one_state to fail \n", 0);
        }
        motor[nodeId-1].SDO_status   = SDO_free;
    }
    else
    {
        motor[nodeId -1 ].RX_DATA[motor[nodeId-1].Read_multi_step] = 0 ;//使用前  clean 0
        for(i = 0;i<motor[nodeId-1].RX_size;i++)
        {
            motor[nodeId -1 ].RX_DATA[motor[nodeId-1].Read_multi_step] |= motor[nodeId -1 ].RX_buf[i]<<(8*i);//第一位留给write_one_buf
        }
        MSG_USER(0x01,"-------------------CHECKSDORead__size:_________________OK",  motor[nodeId-1].RX_size);
        MSG_USER(0x02,"-------------------CHECKSDORead__buf1_________________OK",   motor[nodeId-1].RX_buf[0]);
        MSG_USER(0x03,"-------------------CHECKSDORecl---buf2_________________OK",  motor[nodeId-1].RX_buf[1]);
        MSG_USER(0x04,"-------------------CHECKSDORead___buf3________________OK",   motor[nodeId-1].RX_buf[2]);
        MSG_USER(0x04,"-------------------CHECKSDORead___buf4________________OK",   motor[nodeId-1].RX_buf[3]);
        MSG_USER(0x05,"-------------------RX_DATA:_________________OK",  motor[nodeId-1].RX_DATA[motor[nodeId-1].Read_multi_step]);
        MSG_USER(0x05,"-------------------Read_multi_step:_________________OK",  motor[nodeId-1].Read_multi_step);

        if(motor[nodeId-1].SDO_status == SDO_Read_Multi_check)
        {
            Read_Multi_data(d,nodeId);
            MSG_USER(0x05,"----------------SDO_Read_Multi_check--________________OK",  motor[nodeId-1].RX_DATA[1]);
        }
        if(motor[nodeId-1].SDO_status  == SDO_Read_One_check)
        {
            motor[nodeId-1].SDO_status = SDO_free;
            MSG_USER(0x05,"----------------SDO_Read_o_check--________________OK",  motor[nodeId-1].RX_DATA[1]);
            motor[nodeId-1].Read_one_state = SUCCESS_SEND;
        }
   //   motor[nodeId-1].Read_Multi_Finsh_state = SUCCESS_SEND;
    }
 //  closeSDOtransfer(d, nodeId, SDO_CLIENT);

}


