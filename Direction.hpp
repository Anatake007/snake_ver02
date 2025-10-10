#pragma once
#include <iostream>

enum class Direction {
    Up,
    Down,
    Left,
    Right
};
inline std::ostream& operator<<(std::ostream& os, Direction dir) {
    switch (dir) {
        case Direction::Up: os << "Up"; break;
        case Direction::Down: os << "Down"; break;
        case Direction::Left: os << "Left"; break;
        case Direction::Right: os << "Right"; break;
    }
    return os;
}
