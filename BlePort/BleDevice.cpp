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

#include "BleDevice.h"

#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothservicediscoveryagent.h>
#include <QDebug>
#include <QList>
#include <QMetaEnum>
#include <QTimer>

#define SERV_UUID "0000f101-0001-0001-0001-03ff00000001"
#define CHAR_W_UUID "0000f102-0001-0001-0001-03ff00000001"
#define CHAR_N_UUID "0000f103-0001-0001-0001-03ff00000001"


BleDevice::BleDevice()
{
    //! [les-devicediscovery-1]
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BleDevice::addDevice);
    connect(discoveryAgent, QOverload<QBluetoothDeviceDiscoveryAgent::Error>::of(&QBluetoothDeviceDiscoveryAgent::error),
            this, &BleDevice::deviceScanError);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &BleDevice::deviceScanFinished);
    //! [les-devicediscovery-1]

    setUpdate("Search");
}

BleDevice::~BleDevice()
{
    delete discoveryAgent;
    delete controller;
    qDeleteAll(devices);
    qDeleteAll(m_services);
    qDeleteAll(m_characteristics);
    devices.clear();
    m_services.clear();
    m_characteristics.clear();
}

void BleDevice::startDeviceDiscovery()
{
    qDeleteAll(devices);
    devices.clear();
    emit devicesUpdated();

    setUpdate("Scanning for devices ...");
    //! [les-devicediscovery-2]
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    //! [les-devicediscovery-2]

    if (discoveryAgent->isActive()) {
        m_deviceScanState = true;
        Q_EMIT stateChanged();
    }
}

//! [les-devicediscovery-3]
void BleDevice::addDevice(const QBluetoothDeviceInfo &info)
{
    if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
        setUpdate("Last device added: " + info.name());
}
//! [les-devicediscovery-3]

void BleDevice::deviceScanFinished()
{
    const QList<QBluetoothDeviceInfo> foundDevices = discoveryAgent->discoveredDevices();
    for (auto nextDevice : foundDevices)
        if (nextDevice.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
        {
            if(nextDevice.rssi() > m_rssiFilter){
                devices.append(new DeviceInfo(nextDevice));
            }
        }

    emit devicesUpdated();
    m_deviceScanState = false;
    emit stateChanged();
    if (devices.isEmpty())
        setUpdate("No Low Energy devices found...");
    else
        setUpdate("Done! Scan Again!");
}

QVariant BleDevice::getDevices()
{
    return QVariant::fromValue(devices);
}

QVariant BleDevice::getServices()
{
    return QVariant::fromValue(m_services);
}

QVariant BleDevice::getCharacteristics()
{
    return QVariant::fromValue(m_characteristics);
}

QString BleDevice::getUpdate()
{
    return m_message;
}

int BleDevice::getRssiFilter()
{
    return m_rssiFilter;
}

QByteArray BleDevice::getMsg()
{
    return m_msgArray;
}

void BleDevice::scanServices(const QString &address)
{
    // We need the current device for service discovery.

    for (auto d: qAsConst(devices)) {
        if (auto device = qobject_cast<DeviceInfo *>(d)) {
            if (device->getAddress() == address ) {
                currentDevice.setDevice(device->getDevice());
                break;
            }
        }
    }

    if (!currentDevice.getDevice().isValid()) {
        qWarning() << "Not a valid device";
        return;
    }

    qDeleteAll(m_characteristics);
    m_characteristics.clear();
    emit characteristicsUpdated();
    qDeleteAll(m_services);
    m_services.clear();
    emit servicesUpdated();

    setUpdate("Back\n(Connecting to device...)");

    if (controller && m_previousAddress != currentDevice.getAddress()) {
        controller->disconnectFromDevice();
        delete controller;
        controller = nullptr;
    }

    //! [les-controller-1]
    if (!controller) {
        // Connecting signals and slots for connecting to LE services.
        controller = QLowEnergyController::createCentral(currentDevice.getDevice());
        connect(controller, &QLowEnergyController::connected,
                this, &BleDevice::deviceConnected);
        connect(controller, QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),
                this, &BleDevice::errorReceived);
        connect(controller, &QLowEnergyController::disconnected,
                this, &BleDevice::deviceDisconnected);
        connect(controller, &QLowEnergyController::serviceDiscovered,
                this, &BleDevice::addLowEnergyService);
        connect(controller, &QLowEnergyController::discoveryFinished,
                this, &BleDevice::serviceScanDone);
    }

    if (isRandomAddress())
        controller->setRemoteAddressType(QLowEnergyController::RandomAddress);
    else
        controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    controller->connectToDevice();
    //! [les-controller-1]

    m_previousAddress = currentDevice.getAddress();
}

void BleDevice::addLowEnergyService(const QBluetoothUuid &serviceUuid)
{
    //! [les-service-1]
    QLowEnergyService *service = controller->createServiceObject(serviceUuid);
    if (!service) {
        qWarning() << "Cannot create service for uuid";
        return;
    }
    //! [les-service-1]
    auto serv = new ServiceInfo(service);
    m_services.append(serv);

    emit servicesUpdated();
}
//! [les-service-1]

void BleDevice::serviceScanDone()
{
    setUpdate("Back\n(Service scan done!)");
    // force UI in case we didn't find anything
    if (m_services.isEmpty())
        emit servicesUpdated();
}

void BleDevice::connectToService(const QString &uuid)
{
    QLowEnergyService *service = nullptr;
    for (auto s: qAsConst(m_services)) {
        auto serviceInfo = qobject_cast<ServiceInfo *>(s);
        if (!serviceInfo)
            continue;

        if (serviceInfo->getUuid() == uuid) {
            service = serviceInfo->service();
            break;
        }
    }

    if (!service)
        return;

    qDeleteAll(m_characteristics);
    m_characteristics.clear();
    emit characteristicsUpdated();

    if (service->state() == QLowEnergyService::DiscoveryRequired) {
        //! [les-service-3]
        connect(service, &QLowEnergyService::stateChanged,
                this, &BleDevice::serviceDetailsDiscovered);
        connect(service, &QLowEnergyService::characteristicChanged,
                this, &BleDevice::msgReceivedHandle);

        service->discoverDetails();
        setUpdate("Back\n(Discovering details...)");
        //! [les-service-3]
        return;
    }

    //discovery already done
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);
        if(cInfo->getUuid() == CHAR_N_UUID){
            QLowEnergyCharacteristic char_notify = cInfo->getCharacteristic();
            openNotify(service, char_notify);
        }
    }
    QTimer::singleShot(0, this, &BleDevice::characteristicsUpdated);
}

void BleDevice::openNotify(QLowEnergyService *service, const QLowEnergyCharacteristic &ch)
{
    Q_ASSERT(service !=nullptr);
    QLowEnergyDescriptor desc = ch.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
    service->writeDescriptor(desc, QByteArray::fromHex("0100"));
}

void BleDevice::deviceConnected()
{
    setUpdate("Back\n(Discovering services...)");
    connected = true;
    //! [les-service-2]
    controller->discoverServices();
    //! [les-service-2]
}

void BleDevice::errorReceived(QLowEnergyController::Error /*error*/)
{
    qWarning() << "Error: " << controller->errorString();
    setUpdate(QString("Back\n(%1)").arg(controller->errorString()));
}

void BleDevice::setUpdate(const QString &message)
{
    m_message = message;
    emit updateChanged();
}

void BleDevice::disconnectFromDevice()
{
    // UI always expects disconnect() signal when calling this signal
    // TODO what is really needed is to extend state() to a multi value
    // and thus allowing UI to keep track of controller progress in addition to
    // device scan progress

    if (controller->state() != QLowEnergyController::UnconnectedState)
        controller->disconnectFromDevice();
    else
        deviceDisconnected();
}
#include <ProtobufInterpreter.h>
static QByteArray msgBuffer;
void BleDevice::msgReceivedHandle(const QLowEnergyCharacteristic &info, const QByteArray &value)
{
    qDebug()<<"======== msgReceivedHandle ========";

    QByteArray tail;
    tail.append(0x0D);
    tail.append(0x0A);

    if((value.at(0) == 0xFE) && msgBuffer.isEmpty())
    {
        msgBuffer.append(value);
    }
    else if(value.endsWith(tail) && !msgBuffer.isEmpty())
    {
        ProtobufInterpreter m_pb;
        msgBuffer.append(value);
        m_msgArray = m_pb.parseMsg(msgBuffer);
        emit msgReceived();
        msgBuffer.clear();
    }
    else if(!msgBuffer.isEmpty())
    {
        msgBuffer.append(value);
    }
}

void BleDevice::sendMsg(const QByteArray &msg)
{
    qDebug()<<"Send:"<<hex<<msg;
    //0000f101-0001-0001-0001-03ff00000001
    QList<QObject *>::ConstIterator serv_i;
    for(serv_i = m_services.begin(); serv_i!=m_services.end(); ++serv_i){
        ServiceInfo *servInfo = static_cast<ServiceInfo *>(*serv_i);
        if(servInfo->getUuid() == SERV_UUID)
        {
            QLowEnergyService *service = servInfo->service();
            QList<QObject *>::ConstIterator char_i;
            for(char_i = m_characteristics.begin(); char_i!= m_characteristics.end(); ++char_i)
            {
                CharacteristicInfo *charInfo = static_cast<CharacteristicInfo *>(*char_i);
                if(charInfo->getUuid() == CHAR_W_UUID)
                {
                    QLowEnergyCharacteristic char_write = charInfo->getCharacteristic();
                    service->writeCharacteristic(char_write, msg, QLowEnergyService::WriteWithResponse);
                }
            }
        }
    }
}

void BleDevice::deviceDisconnected()
{
    qWarning() << "Disconnect from device";
    emit disconnected();
}

void BleDevice::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    if (newState != QLowEnergyService::ServiceDiscovered) {
        // do not hang in "Scanning for characteristics" mode forever
        // in case the service discovery failed
        // We have to queue the signal up to give UI time to even enter
        // the above mode
        if (newState != QLowEnergyService::DiscoveringServices) {
            QMetaObject::invokeMethod(this, "characteristicsUpdated",
                                      Qt::QueuedConnection);
        }
        return;
    }

    auto service = qobject_cast<QLowEnergyService *>(sender());
    if (!service)
        return;



    //! [les-chars]
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);
        if(cInfo->getUuid() == CHAR_N_UUID){
            QLowEnergyCharacteristic char_notify = cInfo->getCharacteristic();
            openNotify(service, char_notify);
        }
    }
    //! [les-chars]

    emit characteristicsUpdated();
}

void BleDevice::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
        setUpdate("The Bluetooth adaptor is powered off, power it on before doing discovery.");
    else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
        setUpdate("Writing or reading from the device resulted in an error.");
    else {
        static QMetaEnum qme = discoveryAgent->metaObject()->enumerator(
                    discoveryAgent->metaObject()->indexOfEnumerator("Error"));
        setUpdate("Error: " + QLatin1String(qme.valueToKey(error)));
    }

    m_deviceScanState = false;
    emit devicesUpdated();
    emit stateChanged();
}

bool BleDevice::state()
{
    return m_deviceScanState;
}

bool BleDevice::hasControllerError() const
{
    return (controller && controller->error() != QLowEnergyController::NoError);
}

bool BleDevice::isRandomAddress() const
{
    return randomAddress;
}

void BleDevice::setRandomAddress(bool newValue)
{
    randomAddress = newValue;
    emit randomAddressChanged();
}

void BleDevice::setRssiFilter(int value)
{
    m_rssiFilter = value;
}
