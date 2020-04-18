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

public slots:
    void syncTime(void);

signals:
    void msgChanged();

private:
    QByteArray m_message;
    QByteArray createMsg(const std::string &s);
    void setProtocMsg(const QByteArray &message);
};

#endif // PROTOBUFINTERPRETER_H
