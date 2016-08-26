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



    SystemCheckAlarm(CurrentReg.Current_MotorAlarm);



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


//    switch(WarnID )
//    case 0x01:
 //       ui->label_DisplayAlarm->setText(SystemWarnInformation(UpperPointAlarm));//break;
//    default:break;
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


