cmake_minimum_required(VERSION 3.11-3.18)

project(simple)

add_executable(simple simple.cc)

target_link_libraries(simple
    PRIVATE libscry)

target_compile_features(simple PUBLIC cxx_std_20)