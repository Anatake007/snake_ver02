#include <catch2/catch_test_macros.hpp>
#include "Food.hpp"

TEST_CASE("Food set/get", "[Food]") {
  Food f;
  f.setPosition(Position{5,6});
  REQUIRE(f.getPosition() == Position{5,6});
}
