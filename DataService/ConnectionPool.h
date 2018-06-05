#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <queue>
#include <list>
#include <string>
#include <pthread.h>
#include <string.h>

#include "Connection.h"

using std::string;
using std::queue;
using std::list;

class ConnectionPool
{
	public:

		ConnectionPool(const char *host, const char *user, const char *passwd, const char *db, int initConnCounts, int maxConnCounts);

		~ConnectionPool();

	public:

		Connection *getConnection();

		void returnConnection(Connection *conn);

	private:
		
		pthread_mutex_t mutex;
		
		queue<Connection *> pool_free;
		list<Connection *> pool_busy;

		string host;
		string user;
		string passwd;
		string db;
		int connCounts;
		int maxConnCounts;
};

#endif //CONNECTIONPOOL_H
