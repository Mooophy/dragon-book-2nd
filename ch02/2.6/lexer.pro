TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    lexer.cpp

HEADERS += \
    token.h \
    lexer.h

