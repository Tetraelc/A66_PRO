#include "yreferencepoint.h"
#include "ui_yreferencepoint.h"
#include "global.h"
#include "runstate.h"

YReferencePoint::YReferencePoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YReferencePoint)
{
    ui->setupUi(this);
    Display_YReferenceItem();
    QRegExp rx("^(-?[0]|-?[1-9][0-9]{0,3})(?:\\.\\d{1,2})?$|(^\\t?$)");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_BoardThick->setValidator(pReg);
}

YReferencePoint::~YReferencePoint()
{
    delete ui;
}



void YReferencePoint::Display_YReferenceItem()
{
    //QString Str_ClassId=QString::number(ClassId,10);
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("RunParameter");
    model.select();

    for(int i=0;i<model.rowCount();i++)
    {
        QSqlRecord record = model.record(i);
        ui->lineEdit_YReferencePoint->setText(record.value("YZero").toString());

    }

    //db.close();//释放数据库

}


void YReferencePoint::on_toolButton_comfirm_clicked()
{
    if(ui->lineEdit_YReferencePoint->text() != "")
    {
//        if(!db.open())
//        {
//            QMessageBox::critical(0,QObject::tr("Error"),
//                                  db.lastError().text());//打开数据库连接
//        }
        QSqlTableModel model;
        model.setTable("RunParameter");
       // model.setFilter("ID = " + Str_Id);
        model.select();

        if(model.rowCount() == 1)
        {
            QSqlRecord record = model.record(0);
            record.setValue("YZero",QString::number(ui->lineEdit_YReferencePoint->text().toInt()+ ui->lineEdit_BoardThick->text().toInt(),10));
            model.setRecord(0,record);
            model.submitAll();
        }

        //db.close();//释放数据库
        ui->lineEdit_YReferencePoint->setText(QString::number(ui->lineEdit_YReferencePoint->text().toInt()+ ui->lineEdit_BoardThick->text().toInt(),10));
        //this->close();
    }
}
