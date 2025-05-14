cmake_minimum_required(VERSION 3.13)
project(cpplox)

# Compile options fit to clang-tidy
add_compile_options(-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wshadow -Wconversion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Run clang-format
file(GLOB_RECURSE ALL_SOURCE_FILES
  src/*.cpp
  src/*.h
  test/*.cpp
)

add_custom_target(clang-format
  COMMAND clang-format
  -i
  -style=file
  ${ALL_SOURCE_FILES}
  COMMENT "Running clang-format on source files"
)

# Run clang-tidy
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -quiet;
)

# Include all source files except test files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)
add_executable(interpreter ${SOURCE_FILES})

# Add the include path for the interpreter
target_include_directories(interpreter PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Enable testing
enable_testing()

# Add GoogleTest (submodule)
add_subdirectory(third_party/googletest)

# Automate inclusion of all test files
file(GLOB_RECURSE TEST_SOURCES test/*.cpp)

# Create the test executable
add_executable(runTests ${TEST_SOURCES} src/lexer/lexer.cpp)

# Add the include path for the tests
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link gtest to the test executable
target_link_libraries(runTests PRIVATE gtest gtest_main)

# Register the test with CTest
add_test(NAME MyUnitTests COMMAND runTests)
