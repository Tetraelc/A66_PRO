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
    
private:
    Ui::HomingMode *ui;
};

#endif // HOMINGMODE_H
