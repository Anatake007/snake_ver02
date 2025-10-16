#include "GameEngine.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

GameEngine::GameEngine(int width, int height)
    : board_(std::make_unique<Board>(width, height)),
      snake_(std::make_unique<Snake>(Position{width / 2, height / 2})),
      food_(std::make_unique<Food>()),
      gameOver_(false),
      score_(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    spawnFood();
}

void GameEngine::update(Direction inputDir) {
    if (gameOver_) return;
    snake_->setDirection(inputDir);
    snake_->move();
    processCollision();
}

void GameEngine::spawnFood() {
    Position newPos;
    do {
        newPos.x = std::rand() % board_->getWidth();
        newPos.y = std::rand() % board_->getHeight();
    } while (snake_->occupies(newPos));
    food_->setPosition(newPos);
}

void GameEngine::processCollision() {
    const Position& head = snake_->getBody().front();

    if (!board_->isInside(head)) {
        gameOver_ = true;
        return;
    }

    const auto& body = snake_->getBody();
    if (std::find(body.begin() + 1, body.end(), head) != body.end()) {
        gameOver_ = true;
        return;
    }

    if (head == food_->getPosition()) {
        score_++;
        snake_->grow();
        spawnFood();
    }
}

bool GameEngine::isGameOver() const { return gameOver_; }
int GameEngine::getScore() const { return score_; }

std::ostream& operator<<(std::ostream& os, const GameEngine& g) {
    os << *g.board_ << "\n" << *g.snake_ << "\n" << *g.food_;
    os << "\nScore: " << g.score_ << (g.gameOver_ ? " (GAME OVER)" : "");
    return os;
}

std::istream& operator>>(std::istream& is, GameEngine& g) {
    int score;
    std::cout << "Введите счёт: ";
    is >> score;
    g.score_ = score;
    return is;
}
