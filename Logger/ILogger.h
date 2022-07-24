#pragma once
#include <string>

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

		// Use this method to change the logging configuration
		// param: verbose - prints evry message on console
		// param: timestamp - appends timestamp to every message
		virtual void SetConfiguration(bool verbose = true, bool timestamp = true) = 0;

		// This will save the recorded logs to the input file location or default location
		// After logs are dumped into file, they are cleared from the memory
		// if log file already exists, logs will be appended in the end
		// param: filepath - input file path
		virtual void SaveLog(std::string filepath = "") = 0;

	};
}
