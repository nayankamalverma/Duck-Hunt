#pragma once
#include "BaseUIController.h"
#include "MainMenu/MainMenuUIController.h"
#include "GamePlay/GamePlayUIController.h"
#include "PauseMenu/PauseMenuUIcontroller.h"
#include "GameOver/GameOverMenuUIController.h"
#include "InstructionMenu/InstructionUIController.h"

namespace UI
{
	class UIService				   
	{
	private:
		sf::RenderWindow* game_window;

		BaseUIController* main_menu_controller;
		BaseUIController* game_play_controller;
		BaseUIController* pause_menu_controller;
		BaseUIController* game_over_menu_controller;
		BaseUIController* instruction_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
	};
}
