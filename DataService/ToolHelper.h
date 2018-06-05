#ifndef TOOLHELPER_H
#define TOOLHELPER_H

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

#include "ConnectionPool.h"

class ToolHelper
{
	public:
		static ToolHelper *getInstance();
	public:
		ConnectionPool *writeConnPool;
		ConnectionPool *readConnPool;

	private:
		ToolHelper();
		ToolHelper(const ToolHelper &);
		~ToolHelper();
	private:
		static ToolHelper *th;
};

#endif
