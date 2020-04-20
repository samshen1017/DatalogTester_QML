import QtQuick 2.12
import QtQuick.Controls 2.2

Rectangle {
    id: devicePage
    width: 300
    height: 600
    Header {
        id: header
        anchors.top: parent.top
        headerText: "Device"
    }

    SLabel{
        id: devInfo
        anchors.top: header.bottom
        anchors.topMargin: 5
        textContent:ble.msg
    }

    Connections{
        target: pb
        onMsgChanged:{
            ble.sendMsg(pb.ProtocMsg)
        }
    }

    SMenu {
        id: heartbeat
        anchors.bottom: getDev.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "HeartBeat"
        onButtonClick: {
            pb.heartBeat()
        }
    }

    SMenu {
        id: getDev
        anchors.bottom: syncTime.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "GetDeviceInfo"
        onButtonClick: {
            pb.devInfo()
        }
    }

    SMenu {
        id: syncTime
        anchors.bottom: menu.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "SyncTime"
        onButtonClick: {
            pb.syncTime()
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
