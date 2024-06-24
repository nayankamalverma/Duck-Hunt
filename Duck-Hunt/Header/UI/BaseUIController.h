#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	class BaseUIController
	{
    protected:
        sf::RenderWindow* game_window;

        // Textures:
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        virtual const sf::String& getBackgroundTexturePath() const = 0;

        void initializeBackgroundImage();
        void scaleBackgroundImage();


        virtual void processButtonInteractions() =0;

    public:
        BaseUIController();
		virtual ~BaseUIController();


        virtual void initialize(sf::RenderWindow* window)=0;
        virtual void update() = 0;
        virtual void render();
	};
}
