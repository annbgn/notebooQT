#ifndef FORM_NOTES_ADD_H
#define FORM_NOTES_ADD_H


#include "note.h"
#include <QWidget>

namespace Ui {
class Form_notes_add;
}

class Form_notes_add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_notes_add(QWidget *parent = nullptr);
    ~Form_notes_add();

private slots:
    void on_pushButton_add_new_note_clicked();

private:
    Ui::Form_notes_add *ui;
};

#endif // FORM_NOTES_ADD_H
