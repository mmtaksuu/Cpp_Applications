cmake_minimum_required(VERSION 3.15)
project(App)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#file(GLOB_RECURSE SOURCES "src/*.cpp" "src/addressbook.pb.cc" "src/addressbook.pb.h")
file(GLOB_RECURSE SOURCES "src/*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES} )

# CMAKE_OPTION -DCMAKE_TOOLCHAIN_FILE=C:/Users/MehmetAksu/vcpkg/scripts/buildsystems/vcpkg.cmake

#find_package(protobuf CONFIG REQUIRED)
#
#if(protobuf_VERBOSE)
#    message(STATUS "Using Protocol Buffers ${Protobuf_VERSION}")
#endif()
#
#set(CMAKE_INCLUDE_CURRENT_DIR TRUE)


target_link_libraries(${PROJECT_NAME} PRIVATE
                      Libs::Sentence
                      Libs::MyInt
                      Libs::MySmartPointer)
#                      protobuf::libprotoc
#                      protobuf::libprotobuf
#                      protobuf::libprotobuf-lite)



