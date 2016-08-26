/********************************************************************************
** Form generated from reading UI file 'systemwarn.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMWARN_H
#define UI_SYSTEMWARN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SystemWarn
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_DisplayAlarm;

    void setupUi(QDialog *SystemWarn)
    {
        if (SystemWarn->objectName().isEmpty())
            SystemWarn->setObjectName(QString::fromUtf8("SystemWarn"));
        SystemWarn->resize(400, 300);
        buttonBox = new QDialogButtonBox(SystemWarn);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 230, 166, 33));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_DisplayAlarm = new QLabel(SystemWarn);
        label_DisplayAlarm->setObjectName(QString::fromUtf8("label_DisplayAlarm"));
        label_DisplayAlarm->setGeometry(QRect(90, 80, 211, 41));
        label_DisplayAlarm->setAlignment(Qt::AlignCenter);

        retranslateUi(SystemWarn);
        QObject::connect(buttonBox, SIGNAL(rejected()), SystemWarn, SLOT(close()));

        QMetaObject::connectSlotsByName(SystemWarn);
    } // setupUi

    void retranslateUi(QDialog *SystemWarn)
    {
        SystemWarn->setWindowTitle(QApplication::translate("SystemWarn", "Dialog", 0, QApplication::UnicodeUTF8));
        label_DisplayAlarm->setText(QApplication::translate("SystemWarn", "\346\212\245\350\255\246\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemWarn: public Ui_SystemWarn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMWARN_H
