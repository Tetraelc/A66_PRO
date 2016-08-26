/********************************************************************************
** Form generated from reading UI file 'program.ui'
**
** Created: Wed Jul 27 09:38:22 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAM_H
#define UI_PROGRAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Program
{
public:
    QPushButton *pushButton_D_New_3;
    QPushButton *pushButton_D_Down_3;
    QPushButton *pushButton_P_Del;
    QPushButton *pushButton_P_Up;
    QGroupBox *groupBox;
    QLabel *label_boardThickness;
    QLabel *label_material;
    QLabel *label_mould;
    QLineEdit *lineEdit_P_boardThickness;
    QLabel *label_19;
    QLabel *label_mould_2;
    QLineEdit *lineEdit_P_UpMolds;
    QLineEdit *lineEdit_P_LowerMolds;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox_P_material;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_P_Total;
    QLabel *label_mould_3;
    QLineEdit *lineEdit_P_Name;
    QLabel *label_boardThickness_3;
    QTableWidget *tableWidget_Programdb;
    QPushButton *pushButton_D_Del_3;
    QPushButton *pushButton_P_Down;
    QPushButton *pushButton_Program_New;
    QPushButton *pushButton_D_Up_3;

    void setupUi(QWidget *Program)
    {
        if (Program->objectName().isEmpty())
            Program->setObjectName(QString::fromUtf8("Program"));
        Program->resize(1024, 540);
        pushButton_D_New_3 = new QPushButton(Program);
        pushButton_D_New_3->setObjectName(QString::fromUtf8("pushButton_D_New_3"));
        pushButton_D_New_3->setGeometry(QRect(960, 340, 61, 51));
        QFont font;
        font.setPointSize(18);
        pushButton_D_New_3->setFont(font);
        pushButton_D_Down_3 = new QPushButton(Program);
        pushButton_D_Down_3->setObjectName(QString::fromUtf8("pushButton_D_Down_3"));
        pushButton_D_Down_3->setGeometry(QRect(960, 460, 61, 51));
        pushButton_D_Down_3->setFont(font);
        pushButton_P_Del = new QPushButton(Program);
        pushButton_P_Del->setObjectName(QString::fromUtf8("pushButton_P_Del"));
        pushButton_P_Del->setGeometry(QRect(960, 120, 61, 51));
        pushButton_P_Del->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICO/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_P_Del->setIcon(icon);
        pushButton_P_Del->setIconSize(QSize(48, 48));
        pushButton_P_Up = new QPushButton(Program);
        pushButton_P_Up->setObjectName(QString::fromUtf8("pushButton_P_Up"));
        pushButton_P_Up->setGeometry(QRect(960, 0, 61, 51));
        pushButton_P_Up->setFont(font);
        pushButton_P_Up->setAutoDefault(false);
        groupBox = new QGroupBox(Program);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 270, 871, 251));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(15);
        groupBox->setFont(font1);
        label_boardThickness = new QLabel(groupBox);
        label_boardThickness->setObjectName(QString::fromUtf8("label_boardThickness"));
        label_boardThickness->setGeometry(QRect(50, 61, 111, 20));
        QFont font2;
        font2.setPointSize(12);
        label_boardThickness->setFont(font2);
        label_boardThickness->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_material = new QLabel(groupBox);
        label_material->setObjectName(QString::fromUtf8("label_material"));
        label_material->setGeometry(QRect(50, 102, 110, 16));
        label_material->setFont(font2);
        label_material->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould = new QLabel(groupBox);
        label_mould->setObjectName(QString::fromUtf8("label_mould"));
        label_mould->setGeometry(QRect(118, 137, 41, 20));
        label_mould->setFont(font2);
        label_mould->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_P_boardThickness = new QLineEdit(groupBox);
        lineEdit_P_boardThickness->setObjectName(QString::fromUtf8("lineEdit_P_boardThickness"));
        lineEdit_P_boardThickness->setGeometry(QRect(210, 62, 150, 25));
        lineEdit_P_boardThickness->setMaxLength(5);
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(382, 64, 58, 15));
        label_mould_2 = new QLabel(groupBox);
        label_mould_2->setObjectName(QString::fromUtf8("label_mould_2"));
        label_mould_2->setGeometry(QRect(116, 177, 41, 20));
        label_mould_2->setFont(font2);
        label_mould_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_P_UpMolds = new QLineEdit(groupBox);
        lineEdit_P_UpMolds->setObjectName(QString::fromUtf8("lineEdit_P_UpMolds"));
        lineEdit_P_UpMolds->setGeometry(QRect(210, 137, 150, 25));
        lineEdit_P_LowerMolds = new QLineEdit(groupBox);
        lineEdit_P_LowerMolds->setObjectName(QString::fromUtf8("lineEdit_P_LowerMolds"));
        lineEdit_P_LowerMolds->setGeometry(QRect(210, 177, 150, 25));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 134, 61, 31));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 174, 61, 31));
        comboBox_P_material = new QComboBox(groupBox);
        comboBox_P_material->setObjectName(QString::fromUtf8("comboBox_P_material"));
        comboBox_P_material->setGeometry(QRect(210, 97, 151, 26));
        comboBox_P_material->setEditable(false);
        comboBox_P_material->setModelColumn(0);
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(560, 20, 301, 221));
        lineEdit_P_Total = new QLineEdit(groupBox);
        lineEdit_P_Total->setObjectName(QString::fromUtf8("lineEdit_P_Total"));
        lineEdit_P_Total->setGeometry(QRect(210, 217, 150, 25));
        label_mould_3 = new QLabel(groupBox);
        label_mould_3->setObjectName(QString::fromUtf8("label_mould_3"));
        label_mould_3->setGeometry(QRect(90, 217, 71, 20));
        label_mould_3->setFont(font2);
        label_mould_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_P_Name = new QLineEdit(groupBox);
        lineEdit_P_Name->setObjectName(QString::fromUtf8("lineEdit_P_Name"));
        lineEdit_P_Name->setGeometry(QRect(210, 23, 150, 25));
        lineEdit_P_Name->setMaxLength(5);
        label_boardThickness_3 = new QLabel(groupBox);
        label_boardThickness_3->setObjectName(QString::fromUtf8("label_boardThickness_3"));
        label_boardThickness_3->setGeometry(QRect(50, 27, 111, 20));
        label_boardThickness_3->setFont(font2);
        label_boardThickness_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tableWidget_Programdb = new QTableWidget(Program);
        if (tableWidget_Programdb->columnCount() < 7)
            tableWidget_Programdb->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Programdb->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Programdb->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_Programdb->rowCount() < 50)
            tableWidget_Programdb->setRowCount(50);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Programdb->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_Programdb->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        tableWidget_Programdb->setItem(2, 3, __qtablewidgetitem9);
        tableWidget_Programdb->setObjectName(QString::fromUtf8("tableWidget_Programdb"));
        tableWidget_Programdb->setGeometry(QRect(20, 10, 871, 251));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Programdb->sizePolicy().hasHeightForWidth());
        tableWidget_Programdb->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(15);
        tableWidget_Programdb->setFont(font3);
        tableWidget_Programdb->setAcceptDrops(false);
        tableWidget_Programdb->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Programdb->setMidLineWidth(1);
        tableWidget_Programdb->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Programdb->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Programdb->setAutoScrollMargin(16);
        tableWidget_Programdb->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Programdb->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Programdb->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Programdb->setTextElideMode(Qt::ElideRight);
        tableWidget_Programdb->setGridStyle(Qt::SolidLine);
        tableWidget_Programdb->setSortingEnabled(false);
        tableWidget_Programdb->setRowCount(50);
        tableWidget_Programdb->setColumnCount(7);
        tableWidget_Programdb->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Programdb->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_Programdb->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Programdb->horizontalHeader()->setStretchLastSection(false);
        tableWidget_Programdb->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_Programdb->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton_D_Del_3 = new QPushButton(Program);
        pushButton_D_Del_3->setObjectName(QString::fromUtf8("pushButton_D_Del_3"));
        pushButton_D_Del_3->setGeometry(QRect(960, 400, 61, 51));
        pushButton_D_Del_3->setFont(font);
        pushButton_P_Down = new QPushButton(Program);
        pushButton_P_Down->setObjectName(QString::fromUtf8("pushButton_P_Down"));
        pushButton_P_Down->setGeometry(QRect(960, 180, 61, 51));
        pushButton_P_Down->setFont(font);
        pushButton_Program_New = new QPushButton(Program);
        pushButton_Program_New->setObjectName(QString::fromUtf8("pushButton_Program_New"));
        pushButton_Program_New->setGeometry(QRect(960, 60, 61, 51));
        pushButton_Program_New->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ICO/\346\226\260\345\273\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Program_New->setIcon(icon1);
        pushButton_Program_New->setIconSize(QSize(48, 48));
        pushButton_D_Up_3 = new QPushButton(Program);
        pushButton_D_Up_3->setObjectName(QString::fromUtf8("pushButton_D_Up_3"));
        pushButton_D_Up_3->setGeometry(QRect(960, 280, 61, 51));
        pushButton_D_Up_3->setFont(font);
        pushButton_D_Up_3->setAutoDefault(false);

        retranslateUi(Program);

        QMetaObject::connectSlotsByName(Program);
    } // setupUi

    void retranslateUi(QWidget *Program)
    {
        Program->setWindowTitle(QApplication::translate("Program", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_D_New_3->setText(QApplication::translate("Program", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_D_Down_3->setText(QString());
        pushButton_P_Del->setText(QString());
        pushButton_P_Up->setText(QApplication::translate("Program", "\345\220\221\344\270\212", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Program", "\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_boardThickness->setText(QApplication::translate("Program", "\346\235\277\345\216\232", 0, QApplication::UnicodeUTF8));
        label_material->setText(QApplication::translate("Program", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        label_mould->setText(QApplication::translate("Program", "\344\270\212\346\250\241", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Program", "mm", 0, QApplication::UnicodeUTF8));
        label_mould_2->setText(QApplication::translate("Program", "\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Program", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Program", "\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        label_mould_3->setText(QApplication::translate("Program", "\347\264\257\350\256\241\345\212\240\345\267\245", 0, QApplication::UnicodeUTF8));
        label_boardThickness_3->setText(QApplication::translate("Program", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Programdb->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Program", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Programdb->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Program", "\346\255\245\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Programdb->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Program", "\346\235\277\345\216\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Programdb->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Program", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Programdb->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Program", "\344\270\212\346\250\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Programdb->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Program", "\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Programdb->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Program", "\345\267\262\345\212\240\345\267\245\346\225\260", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_Programdb->isSortingEnabled();
        tableWidget_Programdb->setSortingEnabled(false);
        tableWidget_Programdb->setSortingEnabled(__sortingEnabled);

        pushButton_D_Del_3->setText(QString());
        pushButton_P_Down->setText(QApplication::translate("Program", "\345\220\221\344\270\213", 0, QApplication::UnicodeUTF8));
        pushButton_Program_New->setText(QString());
        pushButton_D_Up_3->setText(QApplication::translate("Program", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Program: public Ui_Program {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAM_H
