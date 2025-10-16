#pragma once
#include "Position.hpp"
#include <iostream>

class Food {
public:
    Food() : pos_(0, 0) {}
    Food(const Position& p) : pos_(p) {}
    Food(const Food& other) = default;
    Food& operator=(const Food& other) = default;

    Position getPosition() const { return pos_; }
    void setPosition(const Position& p) { pos_ = p; }

    friend std::ostream& operator<<(std::ostream& os, const Food& f) {
        os << "Food at " << f.pos_;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Food& f) {
        is >> f.pos_;
        return is;
    }

private:
    Position pos_;
};
