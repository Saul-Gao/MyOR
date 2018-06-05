#include "Connection.h"

Connection::Connection(const char *host, const char *user, const char *passwd, const char *db)
{
	mysql_init(&this->mysql);
	if (!mysql_real_connect(&this->mysql, host, user, passwd, db, 0, NULL, 0))
	{
		cout << "Failed to connect to database: Error: " << mysql_error(&this->mysql) << endl;
	}
}

Connection::~Connection()
{
	mysql_close(&this->mysql);
}

