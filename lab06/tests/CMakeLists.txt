include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(core_tests
  test_position.cpp
  test_board.cpp
  test_food.cpp
  test_snake.cpp
)

target_link_libraries(core_tests PRIVATE core Catch2::Catch2WithMain)
target_include_directories(core_tests PRIVATE ${CMAKE_SOURCE_DIR}/core)

add_test(NAME core_tests COMMAND core_tests)
