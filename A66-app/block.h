#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>

namespace Ui {
class block;
}

class block : public QWidget
{
    Q_OBJECT
    
public:
    explicit block(QWidget *parent = 0);
    ~block();
    
private:
    Ui::block *ui;
};

#endif // BLOCK_H
