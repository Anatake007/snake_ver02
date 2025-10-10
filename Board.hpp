#pragma once
#include "Position.hpp"
#include <iostream>

class Board {
public:
    Board(int width = 20, int height = 20) : width_(width), height_(height) {}
    Board(const Board& other) : width_(other.width_), height_(other.height_) {}
    
    Board& operator=(const Board& other) {
        if (this != &other) {
            width_ = other.width_;
            height_ = other.height_;
        }
        return *this;
    }

    bool operator==(const Board& other) const {
        return width_ == other.width_ && height_ == other.height_;
    }

    bool operator!=(const Board& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Board& b) {
        os << "Board(" << b.width_ << "x" << b.height_ << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Board& b) {
        is >> b.width_ >> b.height_;
        return is;
    }

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    bool isInside(const Position& pos) const {
        return pos.x >=0 && pos.x < width_ && pos.y >=0 && pos.y < height_;
    }

private:
    int width_;
    int height_;
};
