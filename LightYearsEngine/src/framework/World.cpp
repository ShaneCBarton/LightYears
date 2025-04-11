#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owningApp)
		: OwningApp{ owningApp },
		BeganPlay{false},
		Actors{},
		PendingActors{}
	{

	}

	void World::BeginPlayInternal()
	{
		if (!BeganPlay)
		{
			BeganPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : PendingActors)
		{
			Actors.push_back(actor);
			actor->BeginPlayInternal();
		}
		PendingActors.clear();

		for (shared<Actor> actor : Actors)
		{
			actor->Tick(deltaTime);
		}

		Tick(deltaTime);
	}

	World::~World()
	{
	}

	void World::BeginPlay()
	{
		LOG("Began play.");
	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at framerate: %f", 1.f / deltaTime);
	}
}