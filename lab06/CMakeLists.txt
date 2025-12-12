cmake_minimum_required(VERSION 3.15)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(engine)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
  set(DOXYFILE_OUT ${CMAKE_BINARY_DIR}/Doxyfile)
  configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
  add_custom_target(docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
  )
endif()
