#pragma once
#include "Core.h"

namespace Tulip{
	// Objet qui fait tourn� l'application.
	class TULIP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// A d�finir dans le CLIENT
	Application* CreateApplication();
}
