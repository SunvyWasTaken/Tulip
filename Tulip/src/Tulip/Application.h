#pragma once
#include "Core.h"

namespace Tulip{
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
