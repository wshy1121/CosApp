#include "SqliteManager.h"
#include "link_tool.h"

using namespace base;

extern CPthreadMutex g_insMutexCalc;

CSqliteManager* CSqliteManager::_instance = NULL;

CSqliteManager* CSqliteManager::instance() 
{	
	if (NULL == _instance)
	{
		CGuardMutex guardMutex(g_insMutexCalc);
		if (NULL == _instance)
		{
			_instance = new CSqliteManager;
		}
	}
	return _instance;
}


CSqliteManager::CSqliteManager()
{
	m_userDb.open("./LogView.db");
}

CSqliteManager::~CSqliteManager()
{
	m_userDb.close();
}
int CSqliteManager::execDML(const char* fmt, ...)
{
	char szSQL[4096];
	va_list ap;
	va_start(ap,fmt);
	base::vsnprintf(szSQL,sizeof(szSQL), fmt, ap);
	va_end(ap);

	return m_userDb.execDML(szSQL);
}

CppSQLite3Query CSqliteManager::execQuery(const char* fmt, ...)
{
	char szSQL[4096];
	va_list ap;
	va_start(ap,fmt);
	base::vsnprintf(szSQL,sizeof(szSQL), fmt, ap);
	va_end(ap);

	return m_userDb.execQuery(szSQL);
}


