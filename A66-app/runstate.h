#ifndef RUNSTATE_H
#define RUNSTATE_H

#include <QWidget>



namespace Ui {
class RunState;
}

class RunState : public QWidget
{
    Q_OBJECT
    
public:
    explicit RunState(QWidget *parent = 0);
    ~RunState();

    void initRunState();

    void ReadForRun(int Type);
    void ReadRunTable();
    void MotorRun();
    int CheckPressureState();
    void StopRun();
    void ReadTrg( unsigned char pin );
    void initWorkedTotalDialog();
    void SendMTEnableSignalXYAxis();
    void SendMTEnableSignalXYRAxis();
    void QuitRunState();
    void ReflashWorkedTotal();
    void systemCheckSafrState();
    void ReturnRun();
    int  concedeState();
    void checkMotorState();
    void changeStep();
    int Checkstatus(int motor_id);
    int CurrentRnuStateWorkedTotal;
public slots:
    void openRunStateWin();

signals:
    void openProgramwindow();
    void ReturnworkedTotal(int Num);
private slots:
    void on_pushButton_Left_5_clicked();
    void timerEvent(QTimerEvent *t);
    void on_tableWidget_Run_itemSelectionChanged();
    void on_pushButton_Left_1_clicked();
    void on_pushButton_Left_4_clicked();

private:
    Ui::RunState *ui;
    int Ms_Run;
    int Ms_Lable;
    int CurrentRnuStateRow;
protected:
   bool eventFilter(QObject *watched, QEvent *event);

};

#endif // RUNSTATE_H
