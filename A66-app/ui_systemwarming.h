/********************************************************************************
** Form generated from reading UI file 'systemwarming.ui'
**
** Created: Fri Aug 26 10:06:59 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMWARMING_H
#define UI_SYSTEMWARMING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SystemWarming
{
public:
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SystemWarming)
    {
        if (SystemWarming->objectName().isEmpty())
            SystemWarming->setObjectName(QString::fromUtf8("SystemWarming"));
        SystemWarming->resize(400, 300);
        label = new QLabel(SystemWarming);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 261, 101));
        label->setAlignment(Qt::AlignCenter);
        buttonBox = new QDialogButtonBox(SystemWarming);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 220, 166, 33));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(SystemWarming);

        QMetaObject::connectSlotsByName(SystemWarming);
    } // setupUi

    void retranslateUi(QDialog *SystemWarming)
    {
        SystemWarming->setWindowTitle(QApplication::translate("SystemWarming", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SystemWarming", "\346\212\245\350\255\246\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SystemWarming: public Ui_SystemWarming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMWARMING_H
