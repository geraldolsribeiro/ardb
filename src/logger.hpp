/*
 * logger_macros.hpp
 *
 *  Created on: 2011-4-20
 *      Author: qiyingwang
 */

#ifndef LOGGER_MACROS_HPP_
#define LOGGER_MACROS_HPP_

namespace ardb
{
	enum LogLevel
	{
		NONE_LOG_LEVEL = 0,
		FATAL_LOG_LEVEL = 1,
		ERROR_LOG_LEVEL = 2,
		WARN_LOG_LEVEL = 3,
		INFO_LOG_LEVEL = 4,
		DEBUG_LOG_LEVEL = 5,
		TRACE_LOG_LEVEL = 6,
		ALL_LOG_LEVEL = 7,

		INVALID_LOG_LEVEL = 100
	};
	typedef void ARDBLogHandler(LogLevel level, const char* filename,
			const char* function, int line, const char* format, ...);
	typedef bool IsLogEnable(LogLevel level);

	struct ARDBLogger
	{
			static ARDBLogHandler* GetLogHandler();
			static IsLogEnable* GetLogChecker();
			static void InstallLogHandler(ARDBLogHandler* h, IsLogEnable* c);
	};
}

#define DEBUG_ENABLED() ((ardb::ARDBLogger::GetLogChecker())(ardb::DEBUG_LOG_LEVEL))
#define TRACE_ENABLED() ((ardb::ARDBLogger::GetLogChecker())(ardb::TRACE_LOG_LEVEL))
#define ERROR_ENABLED() ((ardb::ARDBLogger::GetLogChecker())(ardb::ERROR_LOG_LEVEL))
#define INFO_ENABLED()  ((ardb::ARDBLogger::GetLogChecker())(ardb::INFO_LOG_LEVEL))
#define FATAL_ENABLED() ((ardb::ARDBLogger::GetLogChecker())(ardb::FATAL_LOG_LEVEL))
#define WARN_ENABLED() ((ardb::ARDBLogger::GetLogChecker())(ardb::WARN_LOG_LEVEL))

#define DEBUG_LOG( ...) do {\
   if(DEBUG_ENABLED())\
   {                 \
	   (*(ardb::ARDBLogger::GetLogHandler()))(ardb::DEBUG_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \
   }\
}while(0)

#define WARN_LOG(...) do {\
	if(WARN_ENABLED())\
    {                 \
		(*(ardb::ARDBLogger::GetLogHandler()))(ardb::WARN_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \
	}\
}while(0)

#define TRACE_LOG(...) do {\
	if(TRACE_ENABLED())\
	{                 \
		(*(ardb::ARDBLogger::GetLogHandler()))(ardb::TRACE_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \
	}\
}while(0)

#define ERROR_LOG(...) do {\
	if(ERROR_ENABLED())\
	{                 \
		(*(ardb::ARDBLogger::GetLogHandler()))(ardb::ERROR_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \
	}\
}while(0)

#define FATAL_LOG(...) do {\
	if(FATAL_ENABLED())\
    {                 \
		(*(ardb::ARDBLogger::GetLogHandler()))(ardb::FATAL_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \
	}\
}while(0)

#define INFO_LOG(...) do {\
	if(INFO_ENABLED())\
	{                 \
		(*(ardb::ARDBLogger::GetLogHandler()))(ardb::INFO_LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__); \                 \
	}\
}while(0)

#endif /* LOGGER_MACROS_HPP_ */
