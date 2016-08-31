#include "homingmode.h"
#include "ui_homingmode.h"

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
