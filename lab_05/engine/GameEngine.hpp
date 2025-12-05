#pragma once
#include <memory>
#include "Board.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Direction.hpp"

class GameEngine {
public:
    GameEngine(int width = 20, int height = 20);

    void update(Direction inputDir);
    bool isGameOver() const;
    int getScore() const;

    const std::deque<Position>& getSnakeBody() const { return snake_->getBody(); }
    Position getFoodPosition() const { return food_->getPosition(); }

private:
    std::unique_ptr<Board> board_;
    std::unique_ptr<Snake> snake_;
    std::unique_ptr<Food> food_;
    bool gameOver_;
    int score_;

    void spawnFood();
    void processCollision();
};
