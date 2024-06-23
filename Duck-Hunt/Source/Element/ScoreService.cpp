#include "../../Header/Element/ScoreService.h"

namespace Element
{
    ScoreService& ScoreService::getInstance()
    {
        static ScoreService instance;
        return instance;
    }

    ScoreService::ScoreService() : score(0)
    {
    }

    ScoreService::~ScoreService()
    {
    }

    void ScoreService::initialize()
    {
    }

    void ScoreService::addScore(int points)
    {
        score += points;
        if (score > highScore)highScore = score;
    }

    int ScoreService::getScore() const
    {
        return score;
    }

    void ScoreService::resetScore()
    {
        score = 0;
        
    }
    int ScoreService::getHighScore() const
    {
        return highScore;
    }


}
