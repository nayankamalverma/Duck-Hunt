#include "../../Header/GamePlay/GamePlayService.h"

#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace GamePlay
{
	using namespace Global;

	GamePlayService::GamePlayService(): ammo(initialAmmo), health(initialHealth), score(0)
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
		ammoText.setCharacterSize(20);
		ammoText.setPosition(10.f, 10.f);

		healthText.setFont(font);
		healthText.setCharacterSize(20);
		healthText.setPosition(10.f, 40.f);
	}

	void GamePlayService::update()
	{
		ammoText.setString("Ammo: " + std::to_string(ammo));
		healthText.setString("Health: "+ std::to_string(health));

		if (roundTimer.getElapsedTime() >= roundTimeLimit) {
			
			if (duck_service->hasActiveDucks()) {
				health--;
				if (health <= 0) {
					Main::GameService::setGameState(Main::GameState::GAME_OVER);// change
				}
				else
				{
					resetRound();
				}
			}
			else {
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
	}

	void GamePlayService::resetRound()
	{
		duck_service->reset();
		ammo = initialAmmo;
		roundTimer.restart();
		duck_service->spawnDuck();	  //spawn more duck
		
	}

	GamePlayService::~GamePlayService()
	{
		delete(duck_service);
	}
	void GamePlayService::handleMouseClick(sf::Vector2i mousePosition) {
		ammo--;
		if (duck_service->checkHit(mousePosition)) {
			score += 10;
		}
	}
}
