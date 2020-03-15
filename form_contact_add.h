#ifndef FORM_CONTACT_ADD_H
#define FORM_CONTACT_ADD_H

#include <QWidget>

namespace Ui {
class Form_contact_add;
}

class Form_contact_add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_contact_add(QWidget *parent = nullptr);
    ~Form_contact_add();

private:
    Ui::Form_contact_add *ui;
};

#endif // FORM_CONTACT_ADD_H
