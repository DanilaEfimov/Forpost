QT += core gui widgets
TEMPLATE = app

CONFIG += c++20

# ========================
# ROOT PATH
# ========================
SRC = $$PWD/src

# ========================
# INCLUDE PATH (ТОЛЬКО ПАПКИ!)
# ========================
INCLUDEPATH += \
    $$SRC \
    $$SRC/ui \
    $$SRC/ui/widgets \
    $$SRC/ui/effects \
    $$SRC/ui/cockpit \
    $$SRC/ui/dialogs \
    $$SRC/core \
    $$SRC/control \
    $$SRC/simulation

# ========================
# SOURCES
# ========================
SOURCES += \
    $$SRC/core/main.cpp \
    $$SRC/ui/widgets/radarview.cpp \
    $$SRC/ui/effects/circlerendereffect.cpp \
    $$SRC/ui/effects/pingeffect.cpp \
    $$SRC/ui/effects/pulseeffect.cpp \
    $$SRC/ui/effects/solidrendereffect.cpp \
    $$SRC/ui/effects/wavefromcentedeffect.cpp \
    $$SRC/ui/effects/wavetocentereffect.cpp \
    $$SRC/ui/cockpit/mainwindow.cpp \
    src/ui/effects/radiansweepeffect.cpp

# ========================
# HEADERS
# ========================
HEADERS += \
    $$SRC/ui/widgets/radarview.h \
    $$SRC/ui/effects/circlerendereffect.h \
    $$SRC/ui/effects/pingeffect.h \
    $$SRC/ui/effects/pulseeffect.h \
    $$SRC/ui/effects/solidrendereffect.h \
    $$SRC/ui/effects/wavefromcentedeffect.h \
    $$SRC/ui/effects/wavetocentereffect.h \
    $$SRC/ui/cockpit/mainwindow.h \
    src/ui/effects/radiansweepeffect.h

# ========================
# FORMS (UI)
# ========================
FORMS += \
    $$SRC/ui/widgets/radarview.ui \
    $$SRC/ui/cockpit/mainwindow.ui

# ========================
# DEFINES
# ========================
DEFINES += APP_VERSION=\"1.0.0\"
