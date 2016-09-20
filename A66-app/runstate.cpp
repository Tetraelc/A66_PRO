#include "runstate.h"
#include "ui_runstate.h"
#include <QDebug>
#include "global.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "programdb.h"
#include "mainwindow.h"
#include "wrokedtotal.h"
#include "systemwarn.h"
#include "mathcalculation.h"
#include <QMouseEvent>


unsigned char sendOneStep = 0;

double XaxisValue;
double YaxisValue;
double RaxisValue;
int ChangeRowFlag =0;
int PostionReachFlag =0;
int concedeModeFlag = 1;
int VbackTime;

unsigned char TrasmitError;
unsigned char Trg_Pos;
unsigned char Cont_Pos;
bool Back_state = false;
bool fastmodeState =false;
bool VFast_flag = false;

extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"
     #include "CanopenDictConfig.h"

RunState::RunState(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunState)
{
    ui->setupUi(this);
    initRunState();
    QFont font;
    font.setPointSize(28);
    ui->lineEdit_XCurrentPos->setFont(font);
    ui->lineEdit_YCurrentPos->setFont(font);
    ui->lineEdit_RCurrentPos->setFont(font);
    ui->tableWidget_Run->viewport()->installEventFilter(this);

    CheckRaxisEnable();
    ui->tableWidget_Run->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_Run->horizontalHeader()->setClickable(false);    //******NEW********//
    ui->tableWidget_Run->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}
bool RunState::eventFilter(QObject *watched, QEvent *event)
{
     if (watched==ui->tableWidget_Run->viewport())         //首先判断控件(这里指 lineEdit1)
     {
          if (event->type()==QEvent::MouseButtonPress)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }
          if (event->type()==QEvent::MouseButtonRelease)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }
          if (event->type()==QEvent::MouseMove)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }
          if (event->type()==QEvent::KeyPress)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }
          if (event->type()==QEvent::KeyRelease)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }
          if (event->type()==QEvent::MouseButtonDblClick)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
                 return true;
          }

     }
 return QWidget::eventFilter(watched,event);     // 最后将事件交给上层对话框
}
RunState::~RunState()
{
    delete ui;
}
void RunState::openRunStateWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);

    ReadRunTable();
    CurrentRnuStateRow =0;
    ReadForRun(CurrentRnuStateRow);
    CurrentRnuStateWorkedTotal=0;
    CheckRaxisEnable();
    initWorkedTotalDialog();



//    Adjust_ManualDate[0].data[1].Data = Get_MOTOR_Demand_Postion(0x01) / XaxisParameter.LeadScrew ;
//    Write_MOTOR_Multi_Data(&Adjust_ManualDate[0],0x01);

//    Adjust_ManualDate[1].data[1].Data = Get_MOTOR_Demand_Postion(0x02) / YaxisParameter.LeadScrew ;
//    Write_MOTOR_Multi_Data(&Adjust_ManualDate[1],0x02);

//    Adjust_ManualDate[2].data[1].Data = Get_MOTOR_Demand_Postion(0x03) / RaxisParameter.LeadScrew ;
//    Write_MOTOR_Multi_Data(&Adjust_ManualDate[2],0x03);


   // Ms_Lable = startTimer(800);

    qDebug()<<"openRunStateWin";
    VFast_flag = false;
    VbackTime = 0;
}

void RunState::systemCheckSafrState()
{

    /*if()*///lianxian
        //A20shangzhidian
        //chushihua
        //
}


void RunState::CheckRaxisEnable()
{
    if(RaxisParameter.ENABLE_AXIS == 1)
    {

        ui->lineEdit_RCurrentPos->setVisible(true);//R轴可视
        ui->label_RRun->setVisible(true);
        ui->toolButton_R->setVisible(true);

        ui->toolButton_X->move(30,20);
        ui->label_XRun->move(100,27);
        ui->lineEdit_XCurrentPos->move(170,20);

        ui->toolButton_Y->move(30,80);
        ui->label_YRun->move(100,88);
        ui->lineEdit_YCurrentPos->move(170,80);

        ui->toolButton_R->move(30,140);
        ui->label_RRun->move(100,147);
        ui->lineEdit_RCurrentPos->move(170,140);

        ui->tableWidget_Run->setColumnHidden(RunStep_Raxis,false);

    }
    else
    {
        ui->lineEdit_RCurrentPos->setVisible(false);//R轴bu可视
        ui->label_RRun->setVisible(false);
        ui->toolButton_R->setVisible(false);

        ui->toolButton_X->move(30,40);
        ui->label_XRun->move(100,48);
        ui->lineEdit_XCurrentPos->move(170,40);

        ui->toolButton_Y->move(30,120);
        ui->label_YRun->move(100,128);
        ui->lineEdit_YCurrentPos->move(170,120);

        ui->tableWidget_Run->setColumnHidden(RunStep_Raxis,true);
    }

}


void RunState::ReturnRun()
{

  Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_RETURN);

}



void RunState::initWorkedTotalDialog()
{
        CurrentRnuStateRow = 0;
        CurrentReg.Current_WorkedTotal =200;
        ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
        StopRun();
        sendOneStep = 0;
        PostionReachFlag = 1;
        ChangeRowFlag =0 ;
        motor[0].Wrte_Multi_Finsh_state = NO_SEND;
        motor[1].Wrte_Multi_Finsh_state = NO_SEND;
        motor[2].Wrte_Multi_Finsh_state = NO_SEND;
        motor[MT_ID-1].Write_One_Finsh_state = NO_SEND;
        WrokedTotal wk ;
        wk.setWindowFlags(Qt::FramelessWindowHint);
        wk.exec();
        qDebug("-----------------------------------------------------------------------------------");
        qDebug()<<"RunStateFlag"<<RunStateFlag;
        qDebug("-----------------------------------------------------------------------------------");

        Ms_Run = startTimer(20);




//    }

}

void RunState::checkMotorState()
{
     CurrentReg.Current_MotorTipResult.clear();
     if(Get_HeartbetError(0x01) == 0x01 || motor[X1_ID-1].initStatus == 0)
     {

         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = Motor1Tip;
         CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("1号电机离线"));

//         qDebug("Motor1");
     }
     if(Get_HeartbetError(0x02) == 0x01 || motor[Y1_ID-1].initStatus == 0)
     {
         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = Motor2Tip;
         CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("2号电机离线"));
//            qDebug("Motor2");
     }



     if(Get_HeartbetError(0x04) == 0x01)
     {
         MotorTipFlag = true;
         CurrentReg.Current_MotorTips = MTTip;
         CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("MT离线"));
  //      qDebug("Motor4");
     }

     if(RaxisParameter.ENABLE_AXIS == 1)
     {

         if(Get_HeartbetError(0x03) == 1 || motor[R1_ID-1].initStatus == 0)
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = Motor3Tip;
             CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
    //         QMessageBox::critical(0,QObject::trUtf8("异常"),
    //                               trUtf8("3号电机离线"));
    //        qDebug("Motor3");
         }
         if(Get_HeartbetError(0x01) == 0x01 || Get_HeartbetError(0x02) == 0x01 ||  Get_HeartbetError(0x03) == 0x01 ||  Get_HeartbetError(0x04) == 0x01 )
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = OfflineTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
             QuitRunState();

        //      qDebug("Motorclean");

         }
     }
     else
     {
         if(Get_HeartbetError(0x01) == 0x01 || Get_HeartbetError(0x02) == 0x01 ||   Get_HeartbetError(0x04) == 0x01 )
         {
             MotorTipFlag = true;
             CurrentReg.Current_MotorTips = OfflineTip;
             CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
             QuitRunState();

        //      qDebug("Motorclean");

         }


     }




}



void RunState::MotorRun()
{
    ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
    ui->label_ProgramName->setText(CurrentProgramTemp.ProgramName);
    ui->label_CurrentStep->setText( QString::number(CurrentRnuStateRow + 1,'.',0) + "/" +  QString::number(CurrentProgramTemp.StepNumber,'.',0));
    ui->label_WorkedTotal->setText(QString::number(CurrentRnuStateWorkedTotal,'.',0) + "/" + QString::number(CurrentReg.Current_WorkedTotal ,10));

    if(A20_IN_Status & CUTSMODE)
     {
        ui->toolButton_Mode->setText(trUtf8("连续"));
     }
    else if(A20_IN_Status & CUTCMODE)
    {
         ui->toolButton_Mode->setText(trUtf8("单次"));
    }
    else if((A20_IN_Status & CUTJMODE) == 0)
    {
        ui->toolButton_Mode->setText(trUtf8("点动")); //>????
    }
    else
    {
        ui->toolButton_Mode->setText(trUtf8("未知状态"));
    }

    checkMotorState();

}


void RunState::ReflashWorkedTotal()
{
    if(CurrentRnuStateWorkedTotal == CurrentReg.Current_WorkedTotal)
    {
         QuitRunState();
    }
}

void RunState::StopRun()
{

  Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_DISENABLE);

}

void RunState::ReadTrg( unsigned char pin )
{
    unsigned char ReadData = pin;
    Trg_Pos = ReadData & (ReadData ^ Cont_Pos);
    Cont_Pos = ReadData;
}

int wait_pos_time = 0;
///XY轴///////
void RunState::SendMTEnableSignalXYAxis()
{
    int temp1,temp2,temp3;
    XaxisValue = CurrentStepTemp.Xaxis;
    YaxisValue = CurrentStepTemp.Yaxis;
    RaxisValue = CurrentStepTemp.Raxis;

    temp1 = MOTOR_STATUS[0] & 0x400;
    temp2 = MOTOR_STATUS[1] & 0x400;
    temp3 = MOTOR_STATUS[2] & 0x400;
   if(sendOneStep == 0) //第一步发送数据  开始定位
   {
     //  qDebug()<<"CurrentStepTemp.Raxis"<<CurrentStepTemp.Raxis;
//       if(XaxisParameter.MotorDirection == 1)
//       {
           Set_Motor_Speed_Postion_Abs(0x01,XaxisParameter.RunSpeed,XaxisValue*1000/XaxisParameter.LeadScrew);
//       }
//       else
//       {
//           Set_Motor_Speed_Postion_Abs(0x01,XaxisParameter.RunSpeed,XaxisValue*-1000/XaxisParameter.LeadScrew);
//       }
//       if(YaxisParameter.MotorDirection == 1)
//       {
           Set_Motor_Speed_Postion_Abs(0x02,YaxisParameter.RunSpeed,YaxisValue*1000/YaxisParameter.LeadScrew);
//       }
//       else
//       {
//           Set_Motor_Speed_Postion_Abs(0x02,YaxisParameter.RunSpeed,YaxisValue*-1000/YaxisParameter.LeadScrew);
//       }

//           if(RaxisParameter.MotorDirection == 1)
//           {
//               Set_Motor_Speed_Postion_Abs(0x03,RaxisParameter.RunSpeed,RaxisValue*1000/RaxisParameter.LeadScrew);
//           }
//           else
//           {
//               Set_Motor_Speed_Postion_Abs(0x03,RaxisParameter.RunSpeed,RaxisValue*-1000/RaxisParameter.LeadScrew);
//           }


       ui->label_Run->setText(trUtf8("定位"));      
       sendOneStep = 1;
   }
   else if (sendOneStep == 1)//第二步等待定位完成  发送A20启动
   {

      if(motor[0].Wrte_Multi_Finsh_state == SUCCESS_SEND && motor[1].Wrte_Multi_Finsh_state == SUCCESS_SEND )//&& motor[2].Wrte_Multi_Finsh_state == SUCCESS_SEND
      {
          wait_pos_time++;
          if(wait_pos_time >20)
          {
              if((temp1 == 0x400) && (temp2 == 0x400)  && PostionReachFlag == 1)//&& (temp3 == 0x400)
              {

                  Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_ENABLE);
                  ui->label_Run->setText(trUtf8("就绪"));
                  MotorTipFlag =true;
                  CurrentReg.Current_MotorTips = PrepareTip;
                  CurrentReg.Current_MotorTipResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
                  PostionReachFlag = 0;
                  wait_pos_time   = 0;
                  motor[0].Wrte_Multi_Finsh_state = NO_SEND;
                  motor[1].Wrte_Multi_Finsh_state = NO_SEND;
                  motor[2].Wrte_Multi_Finsh_state = NO_SEND;
                  sendOneStep = 2;
                  ChangeRowFlag = 1;
               }
           }
       }
       else if(motor[0].Wrte_Multi_Finsh_state == FAIL_SEND || motor[1].Wrte_Multi_Finsh_state == FAIL_SEND )//|| motor[2].Wrte_Multi_Finsh_state == FAIL_SEND
       {
           TrasmitError++;
           //发送失败的处理
           motor[0].Wrte_Multi_Finsh_state = NO_SEND;
           motor[1].Wrte_Multi_Finsh_state = NO_SEND;
          // motor[2].Wrte_Multi_Finsh_state = NO_SEND;
           if(TrasmitError > 10)
           {
                TrasmitError = 0;
                sendOneStep = 0;//要考虑
                motor[0].SendCountError++;
                motor[1].SendCountError++;
               // motor[2].SendCountError++;
                //发送错误.要检查网络了做个显示
           }
           else
           {
              sendOneStep = 0;
           }
       }

   }
   else if (sendOneStep == 2 ) //等待A20到达上至点发送数据关闭命令||(fastmodeState == true))&&
   {
      if(((A20_IN_Status & UpperPoint)&&(Back_state == true))||(VbackTime > (MTParameter.VbackTime *50) && VFast_flag == true && MTParameter.VbackMode == 1))
       {
            Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,ENTER_DISENABLE);

            sendOneStep = 3;
       }
   }
   else if (sendOneStep == 3)//等待命令发送完成 ，进行换步
   {
      changeStep();
   }

}


///XYR轴///////
void RunState::SendMTEnableSignalXYRAxis()
{
    int temp1,temp2,temp3;
    XaxisValue = CurrentStepTemp.Xaxis;
    YaxisValue = CurrentStepTemp.Yaxis;
    RaxisValue = CurrentStepTemp.Raxis;

    temp1 = MOTOR_STATUS[0] & 0x400;
    temp2 = MOTOR_STATUS[1] & 0x400;
    temp3 = MOTOR_STATUS[2] & 0x400;
   if(sendOneStep == 0) //第一步发送数据  开始定位
   {
       qDebug()<<"CurrentStepTemp.Raxis"<<CurrentStepTemp.Raxis;
//       if(XaxisParameter.MotorDirection == 1)
//       {
           Set_Motor_Speed_Postion_Abs(0x01,XaxisParameter.RunSpeed,XaxisValue*1000/XaxisParameter.LeadScrew);
//       }
//       else
//       {
//           Set_Motor_Speed_Postion_Abs(0x01,XaxisParameter.RunSpeed,XaxisValue*-1000/XaxisParameter.LeadScrew);
//       }
//       if(YaxisParameter.MotorDirection == 1)
//       {
           Set_Motor_Speed_Postion_Abs(0x02,YaxisParameter.RunSpeed,YaxisValue*1000/YaxisParameter.LeadScrew);
//       }
//       else
//       {
//           Set_Motor_Speed_Postion_Abs(0x02,YaxisParameter.RunSpeed,YaxisValue*-1000/YaxisParameter.LeadScrew);
//       }

//       if(RaxisParameter.MotorDirection == 1)
//       {
           Set_Motor_Speed_Postion_Abs(0x03,RaxisParameter.RunSpeed,RaxisValue*1000/RaxisParameter.LeadScrew);
//       }
//       else
//       {
//           Set_Motor_Speed_Postion_Abs(0x03,RaxisParameter.RunSpeed,RaxisValue*-1000/RaxisParameter.LeadScrew);
//       }


       ui->label_Run->setText(trUtf8("定位"));
       sendOneStep = 1;
//       qDebug()<<"XaxisValue"<<XaxisValue;
//       qDebug()<<"YaxisValue"<<YaxisValue;
   }
   else if (sendOneStep == 1)//第二步等待定位完成  发送A20启动
   {

      if(motor[0].Wrte_Multi_Finsh_state == SUCCESS_SEND && motor[1].Wrte_Multi_Finsh_state == SUCCESS_SEND && motor[2].Wrte_Multi_Finsh_state == SUCCESS_SEND)
      {
          wait_pos_time++;
          if(wait_pos_time >20)
          {
              if((temp1 == 0x400) && (temp2 == 0x400)  && PostionReachFlag == 1 && (temp3 == 0x400))
              {

                  Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_ENABLE);
                  ui->label_Run->setText(trUtf8("就绪"));
                  MotorTipFlag =true;
                  CurrentReg.Current_MotorTips = PrepareTip;
                  CurrentReg.Current_MotorTipResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
                  PostionReachFlag = 0;
                  wait_pos_time   = 0;
                  motor[0].Wrte_Multi_Finsh_state = NO_SEND;
                  motor[1].Wrte_Multi_Finsh_state = NO_SEND;
                  motor[2].Wrte_Multi_Finsh_state = NO_SEND;
                  sendOneStep = 2;
                  ChangeRowFlag = 1;
               }
           }
       }
       else if(motor[0].Wrte_Multi_Finsh_state == FAIL_SEND || motor[1].Wrte_Multi_Finsh_state == FAIL_SEND || motor[2].Wrte_Multi_Finsh_state == FAIL_SEND)
       {
           TrasmitError++;
           //发送失败的处理
           motor[0].Wrte_Multi_Finsh_state = NO_SEND;
           motor[1].Wrte_Multi_Finsh_state = NO_SEND;
           motor[2].Wrte_Multi_Finsh_state = NO_SEND;
           if(TrasmitError > 10)
           {
                TrasmitError = 0;
                sendOneStep = 0;//要考虑
                motor[0].SendCountError++;
                motor[1].SendCountError++;
                motor[2].SendCountError++;
                //发送错误.要检查网络了做个显示
           }
           else
           {
              sendOneStep = 0;
           }
       }

   }
   else if (sendOneStep == 2) //等待A20到达上至点发送数据关闭命令||(fastmodeState == true))&&
   {
       if(((A20_IN_Status & UpperPoint)&&(Back_state == true))||(VbackTime > (MTParameter.VbackTime *50) && VFast_flag == true && MTParameter.VbackMode == 1))
       {
            Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,ENTER_DISENABLE);
            sendOneStep = 3;
       }
   }
   else if (sendOneStep == 3)//等待命令发送完成 ，进行换步
   {
      changeStep();
   }

}

/*******************************换步*************************/
void RunState::changeStep()
{
   if(motor[MT_ID-1].Write_One_Finsh_state == SUCCESS_SEND)
    {
        motor[MT_ID-1].Write_One_Finsh_state = NO_SEND;


        if(ChangeRowFlag == 1)
        {
             qDebug("CurrentRnuStateRow=%d",CurrentRnuStateRow);

            CurrentRnuStateRow++;

           // ui->tableWidget_Run->selectRow(ui->tableWidget_Run->currentRow()+1);

           if(CurrentRnuStateRow == CurrentProgramTemp.StepNumber )
           {
               CurrentRnuStateRow=0;
               CurrentRnuStateWorkedTotal ++ ;
           }
        }
           ChangeRowFlag = 0;
           sendOneStep = 0;
           Back_state = false;
           fastmodeState = false;
           PostionReachFlag =1;
           concedeModeFlag = 1;
           VbackTime = 0;
           VFast_flag = false;

    }
    else if (motor[MT_ID-1].Write_One_Finsh_state == FAIL_SEND)
    {
        motor[MT_ID-1].Write_One_Finsh_state = NO_SEND;
        if(TrasmitError > 3)
        {
             TrasmitError = 0;
             Back_state = false;
             PostionReachFlag =1;
             sendOneStep = 0;
             //发送停止错误.要检查网络了做个显示
        }
        else
        {
                 sendOneStep = 0;
        }

    }
}


int RunState::concedeState()
{
    if(concedeModeFlag == 1)
    {
        Set_Motor_Speed_Postion_Rel(0x01,1000,CurrentStepTemp.concedeDistance);
        ui->label_Run->setText(trUtf8("退让"));
        concedeModeFlag = 0;
        XStopFalg =true;
        YStopFalg =true;
        RStopFalg =true;
    }
}

int RunState::Checkstatus(int motor_id)
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
        MSG_USER(0x8000,"quick_stop_active",motor_id);  break;
    case Fault_reaction_active:   MSG_USER(0x8000,"Fault_reaction_active",motor_id);  break;
    case Fault:
        if(motor_id == 0x01 )
        {
//            QMessageBox::critical(0,QObject::trUtf8("异常"),
//                                  trUtf8("请检查电机"));break;
        }
        if(motor_id == 0x02 )
        {
//            QMessageBox::critical(0,QObject::trUtf8("异常"),
//                                  trUtf8("请检查电机"));break;
        }

    default:    MSG_USER(0x8000,"Invalid_data",motor_id);break;
    }
      temp1 = MOTOR_STATUS[0] & 0x400;
      temp2 = MOTOR_STATUS[1] & 0x400;
      temp3 = MOTOR_STATUS[2] & 0x400;
         if(temp1 == 0x400)
         {
            ui->toolButton_X->setEnabled(false);
         }
         else
         {
             ui->toolButton_X->setEnabled(true);
         }
         if(temp2 == 0x400)
         {
            ui->toolButton_Y->setEnabled(false);
         }
         else
         {
             ui->toolButton_Y->setEnabled(true);
         }
         if(temp3 == 0x400)
         {
            ui->toolButton_R->setEnabled(false);
         }
         else
         {
             ui->toolButton_R->setEnabled(true);
         }
    return status;
}


void RunState::SaveCurrentAxisDat(int Col)
{

    QSqlTableModel model;
    model.setTable("RunParameter");
    model.setFilter("ID =  1" );
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case X1_ID:record.setValue("XPostion",QString::number(Get_MOTOR_Demand_Postion(X1_ID) * XaxisParameter.LeadScrew /1000,'.',2));
            break;
        case Y1_ID:record.setValue("YPostion",QString::number(Get_MOTOR_Demand_Postion(Y1_ID) * YaxisParameter.LeadScrew /1000,'.',2));
            break;
        case R1_ID:record.setValue("RPostion",QString::number(Get_MOTOR_Demand_Postion(R1_ID) * RaxisParameter.LeadScrew /1000,'.',2));
            break;
        default :break;
        }

        model.setRecord(0,record);
        model.submitAll();
    }


}


int RunState::CheckPressureState()
{
    if((VbackTime > (MTParameter.VbackTime *50) && VFast_flag == true && MTParameter.VbackMode == 1))
    {
        if(RaxisParameter.ENABLE_AXIS == 0)
        {

           SendMTEnableSignalXYAxis();
        }
        else
        {
          SendMTEnableSignalXYRAxis();
        }     
        XStopFalg =true;
        YStopFalg =true;
        RStopFalg =true;
    }
    switch(A20_Run_Status)
    {
    case Vstop  :
         ui->label_Pressure->setText(trUtf8("停止"));
         if(MTParameter.VbackMode == 0)
         {
             if(RaxisParameter.ENABLE_AXIS == 0 )
             {
                SendMTEnableSignalXYAxis();
             }
             else
             {
               SendMTEnableSignalXYRAxis();
             }
             XStopFalg =true;
             YStopFalg =true;
             RStopFalg =true;
         }
        break;
    case VFast:
         ui->label_Pressure->setText(trUtf8("快下"));
         MotorTipFlag =true;
         CurrentReg.Current_MotorTips = RunTip;
         CurrentReg.Current_MotorTipResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
         if((VbackTime > (MTParameter.VbackTime *50) && MTParameter.VbackMode == 1))
            {
                 VFast_flag  = true;
            }
//         qDebug()<<"vbackTime"<<VbackTime;
//         qDebug()<<"sendOneStep"<<sendOneStep;
        break;
    case VSlow :
        ui->label_Pressure->setText(trUtf8("工进"));break;
    case  Vkeep  :
        concedeState();
        ui->label_Pressure->setText(trUtf8("保压"));break;
    case Vunload :
        ui->label_Pressure->setText(trUtf8("卸荷"));break;
    case Vback   :
            Back_state = true;
            VbackTime++;
            ui->label_Pressure->setText(trUtf8("回程"));break;
    }


}


void RunState::timerEvent(QTimerEvent *t) //定时器事件
{


    if(t->timerId()==Ms_Run){
    double Dis_XPos =Get_MOTOR_Demand_Postion(0x01) * XaxisParameter.LeadScrew /1000;
    double Dis_YPos =Get_MOTOR_Demand_Postion(0x02) * YaxisParameter.LeadScrew /1000;


      ui->lineEdit_XCurrentPos->setText(QString::number(Dis_XPos,'.',2));
      ui->lineEdit_YCurrentPos->setText(QString::number(Dis_YPos,'.',2));

      if(RaxisParameter.ENABLE_AXIS == 1)
      {
          double Dis_RPos =Get_MOTOR_Demand_Postion(0x03) * RaxisParameter.LeadScrew /1000;
          ui->lineEdit_RCurrentPos->setText(QString::number(Dis_RPos,'.',2));
      }
      MotorRun();

      qDebug()<<"RunStateFlag"<<RunStateFlag;
      if(RunStateFlag == true)
      {
          CheckPressureState();
      }

      ReflashWorkedTotal();
      Checkstatus(0x01);
      Checkstatus(0x02);
      Checkstatus(0x03);
    }


}

void RunState::ReadRunTable()
{
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable(CurrentReg.CurrentProgramName);
    //model.setFilter("ID > 0");
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_Run->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_Run->setRowCount(1);
        ui->tableWidget_Run->clear();
    }

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            //ui->tableWidget_Run->setItem(i,StepProgram_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_Angle,new QTableWidgetItem(record.value("Angle").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_AngleCompensate,new QTableWidgetItem(record.value("AngleCompensate").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_Yaxis,new QTableWidgetItem(record.value("Yaxis").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_Xaxis,new QTableWidgetItem(record.value("Xaxis").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_XaxisCorrect,new QTableWidgetItem(record.value("XaxisCorrect").toString()));
            //ui->tableWidget_Run->setItem(i,StepProgram_Distance,new QTableWidgetItem(record.value("Distance").toString()));
            //ui->tableWidget_Run->setItem(i,StepProgram_Pressure,new QTableWidgetItem(record.value("Pressure").toString()));
            //ui->tableWidget_Run->setItem(i,StepProgram_ReturnTime,new QTableWidgetItem(record.value("ReturnTime").toString()));
            //ui->tableWidget_Run->setItem(i,StepProgram_HoldingTime,new QTableWidgetItem(record.value("Holding").toString()));
            ui->tableWidget_Run->setItem(i,RunStep_Raxis,new QTableWidgetItem(record.value("Raxis").toString()));

           // qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

   // ui->tableWidget_UpMoulds->selectRow(0);
    //db.close();//释放数据库

}

void RunState::initRunState()
{


}


void RunState::ReadForRun(int Type)
{
    qDebug()<<"Enter ReadForRun data base initial Window!"<<endl;
    bool ok;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }
    QSqlTableModel model;
    model.setTable("ProgramLib");
    model.setFilter("ID =" +QString::number(CurrentReg.Current_ProgramLibRow + 1,10));
    model.select();

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
               CurrentProgramTemp.ProgramName=record.value("Name").toString();
               CurrentProgramTemp.BroadThick = record.value("BoardThick").toDouble(&ok);
               CurrentProgramTemp.BroadWideth = record.value("BoardWide").toDouble(&ok);
               CurrentProgramTemp.Material = record.value("Material").toInt();//QString::fromUtf8(
               CurrentProgramTemp.StepNumber =  record.value("StepTotal").toDouble(&ok);
               CurrentProgramTemp.UpMold     = record.value("UpMold").toDouble(&ok);
               CurrentProgramTemp.LowerMold =  record.value("LowerMold").toDouble(&ok);
               CurrentProgramTemp.ProcessedNum = record.value("WorkedTotal").toDouble(&ok);//P01.jpg
               CurrentReg.CurrentProgramPic = record.value("ProgramPro").toString();

    }

    model.setTable(CurrentReg.CurrentProgramName);
    model.setFilter("ID =" + QString::number( Type + 1, 10));//CurrentReg.Current_StepProgramRow
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
              CurrentStepTemp.Angle = record.value("Angle").toDouble(&ok);
              CurrentStepTemp.AngleCompensate = record.value("AngleCompensate").toDouble(&ok);
              CurrentStepTemp.Yaxis =  record.value("Yaxis").toDouble(&ok);
              CurrentStepTemp.Xaxis = record.value("Xaxis").toDouble(&ok);
              CurrentStepTemp.XaxisCorrect =  record.value("XaxisCorrect").toDouble(&ok);
              CurrentStepTemp.concedeDistance= record.value("Distance").toDouble(&ok) * 1000 / XaxisParameter.LeadScrew ;
              CurrentStepTemp.Pressure =  record.value("Pressure").toDouble(&ok);
              CurrentStepTemp.Holding = record.value("HoldiAng").toDouble(&ok);
              CurrentStepTemp.ReturnTime =  record.value("ReturnTime").toDouble(&ok);
              CurrentStepTemp.Raxis= record.value("Raxis").toDouble(&ok);
//              qDebug()<<"CurrentStepTemp.Raxis"<<CurrentStepTemp.Raxis;
    }

    model.setTable("UpMold");
    model.setFilter("ID =" + QString::number(CurrentProgramTemp.UpMold,'.',0));
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
              CurrentUpMoldTemp.Angle = record.value("Angle").toDouble(&ok);
              CurrentUpMoldTemp.Height = record.value("Height").toDouble(&ok);
              CurrentUpMoldTemp.Radius =  record.value("Radius").toDouble(&ok);
              CurrentUpMoldTemp.Impedance = record.value("Impedance").toDouble(&ok);

           // qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

    model.setTable("LowerMold");
    model.setFilter("ID =" + QString::number(CurrentProgramTemp.LowerMold,'.',0));
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
              CurrentLowerMoldTemp.Angle = record.value("Angle").toDouble(&ok);
              CurrentLowerMoldTemp.Height = record.value("Height").toDouble(&ok);
              CurrentLowerMoldTemp.Radius =  record.value("Radius").toDouble(&ok);
              CurrentLowerMoldTemp.Impedance = record.value("Impedance").toDouble(&ok);
              CurrentLowerMoldTemp.SpeedChangePos = record.value("SpeedPostion").toDouble(&ok);
              CurrentLowerMoldTemp.D_V =  record.value("D_V").toDouble(&ok);
              CurrentLowerMoldTemp.SpeedSafeDis = record.value("SpeedChange").toDouble(&ok);

          // qDebug()<<"record.value().toString()"<<record.value("D_V").toString();
    }
    model.setTable("Materialdb");
    model.setFilter("ID = " + QString::number(CurrentProgramTemp.Material + 1 ,10));//

    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
             CurrentMaterialTemp.StrengthFactor = record.value("StrengthFactor").toDouble(&ok);
             CurrentMaterialTemp.EMold = record.value("EMold").toDouble(&ok);
    }
    model.setTable("RunParameter");
    model.setFilter("ID = 1");
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
             CurrentStepTemp.Yzero = record.value("Yzero").toDouble(&ok);
             CurrentStepTemp.XPostion = record.value("XPostion").toDouble(&ok);
             CurrentStepTemp.YPostion= record.value("YPostion").toDouble(&ok);
             CurrentStepTemp.RPostion= record.value("RPostion").toDouble(&ok);
    }

   // ui->tableWidget_UpMoulds->selectRow(0);
    //db.close();//释放数据库

}

void RunState::QuitRunState()
{

    killTimer(Ms_Run);

    Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_QUIT_STOP);
    Stop_MOTOR(0x01);
    Stop_MOTOR(0x02);
    Stop_MOTOR(0x03);
    sendOneStep = 0;//状态清零
    VbackTime   = 0;
    VFast_flag = false;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("ProgramLib");
    model.setFilter("Name = " + CurrentReg.CurrentProgramName);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        record.setValue("WorkedTotal",QString::number(CurrentRnuStateWorkedTotal,10));
        model.setRecord(0,record);
        model.submitAll();
    }
//    //db.close();//释放数据库
    MotorTipFlag =true;
    CurrentReg.Current_MotorTips = RunFinishTip;
    CurrentReg.Current_MotorTipResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
    CurrentReg.Current_WorkedTotal = CurrentRnuStateWorkedTotal;


    emit ReturnworkedTotal(CurrentRnuStateWorkedTotal);
    emit openProgramwindow();
    openBeep();


   // CurrentRnuStateWorkedTotal = 0;

}



void RunState::on_pushButton_Left_5_clicked()
{
    QuitRunState();
}

void RunState::on_tableWidget_Run_itemSelectionChanged()
{
   //CurrentReg.Current_RunRow = ui->tableWidget_Run->currentRow();
   ReadForRun(CurrentRnuStateRow);
}



}


//void RunState::on_pushButton_Left_1_clicked()  //向上
//{

//    if((A20_IN_Status & UpperPoint))
//    {
//        if((CurrentRnuStateRow > 0) && ( CurrentRnuStateRow < QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt()))
//        {
//            CurrentRnuStateRow--;
//            if(CurrentRnuStateRow == CurrentProgramTemp.StepNumber )
//            {
//                CurrentRnuStateRow= 0;
//            }
//        }
//    }

//}

//void RunState::on_pushButton_Left_4_clicked() //向下
//{
//    if((A20_IN_Status & UpperPoint))
//    {
//        if((CurrentRnuStateRow >= 0) && ( CurrentRnuStateRow < QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt()))
//          {

//             CurrentRnuStateRow++;
//             if((CurrentRnuStateRow) == CurrentProgramTemp.StepNumber )
//             {
//                 CurrentRnuStateRow= CurrentProgramTemp.StepNumber -1;
//             }

//        }

//    }

//}


