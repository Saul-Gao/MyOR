#include "myhttpserver.h"

MyHttpServer::MyHttpServer(QObject *parent) : QObject(parent)
{
    server.listen(QHostAddress::Any, 6002);
    connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)),
            &router, SLOT(handleRequest(Tufao::HttpServerRequest&,Tufao::HttpServerResponse&)));
}

bool handleRegistVerification(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){
        QByteArray msg = request.readBody();
        QString descript = "注册信息";
        response.writeHead(HttpResponseStatus::OK);
        if (SMSVerification(msg, descript))
        {
            response.write("success");
        }
        else
        {
            response.write("failed");
        }
        response.end();
    });
    return true;
}

bool handleLoginVerification(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){
        QByteArray msg = request.readBody();
        QString descript = "登录验证";
        response.writeHead(HttpResponseStatus::OK);
        if (SMSVerification(msg, descript))
        {
            response.write("success");
        }
        else
        {
            response.write("failed");
        }
        response.end();
    });
    return true;
}

bool handleRegistAliVerification(HttpServerRequest &request, HttpServerResponse &response)
{
    QObject::connect(&request, &HttpServerRequest::end, [&request, &response](){
        QByteArray msg = request.readBody();
        QString descript = "ali注册验证";
        response.writeHead(HttpResponseStatus::OK);
        if (SMSAliVerification(msg, descript))
        {
            response.write("success");
        }
        else
        {
            response.write("failed");
        }
        response.end();
    });
    return true;
}

size_t write_func(void *buffer, size_t size, size_t nmemb, void *stream)
{
    strncpy((char *)stream, (char *)buffer, size * nmemb);
    return size * nmemb;
}

bool SMSVerification(QByteArray &msg, QString &descript)
{
    QJsonParseError jsonError;
    QJsonDocument msgJsonDoc = QJsonDocument::fromJson(msg, &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
    {
        qDebug() << "json error";
        return false;
    }

    if (!msgJsonDoc.isObject())
    {
        qDebug() << "json error";
        return false;
    }

    QJsonObject msgJsonObject = msgJsonDoc.object();
    QString code = msgJsonObject["code"].toString();
    QString phone = msgJsonObject["phone"].toString();

    QString verificationStr = QString("{"
                                "\"id\" : 1,"
                                "\"method\" : \"send\","
                                "\"params\" : {"
                                    "\"userid\" : \"200216\","
                                    "\"password\" : \"ab123456\","
                                    "\"submit\" : [ {"
                                        "\"content\" : \"验证码为%1。【淘金者平台】%2\","
                                        "\"phone\" : \"%3\""
                                    "}]"
                                "}"
                               "}").arg(code).arg(descript).arg(phone);

    qDebug() << verificationStr;
    CURL *myCurl = curl_easy_init();
    if (!myCurl)
    {
        qDebug() << "curl init failed";
        return false;
    }

    curl_easy_setopt(myCurl, CURLOPT_POST, 1);
    curl_easy_setopt(myCurl, CURLOPT_URL, "http://112.74.139.4:8002/sms3_api/jsonapi/jsonrpc2.jsp");
    struct curl_slist *headers = curl_slist_append(NULL, "Content-Type:application/json;charset=UTF-8");
    curl_easy_setopt(myCurl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(myCurl, CURLOPT_POSTFIELDS, verificationStr.toUtf8().data());

    char buf[4096] = {0};
    curl_easy_setopt(myCurl, CURLOPT_WRITEDATA, (void *)buf);
    curl_easy_setopt(myCurl, CURLOPT_WRITEFUNCTION, write_func);

    CURLcode curlCode = curl_easy_perform(myCurl);
    if(curlCode != CURLE_OK)
    {
        qDebug() << "curl perform failed" << curlCode;
        curl_easy_cleanup(myCurl);
        return false;
    }

    long responseCode = 0;
    curl_easy_getinfo(myCurl, CURLINFO_RESPONSE_CODE, &responseCode);
    if (responseCode < 200 || responseCode >=300 || strlen(buf) == 0)
    {
        qDebug() << "response error";
        curl_easy_cleanup(myCurl);
        return false;
    }

    curl_easy_cleanup(myCurl);
    qDebug() << buf;
    const char *result = strstr(buf, "\"info\":\"成功\"");
    if (result)
        return true;
    else
        return false;
}


bool SMSAliVerification(QByteArray &msg, QString &descript)
{
    QJsonParseError jsonError;
    QJsonDocument msgJsonDoc = QJsonDocument::fromJson(msg, &jsonError);
    if (jsonError.error != QJsonParseError::NoError)
    {
        qDebug() << "json error";
        return false;
    }

    if (!msgJsonDoc.isObject())
    {
        qDebug() << "json error";
        return false;
    }

    QJsonObject msgJsonObject = msgJsonDoc.object();
    QString code = msgJsonObject["code"].toString();
    QString phone = msgJsonObject["phone"].toString();
    QDateTime dateTime = QDateTime::currentDateTimeUtc();

    QString verificationStr = QString("{"
                                "\"AccessKeyId\" : \"LTAImkpbH8ZRx2PQ\","
                                "\"Timestamp\" : \"%1\","
                                "\"SignatureMethod\" : \"HMAC-SHA1\","
                                "\"SignatureVersion\" : \"1.0\","
                                "\"SignatureNonce\" : \"%2\","
                                "\"Action\" : \"SendSms\","
                                "\"Version\" : \"2017-05-25\","
                                "\"RegionId\" : \"cn-hangzhou\","
                                "\"PhoneNumbers\" : \"%3\","
                                "\"SignName\" : \"云通信\","
                                "\"TemplateCode\" : \"SMS_0000\""
                               "}").arg(dateTime).arg(descript).arg(phone);

    qDebug() << verificationStr;
    CURL *myCurl = curl_easy_init();
    if (!myCurl)
    {
        qDebug() << "curl init failed";
        return false;
    }

    curl_easy_setopt(myCurl, CURLOPT_POST, 1);
    curl_easy_setopt(myCurl, CURLOPT_URL, "http://112.74.139.4:8002/sms3_api/jsonapi/jsonrpc2.jsp");
    struct curl_slist *headers = curl_slist_append(NULL, "Content-Type:application/json;charset=UTF-8");
    curl_easy_setopt(myCurl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(myCurl, CURLOPT_POSTFIELDS, verificationStr.toUtf8().data());

    char buf[4096] = {0};
    curl_easy_setopt(myCurl, CURLOPT_WRITEDATA, (void *)buf);
    curl_easy_setopt(myCurl, CURLOPT_WRITEFUNCTION, write_func);

    CURLcode curlCode = curl_easy_perform(myCurl);
    if(curlCode != CURLE_OK)
    {
        qDebug() << "curl perform failed" << curlCode;
        curl_easy_cleanup(myCurl);
        return false;
    }

    long responseCode = 0;
    curl_easy_getinfo(myCurl, CURLINFO_RESPONSE_CODE, &responseCode);
    if (responseCode < 200 || responseCode >=300 || strlen(buf) == 0)
    {
        qDebug() << "response error";
        curl_easy_cleanup(myCurl);
        return false;
    }

    curl_easy_cleanup(myCurl);
    qDebug() << buf;
    const char *result = strstr(buf, "\"info\":\"成功\"");
    if (result)
        return true;
    else
        return false;

}
