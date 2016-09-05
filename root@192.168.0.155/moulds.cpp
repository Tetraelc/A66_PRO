#include "moulds.h"
#include "ui_moulds.h"
#include <QDebug>
#include "qsoftkeyvalue.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "global.h"
#include "runstate.h"


QString m_strCtrlName;

Moulds::Moulds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moulds)
{
    ui->setupUi(this);

    initMoulds();

    ui->tableWidget_LowerMoulds->setColumnHidden(LowerMold_SpeedPostion,true);
    ui->tableWidget_LowerMoulds->setColumnHidden(LowerMold_SpeedChange,true);
    ui->tableWidget_LowerMoulds->setColumnHidden(LowerMold_Impedance,true);

    ui->tableWidget_UpMoulds->setColumnHidden(UpMold_Impedance,true);

    ui->tableWidget_UpMoulds->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_UpMoulds->horizontalHeader()->setClickable(false);    //******NEW********//
    ui->tableWidget_UpMoulds->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget_LowerMoulds->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_LowerMoulds->horizontalHeader()->setClickable(false);    //******NEW********//
    ui->tableWidget_LowerMoulds->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget_Material->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_Material->horizontalHeader()->setClickable(false);    //******NEW********//
    ui->tableWidget_Material->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

}


Moulds::~Moulds()
{
    delete ui;
}
void Moulds::openMouldsWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);
}



bool Moulds::eventFilter(QObject *watched, QEvent *event)
{
     if (watched==ui->lineEdit_D_Angle)         //首先判断控件(这里指 lineEdit1)
     {
          if (event->type()==QEvent::FocusIn)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {

            //  qDebug()<<"FocusIn";
          }
          else if (event->type()==QEvent::FocusOut)    // 这里指 lineEdit1 控件的失去焦点事件
          {
             //  qDebug()<<"FocusOut";
           }
     }
 return QWidget::eventFilter(watched,event);     // 最后将事件交给上层对话框

}



void Moulds::initMoulds(void)
{
    Display_UpMoldItem();
    Display_LowerMoldItem();
    Display_MaterialItem();

    ui->tableWidget_UpMoulds->selectRow(0);
    ui->tableWidget_LowerMoulds->selectRow(0);
    ui->tableWidget_Material->selectRow(0);

    ui->lineEdit_D_Height->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Height)->text());
    ui->lineEdit_D_V->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_DV)->text());
    ui->lineEdit_D_Angle->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Angle)->text());
    ui->lineEdit_D_Radius->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Radius)->text());
    ui->lineEdit_D_Speed->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_SpeedPostion)->text());
//    ui->lineEdit_D_XCorrect->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_SpeedChange)->text());
//    ui->lineEdit_D_Impedance->setText(ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Impedance)->text());

    ui->lineEdit_U_Height->setText(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Height)->text());
    ui->lineEdit_U_Angle->setText(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Angle)->text());
    ui->lineEdit_U_Radius->setText(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Radius)->text());
//    ui->lineEdit_U_Impedance->setText(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Impedance)->text());

    ui->lineEdit_Strengrht->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_StrengthFactor)->text());
    ui->lineEdit_EMold->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_EMold)->text());
    ui->lineEdit_MaterialName->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_Name)->text().split("-").at(1));

}



void Moulds::Display_UpMoldItem()
{
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("UpMold");
    //model.setFilter("ID > 0");
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_UpMoulds->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_UpMoulds->setRowCount(1);
        ui->tableWidget_UpMoulds->clear();
    }

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            ui->tableWidget_UpMoulds->setItem(i,UpMold_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_UpMoulds->setItem(i,UpMold_Angle,new QTableWidgetItem(record.value("Angle").toString()));
            ui->tableWidget_UpMoulds->setItem(i,UpMold_Height,new QTableWidgetItem(record.value("Height").toString()));
            ui->tableWidget_UpMoulds->setItem(i,UpMold_Radius,new QTableWidgetItem(record.value("Radius").toString()));
            ui->tableWidget_UpMoulds->setItem(i,UpMold_Impedance,new QTableWidgetItem(record.value("Impedance").toString()));
    }

   // ui->tableWidget_UpMoulds->selectRow(0);
    //db.close();//释放数据库

}


void Moulds::Display_LowerMoldItem()
{
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("LowerMold");
    //model.setFilter("ID > 0");
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_LowerMoulds->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setRowCount(1);
        ui->tableWidget_LowerMoulds->clear();
    }

    for(int i=0;i<model.rowCount();i++)
    {

            QSqlRecord record = model.record(i);
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_Height,new QTableWidgetItem(record.value("Height").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_DV,new QTableWidgetItem(record.value("D_V").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_Angle,new QTableWidgetItem(record.value("Angle").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_Radius,new QTableWidgetItem(record.value("Radius").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_SpeedPostion,new QTableWidgetItem(record.value("SpeedPostion").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_SpeedChange,new QTableWidgetItem(record.value("SpeedChange").toString()));
            ui->tableWidget_LowerMoulds->setItem(i,LowerMold_Impedance,new QTableWidgetItem(record.value("Impedance").toString()));
    }

    //db.close();//释放数据库

}


void Moulds::ReadforMold()
{






}


//上模表格输入
void Moulds::on_lineEdit_U_Height_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if( (ui->lineEdit_U_Height->text().toDouble(&ok) > 0) && (ui->lineEdit_U_Height->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Height, new QTableWidgetItem(ui->lineEdit_U_Height->text()));
        Update_UpMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text().toInt(),UpMold_Height,ui->lineEdit_U_Height->text());
    }
    else
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Height, new QTableWidgetItem(QString::number(CurrentUpMoldTemp.Height,'.',0)));
        ui->lineEdit_U_Height->setText(QString::number(CurrentUpMoldTemp.Height,'.',0));
    }
}
void Moulds::on_lineEdit_U_Angle_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if( (ui->lineEdit_U_Angle->text().toDouble(&ok) >= -90) && (ui->lineEdit_U_Angle->text().toDouble(&ok) <= 90) )
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Angle, new QTableWidgetItem(ui->lineEdit_U_Angle->text()));
        Update_UpMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text().toInt(),UpMold_Angle,ui->lineEdit_U_Angle->text());
    }
    else
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Angle, new QTableWidgetItem(QString::number(CurrentUpMoldTemp.Angle,'.',0)));
        ui->lineEdit_U_Angle->setText(QString::number(CurrentUpMoldTemp.Angle,'.',0));
    }
}
void Moulds::on_lineEdit_U_Radius_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_U_Radius->text().toDouble(&ok) > 0) && (ui->lineEdit_U_Radius->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Radius, new QTableWidgetItem(ui->lineEdit_U_Radius->text()));
        Update_UpMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text().toInt(),UpMold_Radius,ui->lineEdit_U_Radius->text());
    }
    else
    {
        ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Radius, new QTableWidgetItem(QString::number(CurrentUpMoldTemp.Radius,'.',0)));
        ui->lineEdit_U_Radius->setText(QString::number(CurrentUpMoldTemp.Radius,'.',0));
    }
}
void Moulds::on_lineEdit_U_Impedance_returnPressed()
{
//    ui->tableWidget_UpMoulds->setItem(ui->tableWidget_UpMoulds->currentRow(), UpMold_Impedance, new QTableWidgetItem(ui->lineEdit_U_Impedance->text()));
//    Update_UpMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text().toInt(),UpMold_Impedance,ui->lineEdit_U_Impedance->text());
}


//下模表格输入
void Moulds::on_lineEdit_D_Height_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_D_Height->text().toDouble(&ok) > 0) && (ui->lineEdit_D_Height->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Height, new QTableWidgetItem(ui->lineEdit_D_Height->text()));
        Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_Height,ui->lineEdit_D_Height->text());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Height, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.Height,'.',0)));
        ui->lineEdit_D_Height->setText(QString::number(CurrentLowerMoldTemp.Height,'.',0));
    }
}
void Moulds::on_lineEdit_D_V_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_D_V->text().toDouble(&ok) > 0) && (ui->lineEdit_D_V->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_DV, new QTableWidgetItem(ui->lineEdit_D_V->text()));
        Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_DV,ui->lineEdit_D_V->text());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_DV, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.D_V,'.',0)));
        ui->lineEdit_D_V->setText(QString::number(CurrentLowerMoldTemp.D_V,'.',0));
    }
}
void Moulds::on_lineEdit_D_Angle_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_D_Angle->text().toDouble(&ok) > 0) && (ui->lineEdit_D_Angle->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Angle, new QTableWidgetItem(ui->lineEdit_D_Angle->text()));
        Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_Angle,ui->lineEdit_D_Angle->text());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Angle, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.Angle,'.',0)));
        ui->lineEdit_D_Angle->setText(QString::number(CurrentLowerMoldTemp.Angle,'.',0));
    }
}
void Moulds::on_lineEdit_D_Radius_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_D_Radius->text().toDouble(&ok) > 0) && (ui->lineEdit_D_Radius->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Radius, new QTableWidgetItem(ui->lineEdit_D_Radius->text()));
        Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_Radius,ui->lineEdit_D_Radius->text());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Radius, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.Radius,'.',0)));
        ui->lineEdit_D_Radius->setText(QString::number(CurrentLowerMoldTemp.Radius,'.',0));
    }
}
void Moulds::on_lineEdit_D_Speed_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    if((ui->lineEdit_D_Speed->text().toDouble(&ok) > 0) && (ui->lineEdit_D_Speed->text().toDouble(&ok) <= 9999) )
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_SpeedPostion, new QTableWidgetItem(ui->lineEdit_D_Speed->text()));
        Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_SpeedPostion,ui->lineEdit_D_Speed->text());
    }
    else
    {
        ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_SpeedPostion, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.SpeedChangePos,'.',0)));
        ui->lineEdit_D_Speed->setText(QString::number(CurrentLowerMoldTemp.SpeedChangePos,'.',0));
    }
    //ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), 5, new QTableWidgetItem(ui->lineEdit_D_Speed->text()));
}
void Moulds::on_lineEdit_D_XCorrect_returnPressed()
{
//    ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_SpeedChange, new QTableWidgetItem(ui->lineEdit_D_XCorrect->text()));
//    Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_SpeedChange,ui->lineEdit_D_XCorrect->text());
    //ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), 6, new QTableWidgetItem(ui->lineEdit_D_XCorrect->text()));
}
void Moulds::on_lineEdit_D_Impedance_returnPressed()
{
//    ui->tableWidget_LowerMoulds->setItem(ui->tableWidget_LowerMoulds->currentRow(), LowerMold_Impedance, new QTableWidgetItem(ui->lineEdit_D_Impedance->text()));
//    Update_LowerMoldItem(ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),LowerMold_Id)->text().toInt(),LowerMold_Impedance,ui->lineEdit_D_Impedance->text());
}


void Moulds::on_tableWidget_LowerMoulds_itemSelectionChanged()
{
     QString CurrentLowerMoldId = ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text();

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("LowerMold");
    model.setFilter("ID = " +CurrentLowerMoldId);
    model.select();


    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);

            ui->lineEdit_D_Height->setText(record.value("Height").toString());
            ui->lineEdit_D_V->setText(record.value("D_V").toString());
            ui->lineEdit_D_Angle->setText(record.value("Angle").toString());
            ui->lineEdit_D_Radius->setText(record.value("Radius").toString());
            ui->lineEdit_D_Speed->setText(record.value("SpeedPostion").toString());
//            ui->lineEdit_D_XCorrect->setText(record.value("SpeedChange").toString());
//            ui->lineEdit_D_Impedance->setText(record.value("Impedance").toString());
            //qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }
    Current_LowerMoldRow = ui->tableWidget_LowerMoulds->currentRow();

    //db.close();//释放数据库

}

void Moulds::on_tableWidget_UpMoulds_itemSelectionChanged()
{

    QString CurrentUpMpldId = ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text();
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }


    QSqlTableModel model;
    model.setTable("UpMold");
    model.setFilter("ID = " +CurrentUpMpldId);
    model.select();


    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);

            ui->lineEdit_U_Height->setText(record.value("Height").toString());
            ui->lineEdit_U_Angle->setText(record.value("Angle").toString());
            ui->lineEdit_U_Radius->setText(record.value("Radius").toString());
//            ui->lineEdit_U_Impedance->setText(record.value("Impedance").toString());
            qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

     Current_UpMoldRow = ui->tableWidget_UpMoulds->currentRow();
  //  ui->tableWidget_UpMoulds->selectRow(0);
    //db.close();//释放数据库


}

void Moulds::Update_UpMoldItem(int Id,int Col,QString Value)
{
    QString Str_Id=QString::number(Id,10);

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    qDebug()<<"Value"<<Value;

    QSqlTableModel model;
    model.setTable("UpMold");
    model.setFilter("ID = " + Str_Id);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case UpMold_Height:record.setValue("Height",Value);
            break;
        case UpMold_Angle:record.setValue("Angle",Value);
            qDebug()<<"Angle";
            break;
        case UpMold_Radius:record.setValue("Radius",Value);
            break;
        case UpMold_Impedance:record.setValue("Impedance",Value);
            break;
        default :break;
        }


        model.setRecord(0,record);
        model.submitAll();
    }

    //db.close();//释放数据库
}


void Moulds::Update_LowerMoldItem(int Id,int Col,QString Value)
{
    QString Str_Id=QString::number(Id,10);

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("LowerMold");
    model.setFilter("ID = " + Str_Id);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case 1:record.setValue("Height",Value);
            break;
        case 2:record.setValue("D_V",Value);
            break;
        case 3:record.setValue("Angle",Value);
            break;
        case 4:record.setValue("Radius",Value);
            break;
        case 5:record.setValue("SpeedPostion",Value);
            break;
        case 6:record.setValue("SpeedChange",Value);
            break;
        case 7:record.setValue("Impedance",Value);
            break;
        default:break;
        }
        model.setRecord(0,record);
        model.submitAll();
    }

    //db.close();//释放数据库
}




//新建上模具库
void Moulds::on_pushButton_U_New_clicked()
{


}
//删除上模具库
void Moulds::on_pushButton_U_Del_clicked()
{



}


void  Moulds::DeleteUpMold()
{
    QString CurrentUpMoldId = ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }


   QSqlTableModel model;
   model.setTable("UpMold");
   model.setFilter("ID ="+ CurrentUpMoldId);
   model.select();
   if(model.rowCount() == 1)
   {
       model.removeRows(0,1);
       model.submitAll();

   }
   QSqlQuery query;
   query.exec("UPDATE UpMold SET ID = ID - 1 WHERE ID > " + QString::number(Current_UpMoldRow,10));


   //db.close();//释放数据库
}


void  Moulds::NewUpMold()
{
    //QString CurrentLowerMpldId = ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }


       QSqlTableModel model;
       model.setTable("UpMold");
       int row = 0;
       model.insertRows(row,1);
       model.setData(model.index(row,UpMold_Height),ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Height)->text());
       model.setData(model.index(row,UpMold_Angle),ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Angle)->text());
       model.setData(model.index(row,UpMold_Radius),ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Radius)->text());
       model.setData(model.index(row,UpMold_Impedance),ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Impedance)->text());

       model.submitAll();

   //db.close();//释放数据库
}


void  Moulds::DeleteLowerMold()
{
    QString CurrentLowerMoldId = ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }


   QSqlTableModel model;
   model.setTable("LowerMold");
   model.setFilter("ID ="+ CurrentLowerMoldId);
   model.select();
   if(model.rowCount() == 1)
   {
       model.removeRows(0,1);
       model.submitAll();
   }

   QSqlQuery query;
   query.exec("UPDATE LowerMold SET ID = ID - 1 WHERE ID > " + QString::number(Current_LowerMoldRow,10));
   //db.close();//释放数据库

}


//新建上模具库
void Moulds::on_pushButton_D_New_clicked()
{


}
void Moulds::on_pushButton_D_Del_clicked()
{


}

void  Moulds::NewLowerMold()
{
    //QString CurrentLowerMpldId = ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }


   QSqlTableModel model;
   model.setTable("LowerMold");
   int row = 0;
   model.insertRows(row,1);

   model.setData(model.index(row,LowerMold_Height),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Height)->text());
   model.setData(model.index(row,LowerMold_DV),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_DV)->text());
   model.setData(model.index(row,LowerMold_Angle),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Angle)->text());
   model.setData(model.index(row,LowerMold_Radius),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Radius)->text());
   model.setData(model.index(row,LowerMold_SpeedPostion),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_SpeedPostion)->text());
   model.setData(model.index(row,LowerMold_SpeedChange),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_SpeedChange)->text());
   model.setData(model.index(row,LowerMold_Impedance),ui->tableWidget_LowerMoulds->item(ui->tableWidget_LowerMoulds->currentRow(),LowerMold_Impedance)->text());

   model.submitAll();
   //db.close();//释放数据库
}


void Moulds::on_pushButton_U_Down_clicked()
{

}
void Moulds::on_pushButton_U_Up_clicked()
{

}

void Moulds::on_pushButton_D_Up_clicked()
{

}
void Moulds::on_pushButton_D_Down_clicked()
{

}

void Moulds::on_pushButton_Left_1_clicked()
{
    if(ui->tableWidget_LowerMoulds->currentRow()==0)
    {
       ui->tableWidget_LowerMoulds->selectRow(ui->tableWidget_LowerMoulds->rowCount()-1);
    }
    else
    {
       ui->tableWidget_LowerMoulds->selectRow(ui->tableWidget_LowerMoulds->currentRow()-1);
    }
}

void Moulds::on_pushButton_Left_4_clicked()
{
    if(ui->tableWidget_LowerMoulds->currentRow()==ui->tableWidget_LowerMoulds->rowCount()-1)
    {
       ui->tableWidget_LowerMoulds->selectRow(0);
    }
    else
    {
       ui->tableWidget_LowerMoulds->selectRow(ui->tableWidget_LowerMoulds->currentRow()+1);
    }
}

void Moulds::on_pushButton_Left_2_clicked()
{
    NewLowerMold();
    Display_LowerMoldItem();
    ui->tableWidget_LowerMoulds->selectRow(ui->tableWidget_LowerMoulds->rowCount()-1);
}

void Moulds::on_pushButton_Left_3_clicked()
{
    if(ui->tableWidget_LowerMoulds->rowCount()>1)
    {
        DeleteLowerMold();
        Display_LowerMoldItem();
    }
}

void Moulds::on_pushButton_Left_12_clicked()
{
    if(ui->tableWidget_UpMoulds->currentRow()==0)
    {
       ui->tableWidget_UpMoulds->selectRow(ui->tableWidget_UpMoulds->rowCount()-1);
    }
    else
    {
    ui->tableWidget_UpMoulds->selectRow(ui->tableWidget_UpMoulds->currentRow()-1);
    }
}

void Moulds::on_pushButton_Left_9_clicked()
{
    if(ui->tableWidget_UpMoulds->currentRow()==ui->tableWidget_UpMoulds->rowCount()-1)
    {
       ui->tableWidget_UpMoulds->selectRow(0);
    }
    else
    {
       ui->tableWidget_UpMoulds->selectRow(ui->tableWidget_UpMoulds->currentRow()+1);
    }
}

void Moulds::on_pushButton_Left_8_clicked()
{
    NewUpMold();
    Display_UpMoldItem();
    ui->tableWidget_UpMoulds->selectRow(ui->tableWidget_UpMoulds->rowCount()-1);
}

void Moulds::on_pushButton_Left_10_clicked()
{
    if(ui->tableWidget_UpMoulds->rowCount()>1)
    {
        DeleteUpMold();
        Display_UpMoldItem();
    }
}

void Moulds::Display_MaterialItem()
{
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("Materialdb");
    //model.setFilter("ID > 0");
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_Material->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_Material->setRowCount(1);
        ui->tableWidget_Material->clear();
    }

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            ui->tableWidget_Material->setItem(i,Material_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_Material->setItem(i,Material_Name,new QTableWidgetItem(record.value("Name").toString()));
            ui->tableWidget_Material->setItem(i,Material_EMold,new QTableWidgetItem(record.value("EMold").toString()));
            ui->tableWidget_Material->setItem(i,Material_StrengthFactor,new QTableWidgetItem(record.value("StrengthFactor").toString()));

    }


    //db.close();//释放数据库
     //ui->tableWidget_Material->selectRow(0);
}


void  Moulds::DeleteMaterial()
{
    QString CurrentMaterialId = ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }


   QSqlTableModel model;
   model.setTable("Materialdb");
   model.setFilter("ID ="+ CurrentMaterialId);
   model.select();
   if(model.rowCount() == 1)
   {
       model.removeRows(0,1);
       model.submitAll();

   }
   QSqlQuery query;
   query.exec("UPDATE Materialdb SET ID = ID - 1 WHERE ID > " + QString::number(CurrentReg.Current_MaterialRow,10));


   //db.close();//释放数据库
}


bool  Moulds::NewMaterial()
{
    //QString CurrentLowerMpldId = ui->tableWidget_UpMoulds->item(ui->tableWidget_UpMoulds->currentRow(),UpMold_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }
    //////材料库不重复//////
//    QSqlTableModel model;
//    model.setTable("Materialdb");
//   // model.setFilter("ID = " +CurrentLowerMoldId);
//    model.select();


//    for(int i=0;i<model.rowCount();i++)
//    {
//            QSqlRecord record = model.record(i);

//            if((ui->comboBox_material->currentText() + "-" + ui->lineEdit_MaterialName->text()) == record.value("Name").toString() )
//            {
//                qDebug()<<"record.value("").toString()"<<record.value("Name").toString();
//                MutiMaterial = 0 ;

//                return false;

//            }

//            //qDebug()<<"record.value().toString()"<<record.value("Id").toString();
//    }

    //////材料库不重复//////

   QSqlTableModel model;
   model.setTable("Materialdb");
   int row = 0;
   model.insertRows(row,1);
   model.setData(model.index(row,Material_Name),ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Name)->text());
   model.setData(model.index(row,Material_EMold),ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_EMold)->text());
   model.setData(model.index(row,Material_StrengthFactor),ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_StrengthFactor)->text());
   model.submitAll();

   //db.close();//释放数据库
}



void Moulds::on_pushButton_M_Up_clicked()
{
   if(ui->tableWidget_Material->currentRow()==0)
    {
       ui->tableWidget_Material->selectRow(ui->tableWidget_Material->rowCount()-1);
    }
    else
    {
       ui->tableWidget_Material->selectRow(ui->tableWidget_Material->currentRow()-1);
    }
}

void Moulds::on_pushButton_M_Down_clicked()
{
    if(ui->tableWidget_Material->currentRow()==ui->tableWidget_Material->rowCount()-1)
    {
       ui->tableWidget_Material->selectRow(0);
    }
    else
    {
       ui->tableWidget_Material->selectRow(ui->tableWidget_Material->currentRow()+1);
    }
}

void Moulds::on_pushButton_M_New_clicked()
{
    NewMaterial();
//    if(MutiMaterial == 1)
//    {
        Display_MaterialItem();
        ui->tableWidget_Material->selectRow(ui->tableWidget_Material->rowCount()-1);
//    }
//    MutiMaterial = 1;

}

void Moulds::on_pushButton_M_Del_clicked()
{
    if(ui->tableWidget_Material->rowCount()>1)
    {
        DeleteMaterial();
        Display_MaterialItem();
    }
}



void Moulds::on_tableWidget_Material_itemSelectionChanged()
{

    CurrentReg.Current_MaterialRow = ui->tableWidget_Material->currentRow();
    ui->lineEdit_Strengrht->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_StrengthFactor)->text());
    ui->lineEdit_EMold->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_EMold)->text());
    ui->lineEdit_MaterialName->setText(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_Name)->text().split("-").at(1));

    if(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_Name)->text().split("-").at(0).compare(trUtf8("铝")) == 0 )
    {
        ui->comboBox_material->setCurrentIndex(0);
    }
    if(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_Name)->text().split("-").at(0).compare(trUtf8("不锈钢")) == 0 )
    {
        ui->comboBox_material->setCurrentIndex(1);
    }
    if(ui->tableWidget_Material->item(CurrentReg.Current_MaterialRow,Material_Name)->text().split("-").at(0).compare(trUtf8("铁")) == 0 )
    {
        ui->comboBox_material->setCurrentIndex(2);
    }


}


void Moulds::Update_MaterialItem(int Id,int Col,QString Value)
{
    QString Str_Id=QString::number(Id,10);

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("Materialdb");
    model.setFilter("ID = " + Str_Id);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case Material_Name:record.setValue("Name",Value);  break;
        case Material_EMold:record.setValue("EMold",Value);   break;
        case Material_StrengthFactor:record.setValue("StrengthFactor",Value);
            break;
        default:break;
        }
        model.setRecord(0,record);
        model.submitAll();
    }

    //db.close();//释放数据库
}

void Moulds::on_lineEdit_Strengrht_returnPressed()
{
    ui->tableWidget_Material->setItem(ui->tableWidget_Material->currentRow(), Material_StrengthFactor, new QTableWidgetItem(ui->lineEdit_Strengrht->text()));
    Update_MaterialItem(ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Id)->text().toInt(),Material_StrengthFactor,ui->lineEdit_Strengrht->text());

}

void Moulds::on_lineEdit_MaterialName_returnPressed()
{
    ui->tableWidget_Material->setItem(ui->tableWidget_Material->currentRow(),Material_Name,new QTableWidgetItem(ui->comboBox_material->currentText() + "-" + ui->lineEdit_MaterialName->text()));
    Update_MaterialItem(ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Id)->text().toInt(),Material_Name,ui->comboBox_material->currentText() + "-"  + ui->lineEdit_MaterialName->text());

}


void Moulds::on_lineEdit_EMold_returnPressed()
{
    ui->tableWidget_Material->setItem(ui->tableWidget_Material->currentRow(), Material_EMold, new QTableWidgetItem(ui->lineEdit_Strengrht->text()));
    Update_MaterialItem(ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Id)->text().toInt(),Material_EMold,ui->lineEdit_EMold->text());

}

void Moulds::on_comboBox_material_currentIndexChanged(int index)
{
    ui->tableWidget_Material->setItem(ui->tableWidget_Material->currentRow(),Material_Name,new QTableWidgetItem(ui->comboBox_material->currentText() + "-" + ui->lineEdit_MaterialName->text()));
    Update_MaterialItem(ui->tableWidget_Material->item(ui->tableWidget_Material->currentRow(),Material_Id)->text().toInt(),Material_Name,ui->comboBox_material->currentText() + "-"  + ui->lineEdit_MaterialName->text());

}





