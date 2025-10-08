        #pragma once
        #include "Board.hpp"
        #include "Snake.hpp"
        #include "Food.hpp"

class GameEngine {
public:
    GameEngine(int width = 20, int height = 20);
    void update(Direction inputDir); // actualizează starea jocului pe baza intrării
    bool isGameOver() const;
    int getScore() const;
private:
    Board board_;
    Snake snake_;
    Food food_;
    bool gameOver_;
    int score_;
    void spawnFood();
    void processCollision();
};
