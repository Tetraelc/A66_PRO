#include "deleoplength.h"
#include "ui_deleoplength.h"
#include "mathcalculation.h"

deleopLength::deleopLength(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleopLength)
{
    ui->setupUi(this);
}

deleopLength::~deleopLength()
{
    delete ui;
}

void deleopLength::on_toolButton_comfirm_clicked()
{
    if(ui->lineEdit_Angle->text().toInt() % 5 == 0 && ui->lineEdit_Angle->text().toInt() >= 60 && ui->lineEdit_Angle->text().toInt() <= 180)
    {
        bool ok;
        MathCalculation mathcal;
        double Length = mathcal.delelopLength(ui->lineEdit_A->text().toDouble(&ok),ui->lineEdit_B->text().toDouble(&ok),ui->lineEdit_Thick->text().toDouble(&ok),ui->lineEdit_Angle->text().toDouble(&ok));
        ui->label_delevoplength->setText(QString::number(Length,'.',4));
    }else
    {
        ui->lineEdit_A->redo();
    }

}
