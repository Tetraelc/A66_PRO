#ifndef SYSTEMINFOTIP_H
#define SYSTEMINFOTIP_H

#include <QObject>
#include <QList>
#include <QListIterator>
class SystemInfoTip : public QObject
{
    Q_OBJECT
public:
    explicit SystemInfoTip(QObject *parent = 0);
    QString getCurrentErrorStatus(int errorId);
    void setMotorOffline(unsigned char nodeId);

    struct   _MOTORERROR
    {
        QString errorName;
        bool CurError;
        bool preError;
        unsigned char errorId;

    };
    struct _MOTORERROR  errorResult[20];

    QList <QString> list;
    //QListIterator<_MOTORERROR> listIterator(list);
//    bool errorResult[20];
signals:
    
public slots:
    
};

#endif // SYSTEMINFOTIP_H
