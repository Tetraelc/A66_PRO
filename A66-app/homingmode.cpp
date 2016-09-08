#include "homingmode.h"
#include "ui_homingmode.h"
#include "global.h"
#include "systemsetting.h"
#include "mainwindow.h"


static int time_count1 =0;
static int arrivedSwitch_X = 0;
static int arrivedSwitch_Y = 0;
static int arrivedSwitch_R = 0;
extern "C"{
     #include "canfestival.h"
     #include "canfestivalAPI.h"
     #include "ObjDict.h"
     #include "CanopenDictConfig.h"

HomingMode::HomingMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomingMode)
{
    ui->setupUi(this);

    SystemSetting sys;
    sys.ReadForSystemDat();

    sys.SystemWriteMotor(0x01);//写电机参数
    sys.SystemWriteMotor(0x02);//写电机参数
    sys.SystemWriteMotor(0x03);//写电机参数
    sys.SystemWriteMT();//写MT参数

    ui->label_X->setText(trUtf8("准备就绪"));
            ui->label_Y->setText(trUtf8("准备就绪"));
            ui->label_R->setText(trUtf8("准备就绪"));
    QFont font;
    font.setPointSize(28);
    ui->lineEdit_XHoming->setFont(font);
    ui->lineEdit_YHoming->setFont(font);
    ui->lineEdit_RHoming->setFont(font);


    MainWindow *mw =new MainWindow;
    mw->setWindowFlags(Qt::FramelessWindowHint);
    mw->move(0,MAIN_WIDGET_Y);
    mw->show();

    connect(mw, SIGNAL(openHomingModeWidget()), this, SLOT(openHomingModeWin()));
    connect(ui->toolButton_QuitRunning, SIGNAL(clicked()), mw, SLOT(ReturnProgramdb()));//returnProgramdb

    Homging_Scan = startTimer(100);
}

HomingMode::~HomingMode()
{
    delete ui;
}


void HomingMode::CheckMotorState()
{
//    qDebug()<<"Get_HeartbetError(X1_ID) " <<Get_HeartbetError(X1_ID) ;
//    qDebug()<<"Get_HeartbetError(Y1_ID) " <<Get_HeartbetError(Y1_ID) ;
//    qDebug()<<"Get_HeartbetError(R1_ID) " <<Get_HeartbetError(R1_ID) ;
//    qDebug()<<"motor[X1_ID].initStatus"<<motor[X1_ID-1].initStatus;
//    qDebug()<<"motor[Y1_ID].initStatus"<<motor[Y1_ID-1].initStatus;
//    qDebug()<<"motor[R1_ID].initStatus"<<motor[R1_ID-1].initStatus;

    if(Get_HeartbetError(X1_ID) == 0x01 || motor[X1_ID-1].initStatus == 0)
    {
        ui->label_X->setText(trUtf8("电机异常"));
        ui->toolButton_RunHoming->setEnabled(false);
    }
    else if(HomgingModeFlag == 1 && arrivedSwitch_X == 0)
    {
        ui->label_X->setText(trUtf8("正在归零"));
    }
    else if(arrivedSwitch_X == 1)
    {
        ui->label_X->setText(trUtf8("归零完成"));
        //ui->toolButton_RunHoming->setEnabled(true);
    }
    else if(arrivedSwitch_X == 0)
    {
        ui->label_X->setText(trUtf8("准备就绪"));
        ui->toolButton_RunHoming->setEnabled(true);
    }
    if(Get_HeartbetError(Y1_ID) == 0x01 || motor[Y1_ID-1].initStatus == 0)
    {
        ui->label_Y->setText(trUtf8("电机异常"));
        ui->toolButton_RunHoming->setEnabled(false);
    }
    else if(HomgingModeFlag == 1 && arrivedSwitch_Y == 0)
    {
        ui->label_Y->setText(trUtf8("正在归零"));
    }
    else if(arrivedSwitch_Y == 1)
    {
        ui->label_Y->setText(trUtf8("归零完成"));
       // ui->toolButton_RunHoming->setEnabled(true);
    }
    else if(arrivedSwitch_Y == 0)
    {
        ui->label_Y->setText(trUtf8("准备就绪"));
        ui->toolButton_RunHoming->setEnabled(true);
    }
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        if(Get_HeartbetError(R1_ID) == 0x01 || motor[R1_ID-1].initStatus == 0)
        {
            ui->label_R->setText(trUtf8("电机异常"));
            ui->toolButton_RunHoming->setEnabled(false);
        }
        else if(HomgingModeFlag == 1 && arrivedSwitch_R == 0)
        {
            ui->label_R->setText(trUtf8("正在归零"));
        }
        else if(arrivedSwitch_R == 1)
        {
            ui->label_R->setText(trUtf8("归零完成"));
            //ui->toolButton_RunHoming->setEnabled(true);
        }
        else if(arrivedSwitch_R == 0)
        {
            ui->label_R->setText(trUtf8("准备就绪"));
            ui->toolButton_RunHoming->setEnabled(true);
        }
    }
    else
    {
        ui->label_R->setText(trUtf8("电机未使能"));
    }



}




void HomingMode::openHomingModeWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);

    ui->toolButton_RunHoming->setEnabled(true);



}

void HomingMode::timerEvent(QTimerEvent *t) //定时器事件
{

        if(t->timerId()==Homging_Scan){

                CheckMotorState();

                double Dis_XPos =Get_MOTOR_Demand_Postion(X1_ID) * XaxisParameter.LeadScrew /1000;
                double Dis_YPos =Get_MOTOR_Demand_Postion(Y1_ID) * XaxisParameter.LeadScrew /1000;
                double Dis_RPos =Get_MOTOR_Demand_Postion(R1_ID) * XaxisParameter.LeadScrew /1000;

                ui->lineEdit_XHoming->setText(QString::number(Dis_XPos,'.',2));

                ui->lineEdit_YHoming->setText(QString::number(Dis_YPos,'.',2));

                ui->lineEdit_RHoming->setText(QString::number(Dis_RPos,'.',2));

               // qDebug()<<"MOTOR_STATUS[0]"<<MOTOR_STATUS[0] ;
                if(HomgingModeFlag == 1)
                {
                    if(time_count1 > 10)
                    {
                      time_count1 = 0;
                      if((MOTOR_STATUS[0] & 0x1400 ) == 0x1400 )
                      {
                      //   ui->label_X->setText(trUtf8("归零完成"));
                          arrivedSwitch_X = 1;
                      }
                      else
                      {
                       //     ui->label_X->setText(trUtf8("正在归零"));
                      }
                      if((MOTOR_STATUS[1] & 0x1400)  == 0x1400)
                      {
                       //   ui->label_Y->setText(trUtf8("归零完成"));
                          arrivedSwitch_Y = 1;
                      }
                      else
                      {
                      //    ui->label_Y->setText(trUtf8("正在归零"));
                      }
                      if(RaxisParameter.ENABLE_AXIS == 1)
                      {
                          if((MOTOR_STATUS[2] & 0x1400)  == 0x1400 )
                          {

                       //      ui->label_R->setText(trUtf8("归零完成"));
                              arrivedSwitch_R = 1;
                          }
                          else
                          {
                        //       ui->label_R->setText(trUtf8("正在归零"));
                          }
                      }

                      if(RaxisParameter.ENABLE_AXIS == 1)
                      {
                          if(arrivedSwitch_X ==1 && arrivedSwitch_Y ==1 && arrivedSwitch_R ==1)
                          {
                              HomgingModeFlag = 0;
                              arrivedSwitch_X =0;
                              arrivedSwitch_Y =0;
                              arrivedSwitch_R = 0;
                              Write_MOTOR_One_Data(X1_ID,0x6060,0x00,0x01,0x01);
                              Write_MOTOR_One_Data(Y1_ID,0x6060,0x00,0x01,0x01);
                              Write_MOTOR_One_Data(R1_ID,0x6060,0x00,0x01,0x01);

                              ui->toolButton_RunHoming->setEnabled(true);
                          }

                      }
                      else
                      {
                          if(arrivedSwitch_X ==1 && arrivedSwitch_Y ==1 )
                          {
                              HomgingModeFlag = 0;
                              arrivedSwitch_X =0;
                              arrivedSwitch_Y =0;
                              Write_MOTOR_One_Data(X1_ID,0x6060,0x00,0x01,0x01);
                              Write_MOTOR_One_Data(Y1_ID,0x6060,0x00,0x01,0x01);

                              ui->toolButton_RunHoming->setEnabled(true);
                          }

                      }

                    }
                    time_count1++;



                }

            }
}


void HomingMode::on_toolButton_RunHoming_clicked()
{

    if(XaxisParameter.ReferencePosMode == 1)
    {
        HomingModeDate[0].data[1].Data = 0x01;// 这里写回零模式

    }else if(XaxisParameter.ReferencePosMode == 2)
    {
        HomingModeDate[0].data[1].Data = 0x02;// 这里写回零模式
    }

     Write_MOTOR_Multi_Data(&HomingModeDate[0],X1_ID);

     if(YaxisParameter.ReferencePosMode == 1)
     {
         HomingModeDate[1].data[1].Data = 0x01;// 这里写回零模式

     }else if(YaxisParameter.ReferencePosMode == 2)
     {
         HomingModeDate[1].data[1].Data = 0x02;// 这里写回零模式
     }

     Write_MOTOR_Multi_Data(&HomingModeDate[1],Y1_ID);

     HomingModeDate[0].data[2].Data  = XaxisParameter.ReferencePos;
     HomingModeDate[1].data[2].Data  = YaxisParameter.ReferencePos;
     Write_MOTOR_Multi_Data(&HomingModeDate[X1_ID -1 ],X1_ID);
     Write_MOTOR_Multi_Data(&HomingModeDate[Y1_ID -1],Y1_ID);


     if(RaxisParameter.ENABLE_AXIS == 1)
     {

         if(RaxisParameter.ReferencePosMode == 1)
         {
             HomingModeDate[2].data[1].Data = 0x01;// 这里写回零模式

         }else if(RaxisParameter.ReferencePosMode == 2)
         {
             HomingModeDate[2].data[1].Data = 0x02;// 这里写回零模式
         }

         HomingModeDate[2].data[2].Data  = RaxisParameter.ReferencePos;
         Write_MOTOR_Multi_Data(&HomingModeDate[R1_ID-1],R1_ID);
     }



    HomgingModeFlag = 1;
    ui->toolButton_RunHoming->setEnabled(false);
}

void HomingMode::on_toolButton_QuitRunning_clicked()
{

    Stop_MOTOR(X1_ID);
    Stop_MOTOR(Y1_ID);
    Write_MOTOR_One_Data(X1_ID,0x6060,0x00,0x01,0x01);
    Write_MOTOR_One_Data(Y1_ID,0x6060,0x00,0x01,0x01);
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        Stop_MOTOR(R1_ID);
        Write_MOTOR_One_Data(R1_ID,0x6060,0x00,0x01,0x01);
    }
    killTimer(Homging_Scan);

}

}



