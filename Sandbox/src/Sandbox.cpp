#include <Tulip.h>

// Class enfant pour comme un truc sur unreal engine
class Sandbox : public Tulip::Application
{
	public:
};

// �a je crois que c'est genre un instance de mon engine... -_-
Tulip::Application* Tulip::CreateApplication()
{
	return new Sandbox();
}