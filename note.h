#ifndef NOTE_H
#define NOTE_H

#include "base.h"

class Note : public Base
{
public :
    QString title;
    QString body;
public:
    Note();
    Note(QString title,QString body);
    Note(QJsonObject*newNoteObj);
};

#endif // NOTE_H
