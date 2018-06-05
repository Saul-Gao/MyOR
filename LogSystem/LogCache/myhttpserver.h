#ifndef MYHTTPSERVER_H
#define MYHTTPSERVER_H

#include <QObject>
#include <QDebug>
#include <Tufao/HttpServer>
#include <Tufao/HttpServerRequest>
#include <Tufao/HttpServerResponse>
#include <Tufao/HttpServerRequestRouter>

#include "myamqpclient.h"

using namespace Tufao;

extern MyAmqpClient programLogClient;

bool handleDataLog(HttpServerRequest &request, HttpServerResponse &response);
bool handleProgramLog(HttpServerRequest &request, HttpServerResponse &response);

class MyHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyHttpServer(QObject *parent = nullptr);

signals:

public slots:

public:
    HttpServer server;
    HttpServerRequestRouter router {
      {QRegularExpression{"dataLog"}, handleDataLog},
      {QRegularExpression{"programLog"}, handleProgramLog}
    };

private:

};

#endif // MYHTTPSERVER_H
