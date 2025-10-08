        #pragma once
        #include "Position.hpp"

class Board {
public:
    Board(int width, int height);
    int getWidth() const;
    int getHeight() const;
    bool isInside(const Position& pos) const;
    void placeFood(const Position& pos);
private:
    int width_;
    int height_;
};
