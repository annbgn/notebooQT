#include "note.h"

Note::Note()
{

}

Note::Note(QString title,QString body)
{
 Note::title=title;
 Note::body=body;
}

Note::Note(QJsonObject*newNoteObj)
{
    title = newNoteObj->value("title").toString();
    body = newNoteObj->value("body").toString();
}
