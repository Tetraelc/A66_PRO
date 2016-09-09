#include "systeminfo.h"
#include "ui_systeminfo.h"
#include "global.h"
#include "qsoftkeyvalue.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "global.h"

static unsigned int value=0;
SystemInfo::SystemInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemInfo)
{

    ui->setupUi(this);

}

SystemInfo::~SystemInfo()
{
    delete ui;
}


void SystemInfo::openInfoWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);
    ui->textBrowser->verticalScrollBar()->setValue(value=0);
    ui->textBrowser->horizontalScrollBar()->setValue(65);

}



void SystemInfo::on_toolButton_Up_clicked()
{
    value=ui->textBrowser->verticalScrollBar()->value()-100;
    ui->textBrowser->verticalScrollBar()->setValue(value-100);
}

void SystemInfo::on_toolButton_Down_clicked()
{
    value=ui->textBrowser->verticalScrollBar()->value()+100;
    ui->textBrowser->verticalScrollBar()->setValue(value+100);
}

void SystemInfo::on_toolButton_Top_clicked()
{
     ui->textBrowser->verticalScrollBar()->setValue(value=0);
}

void SystemInfo::on_toolButton_Bottom_clicked()
{
     ui->textBrowser->verticalScrollBar()->setValue(value=1000000);
}
