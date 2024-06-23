#include "../../../Header/Element/ScoreService.h"
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

			//text
			if (!font.loadFromFile("assets/phenomicon.ttf"))
			{
				printf("font not found.");
			}
			highScoreText.setFont(font);
			highScoreText.setCharacterSize(50);
			highScoreText.setPosition(450, 280);
			highScoreText.setFillColor(sf::Color::Yellow);

			scoreText.setFont(font);
			scoreText.setCharacterSize(50);
			scoreText.setPosition(450, 340);
			scoreText.setFillColor(sf::Color::Yellow);
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
			highScoreText.setString("HighScore : "+ std::to_string(Element::ScoreService::getInstance().getHighScore()));
			scoreText.setString("Score : " + std::to_string(Element::ScoreService::getInstance().getScore()));
			processButtonInteractions();
		}

		void GameOverMenuUIController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(highScoreText);
			game_window->draw(scoreText);
		}

		void GameOverMenuUIController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			if (event_service->pressedLeftMouseButton())
			{
				if (mouse_position.x > 425 && mouse_position.x < 830)
				{
					if (mouse_position.y > 415 && mouse_position.y < 485)
					{
						Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
						GameService::setGameState(GameState::MAIN_MENU);
					}
				}
			}
		}
	}
}