#ifndef EASYBEND_H
#define EASYBEND_H

#include <QWidget>

namespace Ui {
class EasyBend;
}

class EasyBend : public QWidget
{
    Q_OBJECT
    
public:
    explicit EasyBend(QWidget *parent = 0);
    ~EasyBend();
public slots:
    void openEasyBendWin();
private:
    Ui::EasyBend *ui;
};

#endif // EASYBEND_H
