cmake_minimum_required(VERSION 3.15)
project(SFML_explore)

set(CMAKE_CXX_STANDARD 14)





set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFML_explore main.cpp State.hpp StateMachine.cpp StateMachine.hpp AssetManager.cpp AssetManager.hpp InputManager.cpp InputManager.hpp Game.cpp Game.hpp SplashScreenState.cpp SplashScreenState.hpp DEFINITIONS.hpp MainMenuState.cpp MainMenuState.hpp GameState.cpp GameState.hpp Player.cpp Player.hpp)

target_link_libraries (SFML_explore sfml-graphics sfml-window sfml-system)