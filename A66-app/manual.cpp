#include "manual.h"
#include "ui_manual.h"
#include "stdio.h"
#include "CanopenDictConfig.h"
#include <QDebug>
#include "manualadjustdate.h"
#include "global.h"
#include "yreferencepoint.h"
#include "deleoplength.h"
#include "systemsetting.h"


extern bool stopped;
extern QString ReturnMotorValue;

extern int XMotorStatusWord,YMotorStatusWord;
extern int MotorXDisplayFalg,MotorYDisplayFalg,MotorRDisplayFalg;
extern int MotorXDisplayValue,MotorYDisplayValue;

int ManualVisiableFlag =0;


int time_count = 0;
int status_set = 0;
int time_count1 = 0;

static int step = 0;
long last_pos[3] = {0};

unsigned char Trg;
unsigned char Cont;
extern int node_1_init_ok;

extern int ManualSpeedValue;

extern int PDOINDEX;


extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"

Manual::Manual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    id1 = startTimer(1); //其返回值为timerId
    id2 = startTimer(100);
    id3 = startTimer(200);
    //ui->label_X->setText(trUtf8("停止"));
   // ui->label_Y->setText(trUtf8("停止"));
    ui->frame_State->setVisible(false);

}

Manual::~Manual()
{
    delete ui;
}

void Manual::openManualWin()
{

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);
    SystemSetting syssetting;
    syssetting.ReadForSystemDat();

    qDebug()<<"openManualWin";
}



void Manual::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()==id1){

      timerForCan();

    }
    if(t->timerId()==id1){

//        if(MotorXDisplayFalg == 1)
//        {

           double Dis_XPos =Get_MOTOR_Demand_Postion(0x01) * XaxisParameter.LeadScrew /1000;
           double Dis_YPos =Get_MOTOR_Demand_Postion(0x02) * XaxisParameter.LeadScrew /1000;
           double Dis_RPos =Get_MOTOR_Demand_Postion(0x03) * XaxisParameter.LeadScrew /1000;

           ui->lineEdit_ManualX->setText(QString::number(Dis_XPos,'.',2));
//        }
//        if(MotorYDisplayFalg == 1)
//        {
           ui->lineEdit_ManualY->setText(QString::number(Dis_YPos,'.',2));
//        }
//        if(MotorRDisplayFalg == 1)
//        {
          ui->lineEdit_ManualR->setText(QString::number(Dis_RPos,'.',2));
//        }

    }
    if(t->timerId()==id2){

//        Checkstatus(0x01);
//        Checkstatus(0x02);

    }
    if(t->timerId()==id3){

        CheckINState();
        CheckRunState();
        CheckOutState();
        ui->lineEdit_error1->setText(QString::number(motor[0].SendCountError+motor[0].ReadCountError,10));
        ui->lineEdit_error2->setText(QString::number(motor[1].SendCountError+motor[1].ReadCountError,10));
        ui->lineEdit_error3->setText(QString::number(motor[2].SendCountError+motor[2].ReadCountError,10));

    }

}
int Manual::CheckRunState()
{
   // qDebug()<<"A20_Run_Status"<<A20_Run_Status;
    switch(A20_Run_Status)
    {
    case VFast:
         ui->lineEdit_RunState->setText(trUtf8("快下"));break;

    case VSlow :
        ui->lineEdit_RunState->setText(trUtf8("工进"));break;
    case  Vkeep  :
        ui->lineEdit_RunState->setText(trUtf8("保压"));break;
    case Vunload :
        ui->lineEdit_RunState->setText(trUtf8("卸荷"));break;
    case Vback   :
        ui->lineEdit_RunState->setText(trUtf8("回程"));break;
    case Vstop  :
        ui->lineEdit_RunState->setText(trUtf8("停止"));break;
    default:
        ui->lineEdit_RunState->setText(trUtf8("未知状态"));break;
    }

}

int Manual::CheckINState()
{
    if(A20_IN_Status & FootStart)
    ui->label_IN1->setEnabled(true);
    else
    ui->label_IN1->setEnabled(false);
    if(A20_IN_Status & FootUp)
    ui->label_IN2->setEnabled(true);
    else
    ui->label_IN2->setEnabled(false);
    if(A20_IN_Status & CUTSMODE)
    ui->label_IN3->setEnabled(true);
    else
    ui->label_IN3->setEnabled(false);
    if(A20_IN_Status & CUTCMODE)
     ui->label_IN4->setEnabled(true);
    else
    ui->label_IN4->setEnabled(false);
    if(A20_IN_Status & UpperPoint)
    ui->label_IN5->setEnabled(true);
    else
    ui->label_IN5->setEnabled(false);
    if(A20_IN_Status & DownPoint)
    ui->label_IN6->setEnabled(true);
    else
    ui->label_IN6->setEnabled(false);
    if(A20_IN_Status & PumpSignal)
    ui->label_IN7->setEnabled(true);
    else
    ui->label_IN7->setEnabled(false);
   // qDebug()<<"A20_IN_Status"<<A20_IN_Status;
}
int Manual::CheckOutState()
{
    if(A20_OUT_Status & 0x01)
        ui->label_OUT1->setEnabled(true);
    else
        ui->label_OUT1->setEnabled(false);
    if(A20_OUT_Status & 0x02)
        ui->label_OUT2->setEnabled(true);
    else
        ui->label_OUT2->setEnabled(false);
    if(A20_OUT_Status & 0x04)
        ui->label_OUT3->setEnabled(true);
    else
        ui->label_OUT3->setEnabled(false);
    if(A20_OUT_Status & 0x08)
        ui->label_OUT4->setEnabled(true);
    else
        ui->label_OUT4->setEnabled(false);
    if(A20_OUT_Status & 0x10)
        ui->label_OUT5->setEnabled(true);
    else
        ui->label_OUT5->setEnabled(false);
    if(A20_OUT_Status & 0x20)
        ui->label_OUT6->setEnabled(true);
    else
        ui->label_OUT6->setEnabled(false);
    if(A20_OUT_Status & 0x40)
        ui->label_OUT7->setEnabled(true);
    else
        ui->label_OUT7->setEnabled(false);
    if(A20_OUT_Status & 0x80)
        ui->label_OUT8->setEnabled(true);
    else
        ui->label_OUT8->setEnabled(false);


}
int Manual::Checkstatus(int motor_id)
{

    UNS16 status = 0x00;
    int temp1,temp2,temp3;

    status = MOTOR_STATUS[motor_id-1] & STATUS_MASK;
 //   MSG_USER(0x8000,"MOTOR_STATUS[motor_id-1]",MOTOR_STATUS[motor_id-1]);
  //  MSG_USER(0x8000,"status:",status);
    switch(status)
    {
    case Not_ready_to_switch_on:  MSG_USER(0x8000,"1_Not_ready_to_switch_on",motor_id);  break;

    case SWITCH_ON_DISABLED:      MSG_USER(0x8000, "2_SWITCH_ON_DISABLE"    ,motor_id);  break;

    case Ready_to_switch_on:      MSG_USER(0x8000,"Ready_to_switch_on",motor_id);  break;

    case Swiched_on:              MSG_USER(0x8000,"Swiched_on",motor_id);  break;

    case Operation_enabled:       MSG_USER(0x8000,"Operation_enabled",motor_id);  break;

    case Quick_stop_active:

//        if(motor_id == 0x01 )
//        {
//            ui->label_X->setText(trUtf8("停止"));
//        }
//        if(motor_id == 0x02 )
//        {
//            ui->label_Y->setText(trUtf8("停止"));
//        }
        MSG_USER(0x8000,"quick_stop_active",motor_id);  break;

        break;

    case Fault_reaction_active:   MSG_USER(0x8000,"Fault_reaction_active",motor_id);  break;
    case Fault:
        if(motor_id == 0x01 )
        {
//            QMessageBox::critical(0,QObject::trUtf8("异常"),
//                                  trUtf8("请检查电机"));break;
        }
        if(motor_id == 0x02 )
        {
            QMessageBox::critical(0,QObject::trUtf8("异常"),
                                  trUtf8("请检查电机"));break;
        }

    default:    MSG_USER(0x8000,"Invalid_data",motor_id);break;
    }
      temp1 = MOTOR_STATUS[0] & 0x400;
      temp2 = MOTOR_STATUS[1] & 0x400;
      temp3 = MOTOR_STATUS[2] & 0x400;

//    MOTOR_STATUS[motor_id-1] = 0;
         if(temp1 == 0x400)
         {
            ui->toolButton_X->setEnabled(false);
           // ui->label_X->setText(trUtf8("停止"));
         }
         else
         {
             ui->toolButton_X->setEnabled(true);
            // ui->label_X->setText(trUtf8("运行"));
         }
         if(temp2 == 0x400)
         {
            ui->toolButton_Y->setEnabled(false);
            // ui->label_Y->setText(trUtf8("停止"));
         }
         else
         {
             ui->toolButton_Y->setEnabled(true);
            // ui->label_Y->setText(trUtf8("运行"));
         }
         if(temp3 == 0x400)
         {
            ui->toolButton_R->setEnabled(false);
            // ui->label_Y->setText(trUtf8("停止"));
         }
         else
         {
             ui->toolButton_R->setEnabled(true);
            // ui->label_Y->setText(trUtf8("运行"));

         }


//   last_pos[motor_id] = Get_MOTOR_Demand_Postion(motor_id);
    return status;

    qDebug()<<"openManualWin";
}




void Manual::XMotorThread()
{
//    if(MotorXDisplayFalg==1)
//    {
//     ui->lineEdit_ManualX->setText(QString::number(Get_MOTOR_Demand_Postion(0x01),10));
//     //ui->lineEdit_XCurrentPos->setText(QString::number(MotorXDisplayValue,10));
//    }
//    if(MotorYDispcheckMotorState()layFalg==1)
//    {
//     ui->lineEdit_ManualY->setText(QString::number(Get_MOTOR_Demand_Postion(0x02),10));
//     //ui->lineEdit_YCurrentPos->setText(QString::number(MotorYDisplayValue,10));
//    }
//    qDebug()<<"XMotorThread";

}

void Manual::on_pushButton_M_XBack_pressed()
{
    MotorXDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
     qDebug()<<"XaxisParameter.LeadScrew"<<XaxisParameter.LeadScrew;
     qDebug()<<"XaxisParameter.EncodeDirection"<<XaxisParameter.MotorDirection;
     unsigned long ManualSpeed_temp = XaxisParameter.ManualSpeed;
     long LeadScrew_temp =1000000*1000/ XaxisParameter.LeadScrew;

    if(XaxisParameter.MotorDirection == 1)
    {
        Set_Motor_Speed_Postion_Rel(0x01,ManualSpeed_temp,-1 * LeadScrew_temp);
    }
    else
    {

        Set_Motor_Speed_Postion_Rel(0x01,ManualSpeed_temp ,LeadScrew_temp);
        qDebug()<<"XaxisParameter.EncodeDirectionflase";
    }

   // qDebug()<<"XaxisParameter.ManualSpeed"<<XaxisParameter.ManualSpeed;

}

void Manual::on_pushButton_M_XBack_released()
{
//        ThreadX.stop();

        Stop_MOTOR(0x01);
      //Set_Motor_Speed_Postion_Rel(0x01,0,0);
        //ui->lineEdit_ManualX->setText(QString::number(MotorXDisplayValue,10));
     MotorXDisplayFalg=0;
}
void Manual::on_pushButton_M_XForWard_pressed()
{

    MotorXDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    unsigned long XManualSpeed_temp = XaxisParameter.ManualSpeed;
    long XLeadScrew_temp = 1000000*1000/XaxisParameter.LeadScrew;
    qDebug()<<"XLeadScrew_temp"<<XLeadScrew_temp;
    if(XaxisParameter.MotorDirection == 1)
    {
         Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp,XLeadScrew_temp);
    }
    else
    {
         Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp,-1*XLeadScrew_temp);
    }



}

void Manual::on_pushButton_M_XForWard_released()
{
    //ThreadX.stop();

    //Set_Motor_Speed_Postion_Rel(0x01,0,0);
    Stop_MOTOR(0x01);
    // ui->lineEdit_ManualX->setText(QString::number(MotorXDisplayValue,10));
     MotorXDisplayFalg=0;
}

void Manual::on_pushButton_M_YBack_pressed()
{
    MotorYDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    qDebug()<<"YaxisParameter.ManualSpeed"<<YaxisParameter.ManualSpeed;
    qDebug()<<"YaxisParameter.LeadScrew"<<YaxisParameter.LeadScrew;
    unsigned long YManualSpeed_temp = YaxisParameter.ManualSpeed;
     long YLeadScrew_temp = 1000000*1000/YaxisParameter.LeadScrew;
    if(YaxisParameter.MotorDirection == 1)
    {
             Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp,-1 * YLeadScrew_temp);

    }
    else
    {
       Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp,YLeadScrew_temp);
    }

}

void Manual::on_pushButton_M_YBack_released()
{
    //Set_Motor_Speed_Postion(0x02,0,0);
//    ThreadX.stop();

    Stop_MOTOR(0x02);
    MotorYDisplayFalg=0;
}


void Manual::on_pushButton_M_YForWard_pressed()
{

    MotorYDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    unsigned long YManualSpeed_temp = YaxisParameter.ManualSpeed;
     long YLeadScrew_temp = 1000000*1000/YaxisParameter.LeadScrew;
    if(YaxisParameter.MotorDirection == 1)
    {
         Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp,YLeadScrew_temp);
    }
    else
    {
         Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp,-1 * YLeadScrew_temp);
    }

}

void Manual::on_pushButton_M_YForWard_released()
{

    Stop_MOTOR(0x02);
    //Set_Motor_Speed_Postion(0x02,0,0);
//    ThreadX.stop();
    MotorYDisplayFalg=0;

}


void Manual::on_pushButton_M_RForWard_pressed()
{
     MotorRDisplayFalg=1;

     unsigned long RManualSpeed_temp = RaxisParameter.ManualSpeed;
     unsigned long RLeadScrew_temp = 1000000*1000/RaxisParameter.LeadScrew;
     if(RaxisParameter.MotorDirection == 1)
     {
         Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp,RLeadScrew_temp);
     }
     else
     {
         Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp,-1 * RLeadScrew_temp);
     }
}

void Manual::on_pushButton_M_RForWard_released()
{
     Stop_MOTOR(0x03);
     MotorRDisplayFalg=0;
}

void Manual::on_pushButton_M_RBack_pressed()
{
    MotorRDisplayFalg=1;
    unsigned long RManualSpeed_temp = RaxisParameter.ManualSpeed;
    unsigned long RLeadScrew_temp = 1000000*1000/RaxisParameter.LeadScrew;
    if(RaxisParameter.MotorDirection == 1)
    {
        Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp,-1 * RLeadScrew_temp);
    }
    else
    {
        Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp,RLeadScrew_temp);
    }
}

void Manual::on_pushButton_M_RBack_released()
{
    Stop_MOTOR(0x03);
    MotorRDisplayFalg=0;
}
void Manual::on_toolButton_Length_clicked()
{


}

}
void Manual::on_pushButton_Adjust_clicked()
{

    ManualAdjustDate mad;
    connect(&mad, SIGNAL(sig_sndManualX(QString)),this, SLOT(ChangeXCurrentPostion(QString)));
    connect(&mad, SIGNAL(sig_sndManualY(QString)),this, SLOT(ChangeYCurrentPostion(QString)));
    connect(&mad, SIGNAL(sig_sndManualR(QString)),this, SLOT(ChangeRCurrentPostion(QString)));
    QRect AdjusttRect = ui->pushButton_Adjust->rect();
    qDebug()<<"AdjusttRect"<<AdjusttRect.left();
     qDebug()<<"AdjusttRect"<<AdjusttRect.bottomLeft();

    QPoint madPoint = QPoint(627, 90);
    mad.move(madPoint);
    mad.exec();

}

void Manual::ChangeXCurrentPostion(QString str)
{

    ui->lineEdit_ManualX->setText(str);

    Adjust_ManualDate.data[1].Data = str.toInt();
    Write_MOTOR_Multi_Data(&Adjust_ManualDate,0x01);

}
void Manual::ChangeYCurrentPostion(QString str)
{

    ui->lineEdit_ManualY->setText(str);
    Adjust_ManualDate.data[1].Data = str.toInt();
    Write_MOTOR_Multi_Data(&Adjust_ManualDate,0x02);
}
void Manual::ChangeRCurrentPostion(QString str)
{
    ui->lineEdit_ManualR->setText(str);
    Adjust_ManualDate.data[1].Data = str.toInt();
    Write_MOTOR_Multi_Data(&Adjust_ManualDate,0x03);
}


void Manual::on_pushButton_B6_7_clicked()
{
    if(~ManualVisiableFlag)
    {
        ui->frame_State->setVisible(true);
    }
    else
    {
        ui->frame_State->setVisible(false);
    }
     ManualVisiableFlag = ~ManualVisiableFlag;

}




void Manual::on_toolButton_YReferencePoint_clicked()
{
    YReferencePoint yrp;
    yrp.setWindowFlags(Qt::FramelessWindowHint);
    yrp.exec();

}

