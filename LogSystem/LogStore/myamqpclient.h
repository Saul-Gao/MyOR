#ifndef MYAMQPCLIENT_H
#define MYAMQPCLIENT_H

#include <string>
#include <QDebug>
#include "SimpleAmqpClient/SimpleAmqpClient.h"
#include "curl/curl.h"

using std::string;

class MyAmqpClient
{
public:
    MyAmqpClient(string _host, int _port, string _username, string _password, string _queue);
    ~MyAmqpClient();
public:
    void mqToES(const char *_url);
public:
    AmqpClient::Channel::ptr_t mChannel;
    string mQueue;
    string mConsumer;
    CURL *mCurl;
};

#endif // MYAMQPCLIENT_H
