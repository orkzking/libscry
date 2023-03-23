cmake_minimum_required(VERSION 3.11-3.18)

project(scry)

if (WIN32)
find_package(dlfcn-win32 CONFIG REQUIRED)
find_package(rapidjson CONFIG REQUIRED)
endif (WIN32)

add_library(scry SHARED card.cc data.cc list.cc scry-private.cc scry-public.cc web.cc)

target_link_libraries(scry sqlite3  ) #rapidjson dlfcn-win32::dl
if (WIN32)
target_link_libraries(scry dlfcn-win32::dl )
target_link_libraries(scry rapidjson)
endif (WIN32)

# PUBLIC needed to make both hello.h and hello library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR})

#set_target_properties(scry PROPERTIES PUBLIC_HEADER card.h data.h list.h scry.h web.h)

target_compile_features(scry PUBLIC cxx_std_20)

install(TARGETS scry)
install(FILES card.h data.h list.h scry.h web.h DESTINATION include/scry)
