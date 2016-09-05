#ifndef CHOOSELOWERMOLDDIALOG_H
#define CHOOSELOWERMOLDDIALOG_H

#include <QDialog>

namespace Ui {
class chooseLowerMoldDialog;
}

class chooseLowerMoldDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit chooseLowerMoldDialog(QWidget *parent = 0);
    ~chooseLowerMoldDialog();

    enum {
        LowerMold_Id = 0,
        LowerMold_Height = 1,
        LowerMold_DV = 2,
        LowerMold_Angle = 3,
        LowerMold_Radius = 4,
        LowerMold_SpeedPostion = 5,
        LowerMold_SpeedChange= 6,
        LowerMold_Impedance = 7
    };

private slots:
    void on_buttonBox_accepted();
signals:
    void sig_sndLowerMold(int num);

private:
    Ui::chooseLowerMoldDialog *ui;
};

#endif // CHOOSELOWERMOLDDIALOG_H
