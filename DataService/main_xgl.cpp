
#include <QCoreApplication>
#include "myhttpserver.h"

int main_xgl(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    new MyHttpServer;
    return app.exec();
}

#include <QCoreApplication>
#include <Tufao/HttpServerRequestRouter>
#include <Tufao/HttpServer>
using namespace Tufao;


int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    HttpServerRequestRouter router {
        {QRegularExpression{"user"}, handleUser},
        {QRegularExpression{"order"}, handleOrder},
        {QRegularExpression{""}, handleOther},
    };

    HttpServer server;
    server.listen(QHostAddress::Any, 9999);
    QObject::connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)),
                     &router, SLOT(handleRequest(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)));

    return app.exec();
}

void _handleBuy(HttpServerRequest& req, HttpServerResponse& resp) {
    QByteArray buf = req.readBody();
    qDebug() << buf;

    resp.writeHead(HttpResponseStatus::OK);
    resp.end("POST OK");
}

bool handleBuy(HttpServerRequest& req, HttpServerResponse& resp) {
    QObject::connect(&req, &HttpServerRequest::end, [&](){
        _handleBuy(req, resp);
    });
    return true;
}
