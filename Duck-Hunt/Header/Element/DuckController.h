#include <SFML/Graphics.hpp>


#include <random>
#include <chrono>

#include "DuckConfig.h"


namespace Element {

    

	class DuckController {
    public:
        DuckController(DuckType type ,sf::Texture& texture,float speed);
        ~DuckController();

        void initialize();
        void update(float deltaTime);
        void render(sf::RenderWindow* window);

        bool isClicked(sf::Vector2i mousePosition);
        void startRandomMovement();
        float deltaTime;

    private:
        DuckType duckType;
        MovementDirection movement_direction;
        float speed;

        sf::Sprite duckSprite;
        sf::Vector2f currentPos;
        std::vector<sf::IntRect> animationFrames;
        int currentFrame;
        float frameTime;
        float animationDuration;
        float animationTimer;
        sf::Vector2f direction;
        bool moving;

        const sf::Vector2f topLeft = sf::Vector2f(5,5);
        const sf::Vector2f bottomRight = sf::Vector2f(1275,510);

        int frameWidth = 110;
        int frameHeight = 110;

        void animate(float deltaTime);
        MovementDirection getRandomDirection();
        void setInitialPosition();
        void move();
        void moveLeft();
        void moveRight();
        void moveDownLeft();
        void moveDownRight();
        void moveUpLeft();
        void moveUpRight();

       

    };
}
