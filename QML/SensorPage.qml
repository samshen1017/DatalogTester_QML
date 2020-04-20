import QtQuick 2.12
import QtQuick.Controls 2.2

Rectangle {
    id: sensorPage
    width: 300
    height: 600
    Header {
        id: header
        anchors.top: parent.top
        headerText: "Sensor"
    }
    SLabel{
        id: sensors
        textContent: "Sensor List"
        anchors.top: header.bottom
    }


    SMenu {
        id: addSen
        anchors.bottom: modSen.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "AddSensor"
        onButtonClick: {
        }
    }

    SMenu {
        id: modSen
        anchors.bottom: delSen.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "ModifySensor"
        onButtonClick: {
        }
    }

    SMenu {
        id: delSen
        anchors.bottom: getSens.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "DelSensor"
        onButtonClick: {
        }
    }

    SMenu {
        id: getSens
        anchors.bottom: menu.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "GetSensorList"
        onButtonClick: {
        }
    }

    SMenu {
        id: menu
        anchors.bottom: parent.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "Back"
        onButtonClick: {
            pageLoader.source = "Characteristics.qml"
            ble.update = "Back"
        }
    }
}
