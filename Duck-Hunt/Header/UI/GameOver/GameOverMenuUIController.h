#pragma once
#include <SFML/Graphics.hpp>

#include "../BaseUIController.h"

namespace UI
{
	namespace GameOverMenu
	{
        class GameOverMenuUIController : public BaseUIController
        {
        private:
            sf::Font font;
            sf::Text highScoreText;
            sf::Text scoreText;

        	const sf::String background_texture_path = "assets/textures/3.png";
        	void processButtonInteractions() override;
        protected:
        	const sf::String& getBackgroundTexturePath() const override { return background_texture_path; }

        public:
            GameOverMenuUIController();
            void initialize(sf::RenderWindow* window) override;
        	void update() override;
            void render() override;
        };
	}
}
