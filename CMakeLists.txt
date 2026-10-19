cmake_minimum_required(VERSION 3.16)
project(Citra360Bootstrap VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(citra360_core
    src/arm11_core.cpp
    src/memory_bus.cpp
)
target_include_directories(citra360_core PUBLIC include)

add_executable(citra360_bootstrap src/main.cpp)
target_link_libraries(citra360_bootstrap PRIVATE citra360_core)

add_executable(arm11_core_test tests/arm11_core_test.cpp)
target_link_libraries(arm11_core_test PRIVATE citra360_core)

add_executable(memory_bus_test tests/memory_bus_test.cpp)
target_link_libraries(memory_bus_test PRIVATE citra360_core)

enable_testing()
add_test(NAME bootstrap_smoke_test COMMAND citra360_bootstrap --self-test)
add_test(NAME arm11_prototype_test COMMAND arm11_core_test)
add_test(NAME memory_bus_prototype_test COMMAND memory_bus_test)
