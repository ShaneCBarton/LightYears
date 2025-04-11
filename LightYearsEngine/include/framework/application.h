#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style);
		void Run();

		template<typename WorldType>
		weak<World> LoadWorld();

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow RenderWindow;
		float TargetFrameRate;
		sf::Clock TickClock;

		shared<World> CurrentWorld;
	};

	template<typename WorldType>
	weak<World> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		CurrentWorld = newWorld;
		CurrentWorld->BeginPlayInternal();
		return newWorld;
	}
}
