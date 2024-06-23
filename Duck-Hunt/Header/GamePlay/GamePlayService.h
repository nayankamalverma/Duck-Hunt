#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Element/DuckService.h"
#include "../Event/EventService.h"

namespace GamePlay
{
	class GamePlayService
	{
	private:

		sf::RenderWindow* game_window;
		Event::EventService* event_service;
		Element::DuckService* duck_service;

		sf::Font font;
		sf::Text ammoText;
		sf::Text healthText;
		sf::Clock roundTimer;
		sf::Text waveText;
		sf::Text scoreText;

		const int initialAmmo = 5;
		const int initialHealth = 5;
		int noOfDucks;

		int health;
		int score;
		int ammo;
		int wave;
		sf::Time roundTimeLimit = sf::seconds(15.f);
		

		bool isGameOver;
	public:
		GamePlayService();
		~GamePlayService();

		void initialize();
		void update();
		void render();

		void initText();
		void resetRound();
		void handleMouseClick(sf::Vector2i mousePosition);

	};
}
