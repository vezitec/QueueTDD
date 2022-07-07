cmake_minimum_required(VERSION 3.12)
project(queueTDD CXX)

SET(SRCS
        src/queue.cpp
        src/node.cpp
)
SET(UTS
        ut/queueTests.cpp
)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)
add_library(queue ${SRCS})
target_compile_features(queue PUBLIC cxx_std_20)
target_include_directories(queue PUBLIC include)

add_executable(queue_tests ${UTS} )
target_link_libraries(queue_tests queue gmock_main gtest gmock)
target_compile_features(queue_tests PUBLIC cxx_std_20)
target_include_directories(queue_tests PUBLIC include)


add_custom_target(run_tests
                  COMMAND queue_tests
                  DEPENDS queue_tests)

enable_testing()
add_test(tests queue_tests)
