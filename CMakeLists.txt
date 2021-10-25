cmake_minimum_required(VERSION 3.2)

project(Lab1)

# Build googletest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest" "googletest")

# Main target
add_executable(Lab cli/Source.cpp headers/polynomial.h headers/monomial.h)

# Test target
add_executable(test_list test/test.cpp)

# Add src to the include directories for the test target
target_include_directories(test_list PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/cli" "${CMAKE_CURRENT_SOURCE_DIR}/headers")

# Link test target against gtest libraries
target_link_libraries(test_list PRIVATE gtest gtest_main)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	message("COMPILER IS MSVC!")
	message(${gtest_force_shared_crt})
	target_compile_options(Lab PRIVATE /W4)
	target_compile_options(test_list PRIVATE /W4)
else()
	target_compile_options(Lab PRIVATE -Wall -Wextra -pedantic -Werror)
	target_compile_options(test_list PRIVATE -Wall -Wextra -pedantic -Werror)
endif()