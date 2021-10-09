QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += release
CONFIG += debug
CONFIG += c++11

QT += charts
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BarChart.cpp \
    Folders_GroupFiles.cpp \
    SampleChart.cpp \
    Strat_GroupFiles.cpp \
    TableModel_GroupFiles.cpp \
    Types_GroupFiles.cpp \
    helper_Strat.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BarChart.h \
    Folders_GroupFiles.h \
    SampleChart.h \
    Strat_GroupFiles.h \
    TableModel_GroupFiles.h \
    Types_GroupFiles.h \
    helper_Strat.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
