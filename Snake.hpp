#pragma once
#include <deque>
#include <algorithm>
#include <iostream>
#include "Position.hpp"
#include "Direction.hpp"

class Snake {
public:
    Snake(const Position& start = {0, 0}) : dir_(Direction::Right) {
        body_.push_back(start);
    }

    Snake(const Snake& other) = default;
    Snake& operator=(const Snake& other) = default;

    void setDirection(Direction d) { dir_ = d; }
    Direction getDirection() const { return dir_; }

    void move() {
        Position head = body_.front();
        switch (dir_) {
            case Direction::Up:    head.y--; break;
            case Direction::Down:  head.y++; break;
            case Direction::Left:  head.x--; break;
            case Direction::Right: head.x++; break;
        }
        body_.push_front(head);
        body_.pop_back();
    }

    void grow() {
        body_.push_back(body_.back());
    }

    const std::deque<Position>& getBody() const { return body_; }

    bool occupies(const Position& pos) const {
        return std::find(body_.begin(), body_.end(), pos) != body_.end();
    }

    friend std::ostream& operator<<(std::ostream& os, const Snake& s) {
        os << "Snake: ";
        std::for_each(s.body_.begin(), s.body_.end(), [&](const Position& p) {
            os << p << " ";
        });
        return os;
    }

private:
    std::deque<Position> body_;
    Direction dir_;
};
