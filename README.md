# Cardigan

This is a repository dedicated to implementing algorithms and data structures in
C++.

## Contents

* [Getting started](#getting-started)
* [Project structure](#project-structure)
* [Building](#building)
* [Testing](#testing)
* [Implementation status](#implementation-status)

## Getting started

If you wish to contribute to the repo, then view the [contributing
guide](contrib-guide). Otherwise, you can clone the repo with
`git clone https://github.com/camilne/cardigan.git`. Then, checkout how to
[build](#building) the library and run [tests](#testing).

## Project structure

The project is split up into different folders and files to facilitate the reuse
and structure of code.

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

| Feature        | Implemented    | Has Tests      | Location       |
| :------------- | :------------- | :------------- | :------------- |
|                |                |                |                ||

[contrib-guide]: .github/CONTRIBUTING.md
