#include "block.h"
#include "ui_block.h"

block::block(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::block)
{
    ui->setupUi(this);
}

block::~block()
{
    delete ui;
}
