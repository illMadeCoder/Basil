#pragma once

#ifdef BASIL_PLATFORM_WINDOWS

extern Basil::Application* Basil::CreateApplication();

int main(int argc, char** argv)
{

	Basil::Log::Init();
	BASIL_CORE_WARN("Initialized Log!");
	int a = 5;
	BASIL_INFO("Hello Var={0}", a);

	auto app = Basil::CreateApplication();
	app->Run();
	delete app;
}

#endif 