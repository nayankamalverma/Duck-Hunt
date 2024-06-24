#pragma once
#include "../BaseUIController.h"

namespace UI
{
    namespace InstructionMenu
    {
        class InstructionUIController : public BaseUIController
        {
        private:
            const sf::String background_texture_path = "assets/textures/4.png";
			void processButtonInteractions() override;
        protected:
            const sf::String& getBackgroundTexturePath() const override { return background_texture_path; }

        public:
            InstructionUIController();

            void initialize(sf::RenderWindow* w) override;
            void update() override;
        };
    }
}