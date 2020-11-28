cmake_minimum_required(VERSION 3.17)
project(Test)

set(CMAKE_CXX_STANDARD 17)

set(CODECOV_OUTPUTFILE cmake_coverage.output)
set(CODECOV_HTMLOUTPUTFILE coverage_results)

find_program(CODECOV_GCOV gcov)
find_program(CODECOV_LCOV lcov)
find_program(CODECOV_GENHTML genhtml)
add_definitions(-fprofile-arcs -ftest-coverage)
link_libraries(gcov)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} --coverage)
add_custom_target(coverage_init ALL ${CODECOV_LCOV} --base-directory .. --directory ${CMAKE_BINARY_DIR} --output-file ${CODECOV_OUTPUTFILE} --capture --initial)
add_custom_target(coverage ${CODECOV_LCOV} --base-directory .. --directory ${CMAKE_BINARY_DIR} --output-file ${CODECOV_OUTPUTFILE} --capture COMMAND genhtml -o ${CODECOV_HTMLOUTPUTFILE} ${CODECOV_OUTPUTFILE})

file(GLOB_RECURSE DATE_SOURCES "src/date_test.cpp" includes/catch.hpp)
add_executable(date_test ${DATE_SOURCES})
target_link_libraries(date_test PRIVATE Libs::Date)

file(GLOB_RECURSE SENTENCE_SOURCES "src/sentence_test.cpp" includes/catch.hpp)
add_executable(sentence_test ${SENTENCE_SOURCES})
target_link_libraries(sentence_test PRIVATE Libs::Sentence)

