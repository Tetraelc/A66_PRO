#include "chooseupmolddialog.h"
#include "ui_chooseupmolddialog.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "global.h"
#include "runstate.h"

chooseUpMoldDialog::chooseUpMoldDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseUpMoldDialog)
{
    ui->setupUi(this);
    RunState runstate1 ;
    runstate1.ReadForRun(CurrentReg.Current_StepProgramRow);

    ui->tableWidget_UpMoulds->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_UpMoulds->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_UpMoulds->horizontalHeader()->setClickable(false);    //******NEW********//

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
            //qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

    ui->tableWidget_UpMoulds->selectRow(CurrentProgramTemp.UpMold-1);
    //db.close();//释放数据库


//    ui->tableWidget_UpMoulds->setRowCount(UpMoldNum);
//    ui->tableWidget_UpMoulds->selectRow(0);
//    for(int i=0;i<UpMoldNum;i++)
//    {
//      ui->tableWidget_UpMoulds->setItem(i,0,new QTableWidgetItem(QString::number(UpMold[i].Height,'.',0)));
//      ui->tableWidget_UpMoulds->setItem(i,1,new QTableWidgetItem(QString::number(UpMold[i].Angle,'.',0)));
//      ui->tableWidget_UpMoulds->setItem(i,2,new QTableWidgetItem(QString::number(UpMold[i].Radius,'.',0)));
//      ui->tableWidget_UpMoulds->setItem(i,3,new QTableWidgetItem(QString::number(UpMold[i].Impedance,'.',0)));
//    }
}

chooseUpMoldDialog::~chooseUpMoldDialog()
{
    delete ui;
}

void chooseUpMoldDialog::on_toolButton_Comfirm_clicked()
{
    if(ui->tableWidget_UpMoulds->currentRow()>=0)
    {
         emit sig_sndUpMold(ui->tableWidget_UpMoulds->currentRow()+1);
         this->close();
    }
}
