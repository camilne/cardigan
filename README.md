# Cardigan

[![Build Status](https://travis-ci.org/camilne/cardigan.svg?branch=master)](https://travis-ci.org/camilne/cardigan)

This is a repository dedicated to implementing algorithms and data structures in
C++.

## Contents

* [Getting started](#getting-started)
* [Building](#building)
* [Testing](#testing)
* [Implementation status](#implementation-status)

## Getting started

If you wish to contribute to the repo, then view the
[contributing guide][contrib-guide]. Otherwise, you can clone the repo with
`git clone https://github.com/camilne/cardigan.git`. Then, checkout how to
[build](#building) the library and run [tests](#testing).

## Building

Follow these steps (from the root directory of the project) if you wish to build
the library.
```
mkdir build
cd build
cmake ..
make
```

## Testing

Follow these steps (from the root directory of the project) if you with to test the library.
```
mkdir build
cd build
cmake -Dtests=ON ..
make
./cardigan.test
```

## Implementation status

This section details the current status of the contents of the library.

| Feature              | Implemented             | Has Tests          | Location                                             |
| :-------------       | :-------------          | :-------------     | :-------------                                       |
| AVL Tree             | :ballot_box_with_check: | :white_check_mark: | [avl.hpp](include/data_structures/avl.hpp)           |
| Binary Search Tree   | :ballot_box_with_check: | :white_check_mark: | [bst.hpp](include/data_structures/bst.hpp)           |
| Bubble sort          | :ballot_box_with_check: | :white_check_mark: | [bubble_sort.hpp](include/sorting/bubble_sort.hpp)   |
| Euclid's Algorithm   | :ballot_box_with_check: | :white_check_mark: | [euclid.hpp](include/number_theory/euclid.hpp)       |
| Fisher-Yates shuffle | :ballot_box_with_check: | :white_check_mark: | [fisher_yates.hpp](include/permute/fisher_yates.hpp) |
| Quicksort            | :ballot_box_with_check: | :white_check_mark: | [quicksort.hpp](include/sorting/quicksort.hpp)       |


[contrib-guide]: https://github.com/camilne/cardigan/blob/master/.github/CONTRIBUTING.md
