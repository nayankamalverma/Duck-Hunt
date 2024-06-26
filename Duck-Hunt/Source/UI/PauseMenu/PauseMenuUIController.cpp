#include "../../../Header/Element/ScoreService.h"
#include "../../../Header/UI/PauseMenu/PauseMenuUIcontroller.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Graphics//GraphicService.h"

namespace UI
{
	namespace PauseMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		PauseMenuUIController::PauseMenuUIController()
		{
		}
		void PauseMenuUIController::initialize(sf::RenderWindow* window)
		{
			game_window = window;
			BaseUIController::initialize(window);

			if (!font.loadFromFile("assets/phenomicon.ttf"))
			{
				printf("font not found.");
			}
			highScoreText.setFont(font);
			highScoreText.setFont(font);
			highScoreText.setCharacterSize(50);
			highScoreText.setPosition(510, 180);
			highScoreText.setFillColor(sf::Color::Yellow);
		}

		void PauseMenuUIController::update()
		{
			 highScoreText.setString("HighScore : " + std::to_string(Element::ScoreService::getInstance().getHighScore()));
			 processButtonInteractions();
		}

		void PauseMenuUIController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(highScoreText);
		}

		void PauseMenuUIController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			if (event_service->pressedLeftMouseButton())
			{
				if (mouse_position.x > 430 && mouse_position.x < 830) //Since all buttons are in a perfect column, they will all be in this x range
				{
					if (mouse_position.y > 275 && mouse_position.y < 345) //if cursor is in y range for play button
					{
						Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
						GameService::setGameState(GameState::GAMEPLAY);
					}
					else if (mouse_position.y > 380 && mouse_position.y < 450) //if cursor is in y range for 'how to play' button
					{
						Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
						GameService::setGameState(GameState::MAIN_MENU);
						
					}
				}
			}
		}


	}

}
