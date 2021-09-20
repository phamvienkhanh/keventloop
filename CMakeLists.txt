cmake_minimum_required(VERSION 3.0.0)
project(keventloop VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(keventloop test.cpp)
target_link_libraries(keventloop pthread)