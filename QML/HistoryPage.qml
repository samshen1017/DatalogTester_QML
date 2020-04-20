import QtQuick 2.12
import QtQuick.Controls 2.2

Rectangle {
    id: historyPage
    width: 300
    height: 600
    Header {
        id: header
        anchors.top: parent.top
        headerText: "History"
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
