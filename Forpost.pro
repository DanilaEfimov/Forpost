QT += core gui widgets
TEMPLATE = app

CONFIG += c++20

SRC = $$PWD/src

INCLUDEPATH += \
    $$SRC \
    $$SRC/ui \
    $$SRC/ui/widgets \
    $$SRC/ui/effects \
    $$SRC/ui/cockpit \
    $$SRC/ui/styles \
    $$SRC/core \
    $$SRC/control \
    $$SRC/simulation

SOURCES += \
    $$SRC/core/main.cpp \
    $$SRC/ui/cockpit/mainwindow.cpp \
    $$files($$SRC/ui/widgets/*.cpp) \
    $$files($$SRC/ui/effects/*.cpp) \
    $$files($$SRC/ui/styles/*.cpp)

HEADERS += \
    $$files($$SRC/ui/widgets/*.h) \
    $$files($$SRC/ui/effects/*.h) \
    $$files($$SRC/ui/styles/*.h)

FORMS += \
    $$files($$SRC/ui/widgets/*.ui) \
    $$SRC/ui/cockpit/mainwindow.ui

DEFINES += APP_VERSION=\"1.0.0\"

RESOURCES += \
    $$SRC/ui/styles/styles.qrc
