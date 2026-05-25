QT       += core gui

CONFIG += c++20

SRC_DIR = $$PWD/src
UI_DIR = $$PWD/src/ui

INCLUDEPATH =

SOURCES += $$files($$SRC_DIR/*.cpp, true)

HEADERS += $$files($$SRC_DIR/*.h, true)

FORMS += $$files(UI_DIR/*.ui, true)

TRANSLATIONS = $$files(translations/*.ts)

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

VERSION = 1.0.0
DEFINES += APP_VERSION = \\\"$$VERSION\\\"

message("Search path: $$SRC_DIR")
message("Found CPP: $$SOURCES")
