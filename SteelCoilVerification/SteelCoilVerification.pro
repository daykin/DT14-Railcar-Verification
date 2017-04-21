#-------------------------------------------------
#
# Project created by QtCreator 2017-02-26T18:30:15
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SteelCoilVerification
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    steelcoil.cpp \
    shipmentschedule.cpp \
    railcar.cpp \
    ocr.cpp

HEADERS  += mainwindow.h \
    steelcoil.h \
    shipmentschedule.h \
    railcar.h \
    ocr.h

FORMS    += mainwindow.ui

DESTDIR = $$PWD/../bin

QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

win32: LIBS += -LC:/Qt/Tools/mingw530_32/i686-w64-mingw32/lib/ -llept -ltesseract -ltiff -ljpeg -lpng -lz -lws2_32
INCLUDEPATH += C:/Qt/Tools/mingw530_32/i686-w64-mingw32/include

win32: LIBS += -LC:/Qt/Tools/mingw530_32/i686-w64-mingw32/install/x86/mingw/lib/ -llibopencv_core320.dll -llibopencv_highgui320.dll -llibopencv_imgcodecs320.dll -llibopencv_imgproc320.dll -llibopencv_text320.dll
INCLUDEPATH += C:/Qt/Tools/mingw530_32/i686-w64-mingw32/install/include

DISTFILES += \
    icon.ico

win32:RC_ICONS += icon.ico
