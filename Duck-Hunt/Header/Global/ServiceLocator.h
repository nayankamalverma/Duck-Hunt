#pragma once
#include "../Element/DuckService.h"
#include"../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"

namespace Global {

	class ServiceLocator{

		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		UI::UIService* ui_service;
		Time::TimeService* time_service;
		Element::DuckService* duck_service;
	
		ServiceLocator();
		~ServiceLocator();

		void createService();
		void clearAllService();
	public:

		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		UI::UIService* getUIService();
		Time::TimeService* getTimeService();
		Element::DuckService* getDuckService();
	};
}
