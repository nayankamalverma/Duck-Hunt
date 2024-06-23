#pragma once
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "GamePlay/GamePlayUIController.h"
#include "PauseMenu/PauseMenuUIcontroller.h"
#include "GameOver/GameOverMenuUIController.h"
#include "InstructionMenu/InstructionUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		GamePlay::GamePlayUIController* game_play_controller;
		PauseMenu::PauseMenuUIController* pause_menu_controller;
		GameOverMenu::GameOverMenuUIController* game_over_menu_controller;
		InstructionMenu::InstructionUIController* instruction_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}
