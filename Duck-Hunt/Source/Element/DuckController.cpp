#include "../../Header/Element/DuckController.h"


namespace Element
{
    DuckController::DuckController(sf::Texture& texture)
		: duckSprite(texture), currentFrame(0), frameTime(0.1f), animationDuration(1.0f), animationTimer(0.0f), moveDuration(0.0f), moveTimer(0.0f), moving(false) {
		
		for (int i = 0; i < 3; ++i) {
			animationFrames.push_back(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
		}
		duckSprite.setTextureRect(animationFrames[0]);
	}

    DuckController::~DuckController()
    {
	    
    }

    
    void DuckController::initialize() {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		duckSprite.setPosition(static_cast<float>(std::rand() % 720), static_cast<float>(410));
    }

    void DuckController::update(float deltaTime) {

		animate(deltaTime);
		if (moving) {
			move(deltaTime);
		}
    }

    void DuckController::render(sf::RenderWindow* window) {
        window->draw(duckSprite);
    }

    bool DuckController::isClicked(sf::Vector2i mousePosition) {
        if (duckSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            // Handle duck hit logic here
            return true;
        }
        return false;
    }

    void DuckController::startRandomMovement(float duration) {
        moveDuration = duration;
        moveTimer = 0.0f;
        direction = sf::Vector2f(static_cast<float>((std::rand() % 200 - 100) / 100.0f), static_cast<float>((std::rand() % 200 - 100) / 100.0f));
        moving = true;
    }

    void DuckController::animate(float deltaTime) {
        animationTimer += deltaTime;
        if (animationTimer >= frameTime) {
            animationTimer = 0.0f;
            currentFrame = (currentFrame + 1) % animationFrames.size();
            duckSprite.setTextureRect(animationFrames[currentFrame]);
        }
    }

    void DuckController::move(float deltaTime) {
        moveTimer += deltaTime;
        if (moveTimer < moveDuration) {
            duckSprite.move(direction * 100.0f * deltaTime); // Adjust speed as needed
        }
        else {
            moving = false;
        }
    }
}
