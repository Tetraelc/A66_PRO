#include "choosepicture.h"
#include "ui_choosepicture.h"

#include "global.h"
#include "programdb.h"

ChoosePicture::ChoosePicture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoosePicture)
{
    ui->setupUi(this);

    model = new QFileSystemModel;

    model->setRootPath("");
//   QDirModel * model = new QDirModel;

//    model->setFilter(QDir::AllDirs | QDir::Files | QDir::NoSymLinks);


    QStringList filter;

    filter<<"*.jpg"<<"*.png"<<"*.bmp"<<"*.gif";


    model->setNameFilters(filter);
    model->setNameFilterDisables(false);


    ui->treeView->setModel(model);
    ui->treeView->setAnimated(false);
    ui->treeView->setIndentation(20);
    ui->treeView->setRootIndex(model->index("/media"));
//    ui->treeView->setWindowTitle(QObject::trUtf8("添加图片"));
    ui->treeView->setColumnWidth(0,350);
    ui->treeView->setColumnWidth(1,50);
    ui->treeView->setColumnWidth(2,50);
    ui->treeView->setColumnWidth(3,50);
    ui->treeView->show();
}

ChoosePicture::~ChoosePicture()
{
    delete ui;
}

void ChoosePicture::on_toolButton_Add_clicked()
{
    QDir dir;
    QString Pic_Path;
    Pic_Path.clear();
    QModelIndex parentIndex = model->index("/media");
    int numRows = model->rowCount(parentIndex);
    for(int row = 0; row > numRows; ++row)
    {
         QModelIndex index = model->index(row, 0, parentIndex);
         model->data(index, Qt::DisplayRole).toString();
         qDebug()<<"---"<<model->data(index, Qt::DisplayRole).toString()<<model->rowCount(parentIndex);
    }

     Pic_Path = model->data(ui->treeView->currentIndex(), Qt::DisplayRole).toString();

     Pic_Path = model->data(ui->treeView->currentIndex().parent(), Qt::DisplayRole).toString().append("/").append(Pic_Path);
     Pic_Path = model->data(ui->treeView->currentIndex().parent().parent(), Qt::DisplayRole).toString().append("/").append(Pic_Path);
     Pic_Path = model->data(ui->treeView->currentIndex().parent().parent().parent(), Qt::DisplayRole).toString().append("/").append(Pic_Path);
     Pic_Path = model->data(ui->treeView->currentIndex().parent().parent().parent().parent(), Qt::DisplayRole).toString().append("/").append(Pic_Path);
     Pic_Path = model->data(ui->treeView->currentIndex().parent().parent().parent().parent().parent(), Qt::DisplayRole).toString().append("/").append(Pic_Path);

    qDebug()<<"Pic_Path"<< Pic_Path;
    #if ARMFlag
     QString str_tmp = "wr cp " +  Pic_Path +  " /opt/tetra/A66-app/PIC" ;
    #else
     QString str_tmp = "cp " +  Pic_Path +  " /home/tetra/gitA66/A66-app/Picture" ;
    #endif

    CurrentReg.CurrentProgramPic = model->data(ui->treeView->currentIndex(), Qt::DisplayRole).toString();
    qDebug()<<"CurrentReg.CurrentProgramPic-------------"<<CurrentReg.CurrentProgramPic<<CurrentReg.Current_ProgramLibRow +1;
    system(str_tmp.toAscii());
//    Programdb pro;
//    pro.Update_ProgramLibItem(CurrentReg.Current_ProgramLibRow +1,Program_PicPath,CurrentReg.CurrentProgramPic);

    QSqlTableModel model;
    model.setTable("ProgramLib");
    model.setFilter("ID = " + QString::number(CurrentReg.Current_ProgramLibRow +1,10));
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        record.setValue("ProgramPic",CurrentReg.CurrentProgramPic);
        model.setRecord(0,record);
        model.submitAll();
   }







}


void ChoosePicture::on_toolButton_Quit_clicked()
{

}
