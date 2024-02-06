QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    add_form.cpp \
    main.cpp \
    schedule.cpp \
    teachers.cpp \
    view_form.cpp

HEADERS += \
    add_form.h \
    schedule.h \
    teachers.h \
    view_form.h

FORMS += \
    add_form.ui \
    schedule.ui \
    view_form.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES +=

