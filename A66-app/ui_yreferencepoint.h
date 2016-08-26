/********************************************************************************
** Form generated from reading UI file 'yreferencepoint.ui'
**
** Created: Fri Aug 26 15:10:23 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YREFERENCEPOINT_H
#define UI_YREFERENCEPOINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_YReferencePoint
{
public:
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *YReferencePoint)
    {
        if (YReferencePoint->objectName().isEmpty())
            YReferencePoint->setObjectName(QString::fromUtf8("YReferencePoint"));
        YReferencePoint->resize(265, 397);
        lineEdit = new QLineEdit(YReferencePoint);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 110, 113, 26));
        buttonBox = new QDialogButtonBox(YReferencePoint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 200, 166, 33));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(YReferencePoint);

        QMetaObject::connectSlotsByName(YReferencePoint);
    } // setupUi

    void retranslateUi(QDialog *YReferencePoint)
    {
        YReferencePoint->setWindowTitle(QApplication::translate("YReferencePoint", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class YReferencePoint: public Ui_YReferencePoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YREFERENCEPOINT_H
