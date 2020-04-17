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

    SMenu {
        id: getDev
        anchors.top: header.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/6)
        menuText: "GetDeviceInfo"
        onButtonClick: {

        }
    }
    SMenu {
        id: syncTime
        anchors.top: getDev.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/6)
        menuText: "SyncTime"
        onButtonClick: {
            pb.syncTime()
        }
    }
    SMenu {
        id: menu
        anchors.bottom: parent.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/6)
        menuText: "Disconnect"
        onButtonClick: {
            pageLoader.source = "ScanPage.qml"
        }
    }
}
