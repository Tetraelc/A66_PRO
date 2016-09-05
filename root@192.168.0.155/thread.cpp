#include "thread.h"

#include <QDebug>
#include "CanopenDictConfig.h"


int MotorXDisplayValue,MotorYDisplayValue;
int XMotorStatusWord,YMotorStatusWord;
int MotorXDisplayFalg=0;
int MotorYDisplayFalg=0;
int MotorRDisplayFalg=0;
extern QString ReturnMotorValue;
bool stopped;
extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"
void Thread::run()
{
    while(!stopped)
    {

//        if(MotorXDisplayFalg==1)
//        {
//          MotorXDisplayValue=Get_MOTOR_Demand_Postion(0x01);
//          qDebug("1111111111111");
//        //ReturnMotorValue=QString::number(MotorXDisplayValue,10);
//        }
//        if(MotorYDisplayFalg==1)
//        {
//         MotorYDisplayValue=Get_MOTOR_Demand_Postion(0x02);
//        qDebug("22222222222222");
//        //ReturnMotorValue=QString::number(MotorYDisplayValue,10);
//        }

//        emit sig_sndMotorThread();

    }
    stopped=false;
}


void Thread::stop()
{
    stopped=true;
}

Thread::Thread()
{
    stopped=false;

}

}
