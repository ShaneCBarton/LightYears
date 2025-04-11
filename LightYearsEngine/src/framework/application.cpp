#include "framework/application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: RenderWindow{ sf::VideoMode(windowWidth, windowHeight), title, style},
		  TargetFrameRate{ 60.f },
		  TickClock{},
		  CurrentWorld{ nullptr }
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
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);

		if (CurrentWorld)
		{
			CurrentWorld->TickInternal(deltaTime);
		}

	}

	void Application::RenderInternal()
	{
		RenderWindow.clear();

		Render();

		RenderWindow.display();
	}

	void Application::Render()
	{
		if (CurrentWorld)
		{
			CurrentWorld->Render(RenderWindow);
		}
	}

	void Application::Tick(float deltaTime)
	{
	}
}