cmake_minimum_required(VERSION 3.15)

find_package(GTest QUIET)

if(GTest_FOUND)

	add_executable(test_runner test_main.cpp)

	target_link_libraries(test_runner PRIVATE gtest gtest_main)

	add_test(NAME unit_test COMMAND test_runner)

else()

	message(WARNING "Google Test not found. Tests will not be built.")

endif()
