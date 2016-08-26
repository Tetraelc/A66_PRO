/********************************************************************************
** Form generated from reading UI file 'qsoftkeyboard.ui'
**
** Created: Wed Jul 27 15:43:14 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSOFTKEYBOARD_H
#define UI_QSOFTKEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_qSoftKeyboardForm
{
public:

    void setupUi(QDialog *qSoftKeyboardForm)
    {
        if (qSoftKeyboardForm->objectName().isEmpty())
            qSoftKeyboardForm->setObjectName(QString::fromUtf8("qSoftKeyboardForm"));
        qSoftKeyboardForm->resize(400, 300);

        retranslateUi(qSoftKeyboardForm);

        QMetaObject::connectSlotsByName(qSoftKeyboardForm);
    } // setupUi

    void retranslateUi(QDialog *qSoftKeyboardForm)
    {
        qSoftKeyboardForm->setWindowTitle(QApplication::translate("qSoftKeyboardForm", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qSoftKeyboardForm: public Ui_qSoftKeyboardForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSOFTKEYBOARD_H
