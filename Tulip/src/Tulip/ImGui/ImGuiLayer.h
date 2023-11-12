#pragma once

#include "Tulip/Core/Layer.h"

namespace Tulip
{
	class TULIP_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.f;
	};
}

