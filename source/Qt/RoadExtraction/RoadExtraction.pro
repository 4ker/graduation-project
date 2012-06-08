#-------------------------------------------------
#
# Project created by QtCreator 2012-05-03T13:49:42
#
#-------------------------------------------------

QT       += core gui

TARGET = RoadExtraction
TEMPLATE = app


SOURCES += main.cpp\
    mainWindow.cpp \
    pathManager.cpp \
    processorManager.cpp \
    stepProcessor.cpp \
    logsManager.cpp \
    imgDialog.cpp

HEADERS  += \
    common.h \
    mainWindow.h \
    pathManager.h \
    processorManager.h \
    stepProcessor.h \
    logsManager.h \
    imgDialog.h

FORMS    += mainwindow.ui \
    imgdialog.ui

RC_FILE += RoadExtraction.rc

TRANSLATIONS += en_US.ts \
    zh_CN.ts
