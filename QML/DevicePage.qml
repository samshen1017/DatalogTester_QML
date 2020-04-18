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

    Connections{
        target: pb
        onMsgChanged:{
            ble.sendMsg(pb.ProtocMsg)
        }
    }
    Connections{
        target: ble
        onMsgReceived: {
            console.debug(ble.msg);
        }
    }
    SMenu {
        id: getDev
        anchors.bottom: syncTime.top
        menuWidth: parent.width
        menuHeight: (parent.height/8)
        menuText: "GetDeviceInfo"
        onButtonClick: {

        }
    }
    SMenu {
        id: syncTime
        anchors.bottom: menu.top
        menuWidth: parent.width
        menuHeight: (parent.height/8)
        menuText: "SyncTime"
        onButtonClick: {
            pb.syncTime()
        }
    }

    SMenu {
        id: menu
        anchors.bottom: parent.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/8)
        menuText: "Back"
        onButtonClick: {
            pageLoader.source = "Characteristics.qml"
            ble.update = "Back"
        }
    }
}
