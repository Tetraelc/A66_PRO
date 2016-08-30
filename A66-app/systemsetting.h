#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QDialog>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMessageBox>
#include <QModelIndex>
#include <QTableWidgetItem>

namespace Ui {
class SystemSetting;
}

class SystemSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit SystemSetting(QWidget *parent = 0);
    ~SystemSetting();

 //   void initSystemSettings(void);
    void Display_Item(int ClassId);
    void Update_Item(int Id,double Value);
    QString Select_Item(int Id);
    void TreeWidgetInit();
    void ReadForSystem();


    QXmlStreamReader Systemreader;



    struct DataType
    {
        double MaxValue;
        double MinValue;
        double NormValue;
        double DeInitValue;
    };
    struct DataType SystemTemp[50];

    struct SystemData
    {
        struct DataType  Language;
        struct DataType  Units;
        struct DataType  ConcedeTime;
        struct DataType  PressureKeepingTime;
        struct DataType  RemovalTime;
        struct DataType  FrameStrength;
    };

    struct SystemData SystemParamete;
    struct AxisParameter
    {
        struct DataType  LeadScrew;
        struct DataType  MotorDirection;
        struct DataType  EncodeDirection;
        struct DataType  RunSpeed;
        struct DataType  MaxDistance;
        struct DataType  MinDistance;
        struct DataType  PositioningAccuracy;
        struct DataType  PositioningMode;
        struct DataType  OverrunDistance;
    };
    struct AxisParameter XAxisParameter;
    struct AxisParameter YAxisParameter;
    struct AxisParameter RAxisParameter;


    int StepNameNum;
    int SystemTotalItem;


 //设置界面元素
    int MaxNum;
    int MinNum;
    int NormNum;
    int DeInitNum;
    int Table_Editable_Flag;

public slots:
    void openSystemSettingWin();
    void timerEvent(QTimerEvent *t); //定时器事件
    
private slots:

    void on_treeWidget_System_itemSelectionChanged();

    void on_tableWidget_System_cellChanged(int row, int column);


    void on_toolButton_readConfig_clicked();

    void on_toolButton_confirm_clicked();

private:
    int deal_write_config_event();
    int deal_read_config_event();

    void WriteConfig();
    void ReadConfig();
    int ValveConfig_scan;

    Ui::SystemSetting *ui;
};

#endif // SYSTEMSETTING_H
