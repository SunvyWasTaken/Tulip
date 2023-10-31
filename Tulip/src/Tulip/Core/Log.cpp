#include "tlpch.h"
#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Tulip
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Donne le format du message log qu'on veut.
		// Avec la couleur, le temps et le message qui doit etre print.
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Set le nom du logger core.
		s_CoreLogger = spdlog::stdout_color_mt("TULIP");
		s_CoreLogger->set_level(spdlog::level::trace);
		// Set le nom du logger Client.
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}