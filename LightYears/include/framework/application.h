#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		void Tick(float deltaTime);
		void Render();

		sf::RenderWindow RenderWindow;
		float TargetFrameRate;
		sf::Clock TickClock;
	};
}
