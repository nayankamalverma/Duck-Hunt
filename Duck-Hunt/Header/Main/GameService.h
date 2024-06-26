#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Global/ServiceLocator.h"

namespace Main
{
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		INSTRUCTION,
		GAMEPLAY,
		PAUSE,
		GAME_OVER
	};

	class GameService
	{
	private:
		static GameState current_state;

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void showMainMenu();
		void destroy();

	public:
		GameService();
		virtual ~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}