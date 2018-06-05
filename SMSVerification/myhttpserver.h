#ifndef MYHTTPSERVER_H
#define MYHTTPSERVER_H

#include <QObject>
#include <Tufao/HttpServer>
#include <Tufao/HttpServerRequest>
#include <Tufao/HttpServerResponse>
#include <Tufao/HttpServerRequestRouter>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <curl/curl.h>
#include <QDateTime>

using namespace Tufao;

bool handleRegistVerification(HttpServerRequest &request, HttpServerResponse &response);
bool handleLoginVerification(HttpServerRequest &request, HttpServerResponse &response);
bool handleRegistAliVerification(HttpServerRequest &request, HttpServerResponse &response);

bool SMSVerification(QByteArray &msg, QString &descript);
bool SMSAliVerification(QByteArray &msg, QString &descript);

class MyHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyHttpServer(QObject *parent = nullptr);

signals:

public slots:

private:
    HttpServer server;
    HttpServerRequestRouter router{
        {QRegularExpression{"registVerification"}, handleRegistVerification},
        {QRegularExpression{"loginVerification"}, handleLoginVerification},
        {QRegularExpression{"registAliVerification"}, handleRegistAliVerification}
    };
};

#endif // MYHTTPSERVER_H
