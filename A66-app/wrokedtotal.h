#ifndef WROKEDTOTAL_H
#define WROKEDTOTAL_H

#include <QDialog>

namespace Ui {
class WrokedTotal;
}

class WrokedTotal : public QDialog
{
    Q_OBJECT
    
public:
    explicit WrokedTotal(QWidget *parent = 0);
    ~WrokedTotal();
    
private slots:
    void on_toolButton_clicked();

    void on_toolButton_Quit_clicked();

private:
    Ui::WrokedTotal *ui;
};

#endif // WROKEDTOTAL_H
