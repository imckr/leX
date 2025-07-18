cmake_minimum_required(VERSION 3.10)
project(lex VERSION 1.0.0 LANGUAGES CXX)
#if(NOT TARGET gtest)
#	add_subdirectory(external/googletest)
#endif()
#include_directories(external/googletest/googletest/include)

#enable_testing()
#GTest::gtest GTest::gtest_main pthread
#if(GTest_FOUND)

#	add_executable(my_tests test.cpp)
#	target_link_libraries(my_tests GTest::gtest GTest::gtest_main pthread)
#	add_test(Name my_tests COMMAND my_tests)

#else()

#        message(WARNING "Google Test not found. Tests will not be built.")

#endif()
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

#include directories
include_directories(include)

#Add Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

# Create executable
add_executable(lex ${SOURCES} ${HEADERS})


# Link zlib
target_link_libraries(lex z OpenSSL::Crypto)
#target_link_libraries( OpenSSL::Crypto)

add_subdirectory(external/googletest EXCLUDE_FROM_ALL)

# Enable testing
enable_testing()

# Add test subdirectory
add_subdirectory(tests)
