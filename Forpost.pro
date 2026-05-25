QT       += core gui widgets
TEMPLATE = app

CONFIG += c++20

SRC_DIR = $$PWD/src
UI_DIR = $$PWD/src/ui

INCLUDEPATH =

SOURCES += $$files($$SRC_DIR/*.cpp, true) \
    src/ui/effects/circlerendereffect.cpp \
    src/ui/effects/pingeffect.cpp \
    src/ui/effects/pulseeffect.cpp \
    src/ui/effects/solidrendereffect.cpp \
    src/ui/effects/wavefromcentedeffect.cpp \
    src/ui/effects/wavetocentereffect.cpp

HEADERS += $$files($$SRC_DIR/*.h, true) \
        $$files($$UI_DIR/*.h, true) \
        src/ui/effects/circlerendereffect.h \
        src/ui/effects/pingeffect.h \
        src/ui/effects/pulseeffect.h \
        src/ui/effects/solidrendereffect.h \
        src/ui/effects/wavefromcentedeffect.h \
        src/ui/effects/wavetocentereffect.h

FORMS += $$files($$UI_DIR/*.ui, true)

TRANSLATIONS = $$files(translations/*.ts)

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

VERSION = 1.0.0
DEFINES += APP_VERSION = \\\"$$VERSION\\\"

message("Search path: $$SRC_DIR")
message("Found CPP: $$SOURCES")
message()
message("Search path: $$SRC_DIR")
message("Found H: $$HEADERS")
