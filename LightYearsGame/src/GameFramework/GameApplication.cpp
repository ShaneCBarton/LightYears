#include "GameFramework/GameApplication.h"
#include "framework/Actor.h"
#include "framework/World.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		ActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		Counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		Counter += deltaTime;
		if (Counter > 2.f)
		{
			if (!ActorToDestroy.expired())
			{
				ActorToDestroy.lock()->Destroy();
			}
		}
	}
} 