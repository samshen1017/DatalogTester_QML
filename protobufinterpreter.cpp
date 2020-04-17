#include "protobufinterpreter.h"
#include "protocols/DLF.pb.h"
#include <QDebug>


ProtobufInterpreter::ProtobufInterpreter(QObject *parent) : QObject(parent)
{
}


void ProtobufInterpreter::syncTime(void)
{
    setProtocMsg("HelloWorld!");
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
