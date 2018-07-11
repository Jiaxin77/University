#-------------------------------------------------
#
# Project created by QtCreator 2017-04-28T18:18:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    digitalclock.cpp \
    logon.cpp \
    userdialog.cpp \
    rankdialog.cpp \
    noticedialog.cpp \
    cancelredialog.cpp \
    admdialog.cpp \
    addreaderdialog.cpp \
    addbookdialog.cpp \
    delbookdialog.cpp \
    ADMCLASS.cpp \
    BOOKCLASS.cpp \
    file.cpp \
    mytype.cpp \
    Notice.cpp \
    OverdueMgt.cpp \
    READERCLASS.cpp \
    search.cpp \
    Stats.cpp \
    TimeMgt.cpp \
    searchdialog.cpp \
    moneydialog.cpp \
    readeropdialog.cpp \
    ReservationMgt.cpp \
    bruteinput.cpp

HEADERS  += \
    digitalclock.h \
    logon.h \
    userdialog.h \
    rankdialog.h \
    noticedialog.h \
    searchdialog.h \
    cancelredialog.h \
    admdialog.h \
    addreaderdialog.h \
    addbookdialog.h \
    delbookdialog.h \
    ADMCLASS.h \
    BOOKCLASS.h \
    file.h \
    mytype.h \
    Notice.h \
    OverdueMgt.h \
    READERCLASS.h \
    ReservationMgt.h \
    search.h \
    Stats.h \
    TimeMgt.h \
    moneydialog.h \
    readeropdialog.h \
    bruteinput.h

FORMS    += \
    digitalclock.ui \
    logon.ui \
    userdialog.ui \
    rankdialog.ui \
    noticedialog.ui \
    searchdialog.ui \
    cancelredialog.ui \
    admdialog.ui \
    readeropdialog.ui \
    moneydialog.ui \
    addreaderdialog.ui \
    addbookdialog.ui \
    delbookdialog.ui

RESOURCES += \
    source.qrc
