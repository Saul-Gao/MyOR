#include "myhttpserver.h"

MyHttpServer::MyHttpServer(QObject *parent) : QObject(parent)
{
    server.listen(QHostAddress::Any, 9999);
    connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)),
            &router, SLOT(handleRequest(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)));
}

bool handleUserRegist(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){
        QString postData = request.readBody();
        qDebug() << postData;
    });
    return true;
}

bool handleUserLogin(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&](){

    });
    return true;
}

void MyHttpServer::onRequestReady(HttpServerRequest &request, HttpServerResponse &response)
{
    response.writeHead(HttpResponseStatus::OK);
    response.write("write 1");
    response.write("write 2");
    response.end("hello world");
}

