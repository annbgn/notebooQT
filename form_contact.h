#ifndef FORM_CONTACT_H
#define FORM_CONTACT_H

#include <QWidget>
#include <QTableWidget>
#include <QList>
#include <QMessageBox>
#include "phone.h"

namespace Ui {
class Form_contact;
}

class Form_contact : public QWidget
{
    Q_OBJECT

public:
int ChosenContact = -1;


    explicit Form_contact(QWidget *parent = nullptr);
    ~Form_contact();

void setName(QString Str);
void setTypeNumber(int row,int rows,QString Type,QString Number);
QVector <Phone *>  getTemporaryVec();
void setChosenContact (int N);
int getChosenContact ();
QTableWidget * getTable ();
QString getName();
private slots:
void on_pushButton_add_phone_clicked();

void on_pushButton_delete_phones_clicked();

void on_pushButton_save_contact_clicked();

void on_pushButton_contact_OK_clicked();



signals:
void sendContact();

private:
    Ui::Form_contact *ui;
public:
    QVector <Phone *> temporaryVec; //этот вектор содержит в себе текущие номера телефонов
};

#endif // FORM_CONTACT_H
