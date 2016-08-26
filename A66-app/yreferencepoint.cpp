#include "yreferencepoint.h"
#include "ui_yreferencepoint.h"

YReferencePoint::YReferencePoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YReferencePoint)
{
    ui->setupUi(this);
}

YReferencePoint::~YReferencePoint()
{
    delete ui;
}
