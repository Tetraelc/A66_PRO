#include "manualadjustdate.h"
#include "ui_manualadjustdate.h"

extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"


ManualAdjustDate::ManualAdjustDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualAdjustDate)
{
    ui->setupUi(this);
    QRegExp rx("^(-?[0]|-?[1-9][0-9]{0,3})(?:\\.\\d{1,2})?$|(^\\t?$)");
    QRegExpValidator *pReg = new QRegExpValidator(rx, this);
    ui->lineEdit_ManualX->setValidator(pReg);
    ui->lineEdit_ManualY->setValidator(pReg);
    ui->lineEdit_ManualR->setValidator(pReg);
}

ManualAdjustDate::~ManualAdjustDate()
{
    delete ui;
}

void ManualAdjustDate::on_toolButton_clicked()
{
     emit sig_sndManualX(ui->lineEdit_ManualX->text());
}

void ManualAdjustDate::on_toolButton_2_clicked()
{
     emit sig_sndManualY(ui->lineEdit_ManualY->text());
}

void ManualAdjustDate::on_toolButton_3_clicked()
{
     emit sig_sndManualR(ui->lineEdit_ManualR->text());

}


}
