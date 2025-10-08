#include "Food.hpp"

Food::Food() : pos_{0, 0} {}

Position Food::getPosition() const { return pos_; }

void Food::setPosition(const Position& p) { pos_ = p; }
