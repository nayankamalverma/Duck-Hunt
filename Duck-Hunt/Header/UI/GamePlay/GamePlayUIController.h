#pragma once
#include <SFML/Graphics.hpp>
#include "../BaseUIController.h"

namespace UI
{
	namespace GamePlayUI
	{
        class GamePlayUIController : public BaseUIController
        {
        private:
            const sf::String background_texture_path = "assets/textures/background.png";
             void processButtonInteractions() override;
        protected:
            const sf::String& getBackgroundTexturePath() const override { return background_texture_path; }

        public:
            GamePlayUIController();
            void initialize(sf::RenderWindow* window) override;
            void update() override;
        };
	}
}
