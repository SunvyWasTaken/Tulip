#pragma once

#ifdef TL_PLATFORM_WINDOWS

extern Tulip::Application* Tulip::CreateApplication();

// Permet de faire en sorte d'avoir une fenetre qui varie en fonction de la build source...
int main(int argc, char** argv)
{
	auto app = Tulip::CreateApplication();
	app->Run();
	delete app;
}

#endif // TP_PLATFORM_WINDOWS
