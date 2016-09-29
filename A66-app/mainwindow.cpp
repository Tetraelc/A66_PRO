#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "qsoftkeyvalue.h"
#include <QDesktopWidget>
#include "systeminfo.h"
#include "systemwarn.h"
#include "deleoplength.h"
#include "homingmode.h"
#include "wrokedtotal.h"



extern "C"{
    #include "canfestival.h"
    #include "canfestivalAPI.h"
    #include "ObjDict.h"
    #include "CanopenDictConfig.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CurrentReg.Current_ProgramLibRow = 0;
    CurrentReg.Current_WorkedTotal = 0;
    initWindow();
    SystemSetting sys;
    sys.ReadForSystemDat();
    ProgramName_Scan = startTimer(800);
    ProbtionTime_Scan =startTimer(1000);

    //ui->toolButton_T1->setCheckable(false);
//    QPixmap pix;
//    pix.load("/opt/tetra/A66-app/PIC/P01.jpg");
//    ui->label_pic->setPixmap(pix);

    ui->label_Text->setText(trUtf8("回零模式"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/HomingModemini.png");
    ui->label_Picture->setPixmap(pix);

    //    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/HomingMode.png"));
    //    qDebug()<<"ui->toolButton_T1->isCheckable()"<<ui->toolButton_T1->isCheckable();

    //    ui->toolButton_ProName->setCheckable(true);
    //    ui->toolButton_ProName->setChecked(true);
    //    ui->toolButton_ProName->setEnabled(false);
    //    ui->toolButton_T1->setEnabled(false);
//    ui->lcdNumber->set

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayInfoTip()
{
    windowTipFlag = true;

    if(SendFailFlag == true)
    {
        CurrentReg.CurrentTip = SendFail;
        windowTipFlag =false;
        SendFailFlag =false;
    }
    if(SendSuccessFlag == true)
    {
        CurrentReg.CurrentTip = SendSuccess;
        windowTipFlag =false;
        SendSuccessFlag = false;
    }
    if(ReadFailFlag == true)
    {
        CurrentReg.CurrentTip = ReadFail;
        windowTipFlag =false;
        ReadFailFlag = false;
    }
    if(ReadSuccessFlag == true)
    {
        CurrentReg.CurrentTip = ReadSuccess;
        windowTipFlag =false;
        ReadSuccessFlag =false;
    }



    if(LimitFalg == true)
    {
        CurrentReg.CurrentTip = LimitState;
        windowTipFlag =false;
        LimitFalg =false;
    }

    if(MotorRunTipFlag == true )
    {
        CurrentReg.CurrentTip = RuningState;
        windowTipFlag =false;
        MotorRunTipFlag = false;
    }

    if(!(A20_IN_Status & UpperPoint) && ManualTipFlag == true )
    {
        CurrentReg.CurrentTip = UpperPointError;
        windowTipFlag =false;

    }
    if((A20_IN_Status & UpperPoint))
    {
        ManualTipFlag = false;
    }
    if(!(A20_IN_Status & PumpSignal) )
    {
           CurrentReg.CurrentTip = PumpError;
           windowTipFlag =false;
    }
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        if(Get_HeartbetError(0x03) == 0x01 || motor[R1_ID-1].initStatus == 0 )
        {
            CurrentReg.CurrentTip = RAxisoffLine;
            windowTipFlag =false;
        }
        if(MOTOR_STATUS[2] & STATUS_MASK == Fault )
        {
            CurrentReg.CurrentTip = RaxisError;
            windowTipFlag =false;
        }

    }
    if(Get_HeartbetError(0x01) == 0x01 || motor[X1_ID-1].initStatus == 0 )
    {
        CurrentReg.CurrentTip = XAxisoffLine;
        windowTipFlag =false;
    }
    if(Get_HeartbetError(0x02) == 0x01 || motor[Y1_ID-1].initStatus == 0 )
    {
       CurrentReg.CurrentTip =  YAxisoffLine;
       windowTipFlag =false;
    }
    if((MOTOR_STATUS[0] & STATUS_MASK) == Fault )
    {
        CurrentReg.CurrentTip = XaxisError;
        windowTipFlag =false;
    }
    if((MOTOR_STATUS[1] & STATUS_MASK) == Fault )
    {
        CurrentReg.CurrentTip = YaxisError;
        windowTipFlag =false;
    }

    if(((MOTOR_STATUS[1] & STATUS_MASK) == Fault) && ((MOTOR_STATUS[0] & STATUS_MASK) == Fault ) )
    {
        CurrentReg.CurrentTip = XYaxisError;
        windowTipFlag =false;
    }

    if((Get_HeartbetError(0x02) == 0x01 || motor[Y1_ID-1].initStatus == 0) &&(Get_HeartbetError(0x01) == 0x01 || motor[X1_ID-1].initStatus == 0 )  )
    {
       CurrentReg.CurrentTip =  XYAxisoffLine;
       windowTipFlag =false;
    }
    if(Get_HeartbetError(0x04) == 0x01)
    {
       CurrentReg.CurrentTip = MTAxisoffLine;
       windowTipFlag =false;

    }
    if(windowTipFlag == true)
    {
        CurrentReg.CurrentTip = ReadyAll;
        windowTipFlag = false;
    }


    switch(CurrentReg.CurrentTip)
    {
    case ReadyAll:          ui->label_State->setText(trUtf8("准备就绪"));  break;

    case XAxisoffLine:      ui->label_State->setText(trUtf8("X轴离线"));  break;

    case YAxisoffLine:      ui->label_State->setText(trUtf8("Y轴离线"));  break;

    case RAxisoffLine:      ui->label_State->setText(trUtf8("R轴离线"));  break;

    case MTAxisoffLine:     ui->label_State->setText(trUtf8("MT离线"));  break;

    case PumpError:         ui->label_State->setText(trUtf8("油泵未启动"));  break;

    case XaxisError:        ui->label_State->setText(trUtf8("X轴异常"));  break;

    case YaxisError:        ui->label_State->setText(trUtf8("Y轴异常"));break;

    case RaxisError:        ui->label_State->setText(trUtf8("R轴异常")); break;

    case UpperPointError:   ui->label_State->setText(trUtf8("未到上止点，请踩脚踏上")); break;

    case RuningState:        ui->label_State->setText(trUtf8("正在加工"));  break;

    case WorkedState:        ui->label_State->setText(trUtf8("加工完成"));break;

    case XYAxisoffLine:      ui->label_State->setText(trUtf8("X Y轴离线"));  break;

    case XYaxisError:        ui->label_State->setText(trUtf8("X Y轴异常"));break;

    case LimitState:        ui->label_State->setText(trUtf8("软限位"));break;

    case SendSuccess:        ui->label_State->setText(trUtf8("写入成功"));break;

    case SendFail:      ui->label_State->setText(trUtf8("写入失败"));  break;

    case ReadSuccess:        ui->label_State->setText(trUtf8("读取成功"));break;

    case ReadFail:        ui->label_State->setText(trUtf8("读取失败"));break;

    default:    break;
    }

}

//void MainWindow::ProbtionTime()
//{

//    CurrentReg.ProbtionTime

//}


void MainWindow::timerEvent(QTimerEvent *t) //定时器事件
{

    if(t->timerId()== ProbtionTime_Scan){


    }

    if(t->timerId()== ProgramName_Scan){
        if(((MOTOR_STATUS[X1_ID-1] & 0x400) == 0x400) && XStopFalg == true && XaxisParameter.PositioningMode == 0 )
        {
            runstate.SaveCurrentAxisDat(X1_ID);
            XStopFalg =false;
        }
        if(((MOTOR_STATUS[Y1_ID-1] & 0x400) == 0x400) && YStopFalg == true && YaxisParameter.PositioningMode == 0)
        {
            runstate.SaveCurrentAxisDat(Y1_ID);
            YStopFalg =false;
        }
        if(((MOTOR_STATUS[R1_ID-1] & 0x400) == 0x400) && RStopFalg == true && RaxisParameter.PositioningMode == 0)
        {
            runstate.SaveCurrentAxisDat(R1_ID);
            RStopFalg =false;
        }

        ui->label_Program->setText(CurrentReg.CurrentProgramName);
        displayInfoTip();
       // ui->toolButton_ProName->setText(CurrentReg.CurrentProgramName);
//        MainWinState();
    }
}

void MainWindow::MainWinState()
{
    if(MotorTipFlag == true)
    {
         ui->label_State->setText(CurrentReg.Current_MotorTipResult);
         MotorTipFlag = false;
    }
//    if(MotorConfigTipFlag == true)
//    {
//         ui->label_StateTip->setText(CurrentReg.Current_MotorConfigResult);

//  //       CurrentReg.Current_MotorConfigResult.clear();
//         qDebug()<<"CurrentReg.Current_MotorConfigResult"<<CurrentReg.Current_MotorConfigResult;
//         MotorConfigTipFlag = false;
//    }

//    if(developLengthFlag == true)
//    {
//        ui->label_State->setText(trUtf8("展开长度 :") + QString::number( CurrentReg.developLength,'.',2));
//        developLengthFlag = false;
//    }
//    if((A20_IN_Status & UpperPoint) && (MotorConfigFlag == false))
//    {
//        CurrentReg.Current_MotorConfigResult.clear();
//        ui->label_StateTip->setText(CurrentReg.Current_MotorConfigResult);
//    }
//    if(!(A20_IN_Status & PumpSignal) )
//    {

//        ui->label_PumpTip->setText(trUtf8("油泵未启动"));
//    }
//    else
//    {
//         ui->label_PumpTip->clear();
//    }
//    if(!(A20_IN_Status & PumpSignal) )
//    {
//      PumpCurError = true;
//    }
//    else
//    {
//        PumpCurError = false;
//    }
//    if(PumpPreError == PumpCurError)
//    {
//    }
//    else
//    {
//     PumpPreError =  PumpCurError;
//     if(PumpCurError == true)
//     ui->label_State->setText(trUtf8("油泵未启动"));
//     else
//     {
//        ui->label_State->setText(trUtf8(" "));
//     }


}


void MainWindow::initWindow()
{
    Programdb *pg=new Programdb;
    connect(pg, SIGNAL(sig_returnMainwindow()), this, SLOT(openMainWindowWin()));
    connect(pg, SIGNAL(ReflashProgram()), this, SLOT(ReFlashProgName()));
    connect(this, SIGNAL(openProgramWidget()), pg, SLOT(openProgramWin()));
    Step *sp=new Step;
    connect(this, SIGNAL(openStepWidget()), sp, SLOT(openStepWin()));
    connect(sp, SIGNAL(sig_developLength(double)), this, SLOT(ReturndevelopLength(double)));
    Moulds *md=new Moulds;
    connect(this, SIGNAL(openMouldsWidget()), md, SLOT(openMouldsWin()));
    ml=new Manual;
    connect(this, SIGNAL(openManualWidget()), ml, SLOT(openManualWin()));
    sys=new SystemSetting;
    connect(this, SIGNAL(openSystemSettingWidget()), sys, SLOT(openSystemSettingWin()));
    RunState *rs=new RunState;
    connect(this, SIGNAL(openRunStateWidget()), rs, SLOT(openRunStateWin()));
    connect(rs, SIGNAL(openProgramwindow()), this, SLOT(ReturnProgramdb()));

    connect(rs, SIGNAL(ReturnworkedTotal(int )), pg, SLOT(ReflashProgramWrokedNum(int )));
    SystemInfo *Info = new SystemInfo;
    connect(this, SIGNAL(openInfoWidget()), Info, SLOT(openInfoWin()));
    SystemWarn *syswarn =new SystemWarn;
    connect(syswarn, SIGNAL(ReturnProgramdbWin()), this, SLOT(ReturnProgramdb()));


    sys->installEventFilter(this);
     ml->installEventFilter(this);
//    HomingMode *homing =new HomingMode;
//    connect(this, SIGNAL(openHomingModeWidget()), homing, SLOT(openHomingModeWin()));

//    pg->setWindowFlags(Qt::FramelessWindowHint);
//    pg->move(0,WIDGET_Y);
//    pg->show();
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(false);
    ui->toolButton_B2->setEnabled(false);
    ui->toolButton_B3->setEnabled(false);
    ui->toolButton_B4->setEnabled(false);
    ui->toolButton_B5->setEnabled(false);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);



}
void MainWindow::openProgramwindows()
{
//    programwin=new Programdb;
//    connect(programwin, SIGNAL(sig_returnMainwindow()), this, SLOT(openMainWindowWin()));
//   // connect(this, SIGNAL(openProgramWidget()), pg, SLOT(openProgramWin()));
//    programwin->setAttribute(Qt::WA_DeleteOnClose);
//    programwin->show();
}

void MainWindow::closeProgramwindows()
{
//    programwin->close();
}




void MainWindow::on_toolButton_clicked()
{
    ui->label_Text->setText(trUtf8("回零模式"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/HomingModemini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8("回零模式"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/HomingMode.png"));
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(false);
    ui->toolButton_B2->setEnabled(false);
    ui->toolButton_B3->setEnabled(false);
    ui->toolButton_B4->setEnabled(false);
    ui->toolButton_B5->setEnabled(false);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);

    emit openHomingModeWidget();
    openBeep();
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

      developLengthFlag = 1;
}
void MainWindow::ReFlashProgName()
{

}


void MainWindow::ReturnProgramdb()
{
    ui->label_Text->setText(trUtf8("程序库"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-PROGmini.png");
    ui->label_Picture->setPixmap(pix);
     ui->toolButton_B0->setEnabled(false);
     ui->toolButton_B1->setEnabled(true);
     ui->toolButton_B2->setEnabled(true);
     ui->toolButton_B3->setEnabled(true);
     ui->toolButton_B4->setEnabled(true);
     ui->toolButton_B5->setEnabled(true);
     ui->toolButton_Start->setEnabled(true);
     ui->toolButton->setEnabled(false);
     ui->toolButton_4->setEnabled(false);
     emit openProgramWidget();
}


void MainWindow::on_pushButton_T3_clicked()
{
    emit openRunStateWidget();
    ui->label_Text->setText(trUtf8("运行"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-STARTmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 运行"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-MOLD.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    openBeep();
}

void MainWindow::on_pushButton_T2_clicked()
{
    emit openProgramWidget();

    ui->label_Text->setText(trUtf8("程序库"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-PROGmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 程序库"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-PROG.png"));
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    openBeep();

}

void MainWindow::on_toolButton_B0_clicked()
{
    emit openProgramWidget();

    openProgramwindows();
    ui->label_Text->setText(trUtf8("程序库"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-PROGmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 程序库"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-PROG.png"));
    ui->toolButton_B0->setEnabled(false);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(true);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);

    openBeep();

}

void MainWindow::on_toolButton_B1_clicked()
{
    emit openStepWidget();
    ui->label_Text->setText(trUtf8("工步"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-EDITmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 工步"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-EDIT.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(false);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(true);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    openBeep();
}

void MainWindow::on_toolButton_B2_clicked()
{
    emit openMouldsWidget();
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-MOLD.png"));
////    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app/ICO/P1-MOLD.png"));
//    ui->toolButton_T1->setText(trUtf8(" 模具库"));
    ui->label_Text->setText(trUtf8("模具库"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-MOLDmini.png");
    ui->label_Picture->setPixmap(pix);
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(false);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
    openBeep();
}

void MainWindow::on_toolButton_B3_clicked()
{
    emit openManualWidget();
    ui->label_Text->setText(trUtf8("手动"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-MANUmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 手动"));
//    QIcon iconManual("/opt/tetra/A66-app/ICO/P1-MANU.png");
    //ui->toolButton_T1->setIcon(iconManual);
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(false);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);
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
    ui->label_Text->setText(trUtf8("设置"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-SETmini.png");
    ui->label_Picture->setPixmap(pix);
//    ui->toolButton_T1->setText(trUtf8(" 设置"));
//    ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app//ICO/P1-SET.png"));
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(false);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);
    ui->toolButton_4->setEnabled(false);

    openBeep();
}




bool MainWindow::on_toolButton_Start_clicked()
{
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) || (Get_HeartbetError(0x03) == 0x01)  ||  (Get_HeartbetError(0x04) == 0x01) )
        {
            CurrentReg.Current_MotorAlarm = MotorOffline;
            aralmOrTipFalg = true;
            PumpButtonFlag = true;
            SystemWarn warn;
            warn.setWindowFlags(Qt::FramelessWindowHint);
            warn.exec();
            MotorOfflineFlag = false;
        }

    }
    else
    {
        if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) ||  (Get_HeartbetError(0x04) == 0x01) )
        {
            CurrentReg.Current_MotorAlarm = MotorOffline;
            aralmOrTipFalg = true;
            PumpButtonFlag = true;
            SystemWarn warn;
            warn.setWindowFlags(Qt::FramelessWindowHint);
            warn.exec();
            MotorOfflineFlag = false;
        }

    }

    if(MotorOfflineFlag == true)
    {
        if(!(A20_IN_Status & UpperPoint))
        {
            CurrentReg.Current_MotorAlarm = UpperPointAlarm;
            aralmOrTipFalg = true;
            PumpButtonFlag = true;

            Write_MOTOR_One_Data(0x04,0x7001,0x01,0x01,ENTER_RETURN);
            SystemWarn warn;
            warn.setWindowFlags(Qt::FramelessWindowHint);
            warn.exec();

            if(!(A20_IN_Status & UpperPoint))
            {
                 //emit openProgramwindow();
                if(ui->toolButton_B0->isEnabled() == true)
                {
                    emit openProgramWidget();
                    ui->label_Text->setText(trUtf8("程序库"));
                    QPixmap pix;
                    pix.load("/opt/tetra/A66-app/ICO/P1-PROGmini.png");
                    ui->label_Picture->setPixmap(pix);
        //            ui->toolButton_T1->setText(trUtf8(" 程序库"));
        //            ui->toolButton_T1->setIcon(QIcon("/opt/tetra/A66-app//ICO/P1-PROG.png"));
                    ui->toolButton_B0->setEnabled(false);
                    ui->toolButton_B1->setEnabled(true);
                    ui->toolButton_B2->setEnabled(true);
                    ui->toolButton_B3->setEnabled(true);
                    ui->toolButton_B4->setEnabled(true);
                    ui->toolButton_B5->setEnabled(true);
                    ui->toolButton_Start->setEnabled(true);
                    ui->toolButton->setEnabled(false);
                    ui->toolButton_4->setEnabled(false);
                }


            }
            else
            {
                QPixmap pix;
                pix.load("/opt/tetra/A66-app/ICO/P1-STARTmini.png");
                ui->label_Picture->setPixmap(pix);
                ui->label_Text->setText(trUtf8("运行"));
                emit openRunStateWidget();

                ui->toolButton_B0->setEnabled(false);
                ui->toolButton_B1->setEnabled(false);
                ui->toolButton_B2->setEnabled(false);
                ui->toolButton_B3->setEnabled(false);
                ui->toolButton_B4->setEnabled(false);
                ui->toolButton_B5->setEnabled(false);
                ui->toolButton_Start->setEnabled(false);
                ui->toolButton->setEnabled(false);
                ui->toolButton_4->setEnabled(false);
            }
        }
        else
        {
            ui->label_Text->setText(trUtf8("运行"));
            QPixmap pix;
            pix.load("/opt/tetra/A66-app/ICO/P1-STARTmini.png");
            ui->label_Picture->setPixmap(pix);
            emit openRunStateWidget();

            ui->toolButton_B0->setEnabled(false);
            ui->toolButton_B1->setEnabled(false);
            ui->toolButton_B2->setEnabled(false);
            ui->toolButton_B3->setEnabled(false);
            ui->toolButton_B4->setEnabled(false);
            ui->toolButton_B5->setEnabled(false);
            ui->toolButton_Start->setEnabled(false);
            ui->toolButton->setEnabled(false);
            ui->toolButton_4->setEnabled(false);

        }
    }
    MotorOfflineFlag =true;
    openBeep();
}

void MainWindow::on_toolButton_4_clicked()
{
    emit openInfoWidget();
    ui->label_Text->setText(trUtf8("帮助"));
    QPixmap pix;
    pix.load("/opt/tetra/A66-app/ICO/P1-HELP.png");
    ui->label_Picture->setPixmap(pix);
    ui->toolButton_4->setEnabled(false);
    ui->toolButton_B0->setEnabled(true);
    ui->toolButton_B1->setEnabled(true);
    ui->toolButton_B2->setEnabled(true);
    ui->toolButton_B3->setEnabled(true);
    ui->toolButton_B4->setEnabled(true);
    ui->toolButton_B5->setEnabled(true);
    ui->toolButton_Start->setEnabled(false);
    ui->toolButton->setEnabled(false);

}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == sys)
    {
      if (event->type()==QEvent::WindowDeactivate)     //然后再判断控件的具体事件 (这里指获得焦点事件)
      {
          SystemSetting sys;
          sys.ReadForSystemDat();
          sys.SystemWriteMotor(0x01);//写电机参数
          sys.SystemWriteMotor(0x02);//写电机参数
          if(RaxisParameter.ENABLE_AXIS == 1)
          {
              sys.SystemWriteMotor(0x03);//写电机参数
          }
          sys.SystemWriteMT();//写MT参数
          if(FactoryAxisFalg == false)
          {
             EditableFalg = false;
          }
          //FactoryAxisFalg = false;
          MotorConfigFlag = false;
          CurrentReg.Current_MotorConfigResult.clear();
//          ui->label_StateTip->clear();
          return false;
       }
      }

    if(watched==ml)
    {
      if (event->type()==QEvent::WindowDeactivate)
      {
          ManualMTFlag =false;
//          ui->label_StateTip->clear();
          CurrentReg.Current_MotorConfigResult.clear();
          Write_MOTOR_One_Data(MT_ID,0x7001,0x01,0x01,0xa0);
          return false;
      }
    }

 return QWidget::eventFilter(watched,event);     // 最后将事件交给上层对话框
}

}

