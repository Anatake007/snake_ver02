#include <iostream>
#include "GameEngine.hpp"

int main() {
    GameEngine engine(20, 10);
    engine.update(Direction::Right);
    engine.update(Direction::Down);
    engine.update(Direction::Left);

    std::cout << "Score: " << engine.getScore() << "\n";
    std::cout << "Game over: " << (engine.isGameOver() ? "yes" : "no") << "\n";
    return 0;
}
