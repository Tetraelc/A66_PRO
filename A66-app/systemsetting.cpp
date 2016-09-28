#include "systemsetting.h"
#include "ui_systemsetting.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "global.h"
#include "systemwarn.h"
int Write_Button_state = 0;
int Read_Button_state  = 0;
extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"
SystemSetting::SystemSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemSetting)
{
    ui->setupUi(this);



    Table_Editable_Flag = 0;
    ValveConfig_scan = startTimer(50);

    ui->treeWidget_System->expandAll(); //结点全部展开
//    ui->treeWidget_System->setCurrentItem();
//    ui->treeWidget_System->setCurrentIndex(0);

    ui->tableWidget_System->setColumnWidth(Table_Id,50);
    ui->tableWidget_System->setColumnWidth(Table_Name,100);
    ui->tableWidget_System->setColumnWidth(Table_Value,100);


    ui->tableWidget_System->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_System->horizontalHeader()->setClickable(false);    

//    QRegExp rx("^(-?[0]|-?[1-9][0-9]{0,3})$");
//    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    //ui->lineEdit_KeepTime ->setValidator(pReg);
    //ui->lineEdit_UnloadTime->setValidator(pReg);
    //ui->lineEdit_Secret->setValidator(pReg);

    ReadForSystemDat();


    Systemlanguage();



}


void SystemSetting::Systemlanguage()
{

    if(SYSParameter.Language == 0)
    {
       #if ARMFlag
        translator.load("/opt/tetra/A66-app/A66-app.ts");
       #else
        translator.load("/home/tetra/gitA66/A66-app/A66-app.ts");
       #endif
        qApp->installTranslator(&translator);
    }
    else
    {
    #if ARMFlag
     translator.load("/opt/tetra/A66-app/A66-app.qm");
    #else
        translator.load("/home/tetra/gitA66/A66-app/A66-app.qm");
    #endif
        qApp->installTranslator(&translator);
    }

}

void SystemSetting::TreeWidgetIntoTable()
{

    Table_Editable_Flag = 0;

    ReadForSystemDat();
    //Systemlanguage();

    if(ui->treeWidget_System->currentItem()->parent() != NULL)
    {
        if(ui->treeWidget_System->currentItem()->parent()->text(0).compare(trUtf8("通用")) == 0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            Display_Item(ui->treeWidget_System->currentIndex().row()+10,false,true);

//            if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("常量")) == 0 )
//            {
//                ui->stackedWidget->setCurrentIndex(0);
//                Display_Item(10,true);
//            }
//            if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("诊断")) == 0 )
//            {
//                ui->stackedWidget->setCurrentIndex(0);
//                Display_Item(11,true);
//            }

//           qDebug()<<"ui->tableWidget_System->item(2,2)->text()"<<ui->tableWidget_System->item(2,2)->text();

        }

        if(ui->treeWidget_System->currentItem()->parent()->text(0).compare(trUtf8("轴参数")) == 0)
        {
            ui->stackedWidget->setCurrentIndex(0);
           Display_Item(ui->treeWidget_System->currentIndex().row()+20,EditableFalg,false);
        }
        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("轴配置")) == 0 )
        {
           ui->stackedWidget->setCurrentIndex(0);
           Display_Item(Factory_Id,FactoryAxisFalg,true);
        }

        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("阀组配置")) == 0 )
        {
            ui->stackedWidget->setCurrentIndex(2);
            if(FactoryAxisFalg == true)
            {
                ui->pushButton_BackTest->setEnabled(true);
                ui->pushButton_FastTest->setEnabled(true);
                ui->pushButton_KeepTest->setEnabled(true);
                ui->pushButton_SlowTest->setEnabled(true);
                ui->pushButton_StopTest->setEnabled(true);
                ui->pushButton_UnloadTest->setEnabled(true);
                ui->toolButton_confirm->setEnabled(true);
            }
        }
        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("工厂设置")) == 0 )
        {
            ui->stackedWidget->setCurrentIndex(1);

            if(FactoryAxisFalg == true)
            {
                ui->toolButton_InitDAT->setEnabled(true);
                ui->toolButton_ResumeDAT->setEnabled(true);
                ui->toolButton_SaveDAT->setEnabled(true);
            }
        }



      // checktSecret();
    }


}

void SystemSetting::on_treeWidget_System_itemSelectionChanged()
{

    TreeWidgetIntoTable();


}


void SystemSetting::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()== ValveConfig_scan){

        deal_write_config_event();
        deal_read_config_event();


    }
}


void SystemSetting::checktSecret()
{

//    if(ui->treeWidget_System->currentItem()->parent() != NULL)
//    {

//        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("常量")) == 0 )
//        {
//            Display_Item(ui->treeWidget_System->currentIndex().row()+10,true);

//        }
//    }
}

void SystemSetting::TreeWidgetInit()
{

}


void SystemSetting::ReadForSystemDat()
{
    qDebug()<<"Enter ReadForSystem data base initial Window!"<<endl;
    bool ok;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }


    QSqlTableModel model;
    model.setTable("Setup");
    model.setFilter("Class = " NormalSYS_Id);
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            SystemParameterTemp[i] = record.value("Value").toInt();
    }

    model.setTable("Setup");
    model.setFilter("Class = " Xaxis_Id);
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            XaxisParameterTemp[i] = record.value("Value").toDouble(&ok);
    }
    model.setFilter("Class = " Yaxis_Id);
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            YaxisParameterTemp[i] = record.value("Value").toDouble(&ok);
    }
    model.setFilter("Class = " Raxis_Id);
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            RaxisParameterTemp[i] = record.value("Value").toDouble(&ok);
    }
    model.setFilter("Class = " MT_Id);
    model.select();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            MTParameterTemp[i] = record.value("Value").toDouble(&ok);

    }
    SystemDatChange();

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
    //db.close();//释放数据库
}

void SystemSetting::SystemDatChange()
{

    ////X轴参数
     SYSParameter.serialNumber = SystemParameterTemp[0];
     SYSParameter.Language = SystemParameterTemp[1];
     SYSParameter.Units = SystemParameterTemp[2];

     XaxisParameter.LeadScrew = XaxisParameterTemp[0];
     XaxisParameter.MotorDirection = XaxisParameterTemp[1];
     XaxisParameter.RunSpeed = XaxisParameterTemp[2] * 10;
     XaxisParameter.ManualSpeed = XaxisParameterTemp[3] ;
     XaxisParameter.MaxDistance = XaxisParameterTemp[4] ;
     XaxisParameter.MinDistance = XaxisParameterTemp[5];
     XaxisParameter.PositioningMode = XaxisParameterTemp[6];
     XaxisParameter.OverrunDistance = XaxisParameterTemp[7];
     XaxisParameter.ReferencePosMode = XaxisParameterTemp[8];
    XaxisParameter.ReferencePos = XaxisParameterTemp[9] * 1000 / XaxisParameter.LeadScrew;
      ////Y轴参数
     YaxisParameter.LeadScrew = YaxisParameterTemp[0];
     YaxisParameter.MotorDirection = YaxisParameterTemp[1];
     YaxisParameter.RunSpeed = YaxisParameterTemp[2] * 10;
     YaxisParameter.ManualSpeed = YaxisParameterTemp[3];
     YaxisParameter.MaxDistance = YaxisParameterTemp[4];
     YaxisParameter.MinDistance = YaxisParameterTemp[5];
     YaxisParameter.PositioningMode = YaxisParameterTemp[6];
     YaxisParameter.OverrunDistance = YaxisParameterTemp[7];
     YaxisParameter.ReferencePosMode = YaxisParameterTemp[8];
     YaxisParameter.ReferencePos = YaxisParameterTemp[9] * 1000 / YaxisParameter.LeadScrew;
     YaxisParameter.FrameStrength = YaxisParameterTemp[10];
      ////R轴参数
     RaxisParameter.ENABLE_AXIS = RaxisParameterTemp[0];
     RaxisParameter.LeadScrew = RaxisParameterTemp[1];
     RaxisParameter.MotorDirection = RaxisParameterTemp[2];
     RaxisParameter.RunSpeed = RaxisParameterTemp[3] * 10;
     RaxisParameter.ManualSpeed = RaxisParameterTemp[4];
     RaxisParameter.MaxDistance = RaxisParameterTemp[5];
     RaxisParameter.MinDistance = RaxisParameterTemp[6];
     RaxisParameter.PositioningMode = RaxisParameterTemp[7];
     RaxisParameter.OverrunDistance = RaxisParameterTemp[8];
     RaxisParameter.ReferencePosMode = RaxisParameterTemp[9];
     RaxisParameter.ReferencePos = RaxisParameterTemp[10] * 1000 / RaxisParameter.LeadScrew;

     ////MT轴参数////
     MTParameter.KeepTime = MTParameterTemp[0];
     MTParameter.UnloadTime = MTParameterTemp[1];
     MTParameter.VbackMode = MTParameterTemp[2];
     MTParameter.VbackTime = MTParameterTemp[3];
     MTParameter.SingleMode = MTParameterTemp[4];
     MTParameter.FastMode = MTParameterTemp[5];
     MTParameter.concedTime = MTParameterTemp[6];


}



void SystemSetting::SystemWriteMotor(unsigned char nodeId)
{
    if(nodeId == 0x01)
    {
        SystemSet_Motor[0].data[0].Data = XaxisParameter.MinDistance * 1000 / XaxisParameter.LeadScrew;
        SystemSet_Motor[0].data[1].Data = XaxisParameter.MaxDistance * 1000 / XaxisParameter.LeadScrew;
        SystemSet_Motor[0].data[5].Data = CurrentStepTemp.XPostion * 1000 / XaxisParameter.LeadScrew ;
        qDebug()<<"XaxisParameter.PositioningMode"<<CurrentStepTemp.XPostion;
        if(XaxisParameter.ReferencePosMode == 0)
        {
           SystemSet_Motor[0].Cmd_num = 9;
        }
        else
        {
           SystemSet_Motor[0].Cmd_num = 4;
        }

    }
    if(nodeId == 0x02)
    {
        SystemSet_Motor[1].data[0].Data = YaxisParameter.MinDistance * 1000 / YaxisParameter.LeadScrew;
        SystemSet_Motor[1].data[1].Data = YaxisParameter.MaxDistance * 1000 / YaxisParameter.LeadScrew ;
        SystemSet_Motor[1].data[5].Data =  CurrentStepTemp.YPostion * 1000 / YaxisParameter.LeadScrew ;
        if(YaxisParameter.ReferencePosMode == 0)
        {
           SystemSet_Motor[1].Cmd_num = 9;
        }
        else
        {
           SystemSet_Motor[1].Cmd_num = 4;
        }
    }

    if(nodeId == 0x03)
    {
        SystemSet_Motor[2].data[0].Data = RaxisParameter.MinDistance * 1000 / RaxisParameter.LeadScrew;
        SystemSet_Motor[2].data[1].Data = RaxisParameter.MaxDistance * 1000 / RaxisParameter.LeadScrew ;
        SystemSet_Motor[2].data[5].Data =  CurrentStepTemp.RPostion * 1000 / RaxisParameter.LeadScrew ;
        if(RaxisParameter.ReferencePosMode == 0)
        {
           SystemSet_Motor[2].Cmd_num = 9;
        }
        else
        {
           SystemSet_Motor[2].Cmd_num = 4;
        }
    }

    Write_MOTOR_Multi_Data(&SystemSet_Motor[nodeId-1],nodeId);

   //


}

void SystemSetting::SystemWriteMT()
{
     SystemSet_MT.data[0].Data = MTParameter.UnloadTime * 100;
     SystemSet_MT.data[1].Data = MTParameter.KeepTime * 100;
     Write_MOTOR_Multi_Data(&SystemSet_MT,MT_ID);
}



void SystemSetting::Display_Item(int ClassId,bool Editable,bool FristEnable)
{
    QString Str_ClassId=QString::number(ClassId,10);
    qDebug()<<"ClassId"<<ClassId;
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("Setup");
    model.setFilter("Visable = 1  AND Class = " + Str_ClassId);
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_System->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_System->setRowCount(1);
    }

    for(int i=0;i<model.rowCount();i++)
    {
        ui->tableWidget_System->setRowHeight(i,45);

        QSqlRecord record = model.record(i);
        if(SYSParameter.Language == 0)
        {
            ui->tableWidget_System->setItem(i,Table_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_System->setItem(i,Table_Name,new QTableWidgetItem(record.value("Name").toString()));
            ui->tableWidget_System->setItem(i,Table_Value,new QTableWidgetItem(record.value("Value").toString()));
            ui->tableWidget_System->setItem(i,Table_Info,new QTableWidgetItem(record.value("Introduce").toString()));
            //qDebug()<<"record.value"<<record.value("Value").toString();
        }
        else
        {
            ui->tableWidget_System->setItem(i,Table_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_System->setItem(i,Table_Name,new QTableWidgetItem(record.value("EnglishName").toString()));
            ui->tableWidget_System->setItem(i,Table_Value,new QTableWidgetItem(record.value("Value").toString()));
            ui->tableWidget_System->setItem(i,Table_Info,new QTableWidgetItem(record.value("EnglishInfo").toString()));

        }



        if(Editable)
        {                    
            ui->tableWidget_System->item(i,0)->setFlags(ui->tableWidget_System->item(i,Table_Id)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            ui->tableWidget_System->item(i,1)->setFlags(ui->tableWidget_System->item(i,Table_Name)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            //ui->tableWidget_System->item(i,2)->setFlags(ui->tableWidget_System->item(i,Table_Value)->flags() & Qt::ItemIsEnabled & Qt::ItemIsSelectable );
            ui->tableWidget_System->item(i,3)->setFlags(ui->tableWidget_System->item(i,Table_Info)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);

        }
        else
        {
            if(FristEnable)
            {
                ui->tableWidget_System->item(i,0)->setFlags(ui->tableWidget_System->item(i,Table_Id)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                ui->tableWidget_System->item(i,1)->setFlags(ui->tableWidget_System->item(i,Table_Name)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                if(i==0)
                {
                    ui->tableWidget_System->item(i,2)->setFlags(ui->tableWidget_System->item(i,Table_Value)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                }
                 ui->tableWidget_System->item(i,3)->setFlags(ui->tableWidget_System->item(i,Table_Info)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            }
            else
            {
                ui->tableWidget_System->item(i,0)->setFlags(ui->tableWidget_System->item(i,Table_Id)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                ui->tableWidget_System->item(i,1)->setFlags(ui->tableWidget_System->item(i,Table_Name)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                ui->tableWidget_System->item(i,2)->setFlags(ui->tableWidget_System->item(i,Table_Value)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
                ui->tableWidget_System->item(i,3)->setFlags(ui->tableWidget_System->item(i,Table_Info)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            }

        }

    }

    //db.close();//释放数据库

    Table_Editable_Flag = 1;
}


void SystemSetting::Update_Item(int Id,double Value)
{
    QString Str_Id=QString::number(Id,10);

    double Max_Value;
    double Min_Value;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlQuery query;
    query.exec("SELECT MAXVALUE,MINVALUE  FROM Setup WHERE ID = " +  Str_Id);
    while(query.next())
    {
       bool ok;
       Max_Value=query.value(0).toDouble(&ok);
       Min_Value=query.value(1).toDouble(&ok);
       break;
    }

    if(Value > Max_Value)
        Value = Max_Value;
    else if(Value < Min_Value)
        Value = Min_Value;

    QString Str_Value=QString::number(Value,'.',4);

    if((Id != Secret_Index) && (Id != Factory_Index ) && ( Id != 59))
    {
     query.exec("UPDATE Setup SET Value =" + Str_Value + " WHERE ID = " + Str_Id);
    }


    //db.close();//释放数据库
}



QString SystemSetting::Select_Item(int Id)
{
    QString Str_Id=QString::number(Id,10);
    QString CurrentValue;
    bool ok;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlQuery query;
    query.exec("SELECT  VALUE  FROM Setup WHERE ID = "+Str_Id);
    while(query.next())
    {
        CurrentValue=query.value(0).toString();
        break;
    }

    //db.close();//释放数据库X轴
    return CurrentValue;
}


SystemSetting::~SystemSetting()
{
    delete ui;
}

void SystemSetting::openSystemSettingWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);

    qDebug()<<"EditableFalg1111"<<EditableFalg;

    ui->tableWidget_System->setRowCount(0);
    ui->pushButton_BackTest->setEnabled(false);
    ui->pushButton_FastTest->setEnabled(false);
    ui->pushButton_KeepTest->setEnabled(false);
    ui->pushButton_SlowTest->setEnabled(false);
    ui->pushButton_StopTest->setEnabled(false);
    ui->pushButton_UnloadTest->setEnabled(false);
    ui->toolButton_confirm->setEnabled(false);

    ui->toolButton_InitDAT->setEnabled(false);
    ui->toolButton_ResumeDAT->setEnabled(false);
    ui->toolButton_SaveDAT->setEnabled(false);

    //Display_Item(10,true,false);
    //PumpSignalFlag = true;

    qDebug()<<"openSystemSettingWin";
}


void SystemSetting::on_toolButton_InitDAT_clicked()
{

    QSqlQuery query;
    query.exec("UPDATE  Setup  SET  VALUE = INITVALUE");

    CurrentReg.Current_MotorTips = DataInitTip;
    aralmOrTipFalg = false;
    SystemWarn SaveDATWarn;
    SaveDATWarn.setWindowFlags(Qt::FramelessWindowHint);
    SaveDATWarn.exec();

}

void SystemSetting::on_toolButton_SaveDAT_clicked()
{
//    QSqlQuery query;
//    query.exec(" ");
     #if ARMFlag
     system("sqlite3 /opt/tetra/A66-app/A66-app.db .dump > /opt/tetra/A66-app/backup.sql");
     #else
     system("sqlite3 A66-app.db .dump > /home/tetra/gitA66/A66-app/backup.sql");
     #endif
     CurrentReg.Current_MotorTips = DataSaveTip;
     aralmOrTipFalg = false;
     SystemWarn SaveDATWarn;
     SaveDATWarn.setWindowFlags(Qt::FramelessWindowHint);
     SaveDATWarn.exec();

}

void SystemSetting::on_toolButton_ResumeDAT_clicked()
{
 #if ARMFlag
    system("rm /opt/tetra/A66-app/A66-app.db");
    system("sqlite3 /opt/tetra/A66-app/A66-app.db < /opt/tetra/A66-app/backup.sql");
 #else
    system("rm /home/tetra/gitA66/A66-app/A66-app.db");
    system("sqlite3 /home/tetra/gitA66/A66-app/A66-app.db < /home/tetra/gitA66/A66-app/backup.sql");
 #endif
    CurrentReg.Current_MotorTips = DataResumeTip;
    aralmOrTipFalg = false;
    SystemWarn SaveDATWarn;
    SaveDATWarn.setWindowFlags(Qt::FramelessWindowHint);
    SaveDATWarn.exec();
  #if ARMFlag
        system("reboot");
   #endif
}



void SystemSetting::on_tableWidget_System_cellChanged(int row, int column)
{
    bool ok;
    int CurrentId=0;
    double CurrentValue;
   // qDebug("row %d",ui->tableWidget_System->rowCount() );
    if(Table_Editable_Flag == 1 && column == 2)
    {
        CurrentId = ui->tableWidget_System->item(ui->tableWidget_System->currentRow(),0)->text().toInt();

        CurrentValue=ui->tableWidget_System->item(ui->tableWidget_System->currentRow(),2)->text().toDouble(&ok);

        if(CurrentId == Secret_Index)
        {
            CurrentReg.CurrentSecret = ui->tableWidget_System->item(3,2)->text();
        }

        if(CurrentId == Factory_Index)
        {
            CurrentReg.CurrentSecret = ui->tableWidget_System->item(0,2)->text();
            qDebug()<<"Factory_Id"<<Factory_Id;
        }

        if( CurrentReg.CurrentSecret == SYSTEMSECRET)
        {
            EditableFalg =true;
        }

        Update_Item(CurrentId,CurrentValue);
        Table_Editable_Flag =0;
        if(CurrentId != Secret_Index && CurrentId != Factory_Index )
        {
         ui->tableWidget_System->setItem(ui->tableWidget_System->currentRow(),2,new QTableWidgetItem(Select_Item(CurrentId)));
        }
        Table_Editable_Flag =1;
        qDebug()<<"CurrentReg.CurrentSecret"<<CurrentReg.CurrentSecret;

        if( CurrentReg.CurrentSecret == FACTORYSECRET)
        {
            FactoryAxisFalg =true;
            EditableFalg =true;
           // Display_Item(Factory_Id,FactoryAxisFalg,true);
        }


    }
}

void SystemSetting::ReadForSystem()
{
    qDebug()<<"Enter ReadForRun data base initial Window!"<<endl;
    bool ok;

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("Setup");
    model.setFilter("ID =" +QString::number(CurrentReg.Current_ProgramLibRow,10));
    model.select();

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
//              CurrentProgramTemp.BroadThick = record.value("BroadThick").toDouble(&ok);
//              CurrentProgramTemp.Material = record.value("Material").toDouble(&ok);
//              CurrentProgramTemp.StepNumber =  record.value("StepTotal").toDouble(&ok);
//              CurrentProgramTemp.UpMold = record.value("UpMold").toDouble(&ok);
//              CurrentProgramTemp.LowerMold =  record.value("LowerMold").toDouble(&ok);
//              CurrentProgramTemp.ProcessedNum = record.value("WorkedTotal").toDouble(&ok);
           // qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }


   // ui->tableWidget_UpMoulds->selectRow(0);
    //db.close();//释放数据库

}

//////////////////////////////////////////////////////////////阀组配置//////////////////////////////////


void SystemSetting::WriteConfig()
{
    unsigned char VFastStatus[8];
    unsigned char VslowStatus[8];
    unsigned char VkeepStatus[8];
    unsigned char VunloadStatus[8];
    unsigned char VbackStatus[8];
    unsigned char VstopStatus[8];

    if( ui->checkBoxVFast1->checkState() == 2)
       VFastStatus[0] = 1;
    else
       VFastStatus[0] = 0;
    if( ui->checkBoxVFast2->checkState() == 2)
       VFastStatus[1] = 1;
    else
       VFastStatus[1] = 0;
    if( ui->checkBoxVFast3->checkState() == 2)
       VFastStatus[2]= 1;
    else
        VFastStatus[2] = 0;
    if( ui->checkBoxVFast4->checkState() == 2)
       VFastStatus[3] = 1;
    else
       VFastStatus[3] = 0;
    if( ui->checkBoxVFast5->checkState() == 2)
       VFastStatus[4] = 1;
    else
       VFastStatus[4] = 0;
    if( ui->checkBoxVFast6->checkState() == 2)
       VFastStatus[5] = 1;
    else
       VFastStatus[5] = 0;
    if( ui->checkBoxVFast7->checkState() == 2)
       VFastStatus[6] = 1;
    else
       VFastStatus[6] = 0;
    if( ui->checkBoxVFast8->checkState() == 2)
       VFastStatus[7] = 1;
    else
       VFastStatus[7] = 0;

    ValveReg.VFaststate =  VFastStatus[7] << 7 | VFastStatus[6] << 6 | VFastStatus[5] << 5 | VFastStatus[4] << 4 | VFastStatus[3] << 3  | VFastStatus[2] << 2  | VFastStatus[1] << 1 |VFastStatus[0];

    //ValveReg.VFaststate |=  VFastStatus[7] << 7 | VFastStatus[6] << 6 | VFastStatus[5] << 5 | VFastStatus[4] << 4 | VFastStatus[3] << 3  | VFastStatus[2] << 2  | VFastStatus[1] << 1 | VFastStatus[0];

    if( ui->checkBoxVSlow1->checkState() == 2)
       VslowStatus[0] = 1;
    else
       VslowStatus[0] = 0;
    if( ui->checkBoxVSlow2->checkState() == 2)
       VslowStatus[1] = 1;
    else
       VslowStatus[1] = 0;
    if( ui->checkBoxVSlow3->checkState() == 2)
       VslowStatus[2]= 1;
    else
        VslowStatus[2] = 0;
    if( ui->checkBoxVSlow4->checkState() == 2)
       VslowStatus[3] = 1;
    else
       VslowStatus[3] = 0;
    if( ui->checkBoxVSlow5->checkState() == 2)
       VslowStatus[4] = 1;
    else
       VslowStatus[4] = 0;
    if( ui->checkBoxVSlow6->checkState() == 2)
       VslowStatus[5] = 1;
    else
       VslowStatus[5] = 0;
    if( ui->checkBoxVSlow7->checkState() == 2)
       VslowStatus[6] = 1;
    else
       VslowStatus[6] = 0;
    if( ui->checkBoxVSlow8->checkState() == 2)
       VslowStatus[7] = 1;
    else
       VslowStatus[7] = 0;

    ValveReg.VSlowstate = VslowStatus[7] << 7 | VslowStatus[6] << 6 | VslowStatus[5] << 5 | VslowStatus[4] << 4 | VslowStatus[3] << 3  | VslowStatus[2] << 2  | VslowStatus[1] << 1 |VslowStatus[0];

    if( ui->checkBoxVkeep1->checkState() == 2)
       VkeepStatus[0] = 1;
    else
       VkeepStatus[0] = 0;
    if( ui->checkBoxVkeep2->checkState() == 2)
       VkeepStatus[1] = 1;
    else
       VkeepStatus[1] = 0;
    if( ui->checkBoxVkeep3->checkState() == 2)
       VkeepStatus[2]= 1;
    else
        VkeepStatus[2] = 0;
    if( ui->checkBoxVkeep4->checkState() == 2)
       VkeepStatus[3] = 1;
    else
       VkeepStatus[3] = 0;
    if( ui->checkBoxVkeep5->checkState() == 2)
       VkeepStatus[4] = 1;
    else
       VkeepStatus[4] = 0;
    if( ui->checkBoxVkeep6->checkState() == 2)
       VkeepStatus[5] = 1;
    else
       VkeepStatus[5] = 0;
    if( ui->checkBoxVkeep7->checkState() == 2)
       VkeepStatus[6] = 1;
    else
       VkeepStatus[6] = 0;
    if( ui->checkBoxVkeep8->checkState() == 2)
       VkeepStatus[7] = 1;
    else
       VkeepStatus[7] = 0;

    ValveReg.VKeepstate = VkeepStatus[7] << 7 | VkeepStatus[6] << 6 | VkeepStatus[5] << 5 | VkeepStatus[4] << 4 | VkeepStatus[3] << 3  | VkeepStatus[2] << 2  | VkeepStatus[1] << 1 |VkeepStatus[0];

    if( ui->checkBoxVunload1->checkState() == 2)
       VunloadStatus[0] = 1;
    else
       VunloadStatus[0] = 0;
    if( ui->checkBoxVunload2->checkState() == 2)
       VunloadStatus[1] = 1;
    else
       VunloadStatus[1] = 0;
    if( ui->checkBoxVunload3->checkState() == 2)
       VunloadStatus[2]= 1;
    else
        VunloadStatus[2] = 0;
    if( ui->checkBoxVunload4->checkState() == 2)
       VunloadStatus[3] = 1;
    else
       VunloadStatus[3] = 0;
    if( ui->checkBoxVunload5->checkState() == 2)
       VunloadStatus[4] = 1;
    else
       VunloadStatus[4] = 0;
    if( ui->checkBoxVunload6->checkState() == 2)
       VunloadStatus[5] = 1;
    else
       VunloadStatus[5] = 0;
    if( ui->checkBoxVunload7->checkState() == 2)
       VunloadStatus[6] = 1;
    else
       VunloadStatus[6] = 0;
    if( ui->checkBoxVunload8->checkState() == 2)
       VunloadStatus[7] = 1;
    else
       VunloadStatus[7] = 0;

    ValveReg.Vunloadstate = VunloadStatus[7] << 7 | VunloadStatus[6] << 6 | VunloadStatus[5] << 5 | VunloadStatus[4] << 4 | VunloadStatus[3] << 3  | VunloadStatus[2] << 2  | VunloadStatus[1] << 1 |VunloadStatus[0];

    if( ui->checkBoxVback1->checkState() == 2)
       VbackStatus[0] = 1;
    else
       VbackStatus[0] = 0;
    if( ui->checkBoxVback2->checkState() == 2)
       VbackStatus[1] = 1;
    else
       VbackStatus[1] = 0;
    if( ui->checkBoxVback3->checkState() == 2)
       VbackStatus[2]= 1;
    else
        VbackStatus[2] = 0;
    if( ui->checkBoxVback4->checkState() == 2)
       VbackStatus[3] = 1;
    else
       VbackStatus[3] = 0;
    if( ui->checkBoxVback5->checkState() == 2)
       VbackStatus[4] = 1;
    else
       VbackStatus[4] = 0;
    if( ui->checkBoxVback6->checkState() == 2)
       VbackStatus[5] = 1;
    else
       VbackStatus[5] = 0;
    if( ui->checkBoxVback7->checkState() == 2)
       VbackStatus[6] = 1;
    else
       VbackStatus[6] = 0;
    if( ui->checkBoxVback8->checkState() == 2)
       VbackStatus[7] = 1;
    else
       VbackStatus[7] = 0;

    ValveReg.Vbackstate = VbackStatus[7] << 7 | VbackStatus[6] << 6 | VbackStatus[5] << 5 | VbackStatus[4] << 4 | VbackStatus[3] << 3  | VbackStatus[2] << 2  | VbackStatus[1] << 1 |VbackStatus[0];

    if( ui->checkBoxVstop1->checkState() == 2)
       VstopStatus[0] = 1;
    else
       VstopStatus[0] = 0;
    if( ui->checkBoxVstop2->checkState() == 2)
       VstopStatus[1] = 1;
    else
       VstopStatus[1] = 0;
    if( ui->checkBoxVstop3->checkState() == 2)
       VstopStatus[2]= 1;
    else
        VstopStatus[2] = 0;
    if( ui->checkBoxVstop4->checkState() == 2)
       VstopStatus[3] = 1;
    else
       VstopStatus[3] = 0;
    if( ui->checkBoxVstop5->checkState() == 2)
       VstopStatus[4] = 1;
    else
       VstopStatus[4] = 0;
    if( ui->checkBoxVstop6->checkState() == 2)
       VstopStatus[5] = 1;
    else
       VstopStatus[5] = 0;
    if( ui->checkBoxVstop7->checkState() == 2)
       VstopStatus[6] = 1;
    else
       VstopStatus[6] = 0;
    if( ui->checkBoxVstop8->checkState() == 2)
       VstopStatus[7] = 1;
    else
       VstopStatus[7] = 0;

    ValveReg.Vstopstate = VstopStatus[7] << 7 | VstopStatus[6] << 6 | VstopStatus[5] << 5 | VstopStatus[4] << 4 | VstopStatus[3] << 3  | VstopStatus[2] << 2  | VstopStatus[1] << 1 |VstopStatus[0];


//    ValveReg.KeepTime  = ui->lineEdit_KeepTime->text().toInt();0
//    ValveReg.UnloadTime= ui->lineEdit_UnloadTime->text().toInt();

    ValveReg.KeepTime = MTParameter.KeepTime;
    ValveReg.UnloadTime = MTParameter.UnloadTime;


    qDebug("VFastState  %X" ,ValveReg.VFaststate);
    qDebug("VSlowstate  %X" ,ValveReg.VSlowstate);
    qDebug("VKeepstate  %X" ,ValveReg.VKeepstate);
    qDebug("UnloadTime  %X" ,ValveReg.UnloadTime);
    qDebug("Vbackstate  %X" ,ValveReg.Vbackstate);
    qDebug("Vstopstate  %X" ,ValveReg.Vstopstate);



}

void SystemSetting::ReadConfig(void)
{
    if(ValveReg.VFaststate & 0x01)
    {
        ui->checkBoxVFast1->setChecked(true);
    }
    else
    {
         ui->checkBoxVFast1->setChecked(false);
    }
    if((ValveReg.VFaststate >> 1) & 0x01)
    {
       ui->checkBoxVFast2->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast2->setChecked(false);
    }
    if((ValveReg.VFaststate >> 2) & 0x01)
    {
       ui->checkBoxVFast3->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast3->setChecked(false);
    }
    if((ValveReg.VFaststate >> 3) & 0x01)
    {
       ui->checkBoxVFast4->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast4->setChecked(false);
    }
    if((ValveReg.VFaststate >> 4) & 0x01)
    {
       ui->checkBoxVFast5->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast5->setChecked(false);
    }
    if((ValveReg.VFaststate >> 5) & 0x01)
    {
       ui->checkBoxVFast6->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast6->setChecked(false);
    }
    if((ValveReg.VFaststate >> 6) & 0x01)
    {
       ui->checkBoxVFast7->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast7->setChecked(false);
    }
    if((ValveReg.VFaststate >> 7) & 0x01)
    {
       ui->checkBoxVFast8->setChecked(true);
    }
    else
    {
        ui->checkBoxVFast8->setChecked(false);
    }
   /*VSlow*******************************************/
    if((ValveReg.VSlowstate ) & 0x01)
    {
       ui->checkBoxVSlow1->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow1->setChecked(false);
    }
    if((ValveReg.VSlowstate >> 1) & 0x01)
    {
       ui->checkBoxVSlow2->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow2->setChecked(false);
    }
    if((ValveReg.VSlowstate >>2 ) & 0x01)
    {
       ui->checkBoxVSlow3->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow3->setChecked(false);
    }
    if((ValveReg.VSlowstate >>3) & 0x01)
    {
       ui->checkBoxVSlow4->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow4->setChecked(false);
    }
    if((ValveReg.VSlowstate >>4) & 0x01)
    {
       ui->checkBoxVSlow5->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow5->setChecked(false);
    }
    if((ValveReg.VSlowstate >>5 ) & 0x01)
    {
       ui->checkBoxVSlow6->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow6->setChecked(false);
    }
    if((ValveReg.VSlowstate >>6) & 0x01)
    {
       ui->checkBoxVSlow7->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow7->setChecked(false);
    }
    if((ValveReg.VSlowstate >>7) & 0x01)
    {
       ui->checkBoxVSlow8->setChecked(true);
    }
    else
    {
        ui->checkBoxVSlow8->setChecked(false);
    }
 /*VKEEP*/////////////////////////////
    if((ValveReg.VKeepstate) & 0x01)
    {
       ui->checkBoxVkeep1->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep1->setChecked(false);
    }

    if((ValveReg.VKeepstate >> 1) & 0x01)
    {
       ui->checkBoxVkeep2->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep2->setChecked(false);
    }

    if((ValveReg.VKeepstate >>2) & 0x01)
    {
       ui->checkBoxVkeep3->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep3->setChecked(false);
    }

    if((ValveReg.VKeepstate >>3) & 0x01)
    {
       ui->checkBoxVkeep4->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep4->setChecked(false);
    }

    if((ValveReg.VKeepstate >>4) & 0x01)
    {
       ui->checkBoxVkeep5->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep5->setChecked(false);
    }

    if((ValveReg.VKeepstate >>5) & 0x01)
    {
       ui->checkBoxVkeep6->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep6->setChecked(false);
    }

    if((ValveReg.VKeepstate >>6) & 0x01)
    {
       ui->checkBoxVkeep7->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep7->setChecked(false);
    }

    if((ValveReg.VKeepstate >>7) & 0x01)
    {
       ui->checkBoxVkeep8->setChecked(true);
    }
    else
    {
        ui->checkBoxVkeep8->setChecked(false);
    }


    /*Unload********************/
    if((ValveReg.Vunloadstate ) & 0x01)
    {
       ui->checkBoxVunload1->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload1->setChecked(false);
    }

    if((ValveReg.Vunloadstate >>1 ) & 0x01)
    {
       ui->checkBoxVunload2->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload2->setChecked(false);
    }
    if((ValveReg.Vunloadstate >>2) & 0x01)
    {
       ui->checkBoxVunload3->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload3->setChecked(false);
    }
    if((ValveReg.Vunloadstate >>3) & 0x01)
    {
       ui->checkBoxVunload4->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload4->setChecked(false);
    }
    if((ValveReg.Vunloadstate >>4) & 0x01)
    {
       ui->checkBoxVunload5->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload5->setChecked(false);
    }
    if((ValveReg.Vunloadstate >>5) & 0x01)
    {
       ui->checkBoxVunload6->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload6->setChecked(false);
    }

    if((ValveReg.Vunloadstate >>6) & 0x01)
    {
       ui->checkBoxVunload7->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload7->setChecked(false);
    }

    if((ValveReg.Vunloadstate >>7) & 0x01)
    {
       ui->checkBoxVunload8->setChecked(true);
    }
    else
    {
        ui->checkBoxVunload8->setChecked(false);
    }

    /*Vback**********************/
    if((ValveReg.Vbackstate ) & 0x01)
    {
       ui->checkBoxVback1->setChecked(true);
    }
    else
    {
        ui->checkBoxVback1->setChecked(false);
    }

    if((ValveReg.Vbackstate >> 1) & 0x01)
    {
       ui->checkBoxVback2->setChecked(true);
    }
    else
    {
        ui->checkBoxVback2->setChecked(false);
    }

    if((ValveReg.Vbackstate >> 2) & 0x01)
    {
       ui->checkBoxVback3->setChecked(true);
    }
    else
    {
        ui->checkBoxVback3->setChecked(false);
    }

    if((ValveReg.Vbackstate >> 3) & 0x01)
    {
       ui->checkBoxVback4->setChecked(true);
    }
    else
    {
        ui->checkBoxVback4->setChecked(false);
    }

    if((ValveReg.Vbackstate >> 4) & 0x01)
    {
       ui->checkBoxVback5->setChecked(true);
    }
    else
    {
        ui->checkBoxVback5->setChecked(false);
    }

    if((ValveReg.Vbackstate >> 5) & 0x01)
    {
       ui->checkBoxVback6->setChecked(true);
    }
    else
    {
        ui->checkBoxVback6->setChecked(false);
    }
    if((ValveReg.Vbackstate >> 6) & 0x01)
    {
       ui->checkBoxVback7->setChecked(true);
    }
    else
    {
        ui->checkBoxVback7->setChecked(false);
    }
    if((ValveReg.Vbackstate >> 7) & 0x01)
    {
       ui->checkBoxVback8->setChecked(true);
    }
    else
    {
        ui->checkBoxVback8->setChecked(false);
    }

 /*vStop*/
    if((ValveReg.Vstopstate) & 0x01)
    {
       ui->checkBoxVstop1->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop1->setChecked(false);
    }
    if((ValveReg.Vstopstate >>1) & 0x01)
    {
       ui->checkBoxVstop2->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop2->setChecked(false);
    }
    if((ValveReg.Vstopstate >>2) & 0x01)
    {
       ui->checkBoxVstop3->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop3->setChecked(false);
    }

    if((ValveReg.Vstopstate >>3) & 0x01)
    {
       ui->checkBoxVstop4->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop4->setChecked(false);
    }
    if((ValveReg.Vstopstate>>4) & 0x01)
    {
       ui->checkBoxVstop5->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop5->setChecked(false);
    }
    if((ValveReg.Vstopstate>>5) & 0x01)
    {
       ui->checkBoxVstop6->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop6->setChecked(false);
    }
    if((ValveReg.Vstopstate>>6) & 0x01)
    {
       ui->checkBoxVstop7->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop7->setChecked(false);
    }
    if((ValveReg.Vstopstate>>7) & 0x01)
    {
       ui->checkBoxVstop8->setChecked(true);
    }
    else
    {
        ui->checkBoxVstop8->setChecked(false);
    }

    //ui->lineEdit_KeepTime->setText(QString::number(ValveReg.KeepTime,10));
    //ui->lineEdit_UnloadTime->setText(QString::number(ValveReg.UnloadTime,10));

    MTParameter.KeepTime = ValveReg.KeepTime;
    MTParameter.UnloadTime = ValveReg.UnloadTime;



}

void SystemSetting::CleanConfig()
{
    ui->checkBoxVFast1->setChecked(false);
    ui->checkBoxVFast2->setChecked(false);
    ui->checkBoxVFast3->setChecked(false);
    ui->checkBoxVFast4->setChecked(false);
    ui->checkBoxVFast5->setChecked(false);
    ui->checkBoxVFast6->setChecked(false);
    ui->checkBoxVFast7->setChecked(false);
    ui->checkBoxVFast8->setChecked(false);


    ui->checkBoxVSlow1->setChecked(false);
    ui->checkBoxVSlow2->setChecked(false);
    ui->checkBoxVSlow3->setChecked(false);
    ui->checkBoxVSlow4->setChecked(false);
    ui->checkBoxVSlow5->setChecked(false);
    ui->checkBoxVSlow6->setChecked(false);
    ui->checkBoxVSlow7->setChecked(false);
    ui->checkBoxVSlow8->setChecked(false);

    ui->checkBoxVkeep1->setChecked(false);
    ui->checkBoxVkeep2->setChecked(false);
    ui->checkBoxVkeep3->setChecked(false);
    ui->checkBoxVkeep4->setChecked(false);
    ui->checkBoxVkeep5->setChecked(false);
    ui->checkBoxVkeep6->setChecked(false);
    ui->checkBoxVkeep7->setChecked(false);
    ui->checkBoxVkeep8->setChecked(false);

    ui->checkBoxVback1->setChecked(false);
    ui->checkBoxVback2->setChecked(false);
    ui->checkBoxVback3->setChecked(false);
    ui->checkBoxVback4->setChecked(false);
    ui->checkBoxVback5->setChecked(false);
    ui->checkBoxVback6->setChecked(false);
    ui->checkBoxVback7->setChecked(false);
    ui->checkBoxVback8->setChecked(false);

    ui->checkBoxVunload1->setChecked(false);
    ui->checkBoxVunload2->setChecked(false);
    ui->checkBoxVunload3->setChecked(false);
    ui->checkBoxVunload4->setChecked(false);
    ui->checkBoxVunload5->setChecked(false);
    ui->checkBoxVunload6->setChecked(false);
    ui->checkBoxVunload7->setChecked(false);
    ui->checkBoxVunload8->setChecked(false);

    ui->checkBoxVstop1->setChecked(false);
    ui->checkBoxVstop2->setChecked(false);
    ui->checkBoxVstop3->setChecked(false);
    ui->checkBoxVstop4->setChecked(false);
    ui->checkBoxVstop5->setChecked(false);
    ui->checkBoxVstop6->setChecked(false);
    ui->checkBoxVstop7->setChecked(false);
    ui->checkBoxVstop8->setChecked(false);





}

void SystemSetting::on_toolButton_confirm_clicked()
{

//    if(ui->lineEdit_Secret->text() == "5678")
//    {
        Write_Button_state = 1;

//    }
}

void SystemSetting::on_toolButton_readConfig_clicked()
{
    Read_Button_state  = 1;

}



static int write_step=0;
int SystemSetting::deal_write_config_event()
{

    if(Write_Button_state == 1)
{
    WriteConfig();
    Config_valve_buf.data[0].Data = ValveReg.VFaststate;
    Config_valve_buf.data[1].Data = ValveReg.VSlowstate;
    Config_valve_buf.data[2].Data = ValveReg.VKeepstate;
    Config_valve_buf.data[3].Data = ValveReg.Vunloadstate;
    Config_valve_buf.data[4].Data = ValveReg.Vbackstate;
    Config_valve_buf.data[5].Data = ValveReg.Vstopstate;
    Config_valve_buf.data[6].Data = ValveReg.UnloadTime;
    Config_valve_buf.data[7].Data = ValveReg.KeepTime;
    Config_valve_buf.data[8].Data = 0xAA; //写入AA进入从几配置模式
    if(motor[3].Wrte_Multi_Finsh_state == RUN_SEND)
    {
        qDebug("Wrte_Multi_Finsh_state_RUNSED");
        return 0;
    }
    if(motor[3].Read_one_state == RUN_SEND)
    {
    //qDebug("Read_one_state_RUNSEND");
        return 0;
    }
     if(write_step == 0) //motor[3].Wrte_Multi_Finsh_state == NO_SEND &&
    {
        motor[3].SDO_status = SDO_free;
        Write_MOTOR_Multi_Data(&Config_valve_buf,0x04);
       // qDebug("11111111111111111111111111111111");
        qDebug("motor[3].Wrte_Multi_Finsh_state = WAIT_FREE_SEND: %d",motor[3].Wrte_Multi_Finsh_state);
        write_step = 1;
    }
    else if(motor[3].Wrte_Multi_Finsh_state == SUCCESS_SEND) //顺序不能调换
    {
         motor[3].SDO_status = SDO_free;
         read_One_Data(0x04,0x7000,0x01); //进入读取验证配置是否成功
         motor[3].Wrte_Multi_Finsh_state = WAIT_FREE_SEND;
        // qDebug("2222222222222222222222222222222222222");
    }

    else if (motor[3].Wrte_Multi_Finsh_state == FAIL_SEND)
    {
        motor[3].Read_one_state =         NO_SEND;
        motor[3].Wrte_Multi_Finsh_state = NO_SEND;
        motor[3].SDO_status = SDO_free;
        Write_Button_state = 0;
        write_step = 0;

        ReadFailFlag = true;
//        QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
//                              trUtf8("发送失败~。~"));

        return 0;
    }
    else if(motor[3].Read_one_state == SUCCESS_SEND)
    {
        motor[3].Read_one_state        = NO_SEND;
        motor[3].Wrte_Multi_Finsh_state = NO_SEND;
        motor[3].SDO_status = SDO_free;
        Write_Button_state = 0;
         write_step = 0;
        if(motor[3].RX_buf[0] == 0xA0)
        {

            SendSuccessFlag = true;
//            QMessageBox::information(0,QObject::trUtf8("写入配置"),
//                                   trUtf8("配置成功"));
             qDebug("entern readif");
             CleanConfig();
        }
        else
        {
            SendFailFlag = true;

//           QMessageBox::critical(0,QObject::trUtf8("写入配置"),
//                                   trUtf8("配置失败"));
           qDebug("entern readifelse");
        }
        Write_MOTOR_One_Data(MT_ID,0x7000,0x01,0x01,0x00);
       // qDebug("234444444444444444444444444444444444432");
    }
    else if(motor[3].Read_one_state == FAIL_SEND)
    {
         motor[3].Read_one_state = NO_SEND;
         motor[3].Wrte_Multi_Finsh_state = NO_SEND;
         motor[3].SDO_status = SDO_free;
         Write_Button_state = 0;
          write_step = 0;
//         MotorConfigTipFlag = true;
//         MotorConfigFlag = true;
//         CurrentReg.Current_MotorTips = SendFailTip;
//         CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
//         qDebug("SendFailTip");
          SendFailFlag = true;
//        QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
//                              trUtf8("发送失败"));

    }

}
}



int SystemSetting::deal_read_config_event()
{
    if(Read_Button_state == 1)
   {
       if(motor[3].Read_Multi_Finsh_state == NO_SEND)
       {
          Read_MOTOR_Multi_Data(&Config_valve_buf,0x04);
          //qDebug("Read_MOTOR_Multi_Data--1---------------");
       }
       else if(motor[3].Read_Multi_Finsh_state == SUCCESS_SEND)
       {
            ValveReg.VFaststate   = motor[3].RX_DATA[1];
            ValveReg.VSlowstate   = motor[3].RX_DATA[2];
            ValveReg.VKeepstate   = motor[3].RX_DATA[3];
            ValveReg.Vunloadstate = motor[3].RX_DATA[4];
            ValveReg.Vbackstate   = motor[3].RX_DATA[5];
            ValveReg.Vstopstate   = motor[3].RX_DATA[6];
            ValveReg.UnloadTime   = motor[3].RX_DATA[7];
            ValveReg.KeepTime     = motor[3].RX_DATA[8];
            ReadConfig();
//            MotorConfigTipFlag = true;
//            MotorConfigFlag = true;
//            CurrentReg.Current_MotorTips = ReadSuccessTip;
//            CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
//            qDebug("ReadSuccessTip");
            ReadSuccessFlag =true;

//            QMessageBox::information(0,QObject::trUtf8("读取配置信息"),
//                                  trUtf8("读取成功"));
            Read_Button_state = 0;
            motor[3].Read_Multi_Finsh_state = NO_SEND;
            motor[3].SDO_status = SDO_free;
          // qDebug("motor[3].Read_Multi_Finsh_state == SUCCESS_SEND---------------");
       }
        else if (motor[3].Read_Multi_Finsh_state == FAIL_SEND)
        {
//           MotorConfigTipFlag = true;
//           MotorConfigFlag = true;
//           CurrentReg.Current_MotorTips = ReadFailTip;
//           CurrentReg.Current_MotorConfigResult = SystemTipsInformation(CurrentReg.Current_MotorTips);
           ReadFailFlag =true;
//           QMessageBox::critical(0,QObject::trUtf8("读取配置信息"),
//                                 trUtf8("读取失败"));
           qDebug("ReadFailTip");
           Read_Button_state = 0;
           motor[3].SDO_status = SDO_free;
           motor[3].Read_Multi_Finsh_state = NO_SEND;
           // qDebug("motor[3].Read_Multi_Finsh_state == FAIL_SEND--------------");
       }

}

}

}


void SystemSetting::on_pushButton_FastTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.VFaststate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_FastTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_SlowTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.VSlowstate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_SlowTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_KeepTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.VKeepstate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_KeepTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_UnloadTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.Vunloadstate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_UnloadTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_BackTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.Vbackstate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_BackTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_StopTest_pressed()
{
    WriteConfig();
    ConfigTest.data[0].Data = 0x30;//打开测试配置模式
    ConfigTest.data[1].Data = ValveReg.Vstopstate;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

void SystemSetting::on_pushButton_StopTest_released()
{
    ConfigTest.data[0].Data = 0x31;//关闭测试配置模式
    ConfigTest.data[1].Data = 0x00;
    Write_MOTOR_Multi_Data(&ConfigTest,MT_ID);
}

//void SystemSetting::on_lineEdit_Secret_editingFinished()
//{
//    if(ui->lineEdit_Secret->text() == "5678")
//    {
//       ui->pushButton_BackTest->setEnabled(true);
//       ui->pushButton_FastTest->setEnabled(true);
//       ui->pushButton_KeepTest->setEnabled(true);
//       ui->pushButton_SlowTest->setEnabled(true);
//       ui->pushButton_StopTest->setEnabled(true);
//       ui->pushButton_UnloadTest->setEnabled(true);
//       ui->toolButton_confirm->setEnabled(true);
//    }

//}

