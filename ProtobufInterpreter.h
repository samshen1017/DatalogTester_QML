#ifndef PROTOBUFINTERPRETER_H
#define PROTOBUFINTERPRETER_H

#include <QObject>

class ProtobufInterpreter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray ProtocMsg READ getProtocMsg WRITE setProtocMsg NOTIFY msgChanged)

public:
    explicit ProtobufInterpreter(QObject *parent = nullptr);
    QByteArray getProtocMsg();
    QByteArray parseMsg(const QByteArray &amessage);

public slots:
    void heartBeat(void);
    void syncTime(void);
    void devInfo(void);

signals:
    void msgChanged();

private:
    QByteArray m_message;
    QByteArray createMsg(const std::string &s);
    void setProtocMsg(const QByteArray &message);
    bool checkProtobuf(const QByteArray &message);
//    bool checkHead(const QByteArray &message);
//    bool checkVersion(const QByteArray &message);
//    bool checkLength(const QByteArray &message);
//    bool checkCRC(const QByteArray &message);
};

#endif // PROTOBUFINTERPRETER_H
