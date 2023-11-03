#pragma once
#include "Core.h"
#include "Tulip/Events/Event.h"
#include "Window.h"

namespace Tulip{
	// Objet qui fait tourn� l'application.
	class TULIP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:

		bool OnWindowClose(class WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
	};

	// A d�finir dans le CLIENT
	Application* CreateApplication();
}
