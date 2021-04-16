#pragma once

#include "Core.h"

namespace Attempt
{
	class ATTEMPT_API Application
	{
	public:
		Application() {}
		virtual ~Application() {}
		void Run();

	};

	Application* CreateApplication();
}


