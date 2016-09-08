#ifndef CHOOSEUPMOLDDIALOG_H
#define CHOOSEUPMOLDDIALOG_H

#include <QDialog>

namespace Ui {
class chooseUpMoldDialog;
}

class chooseUpMoldDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit chooseUpMoldDialog(QWidget *parent = 0);
    ~chooseUpMoldDialog();
    enum {
        UpMold_Id = 0,
        UpMold_Angle = 1,
        UpMold_Height = 2,
        UpMold_Radius = 3,
        UpMold_Impedance = 4
    };


signals:
    void sig_sndUpMold(int num);
    
private slots:

    void on_toolButton_Comfirm_clicked();

private:
    Ui::chooseUpMoldDialog *ui;
};

#endif // CHOOSEUPMOLDDIALOG_H
