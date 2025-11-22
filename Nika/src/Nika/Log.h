#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>

namespace Nika
{
	class NIKA_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// --- core log macros ---
#define NIKA_TRACE(...)			::Nika::Log::getCoreLogger()->trace(__VA_ARGS__)
#define NIKA_INFO(...)			::Nika::Log::getCoreLogger()->info(__VA_ARGS__)
#define NIKA_WARN(...)			::Nika::Log::getCoreLogger()->warn(__VA_ARGS__)
#define NIKA_ERROR(...)			::Nika::Log::getCoreLogger()->error(__VA_ARGS__)
#define NIKA_FATAL(...)			::Nika::Log::getCoreLogger()->fatal(__VA_ARGS__)

// --- client log macros ---
#define CLIENT_TRACE(...)		::Nika::Log::getClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...)		::Nika::Log::getClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...)		::Nika::Log::getClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...)		::Nika::Log::getClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...)		::Nika::Log::getClientLogger()->fatal(__VA_ARGS__)

