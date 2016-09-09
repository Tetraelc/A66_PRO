#include "systemwarn.h"
#include "ui_systemwarn.h"
#include "global.h"
#include "programdb.h"
#include "mainwindow.h"


extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"

SystemWarn::SystemWarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemWarn)
{
    ui->setupUi(this);

    if(aralmOrTipFalg)
    {
       SystemCheckAlarm(CurrentReg.Current_MotorAlarm);
       ui->label_warming->setVisible(true);
    }
    else
    {
        ui->label_warming->setVisible(false);
        SystemCheckTip(CurrentReg.Current_MotorTips);
        qDebug()<<"CurrentReg.Current_MotorTips"<<CurrentReg.Current_MotorTips;

    }



}

SystemWarn::~SystemWarn()
{
    delete ui;
}

void SystemWarn::SystemCheckAlarm(int WarnID)
{

    switch(WarnID)
    {
    case 1:ui->label_DisplayAlarm->setText(SystemWarnInformation(UpperPointAlarm));
        break;

    default :break;
    }
}

void SystemWarn::SystemCheckTip(int TipID)
{

    switch(TipID)
    {
//    case 1:ui->label_DisplayAlarm->setText(SystemTipsInformation(PrepareTip));
//        break;
//    case 2:ui->label_DisplayAlarm->setText(SystemTipsInformation(RunTip));
//        break;
//    case 3:ui->label_DisplayAlarm->setText(SystemTipsInformation(RunFinishTip));
//        break;
    case 4:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataInitTip));
        break;
    case 5:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataSaveTip));
        break;
    case 6:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataResumeTip));
        break;
    case 7:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataResumeTip));
        break;

    default :break;
    }
}


void SystemWarn::on_toolButton_Comfirm_clicked()
{
      this->close();
}
void SystemWarn::on_toolButton_Quit_clicked()
{
     emit ReturnProgramdbWin();
}

}






