#include "tlpch.h"
#include "Application.h"

#include "Tulip/Core/Log.h"

#include <glad/glad.h>

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

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		TL_CORE_TRACE("{0}", e.ToString());

		// auto it = end() -> start the iteration from the end
		// it != begin() -> Is the iterator condition for the for
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			// --it -> make the decrementation on the loop
			// *it -> Get the pointeur of the layer so it can call the OnEvent function
			(*--it)->OnEvent(e);
			// Check if the event has been handle so it doesn't propagat further down
			if (e.Handled)
				break;
		}
	}

	// Permet d'avoir la boucle 
	void Application::Run()
	{
		while (m_Running)
		{
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}