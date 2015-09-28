// LogManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "net_server.h"
#include "net_client.h"
#include "SimpleIni.h"



int main(int argc, char* argv[])
{

	CNetServer::instance()->startServer();
	sleep(1);
	
	CSimpleIniA ini;  
	ini.SetUnicode();  
	ini.LoadFile("Config.ini");  
	const char * netCliIp = ini.GetValue("NetConfig", "NetCliIp", "default");  
	int netCliPort = (int)ini.GetLongValue("NetConfig", "NetCliPort");

	trace_start(netCliIp, netCliPort, "C:\\Users\\huangyuan1\\Desktop\\Debug1.cpp");
	
	bool bRet = CNetClient::instance()->connect("127.0.0.1");
	if (bRet)
	{
		bRet = CNetClient::instance()->login("admin", "admin");
	}
	else
	{
		printf("startServer failed\n");
		return 0;
	}

	
	char access[32];
	int accessLen = sizeof(access);
	char accessRep[32];
	
	CNetClient::instance()->createAccess(access, accessLen);
	CNetClient::instance()->getAccessRep(access, accessLen, accessRep);
	CNetClient::instance()->verifyAccess(access, accessLen, accessRep);
	while (1)
	{
		sleep(1);
	}
	return 0;
}

