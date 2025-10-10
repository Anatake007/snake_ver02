#pragma once
#include <iostream>

struct Position {
    int x;
    int y;

    Position() : x(0), y(0) {}
    Position(int x_, int y_) : x(x_), y(y_) {}
    Position(const Position& other) : x(other.x), y(other.y) {}

    Position& operator=(const Position& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Position& pos) {
        os << "(" << pos.x << ", " << pos.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Position& pos) {
        is >> pos.x >> pos.y;
        return is;
    }
};
