#include "chooselowermolddialog.h"
#include "ui_chooselowermolddialog.h"
#include "global.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>

chooseLowerMoldDialog::chooseLowerMoldDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseLowerMoldDialog)
{
    ui->setupUi(this);


    ui->tableWidget_LowerMoulds->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_LowerMoulds->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_LowerMoulds->horizontalHeader()->setClickable(false);    //******NEW********//

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

            ui->tableWidget_LowerMoulds->setColumnHidden(LowerMold_SpeedPostion,true);
            ui->tableWidget_LowerMoulds->setColumnHidden(LowerMold_SpeedChange,true);


            //qDebug()<<"record.value().toString()"<<record.value("Id").toString();
    }

   // ui->tableWidget_LowerMoulds->selectRow(0);
    //db.close();//释放数据库
//    ui->tableWidget_LowerMoulds ->setRowCount(LowerMoldNum);
//    ui->tableWidget_LowerMoulds->selectRow(0);
//    for(int i=0;i<LowerMoldNum;i++)
//    {
//      ui->tableWidget_LowerMoulds->setItem(i,0,new QTableWidgetItem(QString::number(LowerMold[i].Height,'.',0)));
//      ui->tableWidget_LowerMoulds->setItem(i,1,new QTableWidgetItem(QString::number(LowerMold[i].D_V,'.',0)));
//      ui->tableWidget_LowerMoulds->setItem(i,2,new QTableWidgetItem(QString::number(LowerMold[i].Angle,'.',0)));
//      ui->tableWidget_LowerMoulds->setItem(i,3,new QTableWidgetItem(QString::number(LowerMold[i].Radius,'.',0)));
//    }

    //connect(this, SIGNAL(openRunStateWidget()), rs, SLOT(openRunStateWin()));

}

chooseLowerMoldDialog::~chooseLowerMoldDialog()
{
    delete ui;
}

void chooseLowerMoldDialog::on_buttonBox_accepted()
{

    if(ui->tableWidget_LowerMoulds->currentRow()>=0)
    {
         emit sig_sndLowerMold(ui->tableWidget_LowerMoulds->currentRow()+1);
         this->close();
     }

}
