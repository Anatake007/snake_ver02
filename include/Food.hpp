        #pragma once
        #include "Position.hpp"

class Food {
public:
    Food();
    Position getPosition() const;
    void setPosition(const Position& p);
private:
    Position pos_;
};
