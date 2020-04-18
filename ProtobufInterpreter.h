#ifndef PROTOBUFINTERPRETER_H
#define PROTOBUFINTERPRETER_H

#include <QObject>

class ProtobufInterpreter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ProtocMsg READ getProtocMsg WRITE setProtocMsg NOTIFY msgChanged)

public:
    explicit ProtobufInterpreter(QObject *parent = nullptr);
    QString getProtocMsg();

public slots:
    void syncTime(void);

signals:
    void msgChanged();

private:
    QString m_message;
    void setProtocMsg(const QString &message);
};

#endif // PROTOBUFINTERPRETER_H
