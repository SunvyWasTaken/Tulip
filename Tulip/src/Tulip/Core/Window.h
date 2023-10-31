#pragma once
#include "tlpch.h"

#include "Core.h"
#include "Tulip/Events/Event.h"

namespace Tulip
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& _title = "Tulip Engine",
					unsigned int _width = 1280,
					unsigned int _height = 720)
			: Title(_title), Width(_width), Height(_height)
		{}
	};

	// Interface representing une fenetre de base sur un ordinateur.
	class TULIP_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Fenetre attribut
		virtual void SetEventCallBack(const EventCallBackFn& _callback) = 0;
		virtual void SetVSync(bool _enable) = 0;
		virtual void IsVSync() const = 0;

		static Window* Create(const WindowProps& _props = WindowProps());

	};
}