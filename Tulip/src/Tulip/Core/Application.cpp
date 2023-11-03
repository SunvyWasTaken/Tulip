#include "tlpch.h"
#include "Application.h"

#include "Tulip/Events/ApplicationEvent.h"
#include "Tulip/Core/Log.h"

#include <GLFW/glfw3.h>

namespace Tulip{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		TL_CORE_INFO("{0}", e.ToString());
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