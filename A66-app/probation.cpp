#include "probation.h"
#include "global.h"

Probation::Probation(QObject *parent) :
    QObject(parent)
{
    readProbtionTime();

}

void Probation::ProbtionTime(int Time)
{
    if(ProbationTime.Second  > 60)
    {
       if(ProbationTime.Minute  >60)
       {
           if(ProbationTime.Hours  > 24)
           {
               if( Time >= ProbationTime.Days)
               {
                   exit(1);
               }
               ProbationTime.Days++;
           }
           ProbationTime.Hours ++;

       }
       ProbationTime.Minute ++;
       saveProbtionTime();
    }

     ProbationTime.Hours++;
}

void Probation::saveProbtionTime()
{
    QString  Str_Value = QString::number(ProbationTime.Days,10).append(".").append(QString::number(ProbationTime.Hours,10)).append(".").append(QString::number(ProbationTime.Minute,10)).append(".").append(QString::number(ProbationTime.Second,10));
    QSqlQuery query;
    query.exec("UPDATE RunParameter SET ProbationTime =" + Str_Value + " WHERE ID = 1" );


}
void Probation::readProbtionTime()
{
    QSqlQuery query;
    query.exec("SELECT ProbationTime,ProbationEnable FROM RunParameter WHERE ID = 1");
    while(query.next())
    {
       CurrentReg.ProbtionTime=query.value(0).toString();
       CurrentReg.ProbtionEnable=query.value(1).toInt();
       break;
    }
    //29.23.59.59

    ProbationTime.Days = CurrentReg.ProbtionTime.split(".").at(0).toInt();

    ProbationTime.Hours = CurrentReg.ProbtionTime.split(".").at(1).toInt();

    ProbationTime.Minute= CurrentReg.ProbtionTime.split(".").at(2).toInt();

    ProbationTime.Second = CurrentReg.ProbtionTime.split(".").at(3).toInt();

}

