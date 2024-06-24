#include "../../Header/Global/ServiceLocator.h"

#include "../../Header/Element/ScoreService.h"
#include "../../header/Main/GameService.h"

namespace Global {

	using namespace Main;
	using namespace Graphic;
	using namespace Event;
	using namespace UI;
	using namespace Time;
	using namespace GamePlay;
	using namespace Sound;

	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		sound_service = nullptr;
		game_play = nullptr;
		createService();
	}
	
	void ServiceLocator::createService() {
		event_service = new EventService();
		time_service = new TimeService();
		graphic_service = new GraphicService();
		sound_service = new Sound::SoundService();
		ui_service = new UIService();
		game_play = new GamePlayService();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllService();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}
	void ServiceLocator::initialize() {
		graphic_service->initialize();
		event_service->initialize();
		time_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
		game_play->initialize();

	} 

	void ServiceLocator::update(){
		if(GameService::getGameState()==GameState::MAIN_MENU)
		{
			delete(game_play);
			game_play = new GamePlayService();
			game_play->initialize();
		}
		graphic_service->update();
		event_service->update();
		time_service->update();
		ui_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			game_play->update();
		}
	}
	
	void ServiceLocator::render(){
		
		graphic_service->render();
		ui_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			game_play->render();
		}
	}

	void ServiceLocator::clearAllService() {
		delete(graphic_service);
		delete(event_service);
		delete(ui_service);
		delete(time_service);
		delete(game_play);
		delete(sound_service);
		time_service = nullptr;
		graphic_service=nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		game_play = nullptr;
		sound_service = nullptr;
	}

	GraphicService* ServiceLocator::getGraphicService(){ return graphic_service;}
	EventService* ServiceLocator::getEventService() { return event_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }
	TimeService* ServiceLocator::getTimeService() { return time_service; }
	GamePlayService* ServiceLocator::getGamePlayService() { return game_play; }
	SoundService* ServiceLocator::getSoundService(){return sound_service;  	}

}
