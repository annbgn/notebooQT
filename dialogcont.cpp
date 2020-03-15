#include "dialogcont.h"
#include "ui_dialogcont.h"

DialogCont::DialogCont(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCont)
{
    ui->setupUi(this);
}

DialogCont::~DialogCont()
{
    delete ui;
}

int DialogCont::rowNum(){
    return ui->tableWidget->rowCount();
}

QString DialogCont::name(){
    return ui->lineEdit_name->text();
}

QString DialogCont::type(){
    return ui->lineEdit_type->text();
}

QVector <Phone*> DialogCont::typeNumsFunc(){

    Phone *addedPhone=new Phone(type(),number());
    typeNums.push_back(addedPhone);

    return typeNums;

}

QString DialogCont::number(){
    return ui->lineEdit_number->text();
}

void DialogCont::on_pushButtonAddNum_clicked()
{
    typeNumsFunc();

    ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
   ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(ui->lineEdit_type->text()));
   ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(ui->lineEdit_number->text()));

   ui->lineEdit_type->clear();
   ui->lineEdit_number->clear();


}
