#include "Basil.h"

class Sandbox : public Basil::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Basil::Application* Basil::CreateApplication()
{
	return new Sandbox();
}