cmake_minimum_required(VERSION 3.26)
project(platformGame)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.1.1
)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(sfml)
add_executable(platformGame main.cpp
        headers/config.hpp
)
target_link_libraries(
        platformGame
        fmt
        sfml-graphics
        sfml-window
        sfml-system
)
IF (WIN32)
    add_custom_command(TARGET platformGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:platformGame> $<TARGET_FILE_DIR:platformGame>
            COMMAND_EXPAND_LISTS
    )
ENDIF ()

