/********************************************************************************
** Form generated from reading UI file 'wrokedtotal.ui'
**
** Created: Sat Aug 27 09:54:53 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WROKEDTOTAL_H
#define UI_WROKEDTOTAL_H

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

class Ui_WrokedTotal
{
public:
    QLineEdit *lineEdit_workedTotal;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QDialog *WrokedTotal)
    {
        if (WrokedTotal->objectName().isEmpty())
            WrokedTotal->setObjectName(QString::fromUtf8("WrokedTotal"));
        WrokedTotal->resize(379, 222);
        lineEdit_workedTotal = new QLineEdit(WrokedTotal);
        lineEdit_workedTotal->setObjectName(QString::fromUtf8("lineEdit_workedTotal"));
        lineEdit_workedTotal->setGeometry(QRect(70, 100, 113, 26));
        label = new QLabel(WrokedTotal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 261, 31));
        toolButton = new QToolButton(WrokedTotal);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(230, 100, 81, 31));

        retranslateUi(WrokedTotal);

        QMetaObject::connectSlotsByName(WrokedTotal);
    } // setupUi

    void retranslateUi(QDialog *WrokedTotal)
    {
        WrokedTotal->setWindowTitle(QApplication::translate("WrokedTotal", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WrokedTotal", "\350\257\267\350\276\223\345\205\245\345\212\240\345\267\245\346\225\260", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("WrokedTotal", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WrokedTotal: public Ui_WrokedTotal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WROKEDTOTAL_H
