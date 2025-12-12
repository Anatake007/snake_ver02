/**
 * @file Board.hpp
 * @brief Clasa Board - tabla de joc.
 * @author Lilia Micușa
 * @date 2025
 */
#pragma once
#include "Position.hpp"
#include <iostream>

/** @brief Reprezintă tabla de joc și verifică limitele. */
class Board {
public:
    /** @brief Constructor. */
    Board(int width = 20, int height = 20) : width_(width), height_(height) { }

    Board(const Board&) = default;
    Board& operator=(const Board&) = default;

    /** @brief Returnează lățimea tablei. */
    int getWidth() const { return width_; }
    /** @brief Returnează înălțimea tablei. */
    int getHeight() const { return height_; }

    /**
     * @brief Verifică dacă poziția este în interiorul tablei.
     * @param pos Poziția verificată.
     * @return true dacă este în interior.
     */
    bool isInside(const Position& pos) const {
        return pos.x >= 0 && pos.x < width_ && pos.y >= 0 && pos.y < height_;
    }

    /** @brief Afișare pentru Board. */
    friend std::ostream& operator<<(std::ostream& os, const Board& b) {
        os << "Board: " << b.width_ << "x" << b.height_;
        return os;
    }

private:
    int width_;
    int height_;
};
