cmake_minimum_required (VERSION 3.8)

project ("Engine")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${GLFW_ROOT} ${GLFW_BUILD} EXCLUDE_FROM_ALL)

add_library("Engine"
    include/Engine/Engine.h
    Engine.cpp
    include/Engine/Window.h
    Window.cpp
    include/Engine/System.h
    System.cpp
    include/Engine/Clock.h
    Clock.cpp
)

target_include_directories("Engine"
    PUBLIC "${GLFW_ROOT}/include"
    PUBLIC "./include"
)

target_link_libraries("Engine"
    "${GLFW_BUILD}/src/glfw3.lib"
)