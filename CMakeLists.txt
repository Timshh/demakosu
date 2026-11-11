cmake_minimum_required (VERSION 3.11)

set(PROJECT_NAME "Demakosu")
project (${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set (SOURCES 
"code/main.cpp" 
"code/game_control.cpp"
"code/gamemode.cpp"
"code/menu.cpp"
"code/object.cpp"
"code/circle.cpp" 
"code/resource_manager.cpp")
set (HEADERS 
"code/game_control.h"
"code/gamemode.h"
"code/menu.h"
"code/object.h"
"code/circle.h" 
"code/resource_manager.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)


add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/data
)


target_include_directories(${PROJECT_NAME} PUBLIC
    code
    data
)