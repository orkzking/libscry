cmake_minimum_required(VERSION 3.11-3.18)

project(simple)

add_executable(simple simple.cc)

target_include_directories(simple PUBLIC ../src)

target_link_libraries(simple
    PRIVATE libscry)

target_compile_features(simple PUBLIC cxx_std_20)

project(testExe)

add_executable(testExe test.cc)

target_include_directories(testExe PUBLIC ../src)

target_link_libraries(testExe
	PRIVATE libscry)

target_compile_features(testExe PUBLIC cxx_std_20)

project(pricecheck)

add_executable(pricecheck pricecheck.cc)

target_include_directories(pricecheck PUBLIC ../src)

target_link_libraries(pricecheck
	PRIVATE libscry)

target_compile_features(pricecheck PUBLIC cxx_std_20)

add_test(pricecheck pricecheck)

