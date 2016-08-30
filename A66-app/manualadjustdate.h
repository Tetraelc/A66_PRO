#ifndef MANUALADJUSTDATE_H
#define MANUALADJUSTDATE_H

#include <QDialog>

namespace Ui {
class ManualAdjustDate;
}

class ManualAdjustDate : public QDialog
{
    Q_OBJECT
    
public:
    explicit ManualAdjustDate(QWidget *parent = 0);
    ~ManualAdjustDate();

signals:
     void sig_sndManualX(QString str);
     void sig_sndManualY(QString str);
     void sig_sndManualR(QString str);

private slots:

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();
private:
    Ui::ManualAdjustDate *ui;
};

#endif // MANUALADJUSTDATE_H
