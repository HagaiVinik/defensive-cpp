cmake_minimum_required(VERSION 3.21)
project(maman11)

set(CMAKE_CXX_STANDARD 17)

add_executable(maman11 main.cpp Message.hpp User.hpp USocial.hpp Post.hpp Media.hpp Photo.hpp Audio.hpp Video.hpp BusinessUser.hpp USocial.cpp)
