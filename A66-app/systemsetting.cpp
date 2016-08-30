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

}

void SystemSetting::on_treeWidget_System_itemSelectionChanged()
{
    Table_Editable_Flag = 0;

    if(ui->treeWidget_System->currentItem()->parent() != NULL)
    {
        if(ui->treeWidget_System->currentItem()->parent()->text(0).compare(trUtf8("通用")) == 0)
        {
           ui->stackedWidget->setCurrentIndex(0);
           Display_Item(ui->treeWidget_System->currentIndex().row()+10,true);

           qDebug()<<"ui->tableWidget_System->item(2,2)->text()"<<ui->tableWidget_System->item(2,2)->text();
           if(ui->tableWidget_System->item(2,2)->text() == "5678")
           {
               EditableFalg =true;
               qDebug("sw");
              // ui->tableWidget_System->setItem(2,2,new QTableWidgetItem(QString::number(0,10)));
           }
        }
        if(ui->treeWidget_System->currentItem()->parent()->text(0).compare(trUtf8("轴参数")) == 0)
        {
            ui->stackedWidget->setCurrentIndex(0);
           Display_Item(ui->treeWidget_System->currentIndex().row()+20,EditableFalg);
        }
        if(ui->treeWidget_System->currentItem()->parent()->text(0).compare(trUtf8("高级设置")) == 0 )
        {
           ui->stackedWidget->setCurrentIndex(0);
           Display_Item(ui->treeWidget_System->currentIndex().row()+30,EditableFalg);
        }
        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("阀组配置")) == 0 )
        {
            ui->stackedWidget->setCurrentIndex(2);
        }
        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("工厂设置")) == 0 )
        {
            ui->stackedWidget->setCurrentIndex(1);
        }



      // checktSecret();
    }


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

        if(ui->treeWidget_System->currentItem()->text(0).compare(trUtf8("常量")) == 0 )
        {
            Display_Item(ui->treeWidget_System->currentIndex().row()+10,true);

        }
//    }
}

void SystemSetting::TreeWidgetInit()
{

}


void SystemSetting::Display_Item(int ClassId,bool Editable)
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
    model.setFilter("Visable = 1 AND Class = " + Str_ClassId);
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
        QSqlRecord record = model.record(i);
        ui->tableWidget_System->setItem(i,Table_Id,new QTableWidgetItem(record.value("Id").toString()));
        ui->tableWidget_System->setItem(i,Table_Name,new QTableWidgetItem(record.value("Name").toString()));
        ui->tableWidget_System->setItem(i,Table_Value,new QTableWidgetItem(record.value("Value").toString()));
        ui->tableWidget_System->setItem(i,Table_Info,new QTableWidgetItem(record.value("Introduce").toString()));

        if(Editable)
        {
        ui->tableWidget_System->item(i,0)->setFlags(ui->tableWidget_System->item(i,Table_Id)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
        ui->tableWidget_System->item(i,1)->setFlags(ui->tableWidget_System->item(i,Table_Name)->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
        //ui->tableWidget_System->item(i,2)->setFlags(ui->tableWidget_System->item(i,Table_Value)->flags() & Qt::ItemIsEnabled & Qt::ItemIsSelectable );
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

    query.exec("UPDATE Setup SET Value =" + Str_Value + " WHERE ID = " + Str_Id);


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
    qDebug()<<"openSystemSettingWin";
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

         qDebug()<<"222222222";

        Update_Item(CurrentId,CurrentValue);
        Table_Editable_Flag =0;
        ui->tableWidget_System->setItem(ui->tableWidget_System->currentRow(),2,new QTableWidgetItem(Select_Item(CurrentId)));
        Table_Editable_Flag =1;
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


    ValveReg.KeepTime  = ui->lineEdit_KeepTime->text().toInt();
    ValveReg.UnloadTime= ui->lineEdit_UnloadTime->text().toInt();

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

    ui->lineEdit_KeepTime->setText(QString::number(ValveReg.KeepTime,10));
    ui->lineEdit_UnloadTime->setText(QString::number(ValveReg.UnloadTime,10));




}

void SystemSetting::on_toolButton_confirm_clicked()
{

    Write_Button_state = 1;

}
void SystemSetting::on_toolButton_readConfig_clicked()
{
    Read_Button_state  = 1;

}




int SystemSetting::deal_write_config_event()
{

    if(Write_Button_state == 1)
{
   // read_One_Data(0x04,0x7000,0x01);
  //  Write_Button_state = 0;
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
    //    qDebug("Read_one_state_RUNSEND");
        return 0;
    }
     if(motor[3].Wrte_Multi_Finsh_state == NO_SEND)
    {
        Write_MOTOR_Multi_Data(&Config_valve_buf,0x04);
        qDebug("11111111111111111111111111111111");
        qDebug("motor[3].Wrte_Multi_Finsh_state = WAIT_FREE_SEND: %d",motor[3].Wrte_Multi_Finsh_state);
    }
    else if(motor[3].Wrte_Multi_Finsh_state == SUCCESS_SEND ) //顺序不能调换
    {
         motor[3].SDO_status = SDO_free;
         read_One_Data(0x04,0x7000,0x01); //进入读取验证配置是否成功
         motor[3].Wrte_Multi_Finsh_state = WAIT_FREE_SEND;
         qDebug("2222222222222222222222222222222222222");
    }

    else if (motor[3].Wrte_Multi_Finsh_state == FAIL_SEND)
    {
        motor[3].Read_one_state =         NO_SEND;
        motor[3].Wrte_Multi_Finsh_state = NO_SEND;
        motor[3].SDO_status = SDO_free;
        Write_Button_state = 0;
        QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
                              trUtf8("发送失败~。~"));

        return 0;
        qDebug("233333333333333333333333333333333333332");
    }
    else if(motor[3].Read_one_state == SUCCESS_SEND)
    {
        motor[3].Read_one_state        = NO_SEND;
        motor[3].Wrte_Multi_Finsh_state = NO_SEND;
        motor[3].SDO_status = SDO_free;
        Write_Button_state = 0;
        if(motor[3].RX_buf[0] == 0xA0)
        {
            QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
                                   trUtf8("配置成功"));
             qDebug("entern readif");
        }
        else
        {
           QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
                                   trUtf8("配置失败"));
           qDebug("entern readifelse");
        }

        qDebug("234444444444444444444444444444444444432");
    }
    else if(motor[3].Read_one_state == FAIL_SEND)
    {
         motor[3].Read_one_state = NO_SEND;
         motor[3].Wrte_Multi_Finsh_state = NO_SEND;
         motor[3].SDO_status = SDO_free;
         Write_Button_state = 0;
        QMessageBox::critical(0,QObject::trUtf8("写入配置信息"),
                              trUtf8("发送失败"));


         qDebug("25555555555555555555555555555555553332");
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
          qDebug("Read_MOTOR_Multi_Data--1---------------");
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
            QMessageBox::critical(0,QObject::trUtf8("读取配置信息"),
                                  trUtf8("读取成功"));
            Read_Button_state = 0;
            motor[3].Read_Multi_Finsh_state = NO_SEND;
            motor[3].SDO_status = SDO_free;
               qDebug("motor[3].Read_Multi_Finsh_state == SUCCESS_SEND---------------");
        }
        else if (motor[3].Read_Multi_Finsh_state == FAIL_SEND)
        {
           QMessageBox::critical(0,QObject::trUtf8("读取配置信息"),
                                 trUtf8("读取失败"));
           Read_Button_state = 0;
           motor[3].SDO_status = SDO_free;
           motor[3].Read_Multi_Finsh_state = NO_SEND;
            qDebug("motor[3].Read_Multi_Finsh_state == FAIL_SEND--------------");
       }
//  else
//  {
//      motor[3].SDO_status = SDO_free;
//      Read_Button_state = 0;
//      motor[3].Read_Multi_Finsh_state = NO_SEND;
//      qDebug("motor[3].Read_Multi_Finsh_state == FAIL_SEND--------------");
//  }

}

}

}




