#include <iostream>

#include "ConsoleLogger.h"
#include "loggersettings.h"

using namespace logger;

/***************************************************************************************
**********************************Warn******************************************
***************************************************************************************/

void ConsoleLogger::Warn(std::string message)
{
	LogRoutine(message, " WARN : ");
}

/***************************************************************************************
**********************************Error******************************************
***************************************************************************************/

void ConsoleLogger::Error(std::string message)
{
	LogRoutine(message, " ERROR : ");
}

/***************************************************************************************
**********************************Info******************************************
***************************************************************************************/

void ConsoleLogger::Info(std::string message)
{
	LogRoutine(message, " ");
}

/***************************************************************************************
**********************************LogRoutine********************************************
***************************************************************************************/

void ConsoleLogger::LogRoutine(std::string msg, std::string prefix)
{
	std::string actualMessage;
	auto settings = LoggerSettings::GetSettings();
	if (settings->timeStamp_)
	{
		// Safe way to get current timestamp into string using ctime_s instead of ctime
		auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		char buffer[35];
		ctime_s(buffer, sizeof(buffer), &time);
		actualMessage = buffer;
	}

	actualMessage = actualMessage.substr(0, actualMessage.size() - 1) + prefix + msg;

	PrintLog(actualMessage);
	
}

/***************************************************************************************
**********************************PrintLog**********************************************
***************************************************************************************/

void ConsoleLogger::PrintLog(std::string message)
{
	//std::lock_guard<std::mutex> lg(coutLock_);
	std::cout << message << std::endl;
}

/***************************************************************************************
****************************************************************************************
***************************************************************************************/