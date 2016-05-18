// LogManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "net_server.h"
#include "net_client.h"
#include "SimpleIni.h"
#include "CmdLineInter.h"
#include "trace_server.h"
#include "cli_server.h"

int main(int argc, char* argv[])
{

	CSimpleIniA ini;
	ini.SetUnicode();  
	ini.LoadFile("Config.ini");  
	const char * netCliIp = ini.GetValue("NetConfig", "NetCliIp", "192.168.0.1");  
	int netCliPort = (int)ini.GetLongValue("NetConfig", "NetCliPort");

	trace_start(netCliIp, netCliPort, "/home/share/Log/LogManagerDebug.cpp");

	CTraceServer::instance()->startServer();
    CCliTcpServer::instance()->startServer();
	CCliUdpServer::instance()->startServer();
    
    INetServer::dispatch();
	sleep(1);
	
	bool bRet = CNetClient::instance()->connect((char *)"127.0.0.1");
	if (bRet)
	{
		bRet = CNetClient::instance()->login((char *)"admin", (char *)"admin");
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
        base::usleep(1000*1000);
    }

    return 0;
}

