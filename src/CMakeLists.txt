cmake_minimum_required(VERSION 3.11-3.18)

project(libscry)

# find_package(sqlite3 CONFIG REQUIRED)
# find_package(RapidJSON CONFIG REQUIRED)
# find_package(dlfcn-win32 CONFIG REQUIRED)

add_library(libscry card.cc data.cc list.cc scry-private.cc scry-public.cc web.cc)

target_link_libraries(libscry libcurl sqlite3 rapidjson dlfcn-win32::dl)

# PUBLIC needed to make both hello.h and hello library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR})

target_compile_features(libscry PUBLIC cxx_std_20)