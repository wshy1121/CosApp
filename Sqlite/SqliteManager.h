#ifndef _SQLITE_MANAGER_H_
#define _SQLITE_MANAGER_H_
#include "Sqlite/CppSQLite3.h"

class CSqliteManager
{
public:
	static CSqliteManager* instance();
	int execDML(const char* fmt, ...);
	CppSQLite3Query execQuery(const char* fmt, ...);
private:
	static  CSqliteManager* _instance;
	CSqliteManager();
	~CSqliteManager();
private:
	CppSQLite3DB m_userDb;
};
#endif


