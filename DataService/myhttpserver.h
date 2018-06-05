
#ifndef MYHTTPSERVER_H
#define MYHTTPSERVER_H

#include <QObject>
#include <Tufao/HttpServer>
#include <Tufao/HttpServerRequest>
#include <Tufao/HttpServerResponse>
#include <Tufao/HttpServerRequestRouter>

#include "DatabaseOperation.h"

using namespace Tufao;

//user table operation function
bool handleUserRegist(HttpServerRequest &request, HttpServerResponse &response);
bool handleUserLogin(HttpServerRequest &request, HttpServerResponse &response);

class MyHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyHttpServer(QObject *parent = nullptr);

    HttpServer server;
    DatabaseOperation dbo;

public:
    HttpServerRequestRouter router {
        {QRegularExpression{"userRegist"}, handleUserRegist},
        {QRegularExpression{"userLogin"}, handleUserLogin}
    };

signals:

public slots:
    void onRequestReady(Tufao::HttpServerRequest &request,
                        Tufao::HttpServerResponse &response);

};

#endif // MYHTTPSERVER_H
