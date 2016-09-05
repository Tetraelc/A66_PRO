#ifndef DELEOPLENGTH_H
#define DELEOPLENGTH_H

#include <QDialog>

namespace Ui {
class deleopLength;
}

class deleopLength : public QDialog
{
    Q_OBJECT
    
public:
    explicit deleopLength(QWidget *parent = 0);
    ~deleopLength();
signals:
    void sig_developLength(double num);
    
private slots:
    void on_toolButton_comfirm_clicked();

private:
    Ui::deleopLength *ui;
};

#endif // DELEOPLENGTH_H
