/********************************************************************************
** Form generated from reading UI file 'chooselowermolddialog.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELOWERMOLDDIALOG_H
#define UI_CHOOSELOWERMOLDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseLowerMoldDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTableWidget *tableWidget_LowerMoulds;

    void setupUi(QDialog *chooseLowerMoldDialog)
    {
        if (chooseLowerMoldDialog->objectName().isEmpty())
            chooseLowerMoldDialog->setObjectName(QString::fromUtf8("chooseLowerMoldDialog"));
        chooseLowerMoldDialog->setWindowModality(Qt::NonModal);
        chooseLowerMoldDialog->resize(639, 343);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(85, 85, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        chooseLowerMoldDialog->setPalette(palette);
        buttonBox = new QDialogButtonBox(chooseLowerMoldDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 290, 471, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(chooseLowerMoldDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 511, 31));
        QPalette palette1;
        QBrush brush2(QColor(174, 255, 239, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        tableWidget_LowerMoulds = new QTableWidget(chooseLowerMoldDialog);
        if (tableWidget_LowerMoulds->columnCount() < 8)
            tableWidget_LowerMoulds->setColumnCount(8);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget_LowerMoulds->rowCount() < 50)
            tableWidget_LowerMoulds->setRowCount(50);
        QFont font3;
        font3.setKerning(false);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font3);
        tableWidget_LowerMoulds->setItem(0, 0, __qtablewidgetitem8);
        tableWidget_LowerMoulds->setObjectName(QString::fromUtf8("tableWidget_LowerMoulds"));
        tableWidget_LowerMoulds->setGeometry(QRect(0, 40, 641, 241));
        QFont font4;
        font4.setPointSize(12);
        tableWidget_LowerMoulds->setFont(font4);
        tableWidget_LowerMoulds->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_LowerMoulds->setFrameShadow(QFrame::Sunken);
        tableWidget_LowerMoulds->setMidLineWidth(1);
        tableWidget_LowerMoulds->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_LowerMoulds->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_LowerMoulds->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_LowerMoulds->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_LowerMoulds->setShowGrid(true);
        tableWidget_LowerMoulds->setSortingEnabled(false);
        tableWidget_LowerMoulds->setCornerButtonEnabled(false);
        tableWidget_LowerMoulds->setRowCount(50);
        tableWidget_LowerMoulds->setColumnCount(8);
        tableWidget_LowerMoulds->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_LowerMoulds->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_LowerMoulds->horizontalHeader()->setMinimumSectionSize(23);
        tableWidget_LowerMoulds->verticalHeader()->setVisible(false);
        tableWidget_LowerMoulds->verticalHeader()->setDefaultSectionSize(30);

        retranslateUi(chooseLowerMoldDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), chooseLowerMoldDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(chooseLowerMoldDialog);
    } // setupUi

    void retranslateUi(QDialog *chooseLowerMoldDialog)
    {
        chooseLowerMoldDialog->setWindowTitle(QApplication::translate("chooseLowerMoldDialog", "\351\200\211\346\213\251\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("chooseLowerMoldDialog", "\351\200\211\346\213\251\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_LowerMoulds->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("chooseLowerMoldDialog", "\346\250\241\345\205\267\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_LowerMoulds->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("chooseLowerMoldDialog", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_LowerMoulds->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("chooseLowerMoldDialog", "V\345\274\200\345\217\243", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_LowerMoulds->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("chooseLowerMoldDialog", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_LowerMoulds->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("chooseLowerMoldDialog", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_LowerMoulds->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("chooseLowerMoldDialog", "\351\200\237\345\272\246\350\275\254\346\215\242\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_LowerMoulds->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("chooseLowerMoldDialog", "X\350\275\264\345\256\211\345\205\250\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_LowerMoulds->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("chooseLowerMoldDialog", "\351\230\273\346\212\227", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_LowerMoulds->isSortingEnabled();
        tableWidget_LowerMoulds->setSortingEnabled(false);
        tableWidget_LowerMoulds->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class chooseLowerMoldDialog: public Ui_chooseLowerMoldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELOWERMOLDDIALOG_H
