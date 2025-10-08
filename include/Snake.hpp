        #pragma once
        #include <deque>
        #include "Position.hpp"
        #include "Direction.hpp"

class Snake {
public:
    Snake(const Position& start);
    void setDirection(Direction d);
    Direction getDirection() const;
    void move(); // avansează o celulă în direcția curentă
    void grow(); // crește lungimea (după consumul alimentului)
    const std::deque<Position>& getBody() const;
    bool occupies(const Position& pos) const;
private:
    std::deque<Position> body_;
    Direction dir_;
};
