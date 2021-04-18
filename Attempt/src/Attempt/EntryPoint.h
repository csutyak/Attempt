#pragma once

#ifdef AMT_PLATFORM_WINDOWS

extern Attempt::Application* Attempt::CreateApplication();

int main(int argc, char** argv)
{
	Attempt::Log::Init();
	AMT_CORE_WARN("Initialized Log!");
	int a = 10;
	AMT_ERROR("Howdy! var={0}",a);

	auto app = Attempt::CreateApplication();
	app->Run();
	delete app;
}


#endif 