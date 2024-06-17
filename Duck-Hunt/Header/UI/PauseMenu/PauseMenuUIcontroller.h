#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace PauseMenu
	{
		class PauseMenuUIController
		{
		private:
			const sf::String background_texture_path = "assets/textures/2.png";

			sf::RenderWindow* game_window;

			// Textures:
			sf::Texture background_texture;
			sf::Sprite background_sprite;
			
			void initializeBackgroundImage();
			void scaleBackgroundImage();


			void processButtonInteractions();

		public:
			PauseMenuUIController();

			void initialize();
			void update();
			void render();

		};
	}
}
