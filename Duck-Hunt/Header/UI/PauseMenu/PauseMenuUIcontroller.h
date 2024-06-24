#pragma once
#include <SFML/Graphics.hpp>
#include "../BaseUIController.h"

namespace UI
{
	namespace PauseMenu
	{
        class PauseMenuUIController : public UI::BaseUIController
        {
        private:
            const sf::String background_texture_path = "assets/textures/2.png";

            sf::Font font;
            sf::Text highScoreText;

            void processButtonInteractions() override;
        protected:
            const sf::String& getBackgroundTexturePath() const override { return background_texture_path; }

        public:
            PauseMenuUIController();
            void initialize(sf::RenderWindow* window) override;
            void update() override;
            void render() override;
        };
	}
}
