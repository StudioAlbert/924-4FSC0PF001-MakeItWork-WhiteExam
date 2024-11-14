#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

class Projectile: public sf::Drawable
{

	sf::RectangleShape rectangle;

public:
	Projectile(int x, int y);

	sf::Vector2f GetPosition() { return rectangle.getPosition(); }

	void SetPosition(sf::Vector2f position)
	{
		rectangle.setPosition(position);
	}

	void SetFillColor(sf::Color color) { rectangle.setFillColor(color); };
	sf::Color GetFillColor() { return rectangle.getFillColor(); };

	sf::FloatRect GetGlobalBounds() { return  rectangle.getGlobalBounds(); };

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

