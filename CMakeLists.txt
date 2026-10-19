cmake_minimum_required(VERSION 3.16)
project(Citra360Bootstrap VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(citra360_bootstrap
    src/main.cpp
)

target_include_directories(citra360_bootstrap PRIVATE include)

enable_testing()
add_test(NAME bootstrap_smoke_test COMMAND citra360_bootstrap --self-test)
