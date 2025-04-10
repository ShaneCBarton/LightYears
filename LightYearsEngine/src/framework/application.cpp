#include "framework/application.h"
#include "framework/Core.h"

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
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
			LOG("Ticking at FR: %f", 1.f / frameDeltaTime);
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void Application::RenderInternal()
	{
		RenderWindow.clear();

		Render();

		RenderWindow.display();
	}

	void Application::Render()
	{
		sf::RectangleShape rectangle{ sf::Vector2f(100, 100) };
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setOrigin(50, 50);
		rectangle.setPosition(RenderWindow.getSize().x / 2.f, RenderWindow.getSize().y / 2.f);

		RenderWindow.draw(rectangle);
	}

	void Application::Tick(float deltaTime)
	{
	}
}