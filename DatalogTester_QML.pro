QT += quick bluetooth

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BlePort/BleDevice.cpp \
        BlePort/characteristicinfo.cpp \
        BlePort/deviceinfo.cpp \
        BlePort/serviceinfo.cpp \
        main.cpp \
        protobufinterpreter.cpp \
        protocols/DLF.pb.cc \
        protocols/Device.pb.cc \
        protocols/History.pb.cc \
        protocols/Modbus.pb.cc \
        protocols/Sensor.pb.cc \
        protocols/Task.pb.cc

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    BlePort/BleDevice.h \
    BlePort/characteristicinfo.h \
    BlePort/deviceinfo.h \
    BlePort/serviceinfo.h \
    protobufinterpreter.h \
    protocols/DLF.pb.h \
    protocols/Device.pb.h \
    protocols/History.pb.h \
    protocols/Modbus.pb.h \
    protocols/Sensor.pb.h \
    protocols/Task.pb.h

INCLUDEPATH += protocols/libpb3.3.0/include

LIBS += -L$$PWD/protocols/libpb3.3.0/lib  -lprotobuf -lprotobuf-lite -lprotoc

#LIBS += -lprotobuf-lite

#LIBS += -lprotoc

ANDROID_EXTRA_LIBS += \
        $$PWD/protocols/libpb3.3.0/lib/libprotobuf.so   \
        $$PWD/protocols/libpb3.3.0/lib/libprotobuf-lite.so  \
        $$PWD/protocols/libpb3.3.0/lib/libprotoc.so
