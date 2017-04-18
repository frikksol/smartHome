#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class ReadDataFromThingSpeak : public QObject
{
    Q_OBJECT
public:
    explicit ReadDataFromThingSpeak(QObject *parent = 0);
    void GetValueForField(QString channelId, QString fieldNumber);

signals:

public slots:
    void replyFinished (QNetworkReply *reply);

private:
   QNetworkAccessManager *manager;
   const QString server{"https://api.thingspeak.com"};
};
