#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/common.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Basil {
	class BASIL_API Log
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

// Core log macros
#define BASIL_CORE_TRACE(...) ::Basil::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BASIL_CORE_INFO(...) ::Basil::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BASIL_CORE_WARN(...) ::Basil::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BASIL_CORE_ERROR(...) ::Basil::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BASIL_CORE_FATAL(...) ::Basil::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BASIL_TRACE(...) ::Basil::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BASIL_INFO(...) ::Basil::Log::GetClientLogger()->info(__VA_ARGS__)
#define BASIL_WARN(...) ::Basil::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BASIL_ERROR(...) ::Basil::Log::GetClientLogger()->error(__VA_ARGS__)
#define BASIL_FATAL(...) ::Basil::Log::GetClientLogger()->fatal(__VA_ARGS__)