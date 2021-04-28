cmake_minimum_required(VERSION 3.19)
project(server)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT /Users/evgeniavu/Desktop/StudyHSE/boost_1_75_0)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIR})
add_executable(server server.cpp label.cpp users.cpp)
target_link_libraries(server ${Boost_LIBRARIES})
