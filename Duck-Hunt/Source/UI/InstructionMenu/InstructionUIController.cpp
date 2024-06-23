#include "../../../Header/Element/ScoreService.h"
#include "../../../Header/UI/InstructionMenu/InstructionUIController.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Graphics//GraphicService.h"

namespace UI
{
	namespace InstructionMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		InstructionUIController::InstructionUIController()
		{
			game_window = nullptr;

		}

		void InstructionUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
		}

		void InstructionUIController::initializeBackgroundImage()
		{

			if (background_texture.loadFromFile(background_texture_path))
			{
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}

		void InstructionUIController::scaleBackgroundImage()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		void InstructionUIController::update()
		{
			processButtonInteractions();
		}

		void InstructionUIController::render()
		{
			game_window->draw(background_sprite);
		}

		void InstructionUIController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			if (event_service->pressedLeftMouseButton())
			{
				printf("%f _ %f\n,", mouse_position.x, mouse_position.y);
				if (mouse_position.x > 1060 && mouse_position.x < 1150) //Since all buttons are in a perfect column, they will all be in this x range
				{
					if (mouse_position.y > 20 && mouse_position.y < 100) //if cursor is in y range for play button
					{
						ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
						GameService::setGameState(GameState::MAIN_MENU);
					}
				}
			}
		}


	}

}
