#ifndef YREFERENCEPOINT_H
#define YREFERENCEPOINT_H

#include <QDialog>

namespace Ui {
class YReferencePoint;
}

class YReferencePoint : public QDialog
{
    Q_OBJECT
    
public:
    explicit YReferencePoint(QWidget *parent = 0);
    ~YReferencePoint();
    void Display_YReferenceItem();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::YReferencePoint *ui;
};

#endif // YREFERENCEPOINT_H
