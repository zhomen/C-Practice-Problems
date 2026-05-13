cmake_minimum_required(VERSION 3.16)

project(practice_problems CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 03597a01ee50ed33e9dfd640b249b4be3799d395
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_library(lib
    src/arrays.cpp
    src/strings.cpp
    src/linkedlists.cpp
)

add_executable(main
    src/main.cpp
)

target_link_libraries(main lib)

enable_testing()

add_executable(
    tests
    tests/arrays_tests.cpp
    tests/strings_tests.cpp
    tests/linkedlists_tests.cpp
)

target_link_libraries(
    tests 
    lib 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)