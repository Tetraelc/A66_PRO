#ifndef SYSTEMWARN_H
#define SYSTEMWARN_H

#include <QDialog>

namespace Ui {
class SystemWarn;
}

class SystemWarn : public QDialog
{
    Q_OBJECT
    
public:
    explicit SystemWarn(QWidget *parent = 0);
    ~SystemWarn();
    void SystemCheckTip(int TipID);
    void SystemCheckAlarm(int WarnID);
signals:
    void ReturnProgramdbWin();
public slots:


private slots:

    void on_toolButton_Comfirm_clicked();

    void on_toolButton_Quit_clicked();

private:
    Ui::SystemWarn *ui;
};

#endif // SYSTEMWARN_H
