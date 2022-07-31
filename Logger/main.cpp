#include "FileLogger.h"
#include "LoggerController.h"
#include "loggersettings.h"


void foo()
{
	logger::ILogger* pLogger = logger::LoggerController::GetLogger();
	for (int i = 0; i < 100; i++)
	{
		pLogger->Info("Slave Thread Message " + std::to_string(i));
	}
}

int main()
{
	logger::ILogger* pLogger = logger::LoggerController::GetLogger();
	pLogger->Info("Message 01");
	pLogger->Warn("Message 02 Warning");
	pLogger->Error("Message 03 Error");

	std::thread t1(&foo);
	for (int i = 0; i < 100; i++)
	{
		logger::ILogger* pLogger1 = logger::LoggerController::GetLogger();
		pLogger1->Info("Master Thread Message " + std::to_string(i));
	}
	t1.join();

	pLogger->Info("Message 04");
	pLogger->Info("Message 05");

	// waiting for logger engine thread to complete the execution
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	return 0;
}
