#include <catch2/catch_test_macros.hpp>
#include "Snake.hpp"

TEST_CASE("Snake move", "[Snake]") {
  Snake s(Position{5,5});
  s.setDirection(Direction::Right);
  s.move();
  REQUIRE(s.getBody().front() == Position{6,5});
}

TEST_CASE("Snake grow", "[Snake]") {
  Snake s(Position{0,0});
  auto n = s.getBody().size();
  s.grow();
  REQUIRE(s.getBody().size() == n + 1);
}
