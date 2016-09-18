#ifndef CHOOSEPICTURE_H
#define CHOOSEPICTURE_H

#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDebug>
#include <QDirModel>

namespace Ui {
class ChoosePicture;
}

class ChoosePicture : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChoosePicture(QWidget *parent = 0);
    ~ChoosePicture();
    
private slots:
    void on_toolButton_Add_clicked();

private:
    Ui::ChoosePicture *ui;
    QFileSystemModel *model;
};

#endif // CHOOSEPICTURE_H
