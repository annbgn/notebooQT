#ifndef CONTACT_H
#define CONTACT_H

#include <QVector>

#include "base.h"
#include"phone.h"

class Contact : public Base
{
public:
    QString name;
    QVector <Phone*> telArr;
public:
    Contact();
    Contact(QString name,QVector <Phone*> telArr);
    Contact(QJsonObject*newContactObj);
    //void readFromFile(QJsonObject*newObj);
};

#endif // CONTACT_H
