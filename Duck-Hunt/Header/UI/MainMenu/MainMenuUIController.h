#pragma once
#include <SFML/Graphics.hpp>
#include "../BaseUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public BaseUIController
		{
		private:
			const sf::String background_texture_path = "assets/textures/1.png";

			sf::Font font;
			sf::Text highScoreText;
			void processButtonInteractions() override;

		protected:
			const sf::String& getBackgroundTexturePath() const override { return background_texture_path; }
		public:
			MainMenuUIController();

			void initialize(sf::RenderWindow* window) override;
			void update() override;
			void render() override;

		};
	}
}
