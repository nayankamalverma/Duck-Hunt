#include "../../Header/Element/DuckController.h"

#include "../../Header/Element/ScoreService.h"


namespace Element
{
    DuckController::DuckController(DuckType type, sf::Texture& texture,float speed)
		:duckType(type),speed(speed), duckSprite(texture), currentFrame(0), frameTime(0.1f), animationDuration(1.0f), animationTimer(0.0f), moving(false) {
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
        int random_value = std::rand() % (static_cast<int>(MovementDirection::RIGHT_UP) + 1);
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
       		moveLeft();
       		break;

       case MovementDirection::RIGHT:
       		moveRight();
       		break;

       case MovementDirection::LEFT_DOWN:
       		moveDownLeft();
			break;
       case MovementDirection::RIGHT_DOWN:
			moveDownRight();
			break;
       case MovementDirection::LEFT_UP:
           moveUpLeft();
           break;
       case MovementDirection::RIGHT_UP:
           moveUpRight();
           break;
       } 
    }

    void DuckController::moveLeft()
    {
        currentPos.x -= speed * deltaTime;
        duckSprite.setScale(-1.f, 1.f);

        if (currentPos.x - frameWidth <= topLeft.x)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

	void DuckController::moveRight()
    {
        currentPos.x += speed * deltaTime;
        duckSprite.setScale(1.f, 1.f);

        if (currentPos.x + frameWidth >= bottomRight.x)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

    void DuckController::moveDownRight()
    {
        currentPos.y += speed * deltaTime;
        currentPos.x += speed * deltaTime;
        duckSprite.setScale(1.f, 1.f);

        if (currentPos.x + frameWidth >= bottomRight.x || currentPos.y + frameHeight >= bottomRight.y)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

    void DuckController::moveDownLeft()
    {
        currentPos.y += speed * deltaTime;
        currentPos.x -= speed * deltaTime;
        duckSprite.setScale(-1.f, 1.f);

        if (currentPos.x - frameWidth <= topLeft.x || currentPos.y + frameWidth >= bottomRight.y)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

    void DuckController::moveUpLeft()
    {
        currentPos.y -= speed * deltaTime;
        currentPos.x -= speed * deltaTime;
        duckSprite.setScale(-1.f, 1.f);

        if (currentPos.x - frameWidth <= topLeft.x || currentPos.y  <= topLeft.y)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

    void DuckController::moveUpRight()
    {
        currentPos.y -= speed * deltaTime;
        currentPos.x += speed * deltaTime;
        duckSprite.setScale(1.f, 1.f);

        if (currentPos.x + frameWidth >= bottomRight.x || currentPos.y  <= topLeft.y)
        {
            movement_direction = getRandomDirection();
        }
        else duckSprite.setPosition(currentPos);
    }

}
