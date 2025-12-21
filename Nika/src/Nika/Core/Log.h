#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Nika
{
	class NIKA_API Log
	{
	public:
		static void initLog();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// --- macro to strip logging from release build ---
#ifdef LOGGING_OFF
	// --- in release mode, macros expand to nothing -> compiler removes calls ---
	#define NIKA_TRACE(...)
	#define NIKA_DEBUG(...)
	#define NIKA_INFO(...)
	#define NIKA_WARN(...)
	#define NIKA_ERROR(...)
	#define NIKA_CRITICAL(...)
	
	#define CLIENT_TRACE(...)
	#define CLIENT_DEBUG(...)
	#define CLIENT_INFO(...)
	#define CLIENT_WARN(...)
	#define CLIENT_ERROR(...)
	#define CLIENT_CRITICAL(...)
#else
	// --- engine side logger ---
	#define NIKA_TRACE(...)			::Nika::Log::getCoreLogger()->trace(__VA_ARGS__)
	#define NIKA_DEBUG(...)			::Nika::Log::getCoreLogger()->debug(__VA_ARGS__)
	#define NIKA_INFO(...)			::Nika::Log::getCoreLogger()->info(__VA_ARGS__)
	#define NIKA_WARN(...)			::Nika::Log::getCoreLogger()->warn(__VA_ARGS__)
	#define NIKA_ERROR(...)			::Nika::Log::getCoreLogger()->error(__VA_ARGS__)
	#define NIKA_CRITICAL(...)		::Nika::Log::getCoreLogger()->critical(__VA_ARGS__)
	
	// --- application side logger ---
	#define CLIENT_TRACE(...)		::Nika::Log::getClientLogger()->trace(__VA_ARGS__)
	#define CLIENT_DEBUG(...)		::Nika::Log::getClientLogger()->debug(__VA_ARGS__)
	#define CLIENT_INFO(...)		::Nika::Log::getClientLogger()->info(__VA_ARGS__)
	#define CLIENT_WARN(...)		::Nika::Log::getClientLogger()->warn(__VA_ARGS__)
	#define CLIENT_ERROR(...)		::Nika::Log::getClientLogger()->error(__VA_ARGS__)
	#define CLIENT_CRITICAL(...)	::Nika::Log::getClientLogger()->critical(__VA_ARGS__)
#endif

