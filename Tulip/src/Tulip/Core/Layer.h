#pragma once
#include "Core.h"
#include "Tulip/Events/Event.h"

namespace Tulip
{
	class TULIP_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}


		// Partie pour pouvoir print dans le Debug.
		inline const std::string& GetName() const { return m_DebugName; };
	protected:
		std::string m_DebugName;
	};

}

