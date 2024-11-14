#pragma once
#include <SFML/Graphics/CircleShape.hpp>

class Player : public sf::Drawable
{
	// Player
	sf::CircleShape circle = sf::CircleShape(5, 3);

public:

	const float kPlayerAltitude = 700;

	Player();

	sf::Vector2f GetPosition() { return circle.getPosition(); }

	void SetPosition(sf::Vector2f position)
	{
		circle.setPosition(position);
	}

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

