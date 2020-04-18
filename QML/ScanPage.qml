/***************************************************************************
**
** Copyright (C) 2013 BlackBerry Limited. All rights reserved.
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.12
import QtQuick.Controls 2.2

Rectangle {
    id: scanPage
    width: 300
    height: 600
    property bool deviceState: ble.state
    onDeviceStateChanged: {
        if (!ble.state)
            info.visible = false;
    }

    Header {
        id: header
        anchors.top: parent.top
        headerText: "Start Discovery"
    }

    ScrollBar{
        id: hbar
        property int value: position * -100
        hoverEnabled: true
        active: hovered || pressed
        height: 30
        policy: ScrollBar.AlwaysOn
        width: parent.width
        orientation: Qt.Horizontal
        anchors.top: header.bottom
        anchors.margins: 5
        position: 1;
        SLabel{
            textContent: parent.value + " db"
            anchors.centerIn: parent
        }
        onValueChanged: ble.rssiFilter = value

    }

    SDialog {
        id: info
        anchors.centerIn: parent
        visible: false
    }

    ListView {
        id: theListView
        width: parent.width
        clip: true

        anchors.top: hbar.bottom
        anchors.bottom: connectToggle.top
        model: ble.devicesList

        delegate: Rectangle {
            id: box
            height:80
            width: parent.width
            color: "lightsteelblue"
            border.width: 2
            border.color: "black"
            radius: 5

            Component.onCompleted: {
                info.visible = false;
                header.headerText = "Select a device";
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ble.scanServices(modelData.deviceAddress);
                    pageLoader.source = "Services.qml"
                }
            }

            SLabel {
                id: deviceName
                textContent: modelData.deviceName
                anchors.top: parent.top
                anchors.topMargin: 5
            }

            SLabel {
                id: deviceRssi
                textContent: modelData.deviceRssi + " db"
                anchors.centerIn: parent
            }

            SLabel {
                id: deviceAddress
                textContent: modelData.deviceAddress
                anchors.bottom: box.bottom
                anchors.bottomMargin: 5
            }
        }
    }

    SMenu {
        id: connectToggle

        menuWidth: parent.width
        anchors.bottom: menu.top
        menuText: { if (ble.devicesList.length)
                visible = true
            else
                visible = false
            if (ble.useRandomAddress)
                "Address type: Random"
            else
                "Address type: Public"
        }

        onButtonClick: ble.useRandomAddress = !ble.useRandomAddress;
    }

    SMenu {
        id: menu
        anchors.bottom: parent.bottom
        menuWidth: parent.width
        menuHeight: (parent.height/8)
        menuText: ble.update
        onButtonClick: {
            ble.startDeviceDiscovery();
            // if startDeviceDiscovery() failed ble.state is not set
            if (ble.state) {
                info.dialogText = "Searching...";
                info.visible = true;
            }
        }
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
    }
}
