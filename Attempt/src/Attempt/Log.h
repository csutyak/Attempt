#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Attempt
{
	class ATTEMPT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define AMT_CORE_TRACE(...)  ::Attempt::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AMT_CORE_INFO(...)   ::Attempt::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AMT_CORE_WARN(...)   ::Attempt::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AMT_CORE_ERROR(...)  ::Attempt::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AMT_CORE_FATAL(...)  ::Attempt::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define AMT_TRACE(...)       ::Attempt::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AMT_INFO(...)        ::Attempt::Log::GetClientLogger()->info(__VA_ARGS__)
#define AMT_WARN(...)        ::Attempt::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AMT_ERROR(...)       ::Attempt::Log::GetClientLogger()->error(__VA_ARGS__)
#define AMT_FATAL(...)       ::Attempt::Log::GetClientLogger()->fatal(__VA_ARGS__)


