#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include "GameEngine.hpp"

int main() {
    GameEngine game(20, 10);
    Direction dir = Direction::Right;

    std::cout << "=== Snake Game (Console Test) ===\n";
    std::cout << "Управление: W/A/S/D, выход — Q\n";

    while (!game.isGameOver()) {
        // Ввод без блокировки
        if (_kbhit()) {
            char input = _getch();
            switch (input) {
                case 'w': case 'W': dir = Direction::Up; break;
                case 's': case 'S': dir = Direction::Down; break;
                case 'a': case 'A': dir = Direction::Left; break;
                case 'd': case 'D': dir = Direction::Right; break;
                case 'q': case 'Q':
                    std::cout << "Выход из игры.\n";
                    return 0;
            }
        }

        game.update(dir);

        system("cls");
        const auto& snakeBody = game.getSnakeBody();
        Position foodPos = game.getFoodPosition();

        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 20; ++x) {
                Position p{x, y};
                if (snakeBody.front() == p)
                    std::cout << "O";
                else if (std::find(snakeBody.begin(), snakeBody.end(), p) != snakeBody.end())
                    std::cout << "o";
                else if (p == foodPos)
                    std::cout << "X";
                else
                    std::cout << ".";
            }
            std::cout << "\n";
        }

        std::cout << "Счёт: " << game.getScore() << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "\nИгра окончена! Итоговый счёт: " << game.getScore() << "\n";
    return 0;
}
