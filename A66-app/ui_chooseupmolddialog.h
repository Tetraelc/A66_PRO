/********************************************************************************
** Form generated from reading UI file 'chooseupmolddialog.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEUPMOLDDIALOG_H
#define UI_CHOOSEUPMOLDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseUpMoldDialog
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidget_UpMoulds;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *chooseUpMoldDialog)
    {
        if (chooseUpMoldDialog->objectName().isEmpty())
            chooseUpMoldDialog->setObjectName(QString::fromUtf8("chooseUpMoldDialog"));
        chooseUpMoldDialog->resize(722, 430);
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
        chooseUpMoldDialog->setPalette(palette);
        groupBox = new QGroupBox(chooseUpMoldDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 681, 391));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(106, 104, 100, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        groupBox->setPalette(palette1);
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        tableWidget_UpMoulds = new QTableWidget(groupBox);
        if (tableWidget_UpMoulds->columnCount() < 5)
            tableWidget_UpMoulds->setColumnCount(5);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        tableWidget_UpMoulds->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget_UpMoulds->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_UpMoulds->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font3.setPointSize(15);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        tableWidget_UpMoulds->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        tableWidget_UpMoulds->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget_UpMoulds->rowCount() < 46)
            tableWidget_UpMoulds->setRowCount(46);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_UpMoulds->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_UpMoulds->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        tableWidget_UpMoulds->setItem(2, 4, __qtablewidgetitem7);
        tableWidget_UpMoulds->setObjectName(QString::fromUtf8("tableWidget_UpMoulds"));
        tableWidget_UpMoulds->setGeometry(QRect(20, 40, 631, 281));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_UpMoulds->sizePolicy().hasHeightForWidth());
        tableWidget_UpMoulds->setSizePolicy(sizePolicy);
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
        tableWidget_UpMoulds->setColumnCount(5);
        tableWidget_UpMoulds->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_UpMoulds->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_UpMoulds->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_UpMoulds->horizontalHeader()->setStretchLastSection(false);
        tableWidget_UpMoulds->verticalHeader()->setVisible(false);
        tableWidget_UpMoulds->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_UpMoulds->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(230, 340, 211, 31));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        retranslateUi(chooseUpMoldDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), chooseUpMoldDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(chooseUpMoldDialog);
    } // setupUi

    void retranslateUi(QDialog *chooseUpMoldDialog)
    {
        chooseUpMoldDialog->setWindowTitle(QApplication::translate("chooseUpMoldDialog", "\351\200\211\346\213\251\344\270\212\346\250\241", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("chooseUpMoldDialog", " \351\200\211\346\213\251\344\270\212\346\250\241 ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_UpMoulds->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("chooseUpMoldDialog", "\346\250\241\345\205\267\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_UpMoulds->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("chooseUpMoldDialog", "\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_UpMoulds->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("chooseUpMoldDialog", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_UpMoulds->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("chooseUpMoldDialog", "\345\215\212\345\276\204", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_UpMoulds->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("chooseUpMoldDialog", "\351\230\273\346\212\227", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_UpMoulds->isSortingEnabled();
        tableWidget_UpMoulds->setSortingEnabled(false);
        tableWidget_UpMoulds->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class chooseUpMoldDialog: public Ui_chooseUpMoldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEUPMOLDDIALOG_H
