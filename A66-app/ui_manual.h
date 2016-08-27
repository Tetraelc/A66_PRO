/********************************************************************************
** Form generated from reading UI file 'manual.ui'
**
** Created: Sat Aug 27 09:54:53 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_H
#define UI_MANUAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manual
{
public:
    QPushButton *pushButton_B6_4;
    QPushButton *pushButton_B6_7;
    QPushButton *pushButton_Adjust;
    QPushButton *pushButton_B6_3;
    QPushButton *pushButton_B6_6;
    QFrame *frame;
    QPushButton *pushButton_M_XForWard;
    QPushButton *pushButton_M_YBack;
    QToolButton *toolButton_R;
    QPushButton *pushButton_M_RForWard;
    QToolButton *toolButton_X;
    QToolButton *toolButton_Y;
    QPushButton *pushButton_M_RBack;
    QPushButton *pushButton_M_XBack;
    QLineEdit *lineEdit_ManualR;
    QPushButton *pushButton_M_YForWard;
    QLabel *label_Y;
    QLabel *label_X;
    QLineEdit *lineEdit_ManualX;
    QLineEdit *lineEdit_ManualY;
    QFrame *frame_State;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_IN4;
    QLabel *label_IN7;
    QLabel *label_23;
    QLabel *label_IN6;
    QLabel *label_IN1;
    QLabel *label_26;
    QLabel *label_IN2;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_IN8;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_IN5;
    QLabel *label_35;
    QLabel *label_IN3;
    QLabel *label_37;
    QLineEdit *lineEdit_RunState;

    void setupUi(QWidget *Manual)
    {
        if (Manual->objectName().isEmpty())
            Manual->setObjectName(QString::fromUtf8("Manual"));
        Manual->resize(1024, 540);
        Manual->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_B6_4 = new QPushButton(Manual);
        pushButton_B6_4->setObjectName(QString::fromUtf8("pushButton_B6_4"));
        pushButton_B6_4->setGeometry(QRect(910, 210, 80, 80));
        pushButton_B6_7 = new QPushButton(Manual);
        pushButton_B6_7->setObjectName(QString::fromUtf8("pushButton_B6_7"));
        pushButton_B6_7->setGeometry(QRect(910, 390, 80, 80));
        pushButton_Adjust = new QPushButton(Manual);
        pushButton_Adjust->setObjectName(QString::fromUtf8("pushButton_Adjust"));
        pushButton_Adjust->setGeometry(QRect(910, 30, 80, 80));
        pushButton_B6_3 = new QPushButton(Manual);
        pushButton_B6_3->setObjectName(QString::fromUtf8("pushButton_B6_3"));
        pushButton_B6_3->setGeometry(QRect(910, 120, 80, 80));
        pushButton_B6_6 = new QPushButton(Manual);
        pushButton_B6_6->setObjectName(QString::fromUtf8("pushButton_B6_6"));
        pushButton_B6_6->setGeometry(QRect(910, 300, 80, 80));
        frame = new QFrame(Manual);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(50, 30, 821, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_M_XForWard = new QPushButton(frame);
        pushButton_M_XForWard->setObjectName(QString::fromUtf8("pushButton_M_XForWard"));
        pushButton_M_XForWard->setGeometry(QRect(590, 40, 91, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ICO/P1-ADD.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_M_XForWard->setIcon(icon);
        pushButton_M_XForWard->setIconSize(QSize(56, 56));
        pushButton_M_YBack = new QPushButton(frame);
        pushButton_M_YBack->setObjectName(QString::fromUtf8("pushButton_M_YBack"));
        pushButton_M_YBack->setGeometry(QRect(130, 150, 91, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/ICO/P1-DEC.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_M_YBack->setIcon(icon1);
        pushButton_M_YBack->setIconSize(QSize(56, 56));
        toolButton_R = new QToolButton(frame);
        toolButton_R->setObjectName(QString::fromUtf8("toolButton_R"));
        toolButton_R->setGeometry(QRect(250, 270, 101, 41));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        toolButton_R->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ICO/P1-START.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_R->setIcon(icon2);
        toolButton_R->setIconSize(QSize(30, 30));
        toolButton_R->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_R->setAutoRaise(true);
        pushButton_M_RForWard = new QPushButton(frame);
        pushButton_M_RForWard->setObjectName(QString::fromUtf8("pushButton_M_RForWard"));
        pushButton_M_RForWard->setGeometry(QRect(590, 260, 91, 61));
        pushButton_M_RForWard->setIcon(icon);
        pushButton_M_RForWard->setIconSize(QSize(56, 56));
        toolButton_X = new QToolButton(frame);
        toolButton_X->setObjectName(QString::fromUtf8("toolButton_X"));
        toolButton_X->setGeometry(QRect(250, 50, 101, 41));
        toolButton_X->setFont(font);
        toolButton_X->setIcon(icon2);
        toolButton_X->setIconSize(QSize(30, 30));
        toolButton_X->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_X->setAutoRaise(true);
        toolButton_Y = new QToolButton(frame);
        toolButton_Y->setObjectName(QString::fromUtf8("toolButton_Y"));
        toolButton_Y->setGeometry(QRect(250, 160, 101, 41));
        toolButton_Y->setFont(font);
        toolButton_Y->setIcon(icon2);
        toolButton_Y->setIconSize(QSize(30, 30));
        toolButton_Y->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_Y->setAutoRaise(true);
        pushButton_M_RBack = new QPushButton(frame);
        pushButton_M_RBack->setObjectName(QString::fromUtf8("pushButton_M_RBack"));
        pushButton_M_RBack->setGeometry(QRect(130, 260, 91, 61));
        pushButton_M_RBack->setIcon(icon1);
        pushButton_M_RBack->setIconSize(QSize(56, 56));
        pushButton_M_XBack = new QPushButton(frame);
        pushButton_M_XBack->setObjectName(QString::fromUtf8("pushButton_M_XBack"));
        pushButton_M_XBack->setGeometry(QRect(130, 40, 91, 61));
        pushButton_M_XBack->setIcon(icon1);
        pushButton_M_XBack->setIconSize(QSize(56, 56));
        lineEdit_ManualR = new QLineEdit(frame);
        lineEdit_ManualR->setObjectName(QString::fromUtf8("lineEdit_ManualR"));
        lineEdit_ManualR->setGeometry(QRect(351, 260, 191, 61));
        QFont font1;
        font1.setPointSize(18);
        lineEdit_ManualR->setFont(font1);
        lineEdit_ManualR->setDragEnabled(false);
        lineEdit_ManualR->setReadOnly(true);
        lineEdit_ManualR->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pushButton_M_YForWard = new QPushButton(frame);
        pushButton_M_YForWard->setObjectName(QString::fromUtf8("pushButton_M_YForWard"));
        pushButton_M_YForWard->setGeometry(QRect(590, 150, 91, 61));
        pushButton_M_YForWard->setIcon(icon);
        pushButton_M_YForWard->setIconSize(QSize(56, 56));
        label_Y = new QLabel(frame);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        label_Y->setGeometry(QRect(60, 170, 51, 31));
        label_X = new QLabel(frame);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        label_X->setGeometry(QRect(60, 60, 51, 30));
        lineEdit_ManualX = new QLineEdit(frame);
        lineEdit_ManualX->setObjectName(QString::fromUtf8("lineEdit_ManualX"));
        lineEdit_ManualX->setGeometry(QRect(353, 44, 191, 61));
        lineEdit_ManualX->setFont(font1);
        lineEdit_ManualX->setDragEnabled(false);
        lineEdit_ManualX->setReadOnly(true);
        lineEdit_ManualX->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_ManualY = new QLineEdit(frame);
        lineEdit_ManualY->setObjectName(QString::fromUtf8("lineEdit_ManualY"));
        lineEdit_ManualY->setGeometry(QRect(351, 152, 191, 61));
        lineEdit_ManualY->setFont(font1);
        lineEdit_ManualY->setDragEnabled(false);
        lineEdit_ManualY->setReadOnly(true);
        lineEdit_ManualY->setCursorMoveStyle(Qt::LogicalMoveStyle);
        frame_State = new QFrame(Manual);
        frame_State->setObjectName(QString::fromUtf8("frame_State"));
        frame_State->setGeometry(QRect(50, 400, 821, 121));
        frame_State->setFrameShape(QFrame::StyledPanel);
        frame_State->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame_State);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 101, 21));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label_2 = new QLabel(frame_State);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 50, 101, 21));
        label_2->setFont(font2);
        label_3 = new QLabel(frame_State);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 80, 101, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(frame_State);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 80, 21, 21));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_4->setScaledContents(true);
        label_6 = new QLabel(frame_State);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 80, 21, 21));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(frame_State);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 80, 21, 21));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(frame_State);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 80, 21, 21));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(frame_State);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 80, 21, 21));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_9->setScaledContents(true);
        label_10 = new QLabel(frame_State);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(290, 80, 21, 21));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(frame_State);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(320, 80, 21, 21));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frame_State);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(350, 80, 21, 21));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_12->setScaledContents(true);
        label_13 = new QLabel(frame_State);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(620, 80, 21, 21));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(frame_State);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(530, 80, 21, 21));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_14->setScaledContents(true);
        label_15 = new QLabel(frame_State);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(590, 80, 21, 21));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_15->setScaledContents(true);
        label_16 = new QLabel(frame_State);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(440, 80, 21, 21));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_16->setScaledContents(true);
        label_17 = new QLabel(frame_State);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(470, 80, 21, 21));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_17->setScaledContents(true);
        label_18 = new QLabel(frame_State);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(650, 80, 21, 21));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_18->setScaledContents(true);
        label_19 = new QLabel(frame_State);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(560, 80, 21, 21));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_19->setScaledContents(true);
        label_20 = new QLabel(frame_State);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(500, 80, 21, 21));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_20->setScaledContents(true);
        label_IN4 = new QLabel(frame_State);
        label_IN4->setObjectName(QString::fromUtf8("label_IN4"));
        label_IN4->setGeometry(QRect(260, 50, 21, 21));
        label_IN4->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN4->setScaledContents(true);
        label_IN7 = new QLabel(frame_State);
        label_IN7->setObjectName(QString::fromUtf8("label_IN7"));
        label_IN7->setGeometry(QRect(350, 50, 21, 21));
        label_IN7->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN7->setScaledContents(true);
        label_23 = new QLabel(frame_State);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(440, 50, 21, 21));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_23->setScaledContents(true);
        label_IN6 = new QLabel(frame_State);
        label_IN6->setObjectName(QString::fromUtf8("label_IN6"));
        label_IN6->setGeometry(QRect(320, 50, 21, 21));
        label_IN6->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN6->setScaledContents(true);
        label_IN1 = new QLabel(frame_State);
        label_IN1->setObjectName(QString::fromUtf8("label_IN1"));
        label_IN1->setGeometry(QRect(170, 50, 21, 21));
        label_IN1->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN1->setScaledContents(true);
        label_26 = new QLabel(frame_State);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(560, 50, 21, 21));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_26->setScaledContents(true);
        label_IN2 = new QLabel(frame_State);
        label_IN2->setObjectName(QString::fromUtf8("label_IN2"));
        label_IN2->setGeometry(QRect(200, 50, 21, 21));
        label_IN2->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN2->setScaledContents(true);
        label_28 = new QLabel(frame_State);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(470, 50, 21, 21));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_28->setScaledContents(true);
        label_29 = new QLabel(frame_State);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(590, 50, 21, 21));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_29->setScaledContents(true);
        label_30 = new QLabel(frame_State);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(620, 50, 21, 21));
        label_30->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_30->setScaledContents(true);
        label_IN8 = new QLabel(frame_State);
        label_IN8->setObjectName(QString::fromUtf8("label_IN8"));
        label_IN8->setGeometry(QRect(380, 50, 21, 21));
        label_IN8->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN8->setScaledContents(true);
        label_32 = new QLabel(frame_State);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(500, 50, 21, 21));
        label_32->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_32->setScaledContents(true);
        label_33 = new QLabel(frame_State);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(650, 50, 21, 21));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_33->setScaledContents(true);
        label_IN5 = new QLabel(frame_State);
        label_IN5->setObjectName(QString::fromUtf8("label_IN5"));
        label_IN5->setGeometry(QRect(290, 50, 21, 21));
        label_IN5->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN5->setScaledContents(true);
        label_35 = new QLabel(frame_State);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(530, 50, 21, 21));
        label_35->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_35->setScaledContents(true);
        label_IN3 = new QLabel(frame_State);
        label_IN3->setObjectName(QString::fromUtf8("label_IN3"));
        label_IN3->setGeometry(QRect(230, 50, 21, 21));
        label_IN3->setPixmap(QPixmap(QString::fromUtf8(":/ico/ICO/P1-LAMP.png")));
        label_IN3->setScaledContents(true);
        label_37 = new QLabel(frame_State);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(170, 20, 231, 21));
        label_37->setFont(font2);
        lineEdit_RunState = new QLineEdit(frame_State);
        lineEdit_RunState->setObjectName(QString::fromUtf8("lineEdit_RunState"));
        lineEdit_RunState->setGeometry(QRect(440, 16, 181, 31));
        lineEdit_RunState->setReadOnly(true);

        retranslateUi(Manual);

        QMetaObject::connectSlotsByName(Manual);
    } // setupUi

    void retranslateUi(QWidget *Manual)
    {
        Manual->setWindowTitle(QApplication::translate("Manual", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_B6_4->setText(QString());
        pushButton_B6_7->setText(QApplication::translate("Manual", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_Adjust->setText(QApplication::translate("Manual", "\345\257\271\346\225\260", 0, QApplication::UnicodeUTF8));
        pushButton_B6_3->setText(QApplication::translate("Manual", "\345\237\272\345\207\206\347\202\271", 0, QApplication::UnicodeUTF8));
        pushButton_B6_6->setText(QString());
        pushButton_M_XForWard->setText(QString());
        pushButton_M_YBack->setText(QString());
        toolButton_R->setText(QApplication::translate("Manual", " R", 0, QApplication::UnicodeUTF8));
        pushButton_M_RForWard->setText(QString());
        toolButton_X->setText(QApplication::translate("Manual", " X", 0, QApplication::UnicodeUTF8));
        toolButton_Y->setText(QApplication::translate("Manual", " Y", 0, QApplication::UnicodeUTF8));
        pushButton_M_RBack->setText(QString());
        pushButton_M_XBack->setText(QString());
        lineEdit_ManualR->setText(QString());
        pushButton_M_YForWard->setText(QString());
        label_Y->setText(QString());
        label_X->setText(QString());
        lineEdit_ManualX->setText(QString());
        lineEdit_ManualY->setText(QString());
        label->setText(QApplication::translate("Manual", "\346\266\262\345\216\213\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Manual", "\350\276\223\345\205\245\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Manual", "\350\276\223\345\207\272\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
        label_IN4->setText(QString());
        label_IN7->setText(QString());
        label_23->setText(QString());
        label_IN6->setText(QString());
        label_IN1->setText(QString());
        label_26->setText(QString());
        label_IN2->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_IN8->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        label_IN5->setText(QString());
        label_35->setText(QString());
        label_IN3->setText(QString());
        label_37->setText(QApplication::translate("Manual", "\345\201\234\346\255\242/\345\277\253\344\270\213/\346\205\242\344\270\213/\345\267\245\350\277\233/\345\233\236\347\250\213", 0, QApplication::UnicodeUTF8));
        lineEdit_RunState->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Manual: public Ui_Manual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_H
