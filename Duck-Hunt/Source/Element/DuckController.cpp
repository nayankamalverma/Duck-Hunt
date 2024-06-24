#include "../../Header/Element/DuckController.h"

#include "../../Header/Element/ScoreService.h"


namespace Element
{
    DuckController::DuckController(DuckType type, sf::Texture& texture,float speed)
		:duckType(type),DuckSpeed(speed), duckSprite(texture), currentFrame(0), frameTime(0.1f), animationDuration(1.0f), animationTimer(0.0f), moving(false) {
        std::srand(static_cast<unsigned int>(std::time(0)));
		for (int i = 0; i < 3; ++i) {
			animationFrames.push_back(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
		}
		duckSprite.setTextureRect(animationFrames[0]);
       
	}

    void DuckController::setInitialPosition() {
        float randomX = static_cast<float>(std::rand() % 1170) ;
        float fixedY = 510.0f;
        duckSprite.setPosition(randomX, fixedY);
        currentPos = sf::Vector2f(randomX, fixedY);
    }

    DuckController::~DuckController()
    {
	    
    }

    void DuckController::initialize() {
    }

    void DuckController::update(float deltaTime) {
        this->deltaTime = deltaTime;
		animate(deltaTime);
		if (moving) {
			move();
		}
    }

    void DuckController::render(sf::RenderWindow* window) {
        window->draw(duckSprite);
    }

    bool DuckController::isClicked(sf::Vector2i mousePosition) {
        if (duckSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))){
            if (duckType == DuckType::BLUE) ScoreService::getInstance().addScore(10);
            else  ScoreService::getInstance().addScore(20);
            return true;
        }
        return false;
    }

    void DuckController::startRandomMovement() {
        
        movement_direction = getRandomDirection();
    	setInitialPosition();
        moving = true;
    }

    MovementDirection DuckController::getRandomDirection()
    {
        int random_value = std::rand() % 5 + 1;
        if (movement_direction == static_cast<MovementDirection>(random_value)) getRandomDirection();
    	return static_cast<MovementDirection>(random_value);
    }


    void DuckController::animate(float deltaTime) {
        animationTimer += deltaTime;
        if (animationTimer >= frameTime) {
            animationTimer = 0.0f;
            currentFrame = (currentFrame + 1) % animationFrames.size();
            duckSprite.setTextureRect(animationFrames[currentFrame]);
        }
    }

    void DuckController::move() {
       switch (movement_direction)
       {
       case MovementDirection::LEFT:
           move(-1, 0, -1, 1);
       		break;

       case MovementDirection::RIGHT:
           move(1, 0, 1, 1);
       		break;

       case MovementDirection::LEFT_DOWN:
           move(-1, 1, -1, 1);
			break;
       case MovementDirection::RIGHT_DOWN:
          move(1, 1, 1, 1);
			break;
       case MovementDirection::LEFT_UP:
            move(-1, -1, -1, 1);
           break;
       case MovementDirection::RIGHT_UP:
          move(1, -1, 1, 1);
           break;
       } 
    }

    void DuckController::move(int xDir, int yDir, int offset_x, int offset_y)
    {

        float speed = DuckSpeed * deltaTime;
        currentPos.x += xDir * speed;
    	currentPos.y += yDir * speed;
        duckSprite.setScale(offset_x, offset_y);

        bool outOfBoundsX = (xDir < 0 && currentPos.x - frameWidth <= topLeft.x) ||
            (xDir > 0 && currentPos.x + frameWidth >= bottomRight.x);
        bool outOfBoundsY = (yDir < 0 && currentPos.y <= topLeft.y) ||
            (yDir > 0 && currentPos.y + frameHeight >= bottomRight.y);
        if (outOfBoundsX || outOfBoundsY) {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }
}
