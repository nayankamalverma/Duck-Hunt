#pragma once

namespace Element
{
    class ScoreService
    {
    public:
        // Get the singleton instance
        static ScoreService& getInstance();

        void initialize();
        void addScore(int points);
        int getScore() const;
        void resetScore();
        int getHighScore() const;

    private:
        // Private constructor and destructor
        ScoreService();
        ~ScoreService();

        // Delete copy constructor and assignment operator
        ScoreService(const ScoreService&) = delete;
        ScoreService& operator=(const ScoreService&) = delete;

        int score;
        int highScore;
    };
}
