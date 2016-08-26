/********************************************************************************
** Form generated from reading UI file 'proupmold.ui'
**
** Created: Wed Aug 10 18:38:28 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROUPMOLD_H
#define UI_PROUPMOLD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ProUpMold
{
public:
    QTableWidget *tableWidget_UpMoulds;
    QPushButton *pushButton_ProDCancel;
    QPushButton *pushButton_ProDConfirm;

    void setupUi(QDialog *ProUpMold)
    {
        if (ProUpMold->objectName().isEmpty())
            ProUpMold->setObjectName(QString::fromUtf8("ProUpMold"));
        ProUpMold->resize(626, 266);
        tableWidget_UpMoulds = new QTableWidget(ProUpMold);
        if (tableWidget_UpMoulds->columnCount() < 4)
            tableWidget_UpMoulds->setColumnCount(4);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        tableWidget_UpMoulds->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget_UpMoulds->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font1.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_UpMoulds->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_UpMoulds->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_UpMoulds->rowCount() < 46)
            tableWidget_UpMoulds->setRowCount(46);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_UpMoulds->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_UpMoulds->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        tableWidget_UpMoulds->setItem(2, 3, __qtablewidgetitem6);
        tableWidget_UpMoulds->setObjectName(QString::fromUtf8("tableWidget_UpMoulds"));
        tableWidget_UpMoulds->setGeometry(QRect(0, 0, 621, 241));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_UpMoulds->sizePolicy().hasHeightForWidth());
        tableWidget_UpMoulds->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        tableWidget_UpMoulds->setFont(font2);
        tableWidget_UpMoulds->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_UpMoulds->setAcceptDrops(false);
        tableWidget_UpMoulds->setLayoutDirection(Qt::LeftToRight);
        tableWidget_UpMoulds->setMidLineWidth(1);
        tableWidget_UpMoulds->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_UpMoulds->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_UpMoulds->setAutoScrollMargin(16);
        tableWidget_UpMoulds->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_UpMoulds->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_UpMoulds->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_UpMoulds->setTextElideMode(Qt::ElideRight);
        tableWidget_UpMoulds->setGridStyle(Qt::SolidLine);
        tableWidget_UpMoulds->setSortingEnabled(false);
        tableWidget_UpMoulds->setRowCount(46);
        tableWidget_UpMoulds->setColumnCount(4);
        tableWidget_UpMoulds->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_UpMoulds->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_UpMoulds->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_UpMoulds->horizontalHeader()->setStretchLastSection(false);
        tableWidget_UpMoulds->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_UpMoulds->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton_ProDCancel = new QPushButton(ProUpMold);
        pushButton_ProDCancel->setObjectName(QString::fromUtf8("pushButton_ProDCancel"));
        pushButton_ProDCancel->setGeometry(QRect(530, 240, 80, 27));
        pushButton_ProDCancel->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_ProDConfirm = new QPushButton(ProUpMold);
        pushButton_ProDConfirm->setObjectName(QString::fromUtf8("pushButton_ProDConfirm"));
        pushButton_ProDConfirm->setGeometry(QRect(430, 240, 80, 27));
        pushButton_ProDConfirm->setCursor(QCursor(Qt::ArrowCursor));

        retranslateUi(ProUpMold);

        QMetaObject::connectSlotsByName(ProUpMold);
    } // setupUi

    void retranslateUi(QDialog *ProUpMold)
    {
        ProUpMold->setWindowTitle(QApplication::translate("ProUpMold", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_UpMoulds->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ProUpMold", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_UpMoulds->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ProUpMold", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_UpMoulds->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ProUpMold", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_UpMoulds->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ProUpMold", "\351\230\273\346\212\227", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_UpMoulds->isSortingEnabled();
        tableWidget_UpMoulds->setSortingEnabled(false);
        tableWidget_UpMoulds->setSortingEnabled(__sortingEnabled);

        pushButton_ProDCancel->setText(QApplication::translate("ProUpMold", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_ProDConfirm->setText(QApplication::translate("ProUpMold", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProUpMold: public Ui_ProUpMold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROUPMOLD_H
