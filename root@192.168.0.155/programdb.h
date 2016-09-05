#ifndef PROGRAMDB_H
#define PROGRAMDB_H

#include <QDialog>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMessageBox>
#include "mainwindow.h"
#include <QTableWidgetItem>
namespace Ui {
class Programdb;
}

class Programdb : public QDialog
{
    Q_OBJECT
    
public:
    explicit Programdb(QWidget *parent = 0);
    ~Programdb();
    void initProgram(void);

    void Display_ProgramItem();
    void DeleteProgramLib();
    void Update_ProgramLibItem(int Id,int Col,QString Value);
    void ReflashMaterialdb();

//    int Materialtemp[50];

public slots:
    void openProgramWin();
    bool NewProgramLib(QString str);
    void ReflashProgramWrokedNum(int Num);

    void LowerMoldDialog(int num);
    void UpMoldDialog(int num);
    void closeProgramWin();

signals:

    void sig_NewisEmpty();
    void sig_NewClose();
    void sig_MulName();
    void Sig_NewStepData();
    void ReflashProgram();
    void sig_returnMainwindow();




private slots:
    void on_lineEdit_P_boardThickness_returnPressed();
    void on_lineEdit_P_UpMolds_returnPressed();
    void on_lineEdit_P_LowerMolds_returnPressed();
//    void on_lineEdit_P_Total_returnPressed();
    void UpdtaeMaterialDat();
    void on_tableWidget_Programdb_itemSelectionChanged();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_toolButton_clicked();

    void on_pushButton_Left_4_clicked();

    void on_pushButton_Left_1_clicked();

    void on_pushButton_Left_2_clicked();

    void on_pushButton_Left_3_clicked();

    void on_lineEdit_P_BoardWidth_returnPressed();

private:
    Ui::Programdb *ui;
    QTableWidgetItem * setItemContext;
    int fristMaterialIndex;
};

#endif // PROGRAMDB_H
