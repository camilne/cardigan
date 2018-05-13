cmake_minimum_required(VERSION 2.8)
project(cardigan)

option(tests "Build tests" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_definitions(${CMAKE_CXX_FLAGS})

set(INCLUDE_FILES
    include/data_structures/bst.hpp
    include/data_structures/avl.hpp
    include/number_theory/euclid.hpp
    include/permute/fisher_yates.hpp
    include/sorting/bubble_sort.hpp
    include/sorting/quicksort.hpp
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
        test/data_structures/bst.test.cpp
        test/data_structures/avl.test.cpp
        test/number_theory/euclid.test.cpp
        test/permute/fisher_yates.test.cpp
        test/sorting/bubble_sort.test.cpp
        test/sorting/quicksort.test.cpp
        test/main.cpp
    )

    add_executable(cardigan.test ${TEST_INCLUDE_FILES} ${TEST_SOURCE_FILES})
    target_link_libraries(cardigan.test cardigan)
endif()
