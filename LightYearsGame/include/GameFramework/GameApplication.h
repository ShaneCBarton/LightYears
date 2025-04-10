#pragma once
#include <framework/application.h>
#include <framework/Core.h>

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void Tick(float deltaTime) override;

	private:
		float Counter;
		weak<Actor> ActorToDestroy;
	};
}