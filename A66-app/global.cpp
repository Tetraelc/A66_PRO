#include "global.h"


#define DEV_PATH "/sys/class/gpio/"

bool EditableFalg = false;
int fastmode =0;
int ProgIndex=0;
int ProgNameNum=1;
int StepIndex=0;
int CurrentStep=1;
int UpMoldIndex;
int LowerMoldIndex;
int ReflashMaterialFalg =0;

int UpMoldNum=1;
int LowerMoldNum=1;
int ManualSpeedValue = 10000;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //采用QSQLITE数据库

struct Stepdata CurrentStepTemp;
struct ProgramFiles  CurrentProgramTemp;
struct UpMoldData CurrentUpMoldTemp;
struct LowerMoldData  CurrentLowerMoldTemp;
struct _CURRENTREG CurrentReg;
struct _VALUESTATE ValveReg;
struct MaterialData  CurrentMaterialTemp;

void openBeep()
{
    system("echo 113 >"DEV_PATH"export");
    system("echo out >"DEV_PATH"gpio113/direction");
    system("echo 1 >> "DEV_PATH"gpio113/value");
    system("echo 113 >"DEV_PATH"unexport");
}

void Sql_Init()
{
    db.setHostName("localhost"); //设置数据库主机名
#if ARMFlag
    db.setDatabaseName("/opt/tetra/A66-app/A66-app.db"); //设置数据库名
#else
    db.setDatabaseName("A66-app.db"); //设置数据库名/opt/tetra/A66-app/
#endif
    db.setUserName("root");//设置数据库登入用户名
    db.setPassword("123456");//设计数据库登入密码
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Error"),
                              db.lastError().text());//打开数据库连接
    }
}

QString SystemWarnInformation(int WarnID)//UpperPointAlarm
{

    QString WarnInformation;
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }

    QSqlTableModel model;
    model.setTable("SystemAlarm");
    model.setFilter("ID = " + QString::number(WarnID,10));
    model.select();

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            WarnInformation = record.value("Info").toString();
    }


    //db.close();//释放数据库
//    qDebug()<<"WarnID"<<WarnID;
//    qDebug()<<"WarnInformation"<<WarnInformation;

    return WarnInformation;

}

QString SystemTipsInformation(int TipsID)
{

    QString TipsInformation;
//    if(!db.open())
//    {
//        QMessageBox::critical(0,QObject::tr("Error"),
//                              db.lastError().text());//打开数据库连接
//    }
    QSqlTableModel model;
    model.setTable("SystemTips");
    model.setFilter("ID = " + QString::number(TipsID,10));
    model.select();

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);
            TipsInformation = record.value("Info").toString();
    }


    //db.close();//释放数据库
//    qDebug()<<"WarnID"<<TipsID;
//    qDebug()<<"WarnInformation"<<TipsInformation;

    return TipsInformation;

}



Global::Global(QWidget *parent) :
    QWidget(parent)
{
}



