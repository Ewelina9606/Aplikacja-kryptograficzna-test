cmake_minimum_required(VERSION 3.15)
project(tests LANGUAGES CXX)

add_executable(main main.cpp operations.cpp)

include(CTest)
enable_testing()
add_executable(test_proba test_proba.cpp operations.cpp)
add_executable(test_powmd test_powmd.cpp operations.cpp)
add_executable(test_euklides test_euklides.cpp operations.cpp)
add_test(NAME test_proba COMMAND test_proba)
add_test(NAME test_powmd COMMAND test_powmd)
add_test(NAME test_euklides COMMAND test_euklides)