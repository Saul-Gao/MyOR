#include "DatabaseOperation.h" 
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <semaphore.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QVariant>
#include <QVariantMap>
#include <QString>
#include <QDebug>
#include <QCoreApplication>

#include "myhttpserver.h"

sem_t sem;
DatabaseOperation dbopt;
void* handler(void* arg){
	long tid = (long)arg;

	while(true)
	{
		sem_wait(&sem);

		/*
		if(!conn){
			cout << "getConnection NULL pointer" << endl;
			exit(-1);

		}
		*/


		const char* query;
		query = "insert into student values(1,'zhangsan')";

		dbopt.insertData(query);

		/*
		int status = mysql_real_query(&conn->mysql, query, strlen(query));
		if (status)
		{
			cout << "execute query failed" << endl;
			exit(0);
		}

		writeConnPool->returnConnection(conn);
		*/


	}
}


int main(int argc,  char *argv[]){
    QCoreApplication app(argc, argv);
    MyHttpServer server;
    return app.exec();
    /*
	const int THREAD_COUNT = 100;
	pthread_t threads[THREAD_COUNT];
	for(long i=0;i<THREAD_COUNT;i++){
		pthread_create(&threads[i],NULL,handler,(void*)i);
	}

	struct timeval start,end;
	gettimeofday(&start,NULL);

	sem_init(&sem, 0, 10000);

	int valp = 0;
	while(true)
	{
		sem_getvalue(&sem, &valp);
		if (valp == 0)
		{
			cout<<"2"<<endl;
			break;
		}
		usleep(1);
	}
	gettimeofday(&end,NULL);
	cout << "time:" << end.tv_sec - start.tv_sec << endl;
	cout << "utime:" << end.tv_usec - start.tv_usec << endl;

	for(int i=0;i<THREAD_COUNT;i++){
		pthread_join(threads[i],0);
	}
    */

//    QString json = "{\
//                   \"id\" : 1,\
//                   \"name\" : \"zhangsan\",\
//                   \"array\" : [1, 2, 3],\
//                   \"hehe\" : {\
//                       \"h\" : 5,\
//                       \"e\" : 6\
//                   }\
//               }";
//    QJsonParseError error;
//    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
//    qDebug() << 1111;
//    if (error.error == QJsonParseError::NoError)
//    {
//        qDebug() << 2222;
//        if (jsonDocument.isObject())
//        {
//            qDebug() << 3333;
//            QVariantMap result = jsonDocument.toVariant().toMap();
//            qDebug() << "id:" << result["id"].toInt();
//            qDebug() << "name:" << result["name"].toString();
//            qDebug() << "array:";
//            foreach (QVariant haha, result["array"].toList()) {
//                qDebug() <<"\t" << haha.toInt();
//            }
//            QVariantMap hehe = result["hehe"].toMap();
//            qDebug() << "hehe :" << "{" << "h:" << hehe["h"].toInt() << ", e: "<<hehe["e"].toInt();
//        }
//        else
//        {
//            qFatal(error.errorString().toUtf8().constData());
//            exit(1);
//        }
//    }

	return 0;
}
