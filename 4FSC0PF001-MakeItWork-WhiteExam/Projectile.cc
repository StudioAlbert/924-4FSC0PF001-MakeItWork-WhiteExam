#include "Projectile.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

Projectile::Projectile(int x, int y)
{
	rectangle = sf::RectangleShape({ 3, 60 });

	rectangle.setOrigin(1.5, 5);
	rectangle.setPosition(x, y);
	rectangle.setFillColor(sf::Color::White);

	//projectiles.emplace_back(sf::RectangleShape({ 3, 60 }));
	//// Define the projectiles
	//projectiles.back().setOrigin(1.5, 5);
	//projectiles.back().setPosition(player.GetPosition().x, player.GetPosition().y - 25);
	//projectiles.back().setFillColor(sf::Color::White);

}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
