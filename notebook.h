#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "base.h"
#include "note.h"
#include "contact.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QFileDialog>

#include <QMessageBox>

#include <QDebug>
#include <QVector>
#include <QString>

class Notebook
{
public :

    QString notePath;
     QFile noteFile;
     QJsonDocument doc;
     QJsonArray docArr;
     QJsonParseError docError;

    QVector <Note*> notes;
    QVector <Contact*> contacts;



};

#endif // NOTEBOOK_H
