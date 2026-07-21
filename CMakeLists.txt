cmake_minimum_required(VERSION 3.15)

project(linear_solver VERSION 1.0 LANGUAGES CXX)

set(CMake_CXX_STANDARD 17)
set(CMake_CXX_STANDARD_REQUIRED ON)
set(CMake_CXX_EXTENSIONS OFF)

add_executable(solver_exec tests/tests.cpp src/gauss.cpp src/lu-algo.cpp src/Permutation-algo.cpp)

target_include_directories(solver_exec PRIVATE include)