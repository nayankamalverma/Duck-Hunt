#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Time/TimeService.h"


namespace Element {

    class DuckController;

    class DuckService {
    private:
        const float spawn_interval = 2.f;
        std::vector<DuckController*> duck_list;
        float spawn_timer=0;
        sf::Texture duckTexture;
        sf::String duck_texture_path="assets/textures/ducks.png";

    	sf::RenderWindow* window;
        Time::TimeService* time;

        void updateSpawnTimer();
        void processDuckSpawn();

    public:
        DuckService();
        virtual ~DuckService();

        void initialize();
        void update();
        void render();
        void reset();

        DuckController* spawnDuck();
        void destroyEnemy(DuckController* duck_controller);
    };
}
