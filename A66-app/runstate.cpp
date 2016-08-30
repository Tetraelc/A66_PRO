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


int set_count =0;
int XaxisValue;
int YaxisValue;
int ChangeRowFlag =0;
int PostionReachFlag =0;
int concedeModeFlag = 1;
int VbackTime;
unsigned char Trg_Pos;
unsigned char Cont_Pos;
bool Back_state = false;
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


//    killTimer();

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

    CurrentReg.Current_MotorTips = RunTip;
    CurrentReg.Current_MotorTipResult = SystemTipsInformation(CurrentReg.Current_MotorTips);

    initWorkedTotalDialog();




   // Ms_Lable = startTimer(800);

    qDebug()<<"openRunStateWin";
}

void RunState::systemCheckSafrState()
{

    /*if()*///lianxian
        //A20shangzhidian
        //chushihua
        //
}

void RunState::ReturnRun()
{

  Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_RETURN);

}



void RunState::initWorkedTotalDialog()
{

//    if(!(A20_IN_Status & UpperPoint))
//    {
//        ReturnRun();
//        //CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        SystemWarn *warn = new SystemWarn;
//        warn->exec();

//        if(!(A20_IN_Status & UpperPoint))
//        {
//             emit openProgramwindow();
//             qDebug("openProgramwindow");
//        }


//    }
//    else
//    {

        CurrentRnuStateRow = 0;
        CurrentReg.Current_WorkedTotal =200;
        ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
        StopRun();
        set_count = 0;
        PostionReachFlag = 1;
        ChangeRowFlag =0 ;
        WrokedTotal *wk =new WrokedTotal;
        wk->exec();
        Ms_Run = startTimer(20);
        qDebug()<<" CurrentReg.Current_WorkedTotal.toInt()"<< CurrentReg.Current_WorkedTotal.toInt();
        qDebug()<<" CurrentReg.Current_WorkedTotal"<< CurrentReg.Current_WorkedTotal;
//    }

}

void RunState::checkMotorState()
{
    //qDebug()<<"Get_HeartbetError(0x01)"<<Get_HeartbetError(0x01);
     if(Get_HeartbetError(0x01) == 0x01)
     {
         QMessageBox::critical(0,QObject::trUtf8("异常"),
                               trUtf8("1号电机离线"));

     }
     if(Get_HeartbetError(0x02) == 0x01)
     {
         QMessageBox::critical(0,QObject::trUtf8("异常"),
                               trUtf8("2号电机离线"));

     }

//     if(Get_HeartbetError(0x03) == 1)
//     {
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("3号电机离线"));
//          Clean_HeartbetError(0x02);
//     }

     if(Get_HeartbetError(0x04) == 0x01)
     {
         QMessageBox::critical(0,QObject::trUtf8("异常"),
                               trUtf8("MT离线"));
     }


     if(motor[0].initStatus == 0)
     {
         QMessageBox::critical(0,QObject::trUtf8("异常"),
                               trUtf8("1号电机未初始化！要重新打开电机"));
     }
     if(motor[1].initStatus == 0)
     {
         QMessageBox::critical(0,QObject::trUtf8("异常"),
                               trUtf8("2号电机未初始化！要重新打开电机"));
     }
//     if(motor[2].initStatus == 0)
//     {
//         QMessageBox::critical(0,QObject::trUtf8("异常"),
//                               trUtf8("3号电机未初始化！要重新打开电机"));
//     }


}



void RunState::MotorRun()
{
//#define CUTSMODE			0x08//µ¥ŽÎÄ£Êœ  IN4
//#define CUTCMODE			0x04//Á¬ÐøÄ£Êœ  IN3
//#define CUTJMODE
    ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
    ui->label_ProgramName->setText(CurrentProgramTemp.ProgramName);
    ui->label_CurrentStep->setText( QString::number(CurrentRnuStateRow + 1,'.',0) + "/" +  QString::number(CurrentProgramTemp.StepNumber,'.',0));
    ui->label_WorkedTotal->setText(QString::number(CurrentRnuStateWorkedTotal,'.',0) + "/" + CurrentReg.Current_WorkedTotal );

    if(A20_IN_Status & CUTSMODE)
     {
        ui->toolButton_Mode->setText(trUtf8("连续"));
     }
    else if(A20_IN_Status & CUTCMODE)
    {
         ui->toolButton_Mode->setText(trUtf8("单次"));
    }
    else if(A20_IN_Status & CUTJMODE)
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
    if(CurrentRnuStateWorkedTotal == CurrentReg.Current_WorkedTotal.toInt())
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
void RunState::SendMTEnableSignal()
{
    int temp1,temp2;
    XaxisValue = CurrentStepTemp.Xaxis;
    YaxisValue = CurrentStepTemp.Yaxis;

   if(set_count==0)
   {
       qDebug("-------------------------------------------------------------------------------------------------");

       qDebug()<<"XaxisValue"<<XaxisValue;
       qDebug()<<"YaxisValue"<<YaxisValue;
       Set_Motor_Speed_Postion_Abs(0x02,5000,YaxisValue);
       Set_Motor_Speed_Postion_Abs(0x01,5000,XaxisValue);
       ui->label_Run->setText(trUtf8("定位"));

       ChangeRowFlag = 1;

   }
  set_count++;
  wait_pos_time++;
  temp1 = MOTOR_STATUS[0] & 0x400;
  temp2 = MOTOR_STATUS[1] & 0x400;

   if(wait_pos_time >200)
   {
       if((temp1 == 0x400) && (temp2 == 0x400) &&  PostionReachFlag == 1)
       {
          // ReadTrg(0x00);
           Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_ENABLE);
           ui->label_Run->setText(trUtf8("就绪"));
           PostionReachFlag=0;
           wait_pos_time   = 0;
       }
   }
//   else
//   {
//       ReadTrg(0x01);
//   }

//   if(Trg_Pos ==0x01 && Cont_Pos == 0x01)// diyici anxia
//   {
//         PostionReachFlag = 1;
//   }

//   if(PostionReachFlag == 1)
//   {
//       if(Trg_Pos ==0x0 && Cont_Pos == 0x0)
//       {
//            Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,0xAA);
//            PostionReachFlag = 0;
//       }
//   }


   if((A20_IN_Status & UpperPoint) && Back_state)
   {
       Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_DISENABLE);
       Back_state = false;
       PostionReachFlag =1;
       concedeModeFlag = 1;
       if(ChangeRowFlag == 1)
       {
           CurrentRnuStateRow++;

           ui->tableWidget_Run->selectRow(ui->tableWidget_Run->currentRow()+1);

          if(CurrentRnuStateRow == CurrentProgramTemp.StepNumber )
          {
              CurrentRnuStateRow=0;
              CurrentRnuStateWorkedTotal ++ ;
          }
            set_count = 0;
       }
       ChangeRowFlag = 0;

  }


}


int RunState::concedeState()
{
//    if(concedeModeFlag == 1)
//    {
//        Set_Motor_Speed_Postion_Rel(0x01,1000,CurrentStepTemp.concedeDistance);
//        ui->label_Run->setText(trUtf8("退让"));
//        concedeModeFlag = 0;
//    }
}




int RunState::CheckPressureState()
{

    switch(A20_Run_Status)
    {
    case Vstop  :
        //qDebug("Vstop");
         ui->label_Pressure->setText(trUtf8("停止"));
         SendMTEnableSignal();

        break;
    case VFast:
        //qDebug("VFast");

        if(VbackTime > 10000 && fastmode == 1 )
        {
            //进行换步
            VbackTime = 0;
        }
         ui->label_Pressure->setText(trUtf8("快下"));break;

    case VSlow :
        // qDebug("VSlow");
        concedeState();
        ui->label_Pressure->setText(trUtf8("工进"));break;
    case  Vkeep  :
         //qDebug("Vkeep");
        ui->label_Pressure->setText(trUtf8("保压"));break;
    case Vunload :
         //qDebug("Vunload");

        ui->label_Pressure->setText(trUtf8("卸荷"));break;


    case Vback   :
         //qDebug("Vback");
            Back_state = true;
            VbackTime++;

            ui->label_Pressure->setText(trUtf8("回程"));break;

    }

}


void RunState::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()==Ms_Run){

      ui->lineEdit_XCurrentPos->setText(QString::number(Get_MOTOR_Demand_Postion(0x01),10));
      ui->lineEdit_YCurrentPos->setText(QString::number(Get_MOTOR_Demand_Postion(0x02),10));

      MotorRun();
      CheckPressureState();
      ReflashWorkedTotal();
    }


}

void RunState::ReadRunTable()
{
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Error"),
                              db.lastError().text());//打开数据库连接
    }

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
    db.close();//释放数据库

}

void RunState::initRunState()
{


}


void RunState::ReadForRun(int Type)
{
    qDebug()<<"Enter ReadForRun data base initial Window!"<<endl;
    bool ok;

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Error"),
                              db.lastError().text());//打开数据库连接
    }

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
              CurrentProgramTemp.UpMold = record.value("UpMold").toDouble(&ok);
              CurrentProgramTemp.LowerMold =  record.value("LowerMold").toDouble(&ok);
              CurrentProgramTemp.ProcessedNum = record.value("WorkedTotal").toDouble(&ok);
    //          qDebug()<<" CurrentProgramTemp.Material"<< CurrentProgramTemp.Material;
        //      qDebug()<<"record.value().toString()"<<record.value("Name").toString();
//              qDebug()<<"record.value().toString()"<<record.value("BoardThick").toString();
//              qDebug()<<"record.value().toString()"<<record.value("Material").toString();

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
              CurrentStepTemp.concedeDistance= record.value("Distance").toDouble(&ok);
              CurrentStepTemp.Pressure =  record.value("Pressure").toDouble(&ok);
              CurrentStepTemp.Holding = record.value("HoldiAng").toDouble(&ok);
              CurrentStepTemp.ReturnTime =  record.value("ReturnTime").toDouble(&ok);
              CurrentStepTemp.Raxis= record.value("Raxis").toDouble(&ok);
            //qDebug()<<"record.value().AngleCompensate()"<<record.value("AngleCompensate").toString();
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

           // qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }
    model.setTable("Materialdb");
    model.setFilter("ID = " + QString::number(CurrentProgramTemp.Material + 1 ,10));//
    qDebug()<<"CurrentProgramTemp.Material"<<CurrentProgramTemp.Material;

    // qDebug()<<"CurrentProgramTemp.Material"<<CurrentProgramTemp.Material.toStdString();
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
             CurrentMaterialTemp.StrengthFactor = record.value("StrengthFactor").toDouble(&ok);
             CurrentMaterialTemp.EMold = record.value("EMold").toDouble(&ok);
             qDebug()<<"record.value().StrengthFactor()"<<record.value("StrengthFactor").toString();
             qDebug()<<"record.value().EMold()"<<record.value("EMold").toString();
    }
    model.setTable("RunParameter");
    model.setFilter("ID = 1");
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
             CurrentStepTemp.Yzero = record.value("Yzero").toDouble(&ok);
       // qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

   // ui->tableWidget_UpMoulds->selectRow(0);
    db.close();//释放数据库

}

void RunState::QuitRunState()
{

    killTimer(Ms_Run);

    Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_QUIT_STOP);

    Programdb *prodb = new Programdb;
     connect(this, SIGNAL(ReturnworkedTotal(int )), prodb, SLOT(ReflashProgramWrokedNum(int )));
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

//    QSqlTableModel model;
//    model.setTable("ProgramLib");
//    model.setFilter("Name = " + CurrentReg.CurrentProgramName);
//    model.select();
//    if(model.rowCount() == 1)
//    {
//        QSqlRecord record = model.record(0);
//        record.setValue("WorkedTotal",QString::number(CurrentRnuStateWorkedTotal,10));
//        model.setRecord(0,record);
//        model.submitAll();
//    }
//    db.close();//释放数据库
    emit openProgramwindow();

    emit ReturnworkedTotal( CurrentRnuStateWorkedTotal);
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


void RunState::on_pushButton_Left_1_clicked()  //向上
{
    if((CurrentRnuStateRow > 0) && ( CurrentRnuStateRow < QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt()))
    {
        CurrentRnuStateRow--;
        if(CurrentRnuStateRow == CurrentProgramTemp.StepNumber )
        {
            CurrentRnuStateRow= 0;
        }
    }
}

void RunState::on_pushButton_Left_4_clicked() //向下
{
    qDebug()<<"QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt()"<<QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt();
  if((CurrentRnuStateRow >= 0) && ( CurrentRnuStateRow < QString::number( CurrentProgramTemp.StepNumber,'.',0).toInt()))
    {

       CurrentRnuStateRow++;
       if((CurrentRnuStateRow) == CurrentProgramTemp.StepNumber )
       {
           CurrentRnuStateRow= CurrentProgramTemp.StepNumber -1;
       }

  }
}
