#include "GameFramework/GameApplication.h"
#include "framework/Actor.h"
#include "framework/World.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{ 600, 980, "Plain Planes", sf::Style::Titlebar | sf::Style::Close}
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		ActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		ActorToDestroy.lock()->SetTexture(GetResourceDir() + "/Ships/ship_0005.png");
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