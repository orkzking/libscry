cmake_minimum_required(VERSION 3.11-3.18)

project(libscry)

add_library(libscry card.cc data.cc list.cc scry-private.cc scry-public.cc web.cc)

# PUBLIC needed to make both hello.h and hello library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR})

target_compile_features(libscry PUBLIC cxx_std_20)