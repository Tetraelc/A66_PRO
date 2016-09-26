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
#include "mainwindow.h"
#include "systemwarn.h"

extern bool stopped;
extern QString ReturnMotorValue;

extern int XMotorStatusWord,YMotorStatusWord;
extern int MotorXDisplayFalg,MotorYDisplayFalg,MotorRDisplayFalg;
extern int MotorXDisplayValue,MotorYDisplayValue;

int ManualVisiableFlag = 0;
int ManualOpenMTFlag = 0;


int time_count = 0;
int status_set = 0;
int time_count1 = 0;

static int step = 0;
long last_pos[3] = {0};

double Dis_XPos = 0.0;
double Dis_YPos = 0.0;
double Dis_RPos = 0.0;


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

    QFont font;
    font.setPointSize(28);
    ui->lineEdit_ManualX->setFont(font);
    ui->lineEdit_ManualY->setFont(font);
    ui->lineEdit_ManualR->setFont(font);

    Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,ENTER_DISENABLE);



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
    SystemSetting sys;
    sys.ReadForSystemDat();
    CheckRaxisEnable();

//    if(XaxisParameter.ReferencePosMode > 0 && YaxisParameter.ReferencePosMode > 0)
//    {
//        ui->pushButton_Adjust->setEnabled(false);
//    }
//    else
//    {
//        ui->pushButton_Adjust->setEnabled(true);
//    }

    ui->toolButton_OpenMT->setText(trUtf8("液压轴关闭"));
    Write_MOTOR_Multi_Data(&Write_MTDisEnable_buf,0x04);
    ManualMTFlag =true;
    ManualOpenMTFlag = 0;
    //PumpSignalFlag = true;

    qDebug()<<"openManualWin";
}


void Manual::CheckRaxisEnable()
{
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        ui->lineEdit_ManualR->setVisible(true); //R轴可视
        ui->pushButton_M_RForWard->setVisible(true);
        ui->label_RMan->setVisible(true);
        ui->pushButton_M_RBack->setVisible(true);
        ui->toolButton_R->setVisible(true);

        ui->pushButton_M_XBack->move(130,40);
        ui->toolButton_X->move(250,50);
        ui->label_XMan->move(305,50);
        ui->lineEdit_ManualX->move(350,40);
        ui->pushButton_M_XForWard->move(590,40);

        ui->pushButton_M_YBack->move(130,150);
        ui->toolButton_Y->move(250,160);
        ui->label_YMan->move(305,160);
        ui->lineEdit_ManualY->move(350,150);
        ui->pushButton_M_YForWard->move(590,150);

        ui->pushButton_M_RBack->move(130,260);
        ui->toolButton_R->move(250,270);
        ui->label_RMan->move(305,270);
        ui->lineEdit_ManualR->move(350,260);
        ui->pushButton_M_RForWard->move(590,260);

    }
    else
    {
        ui->lineEdit_ManualR->setVisible(false); //R轴bu可视
        ui->pushButton_M_RForWard->setVisible(false);
        ui->pushButton_M_RBack->setVisible(false);
        ui->toolButton_R->setVisible(false);
        ui->label_RMan->setVisible(false);

        ui->pushButton_M_XBack->move(130,100);
        ui->toolButton_X->move(250,110);
        ui->label_XMan->move(305,110);
        ui->lineEdit_ManualX->move(350,100);
        ui->pushButton_M_XForWard->move(590,100);

        ui->pushButton_M_YBack->move(130,220);
        ui->toolButton_Y->move(250,230);
        ui->label_YMan->move(305,230);
        ui->lineEdit_ManualY->move(350,220);
        ui->pushButton_M_YForWard->move(590,220);

    }

}


void Manual::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()==id1){

      timerForCan();

    }
    if(t->timerId()==id1){

//        if(MotorXDisplayFalg == 1)
//        {

            Dis_XPos = Get_MOTOR_Demand_Postion(0x01) * XaxisParameter.LeadScrew /1000;
            Dis_YPos = Get_MOTOR_Demand_Postion(0x02) * YaxisParameter.LeadScrew /1000;


           ui->lineEdit_ManualX->setText(QString::number(Dis_XPos,'.',2));
//        }
//        if(MotorYDisplayFalg == 1)
//        {
           ui->lineEdit_ManualY->setText(QString::number(Dis_YPos,'.',2));
//        }
//        if(MotorRDisplayFalg == 1)
//        {
           if(RaxisParameter.ENABLE_AXIS == 1)
           {
                Dis_RPos =Get_MOTOR_Demand_Postion(0x03) * RaxisParameter.LeadScrew /1000;
               ui->lineEdit_ManualR->setText(QString::number(Dis_RPos,'.',2));
           }

//        }

    }
    if(t->timerId()==id2){
        CurrentReg.Current_MotorTipResult.clear();
        Checkstatus(0x01);
        Checkstatus(0x02);
        Checkstatus(0x03);

        checkMotorState();


//        MotorTipFlag = true;
//        CurrentReg.Current_MotorTips = MotorErrorTip;
//        CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));


    }
    if(t->timerId()==id3){

        CheckINState();
        CheckRunState();
        CheckOutState();
       // qDebug()<<"ManualMTFlag"<<ManualMTFlag;

//        if( ManualMTFlag == true)
//            if(A20_IN_Status & CUTSMODE)
//             {
//                ui->toolButton_OpenMT->setText(trUtf8("液压轴关闭"));
//                ui->toolButton_OpenMT->setEnabled(false);
//                Write_MOTOR_Multi_Data(&Write_MTDisEnable_buf,0x04);
//             }
//            else if(A20_IN_Status & CUTCMODE)
//            {
//                 ui->toolButton_OpenMT->setText(trUtf8("液压轴关闭"));
//                 ui->toolButton_OpenMT->setEnabled(false);
//                 Write_MOTOR_Multi_Data(&Write_MTDisEnable_buf,0x04);
//            }
//            else if((A20_IN_Status & CUTJMODE) == 0)
//            {
//                 ui->toolButton_OpenMT->setText(trUtf8("液压轴启动"));
//                ui->toolButton_OpenMT->setEnabled(true);
//                Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0x40);
//            }


    }


}

void Manual::checkMotorState()
{
     CurrentReg.Current_MotorTipResult.clear();

     if(Get_HeartbetError(0x01) == 0x01 || motor[X1_ID-1].initStatus == 0 || XFaultFlag ==true)
     {

         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = Motor1Tip;
         CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("1号电机离线"));

        // qDebug("Motor1");
     }
     if(Get_HeartbetError(0x02) == 0x01 || motor[Y1_ID-1].initStatus == 0 || YFaultFlag ==true)
     {
         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = Motor2Tip;
         CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("2号电机离线"));
           // qDebug("Motor2");
     }
     if(Get_HeartbetError(0x04) == 0x01)
     {
         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = MTTip;
         CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("MT离线"));
        //qDebug("Motor4");
     }
     if(RaxisParameter.ENABLE_AXIS == 1)
     {
         if(Get_HeartbetError(0x03) == 1 || motor[R1_ID-1].initStatus == 0 || RFaultFlag ==true)
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = Motor3Tip;
             CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
    //         QMessageBox::critical(0,QObject::trUtf8("异常"),
    //                               trUtf8("3号电机离线"));
            //qDebug("Motor3");
         }

         if( (XFaultFlag ==true) ||  (YFaultFlag ==true) || (RFaultFlag ==true))
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = MotorErrorTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
             XFaultFlag =false;
             YFaultFlag =false;
             RFaultFlag =false;
         }
         if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) || (Get_HeartbetError(0x03) == 0x01)  ||  (Get_HeartbetError(0x04) == 0x01) )//||  (Get_HeartbetError(0x03) == 0x01)
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = OfflineTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
         }


     }
     else
     {
         if( (XFaultFlag ==true) ||  (YFaultFlag ==true) )
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = MotorErrorTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
             XFaultFlag =false;
             YFaultFlag =false;
         }
         if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) ||  (Get_HeartbetError(0x04) == 0x01) )//
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = OfflineTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
         }
     }



}
int Manual::CheckRunState()
{
    switch(A20_Run_Status)
    {
    case VFast:
         ui->label_RunState->setText(trUtf8("快下"));break;
    case VSlow :
        ui->label_RunState->setText(trUtf8("工进"));break;
    case  Vkeep  :
        ui->label_RunState->setText(trUtf8("保压"));break;
    case Vunload :
        ui->label_RunState->setText(trUtf8("卸荷"));break;
    case Vback   :
        ui->label_RunState->setText(trUtf8("回程"));break;
    case Vstop  :
        ui->label_RunState->setText(trUtf8("停止"));break;
    default:
        ui->label_RunState->setText(trUtf8("未知状态"));break;
    }

}

int Manual::CheckINState()
{
    if(A20_IN_Status & DownPoint)
    ui->label_IN1->setEnabled(true);
    else
    ui->label_IN1->setEnabled(false);
    if(A20_IN_Status & UpperPoint)
    ui->label_IN2->setEnabled(true);
    else
    ui->label_IN2->setEnabled(false);
    if(A20_IN_Status & FootUp)
    ui->label_IN3->setEnabled(true);
    else
    ui->label_IN3->setEnabled(false);
    if(A20_IN_Status & FootStart)
     ui->label_IN4->setEnabled(true);
    else
    ui->label_IN4->setEnabled(false);
    if(A20_IN_Status & PumpSignal)
    ui->label_IN5->setEnabled(true);
    else
    ui->label_IN5->setEnabled(false);
    if(A20_IN_Status & CUTSMODE)
    ui->label_IN6->setEnabled(true);
    else
    ui->label_IN6->setEnabled(false);
    if(A20_IN_Status & CUTCMODE)
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
//            motor[motor_id-1].Error_Mode = 1;

            XFaultFlag =true;
        }
        if(motor_id == 0x02 )
        {
//            QMessageBox::critical(0,QObject::trUtf8("异常"),
//                                  trUtf8("请检查电机"));break;

            YFaultFlag =true;
        }

        if(RaxisParameter.ENABLE_AXIS == 1)
        {
            if(motor_id == 0x03 )
            {
    //            QMessageBox::critical(0,QObject::trUtf8("异常"),
    //                                  trUtf8("请检查电机"));break;

           RFaultFlag =true;
            }
        }


//        CurrentReg.Current_MotorConfigResult.clear();


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

    return status;
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

    if((A20_IN_Status & UpperPoint))
    {
    MotorXDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;

     unsigned long XManualSpeed_temp = XaxisParameter.ManualSpeed;
     long XLeadScrew_temp =10000*1000/ XaxisParameter.LeadScrew;

    if(XaxisParameter.MotorDirection == 1)
    {
        if(Dis_XPos < XaxisParameter.MinDistance)
        {

        }
        else
        {
          //  Set_Motor_Speed_Mode(X1_ID,- 1 * XManualSpeed_temp*10);
            Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp*10,-1 * XLeadScrew_temp);
        }
    }
    else
    {
        if(Dis_XPos > XaxisParameter.MaxDistance )
        {
        }
        else
        {
           // Set_Motor_Speed_Mode(X1_ID,XManualSpeed_temp*10);
            Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp*10,1 * XLeadScrew_temp);
        }
    }
    }
    else
    {


        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
        qDebug()<<"CurrentReg.Current_MotorConfigResult"<<CurrentReg.Current_MotorConfigResult;
//        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        aralmOrTipFalg = true;
//        SystemWarn warn;
//        warn.setWindowFlags(Qt::FramelessWindowHint);
//        warn.exec();

    }

   // qDebug()<<"XaxisParameter.ManualSpeed"<<XaxisParameter.ManualSpeed;
}

void Manual::on_pushButton_M_XBack_released()
{
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
//        ThreadX.stop();
     Stop_MOTOR(0x01);
     MotorXDisplayFalg=0;
     XStopFalg = true;

//     RunState rs;
//     rs.SaveCurrentAxisDat(X1_ID);
}
void Manual::on_pushButton_M_XForWard_pressed()
{

    if((A20_IN_Status & UpperPoint))
    {
    MotorXDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    unsigned long XManualSpeed_temp = XaxisParameter.ManualSpeed;
    long XLeadScrew_temp = 10000*1000/XaxisParameter.LeadScrew;



    if(XaxisParameter.MotorDirection == 1)
    {
        qDebug()<<"---"<<Dis_XPos<<XaxisParameter.MaxDistance;
        if(Dis_XPos > XaxisParameter.MaxDistance )
        {

        }
        else
        {
          //  Set_Motor_Speed_Mode(X1_ID,XManualSpeed_temp*10);
            Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp*10,XLeadScrew_temp);
        }
    }
    else
    {
        if(Dis_XPos < XaxisParameter.MinDistance)
        {

        }
        else
        {
            //Set_Motor_Speed_Mode(X1_ID,-1 * XManualSpeed_temp*10);
            Set_Motor_Speed_Postion_Rel(0x01,XManualSpeed_temp*10,-1*XLeadScrew_temp);
        }
    }
    }
    else
    {
        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
//        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        aralmOrTipFalg = true;
//        SystemWarn warn;
//        warn.setWindowFlags(Qt::FramelessWindowHint);
//        warn.exec();
    }

}

void Manual::on_pushButton_M_XForWard_released()
{
    //ThreadX.stop();
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
    //Set_Motor_Speed_Postion_Rel(0x01,0,0);
    Stop_MOTOR(0x01);
    // ui->lineEdit_ManualX->setText(QString::number(MotorXDisplayValue,10));
     MotorXDisplayFalg=0;
       XStopFalg = true;
//     RunState rs;
//     rs.SaveCurrentAxisDat(X1_ID);

}

void Manual::on_pushButton_M_YBack_pressed()
{

    if((A20_IN_Status & UpperPoint))
    {
    MotorYDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    unsigned long YManualSpeed_temp = YaxisParameter.ManualSpeed;
     long YLeadScrew_temp = 10000*1000/YaxisParameter.LeadScrew;


     if(YaxisParameter.MotorDirection == 1)
     {
         if(Dis_YPos < YaxisParameter.MinDistance)
         {

         }
         else
         {
             //Set_Motor_Speed_Mode(Y1_ID,-1 * YManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp*10,-1 * YLeadScrew_temp);
         }
     }
     else
     {
         if(Dis_YPos > YaxisParameter.MaxDistance )
         {
         }
         else
         {
              //Set_Motor_Speed_Mode(Y1_ID,YManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp*10,1 * YLeadScrew_temp);
         }
     }
    }
    else
    {
        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
        qDebug()<<"CurrentReg.Current_MotorConfigResult"<<CurrentReg.Current_MotorConfigResult;
//        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        aralmOrTipFalg = true;
//        SystemWarn warn;
//        warn.setWindowFlags(Qt::FramelessWindowHint);
//        warn.exec();

    }

}

void Manual::on_pushButton_M_YBack_released()
{
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
    //Set_Motor_Speed_Postion(0x02,0,0);
//    ThreadX.stop();
    Stop_MOTOR(0x02);
    MotorYDisplayFalg=0;
    YStopFalg = true;
//    RunState rs;
//    rs.SaveCurrentAxisDat(Y1_ID);
}


void Manual::on_pushButton_M_YForWard_pressed()
{


    if(A20_IN_Status & UpperPoint)
    {
    MotorYDisplayFalg=1;
//    ThreadX.start();
//    stopped=false;
    unsigned long YManualSpeed_temp = YaxisParameter.ManualSpeed;
     long YLeadScrew_temp = 10000*1000/YaxisParameter.LeadScrew;

     if(YaxisParameter.MotorDirection == 1)
     {
         if(Dis_YPos > YaxisParameter.MaxDistance )
         {

         }
         else
         {
              //Set_Motor_Speed_Mode(Y1_ID,YManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp*10,YLeadScrew_temp);
         }
     }
     else
     {
         if(Dis_YPos < YaxisParameter.MinDistance)
         {

         }
         else
         {
             //Set_Motor_Speed_Mode(Y1_ID,-1 * YManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x02,YManualSpeed_temp*10,-1*YLeadScrew_temp);
         }
     }
    }else
    {
//        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        aralmOrTipFalg = true;
//        SystemWarn warn;
//        warn.setWindowFlags(Qt::FramelessWindowHint);
//        warn.exec();

        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
    }
}

void Manual::on_pushButton_M_YForWard_released()
{
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
    Stop_MOTOR(0x02);
    //Set_Motor_Speed_Postion(0x02,0,0);
//    ThreadX.stop();
      YStopFalg = true;
    MotorYDisplayFalg=0;
//    RunState rs;
//    rs.SaveCurrentAxisDat(Y1_ID);


}


void Manual::on_pushButton_M_RForWard_pressed()
{   

    if(A20_IN_Status & UpperPoint)
    {
     MotorRDisplayFalg=1;

     unsigned long RManualSpeed_temp = RaxisParameter.ManualSpeed;
     unsigned long RLeadScrew_temp = 10000*1000/RaxisParameter.LeadScrew;


     if(RaxisParameter.MotorDirection == 1)
     {
         if(Dis_RPos > RaxisParameter.MaxDistance )
         {

         }
         else
         {
             //Set_Motor_Speed_Mode(R1_ID,RManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp*10,RLeadScrew_temp);
         }
     }
     else
     {
         if(Dis_RPos < RaxisParameter.MinDistance)
         {

         }
         else
         {
             //Set_Motor_Speed_Mode(R1_ID,-1 * RManualSpeed_temp*10);
             Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp*10,-1*RLeadScrew_temp);
         }
     }
    }
    else
    {

        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
    }
}

void Manual::on_pushButton_M_RForWard_released()
{
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
     Stop_MOTOR(0x03);
     MotorRDisplayFalg=0;
       RStopFalg = true;
//     RunState rs;
//     rs.SaveCurrentAxisDat(R1_ID);
}

void Manual::on_pushButton_M_RBack_pressed()
{   
    if((A20_IN_Status & UpperPoint))
    {
        MotorRDisplayFalg=1;
        unsigned long RManualSpeed_temp = RaxisParameter.ManualSpeed;
        unsigned long RLeadScrew_temp = 10000*1000/RaxisParameter.LeadScrew;
        if(RaxisParameter.MotorDirection == 1)
        {
            if(Dis_RPos < RaxisParameter.MinDistance)
            {
            }
            else
            {
                //Set_Motor_Speed_Mode(R1_ID,-1 * RManualSpeed_temp*10);
                Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp*10,-1 * RLeadScrew_temp);
            }
        }
        else
        {
            if(Dis_RPos > RaxisParameter.MaxDistance)
            {
            }
            else
            {
                //Set_Motor_Speed_Mode(R1_ID,RManualSpeed_temp*10);
                Set_Motor_Speed_Postion_Rel(0x03,RManualSpeed_temp*10,1 * RLeadScrew_temp);
            }
        }
    }
    else
    {
//        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        aralmOrTipFalg = true;
//        SystemWarn warn;
//        warn.setWindowFlags(Qt::FramelessWindowHint);
//        warn.exec();
        MotorConfigTipFlag = true;
        CurrentReg.Current_MotorTips = FootUpTip;
        CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);


    }
}

void Manual::on_pushButton_M_RBack_released()
{
    volatile int i =0;
    for( i =0;i <10000;i++)
    {
        ;
    }
    Stop_MOTOR(0x03);
    MotorRDisplayFalg=0;
    RStopFalg = true;
//    RunState rs;
//    rs.SaveCurrentAxisDat(R1_ID);
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

    QPoint madPoint = QPoint(627, 90);
    mad.setWindowFlags(Qt::FramelessWindowHint);
    mad.move(madPoint);
    mad.exec();

}

void Manual::ChangeXCurrentPostion(QString str)
{
    bool ok;
    ui->lineEdit_ManualX->setText(str);

    qDebug()<<"--------"<<XaxisParameter.ReferencePos<<str.toDouble(&ok)<<Get_MOTOR_Demand_Postion(X1_ID) * XaxisParameter.LeadScrew /1000;
    XaxisParameter.ReferencePos  = XaxisParameter.ReferencePos* XaxisParameter.LeadScrew / 1000  + str.toDouble(&ok)  -  Get_MOTOR_Demand_Postion(X1_ID) * XaxisParameter.LeadScrew /1000;
    QSqlQuery query;
    query.exec("UPDATE Setup SET Value =" + QString::number(XaxisParameter.ReferencePos,'.',2) + " WHERE ID =  10" );
    Adjust_ManualDate[0].data[2].Data = str.toDouble(&ok)* 1000/ XaxisParameter.LeadScrew ;
    Write_MOTOR_Multi_Data(&Adjust_ManualDate[0],0x01);

}
void Manual::ChangeYCurrentPostion(QString str)
{
    bool ok;
    ui->lineEdit_ManualY->setText(str);
    YaxisParameter.ReferencePos = YaxisParameter.ReferencePos * YaxisParameter.LeadScrew / 1000+ str.toDouble(&ok) -  Get_MOTOR_Demand_Postion(Y1_ID) * YaxisParameter.LeadScrew /1000;
    QSqlQuery query;
    query.exec("UPDATE Setup SET Value =" + QString::number(YaxisParameter.ReferencePos,'.',2) + " WHERE ID =  25" );
    Adjust_ManualDate[1].data[2].Data = str.toDouble(&ok) *1000 / YaxisParameter.LeadScrew ;
    Write_MOTOR_Multi_Data(&Adjust_ManualDate[1],0x02);
}
void Manual::ChangeRCurrentPostion(QString str)
{
    bool ok;
    ui->lineEdit_ManualR->setText(str);
    RaxisParameter.ReferencePos = RaxisParameter.ReferencePos * RaxisParameter.LeadScrew / 1000 + str.toDouble(&ok) -  Get_MOTOR_Demand_Postion(R1_ID) * RaxisParameter.LeadScrew /1000;
    QSqlQuery query;
    query.exec("UPDATE Setup SET Value =" + QString::number(RaxisParameter.ReferencePos,'.',2) + " WHERE ID =  40" );
    Adjust_ManualDate[2].data[2].Data = str.toDouble(&ok) *1000 / RaxisParameter.LeadScrew ;
    Write_MOTOR_Multi_Data(&Adjust_ManualDate[2],0x03);
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
    yrp.move(627, 90);
    yrp.exec();
}


void Manual::on_pushButton_B6_6_clicked()
{
    MainWindow mv;
    mv.MainWinState();
}

void Manual::on_toolButton_OpenMT_clicked()
{

    if(~ManualOpenMTFlag)
    {
//        ui->frame_State->setVisible(true);
        Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0x40);
//        Write_MOTOR_Multi_Data(&Write_MTEnable_buf,0x04);
        ui->toolButton_OpenMT->setText(trUtf8("液压轴启动"));
        ManualFlag = true;
    }
    else
    {
//        ui->frame_State->setVisible(false);
        Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0xa0);
        //        Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0x00);
              //  Write_MOTOR_Multi_Data(&Write_MTDisEnable_buf,0x04);
                ui->toolButton_OpenMT->setText(trUtf8("液压轴关闭"));
                ManualFlag = false;
    }
     ManualOpenMTFlag = ~ManualOpenMTFlag;





//    static unsigned int Button_press_count = 0;
//    Button_press_count ++;
//    if(Button_press_count == 1)
//    {
////        Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,ENTER_ENABLE);

//    }
//    else if (Button_press_count == 2)
//    {


//        Button_press_count = 0;
//    }


}
