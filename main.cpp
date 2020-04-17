#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "BlePort/BleDevice.h"
#include "protobufinterpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    BleDevice d;
    ProtobufInterpreter pbInter;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("ble", &d);
    engine.rootContext()->setContextProperty("pb", &pbInter);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
