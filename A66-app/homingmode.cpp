#include "homingmode.h"
#include "ui_homingmode.h"
#include "global.h"
#include "systemsetting.h"
#include "mainwindow.h"

//#define HomingXButtonPos   152
//#define HomingXLineditPos  HomingXButtonPos+115
//#define HomingXFramePos    HomingXLineditPos+273


//#define HomingYButtonPos   152
//#define HomingYLineditPos  HomingYButtonPos+115
//#define HomingYFramePos    HomingYLineditPos+273


//#define HomingRButtonPos   152
//#define HomingRLineditPos  HomingRButtonPos+115
//#define HomingRFramePos    HomingRLineditPos+273

//#define  HomingXButtonPosCol  44

//#define  HomingYButtonPosCol  44
//#define  HomingRButtonPosCol  44

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
    ui->label_X->setText(trUtf8("准备就绪"));
    ui->label_Y->setText(trUtf8("准备就绪"));

    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        sys.SystemWriteMotor(0x03);//写电机参数
        ui->label_R->setText(trUtf8("准备就绪"));
    }

    sys.SystemWriteMT();//写MT参数


    QFont font;
    font.setPointSize(28);
    ui->lineEdit_XHoming->setFont(font);
    ui->lineEdit_YHoming->setFont(font);
    ui->lineEdit_RHoming->setFont(font);

    ui->toolButton_X->setEnabled(false);
    ui->toolButton_Y->setEnabled(false);
    ui->toolButton_R->setEnabled(false);

    CheckRaxisEnable();


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

void HomingMode::CheckRaxisEnable()
{
    if(RaxisParameter.ENABLE_AXIS == 1)
    {
        ui->lineEdit_RHoming->setVisible(true); //R轴可视
        ui->frame_4->setVisible(true);
        ui->toolButton_R->setVisible(true);

        ui->toolButton_X->move(152,54);
        ui->lineEdit_XHoming->move(267,44);
        ui->frame_2->move(540,50);

        ui->toolButton_Y->move(150,163);
        ui->lineEdit_YHoming->move(267,152);
        ui->frame_3->move(540,158);

        ui->toolButton_R->move(150,270);
        ui->lineEdit_RHoming->move(267,260);
        ui->frame_4->move(540,266);

    }
    else
    {
        ui->lineEdit_RHoming->setVisible(false);
        ui->frame_4->setVisible(false);
        ui->toolButton_R->setVisible(false);

        ui->toolButton_X->move(150,96);
        ui->lineEdit_XHoming->move(267,86);
        ui->frame_2->move(540,92);

        ui->toolButton_Y->move(150,218);
        ui->lineEdit_YHoming->move(267,207);
        ui->frame_3->move(540,213);
    }

}


//[1]
void HomingMode::CheckMotorState()
{
    if(XaxisParameter.ReferencePosMode == 1 ||  XaxisParameter.ReferencePosMode == 2 )
    {
        if(Get_HeartbetError(X1_ID) == 0x01 || motor[X1_ID-1].initStatus == 0)
        {
            ui->label_X->setText(trUtf8("电机异常"));
            ui->toolButton_RunHoming->setEnabled(false);
            ui->toolButton_X->setEnabled(false);
        }
        else if(HomgingModeFlag == 1 && arrivedSwitch_X == 0)
        {
            ui->label_X->setText(trUtf8("正在归零"));
            ui->toolButton_X->setEnabled(true);
        }
        else if(arrivedSwitch_X == 1)
        {
            ui->label_X->setText(trUtf8("归零完成"));
            ui->toolButton_X->setEnabled(false);
    //        RunState rs;
    //        rs.SaveCurrentAxisDat();
            //ui->toolButton_RunHoming->setEnabled(true);
        }
        else if(arrivedSwitch_X == 0)
        {
            ui->label_X->setText(trUtf8("准备就绪"));
            ui->toolButton_RunHoming->setEnabled(true);
            ui->toolButton_Y->setEnabled(false);
        }

    }
    else
    {
        ui->label_X->setText(trUtf8("手动寻参"));
    }

    if(YaxisParameter.ReferencePosMode == 1 ||  YaxisParameter.ReferencePosMode == 2 )
    {
        if(Get_HeartbetError(Y1_ID) == 0x01 || motor[Y1_ID-1].initStatus == 0)
        {
            ui->label_Y->setText(trUtf8("电机异常"));
            ui->toolButton_RunHoming->setEnabled(false);
            ui->toolButton_Y->setEnabled(false);
        }
        else if(HomgingModeFlag == 1 && arrivedSwitch_Y == 0)
        {
            ui->label_Y->setText(trUtf8("正在归零"));
            ui->toolButton_Y->setEnabled(true);

        }
        else if(arrivedSwitch_Y == 1)
        {
            ui->label_Y->setText(trUtf8("归零完成"));
            ui->toolButton_Y->setEnabled(false);
    //        RunState rs;
    //        rs.SaveCurrentAxisDat();
           // ui->toolButton_RunHoming->setEnabled(true);
        }
        else if(arrivedSwitch_Y == 0)
        {
            ui->label_Y->setText(trUtf8("准备就绪"));
            ui->toolButton_Y->setEnabled(false);
            ui->toolButton_RunHoming->setEnabled(true);
        }

    }
    else
    {
        ui->label_Y->setText(trUtf8("手动寻参"));
    }


    if(RaxisParameter.ReferencePosMode == 1 ||  RaxisParameter.ReferencePosMode == 2 )
    {

        if(RaxisParameter.ENABLE_AXIS == 1)
        {
            if(Get_HeartbetError(R1_ID) == 0x01 || motor[R1_ID-1].initStatus == 0)
            {
                ui->label_R->setText(trUtf8("电机异常"));
                ui->toolButton_R->setEnabled(false);
                ui->toolButton_RunHoming->setEnabled(false);
            }
            else if(HomgingModeFlag == 1 && arrivedSwitch_R == 0)
            {
                ui->label_R->setText(trUtf8("正在归零"));
                ui->toolButton_R->setEnabled(true);
            }
            else if(arrivedSwitch_R == 1)
            {
                ui->label_R->setText(trUtf8("归零完成"));
                ui->toolButton_R->setEnabled(false);
    //            RunState rs;
    //            rs.SaveCurrentAxisDat();
                //ui->toolButton_RunHoming->setEnabled(true);
            }
            else if(arrivedSwitch_R == 0)
            {
                ui->label_R->setText(trUtf8("准备就绪"));
                ui->toolButton_RunHoming->setEnabled(true);
                ui->toolButton_R->setEnabled(false);
            }
        }
    }
    else
    {
        ui->label_R->setText(trUtf8("手动寻参"));
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
                double Dis_YPos =Get_MOTOR_Demand_Postion(Y1_ID) * YaxisParameter.LeadScrew /1000;
                double Dis_RPos =Get_MOTOR_Demand_Postion(R1_ID) * RaxisParameter.LeadScrew /1000;

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

    if(XaxisParameter.ReferencePosMode == 0)
    {

    }else if(XaxisParameter.ReferencePosMode == 1)
    {
        HomingModeDate[0].data[1].Data = 0x01;// 这里写回零模式
        HomingModeDate[0].data[2].Data  = XaxisParameter.ReferencePos;
        Write_MOTOR_Multi_Data(&HomingModeDate[X1_ID -1 ],X1_ID);

    }else if(XaxisParameter.ReferencePosMode == 2)
    {
        HomingModeDate[0].data[1].Data = 0x02;// 这里写回零模式
        HomingModeDate[0].data[2].Data  = XaxisParameter.ReferencePos;
        Write_MOTOR_Multi_Data(&HomingModeDate[X1_ID -1 ],X1_ID);

    }

    if(YaxisParameter.ReferencePosMode == 0)
    {
    } else if(YaxisParameter.ReferencePosMode == 1)
     {
         HomingModeDate[1].data[1].Data = 0x01;// 这里写回零模式
         HomingModeDate[1].data[2].Data  = YaxisParameter.ReferencePos;
         Write_MOTOR_Multi_Data(&HomingModeDate[Y1_ID -1],Y1_ID);
     }else if(YaxisParameter.ReferencePosMode == 2)
     {
         HomingModeDate[1].data[1].Data = 0x02;// 这里写回零模式
         HomingModeDate[1].data[2].Data  = YaxisParameter.ReferencePos;
         Write_MOTOR_Multi_Data(&HomingModeDate[Y1_ID -1],Y1_ID);
     }




     if(RaxisParameter.ENABLE_AXIS == 1)
     {
         if(YaxisParameter.ReferencePosMode == 0)
         {
         } else if(YaxisParameter.ReferencePosMode == 0)
         {
         }else if(RaxisParameter.ReferencePosMode == 1)
         {
             HomingModeDate[2].data[1].Data = 0x01;// 这里写回零模式
             HomingModeDate[2].data[2].Data  = RaxisParameter.ReferencePos;
             Write_MOTOR_Multi_Data(&HomingModeDate[R1_ID-1],R1_ID);

         }else if(RaxisParameter.ReferencePosMode == 2)
         {
             HomingModeDate[2].data[1].Data = 0x02;// 这里写回零模式
             HomingModeDate[2].data[2].Data  = RaxisParameter.ReferencePos;
             Write_MOTOR_Multi_Data(&HomingModeDate[R1_ID-1],R1_ID);
         }
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



