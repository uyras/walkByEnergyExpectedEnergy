TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()


LIBS += -L$$PWD/../partsEngine/ -lPartsEngine

INCLUDEPATH += $$PWD/../partsEngine
DEPENDPATH += $$PWD/../partsEngine

PRE_TARGETDEPS += $$PWD/../partsEngine/libPartsEngine.a

DISTFILES += \
    README.md \
    10_10_40_1.dat \
    make_e_graph.py
