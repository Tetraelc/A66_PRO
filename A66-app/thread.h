#ifndef THREAD_H
#define THREAD_H

#include<QThread>
#include<QString>



extern bool stopped;

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void stop();
    QString returnMotorValue2;
protected:
    void run();

signals:
    void sig_sndMotorThread();
private:



};

#endif // THREAD_H
