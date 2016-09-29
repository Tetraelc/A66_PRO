#ifndef PROBATION_H
#define PROBATION_H

#include <QObject>

class Probation : public QObject
{
    Q_OBJECT
public:
    explicit Probation(QObject *parent = 0);
    void saveProbtionTime();
    void ProbtionTime(int Time);
    void readProbtionTime();
    struct _PROBATION
    {
      int Days;
      int Hours;
      int Minute;
      int Second;
    };
    struct _PROBATION ProbationTime;

    
signals:
    
public slots:
    
};

#endif // PROBATION_H
