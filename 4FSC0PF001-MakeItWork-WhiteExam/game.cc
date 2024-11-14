#include "game.hpp"



void Game::Setup()
{

	window.create(sf::VideoMode(1280, 720), "4FSC0PF001 - Summative exam");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);




	int steps_x = (int)std::floor(((float)window.getSize().x - 2.f * KInvaderMargin) / KInvaderSpacing);
	float invader_line_altitude = 0.5f * (float)window.getSize().y;


	// Affectation des invaders
	for (int y = 0; y <= kInvadersNbLines; y++)
	{
		for (int x = 0; x <= steps_x; x++)
		{
			invaders.emplace_back(sf::RectangleShape({ 15, 15 }));
			// Define the invaders
			invaders.back().setOrigin(7.5, 7.5);
			invaders.back().setPosition(KInvaderMargin + x * KInvaderSpacing, invader_line_altitude);
			invaders.back().setFillColor(sf::Color::Red);
		}

		invader_line_altitude -= KInvaderSpacing;

	}
}


void Game::Loop()
{

	float player_position = (float)window.getSize().x * 0.5f;

	while (window.isOpen())
	{

		// Input controls and actions
		// Non events----------------------------------
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock_projectiles_.getElapsedTime().asSeconds() > kShootingRateAsSeconds)
		{
			projectiles.emplace_back(player.GetPosition().x, player.GetPosition().y - 25);

			// Reset timer
			clock_projectiles_.restart();
		}

		// Events -------------------------------------
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{

			case sf::Event::MouseMoved:
				player_position = std::floor(event.mouseMove.x);
				break;

				// evenement "fermeture demandee" : on ferme la fenetre
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}

		}

		// Game play frame ==================================================================================================================================
		// Move the player
		player.SetPosition(
			{ kSmoothRatio * player_position + (1.F - kSmoothRatio) * player.GetPosition().x,
				player.kPlayerAltitude
			}
		);

		// Move the projectiles
		for (auto& p : projectiles)
		{
			p.SetPosition(p.GetPosition() + kProjectilesSpeed);
		}

		// Clean the projectiles
		auto projectiles_it = std::remove_if(projectiles.begin(), projectiles.end(), [](Projectile& p) {return p.GetPosition().y < 0; });
		projectiles.erase(projectiles_it, projectiles.end());

		// KaBooom ?? ================================================================================================================================
		for (auto& i : invaders)
		{

			if (i.getFillColor() == sf::Color::Black)
				continue;

			for (auto& p : projectiles)
			{

				if (p.GetFillColor() == sf::Color::Black)
					continue;

				if (i.getGlobalBounds().intersects(p.GetGlobalBounds()))
				{
					// Boom ----------------------------------------------------------------------------
					p.SetFillColor(sf::Color::Black);
					i.setFillColor(sf::Color::Black);
				}
			}
		}

		// Clean the projectiles
		auto projectiles_boomed_it = std::remove_if(projectiles.begin(), projectiles.end(), [](Projectile& p) {return p.GetFillColor() == sf::Color::Black; });
		projectiles.erase(projectiles_boomed_it, projectiles.end());

		// Clean the invaders
		auto invader_clean = std::remove_if(invaders.begin(), invaders.end(), [](sf::RectangleShape& i) {return i.getFillColor() == sf::Color::Black; });
		invaders.erase(invader_clean, invaders.end());

		//std::cout << "Projectiles remaining count " << projectiles.size() << std::endl;

		// Graphical frame ==================================================================================================================================
		window.clear();

		for (auto& i : invaders)
		{
			window.draw(i);
		}
		for (auto& p : projectiles)
		{
			window.draw(p);
		}

		window.draw(player);

		window.display();

	}
}
