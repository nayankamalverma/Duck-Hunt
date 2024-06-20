#include <SFML/Graphics.hpp>


#include <random>
#include <chrono>
namespace Element {

	class DuckController {
    public:
        DuckController(sf::Texture& texture);
        ~DuckController();


        void initialize();
        void update(float deltaTime);
        void render(sf::RenderWindow* window);

        bool isClicked(sf::Vector2i mousePosition);
        void startRandomMovement(float duration);

    private:

        int frameWidth = 110;
        int frameHeight = 110;

        void animate(float deltaTime);
        void move(float deltaTime);

        sf::Sprite duckSprite;
        std::vector<sf::IntRect> animationFrames;
        int currentFrame;
        float frameTime;
        float animationDuration;
        float animationTimer;
        float moveDuration;
        float moveTimer;
        sf::Vector2f direction;
        bool moving;
    };
}