cmake_minimum_required(VERSION 3.11-3.18)

project(
    libscry-cmake-build
    VERSION 1.0
    DESCRIPTION "Mein Fork compiled with cmake"
)

include(CTest)

if (WIN32)
# Prefer static libs over shared lib
LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
#========== Add CPM package manager ================= 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
set(CPM_VERSION 0.18)

if(NOT EXISTS ${CPM_DOWNLOAD_LOCATION})
	message(STATUS "Downloading CPM.cmake")
	file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif(NOT EXISTS ${CPM_DOWNLOAD_LOCATION})
include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
		NAME curl
		VERSION 7.67.0
		URL https://github.com/curl/curl/releases/download/curl-7_67_0/curl-7.67.0.tar.gz
		OPTIONS
		"CURL_STATICLIB ON"
		"BUILD_CURL_EXE OFF"
		"BUILD_SHARED_LIBS OFF"
		"BUILD_TESTING OFF"
		"WITH_STATIC_RT ON"
		"CMAKE_USE_LIBSSH2 OFF"
		${CURL_PLATFORM_OPTIONS}
)
endif (WIN32)

add_subdirectory(src)
add_subdirectory(examples)