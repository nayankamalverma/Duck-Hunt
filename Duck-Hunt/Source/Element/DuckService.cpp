#include "../../Header/Element/DuckService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Element
{
    using namespace Global;
    DuckService::DuckService() : spawn_timer(0.0f) {
        if (!duckTexture.loadFromFile(duck_texture_path)) {
            printf( "Error loading duck texture" );
        }
        
    }

    DuckService::~DuckService() {
        for (auto duck : duck_list) {
            delete duck;
        }
        duck_list.clear();
    }

    void DuckService::initialize() {
        printf("duck init");
        spawn_timer = 0.0f;
        duck_list.clear();
    }

    void DuckService::update() {
        //updateSpawnTimer();
        for (auto duck : duck_list) {
            duck->update(ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
        }
    }

    void DuckService::render() {
        for (auto duck : duck_list) {
            duck->render(ServiceLocator::getInstance()->getGraphicService()->getGameWindow());
        }
    }

    void DuckService::reset() {
        for (auto duck : duck_list) {
            delete duck;
        }
        duck_list.clear();
    }

    void DuckService::updateSpawnTimer() {
        spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        if (spawn_timer >= spawn_interval) {
            spawn_timer = 0.0f;
            spawnDuck();
        }
    }

    bool DuckService::hasActiveDucks() {
        return !duck_list.empty();
    }

    void DuckService::processDuckSpawn() {
        if (duck_list.size() <2) { // Limit to 2 ducks
            spawnDuck();
        }
    }

    void DuckService::spawnMoreDucks() {
        // Increase difficulty by adding more ducks
        for (int i = 0; i < 3; ++i) {
            spawnDuck();
        }
    }

    DuckController* DuckService::spawnDuck() {
        DuckController* newDuck = new DuckController(duckTexture);
        newDuck->initialize();
        newDuck->startRandomMovement(15.0f);
        duck_list.push_back(newDuck);
        return newDuck;
    }

    void DuckService::destroyDuck(DuckController* controller) {
        auto it = std::find(duck_list.begin(), duck_list.end(), controller);
        if (it != duck_list.end()) {
            delete* it;
            duck_list.erase(it);
        }
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
