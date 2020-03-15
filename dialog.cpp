#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


QString Dialog::title(){
    return ui->lineEdit->text();

}

QString Dialog::body(){
    return ui->textEdit->toPlainText();
}
