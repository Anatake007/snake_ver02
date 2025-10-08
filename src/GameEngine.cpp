#include "GameEngine.hpp"
#include <cstdlib>
#include <ctime>

GameEngine::GameEngine(int width, int height)
    : board_(width, height),
      snake_({width / 2, height / 2}),
      food_(),
      gameOver_(false),
      score_(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    spawnFood();
}

void GameEngine::update(Direction inputDir) {
    if (gameOver_) return;
    snake_.setDirection(inputDir);
    snake_.move();
    processCollision();
}

bool GameEngine::isGameOver() const { return gameOver_; }
int GameEngine::getScore() const { return score_; }

void GameEngine::spawnFood() {
    Position p;
    p.x = std::rand() % board_.getWidth();
    p.y = std::rand() % board_.getHeight();
    food_.setPosition(p);
}

void GameEngine::processCollision() {
    const Position& head = snake_.getBody().front();
    if (!board_.isInside(head)) {
        gameOver_ = true;
        return;
    }
    auto it = snake_.getBody().begin();
    ++it;
    for (; it != snake_.getBody().end(); ++it) {
        if (*it == head) {
            gameOver_ = true;
            return;
        }
    }
    if (head == food_.getPosition()) {
        snake_.grow();
        ++score_;
        spawnFood();
    }
}
