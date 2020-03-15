#include "form_notes.h"
#include "ui_form_notes.h"
#include "mainwindow.h"

Form_notes::Form_notes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_notes)
{
    ui->setupUi(this);
}

Form_notes::~Form_notes()
{
    delete ui;
}

void Form_notes::setBody(QString Str) {
    ui->textEdit_note_body->setText(Str);
    temporaryNote->body = Str;
}

void Form_notes::setTitle(QString Str) {
    ui->lineEdit_note_title->clear();
    ui->lineEdit_note_title->insert( Str);
    qDebug()<<"Title in setTitle: "<<Str;
    temporaryNote->title = Str;
}
QString Form_notes::getBody () {
    return ui->textEdit_note_body->toPlainText();
}
QString Form_notes::getTitle(){
    return ui->lineEdit_note_title->text();
}

void Form_notes::setChosenNote (int N){
    Form_notes::ChosenNote = N;
}
int Form_notes::getChosenNote () {
    return  Form_notes::ChosenNote;
}

Note * Form_notes::getWholeNote() {
    Note * n = new Note;

    n->title = getTitle();
    n->body = getBody();
    return n;
}

void Form_notes::setWholeNote(Note * n){
    temporaryNote = n;
}


void Form_notes::on_pushButton_note_OK_clicked() {
    qDebug () << "row in form: " << ChosenNote;
    qDebug () << "Title1  in on_pushButton_note_OK_clicked: " << temporaryNote->title;
temporaryNote = getWholeNote();
qDebug () << "Title2  in on_pushButton_note_OK_clicked: " << temporaryNote->title;
    emit sendNote();
}

void Form_notes::setTemporaryNote (Note * N) {
    this->temporaryNote = N;
}
Note * Form_notes::getTemporaryNote () {
    return this->temporaryNote;
}

