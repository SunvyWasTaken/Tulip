#include <Tulip.h>

class ExampleLayer : public Tulip::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		TL_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Tulip::Event& event) override
	{
		TL_CLIENT_TRACE("{0}", event.ToString());
	}
};

// Class enfant pour comme un truc sur unreal engine
class Sandbox : public Tulip::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

// ça je crois que c'est genre un instance de mon engine... -_-
Tulip::Application* Tulip::CreateApplication()
{
	return new Sandbox();
}