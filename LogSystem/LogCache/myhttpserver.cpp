#include "myhttpserver.h"

MyAmqpClient programLogClient("127.0.0.1", 5672, "guest", "guest", "programLogQueue");

MyHttpServer::MyHttpServer(QObject *parent) : QObject(parent)
{
    server.listen(QHostAddress::Any, 6001);
    connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)),
            &router, SLOT(handleRequest(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)));
}

bool handleDataLog(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){

    });
    return true;
}

bool handleProgramLog(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){
        QByteArray json = request.readBody();
        qDebug() << json;
        programLogClient.sendToMQ(json);
        response.writeHead(HttpResponseStatus::OK);
        response.write("test ok");
        response.end();
    });
    return true;
}
