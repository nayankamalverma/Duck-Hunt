#include "../../../Header/Element/ScoreService.h"
#include "../../../Header/UI/InstructionMenu/InstructionUIController.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Graphics//GraphicService.h"

namespace UI
{
	namespace InstructionMenu
	{
		InstructionUIController::InstructionUIController() {}

		void InstructionUIController::initialize(sf::RenderWindow* window)
		{
			BaseUIController::initialize(window);
		}

		void InstructionUIController::update()
		{
			processButtonInteractions();
		}

		void InstructionUIController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();
			if (event_service->pressedLeftMouseButton())
			{
				if (mouse_position.x > 1060 && mouse_position.x < 1150) //Since all buttons are in a perfect column, they will all be in this x range
				{
					if (mouse_position.y > 20 && mouse_position.y < 100) //if cursor is in y range for play button
					{
						Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
						Main::GameService::setGameState(Main::GameState::MAIN_MENU);
					}
				}
			}
		}


	}

}
