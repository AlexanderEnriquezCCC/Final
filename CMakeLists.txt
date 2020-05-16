
cat>gtest.cmake
uired(VERSION 2.8)
Project(Eucher)

include_directories(.)
include(gtest.cmake)

find_package(Threads)
set(CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pthread")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

set(UNIT_TESTS test/test.cpp)
set(MAIN_FILE src/main.cpp)
add_executable(eucher ${MAIN_FILE} src/main.cpp src/cards.cpp src/deck.cpp src/eucher.cpp src/player.cpp)

add_executable(eucher-test ${UNIT_TESTS} src/main.cpp src/cards.cpp src/deck.cpp src/eucher.cpp src/player.cpp)
target_link_libraries(eucher-test gtest ${CMAKE_THREAD_LIBS_INIT})