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
    quint16 tmp = convertToLSB_ByShort(pb_len + 3);
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

QByteArray ProtobufInterpreter::parseMsg(const QByteArray &message)
{
    qDebug()<<"======== parseMsg ========";
    qDebug()<<message;
    if(!checkProtobuf(message)){
        qDebug()<<message;
        return "checkpackage false.";
    }
    QByteArray pb_str = message.mid(5, message.length() - 9);
    std::string str = pb_str.toStdString();
    SH3H_Response resp;
    if(resp.ParseFromString(str))
    {
        switch(resp.type()){
        case Resp_HeartBeat:
        {
            return QByteArray::number(resp.beatcount());
        }
        case Resp_OK:
            return "OK.";
        case Resp_Error:
            return "Error.";
        case Resp_DeviceInfo:
        {
            if(resp.has_devinfo())
            {
                DeviceInfo info = resp.devinfo();
                std::string info_str =info.DebugString();
                return QByteArray::fromStdString(info_str);
            }else{
                return "Protobuf missing DeviceInfo.";
            }
        }
        default:
            break;
        }
    }
    return "protobuf parse fault.";
}

void ProtobufInterpreter::heartBeat(void)
{
    SH3H_Request req;
    std::string pb_str;
    req.set_type(Req_HeartBeat);
    req.SerializeToString(&pb_str);
    QByteArray msg = createMsg(pb_str);
    setProtocMsg(msg);
    qDebug()<<"heart beat";
}

void ProtobufInterpreter::syncTime(void)
{
    uint now = QDateTime::currentDateTimeUtc().toTime_t();
    SH3H_Request req;
    std::string pb_str;
    req.set_type(Req_SyncTime);
    req.set_currenttime(now);
    req.SerializeToString(&pb_str);
    QByteArray msg = createMsg(pb_str);
    setProtocMsg(msg);
    qDebug()<<"sync time:"<<now;
}

void ProtobufInterpreter::devInfo(void)
{
    SH3H_Request req;
    std::string pb_str;
    req.set_type(Req_DeviceInfo);
    req.SerializeToString(&pb_str);
    QByteArray msg = createMsg(pb_str);
    setProtocMsg(msg);
    qDebug()<<"GetDevInfo";
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

bool ProtobufInterpreter::checkProtobuf(const QByteArray &message)
{

    const char *str = message.data();
    if(str[0] == 0xFE){  // check head
        if(0x01 == str[1]){ //check version
            quint16 length = *(quint16 *)(str + 2);
            if(length == (message.length() - 6)){ // check length
                quint16 calc_crc = usMBCRC16((UCHAR *)str + 4, length - 2);
                quint16 cur_crc =  convertToLSB_ByShort(*(quint16 *)(str + (message.length() - 4)));
                if(calc_crc == cur_crc){ //check crc
                    return true;
                }else{
                    qDebug()<<"check crc failed.";
                }
            }else{
                qDebug()<<"check length failed.";
            }
        }else{
            qDebug()<<"check version failed.";
        }
    }else
    {
        qDebug()<<"check head failed.";
    }
    return false;
}
