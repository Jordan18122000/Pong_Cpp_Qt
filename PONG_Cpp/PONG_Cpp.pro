QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../shared
SOURCES += \
    ../shared/lcdrange.cpp \
    ../shared/myrandom.cpp \
    ../shared/qstd.cpp \
    balle.cpp \
    barre.cpp \
    configuration.cpp \
    findujeu.cpp \
    gamemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    score.cpp

HEADERS += \
    ../shared/lcdrange.h \
    ../shared/myrandom.h \
    ../shared/qstd.h \
    balle.h \
    barre.h \
    configuration.h \
    findujeu.h \
    gamemanager.h \
    mainwindow.h \
    score.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
