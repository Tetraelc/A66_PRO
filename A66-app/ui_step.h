/********************************************************************************
** Form generated from reading UI file 'step.ui'
**
** Created: Fri Aug 26 14:07:59 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEP_H
#define UI_STEP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Step
{
public:
    QGroupBox *groupBox_4;
    QLabel *label_50;
    QLineEdit *lineEdit_S_Angle;
    QLineEdit *lineEdit_S_Yaxis;
    QLineEdit *lineEdit_S_Xaxis;
    QLineEdit *lineEdit_S_AngleCompensate;
    QLineEdit *lineEdit_S_XaxisCorrect;
    QLabel *label_boardThickness_2;
    QLabel *label_mould_4;
    QLabel *label_mould_5;
    QLabel *label_material_2;
    QLabel *label_mould_6;
    QLineEdit *lineEdit_S_distance;
    QLineEdit *lineEdit_S_return;
    QLineEdit *lineEdit_S_Holding;
    QLineEdit *lineEdit_S_pressure;
    QLineEdit *lineEdit_S_Raxis;
    QLabel *label_boardThickness_4;
    QLabel *label_mould_8;
    QLabel *label_mould_7;
    QLabel *label_material_3;
    QLabel *label_mould_9;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QTableWidget *tableWidget_Step;
    QToolButton *pushButton_Left_7;
    QToolButton *pushButton_Left_5;
    QToolButton *pushButton_Left_6;
    QToolButton *pushButton_Left_1;
    QToolButton *pushButton_Left_8;
    QToolButton *pushButton_Left_3;
    QToolButton *pushButton_Left_2;
    QToolButton *pushButton_Left_4;

    void setupUi(QWidget *Step)
    {
        if (Step->objectName().isEmpty())
            Step->setObjectName(QString::fromUtf8("Step"));
        Step->resize(1024, 540);
        groupBox_4 = new QGroupBox(Step);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 280, 881, 251));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(12);
        groupBox_4->setFont(font);
        groupBox_4->setFlat(false);
        label_50 = new QLabel(groupBox_4);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(320, 120, 58, 15));
        QFont font1;
        font1.setPointSize(14);
        label_50->setFont(font1);
        lineEdit_S_Angle = new QLineEdit(groupBox_4);
        lineEdit_S_Angle->setObjectName(QString::fromUtf8("lineEdit_S_Angle"));
        lineEdit_S_Angle->setGeometry(QRect(144, 30, 170, 30));
        lineEdit_S_Angle->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_Angle->setMaxLength(5);
        lineEdit_S_Yaxis = new QLineEdit(groupBox_4);
        lineEdit_S_Yaxis->setObjectName(QString::fromUtf8("lineEdit_S_Yaxis"));
        lineEdit_S_Yaxis->setGeometry(QRect(144, 110, 170, 30));
        lineEdit_S_Yaxis->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_Xaxis = new QLineEdit(groupBox_4);
        lineEdit_S_Xaxis->setObjectName(QString::fromUtf8("lineEdit_S_Xaxis"));
        lineEdit_S_Xaxis->setGeometry(QRect(144, 150, 170, 30));
        lineEdit_S_Xaxis->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_AngleCompensate = new QLineEdit(groupBox_4);
        lineEdit_S_AngleCompensate->setObjectName(QString::fromUtf8("lineEdit_S_AngleCompensate"));
        lineEdit_S_AngleCompensate->setGeometry(QRect(144, 70, 170, 30));
        lineEdit_S_AngleCompensate->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_XaxisCorrect = new QLineEdit(groupBox_4);
        lineEdit_S_XaxisCorrect->setObjectName(QString::fromUtf8("lineEdit_S_XaxisCorrect"));
        lineEdit_S_XaxisCorrect->setGeometry(QRect(144, 190, 170, 30));
        lineEdit_S_XaxisCorrect->setFocusPolicy(Qt::ClickFocus);
        label_boardThickness_2 = new QLabel(groupBox_4);
        label_boardThickness_2->setObjectName(QString::fromUtf8("label_boardThickness_2"));
        label_boardThickness_2->setGeometry(QRect(50, 40, 81, 20));
        label_boardThickness_2->setFont(font1);
        label_boardThickness_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_4 = new QLabel(groupBox_4);
        label_mould_4->setObjectName(QString::fromUtf8("label_mould_4"));
        label_mould_4->setGeometry(QRect(50, 120, 81, 20));
        label_mould_4->setFont(font1);
        label_mould_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_5 = new QLabel(groupBox_4);
        label_mould_5->setObjectName(QString::fromUtf8("label_mould_5"));
        label_mould_5->setGeometry(QRect(50, 160, 81, 20));
        label_mould_5->setFont(font1);
        label_mould_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_material_2 = new QLabel(groupBox_4);
        label_material_2->setObjectName(QString::fromUtf8("label_material_2"));
        label_material_2->setGeometry(QRect(50, 80, 81, 20));
        label_material_2->setFont(font1);
        label_material_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_6 = new QLabel(groupBox_4);
        label_mould_6->setObjectName(QString::fromUtf8("label_mould_6"));
        label_mould_6->setGeometry(QRect(50, 200, 81, 20));
        label_mould_6->setFont(font1);
        label_mould_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_S_distance = new QLineEdit(groupBox_4);
        lineEdit_S_distance->setObjectName(QString::fromUtf8("lineEdit_S_distance"));
        lineEdit_S_distance->setGeometry(QRect(575, 30, 170, 30));
        lineEdit_S_distance->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_distance->setMaxLength(5);
        lineEdit_S_return = new QLineEdit(groupBox_4);
        lineEdit_S_return->setObjectName(QString::fromUtf8("lineEdit_S_return"));
        lineEdit_S_return->setGeometry(QRect(575, 110, 170, 30));
        lineEdit_S_return->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_return->setFrame(true);
        lineEdit_S_return->setCursorPosition(0);
        lineEdit_S_Holding = new QLineEdit(groupBox_4);
        lineEdit_S_Holding->setObjectName(QString::fromUtf8("lineEdit_S_Holding"));
        lineEdit_S_Holding->setGeometry(QRect(575, 150, 170, 30));
        lineEdit_S_Holding->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_pressure = new QLineEdit(groupBox_4);
        lineEdit_S_pressure->setObjectName(QString::fromUtf8("lineEdit_S_pressure"));
        lineEdit_S_pressure->setGeometry(QRect(575, 70, 170, 30));
        lineEdit_S_pressure->setFocusPolicy(Qt::ClickFocus);
        lineEdit_S_Raxis = new QLineEdit(groupBox_4);
        lineEdit_S_Raxis->setObjectName(QString::fromUtf8("lineEdit_S_Raxis"));
        lineEdit_S_Raxis->setGeometry(QRect(575, 190, 170, 30));
        lineEdit_S_Raxis->setFocusPolicy(Qt::ClickFocus);
        label_boardThickness_4 = new QLabel(groupBox_4);
        label_boardThickness_4->setObjectName(QString::fromUtf8("label_boardThickness_4"));
        label_boardThickness_4->setGeometry(QRect(480, 40, 80, 20));
        label_boardThickness_4->setFont(font1);
        label_boardThickness_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_8 = new QLabel(groupBox_4);
        label_mould_8->setObjectName(QString::fromUtf8("label_mould_8"));
        label_mould_8->setGeometry(QRect(480, 120, 80, 20));
        label_mould_8->setFont(font1);
        label_mould_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_7 = new QLabel(groupBox_4);
        label_mould_7->setObjectName(QString::fromUtf8("label_mould_7"));
        label_mould_7->setGeometry(QRect(480, 160, 80, 20));
        label_mould_7->setFont(font1);
        label_mould_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_material_3 = new QLabel(groupBox_4);
        label_material_3->setObjectName(QString::fromUtf8("label_material_3"));
        label_material_3->setGeometry(QRect(480, 80, 80, 20));
        label_material_3->setFont(font1);
        label_material_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould_9 = new QLabel(groupBox_4);
        label_mould_9->setObjectName(QString::fromUtf8("label_mould_9"));
        label_mould_9->setGeometry(QRect(480, 200, 80, 20));
        label_mould_9->setFont(font1);
        label_mould_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_51 = new QLabel(groupBox_4);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(320, 160, 58, 15));
        label_51->setFont(font1);
        label_52 = new QLabel(groupBox_4);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(320, 200, 58, 15));
        label_52->setFont(font1);
        label_53 = new QLabel(groupBox_4);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(750, 40, 58, 15));
        label_53->setFont(font1);
        label_54 = new QLabel(groupBox_4);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(750, 80, 58, 15));
        label_54->setFont(font1);
        label_55 = new QLabel(groupBox_4);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(750, 120, 58, 15));
        label_55->setFont(font1);
        label_56 = new QLabel(groupBox_4);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(750, 160, 58, 15));
        label_56->setFont(font1);
        label_57 = new QLabel(groupBox_4);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(750, 200, 58, 15));
        label_57->setFont(font1);
        label_58 = new QLabel(groupBox_4);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(320, 80, 31, 16));
        label_58->setFont(font1);
        label_59 = new QLabel(groupBox_4);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(320, 40, 31, 16));
        label_59->setFont(font1);
        tableWidget_Step = new QTableWidget(Step);
        if (tableWidget_Step->columnCount() < 11)
            tableWidget_Step->setColumnCount(11);
        QFont font2;
        font2.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICO/\350\247\222\345\272\246.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font3.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font3);
        __qtablewidgetitem1->setIcon(icon);
        tableWidget_Step->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ICO/\350\247\222\345\272\246\350\241\245\345\201\277.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font2);
        __qtablewidgetitem2->setIcon(icon1);
        tableWidget_Step->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem6->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem7->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem9->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem10->setFont(font2);
        tableWidget_Step->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget_Step->rowCount() < 1)
            tableWidget_Step->setRowCount(1);
        tableWidget_Step->setObjectName(QString::fromUtf8("tableWidget_Step"));
        tableWidget_Step->setGeometry(QRect(20, 10, 881, 261));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Step->sizePolicy().hasHeightForWidth());
        tableWidget_Step->setSizePolicy(sizePolicy);
        tableWidget_Step->setFont(font2);
        tableWidget_Step->setAcceptDrops(false);
        tableWidget_Step->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Step->setMidLineWidth(1);
        tableWidget_Step->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Step->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Step->setAutoScrollMargin(16);
        tableWidget_Step->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Step->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Step->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Step->setTextElideMode(Qt::ElideLeft);
        tableWidget_Step->setGridStyle(Qt::SolidLine);
        tableWidget_Step->setSortingEnabled(false);
        tableWidget_Step->setRowCount(1);
        tableWidget_Step->setColumnCount(11);
        tableWidget_Step->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Step->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_Step->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Step->horizontalHeader()->setStretchLastSection(false);
        tableWidget_Step->verticalHeader()->setVisible(false);
        tableWidget_Step->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_Step->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton_Left_7 = new QToolButton(Step);
        pushButton_Left_7->setObjectName(QString::fromUtf8("pushButton_Left_7"));
        pushButton_Left_7->setGeometry(QRect(930, 408, 71, 61));
        pushButton_Left_7->setFont(font);
        pushButton_Left_7->setIconSize(QSize(36, 36));
        pushButton_Left_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_5 = new QToolButton(Step);
        pushButton_Left_5->setObjectName(QString::fromUtf8("pushButton_Left_5"));
        pushButton_Left_5->setGeometry(QRect(930, 282, 71, 61));
        pushButton_Left_5->setFont(font);
        pushButton_Left_5->setIconSize(QSize(36, 36));
        pushButton_Left_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_6 = new QToolButton(Step);
        pushButton_Left_6->setObjectName(QString::fromUtf8("pushButton_Left_6"));
        pushButton_Left_6->setGeometry(QRect(930, 345, 71, 61));
        pushButton_Left_6->setFont(font);
        pushButton_Left_6->setIconSize(QSize(36, 36));
        pushButton_Left_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_1 = new QToolButton(Step);
        pushButton_Left_1->setObjectName(QString::fromUtf8("pushButton_Left_1"));
        pushButton_Left_1->setGeometry(QRect(930, 10, 71, 61));
        pushButton_Left_1->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ICO/P2-UP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_1->setIcon(icon2);
        pushButton_Left_1->setIconSize(QSize(36, 36));
        pushButton_Left_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
        pushButton_Left_8 = new QToolButton(Step);
        pushButton_Left_8->setObjectName(QString::fromUtf8("pushButton_Left_8"));
        pushButton_Left_8->setGeometry(QRect(930, 471, 71, 61));
        pushButton_Left_8->setFont(font);
        pushButton_Left_8->setIconSize(QSize(36, 36));
        pushButton_Left_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_3 = new QToolButton(Step);
        pushButton_Left_3->setObjectName(QString::fromUtf8("pushButton_Left_3"));
        pushButton_Left_3->setGeometry(QRect(930, 144, 71, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sans Serif"));
        font4.setPointSize(10);
        pushButton_Left_3->setFont(font4);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/ICO/P1-DEL.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_3->setIcon(icon3);
        pushButton_Left_3->setIconSize(QSize(36, 36));
        pushButton_Left_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_2 = new QToolButton(Step);
        pushButton_Left_2->setObjectName(QString::fromUtf8("pushButton_Left_2"));
        pushButton_Left_2->setGeometry(QRect(930, 77, 71, 61));
        pushButton_Left_2->setFont(font4);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/ICO/P1-NEW.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_2->setIcon(icon4);
        pushButton_Left_2->setIconSize(QSize(36, 36));
        pushButton_Left_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_4 = new QToolButton(Step);
        pushButton_Left_4->setObjectName(QString::fromUtf8("pushButton_Left_4"));
        pushButton_Left_4->setGeometry(QRect(930, 210, 71, 61));
        pushButton_Left_4->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ico/ICO/P2-DOWN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_4->setIcon(icon5);
        pushButton_Left_4->setIconSize(QSize(36, 36));
        pushButton_Left_4->setToolButtonStyle(Qt::ToolButtonIconOnly);

        retranslateUi(Step);

        QMetaObject::connectSlotsByName(Step);
    } // setupUi

    void retranslateUi(QWidget *Step)
    {
        Step->setWindowTitle(QApplication::translate("Step", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Step", " \345\267\245\346\255\245\345\217\202\346\225\260 ", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("Step", "mm", 0, QApplication::UnicodeUTF8));
        label_boardThickness_2->setText(QApplication::translate("Step", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        label_mould_4->setText(QApplication::translate("Step", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
        label_mould_5->setText(QApplication::translate("Step", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        label_material_2->setText(QApplication::translate("Step", "\350\247\222\345\272\246\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        label_mould_6->setText(QApplication::translate("Step", "X\350\275\264\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        lineEdit_S_return->setInputMask(QString());
        lineEdit_S_return->setPlaceholderText(QString());
        label_boardThickness_4->setText(QApplication::translate("Step", "\351\200\200\350\256\251\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        label_mould_8->setText(QApplication::translate("Step", "\345\233\236\347\250\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_mould_7->setText(QApplication::translate("Step", "\344\277\235\345\216\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_material_3->setText(QApplication::translate("Step", "\345\216\213\345\212\233", 0, QApplication::UnicodeUTF8));
        label_mould_9->setText(QApplication::translate("Step", "R\350\275\264", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("Step", "mm", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("Step", "mm", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("Step", "mm", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("Step", "KN", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("Step", "S", 0, QApplication::UnicodeUTF8));
        label_56->setText(QApplication::translate("Step", "S", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("Step", "mm", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("Step", "\302\260", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("Step", "\302\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Step->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Step", "\345\267\245\346\255\245\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Step->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Step", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Step->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Step", "\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Step->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Step", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Step->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Step", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Step->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Step", "X\350\275\264\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Step->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Step", "\351\200\200\350\256\251\350\267\235\347\246\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Step->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Step", "\345\216\213\345\212\233", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Step->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Step", "\345\233\236\347\250\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Step->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Step", "\344\277\235\345\216\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Step->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Step", "R\350\275\264", 0, QApplication::UnicodeUTF8));
        pushButton_Left_7->setText(QString());
        pushButton_Left_5->setText(QString());
        pushButton_Left_1->setText(QApplication::translate("Step", "UP", 0, QApplication::UnicodeUTF8));
        pushButton_Left_8->setText(QString());
        pushButton_Left_3->setText(QApplication::translate("Step", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_Left_2->setText(QApplication::translate("Step", "\346\226\260\345\242\236", 0, QApplication::UnicodeUTF8));
        pushButton_Left_4->setText(QApplication::translate("Step", "down", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Step: public Ui_Step {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEP_H
