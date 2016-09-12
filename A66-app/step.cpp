#include "step.h"
#include "ui_step.h"
#include <QDebug>
#include "global.h"
#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "mathcalculation.h"
#include "deleoplength.h"



bool scanAngleFlag = false;
bool scanAngleCompensateFlag =false;

Step::Step(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Step)
{
    ui->setupUi(this);

    yValue_Scan =startTimer(10);
//    RunState runstate1 ;
//    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    QRegExp rxstep("^(-?[0]|-?[1-9][0-9]{0,3})(?:\\.\\d{1,2})?$|(^\\t?$)");
    QRegExpValidator *pRegstep = new QRegExpValidator(rxstep, this);

    ui->lineEdit_S_Raxis->setValidator(pRegstep);
    ui->lineEdit_S_return->setValidator(pRegstep);
    ui->lineEdit_S_Xaxis->setValidator(pRegstep);

    ui->lineEdit_S_distance->setValidator(pRegstep);
    ui->lineEdit_S_AngleCompensate->setValidator(pRegstep);
    ui->lineEdit_S_XaxisCorrect->setValidator(pRegstep);
    ui->lineEdit_S_Holding->setValidator(pRegstep);
    ui->lineEdit_S_Angle->setValidator(pRegstep);

}

Step::~Step()
{
    delete ui;
}

void Step::openStepWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);


    ui->tableWidget_Step->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_Step->horizontalHeader()->setClickable(false);    //******NEW********//
    ui->tableWidget_Step->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget_Step->setColumnHidden(StepProgram_ReturnTime,true);
    ui->tableWidget_Step->setColumnHidden(StepProgram_HoldingTime,true);
    ui->tableWidget_Step->setColumnHidden(StepProgram_Pressure,true);

    Display_StepProgramItem();
    ui->tableWidget_Step->selectRow(0);

    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    CurrentStepTemp.Pressure = mathcal.pressureCal(CurrentProgramTemp.BroadWideth,CurrentProgramTemp.BroadThick,CurrentMaterialTemp.StrengthFactor,CurrentLowerMoldTemp.D_V);
    ui->lineEdit_S_pressure->setText(QString::number(CurrentStepTemp.Pressure,'.',2));
    ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(),StepProgram_Pressure,new QTableWidgetItem(QString::number(CurrentStepTemp.Pressure,'.',2)));
    Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Pressure,ui->lineEdit_S_pressure->text());

}

void Step::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()==yValue_Scan){

//         MathCalculation *mathcal = new MathCalculation;
        if(scanAngleFlag == true || scanAngleCompensateFlag  == true)
        {
            qDebug()<<"AngleToYDis"<<QString::number(CurrentStepTemp.Angle,'.',0).toInt()<<QString::number(CurrentStepTemp.AngleCompensate,'.',0).toInt()<<CurrentProgramTemp.BroadThick<<CurrentStepTemp.Yzero;
             CurrentStepTemp.Yaxis = mathcal.AngleToYDis(QString::number(CurrentStepTemp.Angle,'.',0).toInt(),QString::number(CurrentStepTemp.AngleCompensate,'.',0).toInt(),0,CurrentProgramTemp.BroadThick,0, CurrentStepTemp.Yzero);
             scanAngleFlag = false;
             scanAngleCompensateFlag = false;
             ui->lineEdit_S_Yaxis->setText(QString::number(CurrentStepTemp.Yaxis,'.',2));
             ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(),StepProgram_Yaxis,new QTableWidgetItem(QString::number(CurrentStepTemp.Yaxis,'.',2)));
             Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Yaxis,ui->lineEdit_S_Yaxis->text());
             qDebug()<<"timerEvent"<<CurrentStepTemp.Angle<<CurrentStepTemp.AngleCompensate<<CurrentProgramTemp.BroadThick<<CurrentStepTemp.Yzero<<CurrentStepTemp.Yaxis;

//             double MathCalculation::pressureCal(double boardWidth,double boardTick,double strength,double moldV)
        }
//内存可能泄露

    }

}


void Step::Display_StepProgramItem()
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
        ui->tableWidget_Step->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_Step->setRowCount(1);
        ui->tableWidget_Step->clear();
    }

   // ui->tableWidget_Step->clearContents();
    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            bool ok;
            ui->tableWidget_Step->setItem(i,StepProgram_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_Step->setItem(i,StepProgram_Angle,new QTableWidgetItem(QString::number(record.value("Angle").toDouble(&ok),'.',2)));
//            if(record.value("AngleCompensate").toInt() > 0)
//            {
//             ui->tableWidget_Step->setItem(i,StepProgram_AngleCompensate,new QTableWidgetItem("+" + record.value("AngleCompensate").toString()));
//            }
//            else
//            {
             ui->tableWidget_Step->setItem(i,StepProgram_AngleCompensate,new QTableWidgetItem(QString::number(record.value("AngleCompensate").toDouble(&ok),'.',2)));
//            }

            ui->tableWidget_Step->setItem(i,StepProgram_Yaxis,new QTableWidgetItem(QString::number(record.value("Yaxis").toDouble(&ok),'.',2) ));
            ui->tableWidget_Step->setItem(i,StepProgram_Xaxis,new QTableWidgetItem(QString::number(record.value("Xaxis").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_XaxisCorrect,new QTableWidgetItem(QString::number(record.value("XaxisCorrect").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_Distance,new QTableWidgetItem(QString::number(record.value("Distance").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_Pressure,new QTableWidgetItem(QString::number(record.value("Pressure").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_ReturnTime,new QTableWidgetItem(QString::number(record.value("ReturnTime").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_HoldingTime,new QTableWidgetItem(QString::number(record.value("Holding").toDouble(&ok),'.',2)));
            ui->tableWidget_Step->setItem(i,StepProgram_Raxis,new QTableWidgetItem(QString::number(record.value("Raxis").toDouble(&ok),'.',2)));

    }

    //db.close();//释放数据库

}


void  Step::NewStepProgram()
{
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }
   QSqlTableModel model_StepTotal;
   QSqlTableModel model;
   model.setTable(CurrentReg.CurrentProgramName);
   int row = 0;
   model.insertRows(row,1);
   model.setData(model.index(row,StepProgram_Angle),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Angle)->text());
   model.setData(model.index(row,StepProgram_AngleCompensate),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_AngleCompensate)->text());
   model.setData(model.index(row,StepProgram_Yaxis),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Yaxis)->text());
   model.setData(model.index(row,StepProgram_Xaxis),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Xaxis)->text());
   model.setData(model.index(row,StepProgram_XaxisCorrect),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_XaxisCorrect)->text());
   model.setData(model.index(row,StepProgram_Distance),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Distance)->text());
   model.setData(model.index(row,StepProgram_Pressure),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Pressure)->text());
   model.setData(model.index(row,StepProgram_ReturnTime),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_ReturnTime)->text());
   model.setData(model.index(row,StepProgram_HoldingTime),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_HoldingTime)->text());
   model.setData(model.index(row,StepProgram_Raxis),ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Raxis)->text());

   model.submitAll();

   model_StepTotal.setTable("ProgramLib");
   model_StepTotal.setFilter("ID = " + QString::number(CurrentReg.Current_ProgramLibRow+1,10));
   model_StepTotal.select();
   if(model_StepTotal.rowCount() == 1)
   {
       QSqlRecord record = model_StepTotal.record(0);
       record.setValue("StepTotal",QString::number(ui->tableWidget_Step->rowCount()+1,10));
       model_StepTotal.setRecord(0,record);
       model_StepTotal.submitAll();
   }
   //db.close();//释放数据库
}


void  Step::DeleteStepProgram()
{
    QString CurrentStepProgramId = ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text();
//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }

   QSqlTableModel model_StepTotal;
   QSqlTableModel model;
   model.setTable(CurrentReg.CurrentProgramName);
   model.setFilter("ID ="+ CurrentStepProgramId);
   model.select();
   if(model.rowCount() == 1)
   {
       model.removeRows(0,1);
       model.submitAll();
   }

   QSqlQuery query;
   query.exec("UPDATE " + CurrentReg.CurrentProgramName + " SET ID = ID - 1 WHERE ID > " + QString::number(CurrentReg.Current_StepProgramRow,10));


   model_StepTotal.setTable("ProgramLib");
   model_StepTotal.setFilter("ID = " + QString::number(CurrentReg.Current_ProgramLibRow+1,10));
   model_StepTotal.select();
   if(model_StepTotal.rowCount() == 1)
   {
       QSqlRecord record = model_StepTotal.record(0);
       record.setValue("StepTotal",QString::number(ui->tableWidget_Step->rowCount()-1,10));
       model_StepTotal.setRecord(0,record);
       model_StepTotal.submitAll();
   }

   ReflashLinedit();

   //db.close();//释放数据库
}


void Step::Update_StepProgramItem(int Id,int Col,QString Value)
{
    QString Str_Id=QString::number(Id,10);

//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable(CurrentReg.CurrentProgramName);
    model.setFilter("ID = " + Str_Id);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case StepProgram_Angle:record.setValue("Angle",Value);
            break;
        case StepProgram_AngleCompensate:record.setValue("AngleCompensate",Value);
            break;
        case StepProgram_Yaxis:record.setValue("Yaxis",Value);
            break;
        case StepProgram_Xaxis:record.setValue("Xaxis",Value);
            break;
        case StepProgram_XaxisCorrect:record.setValue("XaxisCorrect",Value);
            break;
        case StepProgram_Distance:record.setValue("Distance",Value);
            break;
        case StepProgram_Pressure:record.setValue("Pressure",Value);
            break;
        case StepProgram_ReturnTime:record.setValue("RetrunTime",Value);
            break;
        case StepProgram_HoldingTime:record.setValue("HoldingTime",Value);
            break;
        case StepProgram_Raxis:record.setValue("Raxis",Value);
            break;
        default :break;
        }

        model.setRecord(0,record);
        model.submitAll();
    }

    //db.close();//释放数据库
}

//工步编程tableWidget_Step和lineEdit_S建立链接
void Step::on_lineEdit_S_Angle_returnPressed()
{

    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    bool ok;
    if( (ui->lineEdit_S_Angle->text().toDouble(&ok) >= CurrentLowerMoldTemp.Angle) && (ui->lineEdit_S_Angle->text().toDouble(&ok) <= 180) )
    {

        CurrentStepTemp.Angle = ui->lineEdit_S_Angle->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Angle, new QTableWidgetItem(ui->lineEdit_S_Angle->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Angle,ui->lineEdit_S_Angle->text());
        scanAngleFlag = true;
    }else
    {
        if(ui->lineEdit_S_Angle->text().toDouble(&ok) <=  CurrentLowerMoldTemp.Angle)
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Angle, new QTableWidgetItem(QString::number(CurrentLowerMoldTemp.Angle,'.',0)));
            ui->lineEdit_S_Angle->setText(QString::number(CurrentLowerMoldTemp.Angle,'.',0));
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Angle,ui->lineEdit_S_Angle->text());
        }
        else
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Angle, new QTableWidgetItem(QString::number(CurrentStepTemp.Angle,'.',0)));
            ui->lineEdit_S_Angle->setText(QString::number(CurrentStepTemp.Angle,'.',0));
        }

    }

  // MathCalculation::AngleToYDis(ui->lineEdit_S_Angle->text(),ui->lineEdit_S_AngleCompensate->text(),0,float boardThick,float moldThick,float YZero);
}
void Step::on_lineEdit_S_AngleCompensate_returnPressed()
{

    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

//    if(ui->lineEdit_S_AngleCompensate->text().left(1) == "+")
//    {
    if((ui->lineEdit_S_AngleCompensate->text().toDouble(&ok) >= -90) && (ui->lineEdit_S_AngleCompensate->text().toDouble(&ok) <= 90) && !(ui->lineEdit_S_AngleCompensate->text() == "") )
        {
            //CurrentStepTemp.XaxisCorrect = ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok);
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_AngleCompensate, new QTableWidgetItem(ui->lineEdit_S_AngleCompensate->text()));
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_AngleCompensate,ui->lineEdit_S_AngleCompensate->text());
            ui->lineEdit_S_AngleCompensate->setText(ui->lineEdit_S_AngleCompensate->text());
        }
        else
        {
            if(ui->lineEdit_S_AngleCompensate->text() == "")
            {
                ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_AngleCompensate, new QTableWidgetItem(QString::number(0,10)));
                ui->lineEdit_S_AngleCompensate->setText("0");
                Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_AngleCompensate,ui->lineEdit_S_AngleCompensate->text());
            }
            else
            {
                ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_AngleCompensate, new QTableWidgetItem(QString::number(CurrentStepTemp.AngleCompensate,'.',0)));
                ui->lineEdit_S_AngleCompensate->setText(QString::number(CurrentStepTemp.AngleCompensate,'.',0));
            }

        }

//    }

//   else
//    {

//        if( (ui->lineEdit_S_AngleCompensate->text().toDouble(&ok)  > -90) && (ui->lineEdit_S_AngleCompensate->text().toDouble(&ok)  <= 90) )
//        {
//            //CurrentStepTemp.XaxisCorrect = ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok);
//            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_AngleCompensate, new QTableWidgetItem("+"+ui->lineEdit_S_AngleCompensate->text()));
//            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_AngleCompensate,ui->lineEdit_S_AngleCompensate->text());
//            ui->lineEdit_S_AngleCompensate->setText("+"+ui->lineEdit_S_AngleCompensate->text());
//        }
//        else
//        {
//            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_AngleCompensate, new QTableWidgetItem("+"+QString::number(CurrentStepTemp.AngleCompensate,'.',0)));
//            ui->lineEdit_S_AngleCompensate->setText("+"+QString::number(CurrentStepTemp.AngleCompensate,'.',0));
//        }


//    }



}
void Step::on_lineEdit_S_Yaxis_returnPressed()
{   
//    bool ok;
//    if( (ui->lineEdit_S_Yaxis->text().toDouble(&ok) >= 0) && (ui->lineEdit_S_Yaxis->text().toDouble(&ok) <= 9999) )
//    {
//        CurrentStepTemp.Yaxis = ui->lineEdit_S_Yaxis->text().toDouble(&ok);
//        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Yaxis, new QTableWidgetItem(ui->lineEdit_S_Yaxis->text()));
//        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Yaxis,ui->lineEdit_S_Yaxis->text());
//    }else
//    {
//        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Yaxis, new QTableWidgetItem(QString::number(CurrentStepTemp.Yaxis,'.',0)));
//        ui->lineEdit_S_Yaxis->setText(QString::number(CurrentStepTemp.Yaxis,'.',0));
//    }

}
void Step::on_lineEdit_S_Xaxis_returnPressed()
{

    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    if( (ui->lineEdit_S_Xaxis->text().toDouble(&ok) >= 0) && (ui->lineEdit_S_Xaxis->text().toDouble(&ok) <= 9999) && (ui->lineEdit_S_Xaxis->text() != "") )
    {
       // CurrentStepTemp.Xaxis = ui->lineEdit_S_Yaxis->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Xaxis, new QTableWidgetItem(ui->lineEdit_S_Xaxis->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Xaxis,ui->lineEdit_S_Xaxis->text());
//        qDebug()<<"ui->lineEdit_S_Xaxis->text()"<<ui->lineEdit_S_Xaxis->text();
    }else
    {

        if(ui->lineEdit_S_Xaxis->text() == "")
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Xaxis, new QTableWidgetItem(QString::number(0,10)));
            ui->lineEdit_S_Xaxis->setText("0");
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Xaxis,ui->lineEdit_S_Xaxis->text());
        }
        else
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Xaxis, new QTableWidgetItem(QString::number(CurrentStepTemp.Xaxis,'.',0)));
            ui->lineEdit_S_Xaxis->setText(QString::number(CurrentStepTemp.Xaxis,'.',0));

        }
//        qDebug()<<"CurrentStepTemp.Xaxis"<<CurrentStepTemp.Xaxis;
    }

}
void Step::on_lineEdit_S_XaxisCorrect_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);


//    if(ui->lineEdit_S_XaxisCorrect->text().left(1) == "+")
//    {
        if( (ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok) >= 0) && (ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok) <= 9999) && (ui->lineEdit_S_XaxisCorrect->text() != "") )
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_XaxisCorrect, new QTableWidgetItem(ui->lineEdit_S_XaxisCorrect->text()));
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_XaxisCorrect,ui->lineEdit_S_XaxisCorrect->text());
            ui->lineEdit_S_XaxisCorrect->setText(ui->lineEdit_S_XaxisCorrect->text());
        }
        else
        {
            if(ui->lineEdit_S_XaxisCorrect->text() == "")
            {
                ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_XaxisCorrect, new QTableWidgetItem(QString::number(0,10)));
                ui->lineEdit_S_XaxisCorrect->setText("0");
                Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_XaxisCorrect,ui->lineEdit_S_XaxisCorrect->text());
            }
            else
            {
                ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_XaxisCorrect, new QTableWidgetItem(QString::number(CurrentStepTemp.XaxisCorrect,'.',0)));
                ui->lineEdit_S_XaxisCorrect->setText(QString::number(CurrentStepTemp.XaxisCorrect,'.',0));
            }
        }

//    }

//   else
//    {

//        if( (ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok)  > 0) && (ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok)  <= 9999) )
//        {
//            //CurrentStepTemp.XaxisCorrect = ui->lineEdit_S_XaxisCorrect->text().toDouble(&ok);
//            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_XaxisCorrect, new QTableWidgetItem("+"+ui->lineEdit_S_XaxisCorrect->text()));
//            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_XaxisCorrect,ui->lineEdit_S_XaxisCorrect->text());
//            ui->lineEdit_S_XaxisCorrect->setText("+"+ui->lineEdit_S_XaxisCorrect->text());
//            qDebug()<<"ui->lineEdit_S_XaxisCorrect->text()"<<ui->lineEdit_S_XaxisCorrect->text();
//        }
//        else
//        {
//            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_XaxisCorrect, new QTableWidgetItem("+"+QString::number(CurrentStepTemp.XaxisCorrect,'.',0)));
//            ui->lineEdit_S_XaxisCorrect->setText("+"+QString::number(CurrentStepTemp.XaxisCorrect,'.',0));
//        }

//    }

}
void Step::on_lineEdit_S_distance_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    if( (ui->lineEdit_S_distance->text().toDouble(&ok) >= 0) && (ui->lineEdit_S_distance->text().toDouble(&ok) <= 9999) && (ui->lineEdit_S_distance->text() != ""))
    {
        //CurrentStepTemp.concedeDistance = ui->lineEdit_S_distance->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Distance, new QTableWidgetItem(ui->lineEdit_S_distance->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Distance,ui->lineEdit_S_distance->text());
    }else
    {
        if(ui->lineEdit_S_distance->text() == "")
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Distance, new QTableWidgetItem(QString::number(0,10)));
            ui->lineEdit_S_distance->setText("0");
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Distance,ui->lineEdit_S_distance->text());
        }
        else
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Distance, new QTableWidgetItem(QString::number(CurrentStepTemp.concedeDistance,'.',0)));
            ui->lineEdit_S_distance->setText(QString::number(CurrentStepTemp.concedeDistance,'.',0));
        }
    }

}
void Step::on_lineEdit_S_pressure_returnPressed()
{
    bool ok;
    if( (ui->lineEdit_S_pressure->text().toDouble(&ok) > 0) && (ui->lineEdit_S_pressure->text().toDouble(&ok) <= 99) )
    {
        CurrentStepTemp.Pressure = ui->lineEdit_S_pressure->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Pressure, new QTableWidgetItem(ui->lineEdit_S_pressure->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Pressure,ui->lineEdit_S_pressure->text());
    }else
    {
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Pressure, new QTableWidgetItem(QString::number(CurrentStepTemp.Pressure,'.',0)));
        ui->lineEdit_S_pressure->setText(QString::number(CurrentStepTemp.Pressure,'.',0));
    }

}
void Step::on_lineEdit_S_return_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    if( (ui->lineEdit_S_return->text().toDouble(&ok) > 0) && (ui->lineEdit_S_return->text().toDouble(&ok) <= 9999) )
    {
        CurrentStepTemp.ReturnTime = ui->lineEdit_S_return->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_ReturnTime, new QTableWidgetItem(ui->lineEdit_S_return->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_ReturnTime,ui->lineEdit_S_return->text());
    }else
    {
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_ReturnTime, new QTableWidgetItem(QString::number(CurrentStepTemp.ReturnTime,'.',0)));
        ui->lineEdit_S_return->setText(QString::number(CurrentStepTemp.ReturnTime,'.',0));
    }

}
void Step::on_lineEdit_S_Holding_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    if( (ui->lineEdit_S_Holding->text().toDouble(&ok) > 0) && (ui->lineEdit_S_Holding->text().toDouble(&ok) <= 99) )
    {
        CurrentStepTemp.Holding = ui->lineEdit_S_Holding->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_HoldingTime, new QTableWidgetItem(ui->lineEdit_S_Holding->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_HoldingTime,ui->lineEdit_S_Holding->text());
    }else
    {
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_HoldingTime, new QTableWidgetItem(QString::number(CurrentStepTemp.Holding,'.',0)));
        ui->lineEdit_S_Holding->setText(QString::number(CurrentStepTemp.Holding,'.',0));
    }

}
void Step::on_lineEdit_S_Raxis_returnPressed()
{
    bool ok;
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);
    if( (ui->lineEdit_S_Raxis->text().toDouble(&ok) >= 0) && (ui->lineEdit_S_Raxis->text().toDouble(&ok) <= 9999) && (ui->lineEdit_S_Raxis->text() != ""))
    {
        CurrentStepTemp.Raxis = ui->lineEdit_S_Raxis->text().toDouble(&ok);
        ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Raxis, new QTableWidgetItem(ui->lineEdit_S_Raxis->text()));
        Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Raxis,ui->lineEdit_S_Raxis->text());
    }else
    {
        if(ui->lineEdit_S_Raxis->text() == "")
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Raxis, new QTableWidgetItem(QString::number(0,10)));
            ui->lineEdit_S_Raxis->setText("0");
            Update_StepProgramItem(ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text().toInt(),StepProgram_Raxis,ui->lineEdit_S_Raxis->text());
        }
        else
        {
            ui->tableWidget_Step->setItem(ui->tableWidget_Step->currentRow(), StepProgram_Raxis, new QTableWidgetItem(QString::number(CurrentStepTemp.Raxis,'.',0)));
            ui->lineEdit_S_Raxis->setText(QString::number(CurrentStepTemp.Raxis,'.',0));
        }
    }


}


void Step::ReflashLinedit()
{

    QString CurrentStepProgramId = ui->tableWidget_Step->item(ui->tableWidget_Step->currentRow(),StepProgram_Id)->text();

//   if(!db.open())
//   {
//       QMessageBox::critical(0,QObject::tr("Error"),
//                             db.lastError().text());//打开数据库连接
//   }

   QSqlTableModel model;
   model.setTable(CurrentReg.CurrentProgramName);
   model.setFilter("ID = " +CurrentStepProgramId);
   model.select();

   for(int i=0;i<model.rowCount();i++)
   {
           QSqlRecord record = model.record(i);

           bool ok;
           ui->lineEdit_S_Angle->setText(QString::number(record.value("Angle").toDouble(&ok),'.',2));
           ui->lineEdit_S_AngleCompensate->setText(QString::number(record.value("AngleCompensate").toDouble(&ok),'.',2));
//           if(record.value("AngleCompensate").toInt() > 0)
//           {
             //  ui->lineEdit_S_AngleCompensate->setText(ui->lineEdit_S_AngleCompensate->text());
//           }
           ui->lineEdit_S_Yaxis->setText(QString::number(record.value("Yaxis").toDouble(&ok),'.',2));
           ui->lineEdit_S_Xaxis->setText(QString::number(record.value("Xaxis").toDouble(&ok),'.',2));
           ui->lineEdit_S_XaxisCorrect->setText(QString::number(record.value("XaxisCorrect").toDouble(&ok),'.',2));

           ui->lineEdit_S_distance->setText(QString::number(record.value("Distance").toDouble(&ok),'.',2));
           ui->lineEdit_S_pressure->setText(QString::number(record.value("Pressure").toDouble(&ok),'.',2));
           ui->lineEdit_S_return->setText(QString::number(record.value("ReturnTime").toDouble(&ok),'.',2));
           ui->lineEdit_S_Holding->setText(QString::number(record.value("Holding").toDouble(&ok),'.',2));
           ui->lineEdit_S_Raxis->setText(QString::number(record.value("Raxis").toDouble(&ok),'.',2));
           //qDebug()<<"record.value().toString()"<<record.value("Id").toString();

   }
   CurrentReg.Current_StepProgramRow = ui->tableWidget_Step->currentRow();
     //db.close();//释放数据库
}

void Step::on_tableWidget_Step_itemSelectionChanged()
{

    ReflashLinedit();

}

void Step::on_pushButton_Left_1_clicked()//工步编程向上按钮
{
    if(ui->tableWidget_Step->currentRow()==0)
    {
       ui->tableWidget_Step->selectRow(ui->tableWidget_Step->rowCount()-1);
    }
    else
    {
       ui->tableWidget_Step->selectRow(ui->tableWidget_Step->currentRow()-1);
    }
}

void Step::on_pushButton_Left_4_clicked()//工步编程向下按钮
{
    if(ui->tableWidget_Step->currentRow()==ui->tableWidget_Step->rowCount()-1)
    {
       ui->tableWidget_Step->selectRow(0);
    }
    else
    {
       ui->tableWidget_Step->selectRow(ui->tableWidget_Step->currentRow()+1);
    }
}

void Step::on_pushButton_Left_2_clicked()//工步编程 NEW 按钮
{
    NewStepProgram();
    Display_StepProgramItem();
    ui->tableWidget_Step->selectRow(ui->tableWidget_Step->rowCount()-1);

}

void Step::on_pushButton_Left_3_clicked()//工步编程 DELETE 按钮
{
    if(ui->tableWidget_Step->rowCount()>1)
    {
        DeleteStepProgram();
        Display_StepProgramItem();
    }
}

void Step::on_pushButton_Length_clicked()
{
//    deleopLength dl;
//    dl.exec();

    bool ok;
    double Length = 0.0;
    for(int i=0;i<ui->tableWidget_Step->rowCount();i++)
    {
       Length += ui->tableWidget_Step->item(i,StepProgram_Xaxis)->text().toDouble(&ok);
    }
    CurrentReg.developLength = Length;
    emit sig_developLength(Length);

}
