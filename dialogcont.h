#ifndef DIALOGCONT_H
#define DIALOGCONT_H

#include <QDialog>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "phone.h"

namespace Ui {
class DialogCont;
}

class DialogCont : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCont(QWidget *parent = nullptr);
    ~DialogCont();

    QVector <Phone*> typeNums;
    int rowNum();
    QString name();
    QString type();
    QString number();

    QVector <Phone*> typeNumsFunc();

private slots:
    void on_pushButtonAddNum_clicked();

private:
    Ui::DialogCont *ui;
};

#endif // DIALOGCONT_H
