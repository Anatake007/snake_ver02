#pragma once
#include "Position.hpp"
#include <iostream>

class Food {
public:
    Food() : pos_(0,0) {}

    Food(const Position& p) : pos_(p) {}

    Food(const Food& other) : pos_(other.pos_) {}

    Food& operator=(const Food& other) {
        if (this != &other) pos_ = other.pos_;
        return *this;
    }

    bool operator==(const Food& other) const { return pos_ == other.pos_; }

    bool operator!=(const Food& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Food& f) {
        os << f.pos_;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Food& f) {
        is >> f.pos_;
        return is;
    }

    Position getPosition() const { return pos_; }
    void setPosition(const Position& p) { pos_ = p; }

private:
    Position pos_;
};
