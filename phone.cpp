#include "phone.h"

Phone::Phone()
{

}

Phone::Phone(QString type,QString number){
    Phone::type=type;
    Phone::number=number;

};
Phone::Phone (QJsonObject newPhoneObj)
{
    type = newPhoneObj.value("type").toString();
    number = newPhoneObj.value("number").toString();

};
