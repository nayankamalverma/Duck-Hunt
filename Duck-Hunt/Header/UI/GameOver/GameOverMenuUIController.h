#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace GameOverMenu
	{
		class GameOverMenuUIController
		{
		private:
			const sf::String background_texture_path = "assets/textures/3.png";

			sf::RenderWindow* game_window;

			// Textures:
			sf::Texture background_texture;
			sf::Sprite background_sprite;
			sf::Font font;
			sf::Text highScoreText;
			sf::Text scoreText;

			void initializeBackgroundImage();
			void scaleBackgroundImage();


			void processButtonInteractions();

		public:
			GameOverMenuUIController();

			void initialize();
			void update();
			void render();

		};
	}
}
