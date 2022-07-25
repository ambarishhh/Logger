
/***************************************************************************************
****************************************************************************************
***************************************************************************************/

// library includes
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

// local includes
#include "Logger.h"

namespace logger
{
	ILogger * Logger::pLogger_ = nullptr;
	std::mutex Logger::pLoggerLock_;

/***************************************************************************************
*********************************GetLogger*************************************
***************************************************************************************/

	ILogger* Logger::GetLogger(LoggerSettings settings)
	{
		std::lock_guard<std::mutex> lg(pLoggerLock_);
		if (!pLogger_)
			pLogger_ = new Logger(settings);
		return pLogger_;
	}

/***************************************************************************************
*********************************Logger Constructor*************************************
***************************************************************************************/
	
	Logger::Logger(LoggerSettings settings)
	{
		settings_.verbose_ = settings.verbose_.load();
		settings_.timeStamp_ = settings.verbose_.load();

		// delete the extsting log files 
		std::filesystem::remove(settings_.GetFilePath());
		std::filesystem::remove(settings_.GetConsolidatedFilePath());

		// auto deletion of logger in the end
		std::atexit(Logger::DeleteLogger);
	}

/***************************************************************************************
**********************************Logger Destructor*************************************
***************************************************************************************/

	Logger::~Logger()
	{
		Flush();
	}

/***************************************************************************************
**********************************GetCoutMutex******************************************
***************************************************************************************/

	std::mutex& Logger::GetCoutMutex()
	{
		return coutLock_;
	}

/***************************************************************************************
**********************************PrintLog******************************************
***************************************************************************************/

	void Logger::PrintLog(std::string message)
	{
		std::lock_guard<std::mutex> lg(coutLock_);
		std::cout << message << std::endl;
	}

/***************************************************************************************
**********************************SaveLogToFile******************************************
***************************************************************************************/

	void Logger::SaveLogToFile(std::string filepath)
	{
		// This could be done more efficiently by having separate mutex for file handling and logData_
		std::lock_guard<std::mutex> lg(logDataLock_);
		std::fstream file;
		if (std::filesystem::exists(filepath))
			file.open(filepath, std::ios::app);
		else
			file.open(filepath, std::ios::out);
		if (!file.good())
			throw "Please input correct path!";
		for (auto& line : logData_)
			file << line << std::endl;
		file.close();
	}

/***************************************************************************************
**********************************DeleteLogger******************************************
***************************************************************************************/

	void Logger::DeleteLogger()
	{
		if (pLogger_) delete pLogger_;
		pLogger_ = nullptr;
	}

/***************************************************************************************
**********************************Warn******************************************
***************************************************************************************/

	void Logger::Warn(std::string message)
	{
		LogRoutine(message, " WARN : ");
	}

/***************************************************************************************
**********************************Error******************************************
***************************************************************************************/

	void Logger::Error(std::string message)
	{
		LogRoutine(message, " ERROR : ");
	}

/***************************************************************************************
**********************************Info******************************************
***************************************************************************************/

	void Logger::Info(std::string message)
	{
		LogRoutine(message, " ");
	}

/***************************************************************************************
**********************************SaveLog******************************************
***************************************************************************************/

	void Logger::SaveLog(std::string filepath)
	{
		if (filepath == "")
			filepath = settings_.GetFilePath();

		SaveLogToFile(filepath);

		Flush();
	}

/***************************************************************************************
**********************************SetConfiguration**************************************
***************************************************************************************/

	void Logger::SetConfiguration(bool verbose, bool timestamp)
	{
		settings_.verbose_ = verbose;
		settings_.timeStamp_ = timestamp;
	}

/***************************************************************************************
**********************************Flush*************************************************
***************************************************************************************/

	void Logger::Flush()
	{
		SaveLogToFile(settings_.GetConsolidatedFilePath());
		std::lock_guard<std::mutex> lg(logDataLock_);
		logData_.clear();
	}

/***************************************************************************************
**********************************Flush*************************************************
***************************************************************************************/

	void Logger::LogRoutine(std::string msg, std::string prefix)
	{
		std::string actualMessage;
		if (settings_.timeStamp_)
		{
			// Safe way to get current timestamp into string using ctime_s instead of ctime
			auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			char buffer[30];
			ctime_s(buffer, sizeof(buffer), &time);
			actualMessage = buffer;
		}

		actualMessage = actualMessage.substr(0, actualMessage.size() - 1) + prefix + msg;

		if (settings_.verbose_)
			PrintLog(actualMessage);
		std::lock_guard<std::mutex> lg(logDataLock_);
		logData_.push_back(actualMessage);
	}
}

/***************************************************************************************
****************************************************************************************
***************************************************************************************/