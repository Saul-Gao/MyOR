#include <QCoreApplication>

#include "myamqpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication core(argc, argv);
    curl_global_init(CURL_GLOBAL_DEFAULT);

    MyAmqpClient programLogClient("127.0.0.1", 5672, "guest", "guest", "programLogQueue");
    programLogClient.mqToES("http://192.168.1.123:9200/programlog/_doc?pretty");

//    the mqToES function contain a dead while need multi thread
//    MyAmqpClient dataLogClient("127.0.0.1", 5672, "guest", "guest", "dataLogQueue");
//    dataLogClient.mqToES("http://192.168.1.123:9200/datalog/_doc?pretty");

    curl_global_cleanup();
    return core.exec();
}
