#include <iostream>
using namespace std;

// 数据库相关基类
class IDBConnection {

};

class IDBCommand {

};

class IDataReader {

};

// 基类对应工厂
class IDBConnectionFactory {
public:
    virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommandFactory {
public:
    virtual IDBCommand* CreateDBCommand() = 0;
};

class IDataReaderFactory {
public:
    virtual IDataReader* CreateDataReader() = 0;
};

// 支持Sql
class SqlConnection: public IDBConnection {

};

class SqlCommand: public IDBCommand {

};

class SqlDataReader: public IDataReader {

};

// Sql相关工厂
// 略

// 支持Oracle
// 略

// Oracle相关工厂
// 略

class EmployeeDAO {
private:
    // 三个工厂是有相关性的，不可以使用Sql的Connection和Oracle的Command
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDataReaderFactory* dbDataReaderFactory;

public:
    vector<EmployeeDO> GetEmployees() {
        IDBConnection* connection = dbConnectionFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbCommandFactory->CreateDBCommand();
        command->CommandText("...");

        IDataReader* reader = command->ExecuteReader();

        while (reader->Read()) {
            // ...
        }
    }
};