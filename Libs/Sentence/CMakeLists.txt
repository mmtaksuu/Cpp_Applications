cmake_minimum_required(VERSION 3.15)
project(Sentence)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

file(GLOB_RECURSE SOURCES "src/*.cpp" "includes/*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(Libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           $<INSTALL_INTERFACE:includes>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
                           ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
