#pragma once
#include "Tulip/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Tulip
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }


		inline void SetEventCallBack(const EventCallBackFn& _callback) override { m_Data.EventCallBack = _callback; }
		void SetVSync(bool _enable) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		// Struct utilisé pour juste à avoir à send la struct to GLFM et non toute la class
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBackFn EventCallBack;
		};

		WindowData m_Data;
	};
}

