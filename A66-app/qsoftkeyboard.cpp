#include "qsoftkeyboard.h"
#include "moulds.h"

qSoftKeyboard::qSoftKeyboard()
    : QDialog(0, Qt::Tool | Qt::WindowStaysOnTopHint),
      lastFocusedWidget(0)
{
    form.setupUi(this);

//    Moulds md;

//    connect(form.closeButton, SIGNAL(clicked()),&md, SLOT(inputUHeightParameters(void)));
//    connect(form.closeButton, SIGNAL(clicked()),&md, SLOT(inputUAngleParameters(void)));
//    connect(form.closeButton, SIGNAL(clicked()),&md, SLOT(inputURadiusParameters(void)));
//    connect(form.closeButton, SIGNAL(clicked()),&md, SLOT(inputUImpedanceParameters(void)));
    form.BackButton->setProperty("buttonValue", QVariant(int(Qt::Key_Backspace)));
   // form.EscButton->setProperty("buttonValue", QVariant(int(Qt::Key_Clear)));
    connect(form.BackButton,SIGNAL(clicked()),this,SLOT(BackspaceContent()));

    Moulds *mds=new Moulds;
    connect(this, SIGNAL(redoKeyValue()), mds, SLOT(redoKeyAngleValue()));

    //connect(form.EscButton,SIGNAL(clicked()),this,SLOT(BackspaceContent()));

//   /* connect(form.closeButton, SIGNAL(clicked()),this, SLOT(hide()))*/;

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*) ), this, SLOT(saveFocusWidget(QWidget*,QWidget*)));

    signalMapper.setMapping(form.panelButton_1, form.panelButton_1);
    signalMapper.setMapping(form.panelButton_2, form.panelButton_2);
    signalMapper.setMapping(form.panelButton_3, form.panelButton_3);
    signalMapper.setMapping(form.panelButton_4, form.panelButton_4);
    signalMapper.setMapping(form.panelButton_5, form.panelButton_5);
    signalMapper.setMapping(form.panelButton_6, form.panelButton_6);
    signalMapper.setMapping(form.panelButton_7, form.panelButton_7);
    signalMapper.setMapping(form.panelButton_8, form.panelButton_8);
    signalMapper.setMapping(form.panelButton_9, form.panelButton_9);
    signalMapper.setMapping(form.panelButton_star, form.panelButton_star);
    signalMapper.setMapping(form.panelButton_0, form.panelButton_0);
    signalMapper.setMapping(form.panelButton_Dec, form.panelButton_Dec);
    //signalMapper.setMapping(form.panelButton_Plus, form.panelButton_Plus);
    signalMapper.setMapping(form.BackButton, form.BackButton);
    //signalMapper.setMapping(form.EscButton, form.EscButton);

    connect(form.panelButton_1, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_2, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_3, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_4, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_5, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_6, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_7, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_8, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_9, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_star, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_0, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.panelButton_Dec, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
   // connect(form.panelButton_Plus, SIGNAL(clicked()),
   //         &signalMapper, SLOT(map()));
    connect(form.BackButton, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
  //  connect(form.EscButton, SIGNAL(clicked()),
    //        &signalMapper, SLOT(map()));

    connect(&signalMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(buttonClicked(QWidget*)));
}

void qSoftKeyboard::on_EscButton_clicked()
{
    emit redoKeyValue();

    qDebug()<<"redoKeyValue";
    this->close();

}



void qSoftKeyboard::BackspaceContent()
{
    qDebug()<<"BackspaceContent";

    //this->content.chop(1);
    //sendPreeditString(content,0);0x01000005
}


void qSoftKeyboard::on_BackButton_clicked()
{

    //QWSServer::sendKeyEvent(0x01000003,Qt::Key_Backspace,Qt::NoModifier,true,false);//只能嵌入式平台下使用
}

void qSoftKeyboard::on_closeButton_clicked()//Key_Enter
{
    //QWSServer::sendKeyEvent(0x01000005,Qt::Key_Enter,Qt::NoModifier,true,false);//只能嵌入式平台下使用
     this->close();
}




//! [0]

bool qSoftKeyboard::event(QEvent *e)
{
    switch (e->type()) {
//! [1]
    case QEvent::WindowActivate:
        if (lastFocusedWidget)
            lastFocusedWidget->activateWindow();
        break;

//! [1]
    default:
        break;
    }

    return QWidget::event(e);
}

//! [2]

void qSoftKeyboard::saveFocusWidget(QWidget * /*oldFocus*/, QWidget *newFocus)
{
    if (newFocus != 0 && !this->isAncestorOf(newFocus)) {
        lastFocusedWidget = newFocus;
    }
}

//! [2]
//! [3]

void qSoftKeyboard::buttonClicked(QWidget *w)
{

  // int key;
/*    QString str = ((QPushButton*)w)->text();
    if (str == "CLR") {
        key = Qt::Key_Backspace;

    }
    else {
        QChar chr = ((QPushButton*)w)->text().at(0);
        key = chr.unicode();
    }
*/
  //  emit characterGenerated(key);

    int chr = qvariant_cast<int>(w->property("buttonValue"));
    emit characterGenerated(chr);
}

QWidget * qSoftKeyboard::getFocusedWidget()
{
    return lastFocusedWidget;
}
//! [3]






