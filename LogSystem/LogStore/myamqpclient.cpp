#include "myamqpclient.h"

MyAmqpClient::MyAmqpClient(string _host, int _port, string _username, string _password, string _queue)
{
    mChannel = AmqpClient::Channel::Create(_host, _port, _username, _password);

    mQueue = _queue;
    mChannel->DeclareQueue(mQueue, false, true, false, false);

    mConsumer = mChannel->BasicConsume(mQueue, "", true, true, false);
}

MyAmqpClient::~MyAmqpClient()
{

}

void MyAmqpClient::mqToES(const char *_url)
{
    mCurl = curl_easy_init();
    if (!mCurl)
    {
        qDebug() << "curl init failed";
        return;
    }

    curl_easy_setopt(mCurl, CURLOPT_POST, 1);
    curl_easy_setopt(mCurl, CURLOPT_URL, _url);
    struct curl_slist *headers = curl_slist_append(NULL, "Content-Type:application/json;charset=UTF-8");
    curl_easy_setopt(mCurl, CURLOPT_HTTPHEADER, headers);


    while (1)
    {
        AmqpClient::Envelope::ptr_t envelope = mChannel->BasicConsumeMessage(mConsumer);
        string json = envelope->Message()->Body();
        qDebug() << json.c_str();
        curl_easy_setopt(mCurl, CURLOPT_POSTFIELDS, json.c_str());
        curl_easy_perform(mCurl);
    }

    curl_easy_cleanup(mCurl);
}


