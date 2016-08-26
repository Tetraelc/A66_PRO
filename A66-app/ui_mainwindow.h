/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Aug 26 14:07:59 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_Ptitile;
    QLabel *label;
    QToolButton *toolButton_T1;
    QToolButton *toolButton_State;
    QToolButton *toolButton_ProName;
    QFrame *frame;
    QToolButton *toolButton_B0;
    QToolButton *toolButton_B1;
    QToolButton *toolButton_B3;
    QToolButton *toolButton_B4;
    QToolButton *toolButton_B5;
    QToolButton *toolButton_B2;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_Start;
    QToolButton *toolButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_Ptitile = new QFrame(centralWidget);
        frame_Ptitile->setObjectName(QString::fromUtf8("frame_Ptitile"));
        frame_Ptitile->setGeometry(QRect(0, 0, 1031, 91));
        frame_Ptitile->setFrameShape(QFrame::StyledPanel);
        frame_Ptitile->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_Ptitile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(876, 16, 141, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/LOGO.png")));
        label->setScaledContents(false);
        toolButton_T1 = new QToolButton(frame_Ptitile);
        toolButton_T1->setObjectName(QString::fromUtf8("toolButton_T1"));
        toolButton_T1->setGeometry(QRect(36, 5, 191, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(18);
        toolButton_T1->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ICO/P1-PROG.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_T1->setIcon(icon);
        toolButton_T1->setIconSize(QSize(64, 64));
        toolButton_T1->setPopupMode(QToolButton::DelayedPopup);
        toolButton_T1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_T1->setAutoRaise(true);
        toolButton_T1->setArrowType(Qt::NoArrow);
        toolButton_State = new QToolButton(frame_Ptitile);
        toolButton_State->setObjectName(QString::fromUtf8("toolButton_State"));
        toolButton_State->setGeometry(QRect(280, 10, 441, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setPointSize(14);
        toolButton_State->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/ICO/P1-MSG.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_State->setIcon(icon1);
        toolButton_State->setIconSize(QSize(40, 40));
        toolButton_State->setPopupMode(QToolButton::InstantPopup);
        toolButton_State->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_State->setAutoRaise(true);
        toolButton_ProName = new QToolButton(frame_Ptitile);
        toolButton_ProName->setObjectName(QString::fromUtf8("toolButton_ProName"));
        toolButton_ProName->setGeometry(QRect(870, 52, 131, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif"));
        font3.setPointSize(10);
        toolButton_ProName->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ICO/P1-VER.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_ProName->setIcon(icon2);
        toolButton_ProName->setIconSize(QSize(30, 30));
        toolButton_ProName->setPopupMode(QToolButton::DelayedPopup);
        toolButton_ProName->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_ProName->setAutoRaise(true);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 660, 1031, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolButton_B0 = new QToolButton(frame);
        toolButton_B0->setObjectName(QString::fromUtf8("toolButton_B0"));
        toolButton_B0->setGeometry(QRect(20, 10, 80, 80));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        toolButton_B0->setFont(font4);
        toolButton_B0->setIcon(icon);
        toolButton_B0->setIconSize(QSize(52, 52));
        toolButton_B0->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_B1 = new QToolButton(frame);
        toolButton_B1->setObjectName(QString::fromUtf8("toolButton_B1"));
        toolButton_B1->setGeometry(QRect(120, 10, 80, 80));
        toolButton_B1->setFont(font4);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/ICO/P1-EDIT.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_B1->setIcon(icon3);
        toolButton_B1->setIconSize(QSize(52, 52));
        toolButton_B1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_B3 = new QToolButton(frame);
        toolButton_B3->setObjectName(QString::fromUtf8("toolButton_B3"));
        toolButton_B3->setGeometry(QRect(620, 10, 80, 80));
        toolButton_B3->setFont(font4);
        toolButton_B3->setCursor(QCursor(Qt::BlankCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/ICO/P1-MANU.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_B3->setIcon(icon4);
        toolButton_B3->setIconSize(QSize(52, 52));
        toolButton_B3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_B4 = new QToolButton(frame);
        toolButton_B4->setObjectName(QString::fromUtf8("toolButton_B4"));
        toolButton_B4->setGeometry(QRect(420, 10, 80, 80));
        toolButton_B4->setFont(font4);
        toolButton_B4->setIconSize(QSize(48, 48));
        toolButton_B4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_B5 = new QToolButton(frame);
        toolButton_B5->setObjectName(QString::fromUtf8("toolButton_B5"));
        toolButton_B5->setGeometry(QRect(820, 10, 80, 80));
        toolButton_B5->setFont(font4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ico/ICO/P1-SET.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_B5->setIcon(icon5);
        toolButton_B5->setIconSize(QSize(52, 52));
        toolButton_B5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_B2 = new QToolButton(frame);
        toolButton_B2->setObjectName(QString::fromUtf8("toolButton_B2"));
        toolButton_B2->setGeometry(QRect(720, 10, 80, 80));
        toolButton_B2->setFont(font4);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ico/ICO/P1-MOLD.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_B2->setIcon(icon6);
        toolButton_B2->setIconSize(QSize(52, 52));
        toolButton_B2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(320, 10, 80, 80));
        toolButton_2->setIconSize(QSize(52, 52));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(520, 10, 80, 80));
        toolButton_Start = new QToolButton(frame);
        toolButton_Start->setObjectName(QString::fromUtf8("toolButton_Start"));
        toolButton_Start->setGeometry(QRect(220, 10, 80, 80));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ico/ICO/P1-START.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Start->setIcon(icon7);
        toolButton_Start->setIconSize(QSize(52, 52));
        toolButton_Start->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(930, 10, 80, 80));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ico/ICO/P1-HELP.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon8);
        toolButton_4->setIconSize(QSize(52, 52));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        toolButton_T1->setText(QApplication::translate("MainWindow", " \347\250\213\345\272\217\345\272\223", 0, QApplication::UnicodeUTF8));
        toolButton_State->setText(QApplication::translate("MainWindow", " \345\207\206\345\244\207\345\260\261\347\273\252!", 0, QApplication::UnicodeUTF8));
        toolButton_ProName->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217: P01", 0, QApplication::UnicodeUTF8));
        toolButton_B0->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\345\272\223", 0, QApplication::UnicodeUTF8));
        toolButton_B1->setText(QApplication::translate("MainWindow", "\345\267\245\346\255\245\347\274\226\347\250\213", 0, QApplication::UnicodeUTF8));
        toolButton_B3->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250", 0, QApplication::UnicodeUTF8));
        toolButton_B4->setText(QString());
        toolButton_B5->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        toolButton_B2->setText(QApplication::translate("MainWindow", "\346\250\241\345\205\267\345\272\223", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QString());
        toolButton->setText(QString());
        toolButton_Start->setText(QApplication::translate("MainWindow", "RUN", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
