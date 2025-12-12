/**
 * @file Snake.hpp
 * @brief Clasa Snake - corp + direcție.
 * @author Lilia Micușa
 * @date 2025
 */
#pragma once
#include <deque>
#include <algorithm>
#include <iostream>
#include "Position.hpp"
#include "Direction.hpp"

/** @brief Reprezintă șarpele din joc. */
class Snake {
public:
    /** @brief Constructor cu poziția de start. */
    Snake(const Position& start = {0, 0}) : dir_(Direction::Right) { body_.push_back(start); }

    Snake(const Snake&) = default;
    Snake& operator=(const Snake&) = default;

    /** @brief Setează direcția de mișcare. */
    void setDirection(Direction d) { dir_ = d; }
    /** @brief Returnează direcția curentă. */
    Direction getDirection() const { return dir_; }

    /** @brief Mută șarpele cu o celulă. */
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

    /** @brief Crește șarpele (după mâncare). */
    void grow() { body_.push_back(body_.back()); }

    /** @brief Acces la corpul șarpelui. */
    const std::deque<Position>& getBody() const { return body_; }

    /**
     * @brief Verifică dacă șarpele ocupă poziția.
     * @param pos Poziția verificată.
     * @return true dacă e ocupată.
     */
    bool occupies(const Position& pos) const {
        return std::find(body_.begin(), body_.end(), pos) != body_.end();
    }

    /** @brief Afișare pentru Snake. */
    friend std::ostream& operator<<(std::ostream& os, const Snake& s) {
        os << "Snake: ";
        for (auto& p : s.body_) os << p << " ";
        return os;
    }

private:
    std::deque<Position> body_;
    Direction dir_;
};
