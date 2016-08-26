#ifndef MATHCALCULATION_H
#define MATHCALCULATION_H

#include <QObject>

class MathCalculation : public QObject
{
    Q_OBJECT
public:
    explicit MathCalculation(QObject *parent = 0);

    double AngleToYDis(double angle,double compensationAngle,unsigned int compensationMode,double boardThick,double moldThick,double YZero);
    double AngleToLength(double m_ba);
    
signals:
    
public slots:
    
};

#endif // MATHCALCULATION_H
