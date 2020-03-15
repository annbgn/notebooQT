#include "contact.h"

Contact::Contact()
{

}

Contact::Contact(QString name,QVector <Phone*> telArr)
{
    Contact::name=name;
    Contact::telArr=telArr;
};

Contact::Contact(QJsonObject*newContactObj)
{
    name = newContactObj->value("name").toString();
     QJsonArray telArr = newContactObj->value("telArr").toArray();

     for (int i=0; i<telArr.count(); i++)
     {
      QJsonObject newPhoneObj = telArr[i].toObject();

      Phone *newPhone=new Phone(newPhoneObj);

     }

};
