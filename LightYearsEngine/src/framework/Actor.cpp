#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: OwningWorld{ owningWorld },
		HasBeganPlay{false},
		Sprite{},
		Texture{}
	{
		SetTexture(texturePath);
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

	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestruction())
		{
			Tick(deltaTime);
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

	void Actor::SetTexture(const std::string& texturePath)
	{
		Texture.loadFromFile(texturePath);
		Sprite.setTexture(Texture);

		int textureWidth = Texture.getSize().x;
		int textureHeight = Texture.getSize().y;
		Sprite.setTextureRect(sf::IntRect(sf::Vector2i{}, sf::Vector2i{ textureWidth, textureHeight }));
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestruction()) return;

		window.draw(Sprite);
	}
}