/********************************************************************************
** Form generated from reading UI file 'runstate.ui'
**
** Created: Fri Aug 26 14:08:00 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNSTATE_H
#define UI_RUNSTATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunState
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_Run;
    QToolButton *pushButton_Left_1;
    QToolButton *pushButton_Left_2;
    QToolButton *pushButton_Left_4;
    QWidget *tab_2;
    QLabel *label_pic;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QToolButton *toolButton;
    QLineEdit *lineEdit_RCurrentPos;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QLineEdit *lineEdit_XCurrentPos;
    QLineEdit *lineEdit_YCurrentPos;
    QFrame *line;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *pushButton_Left_5;
    QLabel *label_ProgramName;
    QLabel *label_CurrentStep;
    QLabel *label_WorkedTotal;
    QLabel *label_Pressure;
    QLabel *label_Run;
    QFrame *line_2;
    QFrame *frame_2;
    QLabel *label;
    QLabel *label_2;
    QToolButton *pushButton_Left_3;

    void setupUi(QWidget *RunState)
    {
        if (RunState->objectName().isEmpty())
            RunState->setObjectName(QString::fromUtf8("RunState"));
        RunState->resize(1024, 540);
        tabWidget = new QTabWidget(RunState);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 250, 761, 271));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableWidget_Run = new QTableWidget(tab);
        if (tableWidget_Run->columnCount() < 6)
            tableWidget_Run->setColumnCount(6);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font1);
        tableWidget_Run->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font2);
        tableWidget_Run->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font2);
        tableWidget_Run->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font2);
        tableWidget_Run->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font2);
        tableWidget_Run->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font2);
        tableWidget_Run->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_Run->rowCount() < 1)
            tableWidget_Run->setRowCount(1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font3);
        tableWidget_Run->setItem(0, 0, __qtablewidgetitem6);
        tableWidget_Run->setObjectName(QString::fromUtf8("tableWidget_Run"));
        tableWidget_Run->setGeometry(QRect(20, 10, 611, 221));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Run->sizePolicy().hasHeightForWidth());
        tableWidget_Run->setSizePolicy(sizePolicy);
        tableWidget_Run->setFont(font2);
        tableWidget_Run->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_Run->setMouseTracking(true);
        tableWidget_Run->setFocusPolicy(Qt::NoFocus);
        tableWidget_Run->setAcceptDrops(true);
        tableWidget_Run->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Run->setMidLineWidth(1);
        tableWidget_Run->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Run->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Run->setAutoScrollMargin(16);
        tableWidget_Run->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Run->setDragEnabled(true);
        tableWidget_Run->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Run->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Run->setTextElideMode(Qt::ElideRight);
        tableWidget_Run->setGridStyle(Qt::SolidLine);
        tableWidget_Run->setSortingEnabled(false);
        tableWidget_Run->setRowCount(1);
        tableWidget_Run->setColumnCount(6);
        tableWidget_Run->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Run->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_Run->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Run->horizontalHeader()->setStretchLastSection(false);
        tableWidget_Run->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_Run->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton_Left_1 = new QToolButton(tab);
        pushButton_Left_1->setObjectName(QString::fromUtf8("pushButton_Left_1"));
        pushButton_Left_1->setGeometry(QRect(660, 10, 71, 61));
        pushButton_Left_1->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ICO/P2-UP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_1->setIcon(icon);
        pushButton_Left_1->setIconSize(QSize(36, 36));
        pushButton_Left_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
        pushButton_Left_2 = new QToolButton(tab);
        pushButton_Left_2->setObjectName(QString::fromUtf8("pushButton_Left_2"));
        pushButton_Left_2->setGeometry(QRect(660, 80, 71, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sans Serif"));
        font4.setPointSize(10);
        pushButton_Left_2->setFont(font4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/ICO/P1-LINK.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_2->setIcon(icon1);
        pushButton_Left_2->setIconSize(QSize(36, 36));
        pushButton_Left_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_4 = new QToolButton(tab);
        pushButton_Left_4->setObjectName(QString::fromUtf8("pushButton_Left_4"));
        pushButton_Left_4->setGeometry(QRect(660, 170, 71, 61));
        pushButton_Left_4->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ICO/P2-DOWN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_4->setIcon(icon2);
        pushButton_Left_4->setIconSize(QSize(36, 36));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_pic = new QLabel(tab_2);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(220, 40, 261, 171));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/PIC/PIC/P01.jpg")));
        label_pic->setScaledContents(true);
        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 711, 211));
        tabWidget->addTab(tab_2, QString());
        graphicsView->raise();
        label_pic->raise();
        frame = new QFrame(RunState);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 761, 211));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(30, 140, 101, 41));
        QFont font5;
        font5.setPointSize(28);
        font5.setBold(true);
        font5.setWeight(75);
        toolButton->setFont(font5);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/ICO/P1-START.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setIconSize(QSize(30, 30));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        lineEdit_RCurrentPos = new QLineEdit(frame);
        lineEdit_RCurrentPos->setObjectName(QString::fromUtf8("lineEdit_RCurrentPos"));
        lineEdit_RCurrentPos->setGeometry(QRect(170, 140, 181, 40));
        lineEdit_RCurrentPos->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_RCurrentPos->setReadOnly(true);
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(30, 80, 101, 41));
        toolButton_2->setFont(font5);
        toolButton_2->setIcon(icon3);
        toolButton_2->setIconSize(QSize(30, 30));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);
        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(30, 20, 101, 41));
        toolButton_3->setFont(font5);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(30, 30));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_3->setAutoRaise(true);
        lineEdit_XCurrentPos = new QLineEdit(frame);
        lineEdit_XCurrentPos->setObjectName(QString::fromUtf8("lineEdit_XCurrentPos"));
        lineEdit_XCurrentPos->setGeometry(QRect(170, 20, 181, 40));
        lineEdit_XCurrentPos->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_XCurrentPos->setReadOnly(true);
        lineEdit_YCurrentPos = new QLineEdit(frame);
        lineEdit_YCurrentPos->setObjectName(QString::fromUtf8("lineEdit_YCurrentPos"));
        lineEdit_YCurrentPos->setGeometry(QRect(170, 80, 181, 40));
        lineEdit_YCurrentPos->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_YCurrentPos->setReadOnly(true);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(380, 30, 20, 151));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(410, 30, 91, 31));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        toolButton_4->setFont(font6);
        toolButton_4->setIconSize(QSize(30, 30));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_4->setAutoRaise(true);
        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(410, 60, 91, 31));
        toolButton_5->setFont(font6);
        toolButton_5->setIconSize(QSize(30, 30));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_5->setAutoRaise(true);
        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(410, 90, 91, 31));
        toolButton_6->setFont(font6);
        toolButton_6->setIconSize(QSize(30, 30));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_6->setAutoRaise(true);
        toolButton_7 = new QToolButton(frame);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(410, 120, 91, 31));
        toolButton_7->setFont(font6);
        toolButton_7->setIconSize(QSize(30, 30));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_7->setAutoRaise(true);
        toolButton_8 = new QToolButton(frame);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        toolButton_8->setGeometry(QRect(410, 150, 91, 31));
        toolButton_8->setFont(font6);
        toolButton_8->setIconSize(QSize(30, 30));
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_8->setAutoRaise(true);
        pushButton_Left_5 = new QToolButton(frame);
        pushButton_Left_5->setObjectName(QString::fromUtf8("pushButton_Left_5"));
        pushButton_Left_5->setGeometry(QRect(660, 30, 71, 151));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pushButton_Left_5->setPalette(palette);
        pushButton_Left_5->setFont(font2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/ICO/P1-STOP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_5->setIcon(icon4);
        pushButton_Left_5->setIconSize(QSize(48, 48));
        label_ProgramName = new QLabel(frame);
        label_ProgramName->setObjectName(QString::fromUtf8("label_ProgramName"));
        label_ProgramName->setGeometry(QRect(500, 30, 131, 31));
        label_ProgramName->setFont(font1);
        label_CurrentStep = new QLabel(frame);
        label_CurrentStep->setObjectName(QString::fromUtf8("label_CurrentStep"));
        label_CurrentStep->setGeometry(QRect(500, 60, 131, 31));
        label_CurrentStep->setFont(font1);
        label_WorkedTotal = new QLabel(frame);
        label_WorkedTotal->setObjectName(QString::fromUtf8("label_WorkedTotal"));
        label_WorkedTotal->setGeometry(QRect(500, 90, 131, 31));
        label_WorkedTotal->setFont(font1);
        label_Pressure = new QLabel(frame);
        label_Pressure->setObjectName(QString::fromUtf8("label_Pressure"));
        label_Pressure->setGeometry(QRect(500, 120, 131, 31));
        label_Pressure->setFont(font1);
        label_Run = new QLabel(frame);
        label_Run->setObjectName(QString::fromUtf8("label_Run"));
        label_Run->setGeometry(QRect(500, 150, 131, 31));
        label_Run->setFont(font1);
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(630, 30, 20, 151));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        frame_2 = new QFrame(RunState);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(800, 20, 211, 501));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 70, 201, 261));
        label->setPixmap(QPixmap(QString::fromUtf8(":/PIC/PIC/PIC_UPPER.png")));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 350, 201, 161));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/PIC/PIC/PIC_LOWER.png")));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_Left_3 = new QToolButton(frame_2);
        pushButton_Left_3->setObjectName(QString::fromUtf8("pushButton_Left_3"));
        pushButton_Left_3->setGeometry(QRect(30, 10, 151, 41));
        pushButton_Left_3->setFont(font2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ico/ICO/P1-SIN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_3->setIcon(icon5);
        pushButton_Left_3->setIconSize(QSize(36, 35));
        pushButton_Left_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        retranslateUi(RunState);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RunState);
    } // setupUi

    void retranslateUi(QWidget *RunState)
    {
        RunState->setWindowTitle(QApplication::translate("RunState", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Run->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RunState", "\350\247\222\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Run->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RunState", "\350\247\222\345\272\246\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Run->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RunState", "Y\350\275\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Run->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RunState", "X\350\275\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Run->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("RunState", "X\350\275\264\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Run->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("RunState", "R\350\275\264", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_Run->isSortingEnabled();
        tableWidget_Run->setSortingEnabled(false);
        tableWidget_Run->setSortingEnabled(__sortingEnabled);

        pushButton_Left_1->setText(QApplication::translate("RunState", "UP", 0, QApplication::UnicodeUTF8));
        pushButton_Left_2->setText(QApplication::translate("RunState", "\350\267\263\350\275\254\350\207\263", 0, QApplication::UnicodeUTF8));
        pushButton_Left_4->setText(QApplication::translate("RunState", "down", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RunState", " \345\267\245\346\255\245 ", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RunState", " \345\233\276\346\240\267 ", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("RunState", "  R", 0, QApplication::UnicodeUTF8));
        lineEdit_RCurrentPos->setText(QString());
        toolButton_2->setText(QApplication::translate("RunState", "  Y", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("RunState", "  X", 0, QApplication::UnicodeUTF8));
        lineEdit_XCurrentPos->setText(QString());
        lineEdit_YCurrentPos->setText(QString());
        toolButton_4->setText(QApplication::translate("RunState", "\347\250\213 \345\272\217 \345\220\215 \357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("RunState", "\345\275\223\345\211\215\345\267\245\346\255\245\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("RunState", "\347\264\257\350\256\241\345\212\240\345\267\245\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("RunState", "\346\266\262\345\216\213\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("RunState", "\350\277\220\350\241\214\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Left_5->setText(QApplication::translate("RunState", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        label_ProgramName->setText(QApplication::translate("RunState", "EP01", 0, QApplication::UnicodeUTF8));
        label_CurrentStep->setText(QApplication::translate("RunState", "1/5", 0, QApplication::UnicodeUTF8));
        label_WorkedTotal->setText(QApplication::translate("RunState", "1/200", 0, QApplication::UnicodeUTF8));
        label_Pressure->setText(QApplication::translate("RunState", "\345\201\234\346\255\242/\345\277\253\344\270\213/\344\277\235\345\216\213", 0, QApplication::UnicodeUTF8));
        label_Run->setText(QApplication::translate("RunState", "\351\200\200\350\256\251/\345\256\232\344\275\215/\345\260\261\347\273\252", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        pushButton_Left_3->setText(QApplication::translate("RunState", "     \347\202\271\345\212\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunState: public Ui_RunState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSTATE_H
