#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include "GameEngine.hpp"

int main() {
    GameEngine game(20, 10);
    Direction dir = Direction::Right;

    std::cout << "Consola: W/A/S/D, Q — iesire\n";

    while (!game.isGameOver()) {
        if (_kbhit()) {
            char c = _getch();
            switch (c) {
                case 'w': case 'W': dir = Direction::Up; break;
                case 's': case 'S': dir = Direction::Down; break;
                case 'a': case 'A': dir = Direction::Left; break;
                case 'd': case 'D': dir = Direction::Right; break;
                case 'q': case 'Q': return 0;
            }
        }

        game.update(dir);
        system("cls");

        const auto& body = game.getSnakeBody();
        Position food = game.getFoodPosition();

        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 20; ++x) {
                Position p{x, y};
                if (body.front() == p) std::cout << "O";
                else if (std::find(body.begin(), body.end(), p) != body.end()) std::cout << "o";
                else if (food == p) std::cout << "X";
                else std::cout << ".";
            }
            std::cout << "\n";
        }

        std::cout << "Score: " << game.getScore() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "\nGame Over! Final Score: " << game.getScore() << "\n";
    return 0;
}
