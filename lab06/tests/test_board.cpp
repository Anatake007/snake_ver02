#include <catch2/catch_test_macros.hpp>
#include "Board.hpp"

TEST_CASE("Board boundaries", "[Board]") {
  Board b(20, 10);
  REQUIRE(b.isInside(Position{0,0}));
  REQUIRE(b.isInside(Position{19,9}));
  REQUIRE_FALSE(b.isInside(Position{-1,0}));
  REQUIRE_FALSE(b.isInside(Position{20,0}));
  REQUIRE_FALSE(b.isInside(Position{0,10}));
}
