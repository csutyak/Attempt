#pragma once

#ifdef AMT_PLATFORM_WINDOWS

extern Attempt::Application* Attempt::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Attempt::CreateApplication();
	app->Run();
	delete app;
}


#endif 