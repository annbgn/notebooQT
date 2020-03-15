#include "form_contact_add.h"
#include "ui_form_contact_add.h"

Form_contact_add::Form_contact_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_contact_add)
{
    ui->setupUi(this);
}

Form_contact_add::~Form_contact_add()
{
    delete ui;
}
