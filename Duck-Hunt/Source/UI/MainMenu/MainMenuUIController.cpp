#include "../../../header/UI/MainMenu/MainMenuUIController.h"

#include "../../../Header/Element/ScoreService.h"
#include "../../../header/Main/GameService.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Graphics//GraphicService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;

        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeButtons();

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

        void MainMenuUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(background_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool MainMenuUIController::loadButtonTexturesFromFile()
        {    
            return play_button_texture.loadFromFile(play_button_texture_path) &&
                instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(quit_button_texture_path);
        }

        void MainMenuUIController::setButtonSprites()
        {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }

        void MainMenuUIController::scaleAllButttons()
        {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            play_button_sprite.setPosition({ x_position, 500.f });
            instructions_button_sprite.setPosition({ x_position, 700.f });
            quit_button_sprite.setPosition({ x_position, 900.f });
        }

        void MainMenuUIController::update()
        {
            highScoreText.setString("High Score : " + std::to_string(Element::ScoreService::getInstance().getHighScore()));
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(play_button_sprite);
            game_window->draw(instructions_button_sprite);
            game_window->draw(quit_button_sprite);
            game_window->draw(highScoreText);
        }

        void MainMenuUIController::show() { }

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

        bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }
    }
}