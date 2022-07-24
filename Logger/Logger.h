#pragma once
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
	// 3. Logs saved in file in case of exception
	// 4. Return the mutex for cout to client code
	// 5. Automatic deletion of logger object in the program end

	
	class Logger : public ILogger
	{
	public:		

		static ILogger* GetLogger(LoggerSettings settings = LoggerSettings());

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

		// This will save the recorded logs to the input file location or default location
		// After logs are dumped into file, they are cleared from the memory
		// if log file already exists, logs will be appended in the end
		// param: filepath - input file path
		void SaveLog(std::string filepath = "");

		// change configuration after creating the logger
		// param: verbose - print the log statement on console immediately in call to log method
		// param: timestamp - add timestamp before log string
		void SetConfiguration(bool verbose = true, bool timestamp = true);

		// any logs in the memory will be dumped into default file location.
		~Logger();

		// return lock on cout so that clients could use this lock for correct printing on console using cout if they wish to
		std::mutex& GetCoutMutex();

	private:
		Logger(LoggerSettings settings);

		void PrintLog(std::string message);

		void SaveLogToFile(std::string filepath);

		static void DeleteLogger();

		void Flush();

		static ILogger* pLogger_;
		LoggerSettings settings_;
		std::deque<std::string> logData_;
		static std::mutex pLoggerLock_;
		std::mutex coutLock_;
		std::mutex logDataLock_;
	};
}

