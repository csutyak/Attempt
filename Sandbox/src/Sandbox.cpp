#include <Attempt.h>

class Sandbox : public Attempt::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Attempt::Application* Attempt::CreateApplication()
{
	return new Sandbox();
}