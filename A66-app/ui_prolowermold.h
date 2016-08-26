/********************************************************************************
** Form generated from reading UI file 'prolowermold.ui'
**
** Created: Wed Aug 10 18:44:23 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROLOWERMOLD_H
#define UI_PROLOWERMOLD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ProLowerMold
{
public:
    QTableWidget *tableWidget_LowerMoulds;
    QPushButton *pushButton_ProUConfirm;
    QPushButton *pushButton_ProUCancel;

    void setupUi(QDialog *ProLowerMold)
    {
        if (ProLowerMold->objectName().isEmpty())
            ProLowerMold->setObjectName(QString::fromUtf8("ProLowerMold"));
        ProLowerMold->resize(838, 370);
        tableWidget_LowerMoulds = new QTableWidget(ProLowerMold);
        if (tableWidget_LowerMoulds->columnCount() < 7)
            tableWidget_LowerMoulds->setColumnCount(7);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget_LowerMoulds->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_LowerMoulds->rowCount() < 50)
            tableWidget_LowerMoulds->setRowCount(50);
        QFont font1;
        font1.setKerning(false);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font1);
        tableWidget_LowerMoulds->setItem(0, 0, __qtablewidgetitem7);
        tableWidget_LowerMoulds->setObjectName(QString::fromUtf8("tableWidget_LowerMoulds"));
        tableWidget_LowerMoulds->setGeometry(QRect(0, 0, 621, 241));
        QFont font2;
        font2.setPointSize(12);
        tableWidget_LowerMoulds->setFont(font2);
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
        tableWidget_LowerMoulds->setColumnCount(7);
        tableWidget_LowerMoulds->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_LowerMoulds->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_LowerMoulds->horizontalHeader()->setMinimumSectionSize(23);
        tableWidget_LowerMoulds->verticalHeader()->setDefaultSectionSize(30);
        pushButton_ProUConfirm = new QPushButton(ProLowerMold);
        pushButton_ProUConfirm->setObjectName(QString::fromUtf8("pushButton_ProUConfirm"));
        pushButton_ProUConfirm->setGeometry(QRect(440, 240, 80, 27));
        pushButton_ProUConfirm->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_ProUCancel = new QPushButton(ProLowerMold);
        pushButton_ProUCancel->setObjectName(QString::fromUtf8("pushButton_ProUCancel"));
        pushButton_ProUCancel->setGeometry(QRect(540, 240, 80, 27));
        pushButton_ProUCancel->setCursor(QCursor(Qt::ArrowCursor));

        retranslateUi(ProLowerMold);

        QMetaObject::connectSlotsByName(ProLowerMold);
    } // setupUi

    void retranslateUi(QDialog *ProLowerMold)
    {
        ProLowerMold->setWindowTitle(QApplication::translate("ProLowerMold", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_LowerMoulds->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ProLowerMold", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_LowerMoulds->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ProLowerMold", "V\345\274\200\345\217\243", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_LowerMoulds->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ProLowerMold", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_LowerMoulds->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ProLowerMold", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_LowerMoulds->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ProLowerMold", "\351\200\237\345\272\246\350\275\254\346\215\242\347\202\271", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_LowerMoulds->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ProLowerMold", "X\350\275\264\345\256\211\345\205\250\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_LowerMoulds->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ProLowerMold", "\351\230\273\346\212\227", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_LowerMoulds->isSortingEnabled();
        tableWidget_LowerMoulds->setSortingEnabled(false);
        tableWidget_LowerMoulds->setSortingEnabled(__sortingEnabled);

        pushButton_ProUConfirm->setText(QApplication::translate("ProLowerMold", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton_ProUCancel->setText(QApplication::translate("ProLowerMold", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProLowerMold: public Ui_ProLowerMold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROLOWERMOLD_H
