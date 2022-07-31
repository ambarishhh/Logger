#pragma once

#include <vector>
#include <queue>

#include "ILogger.h"
#include "loggersettings.h"

#include "ConsoleLogger.h"
#include "FileLogger.h"

using namespace std;

namespace logger
{
	enum class ELogCategories
	{
		ERROR,
		WARN,
		INFO
	};

	class LoggerController : public ILogger
	{
	public:
		static ILogger* GetLogger();

		void Warn(std::string message);
		void Error(std::string message);
		void Info(std::string message);

		~LoggerController();

	private:
		LoggerController();
		void InitLogger();
		static void DeleteLogger();
		void LoggerEngine();

		vector<ILogger*> loggerImpls_;
		queue<pair<string, ELogCategories>> messages_;

		std::thread loggerEngine_;

		static ILogger* pLogger_;
		static std::mutex pLoggerLock_;

		std::mutex messagesLock_;

		std::atomic_bool terminateLogger_ = false;
	};
}