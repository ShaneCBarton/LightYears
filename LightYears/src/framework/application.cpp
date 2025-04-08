#include <iostream>

#include "framework/application.h"

namespace ly
{
	Application::Application()
		: RenderWindow{ sf::VideoMode(1920, 1080), "Light Years" },
		TargetFrameRate{ 60.f },
		TickClock{}
	{
		
	}

	void Application::Run()
	{
		TickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / TargetFrameRate;

		while (RenderWindow.isOpen())
		{
			sf::Event windowEvent;
			while (RenderWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					RenderWindow.close();
				}
			}
			float frameDeltaTime = TickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}
			std::cout << "Ticking at FR: " << 1.f / frameDeltaTime << std::endl;
		}
	}

	void Application::Tick(float deltaTime)
	{

	}

	void Application::Render()
	{

	}
}