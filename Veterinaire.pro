FORMS += \
    mainwindow.ui \
    creation.ui

HEADERS += \
    mainwindow.h \
    creation.h \
    personnel.h \
    veto.h \
    secretaire.h \
    veterinaireInterface.h \
    dock.h \
    animal.h \
    animaldialog.h \
    owneranimaltreemodel.h \
    owneranimaltreeitem.h \
    owner.h \
    owner.hpp \
    conteneur.hpp \
    animal.hpp \
    personnel.hpp \
    vetodelegate.h

SOURCES += \
    mainwindow.cpp \
    main.cpp \
    creation.cpp \
    personnel.cpp \
    veto.cpp \
    secretaire.cpp \
    veterinaireInterface.cpp \
    dock.cpp \
    animal.cpp \
    animaldialog.cpp \
    owneranimaltreemodel.cpp \
    owneranimaltreeitem.cpp \
    owner.cpp \
    vetodelegate.cpp

QT += widgets
QT += core
QT += gui
QT += qml
QT += quick

DISTFILES += \
    qml/Kalendar.qml

QT += sql

