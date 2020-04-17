import QtQuick 2.12
import QtQuick.Window 2.12
//import QtQuick.Controls 2.2
import "QML"

Window {
    visible: true
    width: 300
    height: 600

    ScanPage{
        id: page_scan
        anchors.fill: parent
    }
}
