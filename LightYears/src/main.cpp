#include <memory>

#include "framework/application.h"

int main()
{
	std::unique_ptr<ly::Application> application(new ly::Application());
	application->Run();
}