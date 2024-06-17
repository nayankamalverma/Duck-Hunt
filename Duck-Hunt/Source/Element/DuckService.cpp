#include "../../Header/Element/DuckService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/DuckController.h"

namespace Element
{

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
        window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        time = Global::ServiceLocator::getInstance()->getTimeService();
    }

    void DuckService::update() {
        updateSpawnTimer();
        for (auto duck : duck_list) {
            duck->update(time->getDeltaTime());
        }
    }

    void DuckService::render() {
        for (auto duck : duck_list) {
            duck->render(window);
        }
    }

    void DuckService::reset() {
        for (auto duck : duck_list) {
            delete duck;
        }
        duck_list.clear();
    }

    void DuckService::updateSpawnTimer() {
        spawn_timer += time->getDeltaTime();
        if (spawn_timer >= spawn_interval) {
            spawn_timer = 0.0f;
            spawnDuck();
        }
    }

    void DuckService::processDuckSpawn() {
        if (duck_list.size() <2) { // Limit to 2 ducks
            spawnDuck();
        }
    }

    DuckController* DuckService::spawnDuck() {
        DuckController* newDuck = new DuckController(duckTexture);
        newDuck->initialize();
        duck_list.push_back(newDuck);
        return newDuck;
    }

    void DuckService::destroyEnemy(DuckController* enemy_controller) {
        auto it = std::find(duck_list.begin(), duck_list.end(), enemy_controller);
        if (it != duck_list.end()) {
            delete* it;
            duck_list.erase(it);
        }
    }
}
