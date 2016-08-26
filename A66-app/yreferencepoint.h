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
    
private:
    Ui::YReferencePoint *ui;
};

#endif // YREFERENCEPOINT_H
