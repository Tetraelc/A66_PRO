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

HomingMode::HomingMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomingMode)
{
    ui->setupUi(this);
    ui->label_X->setText(trUtf8("执行归零"));
    ui->label_Y->setText(trUtf8("执行归零"));
    ui->label_R->setText(trUtf8("执行归零"));

//    MainWindow *mw =new MainWindow;
//    connect(mw, SIGNAL(openHomingModeWidget()), this, SLOT(openHomingModeWin()));
}

HomingMode::~HomingMode()
{
    delete ui;
}


void HomingMode::openHomingModeWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);
    SystemSetting syssetting;
    syssetting.ReadForSystemDat();
    Homging_Scan = startTimer(100);
    ui->toolButton_RunHoming->setEnabled(true);



}

void HomingMode::timerEvent(QTimerEvent *t) //定时器事件
{

        if(t->timerId()==Homging_Scan){




                double Dis_XPos =Get_MOTOR_Demand_Postion(X1_ID) * XaxisParameter.LeadScrew /1000;
                double Dis_YPos =Get_MOTOR_Demand_Postion(Y1_ID) * XaxisParameter.LeadScrew /1000;
                double Dis_RPos =Get_MOTOR_Demand_Postion(R1_ID) * XaxisParameter.LeadScrew /1000;

                ui->lineEdit_XHoming->setText(QString::number(Dis_XPos,'.',2));

                ui->lineEdit_YHoming->setText(QString::number(Dis_YPos,'.',2));

                ui->lineEdit_RHoming->setText(QString::number(Dis_RPos,'.',2));

                qDebug()<<"MOTOR_STATUS[0]"<<MOTOR_STATUS[0] ;
                if(HomgingModeFlag == 1)
                {
                    if(time_count1 > 10)
                    {
                      time_count1 = 0;
                      if((MOTOR_STATUS[0] & 0x1400 ) == 0x1400 )
                      {
                         ui->label_X->setText(trUtf8("归零完成"));
                          arrivedSwitch_X = 1;
                      }
                      else
                      {
                            ui->label_X->setText(trUtf8("正在归零"));
                      }
                      if((MOTOR_STATUS[1] & 0x1400)  == 0x1400)
                      {
                          ui->label_Y->setText(trUtf8("归零完成"));
                          arrivedSwitch_Y = 1;
                      }
                      else
                      {
                          ui->label_Y->setText(trUtf8("正在归零"));
                      }
                      if((MOTOR_STATUS[2] & 0x1400)  == 0x1400 )
                      {

                         ui->label_R->setText(trUtf8("归零完成"));
                          arrivedSwitch_R = 1;
                      }
                      else
                      {
                           ui->label_R->setText(trUtf8("正在归零"));
                      }
//                      if( (MOTOR_STATUS[0] & 0x8000 == 0x8000))
//                      {
//                          arrivedSwitch_X = 1;
//                          ui->label_X->setText(trUtf8("到达开关"));
//                      }
//                      if( (MOTOR_STATUS[1] & 0x8000 == 0x8000))
//                      {
//                          arrivedSwitch_Y = 1;
//                      }
//                      if( (MOTOR_STATUS[2] & 0x8000 == 0x8000))
//                      {
//                          arrivedSwitch_R = 1;
//                      }
                      if(arrivedSwitch_X ==1 && arrivedSwitch_Y ==1 && arrivedSwitch_R ==1)
                      {
                          HomgingModeFlag = 0;
                          arrivedSwitch_X =0;
                          arrivedSwitch_Y =0;
                          arrivedSwitch_R = 0;
                          Write_MOTOR_One_Data(X1_ID,0x6060,0x00,0x01,0x01);
                          Write_MOTOR_One_Data(Y1_ID,0x6060,0x00,0x01,0x01);
                          Write_MOTOR_One_Data(R1_ID,0x6060,0x00,0x01,0x01);
                            ui->label_R->setText(trUtf8("全部回零完成"));
                          ui->toolButton_RunHoming->setEnabled(true);
                         // killTimer(Homging_Scan);
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

    if(RaxisParameter.ReferencePosMode == 1)
    {
        HomingModeDate[2].data[1].Data = 0x01;// 这里写回零模式

    }else if(RaxisParameter.ReferencePosMode == 2)
    {
        HomingModeDate[2].data[1].Data = 0x02;// 这里写回零模式
    }

    Write_MOTOR_Multi_Data(&HomingModeDate[2],R1_ID);
    HomgingModeFlag = 1;
    ui->toolButton_RunHoming->setEnabled(false);
}


}

