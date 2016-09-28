#include "canfestival.h"
#include "stdio.h"
#include"TestSlave.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/socket.h>
#include <linux/can.h>
#include <linux/can/error.h>
#include <linux/can/raw.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "ObjDict.h"
//#ifndef AF_CAN
//#define AF_CAN 29
//#endif
//#ifndef PF_CAN
//#define PF_CAN AF_CAN
//#endif

#define CAN_RTR_DATA     ((unsigned int )0x00000000)
#define CAN_RTR_REMOTE   ((unsigned int )0x00000002)
#define CAN_ID_STD       ((unsigned int)0x00000000)

extern int fd_Write,fd,fd_Read;
//int ret,i;
//struct sockaddr_can addr;
//struct ifreq ifr;

extern struct can_frame fr, canwr,canre,frdup;
//struct timeval tv;
//fd_set rset;

typedef struct
{
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8_t IDE;     /*!< Specifies the type of identifier for the message that
                        will be transmitted. This parameter can be a value
                        of @ref CAN_identifier_type */

  uint8_t RTR;     /*!< Specifies the type of frame for the message that will
                        be transmitted. This parameter can be a value of
                        @ref CAN_remote_transmission_request */

  uint8_t DLC;     /*!< Specifies the length of the frame that will be
                        transmitted. This parameter can be a value between
                        0 to 8 */

  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0
                        to 0xFF. */
} CanTxMsg;

typedef struct
{
  uint32_t StdId;  /*!< Specifies the standard identifier.
                        This parameter can be a value between 0 to 0x7FF. */

  uint32_t ExtId;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8_t IDE;     /*!< Specifies the type of identifier for the message that
                        will be received. This parameter can be a value of
                        @ref CAN_identifier_type */

  uint8_t RTR;     /*!< Specifies the type of frame for the received message.
                        This parameter can be a value of
                        @ref CAN_remote_transmission_request */

  uint8_t DLC;     /*!< Specifies the length of the frame that will be received.
                        This parameter can be a value between 0 to 8 */

  uint8_t Data[8]; /*!< Contains the data to be received. It ranges from 0 to
                        0xFF. */

  uint8_t FMI;     /*!< Specifies the index of the filter the message stored in
                        the mailbox passes through. This parameter can be a
                        value between 0 to 0xFF */
} CanRxMsg;

unsigned int TimeCNT=0;//时间计数
unsigned int NextTime=0;//下一次触发时间计数
unsigned int TIMER_MAX_COUNT=0xffff;//最大时间计数
static TIMEVAL last_time_set = TIMEVAL_MAX;//上一次的时间计数


void setTimer(TIMEVAL value)
{
        NextTime=(TimeCNT+value)%TIMER_MAX_COUNT;
}


// Get the elapsed time since the last occured alarm //
TIMEVAL getElapsedTime(void)
{
    int ret=0;
       // ret = TimeCNT> last_time_set ? TimeCNT - last_time_set : TimeCNT + TIMER_MAX_COUNT - last_time_set;
    // 修改计数值
        ret = TimeCNT> last_time_set ? TimeCNT - last_time_set :last_time_set-TimeCNT;
        last_time_set = TimeCNT;
        return ret;
}
void timerForCan()
{

        if (TimeCNT>= TIMER_MAX_COUNT)
        {
                TimeCNT=0;
        }
        if (TimeCNT == NextTime)
        {
                TimeDispatch();
        }
      // printf("timerforcan is ok!\n");
        TimeCNT++;
}

//void socketCan()
//{
//    canfd=socket(PF_CAN, SOCK_RAW, CAN_RAW);
//    if(canfd<0)
//    {
//    perror("socket");
//    exit(1);
//    }
//    strcpy(ifr.ifr_name, "can0" );
//    if(ioctl(canfd, SIOCGIFINDEX, &ifr)<0)
//    {
//      perror("ioctl");
//      return 1;
//    }
//    addr.can_family = PF_CAN;
//    addr.can_ifindex = ifr.ifr_ifindex;
//    if(bind(canfd, (struct sockaddr *)&addr, sizeof(addr))<0)
//    {
//       perror("bind");
//       return 1;
//    }
//}


int canReceive_Handle()
{
    Message m;
    int i;
//fd_Read=socket(PF_CAN, SOCK_RAW, CAN_RAW);
//    if(fd_Read<0)
//    {
//    perror("socket");
//    exit(1);
//    }
//    strcpy(ifr.ifr_name, "can0" );
//    if(ioctl(fd_Read, SIOCGIFINDEX, &ifr)<0)
//    {
//      perror("ioctl");
//      return 1;
//    }
//    addr.can_family = PF_CAN;
//    addr.can_ifindex = ifr.ifr_ifindex;
//    if(bind(fd_Read, (struct sockaddr *)&addr, sizeof(addr))<0)
//    {
//       perror("bind");
//       return 1;
//    }
    if(read(fd_Read, &canre, sizeof(struct can_frame))<sizeof(struct can_frame))
    {
        perror("read failed");
        return -1;
    }
    m.cob_id=canre.can_id;
    m.rtr=0;
    m.len=canre.can_dlc;
    for(i = 0; i <  m.len; i++)
    m.data[i]=canre.data[i];

    canDispatch(&ObjDict_Data, &m);
  //  close(fd_Read);
    return 0;
}


unsigned char canSend(CAN_PORT notused,Message *m)
{
   uint32_t i;
   CanTxMsg TxMessage;
   CanTxMsg *ptx_msg=&TxMessage;
   ptx_msg->StdId = m->cob_id;

   ptx_msg->RTR = CAN_RTR_DATA;

   ptx_msg->IDE = CAN_ID_STD;

    ptx_msg->DLC = m->len;
    for(i = 0; i < m->len; i++)
    ptx_msg->Data[i] = m->data[i];

//        fd_Write=socket(PF_CAN, SOCK_RAW, CAN_RAW);
//        if(fd_Write<0)
//        {
//        perror("socket");
//        exit(1);
//        }
//        strcpy(ifr.ifr_name, "can0" );
//        if(ioctl(fd_Write, SIOCGIFINDEX, &ifr)<0)
//        {
//          perror("ioctl");
//          return 1;
//        }
//        addr.can_family = PF_CAN;
//        addr.can_ifindex = ifr.ifr_ifindex;
//        if(bind(fd_Write, (struct sockaddr *)&addr, sizeof(addr))<0)
//        {
//           perror("bind");
//           return 1;
//        }
    memcpy(canwr.data,ptx_msg->Data,8);
    canwr.can_dlc=ptx_msg->DLC;
    canwr.can_id= m->cob_id;
    write(fd_Write, &canwr, sizeof(struct can_frame));
  //  close(fd_Write);
    return 0x00;
}


