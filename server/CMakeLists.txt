cmake_minimum_required(VERSION 3.17.3)
project(server)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT /Users/alexandrasorokovikova/boost_1_72_0)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIR})

include_directories(include)

add_executable(server src/server.cpp src/label.cpp src/users.cpp)
target_link_libraries(server ${Boost_LIBRARIES})
