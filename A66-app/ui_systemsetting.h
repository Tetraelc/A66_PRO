/********************************************************************************
** Form generated from reading UI file 'systemsetting.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTING_H
#define UI_SYSTEMSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemSetting
{
public:
    QTreeWidget *treeWidget_System;
    QWidget *widget_System;
    QGroupBox *groupBox_7;
    QLineEdit *lineEdit_KeepTime;
    QLineEdit *lineEdit_UnloadTime;
    QLabel *label_KeepTime;
    QLabel *label_UnloadTime;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox;
    QCheckBox *checkBoxVFast1;
    QCheckBox *checkBoxVFast2;
    QCheckBox *checkBoxVFast3;
    QCheckBox *checkBoxVFast4;
    QCheckBox *checkBoxVFast5;
    QCheckBox *checkBoxVFast6;
    QCheckBox *checkBoxVFast7;
    QCheckBox *checkBoxVFast8;
    QCheckBox *checkBoxVSlow2;
    QCheckBox *checkBoxVSlow1;
    QCheckBox *checkBoxVSlow7;
    QCheckBox *checkBoxVSlow3;
    QCheckBox *checkBoxVSlow4;
    QCheckBox *checkBoxVSlow8;
    QCheckBox *checkBoxVSlow5;
    QCheckBox *checkBoxVSlow6;
    QCheckBox *checkBoxVkeep5;
    QCheckBox *checkBoxVkeep8;
    QCheckBox *checkBoxVkeep2;
    QCheckBox *checkBoxVkeep7;
    QCheckBox *checkBoxVkeep1;
    QCheckBox *checkBoxVkeep6;
    QCheckBox *checkBoxVkeep3;
    QCheckBox *checkBoxVkeep4;
    QCheckBox *checkBoxVunload3;
    QCheckBox *checkBoxVunload2;
    QCheckBox *checkBoxVunload5;
    QCheckBox *checkBoxVunload1;
    QCheckBox *checkBoxVunload6;
    QCheckBox *checkBoxVunload8;
    QCheckBox *checkBoxVunload4;
    QCheckBox *checkBoxVunload7;
    QCheckBox *checkBoxVback4;
    QCheckBox *checkBoxVback5;
    QCheckBox *checkBoxVback7;
    QCheckBox *checkBoxVback3;
    QCheckBox *checkBoxVback2;
    QCheckBox *checkBoxVback6;
    QCheckBox *checkBoxVback8;
    QCheckBox *checkBoxVback1;
    QCheckBox *checkBoxVstop1;
    QCheckBox *checkBoxVstop4;
    QCheckBox *checkBoxVstop5;
    QCheckBox *checkBoxVstop7;
    QCheckBox *checkBoxVstop8;
    QCheckBox *checkBoxVstop3;
    QCheckBox *checkBoxVstop2;
    QCheckBox *checkBoxVstop6;
    QToolButton *toolButton_confirm;
    QToolButton *toolButton_readConfig;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_2;
    QTableWidget *tableWidget_System;

    void setupUi(QWidget *SystemSetting)
    {
        if (SystemSetting->objectName().isEmpty())
            SystemSetting->setObjectName(QString::fromUtf8("SystemSetting"));
        SystemSetting->resize(1024, 540);
        treeWidget_System = new QTreeWidget(SystemSetting);
        QFont font;
        font.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font);
        treeWidget_System->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget_System);
        __qtreewidgetitem1->setFlags(Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget_System);
        __qtreewidgetitem2->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget_System);
        __qtreewidgetitem3->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        treeWidget_System->setObjectName(QString::fromUtf8("treeWidget_System"));
        treeWidget_System->setGeometry(QRect(30, 20, 171, 491));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font1.setPointSize(12);
        treeWidget_System->setFont(font1);
        widget_System = new QWidget(SystemSetting);
        widget_System->setObjectName(QString::fromUtf8("widget_System"));
        widget_System->setGeometry(QRect(210, 20, 791, 491));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(244, 244, 242, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        widget_System->setPalette(palette);
        groupBox_7 = new QGroupBox(widget_System);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(150, 320, 509, 53));
        lineEdit_KeepTime = new QLineEdit(groupBox_7);
        lineEdit_KeepTime->setObjectName(QString::fromUtf8("lineEdit_KeepTime"));
        lineEdit_KeepTime->setGeometry(QRect(90, 18, 113, 30));
        lineEdit_UnloadTime = new QLineEdit(groupBox_7);
        lineEdit_UnloadTime->setObjectName(QString::fromUtf8("lineEdit_UnloadTime"));
        lineEdit_UnloadTime->setGeometry(QRect(350, 17, 113, 31));
        label_KeepTime = new QLabel(groupBox_7);
        label_KeepTime->setObjectName(QString::fromUtf8("label_KeepTime"));
        label_KeepTime->setGeometry(QRect(20, 20, 61, 31));
        label_UnloadTime = new QLabel(groupBox_7);
        label_UnloadTime->setObjectName(QString::fromUtf8("label_UnloadTime"));
        label_UnloadTime->setGeometry(QRect(270, 20, 61, 31));
        label = new QLabel(widget_System);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 59, 471, 21));
        lineEdit_3 = new QLineEdit(widget_System);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 380, 113, 30));
        groupBox = new QGroupBox(widget_System);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(151, 80, 509, 241));
        checkBoxVFast1 = new QCheckBox(groupBox);
        checkBoxVFast1->setObjectName(QString::fromUtf8("checkBoxVFast1"));
        checkBoxVFast1->setGeometry(QRect(30, 10, 21, 21));
        checkBoxVFast2 = new QCheckBox(groupBox);
        checkBoxVFast2->setObjectName(QString::fromUtf8("checkBoxVFast2"));
        checkBoxVFast2->setGeometry(QRect(80, 10, 21, 21));
        checkBoxVFast3 = new QCheckBox(groupBox);
        checkBoxVFast3->setObjectName(QString::fromUtf8("checkBoxVFast3"));
        checkBoxVFast3->setGeometry(QRect(130, 10, 21, 21));
        checkBoxVFast4 = new QCheckBox(groupBox);
        checkBoxVFast4->setObjectName(QString::fromUtf8("checkBoxVFast4"));
        checkBoxVFast4->setGeometry(QRect(180, 10, 21, 21));
        checkBoxVFast5 = new QCheckBox(groupBox);
        checkBoxVFast5->setObjectName(QString::fromUtf8("checkBoxVFast5"));
        checkBoxVFast5->setGeometry(QRect(230, 10, 21, 21));
        checkBoxVFast6 = new QCheckBox(groupBox);
        checkBoxVFast6->setObjectName(QString::fromUtf8("checkBoxVFast6"));
        checkBoxVFast6->setGeometry(QRect(280, 10, 21, 21));
        checkBoxVFast7 = new QCheckBox(groupBox);
        checkBoxVFast7->setObjectName(QString::fromUtf8("checkBoxVFast7"));
        checkBoxVFast7->setGeometry(QRect(330, 10, 21, 21));
        checkBoxVFast8 = new QCheckBox(groupBox);
        checkBoxVFast8->setObjectName(QString::fromUtf8("checkBoxVFast8"));
        checkBoxVFast8->setGeometry(QRect(380, 10, 21, 21));
        checkBoxVSlow2 = new QCheckBox(groupBox);
        checkBoxVSlow2->setObjectName(QString::fromUtf8("checkBoxVSlow2"));
        checkBoxVSlow2->setGeometry(QRect(80, 50, 21, 21));
        checkBoxVSlow1 = new QCheckBox(groupBox);
        checkBoxVSlow1->setObjectName(QString::fromUtf8("checkBoxVSlow1"));
        checkBoxVSlow1->setGeometry(QRect(30, 50, 21, 21));
        checkBoxVSlow7 = new QCheckBox(groupBox);
        checkBoxVSlow7->setObjectName(QString::fromUtf8("checkBoxVSlow7"));
        checkBoxVSlow7->setGeometry(QRect(330, 50, 21, 21));
        checkBoxVSlow3 = new QCheckBox(groupBox);
        checkBoxVSlow3->setObjectName(QString::fromUtf8("checkBoxVSlow3"));
        checkBoxVSlow3->setGeometry(QRect(130, 50, 21, 21));
        checkBoxVSlow4 = new QCheckBox(groupBox);
        checkBoxVSlow4->setObjectName(QString::fromUtf8("checkBoxVSlow4"));
        checkBoxVSlow4->setGeometry(QRect(180, 50, 21, 21));
        checkBoxVSlow8 = new QCheckBox(groupBox);
        checkBoxVSlow8->setObjectName(QString::fromUtf8("checkBoxVSlow8"));
        checkBoxVSlow8->setGeometry(QRect(380, 50, 21, 21));
        checkBoxVSlow5 = new QCheckBox(groupBox);
        checkBoxVSlow5->setObjectName(QString::fromUtf8("checkBoxVSlow5"));
        checkBoxVSlow5->setGeometry(QRect(230, 50, 21, 21));
        checkBoxVSlow6 = new QCheckBox(groupBox);
        checkBoxVSlow6->setObjectName(QString::fromUtf8("checkBoxVSlow6"));
        checkBoxVSlow6->setGeometry(QRect(280, 50, 21, 21));
        checkBoxVkeep5 = new QCheckBox(groupBox);
        checkBoxVkeep5->setObjectName(QString::fromUtf8("checkBoxVkeep5"));
        checkBoxVkeep5->setGeometry(QRect(230, 90, 21, 21));
        checkBoxVkeep8 = new QCheckBox(groupBox);
        checkBoxVkeep8->setObjectName(QString::fromUtf8("checkBoxVkeep8"));
        checkBoxVkeep8->setGeometry(QRect(380, 90, 21, 21));
        checkBoxVkeep2 = new QCheckBox(groupBox);
        checkBoxVkeep2->setObjectName(QString::fromUtf8("checkBoxVkeep2"));
        checkBoxVkeep2->setGeometry(QRect(80, 90, 21, 21));
        checkBoxVkeep7 = new QCheckBox(groupBox);
        checkBoxVkeep7->setObjectName(QString::fromUtf8("checkBoxVkeep7"));
        checkBoxVkeep7->setGeometry(QRect(330, 90, 21, 21));
        checkBoxVkeep1 = new QCheckBox(groupBox);
        checkBoxVkeep1->setObjectName(QString::fromUtf8("checkBoxVkeep1"));
        checkBoxVkeep1->setGeometry(QRect(30, 90, 21, 21));
        checkBoxVkeep6 = new QCheckBox(groupBox);
        checkBoxVkeep6->setObjectName(QString::fromUtf8("checkBoxVkeep6"));
        checkBoxVkeep6->setGeometry(QRect(280, 90, 21, 21));
        checkBoxVkeep3 = new QCheckBox(groupBox);
        checkBoxVkeep3->setObjectName(QString::fromUtf8("checkBoxVkeep3"));
        checkBoxVkeep3->setGeometry(QRect(130, 90, 21, 21));
        checkBoxVkeep4 = new QCheckBox(groupBox);
        checkBoxVkeep4->setObjectName(QString::fromUtf8("checkBoxVkeep4"));
        checkBoxVkeep4->setGeometry(QRect(180, 90, 21, 21));
        checkBoxVunload3 = new QCheckBox(groupBox);
        checkBoxVunload3->setObjectName(QString::fromUtf8("checkBoxVunload3"));
        checkBoxVunload3->setGeometry(QRect(130, 130, 21, 21));
        checkBoxVunload2 = new QCheckBox(groupBox);
        checkBoxVunload2->setObjectName(QString::fromUtf8("checkBoxVunload2"));
        checkBoxVunload2->setGeometry(QRect(80, 130, 21, 21));
        checkBoxVunload5 = new QCheckBox(groupBox);
        checkBoxVunload5->setObjectName(QString::fromUtf8("checkBoxVunload5"));
        checkBoxVunload5->setGeometry(QRect(230, 130, 21, 21));
        checkBoxVunload1 = new QCheckBox(groupBox);
        checkBoxVunload1->setObjectName(QString::fromUtf8("checkBoxVunload1"));
        checkBoxVunload1->setGeometry(QRect(30, 130, 21, 21));
        checkBoxVunload6 = new QCheckBox(groupBox);
        checkBoxVunload6->setObjectName(QString::fromUtf8("checkBoxVunload6"));
        checkBoxVunload6->setGeometry(QRect(280, 130, 21, 21));
        checkBoxVunload8 = new QCheckBox(groupBox);
        checkBoxVunload8->setObjectName(QString::fromUtf8("checkBoxVunload8"));
        checkBoxVunload8->setGeometry(QRect(380, 130, 21, 21));
        checkBoxVunload4 = new QCheckBox(groupBox);
        checkBoxVunload4->setObjectName(QString::fromUtf8("checkBoxVunload4"));
        checkBoxVunload4->setGeometry(QRect(180, 130, 21, 21));
        checkBoxVunload7 = new QCheckBox(groupBox);
        checkBoxVunload7->setObjectName(QString::fromUtf8("checkBoxVunload7"));
        checkBoxVunload7->setGeometry(QRect(330, 130, 21, 21));
        checkBoxVback4 = new QCheckBox(groupBox);
        checkBoxVback4->setObjectName(QString::fromUtf8("checkBoxVback4"));
        checkBoxVback4->setGeometry(QRect(180, 170, 21, 21));
        checkBoxVback5 = new QCheckBox(groupBox);
        checkBoxVback5->setObjectName(QString::fromUtf8("checkBoxVback5"));
        checkBoxVback5->setGeometry(QRect(230, 170, 21, 21));
        checkBoxVback7 = new QCheckBox(groupBox);
        checkBoxVback7->setObjectName(QString::fromUtf8("checkBoxVback7"));
        checkBoxVback7->setGeometry(QRect(330, 170, 21, 21));
        checkBoxVback3 = new QCheckBox(groupBox);
        checkBoxVback3->setObjectName(QString::fromUtf8("checkBoxVback3"));
        checkBoxVback3->setGeometry(QRect(130, 170, 21, 21));
        checkBoxVback2 = new QCheckBox(groupBox);
        checkBoxVback2->setObjectName(QString::fromUtf8("checkBoxVback2"));
        checkBoxVback2->setGeometry(QRect(80, 170, 21, 21));
        checkBoxVback6 = new QCheckBox(groupBox);
        checkBoxVback6->setObjectName(QString::fromUtf8("checkBoxVback6"));
        checkBoxVback6->setGeometry(QRect(280, 170, 21, 21));
        checkBoxVback8 = new QCheckBox(groupBox);
        checkBoxVback8->setObjectName(QString::fromUtf8("checkBoxVback8"));
        checkBoxVback8->setGeometry(QRect(380, 170, 21, 21));
        checkBoxVback1 = new QCheckBox(groupBox);
        checkBoxVback1->setObjectName(QString::fromUtf8("checkBoxVback1"));
        checkBoxVback1->setGeometry(QRect(30, 170, 21, 21));
        checkBoxVstop1 = new QCheckBox(groupBox);
        checkBoxVstop1->setObjectName(QString::fromUtf8("checkBoxVstop1"));
        checkBoxVstop1->setGeometry(QRect(30, 210, 21, 21));
        checkBoxVstop4 = new QCheckBox(groupBox);
        checkBoxVstop4->setObjectName(QString::fromUtf8("checkBoxVstop4"));
        checkBoxVstop4->setGeometry(QRect(180, 210, 21, 21));
        checkBoxVstop5 = new QCheckBox(groupBox);
        checkBoxVstop5->setObjectName(QString::fromUtf8("checkBoxVstop5"));
        checkBoxVstop5->setGeometry(QRect(230, 210, 21, 21));
        checkBoxVstop7 = new QCheckBox(groupBox);
        checkBoxVstop7->setObjectName(QString::fromUtf8("checkBoxVstop7"));
        checkBoxVstop7->setGeometry(QRect(330, 210, 21, 21));
        checkBoxVstop8 = new QCheckBox(groupBox);
        checkBoxVstop8->setObjectName(QString::fromUtf8("checkBoxVstop8"));
        checkBoxVstop8->setGeometry(QRect(380, 210, 21, 21));
        checkBoxVstop3 = new QCheckBox(groupBox);
        checkBoxVstop3->setObjectName(QString::fromUtf8("checkBoxVstop3"));
        checkBoxVstop3->setGeometry(QRect(130, 210, 21, 21));
        checkBoxVstop2 = new QCheckBox(groupBox);
        checkBoxVstop2->setObjectName(QString::fromUtf8("checkBoxVstop2"));
        checkBoxVstop2->setGeometry(QRect(80, 210, 21, 21));
        checkBoxVstop6 = new QCheckBox(groupBox);
        checkBoxVstop6->setObjectName(QString::fromUtf8("checkBoxVstop6"));
        checkBoxVstop6->setGeometry(QRect(280, 210, 21, 21));
        toolButton_confirm = new QToolButton(widget_System);
        toolButton_confirm->setObjectName(QString::fromUtf8("toolButton_confirm"));
        toolButton_confirm->setGeometry(QRect(490, 380, 51, 31));
        toolButton_readConfig = new QToolButton(widget_System);
        toolButton_readConfig->setObjectName(QString::fromUtf8("toolButton_readConfig"));
        toolButton_readConfig->setGeometry(QRect(190, 380, 51, 31));
        label_3 = new QLabel(widget_System);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 130, 31, 21));
        label_4 = new QLabel(widget_System);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 170, 31, 21));
        label_5 = new QLabel(widget_System);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 210, 31, 21));
        label_6 = new QLabel(widget_System);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 250, 31, 21));
        label_7 = new QLabel(widget_System);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 290, 31, 21));
        label_2 = new QLabel(widget_System);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 90, 31, 21));
        tableWidget_System = new QTableWidget(widget_System);
        if (tableWidget_System->columnCount() < 4)
            tableWidget_System->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_System->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_System->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_System->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_System->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_System->setObjectName(QString::fromUtf8("tableWidget_System"));
        tableWidget_System->setGeometry(QRect(0, 0, 791, 491));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setPointSize(10);
        tableWidget_System->setFont(font2);
        tableWidget_System->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableWidget_System->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_System->setRowCount(0);
        tableWidget_System->setColumnCount(4);
        tableWidget_System->horizontalHeader()->setVisible(false);
        tableWidget_System->horizontalHeader()->setHighlightSections(false);
        tableWidget_System->verticalHeader()->setVisible(false);
        widget_System->raise();
        treeWidget_System->raise();

        retranslateUi(SystemSetting);

        QMetaObject::connectSlotsByName(SystemSetting);
    } // setupUi

    void retranslateUi(QWidget *SystemSetting)
    {
        SystemSetting->setWindowTitle(QApplication::translate("SystemSetting", "Form", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_System->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SystemSetting", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget_System->isSortingEnabled();
        treeWidget_System->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_System->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("SystemSetting", "\351\200\232\347\224\250", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("SystemSetting", "\345\270\270\351\207\217", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("SystemSetting", "\350\257\212\346\226\255", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_System->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("SystemSetting", "\350\275\264\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QApplication::translate("SystemSetting", "\346\266\262\345\216\213\350\275\264", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(0, QApplication::translate("SystemSetting", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem4->child(2);
        ___qtreewidgetitem7->setText(0, QApplication::translate("SystemSetting", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem4->child(3);
        ___qtreewidgetitem8->setText(0, QApplication::translate("SystemSetting", "R\350\275\264", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget_System->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("SystemSetting", "\351\253\230\347\272\247\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("SystemSetting", "\345\267\245\345\216\202\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("SystemSetting", "\351\230\200\347\273\204\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        treeWidget_System->setSortingEnabled(__sortingEnabled);

        groupBox_7->setTitle(QApplication::translate("SystemSetting", "\346\227\266\351\227\264\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        label_KeepTime->setText(QApplication::translate("SystemSetting", "\344\277\235\345\216\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_UnloadTime->setText(QApplication::translate("SystemSetting", "\345\215\270\350\215\267\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SystemSetting", "        KA1       KA2         KA3       KA4        KA5         KA6        KA7        KA8   ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        checkBoxVFast1->setText(QString());
        checkBoxVFast2->setText(QString());
        checkBoxVFast3->setText(QString());
        checkBoxVFast4->setText(QString());
        checkBoxVFast5->setText(QString());
        checkBoxVFast6->setText(QString());
        checkBoxVFast7->setText(QString());
        checkBoxVFast8->setText(QString());
        checkBoxVSlow2->setText(QString());
        checkBoxVSlow1->setText(QString());
        checkBoxVSlow7->setText(QString());
        checkBoxVSlow3->setText(QString());
        checkBoxVSlow4->setText(QString());
        checkBoxVSlow8->setText(QString());
        checkBoxVSlow5->setText(QString());
        checkBoxVSlow6->setText(QString());
        checkBoxVkeep5->setText(QString());
        checkBoxVkeep8->setText(QString());
        checkBoxVkeep2->setText(QString());
        checkBoxVkeep7->setText(QString());
        checkBoxVkeep1->setText(QString());
        checkBoxVkeep6->setText(QString());
        checkBoxVkeep3->setText(QString());
        checkBoxVkeep4->setText(QString());
        checkBoxVunload3->setText(QString());
        checkBoxVunload2->setText(QString());
        checkBoxVunload5->setText(QString());
        checkBoxVunload1->setText(QString());
        checkBoxVunload6->setText(QString());
        checkBoxVunload8->setText(QString());
        checkBoxVunload4->setText(QString());
        checkBoxVunload7->setText(QString());
        checkBoxVback4->setText(QString());
        checkBoxVback5->setText(QString());
        checkBoxVback7->setText(QString());
        checkBoxVback3->setText(QString());
        checkBoxVback2->setText(QString());
        checkBoxVback6->setText(QString());
        checkBoxVback8->setText(QString());
        checkBoxVback1->setText(QString());
        checkBoxVstop1->setText(QString());
        checkBoxVstop4->setText(QString());
        checkBoxVstop5->setText(QString());
        checkBoxVstop7->setText(QString());
        checkBoxVstop8->setText(QString());
        checkBoxVstop3->setText(QString());
        checkBoxVstop2->setText(QString());
        checkBoxVstop6->setText(QString());
        toolButton_confirm->setText(QApplication::translate("SystemSetting", "\345\206\231\345\205\245", 0, QApplication::UnicodeUTF8));
        toolButton_readConfig->setText(QApplication::translate("SystemSetting", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SystemSetting", "\345\267\245\350\277\233", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SystemSetting", "\344\277\235\345\216\213", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SystemSetting", "\345\215\270\350\215\267", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SystemSetting", "\345\233\236\347\250\213", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SystemSetting", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SystemSetting", "\345\277\253\344\270\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_System->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SystemSetting", "\347\264\242\345\274\225", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_System->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SystemSetting", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_System->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SystemSetting", "\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_System->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SystemSetting", "\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemSetting: public Ui_SystemSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H
