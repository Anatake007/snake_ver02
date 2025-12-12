/**
 * @file Position.hpp
 * @brief Definește structura Position pentru coordonate.
 * @author Lilia Micușa
 * @date 2025
 */
#pragma once
#include <iostream>

/** @brief Reprezintă o poziție (x, y) pe tabla de joc. */
struct Position {
    int x; /**< Coordonata X */
    int y; /**< Coordonata Y */

    /** @brief Constructor. */
    Position(int x_ = 0, int y_ = 0) : x(x_), y(y_) { }

    /** @brief Egalitate între două poziții. */
    bool operator==(const Position& other) const { return x == other.x && y == other.y; }
    /** @brief Inegalitate între două poziții. */
    bool operator!=(const Position& other) const { return !(*this == other); }

    /** @brief Afișare pentru Position. */
    friend std::ostream& operator<<(std::ostream& os, const Position& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    /** @brief Citire pentru Position. */
    friend std::istream& operator>>(std::istream& is, Position& p) {
        is >> p.x >> p.y;
        return is;
    }
};
