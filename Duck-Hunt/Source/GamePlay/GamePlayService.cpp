#include "../../Header/GamePlay/GamePlayService.h"

#include "../../Header/Element/ScoreService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace GamePlay
{
	using namespace Global;
	using namespace Element;

	GamePlayService::GamePlayService():noOfDucks(3), health(initialHealth), score(0) , ammo(initialAmmo), wave(1), isGameOver(false)
	{
		game_window = nullptr;
		duck_service = nullptr;
		event_service = nullptr;
		health = initialHealth;

	}

	void GamePlayService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		event_service = ServiceLocator::getInstance()->getEventService();

		duck_service = new Element::DuckService();
		if(!font.loadFromFile("assets/phenomicon.ttf"))
		{
			printf("font not found.");
		}
		
		initText();
		resetRound();
	}

	void GamePlayService::initText()
	{
		ammoText.setFont(font);
		ammoText.setCharacterSize(30);
		ammoText.setPosition(10.f, 10.f);
		ammoText.setFillColor(sf::Color::Yellow);

		healthText.setFont(font);
		healthText.setCharacterSize(30);
		healthText.setPosition(10.f, 50.f);
		healthText.setFillColor(sf::Color::Red);

		waveText.setFont(font);
		waveText.setCharacterSize(50);
		waveText.setPosition(game_window->getSize().x-210, 10.f);
		waveText.setFillColor(sf::Color::Magenta);

		scoreText.setFont(font);
		scoreText.setCharacterSize(30);
		scoreText.setPosition(10.f,90.f);
		scoreText.setFillColor(sf::Color::Green);
	}

	void GamePlayService::update()
	{
		score = ScoreService::getInstance().getScore();
		ammoText.setString("Ammo: " + std::to_string(ammo));
		healthText.setString("Health: "+ std::to_string(health));
		waveText.setString("WAVE : " + std::to_string(wave) +"\nTime Left : "+ std::to_string((int)(roundTimeLimit.asSeconds()-roundTimer.getElapsedTime().asSeconds())));
		scoreText.setString("Score : " + std::to_string(score));
		if (ammo <= 0 || roundTimer.getElapsedTime() >= roundTimeLimit) {
			
			if ( duck_service->hasActiveDucks() ) {
				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::WAVE_NOT_CLEAR);
				health--;
				if (health <= 0) {
					ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_OVER);
					Main::GameService::setGameState(Main::GameState::GAME_OVER);// change
				}
				else
				{
					resetRound();
				}
			}
			else {
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::WAVE_CLEAR);
				wave++;
				if((int)roundTimeLimit.asSeconds()>=8)
					roundTimeLimit = roundTimeLimit - sf::seconds(1);		//decreasing time round time as wave increases
				if (wave == 10 || wave== 20)noOfDucks++;
				resetRound();
			}
		}
		if(event_service->pressedLeftMouseButton() && ammo>0)
		{
			handleMouseClick(sf::Mouse::getPosition(*game_window));
		}
		duck_service->update();
	}

	void GamePlayService::render()
	{
		duck_service->render();
		game_window->draw(ammoText);
		game_window->draw(healthText);
		game_window->draw(waveText);
		game_window->draw(scoreText);
	}

	void GamePlayService::resetRound()
	{
		duck_service->reset();
		ammo = initialAmmo;
		roundTimer.restart();
		duck_service->spawnMoreDucks(noOfDucks);	
	}

	GamePlayService::~GamePlayService()
	{
		delete(duck_service);
	}

	void GamePlayService::handleMouseClick(sf::Vector2i mousePosition) {
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BULLET_FIRE);
		ammo--;
		if (duck_service->checkHit(mousePosition))
		{
			
		}
	}
}
