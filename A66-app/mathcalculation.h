#ifndef MATHCALCULATION_H
#define MATHCALCULATION_H

#include <QObject>
struct AngleMulti{
       double angle;
       double multi;
};
class MathCalculation : public QObject
{
    Q_OBJECT
public:
    explicit MathCalculation(QObject *parent = 0);

    double AngleToYDis(double angle,double compensationAngle,unsigned int compensationMode,double boardThick,double moldThick,double YZero);
    double AngleToLength(double m_ba);
    double pressureCal(double boardWidth,double boardTick,double strength,double moldV);
    double delelopLength(double A,double B,double boardTick,double angle);
    int circleCal(double Radius);
signals:
    
public slots:
    
};

#endif // MATHCALCULATION_H
