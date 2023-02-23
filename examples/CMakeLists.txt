cmake_minimum_required(VERSION 3.11-3.18)

project(simple)

add_executable(simple simple.cc)

target_include_directories(simple PUBLIC ../src)

target_link_libraries(simple
    PRIVATE libscry)

target_compile_features(simple PUBLIC cxx_std_20)

project(test)

add_executable(test test.cc)

target_include_directories(test PUBLIC ../src)

target_link_libraries(test
	PRIVATE libscry)

target_compile_features(test PUBLIC cxx_std_20)

