cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 23)
project(App)

set(SOURCE_DIR Source)
set(INCLUDE_DIR Include)
set(THIRD_PARTY_SOURCE_DIR ThirdParty)

set(INCLUDES ${SOURCE_DIR} ${INCLUDE_DIR})

set(SOURCES
    ${SOURCE_DIR}/Main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

## Fetch ##

include(FetchContent)

set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

FetchContent_MakeAvailable(raylib)

## Libs ##

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)