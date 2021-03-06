# cpp-xor-list [![Build Status](https://travis-ci.org/NikitkoCent/cpp-xor-list.svg?branch=master)](https://travis-ci.org/NikitkoCent/cpp-xor-list) [![Code Coverage](https://codecov.io/gh/NikitkoCent/cpp-xor-list/branch/master/graph/badge.svg)](https://codecov.io/gh/NikitkoCent/cpp-xor-list) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
C++11-compatible header-only implementation of [XOR linked list](https://en.wikipedia.org/wiki/XOR_linked_list)
with STL-like interface. Most of C++14 `std::list` methods are also supported.

<details>
<summary>Notes</summary>

### Not supported methods:
* `std::erase_if` - will be added after C++20 release
</details>

## Example
```cpp
#include <xor_list/xor_list.h>
#include <iostream>

template<typename Range>
void printRange(Range &&range)
{
    for (auto &&val : range)
    {
        std::cout << val << ' ';
    }
}

int main(int argc, char *argv[])
{
    xor_list<int> list, list2{5, 6, 1, 6, 2, 4, 0};

    list.push_back(2);
    list.push_back(0);
    list.push_front(-1);
    list.push_back(1);

    // Will print "-1 2 0 1 "
    printRange(list);
    std::cout << std::endl;

    list.sort();
    list2.sort();

    list2.merge(list);

    // Will print "-1 0 0 1 1 2 2 4 5 6 6 "
    printRange(list2);
    std::cout << std::endl;

    // Nothing will be printed (list is empty)
    printRange(list);

    return 0;
}
```

## Requirements
* Using the library:
    * C++11-compatible compiler
* For running tests, you need:
    * [git](https://git-scm.com/downloads)
    * [CMake](https://cmake.org/download/) >= v3.1
    * Additionally, if you want to measure code coverage, you need:
        * compiler, 
        [gcov](https://en.wikipedia.org/wiki/Gcov)
        [, optional: [lcov](https://wiki.documentfoundation.org/Development/Lcov)]
        compatible with each other
        (for example, gcc 6.3.0, gcov 6.3.0 and lcov 1.13 are compatible)
        * [genhtml](https://linux.die.net/man/1/genhtml)
        * [CMake](https://cmake.org/download/) >= v3.13

## Build and run tests
See [Requirements](#requirements) chapter first.

Just use [CMake](https://cmake.org/download/) (run from project root):
```bash
# Build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .

# Running tests
ctest -C Release -V

# You can also run benchmarks (example for Release build configuration):
#Release/sort_performance.exe
```

Note: This project uses [GoogleTest](https://github.com/google/googletest) for testing.

## Code coverage measurement
See [Requirements](#requirements) chapter first.

CMake scripts provides the next additional variables for setting up the measurement:
* `COLLECT_CODE_COVERAGE=<LCOV|OTHER|OFF>` - if set to `LCOV` then code coverage target `collect_coverage` will be created. `OTHER` assumes compiling/linking code for measuring via different than lcov instrument ([gcov](https://en.wikipedia.org/wiki/Gcov) for example). `OFF` does nothing and set by default.
* `GCOV_PATH` - allows to specify path to [gcov](https://en.wikipedia.org/wiki/Gcov) executable. `gcov` by default.

It's recommended to build the code in `Debug` mode for coverage measurement.

Example (run from project root):
```bash
# Build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_C_COMPILER=gcc-6.3.0 \
-DCMAKE_CXX_COMPILER=g++-6.3.0 \
-DCOLLECT_CODE_COVERAGE=LCOV \
-DGCOV_PATH=gcov-6.3.0 \
..

# Collecting the coverage:
cmake --build . --target collect_coverage

# Html reports will be generated. Use browser to see it:
<your_browser_name> ./collect_coverage/index.html &
```
