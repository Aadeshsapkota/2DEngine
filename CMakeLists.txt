cmake_minimum_required(VERSION 3.20)

project(ENGINE LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    src/core/Application.cpp
    src/core/Debug.cpp
    src/core/Time.cpp
    src/input/Input.cpp
)


add_executable(ENGINE ${SOURCES})

# Raylib paths (MSYS2 MinGW64)
set(RAYLIB_INCLUDE_DIR "C:/msys64/mingw64/include")
set(RAYLIB_LIBRARY_DIR "C:/msys64/mingw64/lib")

target_include_directories(ENGINE PRIVATE ${RAYLIB_INCLUDE_DIR})
target_link_directories(ENGINE PRIVATE ${RAYLIB_LIBRARY_DIR})

target_link_libraries(ENGINE raylib winmm gdi32 opengl32)
