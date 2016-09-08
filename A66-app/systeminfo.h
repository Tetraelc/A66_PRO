#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QDialog>

namespace Ui {
class SystemInfo;
}

class SystemInfo : public QDialog
{
    Q_OBJECT
    
public:
    explicit SystemInfo(QWidget *parent = 0);
    ~SystemInfo();

public slots:
    void openInfoWin();
    
private slots:
    void on_toolButton_Up_clicked();

    void on_toolButton_Down_clicked();

    void on_toolButton_Top_clicked();

    void on_toolButton_Bottom_clicked();

private:
    Ui::SystemInfo *ui;
};

#endif // SYSTEMINFO_H
