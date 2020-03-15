#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define NF "D:\\codes_for_uni\\C++\\notebooQT\\NOTE.txt"
//#define CF "D:\\codes_for_uni\\C++\\notebooQT\\CONTACT.txt"


#include "ui_mainwindow.h"
#include "form_notes.h"
#include "form_contact.h"
#include "form_contact_add.h"
#include "form_notes_add.h"
#include "notebook.h"

#include "dialog.h"
#include "dialogcont.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QFileDialog>

#include <QStandardItem>
#include <QMessageBox>

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Notebook *newBook= new Notebook;

    QJsonDocument doc;
    QJsonArray docArr;
    QJsonParseError docError;
    QString contactPath; //для пути к файлу с kontaktami, чтобы эта переменная всега хранилась именно тут
    QFile contactFile;
    QString notePath; //для пути к файлу с заметками, чтобы эта переменная всега хранилась именно тут
    QFile noteFile;

    //void readFromNoteFile();
    void readFromNoteFileJson();
    void readFromContactFileJson();

    void setListNotes(); //эта функция нужна для того, чтобы отображать вектор заметок в виждете
    void setListContacts();
    void setNotebook (Notebook* Nb);
    Notebook* getNotebook ();


    //void deleteNC (QString type, int row);//обща функция удаления для listWidget заметок и котнтактов, type может быть только "NOTES" или "CONTACTS", а row - это номер строки, которую надо удалить
void showLists(); //вызывает диалоговое окно для выбора файлов json, парсит json, заполняет виджеты (пока работает только для заметок)


private slots:

    void on_pushButton_add_contact_clicked();

    void on_pushButton_add_note_clicked();

    void on_listWidget_notes_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_contacts_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_delete_note_clicked();

    void on_pushButton_delete_contact_clicked();

    void on_pushButton_addDialog_clicked();

    void on_pushButton_AddDialCont_clicked();

    void on_actionsave_notes_triggered();
    void on_actionsave_contacts_triggered();

    void on_actionboth_notes_and_contacts_triggered();

    void consolePrintNotes();
    void consolePrintContacts();

    void recieveNote();
    void recieveContact();

    //void setourrows();

private:
    Ui::MainWindow *ui;
    Form_notes * fn;
    Form_contact * fc;

};

#endif // MAINWINDOW_H
