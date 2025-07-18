cmake_minimum_required(VERSION 3.15)

# Add the test executable
add_executable(my_tests test.cpp)

# Link against the locally built GoogleTest
target_link_libraries(my_tests PRIVATE gtest gtest_main)

# Enable test discovery
include(GoogleTest)
gtest_discover_tests(my_tests)
