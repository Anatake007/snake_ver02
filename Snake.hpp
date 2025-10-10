#pragma once
#include <deque>
#include "Position.hpp"
#include "Direction.hpp"
#include <iostream>

class Snake {
public:
    Snake(const Position& start) : body_{start}, dir_(Direction::Right) {}
    Snake(const Snake& other) : body_(other.body_), dir_(other.dir_) {}

    Snake& operator=(const Snake& other) {
        if (this != &other) {
            body_ = other.body_;
            dir_ = other.dir_;
        }
        return *this;
    }

    bool operator==(const Snake& other) const {
        return body_ == other.body_ && dir_ == other.dir_;
    }

    bool operator!=(const Snake& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Snake& s) {
        for (const auto& pos : s.body_) os << pos << " ";
        return os;
    }

    void setDirection(Direction d) { dir_ = d; }
    Direction getDirection() const { return dir_; }

    void move() {
        Position newHead = body_.front();
        switch (dir_) {
            case Direction::Up:    newHead.y -= 1; break;
            case Direction::Down:  newHead.y += 1; break;
            case Direction::Left:  newHead.x -= 1; break;
            case Direction::Right: newHead.x += 1; break;
        }
        body_.push_front(newHead);
        body_.pop_back();
    }

    void grow() { body_.push_back(body_.back()); }
    const std::deque<Position>& getBody() const { return body_; }

    bool occupies(const Position& pos) const {
        for (const auto& segment : body_)
            if (segment == pos) return true;
        return false;
    }

private:
    std::deque<Position> body_;
    Direction dir_;
};
