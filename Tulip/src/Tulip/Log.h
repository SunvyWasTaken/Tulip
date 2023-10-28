#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory.h>

namespace Tulip {
	class TULIP_API Log
	{
	public:
		static void Init();
		// Return le Pointeur vers le Log de l'engine
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		// Return le Pointeur vers le Log du l'application
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log
// Macro pour �viter d'avoir � tous r�crire.
#define TL_CORE_TRACE(...)		::Tulip::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define TL_CORE_INFO(...)		::Tulip::Log::GetCoreLogger()->info(__VA_ARGS__);
#define TL_CORE_WARN(...)		::Tulip::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define TL_CORE_ERROR(...)		::Tulip::Log::GetCoreLogger()->error(__VA_ARGS__);
#define TL_CORE_FATAL(...)		::Tulip::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log
// Macro pour le client � use dans l'application.
#define TL_CLIENT_TRACE(...)	::Tulip::Log::GetClientLogger()->trace(__VA_ARGS__);
#define TL_CLIENT_INFO(...)		::Tulip::Log::GetClientLogger()->info(__VA_ARGS__);
#define TL_CLIENT_WARN(...)		::Tulip::Log::GetClientLogger()->warn(__VA_ARGS__);
#define TL_CLIENT_ERROR(...)	::Tulip::Log::GetClientLogger()->error(__VA_ARGS__);
#define TL_CLIENT_FATAL(...)	::Tulip::Log::GetClientLogger()->fatal(__VA_ARGS__);
