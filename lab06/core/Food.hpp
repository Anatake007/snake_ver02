/**
 * @file Food.hpp
 * @brief Clasa Food - mâncarea din joc.
 * @author Lilia Micușa
 * @date 2025
 */
#pragma once
#include "Position.hpp"
#include <iostream>

/** @brief Reprezintă mâncarea (poziția acesteia). */
class Food {
public:
    /** @brief Constructor implicit (0,0). */
    Food() : pos_(0, 0) { }
    /** @brief Constructor cu poziție. */
    Food(const Position& p) : pos_(p) { }

    Food(const Food&) = default;
    Food& operator=(const Food&) = default;

    /** @brief Returnează poziția mâncării. */
    Position getPosition() const { return pos_; }
    /** @brief Setează poziția mâncării. */
    void setPosition(const Position& p) { pos_ = p; }

    /** @brief Afișare pentru Food. */
    friend std::ostream& operator<<(std::ostream& os, const Food& f) {
        os << "Food at " << f.pos_;
        return os;
    }

    /** @brief Citire pentru Food (citește poziția). */
    friend std::istream& operator>>(std::istream& is, Food& f) {
        is >> f.pos_;
        return is;
    }

private:
    Position pos_;
};
