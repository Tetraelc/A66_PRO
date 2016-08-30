#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "qsoftkeyvalue.h"
#include <QDesktopWidget>
#include "systeminfo.h"
#include "systemwarn.h"
#include "deleoplength.h"



extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
    ProgramName_Scan = startTimer(800);

//    this->move((QApplication::desktop()->width() - this->width() )/2,(QApplication::desktop()->height() -this->width())/2);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()== ProgramName_Scan){

        ui->toolButton_ProName->setText(CurrentReg.CurrentProgramName);
        MainWinState();

    }
}

void MainWindow::MainWinState()
{
    //ui->toolButton_State->setText(CurrentReg.Current_MotorTipResult);
}


void MainWindow::initWindow()
{

    Step *sp=new Step;
    connect(this, SIGNAL(openStepWidget()), sp, SLOT(openStepWin()));
    Moulds *md=new Moulds;
    connect(this, SIGNAL(openMouldsWidget()), md, SLOT(openMouldsWin()));
    Manual *ml=new Manual;
    connect(this, SIGNAL(openManualWidget()), ml, SLOT(openManualWin()));
    SystemSetting *sys=new SystemSetting;
    connect(this, SIGNAL(openSystemSettingWidget()), sys, SLOT(openSystemSettingWin()));
    RunState *rs=new RunState;
    connect(this, SIGNAL(openRunStateWidget()), rs, SLOT(openRunStateWin()));
    connect(rs, SIGNAL(openProgramwindow()), this, SLOT(ReturnProgramdb()));
    Programdb *pg=new Programdb;
    connect(pg, SIGNAL(sig_returnMainwindow()), this, SLOT(openMainWindowWin()));
    connect(pg, SIGNAL(ReflashProgram()), this, SLOT(ReFlashProgName()));
    connect(this, SIGNAL(openProgramWidget()), pg, SLOT(openProgramWin()));
    SystemInfo *Info = new SystemInfo;
    connect(this, SIGNAL(openInfoWidget()), Info, SLOT(openInfoWin()));
    SystemWarn *syswarn =new SystemWarn;
    connect(syswarn, SIGNAL(ReturnProgramdbWin()), this, SLOT(ReturnProgramdb()));


//    pg->setWindowFlags(Qt::FramelessWindowHint);
//    pg->move(0,WIDGET_Y);
//    pg->show();
    ui->toolButton_B0->setEnabled(false);
}

void MainWindow::openMainWindowWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,MAIN_WIDGET_Y);
    qDebug("openMainWindowWin");

}


void MainWindow::ReturndevelopLength(double num)
{

    ui->toolButton_State->setText(trUtf8("展开长度 :") + QString::number(num ,'.',0));
    qDebug("zhankanchangdu");
}
void MainWindow::ReFlashProgName()
{

}


void MainWindow::ReturnProgramdb()
{

     ui->toolButton_T1->setText(trUtf8(" 程序库"));
     ui->toolButton_T1->setIcon(QIcon("./ICO/P1-PROG.png"));
     ui->toolButton_B0->setEnabled(false);
     ui->toolButton_B1->setEnabled(true);
     ui->toolButton_B2->setEnabled(true);
     ui->toolButton_B3->setEnabled(true);
     ui->toolButton_B4->setEnabled(true);
     ui->toolButton_B5->setEnabled(true);
     ui->toolButton_Start->setEnabled(true);
  //   qDebug("deeeeeeeeeeeeeeeeeeeeeeeeeeede");
     emit openProgramWidget();
   //  openBeep();

}


void MainWindow::on_pushButton_T3_clicked()
{


    emit openRunStateWidget();
    ui->toolButton_T1->setText(trUtf8(" 运行"));
    ui->toolButton_T1->setIcon(QIcon(":/ICO/P1-MOLD.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    openBeep();
}

void MainWindow::on_pushButton_T2_clicked()
{
    emit openProgramWidget();
    ui->toolButton_T1->setText(trUtf8(" 程序库"));
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    openBeep();

}

void MainWindow::on_toolButton_B0_clicked()
{
    emit openProgramWidget();
    ui->toolButton_T1->setText(trUtf8(" 程序库"));
    ui->toolButton_T1->setIcon(QIcon("./ICO/P1-PROG.png"));
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(true);

    openBeep();

}

void MainWindow::on_toolButton_B1_clicked()
{
//    Programdb *pg=new Programdb;
//    connect(this, SIGNAL(sig_closeProgramdbWin()), pg, SLOT(closeProgramWin()));
//    emit sig_closeProgramdbWin();

    emit openStepWidget();
    ui->toolButton_T1->setText(trUtf8(" 工步"));
    ui->toolButton_T1->setIcon(QIcon("./ICO/P1-EDIT.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(false);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(true);


    openBeep();
}

void MainWindow::on_toolButton_B2_clicked()
{
    emit openMouldsWidget();

    ui->toolButton_T1->setIcon(QIcon("./ICO/P1-MOLD.png"));
    ui->toolButton_T1->setText(trUtf8(" 模具库"));

    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(false);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(false);

    openBeep();
}

void MainWindow::on_toolButton_B3_clicked()
{
    emit openManualWidget();
    ui->toolButton_T1->setText(trUtf8(" 手动"));
    ui->toolButton_T1->setIcon(QIcon("./ICO/P1-MANU.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(false);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(false);
    openBeep();
}

void MainWindow::on_toolButton_B4_clicked()
{
//    emit openEasyBendWidget();
//    ui->toolButton_T1->setText(trUtf8(" 简易折弯"));
//    ui->toolButton_B0->setEnabled(true);
//    ui->toolButton_B1->setEnabled(true);
//    ui->toolButton_B2->setEnabled(true);
//    ui->toolButton_B3->setEnabled(true);
//    ui->toolButton_B4->setEnabled(false);
//    ui->toolButton_B5->setEnabled(true);
//    openBeep();
}

void MainWindow::on_toolButton_B5_clicked()
{
    emit openSystemSettingWidget();
    ui->toolButton_T1->setText(trUtf8(" 设置"));
    ui->toolButton_T1->setIcon(QIcon("./ICO/P1-SET.png"));

    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(false);
    ui->toolButton_Start->setEnabled(false);

    openBeep();
}


bool MainWindow::on_toolButton_Start_clicked()
{
//    SystemWarnInformation(UpperPointAlarm);

    if(!(A20_IN_Status & UpperPoint))
    {
//        ReturnRun();
        CurrentReg.Current_MotorAlarm = UpperPointAlarm;
        SystemWarnInformation(CurrentReg.Current_MotorAlarm);
        Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_RETURN);
        SystemWarn warn;
        warn.exec();


        if(!(A20_IN_Status & UpperPoint))
        {
             //emit openProgramwindow();
            emit openProgramWidget();
            ui->toolButton_T1->setText(trUtf8(" 程序库"));
            ui->toolButton_T1->setIcon(QIcon("./ICO/P1-PROG.png"));
            ui->toolButton_B0->setEnabled(false);
            ui->toolButton_B1->setEnabled(true);
            ui->toolButton_B2->setEnabled(true);
            ui->toolButton_B3->setEnabled(true);
            ui->toolButton_B4->setEnabled(true);
            ui->toolButton_B5->setEnabled(true);
            ui->toolButton_Start->setEnabled(true);

             qDebug("openProgramwindow");
        }
        else
        {
            emit openRunStateWidget();
            ui->toolButton_T1->setText(trUtf8(" 运行"));
            ui->toolButton_T1->setIcon(QIcon("./ICO/P1-RUN.png"));
            ui->toolButton_B0->setEnabled(false);
            ui->toolButton_B1->setEnabled(false);
            ui->toolButton_B2->setEnabled(false);
            ui->toolButton_B3->setEnabled(false);
            ui->toolButton_B4->setEnabled(false);
            ui->toolButton_B5->setEnabled(false);
            ui->toolButton_Start->setEnabled(false);
        }
    }
    else
    {
        emit openRunStateWidget();
        ui->toolButton_T1->setText(trUtf8(" 运行"));
        ui->toolButton_T1->setIcon(QIcon("./ICO/P1-RUN.png"));
        ui->toolButton_B0->setEnabled(false);
        ui->toolButton_B1->setEnabled(false);
        ui->toolButton_B2->setEnabled(false);
        ui->toolButton_B3->setEnabled(false);
        ui->toolButton_B4->setEnabled(false);
        ui->toolButton_B5->setEnabled(false);
        ui->toolButton_Start->setEnabled(false);

    }
    openBeep();
}

void MainWindow::on_toolButton_4_clicked()
{
    emit openInfoWidget();

}

}
