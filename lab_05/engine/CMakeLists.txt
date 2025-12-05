add_executable(game
    GameEngine.cpp
    main.cpp
)

target_link_libraries(game PRIVATE core)
