#include <Attempt.h>

class ExampleLayer : public Attempt::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		AMT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Attempt::Event& event) override
	{
		AMT_TRACE("{0}", event);
	}
};

class Sandbox : public Attempt::Application
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

Attempt::Application* Attempt::CreateApplication()
{
	return new Sandbox();
}