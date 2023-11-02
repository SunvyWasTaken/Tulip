#pragma once

#ifdef TL_PLATFORM_WINDOWS

extern Tulip::Application* Tulip::CreateApplication();

// Permet de faire en sorte d'avoir une fenetre qui varie en fonction de la build source...
int main(int argc, char** argv)
{
	// Init les loggers.
	Tulip::Log::Init();
	// Test d'utilisation du logger CORE
	TL_CORE_WARN("Initlized Log!");
	// Test Logger Client
	int a = 5;
	TL_CLIENT_INFO("Hello! var = {0}", a);

	//auto app = Tulip::CreateApplication();
	//app->Run();
	//delete app;
}

#endif // TP_PLATFORM_WINDOWS
