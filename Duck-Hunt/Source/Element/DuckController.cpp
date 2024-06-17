#include "../../Header/Element/DuckController.h"

#include "../../Header/Global/ServiceLocator.h"

namespace Element
{
    DuckController::DuckController(sf::Texture& texture)
        : currentFrame(0), frameTime(0.1f), currentFrameTime(0.0f),
        x_velocity(100.0f), y_velocity(0.0f) {

        // Set up the frames for animation
        for (int i = 0; i < 3; ++i) {
            frames.push_back(sf::IntRect(i * 110, 0, 110, 110));
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(frames[0]);
    }

    void DuckController::initialize() {
        // Set initial position or any other initialization logic
        sprite.setPosition(100, 410);
    }

    void DuckController::update(float deltaTime) {
        currentFrameTime += deltaTime;
        if (currentFrameTime >= frameTime) {
            currentFrame = (currentFrame + 1) % frames.size();
            sprite.setTextureRect(frames[currentFrame]);
            currentFrameTime = 0.0f;
        }
        // Move the duck
        sprite.move(x_velocity * deltaTime, y_velocity * deltaTime);
        //move();
		//moveSpriteRandomly(sprite, sf::seconds(15));
    }

    void DuckController::render(sf::RenderWindow* window) {
        window->draw(sprite);
    }

	void DuckController::moveSpriteRandomly(sf::Sprite& sprite, sf::Time duration)
	{
		// Create a random device and distribution
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(-1.f, 1.f);

		// Calculate the elapsed time
		sf::Clock clock;
		sf::Time elapsed = sf::Time::Zero;

		// Move the sprite randomly until the specified duration has elapsed
		while (elapsed < duration)
		{
			// Generate random displacements for the sprite
			float dx = dis(gen) * 10.f; // Adjust the value of 10.f to control the speed of the sprite
			float dy = dis(gen) * 10.f; // Adjust the value of 10.f to control the speed of the sprite

			// Move the sprite
			sprite.move(dx, dy);

			// Sleep for a short period of time to limit the frame rate
			sf::sleep(sf::milliseconds(10));

			// Update the elapsed time
			elapsed = clock.getElapsedTime();
		}
	}

	void DuckController::move()
	{
		switch (move_direction)
		{
		case::Element::MovementDirection::LEFT:
			moveLeft();
			break;

		case::Element::MovementDirection::RIGHT:
			moveRight();
			break;

		case::Element::MovementDirection::LEFT_DOWN:
			moveDiagonalLeft();
			break;

		case::Element::MovementDirection::RIGHT_DOWN:
			moveDiagonalRight();
			break;
		}
	}

	void DuckController::moveDiagonalLeft()
	{
		
	}

	void DuckController::moveDiagonalRight()
	{
		
	}

	void DuckController::moveLeft()
	{
		
	}

	void DuckController::moveRight()
	{
		
	}


	/*void DuckController::moveLeft()
	{
		sf::Vector2f currentPosition = sprite.getPosition();
		currentPosition.x -= x_velocity * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x <= left_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void ThunderSnakeController::moveRight()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x >= enemy_model->right_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void ThunderSnakeController::moveDiagonalLeft()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x <= enemy_model->left_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::RIGHT);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	}

	void DuckController::moveDiagonalRight()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.x >= enemy_model->right_most_position.x)
		{
			enemy_model->setMovementDirection(MovementDirection::LEFT);
		}
		else enemy_model->setEnemyPosition(currentPosition);
	} */

}
