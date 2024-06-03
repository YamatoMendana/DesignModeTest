#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/* 抽象工厂模式
AbstractFactory -> IDBFactory (稳定)
AbstractProductA -> IDBConnection （稳定）
AbstractProductB -> IDBCommand / IDataReader （稳定）
ConcreteFactoryX -> SqlDBFactory / OracleDBFactory (变化)
*/
//数据库访问有关的基类
class IDBConnection {
public:
	void ConnectionString(const char* str) { cout << "IDBConnection::ConnectionString" << endl; }
};

class IDataReader {
public:
	int Read() { 
		cout << "IDataReader::Read" << endl;
		return 0; 
	}
};

class IDBCommand {
public:
	void CommandText(const char* str) { cout << "IDBCommand::CommandText" << endl; }
	void SetConnection(IDBConnection* connection) { cout << "IDBCommand::SetConnection" << endl; }
	IDataReader* ExecuteReader() {
		cout << "IDBCommand::ExecuteReader" << endl;
		IDataReader* IDR = new IDataReader();
		return IDR;
	}
};

class IDBFactory {
public:
	//因为三个有相关性，所以考虑把它们放到一个工厂里
	virtual IDBConnection* createDBConnection() = 0;
	virtual IDBCommand* createDBCommand() = 0;
	virtual IDataReader* createDataReader() = 0;
};

//支持SQL Server
class SqlConnection : public IDBConnection {};
class SqlCommand : public IDBCommand {};
class SqlDataReader : public IDataReader {};

class SqlDBFactory : public IDBFactory {
	virtual IDBConnection* createDBConnection() {}
	virtual IDBCommand* createDBCommand() {}
	virtual IDataReader* createDataReader() {}
};

//支持 Oracle
class OracleConnection : public IDBConnection {
public:
	OracleConnection() { cout << "OracleConnection create" << endl; }
};
class OracleCommand : public IDBCommand {
public:
	OracleCommand() { cout << "OracleCommand create" << endl; }
};
class OracleDataReader : public IDataReader {
public:
	OracleDataReader() { cout << "OracleDataReader create" << endl; }
};

class OracleDBFactory : public IDBFactory {
	virtual IDBConnection* createDBConnection() {
		cout << "OracleDBFactory::createDBConnection" << endl;
		IDBConnection* connect = new IDBConnection();
		return connect;

	}
	virtual IDBCommand* createDBCommand() {
		cout << "OracleDBFactory::createDBCommand" << endl;
		IDBCommand* command = new IDBCommand();
		return command;
	}
	virtual IDataReader* createDataReader() {
		cout << "OracleDBFactory::createDataReader" << endl;
		IDataReader* reader = new IDataReader();
		return reader;
	}
};

class EmployeeDAO {
	IDBFactory* dbFactory;
public:
	EmployeeDAO(IDBFactory* dbFactory){
		this->dbFactory = dbFactory;
	}

	void run(){
		IDBConnection* connection = dbFactory->createDBConnection();
		connection->ConnectionString("...");

		IDBCommand* command = dbFactory->createDBCommand();
		command->CommandText("...");
		command->SetConnection(connection); //关联性

		IDataReader* reader = command->ExecuteReader(); //关联性
		while (reader->Read()) {

		}
	}
};
