#include <chrono>
#include <thread>

#include "LoggerController.h"

using namespace logger;

ILogger* LoggerController::pLogger_ = nullptr;
std::mutex LoggerController::pLoggerLock_;

ILogger* LoggerController::GetLogger()
{
	std::lock_guard<std::mutex> lg(pLoggerLock_);
	if (!pLogger_)
		pLogger_ = new LoggerController();
	return pLogger_;
}

LoggerController::LoggerController()
{
	InitLogger();
	std::atexit(LoggerController::DeleteLogger);
}

void LoggerController::DeleteLogger()
{
	std::lock_guard<std::mutex> lg(pLoggerLock_);	
	delete pLogger_;
}

logger::LoggerController::~LoggerController()
{
	terminateLogger_.store(true);
	loggerEngine_.join();
}

void logger::LoggerController::Warn(std::string message)
{
	std::lock_guard<std::mutex> lg(pLoggerLock_);
	messages_.push({ message, ELogCategories::WARN });
}

void logger::LoggerController::Error(std::string message)
{
	std::lock_guard<std::mutex> lg(pLoggerLock_);
	messages_.push({ message, ELogCategories::ERROR });
}

void logger::LoggerController::Info(std::string message)
{
	std::lock_guard<std::mutex> lg(pLoggerLock_);
	messages_.push({ message, ELogCategories::INFO });
}

void logger::LoggerController::InitLogger()
{
	messages_.push({ "Initialized Logger....", ELogCategories::INFO });
	auto settings = LoggerSettings::GetSettings();

	if (settings->enableConsoleLogging_)
	{
		loggerImpls_.push_back(new ConsoleLogger());
	}
	if (settings->enableFileLogging_)
	{
		loggerImpls_.push_back(new FileLogger());
	}
	
	loggerEngine_ = std::thread{ &LoggerController::LoggerEngine, this };
}

void logger::LoggerController::LoggerEngine()
{
	while (!terminateLogger_.load() && !messages_.empty())
	{
		// Since LoggerEngine method runs on separate thread and no other thread can pop messages 
		// no need to apply lock on empty check. LoggerEngine will only run on one thread only.
		// LoggerEngine will only run on one thread only so no need to lock local variable message
		while (!messages_.empty())
		{
			std::pair<string, ELogCategories> message;
			{
				std::lock_guard<std::mutex> lg(pLoggerLock_);
				message = messages_.front();
				messages_.pop();
			}
			for (const auto& impl : loggerImpls_)
			{
				if (message.second == ELogCategories::ERROR)
					impl->Error(message.first);
				else if (message.second == ELogCategories::WARN)
					impl->Warn(message.first);
				else if (message.second == ELogCategories::INFO)
					impl->Info(message.first);
			}
		}
		// check status of _messages every half a second. This is to avoid continuous polling 
		// filling of messages will continue during this period
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
