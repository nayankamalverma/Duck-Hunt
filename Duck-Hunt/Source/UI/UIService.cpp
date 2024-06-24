#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace GamePlayUI;
	using namespace PauseMenu;
	using namespace GameOverMenu;
	using namespace Element;
	using namespace InstructionMenu;


	UIService::UIService()
	{
		game_window = nullptr;
		main_menu_controller = nullptr;
		game_play_controller = nullptr;
		pause_menu_controller = nullptr;
		game_over_menu_controller = nullptr;
		instruction_ui_controller = nullptr;
		createControllers();
	}


	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		game_play_controller = new GamePlayUIController();
		pause_menu_controller = new PauseMenuUIController();
		game_over_menu_controller = new GameOverMenuUIController();
		instruction_ui_controller = new InstructionUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeControllers();
	}

	void UIService::update()
	{
		if(GameService::getGameState()==GameState::GAMEPLAY)
		{
			Event::EventService* event = Global::ServiceLocator::getInstance()->getEventService();
			if(( event->pressedEscapeKey()) && GameService::getGameState() == GameState::GAMEPLAY)
			{
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
				GameService::setGameState(GameState::PAUSE);
			}
		}
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->update();
			break;
		case GameState::INSTRUCTION:
			return instruction_ui_controller->update();
			break;
		case GameState::GAMEPLAY:
			return game_play_controller->update();
			break;
		case GameState::PAUSE:
			return pause_menu_controller->update();
			break;
		case GameState::GAME_OVER:
			return game_over_menu_controller->update();
			break;
		default:
			printf("Ui service default update");
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
		case GameState::INSTRUCTION:
			return instruction_ui_controller->render();
			break;
		case GameState::GAMEPLAY :
			return 	 game_play_controller->render();
			break;
		case GameState::PAUSE:
			return pause_menu_controller->render();
		case GameState::GAME_OVER:
			return game_over_menu_controller->render();
			break;
		default:
			printf("Ui service default render");
			break;
		}
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize(game_window);
		game_play_controller->initialize(game_window);
		pause_menu_controller->initialize(game_window);
		game_over_menu_controller->initialize(game_window);
		instruction_ui_controller->initialize(game_window);
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
		delete(game_play_controller);
		delete(pause_menu_controller);
		delete(game_over_menu_controller);
		delete(instruction_ui_controller);
	}
}