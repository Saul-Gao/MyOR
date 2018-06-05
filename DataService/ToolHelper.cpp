#include "ToolHelper.h"

ToolHelper *ToolHelper::th = new ToolHelper;

ToolHelper::ToolHelper()
{
    this->writeConnPool = new ConnectionPool("192.168.71.128", "saul", "205205", "test", 100, 100);
	this->readConnPool = NULL;
}

ToolHelper::~ToolHelper()
{
	delete this->writeConnPool;
}

ToolHelper *ToolHelper::getInstance()
{
	return th;
}
