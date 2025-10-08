#include "Snake.hpp"

Snake::Snake(const Position& start) : body_{start}, dir_{Direction::Right} {}

void Snake::setDirection(Direction d) {
    if ((dir_ == Direction::Up && d == Direction::Down) ||
        (dir_ == Direction::Down && d == Direction::Up) ||
        (dir_ == Direction::Left && d == Direction::Right) ||
        (dir_ == Direction::Right && d == Direction::Left)) {
        return;
    }
    dir_ = d;
}

Direction Snake::getDirection() const { return dir_; }

void Snake::move() {
    Position head = body_.front();
    Position newHead = head;
    switch (dir_) {
        case Direction::Up:    newHead.y -= 1; break;
        case Direction::Down:  newHead.y += 1; break;
        case Direction::Left:  newHead.x -= 1; break;
        case Direction::Right: newHead.x += 1; break;
    }
    body_.push_front(newHead);
    body_.pop_back();
}

void Snake::grow() {
    if (!body_.empty()) body_.push_back(body_.back());
}

const std::deque<Position>& Snake::getBody() const { return body_; }

bool Snake::occupies(const Position& pos) const {
    for (const auto& p : body_) if (p == pos) return true;
    return false;
}
