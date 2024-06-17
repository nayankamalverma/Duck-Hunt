#include "../../Header/Global/ServiceLocator.h"

#include "../../header/Main/GameService.h"

namespace Global {

	using namespace Main;
	using namespace Graphic;
	using namespace Event;
	using namespace UI;
	using namespace Time;
	using namespace Element;

	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		duck_service = nullptr;
		createService();
	}
	
	void ServiceLocator::createService() {
		event_service = new EventService();
		time_service = new TimeService();
		graphic_service = new GraphicService();
		ui_service = new UIService();
		duck_service = new DuckService();
		printf("create\n");
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
		ui_service->initialize();
		duck_service->initialize();

	} 

	void ServiceLocator::update(){
		graphic_service->update();
		event_service->update();
		time_service->update();
		
		ui_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			duck_service->update();
		}
	}
	
	void ServiceLocator::render(){
		
		graphic_service->render();
		ui_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			duck_service->render();
		}
	}

	void ServiceLocator::clearAllService() {
		delete(graphic_service);
		delete(event_service);
		delete(ui_service);
		delete(time_service);
		delete(duck_service);
		time_service = nullptr;
		graphic_service=nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		duck_service = nullptr;
	}

	GraphicService* ServiceLocator::getGraphicService(){ return graphic_service;}
	EventService* ServiceLocator::getEventService() { return event_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }
	TimeService* ServiceLocator::getTimeService() { return time_service; }
	DuckService* ServiceLocator::getDuckService() { return duck_service; }
}
