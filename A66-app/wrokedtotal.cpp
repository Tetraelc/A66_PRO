#include "wrokedtotal.h"
#include "ui_wrokedtotal.h"
#include "global.h"

WrokedTotal::WrokedTotal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrokedTotal)
{
    ui->setupUi(this);
}

WrokedTotal::~WrokedTotal()
{
    delete ui;
}


void WrokedTotal::on_toolButton_clicked()
{
    if( ui->lineEdit_workedTotal->text() != "")
    {
        CurrentReg.Current_WorkedTotal = ui->lineEdit_workedTotal->text();
        this->close();
    }
}
