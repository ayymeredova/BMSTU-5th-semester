QT       += 3dcore 3drender 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    branch.cpp \
    event_handler.cpp \
    leaf.cpp \
    line3d.cpp \
    main.cpp \
    model3d.cpp \
    model_handler.cpp \
    panel.cpp \
    tree.cpp \
    vector.cpp \
    view3d.cpp \
    widget.cpp

HEADERS += \
    branch.h \
    custom_struct.h \
    error.h \
    event_handler.h \
    leaf.h \
    line3d.h \
    model3d.h \
    model_handler.h \
    panel.h \
    request.h \
    tree.h \
    vector.h \
    view3d.h \
    widget.h

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
