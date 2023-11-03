#include "tlpch.h"
#include "Application.h"

#include "Tulip/Events/ApplicationEvent.h"
#include "Tulip/Core/Log.h"

#include <GLFW/glfw3.h>

namespace Tulip{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
		
	}
	// Permet d'avoir la boucle 
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}