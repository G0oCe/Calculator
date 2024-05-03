TEMPLATE = app
TARGET = APP
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
QT += multimedia
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += \
    mainwindow.h

DISTFILES += \
    calculator.css

RESOURCES += \
    css.qrc
