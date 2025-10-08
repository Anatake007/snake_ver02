#include "Board.hpp"

Board::Board(int width, int height) : width_(width), height_(height) {}

int Board::getWidth() const { return width_; }
int Board::getHeight() const { return height_; }

bool Board::isInside(const Position& pos) const {
    return pos.x >= 0 && pos.x < width_ && pos.y >= 0 && pos.y < height_;
}

void Board::placeFood(const Position& pos) {
    (void)pos;
}
