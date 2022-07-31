#pragma once
#include <string>
#include <mutex>

#include "ILogger.h"

namespace logger
{

	class ConsoleLogger : public ILogger
	{
	public :
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

		void LogRoutine(std::string msg, std::string prefix);

		void PrintLog(std::string message);

		std::mutex coutLock_;
	};

}