QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    about.cpp

HEADERS += \
    mainwindow.h \
    parser.h \
    about.h

FORMS += \
        mainwindow.ui \
    about.ui

RESOURCES += \
    resources.qrc