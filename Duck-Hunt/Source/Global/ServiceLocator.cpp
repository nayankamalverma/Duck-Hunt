#include "../../Header/Global/ServiceLocator.h"

namespace Global {

	using namespace Graphic;
	using namespace Event;
	using namespace UI;

	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;
		event_service = nullptr;
		ui_service = nullptr;
		createService();
	}
	
	void ServiceLocator::createService() {
		graphic_service = new GraphicService();
		event_service = new EventService();
		ui_service = new UIService();
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
		ui_service->initialize();
	} 

	void ServiceLocator::update(){
		graphic_service->update();
		event_service->update();
		ui_service->update();
	}
	
	void ServiceLocator::render(){
		ui_service->render();
		graphic_service->render();
		/*if(event_service->pressedLeftMouseButton()){
			printf("hbajc");
			sf::CircleShape circle;
			circle.setRadius(10);
			circle.setFillColor(sf::Color::Green);
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*ServiceLocator::getInstance()->getGraphicService()->getGameWindow());
			circle.setPosition(sf::Vector2f(static_cast<float>(mousePosition.x)-10, static_cast<float>(mousePosition.y)-10));
			graphic_service->getGameWindow()->draw(circle);
		} */
		
	}

	void ServiceLocator::clearAllService() {
		delete(graphic_service);
		delete(event_service);
		delete(ui_service);
		graphic_service=nullptr;
		event_service = nullptr;
		ui_service = nullptr;
	}

	GraphicService* ServiceLocator::getGraphicService(){ return graphic_service;}
	EventService* ServiceLocator::getEventService() { return event_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }

}
