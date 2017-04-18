#include "ReadDataFromThingSpeak.h"

ReadDataFromThingSpeak::ReadDataFromThingSpeak(QObject *parent) : QObject(parent)
{

}

void ReadDataFromThingSpeak::GetValueForField(QString channelId, QString fieldNumber)
{
    QUrl url = (server + "/channels/" + channelId + "/fields/" + fieldNumber + ".json?results=2");
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(url));
}

void ReadDataFromThingSpeak::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        qDebug() << reply->readAll();

        QFile *file = new QFile("C:/Qt/Dummy/downloaded.txt");
        if(file->open(QFile::Append))
        {
            file->write(reply->readAll());
            file->flush();
            file->close();
        }
        delete file;
    }

    reply->deleteLater();
}
