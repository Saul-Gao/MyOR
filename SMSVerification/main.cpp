#include <QCoreApplication>
#include "myhttpserver.h"

int main(int argc, char *argv[])
{
   QCoreApplication core(argc, argv);
   curl_global_init(CURL_GLOBAL_DEFAULT);
   MyHttpServer server;
   curl_global_cleanup();
   return core.exec();
}
