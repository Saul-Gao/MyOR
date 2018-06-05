#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <mysql.h>

using std::cout;
using std::endl;

class Connection
{
	public:
		Connection(const char *host, const char *user, const char *passwd, const char *db);
		~Connection();
	public:
		MYSQL mysql;
};

#endif //CONNECTION_H
