#ifndef STEP_H
#define STEP_H

#include <QDialog>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMessageBox>
#include "mathcalculation.h"

namespace Ui {
class Step;
}

class Step : public QDialog
{
    Q_OBJECT
    
public:
    explicit Step(QWidget *parent = 0);
    ~Step();






    void Display_StepProgramItem();
    void NewStepProgram();
    void DeleteStepProgram();
    void Update_StepProgramItem(int Id,int Col,QString Value);

    void initStep(void);


//signals:
//    void reflashProIndex();
//    void reflashStepNum();

public slots:
    void openStepWin();
//    void NewStepData();
//    void initStepData();


    void on_lineEdit_S_Angle_returnPressed();
    void on_lineEdit_S_AngleCompensate_returnPressed();
    void on_lineEdit_S_Yaxis_returnPressed();
    void on_lineEdit_S_Xaxis_returnPressed();
    void on_lineEdit_S_XaxisCorrect_returnPressed();
    void on_lineEdit_S_distance_returnPressed();
    void on_lineEdit_S_pressure_returnPressed();
    void on_lineEdit_S_return_returnPressed();
    void on_lineEdit_S_Holding_returnPressed();
    void on_lineEdit_S_Raxis_returnPressed();
    void on_tableWidget_Step_itemSelectionChanged();
//    void on_pushButton_S_Up_clicked();
//    void on_pushButton_S_Down_clicked();
//    bool on_pushButton_S_New_clicked();
//    bool on_pushButton_S_Del_clicked();


//    void on_lineEdit_S_Angle_editingFinished();

//    void on_lineEdit_S_AngleCompensate_editingFinished();
//    void on_lineEdit_S_Yaxis_editingFinished();
//    void on_lineEdit_S_Xaxis_editingFinished();
//    void on_lineEdit_S_XaxisCorrect_editingFinished();
//    void on_lineEdit_S_distance_editingFinished();
//    void on_lineEdit_S_pressure_editingFinished();
//    void on_lineEdit_S_return_editingFinished();
//    void on_lineEdit_S_Holding_editingFinished();
 //   void on_lineEdit_S_Raxis_editingFinished();
    


private slots:

    void on_pushButton_Left_1_clicked();

    void on_pushButton_Left_4_clicked();

    void on_pushButton_Left_2_clicked();

    void on_pushButton_Left_3_clicked();

private:
    void timerEvent(QTimerEvent *t) ;
    Ui::Step *ui;
    MathCalculation mathcal;
    int yValue_Scan ;
};

#endif // STEP_H
