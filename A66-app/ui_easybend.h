/********************************************************************************
** Form generated from reading UI file 'easybend.ui'
**
** Created: Sat Aug 27 09:54:53 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYBEND_H
#define UI_EASYBEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyBend
{
public:
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_20;
    QLineEdit *lineEdit_Y;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLineEdit *lineEdit_thickness;
    QLineEdit *lineEdit_material_2;
    QLineEdit *lineEdit_width;
    QLineEdit *lineEdit_X_2;
    QLineEdit *lineEdit_X_correct;
    QLineEdit *lineEdit_Angle_Compensation;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *lineEdit_Angle;
    QWidget *tab_5;
    QWidget *tab_4;
    QLabel *label_22;
    QLineEdit *lineEdit_X;
    QLabel *label_25;
    QLabel *label_21;
    QLineEdit *lineEdit_R;

    void setupUi(QWidget *EasyBend)
    {
        if (EasyBend->objectName().isEmpty())
            EasyBend->setObjectName(QString::fromUtf8("EasyBend"));
        EasyBend->resize(1024, 540);
        EasyBend->setCursor(QCursor(Qt::ArrowCursor));
        label_23 = new QLabel(EasyBend);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 140, 41, 21));
        QFont font;
        font.setPointSize(12);
        label_23->setFont(font);
        label_24 = new QLabel(EasyBend);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(40, 200, 55, 16));
        label_24->setFont(font);
        label_20 = new QLabel(EasyBend);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(40, 79, 50, 16));
        label_20->setFont(font);
        lineEdit_Y = new QLineEdit(EasyBend);
        lineEdit_Y->setObjectName(QString::fromUtf8("lineEdit_Y"));
        lineEdit_Y->setGeometry(QRect(100, 130, 150, 40));
        tabWidget_2 = new QTabWidget(EasyBend);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(310, 10, 681, 521));
        QFont font1;
        font1.setPointSize(15);
        tabWidget_2->setFont(font1);
        tabWidget_2->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget_2->setIconSize(QSize(16, 16));
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(42, 33, 101, 20));
        label_26->setFont(font1);
        label_27 = new QLabel(tab_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(42, 81, 81, 20));
        label_27->setFont(font1);
        label_28 = new QLabel(tab_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(42, 129, 81, 20));
        label_28->setFont(font1);
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(42, 177, 16, 20));
        label_29->setFont(font1);
        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(42, 224, 91, 20));
        label_30->setFont(font1);
        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(42, 272, 81, 20));
        label_31->setFont(font1);
        label_32 = new QLabel(tab_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(42, 320, 181, 20));
        label_32->setFont(font1);
        lineEdit_thickness = new QLineEdit(tab_3);
        lineEdit_thickness->setObjectName(QString::fromUtf8("lineEdit_thickness"));
        lineEdit_thickness->setGeometry(QRect(229, 28, 200, 40));
        lineEdit_material_2 = new QLineEdit(tab_3);
        lineEdit_material_2->setObjectName(QString::fromUtf8("lineEdit_material_2"));
        lineEdit_material_2->setGeometry(QRect(229, 75, 200, 40));
        lineEdit_width = new QLineEdit(tab_3);
        lineEdit_width->setObjectName(QString::fromUtf8("lineEdit_width"));
        lineEdit_width->setGeometry(QRect(229, 122, 200, 40));
        lineEdit_X_2 = new QLineEdit(tab_3);
        lineEdit_X_2->setObjectName(QString::fromUtf8("lineEdit_X_2"));
        lineEdit_X_2->setGeometry(QRect(229, 169, 200, 40));
        lineEdit_X_correct = new QLineEdit(tab_3);
        lineEdit_X_correct->setObjectName(QString::fromUtf8("lineEdit_X_correct"));
        lineEdit_X_correct->setGeometry(QRect(229, 216, 200, 40));
        lineEdit_Angle_Compensation = new QLineEdit(tab_3);
        lineEdit_Angle_Compensation->setObjectName(QString::fromUtf8("lineEdit_Angle_Compensation"));
        lineEdit_Angle_Compensation->setGeometry(QRect(229, 310, 200, 40));
        label_33 = new QLabel(tab_3);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(440, 44, 40, 16));
        label_33->setFont(font1);
        label_34 = new QLabel(tab_3);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(440, 136, 40, 20));
        label_34->setFont(font1);
        label_35 = new QLabel(tab_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(440, 182, 40, 20));
        label_35->setFont(font1);
        label_36 = new QLabel(tab_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(440, 232, 40, 16));
        label_36->setFont(font1);
        lineEdit_Angle = new QLineEdit(tab_3);
        lineEdit_Angle->setObjectName(QString::fromUtf8("lineEdit_Angle"));
        lineEdit_Angle->setGeometry(QRect(229, 263, 200, 40));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        label_22 = new QLabel(EasyBend);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(260, 80, 35, 16));
        label_22->setFont(font);
        lineEdit_X = new QLineEdit(EasyBend);
        lineEdit_X->setObjectName(QString::fromUtf8("lineEdit_X"));
        lineEdit_X->setGeometry(QRect(100, 70, 150, 40));
        label_25 = new QLabel(EasyBend);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(40, 140, 55, 20));
        label_25->setFont(font);
        label_21 = new QLabel(EasyBend);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(260, 200, 31, 21));
        label_21->setFont(font);
        lineEdit_R = new QLineEdit(EasyBend);
        lineEdit_R->setObjectName(QString::fromUtf8("lineEdit_R"));
        lineEdit_R->setGeometry(QRect(100, 190, 150, 40));

        retranslateUi(EasyBend);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EasyBend);
    } // setupUi

    void retranslateUi(QWidget *EasyBend)
    {
        EasyBend->setWindowTitle(QApplication::translate("EasyBend", "Form", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("EasyBend", "R\350\275\264", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("EasyBend", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("EasyBend", "\346\235\277\345\216\232", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("EasyBend", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("EasyBend", "\346\235\277\345\256\275", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("EasyBend", "X", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("EasyBend", "X\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("EasyBend", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("EasyBend", "\350\247\222\345\272\246\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("EasyBend", "\345\237\272\346\234\254\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("EasyBend", "X\350\275\264\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("EasyBend", "\345\217\257\351\200\211\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("EasyBend", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("EasyBend", "mm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EasyBend: public Ui_EasyBend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYBEND_H
