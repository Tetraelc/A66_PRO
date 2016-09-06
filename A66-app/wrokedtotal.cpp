#include "wrokedtotal.h"
#include "ui_wrokedtotal.h"
#include "global.h"
#include "QDebug"
#include "mainwindow.h"

WrokedTotal::WrokedTotal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrokedTotal)
{
    ui->setupUi(this);
    QRegExp rx("^([1-9][0-9]{0,3})$");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_workedTotal->setValidator(pReg);
}

WrokedTotal::~WrokedTotal()
{
    delete ui;
}


void WrokedTotal::on_toolButton_clicked()
{
    if( ui->lineEdit_workedTotal->text() != "")
    {
        CurrentReg.Current_WorkedTotal = ui->lineEdit_workedTotal->text().toInt();
        qDebug()<<"Current_WorkedTota------------------------------l"<<CurrentReg.Current_WorkedTotal;
        this->close();
    }
}

void WrokedTotal::on_toolButton_Quit_clicked()
{

    MainWindow MainWin;
    MainWin.ReturnProgramdb();
}
