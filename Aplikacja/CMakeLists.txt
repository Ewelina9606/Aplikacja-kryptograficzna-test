cmake_minimum_required(VERSION 3.15)
project(tests LANGUAGES CXX)



find_package(Git REQUIRED)

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/cryptopp")
    execute_process(
        COMMAND "${GIT_EXECUTABLE}" clone https://github.com/weidai11/cryptopp.git
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
endif()

set(CMAKE_SKIP_INSTALL_RULES TRUE)
add_subdirectory(cryptopp)

add_executable(main main.cpp operations.cpp)
target_link_libraries(main cryptopp-static)

include(CTest)
enable_testing()
add_executable(test_proba test_proba.cpp operations.cpp)
add_executable(test_powmd test_powmd.cpp operations.cpp)
add_executable(test_euklides test_euklides.cpp operations.cpp)
add_test(NAME test_proba COMMAND test_proba)
add_test(NAME test_powmd COMMAND test_powmd)
add_test(NAME test_euklides COMMAND test_euklides)
