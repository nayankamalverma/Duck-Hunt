#include "../../Header/UI/BaseUIController.h"

#include "../../header/Global/ServiceLocator.h"

namespace UI
{
  BaseUIController::BaseUIController() : game_window(nullptr) {}

	BaseUIController::~BaseUIController(){}

	void BaseUIController::initialize(sf::RenderWindow* window)
	{
		game_window = window;
		initializeBackgroundImage();
		scaleBackgroundImage();
	}

	void BaseUIController::initializeBackgroundImage()
	{
		if (!background_texture.loadFromFile(getBackgroundTexturePath()))
		{
			throw std::runtime_error("Failed to load background texture.");
		}
		background_sprite.setTexture(background_texture);
	}

	void BaseUIController::scaleBackgroundImage()
	{
		sf::Vector2u textureSize = background_texture.getSize();
		sf::Vector2u windowSize = game_window->getSize();

		float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
		float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

		background_sprite.setScale(scaleX, scaleY);
	}

	void BaseUIController::render()
	{
		game_window->draw(background_sprite);
	}


}
