#include "manualadjustdate.h"
#include "ui_manualadjustdate.h"
#include "global.h"

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
//    if(XaxisParameter.ReferencePosMode > 0)
//    {
//        ui->label_X->setVisible(false);
//        ui->lineEdit_ManualX->setVisible(false);
//        ui->toolButton->setVisible(false);
//    }
//    else
//    {
//        ui->label_X->setVisible(true);
//        ui->lineEdit_ManualX->setVisible(true);
//        ui->toolButton->setVisible(true);
//    }

//    if(YaxisParameter.ReferencePosMode > 0)
//    {
//        ui->label_Y->setVisible(false);
//        ui->lineEdit_ManualY->setVisible(false);
//        ui->toolButton_2->setVisible(false);
//    }
//    else
//    {
//        ui->label_Y->setVisible(true);
//        ui->lineEdit_ManualY->setVisible(true);
//        ui->toolButton_2->setVisible(true);
//    }



    CheckRaxisEnable();
}

ManualAdjustDate::~ManualAdjustDate()
{
    delete ui;
}

void ManualAdjustDate::CheckRaxisEnable()
{
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        ui->lineEdit_ManualR->setVisible(true); //R轴可视
        ui->label_R->setVisible(true);
        ui->toolButton_3->setVisible(true);

        ui->label_X->move(20,106);
        ui->lineEdit_ManualX->move(95,100);
        ui->toolButton->move(300,100);

        ui->label_Y->move(20,206);
        ui->lineEdit_ManualY->move(95,200);
        ui->toolButton_2->move(300,200);

        ui->label_R->move(20,306);
        ui->lineEdit_ManualR->move(95,300);
        ui->toolButton_3->move(300,300);



    }
    else
    {
        ui->lineEdit_ManualR->setVisible(false); //R轴bu可视
        ui->label_R->setVisible(false);
        ui->toolButton_3->setVisible(false);

        ui->label_X->move(20,146);
        ui->lineEdit_ManualX->move(95,140);
        ui->toolButton->move(300,140);

        ui->label_Y->move(20,266);
        ui->lineEdit_ManualY->move(95,260);
        ui->toolButton_2->move(300,260);

    }

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

void ManualAdjustDate::on_toolButton_4_clicked()
{
    if(ManualFlag == true)
    {
        Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0x40);
    }
}
