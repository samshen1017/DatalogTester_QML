import QtQuick 2.12
import QtQuick.Controls 2.2

Rectangle {
    id:taskPage
    width: 300
    height: 600
    Header {
        id: header
        anchors.top: parent.top
        headerText: "Task"
    }

    SLabel{
        id: tasks
        textContent: "Task List"
        anchors.top: header.bottom
    }

    SMenu {
        id: updateTasks
        anchors.bottom: newTask.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "update Tasks"
        onButtonClick: {

        }
    }
    SMenu {
        id: newTask
        anchors.bottom: menu.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "New Task"
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
