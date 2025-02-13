cmake_minimum_required(VERSION 3.31)
project(mu C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(mu main.c)

# Find all source files in src/ and add them to the executable
file(GLOB SRC_FILES "src/*.c")
target_sources(mu PRIVATE ${SRC_FILES})

# Include the src directory for headers
target_include_directories(mu PRIVATE src)

# Add compiler flags
target_compile_options(mu PRIVATE -Wall -Wextra -Wpedantic -Werror)
