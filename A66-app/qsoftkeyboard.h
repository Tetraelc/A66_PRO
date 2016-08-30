#ifndef QSOFTKEYBOARD_H
#define QSOFTKEYBOARD_H

//#include <QWidget>
#include <QtGui>
#include <QtCore>
#include "ui_qsoftkeyboardForm.h"
#include<QWSServer>
#include <Qt>
#include <QMouseEvent>


namespace Ui {
class qSoftKeyboard;
}

class qSoftKeyboard : public QDialog
{
    Q_OBJECT
    
public:
   // explicit qSoftKeyboard(QWidget *parent = 0);
    qSoftKeyboard();
    QWidget *getFocusedWidget();
   // ~qSoftKeyboard();

signals:
    void characterGenerated(int key);
    void SendBackspace();
    void SendKeyBack();
    void redoKeyValue();

protected:
    bool event(QEvent *e);

private slots:
    void saveFocusWidget(QWidget *oldFocus, QWidget *newFocus);
    void buttonClicked(QWidget *w);
    void BackspaceContent();

    void on_closeButton_clicked();


    void on_EscButton_clicked();
    
    void on_BackButton_clicked();

private:
   // Ui::qSoftKeyboard *ui;
    Ui::qSoftKeyboardForm form;
    QWidget *lastFocusedWidget;
    QSignalMapper signalMapper;
};

#endif // QSOFTKEYBOARD_H
