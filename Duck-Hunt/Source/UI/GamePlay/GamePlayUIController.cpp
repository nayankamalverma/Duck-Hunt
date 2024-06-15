#include "../../../Header/UI/GamePlay/GamePlayUIController.h"
#include "../../../Header/Global/ServiceLocator.h"

namespace GamePlay
{
	using namespace Global;

	GamePlayUIController::GamePlayUIController()
	{
		game_window = nullptr;
	}

	void GamePlayUIController::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackgroundImage();
	}

	void GamePlayUIController::initializeBackgroundImage()
	{
		if (background_texture.loadFromFile(background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			scaleBackgroundImage();
		}
		if(tree_texture.loadFromFile(tree_texture_path))
		{
			tree_sprite.setTexture(tree_texture);
			tree_sprite.setPosition(50, 100);
		}
		if (grass_texture.loadFromFile(grass_texture_path))
		{
			grass_sprite.setTexture(grass_texture);
			grass_sprite.setPosition(0, 410);
			grass_sprite.setScale(static_cast<float>(game_window->getSize().x)/ static_cast<float>(grass_sprite.getTexture()->getSize().x), 150 / static_cast<float>(grass_sprite.getTexture()->getSize().y));

		}	

	}

	void GamePlayUIController::scaleBackgroundImage()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}

	void GamePlayUIController::update()
	{
		
	}

	void GamePlayUIController::render()
	{
		game_window->draw(background_sprite);
		game_window->draw(tree_sprite);
		game_window->draw(grass_sprite);
	}



}
