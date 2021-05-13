TARGET = model
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/userobject.h
HEADERS += user.h
SOURCES += user.cpp
HEADERS += sqlobjects/groupobject.h
HEADERS += group.h
SOURCES += group.cpp
HEADERS += sqlobjects/groupuserobject.h
HEADERS += groupuser.h
SOURCES += groupuser.cpp
HEADERS += sqlobjects/creditlogobject.h
HEADERS += creditlog.h
SOURCES += creditlog.cpp
HEADERS += sqlobjects/quizobject.h
HEADERS += quiz.h
SOURCES += quiz.cpp
