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
    $$files($$SRC/ui/cockpit/*.cpp) \
    $$files($$SRC/ui/widgets/*.cpp) \
    $$files($$SRC/ui/effects/*.cpp) \
    $$files($$SRC/ui/styles/*.cpp)  \
    $$files($$SRC/ui/widgets/data/*.cpp) \
    src/ui/widgets/cameraconfigvisualizer.cpp \
    src/ui/widgets/optionswidget.cpp

HEADERS += \
    $$files($$SRC/ui/cockpit/*.h) \
    $$files($$SRC/ui/widgets/*.h)   \
    $$files($$SRC/ui/effects/*.h)   \
    $$files($$SRC/ui/styles/*.h)    \
    $$files($$SRC/ui/widgets/data/*.h) \
    src/ui/widgets/cameraconfigvisualizer.h \
    src/ui/widgets/optionswidget.h

FORMS += \
    $$files($$SRC/ui/widgets/*.ui) \
    $$SRC/ui/cockpit/mainwindow.ui \
    src/ui/widgets/cameraconfigvisualizer.ui \
    src/ui/widgets/optionswidget.ui

DEFINES += APP_VERSION=\"1.0.0\"

RESOURCES += \
    $$SRC/ui/styles/styles.qrc
