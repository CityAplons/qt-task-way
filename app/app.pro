QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    about.cpp \
    parser2.cpp

HEADERS += \
    mainwindow.h \
    parser.h \
    about.h \
    parser2.h

FORMS += \
        mainwindow.ui \
    about.ui

RESOURCES += \
    resources.qrc