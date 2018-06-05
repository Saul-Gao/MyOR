#include "ConnectionPool.h"

ConnectionPool::ConnectionPool(const char *host, const char *user, const char *passwd, const char *db, int initConnCounts, int maxConnCounts)
{
	this->host = host;
	this->user = user;
	this->passwd = passwd;
	this->db = db;
	this->connCounts = initConnCounts;
	this->maxConnCounts = maxConnCounts;

	for (int i = 0; i < initConnCounts; ++i)
	{
		Connection *conn = new Connection(host, user, passwd, db);
		pool_free.push(conn);
	}

	pthread_mutex_init(&this->mutex, NULL);
}

ConnectionPool::~ConnectionPool()
{
	//释放空闲队列
	while(!pool_free.empty())
	{
		delete pool_free.front();
		pool_free.pop();
	}
	//释放忙碌队列
	for (list<Connection *>::iterator it = pool_busy.begin(); it != pool_busy.end(); ++it)
	{
		delete *it;
	}
}

Connection *ConnectionPool::getConnection()
{
	pthread_mutex_lock(&this->mutex);
	//如果有空闲连接，把该连接从空闲队列转移到忙碌队列，并返回给用户
	if (!pool_free.empty())
	{
		Connection *conn = pool_free.front();
		pool_free.pop();
		pool_busy.push_back(conn);
		pthread_mutex_unlock(&this->mutex);
		return conn;
	}
	//如果没有空闲连接，并且连接数未到上限，则申请一个新连接给用户，并加入到忙碌队列
	else if (connCounts < maxConnCounts)
	{
		Connection *conn = new Connection(this->host.c_str(), this->user.c_str(), this->passwd.c_str(), this->db.c_str());
		pool_busy.push_back(conn);
		++connCounts;
		pthread_mutex_unlock(&this->mutex);
		return conn;
	}
	//如果没有空闲连接并且连接数达到上限，则暂时返回空
	else
	{
		pthread_mutex_lock(&this->mutex);
		return NULL;
	}
}

void ConnectionPool::returnConnection(Connection *conn)
{
	pthread_mutex_lock(&this->mutex);
	//从忙碌队列检索要归还的连接，并把它转移到空闲队列
	for (list<Connection *>::iterator it = pool_busy.begin(); it != pool_busy.end(); ++it)
	{
		if (conn == *it)
		{
			pool_free.push(*it);
			pool_busy.remove(*it);
			break;
		}
	}
	pthread_mutex_unlock(&this->mutex);
}
