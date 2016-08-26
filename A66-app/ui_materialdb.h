/********************************************************************************
** Form generated from reading UI file 'materialdb.ui'
**
** Created: Mon Aug 22 19:46:51 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALDB_H
#define UI_MATERIALDB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Materialdb
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Materialdb)
    {
        if (Materialdb->objectName().isEmpty())
            Materialdb->setObjectName(QString::fromUtf8("Materialdb"));
        Materialdb->resize(841, 407);
        buttonBox = new QDialogButtonBox(Materialdb);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 330, 166, 33));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Materialdb);

        QMetaObject::connectSlotsByName(Materialdb);
    } // setupUi

    void retranslateUi(QDialog *Materialdb)
    {
        Materialdb->setWindowTitle(QApplication::translate("Materialdb", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Materialdb: public Ui_Materialdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALDB_H
