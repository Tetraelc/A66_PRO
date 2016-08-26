/********************************************************************************
** Form generated from reading UI file 'manualadjustdate.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALADJUSTDATE_H
#define UI_MANUALADJUSTDATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_ManualAdjustDate
{
public:
    QLineEdit *lineEdit_ManualR;
    QLineEdit *lineEdit_ManualX;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QLabel *label_38;
    QLineEdit *lineEdit_ManualY;
    QLabel *label_37;
    QToolButton *toolButton_4;
    QLabel *label_39;

    void setupUi(QDialog *ManualAdjustDate)
    {
        if (ManualAdjustDate->objectName().isEmpty())
            ManualAdjustDate->setObjectName(QString::fromUtf8("ManualAdjustDate"));
        ManualAdjustDate->resize(375, 501);
        lineEdit_ManualR = new QLineEdit(ManualAdjustDate);
        lineEdit_ManualR->setObjectName(QString::fromUtf8("lineEdit_ManualR"));
        lineEdit_ManualR->setGeometry(QRect(100, 284, 181, 40));
        lineEdit_ManualR->setReadOnly(false);
        lineEdit_ManualX = new QLineEdit(ManualAdjustDate);
        lineEdit_ManualX->setObjectName(QString::fromUtf8("lineEdit_ManualX"));
        lineEdit_ManualX->setGeometry(QRect(100, 104, 181, 40));
        lineEdit_ManualX->setReadOnly(false);
        toolButton = new QToolButton(ManualAdjustDate);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(310, 105, 61, 41));
        toolButton_3 = new QToolButton(ManualAdjustDate);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(310, 285, 61, 41));
        toolButton_2 = new QToolButton(ManualAdjustDate);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(310, 195, 61, 41));
        label_38 = new QLabel(ManualAdjustDate);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(20, 114, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(20);
        label_38->setFont(font);
        lineEdit_ManualY = new QLineEdit(ManualAdjustDate);
        lineEdit_ManualY->setObjectName(QString::fromUtf8("lineEdit_ManualY"));
        lineEdit_ManualY->setGeometry(QRect(100, 193, 181, 40));
        lineEdit_ManualY->setReadOnly(false);
        label_37 = new QLabel(ManualAdjustDate);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(20, 284, 81, 41));
        label_37->setFont(font);
        toolButton_4 = new QToolButton(ManualAdjustDate);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(130, 370, 121, 41));
        label_39 = new QLabel(ManualAdjustDate);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(20, 200, 81, 31));
        label_39->setFont(font);

        retranslateUi(ManualAdjustDate);
        QObject::connect(toolButton_4, SIGNAL(clicked()), ManualAdjustDate, SLOT(close()));

        QMetaObject::connectSlotsByName(ManualAdjustDate);
    } // setupUi

    void retranslateUi(QDialog *ManualAdjustDate)
    {
        ManualAdjustDate->setWindowTitle(QApplication::translate("ManualAdjustDate", "Dialog", 0, QApplication::UnicodeUTF8));
        lineEdit_ManualR->setText(QString());
        lineEdit_ManualX->setText(QString());
        toolButton->setText(QApplication::translate("ManualAdjustDate", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("ManualAdjustDate", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("ManualAdjustDate", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("ManualAdjustDate", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        lineEdit_ManualY->setText(QString());
        label_37->setText(QApplication::translate("ManualAdjustDate", "R\350\275\264", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("ManualAdjustDate", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("ManualAdjustDate", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManualAdjustDate: public Ui_ManualAdjustDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALADJUSTDATE_H
