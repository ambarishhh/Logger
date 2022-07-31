#pragma once

#include <string>
#include <mutex>
#include <deque>

#include "loggersettings.h"
#include "ILogger.h"

namespace logger
{
	// Various components can use logger to print log on console, save log in a file
	// Various implicit requirements this project will comply are:
	// 1. It can display timestamp 
	// 2. Supported log categories - Error, warning, information

	
	class FileLogger : public ILogger
	{
	public:		

		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		void Warn(std::string message);

		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		void Info(std::string message);

		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		void Error(std::string message);

	private:		

		void SaveLog(std::string message);

		void LogRoutine(std::string msg, std::string prefix);
	
		std::mutex fileLock_;
	};
}

