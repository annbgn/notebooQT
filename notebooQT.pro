#-------------------------------------------------
#
# Project created by QtCreator 2019-04-24T16:33:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notebooQT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    notebook.cpp \
    form_notes.cpp \
    form_contact.cpp \
    form_notes_add.cpp \
    form_contact_add.cpp \
    base.cpp \
    contact.cpp \
    phone.cpp \
    note.cpp \
    dialog.cpp \
    dialogcont.cpp

HEADERS += \
        mainwindow.h \
    notebook.h \
    form_notes.h \
    form_contact.h \
    form_notes_add.h \
    form_contact_add.h \
    base.h \
    contact.h \
    phone.h \
    note.h \
    dialog.h \
    dialogcont.h

FORMS += \
        mainwindow.ui \
    form_notes.ui \
    form_contact.ui \
    form_notes_add.ui \
    form_contact_add.ui \
    dialog.ui \
    dialogcont.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
