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
		LoggerSettings();
		LoggerSettings(bool verbose, bool timestamp);
		LoggerSettings(const LoggerSettings& input);
		void SetConfiguration(bool verbose, bool timestamp);
		void SetFilePath(std::string filepath);
		std::string GetConsolidatedFilePath();
		std::string GetFilePath();

		std::atomic_bool verbose_ = true;
		std::atomic_bool timeStamp_ = true;

	private:
		// default log location
		std::string filepath_ = "C://temp//log.txt";
		std::string consolidatedLogFilepath_ = "C://temp//consilidated_log.txt";
		std::mutex filepathMutex_;
	};
}