#pragma once
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Tulip/Events/Event.h"
#include "Tulip/Events/ApplicationEvent.h"


namespace Tulip{
	// Objet qui fait tourn� l'application.
	class TULIP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		// Dispatch all event throw the application
		// Call � chaque event.
		void OnEvent(Event& e);

		void PushOverlay(Layer* layer);
		void PushLayer(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return* m_Window; }

	private:

		bool OnWindowClose(class WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// A d�finir dans le CLIENT
	Application* CreateApplication();
}
