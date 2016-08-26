/********************************************************************************
** Form generated from reading UI file 'programdb.ui'
**
** Created: Fri Aug 26 14:29:48 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMDB_H
#define UI_PROGRAMDB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Programdb
{
public:
    QGroupBox *groupBox;
    QLabel *label_boardThickness;
    QLabel *label_material;
    QLabel *label_mould;
    QLineEdit *lineEdit_P_boardThickness;
    QLabel *label_19;
    QLabel *label_mould_2;
    QLineEdit *lineEdit_P_UpMolds;
    QLineEdit *lineEdit_P_LowerMolds;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox_P_material;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_P_Total;
    QLabel *label_pic;
    QLabel *label_mould_3;
    QTableWidget *tableWidget_Programdb;
    QToolButton *pushButton_Left_2;
    QToolButton *pushButton_Left_5;
    QToolButton *pushButton_Left_6;
    QToolButton *pushButton_Left_3;
    QToolButton *pushButton_Left_8;
    QToolButton *pushButton_Left_7;
    QToolButton *pushButton_Left_1;
    QToolButton *pushButton_Left_4;

    void setupUi(QWidget *Programdb)
    {
        if (Programdb->objectName().isEmpty())
            Programdb->setObjectName(QString::fromUtf8("Programdb"));
        Programdb->resize(1024, 540);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\346\255\243\351\273\221"));
        font.setPointSize(20);
        Programdb->setFont(font);
        Programdb->setCursor(QCursor(Qt::ArrowCursor));
        groupBox = new QGroupBox(Programdb);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 280, 881, 251));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(12);
        groupBox->setFont(font1);
        label_boardThickness = new QLabel(groupBox);
        label_boardThickness->setObjectName(QString::fromUtf8("label_boardThickness"));
        label_boardThickness->setGeometry(QRect(30, 40, 131, 20));
        QFont font2;
        font2.setPointSize(14);
        label_boardThickness->setFont(font2);
        label_boardThickness->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_material = new QLabel(groupBox);
        label_material->setObjectName(QString::fromUtf8("label_material"));
        label_material->setGeometry(QRect(30, 80, 131, 21));
        label_material->setFont(font2);
        label_material->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mould = new QLabel(groupBox);
        label_mould->setObjectName(QString::fromUtf8("label_mould"));
        label_mould->setGeometry(QRect(28, 120, 131, 20));
        label_mould->setFont(font2);
        label_mould->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_P_boardThickness = new QLineEdit(groupBox);
        lineEdit_P_boardThickness->setObjectName(QString::fromUtf8("lineEdit_P_boardThickness"));
        lineEdit_P_boardThickness->setGeometry(QRect(180, 30, 170, 30));
        lineEdit_P_boardThickness->setFocusPolicy(Qt::ClickFocus);
        lineEdit_P_boardThickness->setMaxLength(5);
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(360, 40, 58, 15));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif"));
        font3.setPointSize(14);
        label_19->setFont(font3);
        label_mould_2 = new QLabel(groupBox);
        label_mould_2->setObjectName(QString::fromUtf8("label_mould_2"));
        label_mould_2->setGeometry(QRect(28, 160, 131, 20));
        label_mould_2->setFont(font2);
        label_mould_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_P_UpMolds = new QLineEdit(groupBox);
        lineEdit_P_UpMolds->setObjectName(QString::fromUtf8("lineEdit_P_UpMolds"));
        lineEdit_P_UpMolds->setGeometry(QRect(180, 110, 170, 30));
        lineEdit_P_UpMolds->setFocusPolicy(Qt::ClickFocus);
        lineEdit_P_UpMolds->setReadOnly(true);
        lineEdit_P_LowerMolds = new QLineEdit(groupBox);
        lineEdit_P_LowerMolds->setObjectName(QString::fromUtf8("lineEdit_P_LowerMolds"));
        lineEdit_P_LowerMolds->setGeometry(QRect(180, 150, 170, 30));
        lineEdit_P_LowerMolds->setFocusPolicy(Qt::ClickFocus);
        lineEdit_P_LowerMolds->setReadOnly(true);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 110, 60, 30));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 150, 60, 30));
        comboBox_P_material = new QComboBox(groupBox);
        comboBox_P_material->setObjectName(QString::fromUtf8("comboBox_P_material"));
        comboBox_P_material->setGeometry(QRect(180, 70, 170, 30));
        comboBox_P_material->setEditable(false);
        comboBox_P_material->setModelColumn(0);
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(560, 20, 301, 211));
        lineEdit_P_Total = new QLineEdit(groupBox);
        lineEdit_P_Total->setObjectName(QString::fromUtf8("lineEdit_P_Total"));
        lineEdit_P_Total->setGeometry(QRect(180, 190, 170, 30));
        lineEdit_P_Total->setFocusPolicy(Qt::ClickFocus);
        label_pic = new QLabel(groupBox);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(580, 40, 261, 171));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/PIC/PIC/P01.jpg")));
        label_pic->setScaledContents(true);
        label_mould_3 = new QLabel(groupBox);
        label_mould_3->setObjectName(QString::fromUtf8("label_mould_3"));
        label_mould_3->setGeometry(QRect(28, 200, 131, 20));
        label_mould_3->setFont(font2);
        label_mould_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tableWidget_Programdb = new QTableWidget(Programdb);
        if (tableWidget_Programdb->columnCount() < 9)
            tableWidget_Programdb->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font4;
        font4.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font4);
        tableWidget_Programdb->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font4);
        tableWidget_Programdb->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem6->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem7->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font1);
        tableWidget_Programdb->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget_Programdb->rowCount() < 1)
            tableWidget_Programdb->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_Programdb->setItem(0, 0, __qtablewidgetitem9);
        tableWidget_Programdb->setObjectName(QString::fromUtf8("tableWidget_Programdb"));
        tableWidget_Programdb->setGeometry(QRect(20, 10, 881, 261));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Programdb->sizePolicy().hasHeightForWidth());
        tableWidget_Programdb->setSizePolicy(sizePolicy);
        tableWidget_Programdb->setFont(font1);
        tableWidget_Programdb->setMouseTracking(true);
        tableWidget_Programdb->setAcceptDrops(false);
        tableWidget_Programdb->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Programdb->setMidLineWidth(1);
        tableWidget_Programdb->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Programdb->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Programdb->setAutoScroll(true);
        tableWidget_Programdb->setAutoScrollMargin(16);
        tableWidget_Programdb->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Programdb->setTabKeyNavigation(true);
        tableWidget_Programdb->setProperty("showDropIndicator", QVariant(true));
        tableWidget_Programdb->setDragEnabled(true);
        tableWidget_Programdb->setDragDropOverwriteMode(false);
        tableWidget_Programdb->setAlternatingRowColors(false);
        tableWidget_Programdb->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Programdb->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Programdb->setTextElideMode(Qt::ElideRight);
        tableWidget_Programdb->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_Programdb->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget_Programdb->setGridStyle(Qt::SolidLine);
        tableWidget_Programdb->setSortingEnabled(false);
        tableWidget_Programdb->setRowCount(1);
        tableWidget_Programdb->setColumnCount(9);
        tableWidget_Programdb->horizontalHeader()->setVisible(true);
        tableWidget_Programdb->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Programdb->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_Programdb->horizontalHeader()->setHighlightSections(true);
        tableWidget_Programdb->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget_Programdb->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Programdb->horizontalHeader()->setStretchLastSection(false);
        tableWidget_Programdb->verticalHeader()->setVisible(false);
        tableWidget_Programdb->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_Programdb->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton_Left_2 = new QToolButton(Programdb);
        pushButton_Left_2->setObjectName(QString::fromUtf8("pushButton_Left_2"));
        pushButton_Left_2->setGeometry(QRect(930, 77, 71, 61));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Sans Serif"));
        font5.setPointSize(10);
        pushButton_Left_2->setFont(font5);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ICO/P1-NEW.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_2->setIcon(icon);
        pushButton_Left_2->setIconSize(QSize(36, 36));
        pushButton_Left_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_5 = new QToolButton(Programdb);
        pushButton_Left_5->setObjectName(QString::fromUtf8("pushButton_Left_5"));
        pushButton_Left_5->setGeometry(QRect(930, 282, 71, 61));
        pushButton_Left_5->setFont(font5);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/ICO/P1-IMPORT.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_5->setIcon(icon1);
        pushButton_Left_5->setIconSize(QSize(36, 36));
        pushButton_Left_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_6 = new QToolButton(Programdb);
        pushButton_Left_6->setObjectName(QString::fromUtf8("pushButton_Left_6"));
        pushButton_Left_6->setGeometry(QRect(930, 345, 71, 61));
        pushButton_Left_6->setFont(font5);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ICO/P1-OUTPORT.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_6->setIcon(icon2);
        pushButton_Left_6->setIconSize(QSize(36, 36));
        pushButton_Left_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_3 = new QToolButton(Programdb);
        pushButton_Left_3->setObjectName(QString::fromUtf8("pushButton_Left_3"));
        pushButton_Left_3->setGeometry(QRect(930, 143, 71, 61));
        pushButton_Left_3->setFont(font5);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/ICO/P1-DEL.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_3->setIcon(icon3);
        pushButton_Left_3->setIconSize(QSize(36, 36));
        pushButton_Left_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_8 = new QToolButton(Programdb);
        pushButton_Left_8->setObjectName(QString::fromUtf8("pushButton_Left_8"));
        pushButton_Left_8->setGeometry(QRect(930, 471, 71, 61));
        pushButton_Left_8->setFont(font5);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/ICO/P1-PIC.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_8->setIcon(icon4);
        pushButton_Left_8->setIconSize(QSize(36, 36));
        pushButton_Left_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_7 = new QToolButton(Programdb);
        pushButton_Left_7->setObjectName(QString::fromUtf8("pushButton_Left_7"));
        pushButton_Left_7->setGeometry(QRect(930, 408, 71, 61));
        pushButton_Left_7->setFont(font1);
        pushButton_Left_7->setIconSize(QSize(36, 36));
        pushButton_Left_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pushButton_Left_1 = new QToolButton(Programdb);
        pushButton_Left_1->setObjectName(QString::fromUtf8("pushButton_Left_1"));
        pushButton_Left_1->setGeometry(QRect(930, 10, 71, 61));
        pushButton_Left_1->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ico/ICO/P2-UP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_1->setIcon(icon5);
        pushButton_Left_1->setIconSize(QSize(36, 36));
        pushButton_Left_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
        pushButton_Left_4 = new QToolButton(Programdb);
        pushButton_Left_4->setObjectName(QString::fromUtf8("pushButton_Left_4"));
        pushButton_Left_4->setGeometry(QRect(930, 210, 71, 61));
        pushButton_Left_4->setFont(font1);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ico/ICO/P2-DOWN.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Left_4->setIcon(icon6);
        pushButton_Left_4->setIconSize(QSize(36, 36));

        retranslateUi(Programdb);

        QMetaObject::connectSlotsByName(Programdb);
    } // setupUi

    void retranslateUi(QWidget *Programdb)
    {
        Programdb->setWindowTitle(QApplication::translate("Programdb", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Programdb", "\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_boardThickness->setText(QApplication::translate("Programdb", "\346\235\277\345\216\232", 0, QApplication::UnicodeUTF8));
        label_material->setText(QApplication::translate("Programdb", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        label_mould->setText(QApplication::translate("Programdb", "\344\270\212\346\250\241", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Programdb", "mm", 0, QApplication::UnicodeUTF8));
        label_mould_2->setText(QApplication::translate("Programdb", "\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Programdb", "...", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Programdb", "...", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QString());
        label_mould_3->setText(QApplication::translate("Programdb", "\347\264\257\350\256\241\345\212\240\345\267\245", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Programdb->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Programdb", "\347\250\213\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Programdb->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Programdb", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Programdb->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Programdb", "\346\255\245\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Programdb->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Programdb", "\346\235\277\345\256\275", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Programdb->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Programdb", "\346\235\277\345\216\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Programdb->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Programdb", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Programdb->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Programdb", "\344\270\212\346\250\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Programdb->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Programdb", "\344\270\213\346\250\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Programdb->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Programdb", "\345\267\262\345\212\240\345\267\245\346\225\260", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_Programdb->isSortingEnabled();
        tableWidget_Programdb->setSortingEnabled(false);
        tableWidget_Programdb->setSortingEnabled(__sortingEnabled);

        pushButton_Left_2->setText(QApplication::translate("Programdb", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
        pushButton_Left_5->setText(QApplication::translate("Programdb", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        pushButton_Left_6->setText(QApplication::translate("Programdb", "\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_Left_3->setText(QApplication::translate("Programdb", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_Left_8->setText(QApplication::translate("Programdb", "\346\267\273\345\212\240\347\205\247\347\211\207", 0, QApplication::UnicodeUTF8));
        pushButton_Left_7->setText(QString());
        pushButton_Left_1->setText(QApplication::translate("Programdb", "UP", 0, QApplication::UnicodeUTF8));
        pushButton_Left_4->setText(QApplication::translate("Programdb", "down", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Programdb: public Ui_Programdb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMDB_H
