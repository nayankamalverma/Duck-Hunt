#include <SFML/Graphics.hpp>


#include <random>
#include <chrono>
namespace Element {

    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
        LEFT_DOWN,
        RIGHT_DOWN,
    };

    class DuckController {
    public:
        DuckController(sf::Texture& texture);
        ~DuckController() = default;

        sf::RenderWindow* window;

        MovementDirection move_direction;

        void initialize();
        void update(float deltaTime);
        void render(sf::RenderWindow* window);

    private:
        sf::Sprite sprite;
        std::vector<sf::IntRect> frames;
        size_t currentFrame;
        float frameTime;
        float currentFrameTime;
        float x_velocity;
        float y_velocity;

        void move();
        void moveLeft();
        void moveRight();
        void moveDiagonalLeft();
        void moveDiagonalRight();
        void moveSpriteRandomly(sf::Sprite& sprite, sf::Time duration);
    };
}