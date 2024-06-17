#pragma once
#include <SFML/Graphics.hpp>

namespace GamePlay
{
	class GamePlayUIController
	{
		sf::RenderWindow* game_window;

		const sf::String background_texture_path = "assets/textures/background.png";
		const sf::String tree_texture_path = "assets/textures/tree_1.png-";
		const sf::String grass_texture_path = "Assets/textures/NES - Duck Hunt - The Dog-Smell.png-";

		sf::Texture background_texture;
		sf::Sprite background_sprite;
		sf::Texture tree_texture;
		sf::Sprite tree_sprite;
		sf::Texture grass_texture;
		sf::Sprite grass_sprite;


		void initializeBackgroundImage();
		void scaleBackgroundImage();

	public:
		GamePlayUIController();

		void initialize();
		void update();
		void render();
	};
}
