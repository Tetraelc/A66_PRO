#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include <qtimer.h>
#include <QTimer>
#include <QThread>
#include "thread.h"

namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT
    
public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();
    int Checkstatus(int motor_id);
    int CheckINState();
    int CheckRunState();
    int CheckOutState();
public slots:
    void openManualWin();
    void XMotorThread();
    void ChangeXCurrentPostion(QString str);
    void ChangeYCurrentPostion(QString str);
    void ChangeRCurrentPostion(QString str);
private slots:
    void timerEvent(QTimerEvent *);

    void on_pushButton_M_XBack_pressed();

    void on_pushButton_M_XBack_released();

    void on_pushButton_M_XForWard_pressed();

    void on_pushButton_M_XForWard_released();

    void on_pushButton_M_YBack_pressed();

    void on_pushButton_M_YBack_released();

    void on_pushButton_M_YForWard_pressed();

    void on_pushButton_M_YForWard_released();

    void on_pushButton_Adjust_clicked();
    
    void on_pushButton_B6_7_clicked();

    void on_toolButton_YReferencePoint_clicked();

    void on_toolButton_Length_clicked();

private:
    Ui::Manual *ui;
    Thread ThreadX;
    Thread ThreadY;

    int id1,id2,id3;
};

#endif // MANUAL_H
