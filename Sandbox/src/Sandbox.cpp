#include <Tulip.h>

class Sandbox : public Tulip::Application
{
	public:
};

// ça je crois que c'est genre un instance de mon engine... -_-
Tulip::Application* Tulip::CreateApplication()
{
	return new Sandbox();
}