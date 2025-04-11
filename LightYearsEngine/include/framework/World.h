#pragma once
#include "framework/Core.h"

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owningApp);
		
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual ~World();
		void Render(sf::RenderWindow& window);

		template <typename ActorType>
		weak<ActorType> SpawnActor();

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* OwningApp;
		bool BeganPlay;

		List<shared<Actor>> Actors;
		List<shared<Actor>> PendingActors;
	};

	template <typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		PendingActors.push_back(newActor);
		return newActor;
	}
}