#define nautilusPATH "C:\\Users\\ksuun\\Documents\\QtProjects\\ProjectNotebook\\notebooQT(v.190519)_upd"
//"C:\\Users\\HP_HOME\\Desktop\\QtProjects\\notebooQT(v.190519)_upd"
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fn = new Form_notes ();
    fc = new Form_contact ();
    connect(ui->listWidget_notes, SIGNAL(itemDoubleClicked(QListWidgetItem *)), fn, SLOT(show()));
    connect(ui->listWidget_contacts, SIGNAL(itemDoubleClicked(QListWidgetItem *)), fc, SLOT(show()));
    connect (fn, SIGNAL(sendNote()), this, SLOT(recieveNote()));
    connect (fc, SIGNAL(sendContact()), this, SLOT(recieveContact()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNotebook (Notebook *Nb) {
    newBook = Nb;
}
Notebook* MainWindow::getNotebook () {
    return newBook;
}

void MainWindow::showLists() {
   readFromNoteFileJson();
    readFromContactFileJson();
   setListNotes();
    setListContacts();

}

void MainWindow::setListContacts(){
    ui->listWidget_contacts->clear();  //очистим виджет, чтобы эту функцию можно было использовать много раз
    QStringList listContactName;
    for(int i=0;i<newBook->contacts.size();i++)
    {
        if (newBook->contacts[i]->name != "")
            listContactName << newBook->contacts[i]->name;
        else
            listContactName << "Без имени";

    }
    ui->listWidget_contacts->addItems(listContactName);
}

void MainWindow::setListNotes(){
    ui->listWidget_notes->clear();  //очистим виджет, чтобы эту функцию можно было использовать много раз
    QStringList listNoteTitle;
    for(int i=0;i<newBook->notes.size();i++)
    {
        if (newBook->notes[i]->title != "")
            listNoteTitle << newBook->notes[i]->title;
        else
            listNoteTitle << "Без названия";

    }
    ui->listWidget_notes->addItems(listNoteTitle);
}


void MainWindow::on_pushButton_add_contact_clicked()
{
    Form_contact_add *w = new Form_contact_add;

    w->show();
}

void MainWindow::on_pushButton_add_note_clicked()
{
    Form_notes_add *w = new Form_notes_add;
    w->show();
}

void MainWindow::readFromNoteFileJson ()
{
    notePath = QFileDialog::getOpenFileName(nullptr, "choose notes json", nautilusPATH, "*.json" );
    noteFile.setFileName(notePath);
    if (noteFile.open(QIODevice::ReadOnly|QFile::Text)) {
        doc = QJsonDocument::fromJson(QByteArray(noteFile.readAll()), &docError);
        noteFile.close();

        docArr = QJsonValue(doc.object().value("notes")).toArray();

        if (docError.errorString().toInt()==QJsonParseError::NoError) {


            for (int i=0; i<docArr.count(); i++) {

              QJsonObject  curr_obj = docArr[i].toObject();

             Note *newNote=new Note(curr_obj.value("title").toString(), curr_obj.value("body").toString());
             newBook->notes.push_back(newNote);
            }
      }
        else {
            QMessageBox::information(nullptr, "info", "json parse error, dunno how to fix it");
        }
    }
    else {
        QMessageBox::information(nullptr, "info","note file was not opened");
    }
}


void MainWindow::readFromContactFileJson (){
    contactPath = QFileDialog::getOpenFileName(nullptr, "choose contacts json", nautilusPATH, "*.json" );
    contactFile.setFileName(contactPath);
    if (contactFile.open(QIODevice::ReadOnly|QFile::Text)) {
        doc = QJsonDocument::fromJson(QByteArray(contactFile.readAll()), &docError);
        contactFile.close();

        docArr = QJsonValue(doc.object().value("contacts")).toArray();

        if (docError.errorString().toInt()==QJsonParseError::NoError) {


            for (int i=0; i<docArr.count(); i++) {

              QJsonObject  curr_obj = docArr[i].toObject();

QString Name = curr_obj.value("name").toString();
QVector <Phone*> PhoneVec;
QJsonArray  telArr = curr_obj.value("telArr").toArray() ;
for (int j = 0 ; j < telArr.size(); j ++)
{
    Phone * newPhone = new Phone(telArr[j].toObject().value("type").toString(),telArr[j].toObject().value("number").toString());

    PhoneVec.push_back(newPhone);
}

            Contact *newContact=new Contact(Name, PhoneVec);
             newBook->contacts.push_back(newContact);
            }
      }
        else {
            QMessageBox::information(nullptr, "info", "json parse error, dunno how to fix it");
        }
    }
    else {
        QMessageBox::information(nullptr, "info","note file was not opened");
    }
}

void MainWindow::on_listWidget_notes_itemDoubleClicked(QListWidgetItem *item)
{
    QString Title = item->text();
    qDebug()<<"Title: "<<Title;

    int row=ui->listWidget_notes->row(item);

    fn->setTitle(newBook->notes[row]->title);
    fn->setBody(newBook->notes[row]->body);

    fn->setChosenNote(row);

    fn->setWholeNote(newBook->notes[row]);
}

void MainWindow::on_listWidget_contacts_itemDoubleClicked(QListWidgetItem *item)
{
     int row=ui->listWidget_contacts->row(item);

    fc->setName( newBook->contacts[row]->name);
    if (newBook->contacts[row]->telArr.size() != 0)
    {

int rowsNum=newBook->contacts[row]->telArr.size();

for (int j = 0 ; j < newBook->contacts[row]->telArr.size(); j ++)//вывод в таблицу
{
     fc->setTypeNumber(j,rowsNum,newBook->contacts[row]->telArr[j]->type, newBook->contacts[row]->telArr[j]->number);

   }
    }

fc->setChosenContact(row);

}

void MainWindow::on_pushButton_delete_note_clicked()
{
    if (ui->listWidget_notes->count() != 0)
    {
        int row=ui->listWidget_notes->currentRow();
        QListWidgetItem * i = ui->listWidget_notes->takeItem(row);
        if ( i != nullptr)
        {
            this->newBook->notes.remove(row);
        }
    }
}
void MainWindow::on_pushButton_delete_contact_clicked()
{
    if (ui->listWidget_contacts->count() != 0)
    {
        int row=ui->listWidget_contacts->currentRow();
        QListWidgetItem * i = ui->listWidget_contacts->takeItem(row);
        if ( i != nullptr)
        {
        this->newBook->contacts.remove(row);
        }
    }
}


void MainWindow::on_pushButton_addDialog_clicked()
{
    Dialog dialog;
    if(dialog.exec()){
        if (dialog.title() != "")
            ui->listWidget_notes->addItem(dialog.title());
        else {
            ui->listWidget_notes->addItem("Без названия");
        }
        Note *newAddedNote=new Note(dialog.title(), dialog.body());
        newBook->notes.push_back(newAddedNote);
    }
    for (int i=0;i<newBook->notes.size();i++){
    qDebug()<<"Titles: "<<newBook->notes[i]->title;
    qDebug()<<"Bodies: "<<newBook->notes[i]->body;
    }
}

void MainWindow::on_pushButton_AddDialCont_clicked()
{
    DialogCont dialogCont;
    if (dialogCont.exec()){
        if (dialogCont.name() != "")
         ui->listWidget_contacts->addItem(dialogCont.name());
        else {
            ui->listWidget_contacts->addItem("No name");
        }
         QVector <Phone*> PhoneVec;
            PhoneVec=dialogCont.typeNumsFunc();

            if ((PhoneVec[PhoneVec.size()-1]->number =="") && (PhoneVec[PhoneVec.size()-1]->type== ""))
            PhoneVec.pop_back();

         Contact *newAddedContact=new Contact(dialogCont.name(), PhoneVec);
          newBook->contacts.push_back(newAddedContact);
    }
}


void MainWindow::on_actionsave_notes_triggered()
{
    noteFile.setFileName(notePath); //сохраняем в тот же файл, который и открывали
    if (noteFile.open (QIODevice::WriteOnly)) {
        QList <QVariantMap> mapList = {};
        QVariantMap  map;
        for (int i = 0; i<this->newBook->notes.size(); i++) {
            map.insert("title", this->newBook->notes[i]->title );
            map.insert("body", this->newBook->notes[i]->body );
            mapList.append(map);
        }
                QJsonArray docToWrite;
                for (int i = 0; i<this->newBook->notes.size(); i++) {
                    QJsonObject json = QJsonObject::fromVariantMap(mapList[i]);
                docToWrite.append(json);
                }
                doc.setArray(docToWrite);
                noteFile.write("{\"notes\":" + doc.toJson() + "}");
                noteFile.close();
    }
    else {

        QMessageBox::information(nullptr, "info","note file was not opened");
    }
}

void MainWindow::on_actionsave_contacts_triggered()
{
    consolePrintContacts();
    contactFile.setFileName(contactPath);
    if(contactFile.open(QIODevice::WriteOnly))
    {
        QList<QVariantMap> mapList1 = {};
        QList<QVariantMap> mapList2 = {};
        QVariantMap map1; //для целого контакта
        QVariantMap map2; //для массива телефонов
        for(int i=0;i<this->newBook->contacts.size(); i++)
        {
            map1.insert("name", this->newBook->contacts[i]->name);
            mapList2.clear();
            for(int j=0; j<this->newBook->contacts[i]->telArr.size(); j++)
               {
                //возможно, map2 надо очищать
                map2.insert("type", this->newBook->contacts[i]->telArr[j]->type);
                map2.insert("number", this->newBook->contacts[i]->telArr[j]->number);
                mapList2.append(map2);
               }
            QJsonArray newMap;
            for (int k = 0; k<this->newBook->contacts[i]->telArr.size(); k++)
            {
                QJsonObject json1 = QJsonObject::fromVariantMap(mapList2[k]);
                newMap.append(json1);
            }
              map1.insert("telArr", newMap);
              mapList1.append(map1);
        }
                QJsonArray docToWrite1;
                for (int m = 0; m<this->newBook->contacts.size(); m++)
                {
                    QJsonObject json2 = QJsonObject::fromVariantMap(mapList1[m]);
                    docToWrite1.append(json2);
                }
            doc.setArray(docToWrite1);
            contactFile.write("{\"contacts\":" + doc.toJson() + "}");
            contactFile.close();
    }
 else
    QMessageBox::information(nullptr, "info","contact file was not opened");

}
void MainWindow::on_actionboth_notes_and_contacts_triggered()
{
    ui->listWidget_notes->clear();
    ui->listWidget_contacts->clear();
    newBook->notes.clear();
    newBook->contacts.clear();
    showLists();
}

void MainWindow::consolePrintNotes() {
    qDebug () << "notes: ";
    for (int i = 0; i < newBook->notes.size(); i++){
        qDebug() << i << " - " << newBook->notes[i]->title << ' ' << newBook->notes[i]->body;
    }
}

void MainWindow::consolePrintContacts() {
    qDebug () << "contacts: ";
    for (int i = 0; i < newBook->contacts.size(); i++){
        qDebug() << i << " - " << newBook->contacts[i]->name;
        for (int j = 0; j < newBook->contacts[i]->telArr.size(); j++)
            qDebug () << " t: " << newBook->contacts[i]->telArr[j]->type << " n: " << newBook->contacts[i]->telArr[j]->number;
    }
}

void  MainWindow::recieveNote (){

    Note * n = fn->getWholeNote();
    int row = fn->getChosenNote();
    qDebug () << "row: " <<  row;
    newBook->notes[row] = n;
    setListNotes();
    fn->setChosenNote(-1);
    fn->close();
}

void  MainWindow::recieveContact () {

    QVector <Phone *> v = fc->getTemporaryVec();
    int row = fc->getChosenContact();
    newBook->contacts[row]->telArr = v;
    newBook->contacts[row]->name = fc->getName();
    fc->temporaryVec.clear();
    setListContacts();
    fc->setChosenContact(-1);
    fc->close();
}

