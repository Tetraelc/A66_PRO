#ifndef MOULDS_H
#define MOULDS_H

#include <QDialog>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMessageBox>
#include "qsoftkeyboard.h"
#include "qsoftkeyvalue.h"
#include "global.h"

namespace Ui {
class Moulds;
}

class Moulds : public QDialog
{
    Q_OBJECT
    
public:
    explicit Moulds(QWidget *parent = 0);
    ~Moulds();
    void initMoulds(void);


    void Display_UpMoldItem();
    void Display_LowerMoldItem();
    void NewUpMold();
    void DeleteUpMold();
    void NewLowerMold();
    void DeleteLowerMold();
    void Update_UpMoldItem(int Id,int Col,QString Value);
    void Update_LowerMoldItem(int Id,int Col,QString Value);

    void Display_MaterialItem();

    void DeleteMaterial();
    bool NewMaterial();
    void Update_MaterialItem(int Id,int Col,QString Value);

    void ReadforMold();


    int Current_UpMoldRow;
    int Current_LowerMoldRow;
     QXmlStreamReader Dreader;
     QXmlStreamReader Ureader;




signals:


public slots:
    void openMouldsWin();
    bool eventFilter(QObject *,QEvent *);
    void on_pushButton_M_Up_clicked();

    void on_pushButton_M_Down_clicked();

    void on_pushButton_M_New_clicked();

    void on_pushButton_M_Del_clicked();



private slots:

    void on_pushButton_U_New_clicked();
    void on_pushButton_U_Del_clicked();
    void on_pushButton_U_Up_clicked();
    void on_pushButton_U_Down_clicked();

    void on_pushButton_D_Up_clicked();
    void on_pushButton_D_Down_clicked();
    void on_pushButton_D_New_clicked();
    void on_pushButton_D_Del_clicked();

    void on_lineEdit_U_Height_returnPressed();
    void on_lineEdit_U_Angle_returnPressed();
    void on_lineEdit_U_Radius_returnPressed();
    void on_lineEdit_U_Impedance_returnPressed();
    void on_lineEdit_D_Height_returnPressed();
    void on_lineEdit_D_V_returnPressed();
    void on_lineEdit_D_Angle_returnPressed();
    void on_lineEdit_D_Radius_returnPressed();
    void on_lineEdit_D_Speed_returnPressed();
    void on_lineEdit_D_XCorrect_returnPressed();
    void on_lineEdit_D_Impedance_returnPressed();

    void on_tableWidget_LowerMoulds_itemSelectionChanged();
    void on_tableWidget_UpMoulds_itemSelectionChanged();

    void on_pushButton_Left_1_clicked();

    void on_pushButton_Left_4_clicked();

    void on_pushButton_Left_2_clicked();

    void on_pushButton_Left_3_clicked();

    void on_pushButton_Left_12_clicked();

    void on_pushButton_Left_9_clicked();

    void on_pushButton_Left_8_clicked();

    void on_pushButton_Left_10_clicked();


    void on_tableWidget_Material_itemSelectionChanged();

    void on_lineEdit_Strengrht_returnPressed();

    void on_lineEdit_MaterialName_returnPressed();

    void on_lineEdit_EMold_returnPressed();

    void on_comboBox_material_currentIndexChanged(int index);

private:
    Ui::Moulds *ui;

};

#endif // MOULDS_H
