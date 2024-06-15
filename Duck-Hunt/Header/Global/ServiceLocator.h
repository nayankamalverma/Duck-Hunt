#pragma once
#include"../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../UI/UIService.h"

namespace Global {

	class ServiceLocator{

		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		UI::UIService* ui_service;
	
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
	};
}
