#include <catch2/catch_test_macros.hpp>
#include "Position.hpp"

TEST_CASE("Position equality", "[Position]") {
  REQUIRE(Position{1,2} == Position{1,2});
  REQUIRE(Position{1,2} != Position{2,1});
}
