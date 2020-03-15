#include "form_contact.h"
#include "ui_form_contact.h"
#include <QDebug>

Form_contact::Form_contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_contact)
{
    ui->setupUi(this);
}

Form_contact::~Form_contact()
{
    delete ui;
}


void Form_contact::setName(QString Str) {
    ui->lineEdit_name->clear();

ui->lineEdit_name->insert(Str);


}


void Form_contact::setTypeNumber(int row,int rowsNum,QString Type,QString Number) {//вывод в таблицу

ui->tableWidgetContacts->setRowCount(rowsNum);
ui->tableWidgetContacts->setItem(row,0,new QTableWidgetItem(Type));
ui->tableWidgetContacts->setItem(row,1, new QTableWidgetItem(Number));

}

void Form_contact::on_pushButton_add_phone_clicked()
{
   ui->tableWidgetContacts->insertRow(ui->tableWidgetContacts->rowCount());//...и появляется пустая строчка в табличке
}

void Form_contact::on_pushButton_delete_phones_clicked()
{
    for (int i = 0; i < ui->tableWidgetContacts->rowCount(); i ++){
        Phone * p = new Phone;
         p->type = ui->tableWidgetContacts->item(i,0)->text();
         p->number = ui->tableWidgetContacts->item(i,1)->text();
         temporaryVec.append(p);
    }

    qDebug () << "temp vec size in deleting" << temporaryVec.size();

    QList <QTableWidgetItem *>  selected = ui->tableWidgetContacts->selectedItems();

    QList <int> selectedIndexes;

    for (int i = 0; i < selected.size(); i ++) {
        selectedIndexes.append( selected[i]->row());
    }

    selectedIndexes = (selectedIndexes.toSet()).toList(); //убираю дубликаты по-питонски

//такая странная логика связана с тем, что если мы удаляем из вектора элемент какого-то индекса, то все индексы после него сдвигаются, и нарушается последовательность
     qSort(selectedIndexes);
    int counter = 0;
    while (selectedIndexes.isEmpty() == false)
        {
            qDebug () << 0 << " - " << selectedIndexes[0];
                ui->tableWidgetContacts->removeRow(selectedIndexes[0] - counter);
                temporaryVec.remove(selectedIndexes[0] - counter);
            selectedIndexes.pop_front();
            counter ++;
}

}

void Form_contact::on_pushButton_save_contact_clicked()
{
    temporaryVec.clear();
    for (int i = /*ui->tableWidgetContacts->rowCount()-1*/ 0 ; i < ui->tableWidgetContacts->rowCount(); i ++){//цикл начинается со строчки, которая была последней до того,
    Phone * p = new Phone; //как мы добавили новую
    //int i=ui->tableWidgetContacts->rowCount()-1;
    p->type = ui->tableWidgetContacts->item(i,0)->text(); //остается научиться передавать в MainWindow и сделать append нашему telArr
    p->number = ui->tableWidgetContacts->item(i,1)->text();
    temporaryVec.append(p);
    }
    qDebug ()<< "temp vec size " << temporaryVec.size();
    for (int i = 0; i < temporaryVec.size(); i ++){
    qDebug ()<< "temp vec elements t " << temporaryVec[i]->type;
    qDebug ()<< "temp vec elements n" << temporaryVec[i]->number;
    }
}

void Form_contact::setChosenContact (int N){
    Form_contact::ChosenContact = N;
}
int Form_contact::getChosenContact () {
    return  Form_contact::ChosenContact;
}
void Form_contact::on_pushButton_contact_OK_clicked()
{
    //this->setChosenContact(-1);
    //this->close(); //здесь закрываем форму // теперь мы закрываем ее в слоте, который открывается по сгналу
    //temporaryVec = getTemporaryVec();
    emit sendContact(); //посылаем сигнал
    //ui->tableWidgetContacts->clear();
    //ui->tableWidgetContacts->setRowCount( 0);
}

QVector <Phone *>  Form_contact::getTemporaryVec(){
    QVector <Phone *> vec;
    vec = this->temporaryVec;
    return vec;
}

QTableWidget * Form_contact::getTable (){
    return ui->tableWidgetContacts;
}

QString Form_contact::getName(){
    return ui->lineEdit_name->text();
}
