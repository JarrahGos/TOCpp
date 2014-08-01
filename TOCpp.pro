TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
QT += qml quick widgets

SOURCES += \
    src/CheckOut.cpp \
    src/Interface.cpp \
    src/Person.cpp \
    src/PersonDatabase.cpp \
    src/Product.cpp \
    src/ProductDatabase.cpp \
    src/WorkingUser.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
