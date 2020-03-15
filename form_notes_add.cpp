#include "form_notes_add.h"
#include "ui_form_notes_add.h"


Form_notes_add::Form_notes_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_notes_add)
{
    ui->setupUi(this);
}

Form_notes_add::~Form_notes_add()
{
    delete ui;
}

void Form_notes_add::on_pushButton_add_new_note_clicked()
{
     QString someTitle, someBody;
     someTitle=ui->lineEdit_note_title->text();
     someBody=ui->textEdit_note_body->toPlainText();

     Note *newAddedNote=new Note(someTitle,someBody);

}
