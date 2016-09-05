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
    }
    else
    {
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
        qDebug()<<"SystemTipsInformation(DataInitTip)"<<SystemTipsInformation(4);
        break;
    case 5:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataSaveTip));
        break;
    case 6:ui->label_DisplayAlarm->setText(SystemTipsInformation(DataResumeTip));
        qDebug("11");
        break;

    default :break;
    }
}



void SystemWarn::on_buttonBox_accepted()
{

    if(!(A20_IN_Status & UpperPoint))
    {
        //emit ReturnProgramWin();

        this->close();

    }else
    {
       this->close();
    }

}


void SystemWarn::on_buttonBox_rejected()
{

    emit ReturnProgramdbWin();
}


}


