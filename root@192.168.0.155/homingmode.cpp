#include "homingmode.h"
#include "ui_homingmode.h"
#include "global.h"

HomingMode::HomingMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomingMode)
{
    ui->setupUi(this);
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

}

void HomingMode::timerEvent(QTimerEvent *t) //定时器事件
{


}
