#include "myamqpclient.h"

MyAmqpClient::MyAmqpClient(string _host, int _port, string _username, string _password, string _queue)
{
    mChannel = AmqpClient::Channel::Create(_host, _port, _username, _password);
    mQueue = _queue;
    mChannel->DeclareQueue(mQueue, false, true, false, false);
}

MyAmqpClient::~MyAmqpClient()
{

}

void MyAmqpClient::sendToMQ(QByteArray msg)
{
    mChannel->BasicPublish("", mQueue, AmqpClient::BasicMessage::Create(msg.data()));
}
