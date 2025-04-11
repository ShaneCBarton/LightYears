#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld)
		: OwningWorld{ owningWorld },
		HasBeganPlay{false}
	{

	}

	Actor::~Actor()
	{
		LOG("Actor destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!HasBeganPlay)
		{
			HasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor began play.");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor ticking");
	}
}