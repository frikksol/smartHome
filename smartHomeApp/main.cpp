#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ReadDataFromThingSpeak.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    ReadDataFromThingSpeak data;
    data.GetValueForField("221479", "1");

    return app.exec();
}
