#ifndef QSOFTKEYVALUE_H
#define QSOFTKEYVALUE_H
#include <QtGui/QInputContext>

#include "qsoftkeyboard.h"

extern int showKeyvauleFlag;
class qSoftKeyboard;

class qSoftKeyvaule : public QInputContext
{
    Q_OBJECT

public:
    qSoftKeyvaule();
    ~qSoftKeyvaule();

    bool filterEvent(const QEvent* event);

    QString identifierName();
    QString language();

    bool isComposing() const;

    void reset();

private slots:
    void sendCharacter(int key);

signals:
    void AngleSelectAll();

public slots:
    void recKey_Backspace();
    bool reshowkeyvaule();


private:
    void updatePosition();

private:
    qSoftKeyboard *MyKeyvaule;
};


#endif // QSOFTKEYVALUE_H
