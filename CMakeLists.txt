cmake_minimum_required(VERSION 3.22.0)
project(CPP_SFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CURRENT_SOURCE_DIR src)

include(FetchContent)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.26.3
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2)
include_directories(${SDL2_SOURCE_DIR}/include})

# find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME})

include("src/CMakeLists.txt")

target_link_libraries(${PROJECT_NAME}
    # SDL
    SDL2::SDL2main
    SDL2::SDL2-static
)