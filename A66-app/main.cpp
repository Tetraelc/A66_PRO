#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QWSServer>

#include "TestMaster.h"
///////////////////
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
#include "CanopenDictConfig.h"
///////////////
#include "global.h"
#include "manual.h"
#include "thread.h"
#include "homingmode.h"

extern int XMotorStatusWord,YMotorStatusWord;
extern int MotorXDisplayFalg,MotorYDisplayFalg;
extern int MotorXDisplayValue,MotorYDisplayValue;


/*第二次测试分支效果*/
#ifndef AF_CAN
#define AF_CAN 29
#endif
#ifndef PF_CAN
#define PF_CAN AF_CAN
#endif

#define CAN_RTR_DATA     ((unsigned int )0x00000000)
#define CAN_RTR_REMOTE   ((unsigned int )0x00000002)
#define CAN_ID_STD       ((unsigned int)0x00000000)

int fd_Write,fd,fd_Read;
int ret,i;
struct sockaddr_can addr;
struct ifreq ifr;

struct can_frame fr, canwr,canre,frdup;
struct timeval tv;
fd_set rset;

extern CO_Data TestSlave_Data;
extern "C"{
     #include "canfestival.h"
}

class  MyThread :  public  QThread {
   public :
       virtual   void  run();
  };

void  MyThread::run()
 {
       while(1)
       {
        canReceive_Handle();
       //  qDebug("call_can_receive_over\n\r");
       }
 }

class  MotorThread :  public  QThread {
   public :
       virtual   void  run();
  };

void  MotorThread::run()
 {
       while(1)
       {
//           if(MotorXDisplayFalg==1)
//           {
//               MotorXDisplayValue = Get_MOTOR_Demand_Postion(0x01);
//           }

//           if(MotorYDisplayFalg==1)
//           {
//               MotorYDisplayValue = Get_MOTOR_Demand_Postion(0x02);
//           }

       }
 }





int main(int argc, char *argv[])
{
#if    ARMFlag
    CanopenInit();
///////////////////////////////
    printf("to_socket\n");
    fd_Read=socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(fd_Read<0)
    {
    perror("socket");
    exit(1);
    }
    printf("to_socket1\n");
    strcpy(ifr.ifr_name, "can0" );
    if(ioctl(fd_Read, SIOCGIFINDEX, &ifr)<0)
    {
      perror("ioctl");
      return 1;
    }
    addr.can_family = PF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if(bind(fd_Read, (struct sockaddr *)&addr, sizeof(addr))<0)
    {
       perror("bind");
       return 1;
    }

    ///////////////////////////
         printf("to_socket3\n");
                fd_Write=socket(PF_CAN, SOCK_RAW, CAN_RAW);
                if(fd_Write<0)
                {
                perror("socket");
                exit(1);
                }
                printf("to_socket4\n");
                strcpy(ifr.ifr_name, "can0" );
                if(ioctl(fd_Write, SIOCGIFINDEX, &ifr)<0)
                {
                  perror("ioctl");
                  return 1;
                }
                addr.can_family = PF_CAN;
                addr.can_ifindex = ifr.ifr_ifindex;
                if(bind(fd_Write, (struct sockaddr *)&addr, sizeof(addr))<0)
                {
                   perror("bind");
                   return 1;
                }

               ////////////////
        printf("mian----------\n\r");

#endif
    QApplication a(argc, argv);

   // QWSServer::setCursorVisible(false);
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    Sql_Init();
//    MainWindow w;
//    w.setWindowFlags(Qt::FramelessWindowHint);
//    w.move(0,MAIN_WIDGET_Y);
//    w.show();

    qSoftKeyvaule *ic = new qSoftKeyvaule;
    a.setInputContext(ic);

    MyThread ThreadA;
    ThreadA.start();

    HomingMode hm;
    hm.setWindowFlags(Qt::FramelessWindowHint);
    hm.move(0,WIDGET_Y);
    hm.show();

//    Programdb Pg ;
//    Pg.setWindowFlags(Qt::FramelessWindowHint);
//    Pg.move(0,WIDGET_Y);
//    Pg.show();


    
    return a.exec();
}
