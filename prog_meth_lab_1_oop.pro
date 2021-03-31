TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += \
        main.cpp \
        program.cpp \
        test/test.cpp \
        test/test.cpp

HEADERS += \
    program.h \
    test/test.h \
    test/test.h

DISTFILES += \
    test/input_test.txt \
    test/output_test.txt \
    test/test.moc
