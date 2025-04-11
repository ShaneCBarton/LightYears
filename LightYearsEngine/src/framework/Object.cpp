#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	Object::Object() :
		bIsPendingDestruction{false}
	{

	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}

	void Object::Destroy()
	{
		bIsPendingDestruction = true;
	}
}
