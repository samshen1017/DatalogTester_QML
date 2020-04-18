#include "ProtobufInterpreter.h"
#include "protocols/DLF.pb.h"
#include <QDebug>
#include <QDateTime>
#include "tools/mbcrc.h"


#define PROTOC_MAGNUM_LEN 1
#define PROTOC_VER_LEN 1
#define PROTOC_LENGTH_LEN 2
#define PROTOC_CMD_LEN 1
#define PROTOC_CRC_LEN 2
#define PROTOC_TAIL_LEN 2

#define PROTOC_MAGIC_NUMBER (0xFE)
#define PROTOC_PB_VER (0x01)
#define PROTOC_PB_CMD (0x0A)

using namespace com::shanghai3h::protobuf;

ProtobufInterpreter::ProtobufInterpreter(QObject *parent) : QObject(parent)
{

}

QByteArray ProtobufInterpreter::createMsg(const std::string &s)
{
    QByteArray array, head;
    quint32 pb_len = s.length();
    head.append(PROTOC_MAGIC_NUMBER);
    head.append(PROTOC_PB_VER);
    quint16 tmp = pb_len + 3;
    head.append((char *)&tmp, 2);
    array.append(PROTOC_PB_CMD);
    array.append(QByteArray::fromStdString(s));
    quint16 crc = usMBCRC16((UCHAR *)(array.data()), pb_len +1);
    array.append((char *)&crc, 2);
    array.append(0x0D);
    array.append(0x0A);
    array.insert(0, head);
    return array;
}



void ProtobufInterpreter::syncTime(void)
{
    uint now = QDateTime::currentDateTimeUtc().toTime_t();
    SH3H_Request req;
    std::string pb_str;
    req.set_type(Req_SyncTime);
    req.set_currenttime(now);
    qDebug()<<"sync time:"<<now;
    req.SerializeToString(&pb_str);
    QByteArray msg = createMsg(pb_str);
    setProtocMsg(msg);
}

QByteArray ProtobufInterpreter::getProtocMsg()
{
    return m_message;
}

void ProtobufInterpreter::setProtocMsg(const QByteArray &message)
{
    m_message = message;
    emit msgChanged();
}
