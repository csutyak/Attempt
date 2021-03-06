#pragma once

#include "Core.h"

#include "Window.h"
#include "Attempt/LayerStack.h"
#include "Attempt/Events/Event.h"
#include "Attempt/Events/ApplicationEvent.h"

namespace Attempt
{
	class ATTEMPT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	Application* CreateApplication();
}


