#pragma once
#include <iostream>

struct Position {
    int x;
    int y;

    Position(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    bool operator==(const Position& other) const { return x == other.x && y == other.y; }
    bool operator!=(const Position& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Position& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Position& p) {
        is >> p.x >> p.y;
        return is;
    }
};
