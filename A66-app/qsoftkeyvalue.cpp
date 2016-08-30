#include "qsoftkeyvalue.h"
#include <QtCore>
#include <QDebug>

//! [0]

qSoftKeyvaule::qSoftKeyvaule()
{
    MyKeyvaule = new qSoftKeyboard;
    connect(MyKeyvaule, SIGNAL(SendKeyBack()), SLOT(recKey_Backspace()));
    connect(MyKeyvaule, SIGNAL(characterGenerated(int)), SLOT(sendCharacter(int)));




}

//! [0]

qSoftKeyvaule::~qSoftKeyvaule()
{
    delete MyKeyvaule;
}

void qSoftKeyvaule::recKey_Backspace()
{
   // QWSServer::sendKeyEvent(0x01000003,Qt::Key_Backspace,Qt::NoModifier,true,false);//只能嵌入式平台下使用

   // QWSServer::sendKeyEvent(0x01000003,Qt::Key_Backspace,Qt::NoModifier,true,false);
    //MyKeyvaule->exec();
    qDebug("recKey_Backspace");
}


//! [1]


bool qSoftKeyvaule::reshowkeyvaule()
{
//    if (event->type() == QEvent::RequestSoftwareInputPanel) {
//       updatePosition();

////       MyKeyvaule->setWindowFlags(Qt::X11BypassWindowManagerHint);
//       MyKeyvaule->exec();

//        return true;
//    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
//        MyKeyvaule->hide();
//        return true;
//    }
//    return false;
}







bool qSoftKeyvaule::filterEvent(const QEvent* event)
{
    if (event->type() == QEvent::RequestSoftwareInputPanel) {
       updatePosition();

     //  emit AngleSelectAll();

//       MyKeyvaule->setWindowFlags(Qt::X11BypassWindowManagerHint);
       MyKeyvaule->exec();

        return true;
    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
        MyKeyvaule->hide();
        return true;
    }
    return false;
}

//! [1]

QString qSoftKeyvaule::identifierName()
{
    return "MyInputPanelContext";
}

void qSoftKeyvaule::reset()
{
}

bool qSoftKeyvaule::isComposing() const
{
    return false;
}

QString qSoftKeyvaule::language()
{
    return "en_US";
}

//! [2]

void qSoftKeyvaule::sendCharacter( int key)
{
    //QPointer<QWidget> w = focusWidget();
    QPointer<QWidget> w = MyKeyvaule->getFocusedWidget();

    if (!w)
        return;

    QKeyEvent keyPress(QEvent::KeyPress, key, Qt::NoModifier, QString(key));
    QApplication::sendEvent(w, &keyPress);


//    if (!w)
//        return;

//    QKeyEvent keyRelease(QEvent::KeyPress, key, Qt::NoModifier, QString());
//    QApplication::sendEvent(w, &keyRelease);

}

//! [2]

//! [3]

void qSoftKeyvaule::updatePosition()
{
    QWidget *widget = focusWidget();
    if (!widget)
        return;
    QRect widgetRect = widget->rect();

    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom() +2);
    panelPos = widget->mapToGlobal(panelPos);
    MyKeyvaule->move(panelPos);
}

//! [3]
