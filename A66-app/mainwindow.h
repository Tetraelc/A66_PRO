#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programdb.h"
#include "step.h"
#include "moulds.h"
#include "manual.h"
#include "runstate.h"
#include "systemsetting.h"
#include "easybend.h"
#include "systemwarn.h"
#include "systeminfotip.h"

class Programdb;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initWindow();
    void MainWinState();
    void openProgramwindows();
    void closeProgramwindows();



public slots:
    void openMainWindowWin();
    void ReturnProgramdb();
    void ReFlashProgName();
    void ReturndevelopLength(double num);


private slots:

    void on_pushButton_T3_clicked();

    void on_pushButton_T2_clicked();

    void on_toolButton_B0_clicked();

    void on_toolButton_B1_clicked();

    void on_toolButton_B2_clicked();

    void on_toolButton_B3_clicked();

    void on_toolButton_B4_clicked();

    void on_toolButton_B5_clicked();

    bool on_toolButton_Start_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_clicked();

signals:
    void openStepWidget();
    void openProgramWidget();
    void openMouldsWidget();
    void openManualWidget();
    void openRunStateWidget();
    void openSystemSettingWidget();
    void openEasyBendWidget();
    void openInfoWidget();
    void sig_UpperPointAlarm();
    void sig_closeProgramdbWin();
    void openHomingModeWidget();

    
private:
    void timerEvent(QTimerEvent *t); //定时器事件
    Ui::MainWindow *ui;

    Manual *ml;
    SystemSetting *sys;
    Programdb *programwin;
    RunState runstate;
    SystemInfoTip *infotip;

    //SystemWarn warn;
    int ProgramName_Scan;
protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
