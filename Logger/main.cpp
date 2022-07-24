#include "logger.h"
#include "ILogger.h"
#include "loggersettings.h"


void foo()
{
	logger::ILogger* pLogger = logger::Logger::GetLogger();
	for (int i = 0; i < 100; i++)
	{
		pLogger->Info("Slave Thread Message " + std::to_string(i));
	}
}

int main()
{
	logger::ILogger* pLogger = logger::Logger::GetLogger();
	pLogger->Info("Message 01");
	pLogger->Warn("Message 02 Warning");
	pLogger->Error("Message 03 Error");

	std::thread t1(&foo);
	for (int i = 0; i < 100; i++)
	{
		logger::ILogger* pLogger1 = logger::Logger::GetLogger();
		pLogger1->Info("Master Thread Message " + std::to_string(i));
	}
	t1.join();

	pLogger->SetConfiguration(false, false);
	pLogger->Info("Message 04");
	pLogger->SaveLog();
	pLogger->Info("Message 05");
	pLogger->SaveLog("c://temp//customlog.txt");
	return 0;
}