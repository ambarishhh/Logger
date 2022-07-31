
/***************************************************************************************
****************************************************************************************
***************************************************************************************/

// library includes
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

// local includes
#include "FileLogger.h"

namespace logger
{

/***************************************************************************************
**********************************Warn******************************************
***************************************************************************************/

	void FileLogger::Warn(std::string message)
	{
		LogRoutine(message, " WARN : ");
	}

/***************************************************************************************
**********************************Error******************************************
***************************************************************************************/

	void FileLogger::Error(std::string message)
	{
		LogRoutine(message, " ERROR : ");
	}

/***************************************************************************************
**********************************Info******************************************
***************************************************************************************/

	void FileLogger::Info(std::string message)
	{
		LogRoutine(message, " ");
	}

/***************************************************************************************
**********************************SaveLog******************************************
***************************************************************************************/

	void FileLogger::SaveLog(std::string message)
	{
		auto settings = LoggerSettings::GetSettings();
		auto filepath = settings->GetFilePath();

		std::lock_guard<std::mutex> lg(fileLock_);
		std::fstream file;
		file.open(filepath, std::ios::app);
		file << message << std::endl;		
		file.close();
	}

/***************************************************************************************
**********************************Flush*************************************************
***************************************************************************************/

	void FileLogger::LogRoutine(std::string msg, std::string prefix)
	{
		std::string actualMessage;
		auto settings = LoggerSettings::GetSettings();
		if (settings->timeStamp_)
		{
			// Safe way to get current timestamp into string using ctime_s instead of ctime
			auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			char buffer[30];
			ctime_s(buffer, sizeof(buffer), &time);
			actualMessage = buffer;
		}

		actualMessage = actualMessage.substr(0, actualMessage.size() - 1) + prefix + msg;

		SaveLog(actualMessage);
	}
}

/***************************************************************************************
****************************************************************************************
***************************************************************************************/