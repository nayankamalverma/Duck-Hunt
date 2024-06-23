#include "../../Header/Element/DuckService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <cstdlib>

namespace Element
{
    using namespace Global;
    DuckService::DuckService() : spawn_timer(1.0f) {

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        time_service = ServiceLocator::getInstance()->getTimeService();

    }

    DuckService::~DuckService() {
        for (auto duck : duck_list) {
            delete duck;
        }
        duck_list.clear();
    }

    void DuckService::initialize() {
        spawn_timer = 0.0f;
        duck_list.clear();
    }

    void DuckService::update() {
        //updateSpawnTimer();
        for (auto duck : duck_list) {
            duck->update(time_service->getDeltaTime());
        }
    }

    void DuckService::render() {
        for (auto duck : duck_list) {
            duck->render(game_window);
        }
    }

    void DuckService::reset() {
        for (auto duck : duck_list) {
            delete duck;
        }
        duck_list.clear();
    }

    void DuckService::updateSpawnTimer() {
        spawn_timer += time_service->getDeltaTime();
        if (spawn_timer >= spawn_interval) {
            spawn_timer = 0.0f;
            spawnDuck();
        }
    }

    DuckType DuckService::getDuckType()
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        int random_value = std::rand() % (static_cast<int>(DuckType::ORANGE) + 1);
        return static_cast<DuckType>(random_value);
    }


    bool DuckService::hasActiveDucks() {
        return !duck_list.empty();
    }

    void DuckService::processDuckSpawn() {
        if (duck_list.size() <2) { // Limit to 2 ducks
            spawnDuck();
        }
    }

    void DuckService::spawnMoreDucks(int noOfDuck) {

        for (int i = 0; i < noOfDuck; ++i) {
            spawnDuck();
        }
    }

    DuckController* DuckService::spawnDuck() {
        
        DuckType type= getDuckType();
        sf::String duck_texture_path;
    	float duckSpeed;
        if (type == DuckType::BLUE)
        {
	        duck_texture_path = duck1_texture_path;
        	duckSpeed = blueDuckSpeed;
        }
        else
        {
	        duck_texture_path = duck2_texture_path;
            duckSpeed = orangeDuckSpeed;
        }
        if (!duckTexture.loadFromFile(duck_texture_path)) {
            printf("Error loading duck texture");
        }

        
        DuckController* newDuck = new DuckController(type,duckTexture,duckSpeed);
        newDuck->initialize();
        newDuck->startRandomMovement();
        duck_list.push_back(newDuck);
        return newDuck;
    }

    bool DuckService::checkHit(sf::Vector2i mousePosition) {
        for (auto it = duck_list.begin(); it != duck_list.end(); ) {
            if ((*it)->isClicked(mousePosition)) {
                delete* it;
                it = duck_list.erase(it);
                return true;
            }
            else {
                ++it;
            }
        }
        return false;
    }
}
