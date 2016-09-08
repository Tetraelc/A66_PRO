#ifndef HOMINGMODE_H
#define HOMINGMODE_H

#include <QDialog>

namespace Ui {
class HomingMode;
}

class HomingMode : public QDialog
{
    Q_OBJECT
    
public:
    explicit HomingMode(QWidget *parent = 0);
    ~HomingMode();
    void timerEvent(QTimerEvent *t) ;//定时器事件
    void CheckMotorState();

public slots:
    void openHomingModeWin();
    
private slots:

    void on_toolButton_RunHoming_clicked();

    void on_toolButton_QuitRunning_clicked();

private:
    Ui::HomingMode *ui;
    int Homging_Scan;
};

#endif // HOMINGMODE_H
