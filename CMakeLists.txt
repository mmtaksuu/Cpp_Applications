cmake_minimum_required(VERSION 3.15)
project(Cpp_Applications)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(App)
add_subdirectory(Libs)
add_subdirectory(Test)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)