#pragma once
#include "Core.h"

namespace Tulip{
	// Objet qui fait tourné l'application.
	class TULIP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// A définir dans le CLIENT
	Application* CreateApplication();
}
