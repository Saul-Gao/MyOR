#ifndef MYAMQPCLIENT_H
#define MYAMQPCLIENT_H

#include <string>
#include <QByteArray>
#include "SimpleAmqpClient/SimpleAmqpClient.h"

using std::string;

class MyAmqpClient
{
public:
    MyAmqpClient(string _host, int _port, string _username, string _password, string _queue);
    ~MyAmqpClient();
private:
    AmqpClient::Channel::ptr_t mChannel;
    string mQueue;
public:
    void sendToMQ(QByteArray msg);
};

#endif // MYAMQPCLIENT_H
