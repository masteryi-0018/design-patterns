#include <iostream>
using namespace std;

// 数据库相关基类
class IDBConnection {

};

class IDBCommand {

};

class IDataReader {

};

// 抽象工厂
class IDBFactory {
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDataReader* CreateDataReader() = 0;
};

// 支持Sql
// 略

// Sql工厂
class SqlDBFactory: public IDBFactory {
public:
    virtual IDBConnection* CreateDBConnection() {

    }
    virtual IDBCommand* CreateDBCommand() {

    }
    virtual IDataReader* CreateDataReader() {

    }
};

// Oracl工厂
// 略

class EmployeeDAO {
private:
    IDBFactory* dbFactory;

public:
    vector<EmployeeDO> GetEmployees() {
        IDBConnection* connection = dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbFactory->CreateDBCommand();
        command->CommandText("...");

        IDataReader* reader = command->ExecuteReader();

        while (reader->Read()) {
            // ...
        }
    }
};