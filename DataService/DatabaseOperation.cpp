#include "DatabaseOperation.h"

DatabaseOperation::DatabaseOperation()
{

}

DatabaseOperation::~DatabaseOperation()
{

}

int DatabaseOperation::executeSql(string sql)
{
	Connection *conn = ToolHelper::getInstance()->writeConnPool->getConnection();
	int status = mysql_real_query(&conn->mysql, sql.c_str(), sql.length());
	ToolHelper::getInstance()->writeConnPool->returnConnection(conn);
	return status;
}

int DatabaseOperation::insertData(string sql)
{
	return executeSql(sql);
}

int DatabaseOperation::deleteData(string sql)
{
	return executeSql(sql);
}

int DatabaseOperation::updateData(string sql)
{
	return executeSql(sql);
}

int DatabaseOperation::selectData(string sql)
{

}

int DatabaseOperation::userRegist(QString json)
{
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
    QJsonParseError err;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &err);
    if (err.error == QJsonParseError::NoError)
    {

    }
}

int DatabaseOperation::userLogin(QString json)
{

}


