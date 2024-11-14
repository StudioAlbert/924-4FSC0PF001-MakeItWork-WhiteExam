#include "Player.h"

#include <SFML/Graphics/RenderTarget.hpp>

Player::Player()
{
	//kPlayerAltitude = 75;
	circle.setOrigin(2.5, 2.5);
	circle.setFillColor(sf::Color(92, 88, 168));
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(1);

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle);
}

