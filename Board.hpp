#pragma once
#include "Position.hpp"
#include <iostream>

class Board {
public:
    Board(int width = 20, int height = 20)
        : width_(width), height_(height) {}
    Board(const Board& other) = default;
    Board& operator=(const Board& other) = default;

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

    bool isInside(const Position& pos) const {
        return pos.x >= 0 && pos.x < width_ && pos.y >= 0 && pos.y < height_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Board& b) {
        os << "Board: " << b.width_ << "x" << b.height_;
        return os;
    }

private:
    int width_;
    int height_;
};
