cmake_minimum_required(VERSION 3.20)

project(Aether2D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    src/core/Application.cpp
    src/core/Debug.cpp
    src/core/Time.cpp
    src/input/Input.cpp
)


add_executable(Aether2D ${SOURCES})

# Raylib paths (MSYS2 MinGW64)
set(RAYLIB_INCLUDE_DIR "C:/msys64/mingw64/include")
set(RAYLIB_LIBRARY_DIR "C:/msys64/mingw64/lib")

target_include_directories(Aether2D PRIVATE ${RAYLIB_INCLUDE_DIR})
target_link_directories(Aether2D PRIVATE ${RAYLIB_LIBRARY_DIR})

target_link_libraries(Aether2D raylib winmm gdi32 opengl32)
