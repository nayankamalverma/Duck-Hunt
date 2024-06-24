#include "../../../header/UI/MainMenu/MainMenuUIController.h"

#include "../../../Header/Element/ScoreService.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;

        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize(sf::RenderWindow* window)
        {
            game_window = window;
            BaseUIController::initialize(window);
            //text
            if (!font.loadFromFile("assets/phenomicon.ttf"))
            {
                printf("font not found.");
            }
            highScoreText.setFont(font);
            highScoreText.setFont(font);
            highScoreText.setCharacterSize(50);
            highScoreText.setPosition(10.f, 10.f);
            highScoreText.setFillColor(sf::Color::Yellow);
        }

        void MainMenuUIController::update()
        {
            highScoreText.setString("High Score : " + std::to_string(Element::ScoreService::getInstance().getHighScore()));
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(highScoreText);
        }

        void MainMenuUIController::processButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            if(event_service->pressedLeftMouseButton())
            {
                if (mouse_position.x > 440 && mouse_position.x < 840) //Since all buttons are in a perfect column, they will all be in this x range
                {
                    if (mouse_position.y > 260 && mouse_position.y < 330) //if cursor is in y range for play button
                    {
                        Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                        GameService::setGameState(GameState::GAMEPLAY);
                        Element::ScoreService::getInstance().resetScore();
                    }
                    else if (mouse_position.y > 360 && mouse_position.y < 430) //if cursor is in y range for 'how to play' button
                    {
                        Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                        printf("Clicked Instruction Button \n");
                        GameService::setGameState(GameState::INSTRUCTION);
                    }
                    else if (mouse_position.y > 460 && mouse_position.y < 530) //if cursor is in y range for exit button
                    {
                        Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                        game_window->close();
                    }
                }
            }
        }
    }
}