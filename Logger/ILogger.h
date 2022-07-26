#pragma once
#include <string>

#include "loggersettings.h"

namespace logger
{
	class ILogger
	{
	public:
		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		virtual void Warn(std::string message) = 0;

		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		virtual void Info(std::string message) = 0;

		// Use this method to log the message
		// param: message - user message 
		// param: category - category of the message
		// This method will print message on console as well as store it to be later saved/shared 
		virtual void Error(std::string message) = 0;

	};
}
