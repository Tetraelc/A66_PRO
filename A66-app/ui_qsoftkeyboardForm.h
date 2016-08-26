/********************************************************************************
** Form generated from reading UI file 'qsoftkeyboardForm.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSOFTKEYBOARDFORM_H
#define UI_QSOFTKEYBOARDFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qSoftKeyboardForm
{
public:
    QPushButton *panelButton_9;
    QPushButton *panelButton_1;
    QPushButton *closeButton;
    QPushButton *panelButton_Dec;
    QPushButton *panelButton_5;
    QPushButton *panelButton_0;
    QPushButton *panelButton_3;
    QPushButton *panelButton_2;
    QPushButton *panelButton_4;
    QPushButton *panelButton_6;
    QPushButton *panelButton_star;
    QPushButton *panelButton_7;
    QPushButton *panelButton_8;
    QPushButton *BackButton;

    void setupUi(QWidget *qSoftKeyboardForm)
    {
        if (qSoftKeyboardForm->objectName().isEmpty())
            qSoftKeyboardForm->setObjectName(QString::fromUtf8("qSoftKeyboardForm"));
        qSoftKeyboardForm->resize(199, 167);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(164, 164, 170, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        qSoftKeyboardForm->setPalette(palette);
        panelButton_9 = new QPushButton(qSoftKeyboardForm);
        panelButton_9->setObjectName(QString::fromUtf8("panelButton_9"));
        panelButton_9->setGeometry(QRect(101, 84, 45, 40));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(panelButton_9->sizePolicy().hasHeightForWidth());
        panelButton_9->setSizePolicy(sizePolicy);
        panelButton_9->setMinimumSize(QSize(45, 40));
        QFont font;
        font.setPointSize(11);
        panelButton_9->setFont(font);
        panelButton_9->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_9->setFocusPolicy(Qt::NoFocus);
        panelButton_9->setProperty("buttonValue", QVariant(QChar(57)));
        panelButton_1 = new QPushButton(qSoftKeyboardForm);
        panelButton_1->setObjectName(QString::fromUtf8("panelButton_1"));
        panelButton_1->setGeometry(QRect(5, 4, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_1->sizePolicy().hasHeightForWidth());
        panelButton_1->setSizePolicy(sizePolicy);
        panelButton_1->setMinimumSize(QSize(45, 40));
        panelButton_1->setFont(font);
        panelButton_1->setCursor(QCursor(Qt::BlankCursor));
        panelButton_1->setFocusPolicy(Qt::NoFocus);
        panelButton_1->setProperty("buttonValue", QVariant(QChar(49)));
        closeButton = new QPushButton(qSoftKeyboardForm);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(149, 44, 45, 121));
        closeButton->setFont(font);
        closeButton->setCursor(QCursor(Qt::BlankCursor));
        closeButton->setFocusPolicy(Qt::NoFocus);
        panelButton_Dec = new QPushButton(qSoftKeyboardForm);
        panelButton_Dec->setObjectName(QString::fromUtf8("panelButton_Dec"));
        panelButton_Dec->setGeometry(QRect(101, 124, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_Dec->sizePolicy().hasHeightForWidth());
        panelButton_Dec->setSizePolicy(sizePolicy);
        panelButton_Dec->setMinimumSize(QSize(45, 40));
        panelButton_Dec->setFont(font);
        panelButton_Dec->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_Dec->setFocusPolicy(Qt::NoFocus);
        panelButton_Dec->setProperty("buttonValue", QVariant(QChar(45)));
        panelButton_5 = new QPushButton(qSoftKeyboardForm);
        panelButton_5->setObjectName(QString::fromUtf8("panelButton_5"));
        panelButton_5->setGeometry(QRect(53, 44, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_5->sizePolicy().hasHeightForWidth());
        panelButton_5->setSizePolicy(sizePolicy);
        panelButton_5->setMinimumSize(QSize(45, 40));
        panelButton_5->setFont(font);
        panelButton_5->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_5->setFocusPolicy(Qt::NoFocus);
        panelButton_5->setProperty("buttonValue", QVariant(QChar(53)));
        panelButton_0 = new QPushButton(qSoftKeyboardForm);
        panelButton_0->setObjectName(QString::fromUtf8("panelButton_0"));
        panelButton_0->setGeometry(QRect(53, 124, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_0->sizePolicy().hasHeightForWidth());
        panelButton_0->setSizePolicy(sizePolicy);
        panelButton_0->setMinimumSize(QSize(45, 40));
        panelButton_0->setFont(font);
        panelButton_0->setCursor(QCursor(Qt::BlankCursor));
        panelButton_0->setFocusPolicy(Qt::NoFocus);
        panelButton_0->setProperty("buttonValue", QVariant(QChar(48)));
        panelButton_3 = new QPushButton(qSoftKeyboardForm);
        panelButton_3->setObjectName(QString::fromUtf8("panelButton_3"));
        panelButton_3->setGeometry(QRect(101, 4, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_3->sizePolicy().hasHeightForWidth());
        panelButton_3->setSizePolicy(sizePolicy);
        panelButton_3->setMinimumSize(QSize(45, 40));
        panelButton_3->setFont(font);
        panelButton_3->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_3->setFocusPolicy(Qt::NoFocus);
        panelButton_3->setProperty("buttonValue", QVariant(QChar(51)));
        panelButton_2 = new QPushButton(qSoftKeyboardForm);
        panelButton_2->setObjectName(QString::fromUtf8("panelButton_2"));
        panelButton_2->setGeometry(QRect(53, 4, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_2->sizePolicy().hasHeightForWidth());
        panelButton_2->setSizePolicy(sizePolicy);
        panelButton_2->setMinimumSize(QSize(45, 40));
        panelButton_2->setFont(font);
        panelButton_2->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_2->setFocusPolicy(Qt::NoFocus);
        panelButton_2->setProperty("buttonValue", QVariant(QChar(50)));
        panelButton_4 = new QPushButton(qSoftKeyboardForm);
        panelButton_4->setObjectName(QString::fromUtf8("panelButton_4"));
        panelButton_4->setGeometry(QRect(5, 44, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_4->sizePolicy().hasHeightForWidth());
        panelButton_4->setSizePolicy(sizePolicy);
        panelButton_4->setMinimumSize(QSize(45, 40));
        panelButton_4->setFont(font);
        panelButton_4->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_4->setFocusPolicy(Qt::NoFocus);
        panelButton_4->setProperty("buttonValue", QVariant(QChar(52)));
        panelButton_6 = new QPushButton(qSoftKeyboardForm);
        panelButton_6->setObjectName(QString::fromUtf8("panelButton_6"));
        panelButton_6->setGeometry(QRect(101, 44, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_6->sizePolicy().hasHeightForWidth());
        panelButton_6->setSizePolicy(sizePolicy);
        panelButton_6->setMinimumSize(QSize(45, 40));
        panelButton_6->setFont(font);
        panelButton_6->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_6->setFocusPolicy(Qt::NoFocus);
        panelButton_6->setProperty("buttonValue", QVariant(QChar(54)));
        panelButton_star = new QPushButton(qSoftKeyboardForm);
        panelButton_star->setObjectName(QString::fromUtf8("panelButton_star"));
        panelButton_star->setGeometry(QRect(5, 124, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_star->sizePolicy().hasHeightForWidth());
        panelButton_star->setSizePolicy(sizePolicy);
        panelButton_star->setMinimumSize(QSize(45, 40));
        panelButton_star->setFont(font);
        panelButton_star->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_star->setFocusPolicy(Qt::NoFocus);
        panelButton_star->setProperty("buttonValue", QVariant(QChar(46)));
        panelButton_7 = new QPushButton(qSoftKeyboardForm);
        panelButton_7->setObjectName(QString::fromUtf8("panelButton_7"));
        panelButton_7->setGeometry(QRect(5, 84, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_7->sizePolicy().hasHeightForWidth());
        panelButton_7->setSizePolicy(sizePolicy);
        panelButton_7->setMinimumSize(QSize(45, 40));
        panelButton_7->setFont(font);
        panelButton_7->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_7->setFocusPolicy(Qt::NoFocus);
        panelButton_7->setProperty("buttonValue", QVariant(QChar(55)));
        panelButton_8 = new QPushButton(qSoftKeyboardForm);
        panelButton_8->setObjectName(QString::fromUtf8("panelButton_8"));
        panelButton_8->setGeometry(QRect(53, 84, 45, 40));
        sizePolicy.setHeightForWidth(panelButton_8->sizePolicy().hasHeightForWidth());
        panelButton_8->setSizePolicy(sizePolicy);
        panelButton_8->setMinimumSize(QSize(45, 40));
        panelButton_8->setFont(font);
        panelButton_8->setCursor(QCursor(Qt::ArrowCursor));
        panelButton_8->setFocusPolicy(Qt::NoFocus);
        panelButton_8->setProperty("buttonValue", QVariant(QChar(56)));
        BackButton = new QPushButton(qSoftKeyboardForm);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setGeometry(QRect(149, 4, 45, 41));
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);
        BackButton->setMinimumSize(QSize(45, 40));
        BackButton->setFont(font);
        BackButton->setCursor(QCursor(Qt::BlankCursor));
        BackButton->setFocusPolicy(Qt::NoFocus);
        BackButton->setProperty("buttonValue", QVariant(QChar(0)));

        retranslateUi(qSoftKeyboardForm);

        QMetaObject::connectSlotsByName(qSoftKeyboardForm);
    } // setupUi

    void retranslateUi(QWidget *qSoftKeyboardForm)
    {
        qSoftKeyboardForm->setWindowTitle(QApplication::translate("qSoftKeyboardForm", "Form", 0, QApplication::UnicodeUTF8));
        panelButton_9->setText(QApplication::translate("qSoftKeyboardForm", "9", 0, QApplication::UnicodeUTF8));
        panelButton_1->setText(QApplication::translate("qSoftKeyboardForm", "1", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("qSoftKeyboardForm", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        panelButton_Dec->setText(QApplication::translate("qSoftKeyboardForm", "-/+", 0, QApplication::UnicodeUTF8));
        panelButton_5->setText(QApplication::translate("qSoftKeyboardForm", "5", 0, QApplication::UnicodeUTF8));
        panelButton_0->setText(QApplication::translate("qSoftKeyboardForm", "0", 0, QApplication::UnicodeUTF8));
        panelButton_3->setText(QApplication::translate("qSoftKeyboardForm", "3", 0, QApplication::UnicodeUTF8));
        panelButton_2->setText(QApplication::translate("qSoftKeyboardForm", "2", 0, QApplication::UnicodeUTF8));
        panelButton_4->setText(QApplication::translate("qSoftKeyboardForm", "4", 0, QApplication::UnicodeUTF8));
        panelButton_6->setText(QApplication::translate("qSoftKeyboardForm", "6", 0, QApplication::UnicodeUTF8));
        panelButton_star->setText(QApplication::translate("qSoftKeyboardForm", ".", 0, QApplication::UnicodeUTF8));
        panelButton_7->setText(QApplication::translate("qSoftKeyboardForm", "7", 0, QApplication::UnicodeUTF8));
        panelButton_8->setText(QApplication::translate("qSoftKeyboardForm", "8", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("qSoftKeyboardForm", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qSoftKeyboardForm: public Ui_qSoftKeyboardForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSOFTKEYBOARDFORM_H
