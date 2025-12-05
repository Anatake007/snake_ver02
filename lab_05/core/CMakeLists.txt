add_library(core STATIC
    Position.cpp
    Board.cpp
    Food.cpp
    Snake.cpp
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
