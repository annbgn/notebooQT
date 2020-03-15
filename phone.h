#ifndef PHONE_H
#define PHONE_H

#include "base.h"

class Phone : public Base
{
    public:
    QString type;
    QString number;

public:
    Phone();
    Phone(QString type,QString number);
    Phone (QJsonObject newPhoneObj);
};

#endif // PHONE_H
