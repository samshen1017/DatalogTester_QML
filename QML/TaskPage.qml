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
        id: newTask
        anchors.bottom: menu.top
        menuWidth: delTask.width
        menuHeight: (parent.height/10)
        menuText: "NewTask"
        onButtonClick: {

        }
    }

    SMenu {
        id: delTask
        anchors.bottom: updateTasks.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "DelTask"
        onButtonClick: {

        }
    }

    SMenu {
        id: updateTasks
        anchors.bottom: menu.top
        menuWidth: parent.width
        menuHeight: (parent.height/10)
        menuText: "updateTasks"
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
