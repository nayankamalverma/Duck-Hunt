#pragma once
#include <SFML/Graphics.hpp>

namespace Graphic {

	class GraphicService
	{
		const std::string game_window_title = "Duck Hunt";

		const int game_window_width = 1920;
		const int game_window_height = 1080;

		const sf::Color window_color = sf::Color::Blue;

		sf::VideoMode* video_mode; // ptr to video mode
		sf::RenderWindow* game_window; // ptr to a RenderWindow

		void setVideoMode();
		void onDestroy();

	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* createGameWindow();

		void initialize(); //lifecycle functions
		void update(); //..
		void render(); //..
		bool isGameWindowOpen(); //check if the window is open

		sf::RenderWindow* getGameWindow(); //getter for the game window instance
		sf::Color getWindowColor();//get the color
	};
}