#ifndef DATABASEOPERATION_H
#define DATABASEOPERATION_H

#include "ToolHelper.h"

class DatabaseOperation
{
	public:
		DatabaseOperation();
		~DatabaseOperation();
	public:
		int executeSql(string sql);
		int insertData(string sql);
		int deleteData(string sql);
		int updateData(string sql);
		int selectData(string sql);

        int userRegist(QString json);
        int userLogin(QString json);
};

#endif //DATABASEOPERATION_H
