#include "easybend.h"
#include "ui_easybend.h"
#include <QDebug>

EasyBend::EasyBend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyBend)
{
    ui->setupUi(this);
}

EasyBend::~EasyBend()
{
    delete ui;
}
void EasyBend::openEasyBendWin()
{

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,100);

    qDebug()<<"14";
}
