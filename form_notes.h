#ifndef FORM_NOTES_H
#define FORM_NOTES_H

#include <QWidget>
#include <QString>
#include "note.h"

namespace Ui {
class Form_notes;
}

class Form_notes : public QWidget
{
    Q_OBJECT

public:
    int ChosenNote = -1;
    Note * temporaryNote = new Note ("", "");
    explicit Form_notes(QWidget *parent = nullptr);
    ~Form_notes();


    void setBody (QString Str);
void setTitle(QString Str);
QString getBody (); //сохранится с переносами на новую строку \n , но все одной строкой
QString getTitle();

void setChosenNote (int N);
int getChosenNote ();

Note * getWholeNote();
void setWholeNote(Note * );

void setTemporaryNote (Note * N);
Note * getTemporaryNote ();

private slots:
void on_pushButton_note_OK_clicked(/*Note * note*/);
signals:
void sendNote();
//void respondForNote();

private:
    Ui::Form_notes *ui;
/*
signals:
    void sendData(Note * note);
private slots:
    void onButtonSend();
*/
};

#endif // FORM_NOTES_H
