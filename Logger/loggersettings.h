#pragma once
#include <string>
#include <atomic>
#include <mutex>

// Class managing various settings
namespace logger
{
	class LoggerSettings
	{
	public:
		static LoggerSettings* GetSettings();
		void SetFilePath(std::string filepath);
		std::string GetFilePath();

		std::atomic_bool timeStamp_ = false;
		std::atomic_bool enableFileLogging_ = true;
		std::atomic_bool enableConsoleLogging_ = true;
		std::atomic_bool enableHTTPLogging_ = false;

	private:	

		LoggerSettings();

		// default log location
		std::string filepath_ = "C://temp//log.txt";
		std::mutex filepathMutex_;
		static LoggerSettings* settings_;
		static std::mutex settingsLock_;

	};
}