#pragma once
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Player.h"
#include "Projectile.hpp"

class Game
{

	sf::RenderWindow window;

	// Constants
	const float KInvaderMargin = 150;
	const float KInvaderSpacing = 20;
	const float kInvadersNbLines = 15;

	const float kSmoothRatio = 0.15f;
	const float kShootingRateAsSeconds = 0.15f;


	// Time ----------------------------------------------------------------------------------
	sf::Clock clock_projectiles_;

	// Game elements -------------------------------------------------------------------------
	// Ennemies
	std::vector<sf::RectangleShape> invaders;

	// Projectiles
	std::vector<Projectile> projectiles;

	const sf::Vector2f kProjectilesSpeed = { 0, -32.45636365 };

	Player player;

public:
	void Setup();
	void Loop();

};

