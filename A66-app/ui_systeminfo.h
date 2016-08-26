/********************************************************************************
** Form generated from reading UI file 'systeminfo.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMINFO_H
#define UI_SYSTEMINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemInfo
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *SystemInfo)
    {
        if (SystemInfo->objectName().isEmpty())
            SystemInfo->setObjectName(QString::fromUtf8("SystemInfo"));
        SystemInfo->resize(1024, 540);
        pushButton = new QPushButton(SystemInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 150, 641, 181));

        retranslateUi(SystemInfo);

        QMetaObject::connectSlotsByName(SystemInfo);
    } // setupUi

    void retranslateUi(QWidget *SystemInfo)
    {
        SystemInfo->setWindowTitle(QApplication::translate("SystemInfo", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SystemInfo", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemInfo: public Ui_SystemInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMINFO_H
