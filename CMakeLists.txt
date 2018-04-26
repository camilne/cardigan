cmake_minimum_required(VERSION 2.8)
project(cardigan)

option(tests "Build tests" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
add_definitions(${CMAKE_CXX_FLAGS})

set(INCLUDE_FILES
    include/sorting/bubble_sort.hpp
)

set(SOURCE_FILES
    src/placeholder.cpp
)

add_library(cardigan ${INCLUDE_FILES} ${SOURCE_FILES})

if(${tests})
    set(TEST_INCLUDE_FILES
        ${INCLUDE_FILES}
        include/test/common.test.hpp
        include/third_party/catch.hpp
    )

    set(TEST_SOURCE_FILES
        test/sorting/bubble_sort.test.cpp
        test/main.cpp
    )

    add_executable(cardigan.test ${TEST_INCLUDE_FILES} ${TEST_SOURCE_FILES})
    target_link_libraries(cardigan.test cardigan)
endif()
