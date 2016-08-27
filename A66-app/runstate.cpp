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


int set_count =0;
int XaxisValue;
int YaxisValue;
int ChangeRowFlag =0;
int PostionReachFlag =0;
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
    ReadForRun();
    CurrentRnuStateWorkedTotal=0;


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
    if(!(A20_IN_Status & UpperPoint))
    {
        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
//        SystemWarn *warn = new SystemWarn;
//        warn->exec();

        if(!(A20_IN_Status & UpperPoint))
        {
             emit openProgramwindow();
        }

    }
    else
    {
        WrokedTotal *wk =new WrokedTotal;
        wk->exec();
        CurrentRnuStateRow = 0;
        CurrentReg.Current_WorkedTotal =200;
        ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
        StopRun();
        set_count = 0;
        PostionReachFlag = 1;
        ChangeRowFlag =0 ;

        Ms_Run = startTimer(20);
    }

}



void RunState::MotorRun()
{

    ui->tableWidget_Run->selectRow(CurrentRnuStateRow);
    ui->label_ProgramName->setText(CurrentProgramTemp.ProgramName);

    ui->label_CurrentStep->setText( QString::number(CurrentRnuStateRow + 1,'.',0) + "/" +  QString::number(CurrentProgramTemp.StepNumber,'.',0));

    ui->label_WorkedTotal->setText(QString::number(CurrentRnuStateWorkedTotal,'.',0) + "/" + CurrentReg.Current_WorkedTotal );

   //qDebug()<<"Get_HeartbetError(0x01)"<<Get_HeartbetError(0x01);
//    if(Get_HeartbetError(0x01) == 0x01)
//    {
//        QMessageBox::critical(0,QObject::trUtf8("异常"),
//                              trUtf8("1号电机离线"));

//    }
//    if(Get_HeartbetError(0x02) == 0x01)
//    {
//        QMessageBox::critical(0,QObject::trUtf8("异常"),
//                              trUtf8("2号电机离线"));

//    }

//    if(Get_HeartbetError(0x03) == 1)
//    {
//        QMessageBox::critical(0,QObject::trUtf8("异常"),
//                              trUtf8("3号电机离线"));
//         Clean_HeartbetError(0x02);
//    }

//    if(Get_HeartbetError(0x04) == 0x01)
//    {
//        QMessageBox::critical(0,QObject::trUtf8("异常"),
//                              trUtf8("MT离线"));
//    }

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

       Set_Motor_Speed_Postion_Abs(0x02,5000,YaxisValue);
       Set_Motor_Speed_Postion_Abs(0x01,5000,XaxisValue);

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
       Back_state = false;
       PostionReachFlag =1;
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
         ui->label_Pressure->setText(trUtf8("快下"));break;

    case VSlow :
        // qDebug("VSlow");
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
            Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,0x55);
            ui->label_Pressure->setText(trUtf8("回程"));break;

    }

}


void RunState::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()==Ms_Run){

      ui->lineEdit_XCurrentPos->setText(QString::number(Get_MOTOR_Demand_Postion(0x01),10));

      ui->lineEdit_YCurrentPos->setText(QString::number(Get_MOTOR_Demand_Postion(0x02),10));

 //     ReadForRun();

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
    qDebug()<<"Enter initRunState data base initial Window!"<<endl;
    for(int i=0;i<50;i++)
    {
      for(int j=0;j<10;j++)
      {
      ui->tableWidget_Run->setItem(i,j,new QTableWidgetItem(""));
      }
    }

   // ui->tableWidget_Run->setRowCount(Program[0].StepNumber);

    //ui->tableWidget_Run->selectRow(0);

//    for(ProgIndex=0;ProgIndex<ProgNameNum;ProgIndex++)
//    {
//        for(StepIndex=0;StepIndex<Program[ProgIndex].StepNumber;StepIndex++)
//        {
//          readSDataIntoTable();
//        }
//    }


}


void RunState::ReadForRun()
{
    qDebug()<<"Enter ReadForRun data base initial Window!"<<endl;
    bool ok;

//    CurrentStepTemp.Angle = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Angle)->text().toDouble(&ok);
//    CurrentStepTemp.AngleCompensate = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_AngleCompensate)->text().toDouble(&ok);
//    CurrentStepTemp.Yaxis = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Yaxis)->text().toDouble(&ok);
//    CurrentStepTemp.Xaxis = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Xaxis)->text().toDouble(&ok);
//    CurrentStepTemp.XaxisCorrect = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_XaxisCorrect)->text().toDouble(&ok);
//    CurrentStepTemp.Distance = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Distance)->text().toDouble(&ok);
//    CurrentStepTemp.Pressure = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Pressure)->text().toDouble(&ok);
//    CurrentStepTemp.ReturnTime = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_ReturnTime)->text().toDouble(&ok);
//    CurrentStepTemp.Holding = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_HoldingTime)->text().toDouble(&ok);
//    CurrentStepTemp.Raxis = ui->tableWidget_Run->item(ui->tableWidget_Run->currentRow(),StepProgram_Raxis)->text().toDouble(&ok);


//    CurrentProgramTemp.BroadThickA


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
              qDebug()<<" CurrentProgramTemp.Material"<< CurrentProgramTemp.Material;
              qDebug()<<"record.value().toString()"<<record.value("Name").toString();
//              qDebug()<<"record.value().toString()"<<record.value("BoardThick").toString();
//              qDebug()<<"record.value().toString()"<<record.value("Material").toString();

    }

    model.setTable(CurrentReg.CurrentProgramName);
    model.setFilter("ID =" + QString::number(CurrentReg.Current_StepProgramRow + 1, 10));
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
              CurrentStepTemp.Angle = record.value("Angle").toDouble(&ok);
              CurrentStepTemp.AngleCompensate = record.value("AngleCompensate").toDouble(&ok);
              CurrentStepTemp.Yaxis =  record.value("Yaxis").toDouble(&ok);
              CurrentStepTemp.Xaxis = record.value("Xaxis").toDouble(&ok);
              CurrentStepTemp.XaxisCorrect =  record.value("XaxisCorrect").toDouble(&ok);
              CurrentStepTemp.Distance= record.value("Distance").toDouble(&ok);
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
    model.setFilter("Name = " + QString::number(CurrentProgramTemp.Material + 1 ,10));//
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
   ReadForRun();
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
