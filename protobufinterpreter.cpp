#include "protobufinterpreter.h"
#include "protocols/DLF.pb.h"
#include <QDebug>


ProtobufInterpreter::ProtobufInterpreter(QObject *parent) : QObject(parent)
{
}


void ProtobufInterpreter::syncTime(void)
{
    QString msg;
    msg.append(0xFE);
    msg.append(0x01);
    msg.append(0x00);
    msg.append(0x0D);
    msg.append(0x0A);
    setProtocMsg(msg);
}

QString ProtobufInterpreter::getProtocMsg()
{
    return m_message;
}

void ProtobufInterpreter::setProtocMsg(const QString &message)
{
    m_message = message;
    emit msgChanged();
}
