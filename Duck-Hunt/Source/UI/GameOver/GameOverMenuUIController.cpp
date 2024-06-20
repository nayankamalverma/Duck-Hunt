#include "../../../Header/UI/GameOver/GameOverMenuUIcontroller.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Graphics//GraphicService.h"

namespace UI
{
	namespace GameOverMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		GameOverMenuUIController::GameOverMenuUIController()
		{
			game_window = nullptr;
		}

		void GameOverMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
		}

		void GameOverMenuUIController::initializeBackgroundImage()
		{

			if (background_texture.loadFromFile(background_texture_path))
			{
				printf("\nbg GameOverMenuUIController\n");
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}

		void GameOverMenuUIController::scaleBackgroundImage()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		void GameOverMenuUIController::update()
		{
			processButtonInteractions();
		}

		void GameOverMenuUIController::render()
		{
			game_window->draw(background_sprite);
		}

		void GameOverMenuUIController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			if (event_service->pressedLeftMouseButton())
			{
				if (mouse_position.x > 430 && mouse_position.x < 830) //Since all buttons are in a perfect column, they will all be in this x range
				{
					if (mouse_position.y > 275 && mouse_position.y < 345) //if cursor is in y range for play button
					{
						GameService::setGameState(GameState::GAMEPLAY);
					}
					else if (mouse_position.y > 380 && mouse_position.y < 450) //if cursor is in y range for 'how to play' button
					{
						GameService::setGameState(GameState::MAIN_MENU);
					}
				}
			}
		}


	}

}
