#include <QCoreApplication>

#include "myhttpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication core(argc, argv);
    MyHttpServer myserver;
    return core.exec();
}
