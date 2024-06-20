#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Time/TimeService.h"

#include "../../Header/Element/DuckController.h"


namespace Element {


    class DuckService {
    private:
        const float spawn_interval = 2.f;
        std::vector<DuckController*> duck_list;
        float spawn_timer=0;
        sf::Texture duckTexture;
        sf::String duck_texture_path="assets/textures/ducks.png";


        void updateSpawnTimer();
        void processDuckSpawn();

    public:
        DuckService();
        virtual ~DuckService();

        void initialize();
        void update();
        void render();
        void reset();
        void handleMouseClick(sf::Vector2i mousePosition);

        DuckController* spawnDuck();
        void destroyDuck(DuckController* duck_controller);

        bool hasActiveDucks();
        void spawnMoreDucks();
        bool checkHit(sf::Vector2i mousePosition);
    };
}
