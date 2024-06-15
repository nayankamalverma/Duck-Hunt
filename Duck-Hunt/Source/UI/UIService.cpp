#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace GamePlay;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		game_play_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		game_play_controller = new GamePlayUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->update();
			break;
		case GameState::GAMEPLAY:
			return; game_play_controller->update();
			break;
		}
		
	}

	void UIService::render()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->render();
			break;
		case GameState::GAMEPLAY :
			return 	 game_play_controller->render();
		}
	}

	void UIService::showScreen()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->show();
		}
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		game_play_controller->initialize();
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
		delete(game_play_controller);
	}
}