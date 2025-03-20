cmake_minimum_required(VERSION 3.30)
project(app)

set(SOURCE_DIR Source)
set(INCLUDE_DIR Include)
set(THIRD_PARTY_SOURCE_DIR ThirdParty)

set(INCLUDES ${SOURCE_DIR} ${INCLUDE_DIR})

set(SOURCES
    ${SOURCE_DIR}/Main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

## Properties ##

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
    COMPILE_WARNING_AS_ERROR ON
)

## Fetch ##

include(FetchContent)

set(RAYLIB_VERSION 5.5)
set(RAYLIB_CPP_VERSION drawing)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)

FetchContent_Declare(
    raylib_cpp
    URL https://github.com/RobLoach/raylib-cpp/archive/refs/heads/${RAYLIB_CPP_VERSION}.zip
)

FetchContent_MakeAvailable(
    raylib 
    raylib_cpp
)

## Libs ##

target_link_libraries(${PROJECT_NAME} PRIVATE 
    raylib
    raylib_cpp
)

