## Adding unit tests for C++ code

1. Under the [`test` directory](test), locate (or create, if it doesn't exist)
   the directory having the same relative path from `test` as from `include`.
   **Eg.** if you've created a header file in `include/algorithms/some_dir/`,
   locate or create the directory `test/algorithms/some_dir`.

1. Create a file with the same name as the corresponding header file for which
   you are writing tests, except that the extension should be `.test.cpp`.

1. Add the following code to the test file:
    ```c++
    #include "third_party/catch.hpp"
    #include "path/to/header_file.hpp"
    ```
    The path to the header file is relative from the `include` directory. So,
    for instance, if you need to include the header file
    `include/algorithms/searching/linear_search.hpp`, you can write:
    ```c++
    #include "algorithms/searching/linear_search.hpp"
    ```

1. After these lines you can add your test cases. For details regarding how to
   write test cases using the [Catch test framework][catch], I suggest you to
   go through [this short tutorial][catch-tutorial]. You can also take a look
   at the [existing unit tests][unit-tests] to get a clearer idea about how the
   tests are written.

**And that's it!** Now you can compile the test binary using
**`cmake -Dtests=ON .. && make && ./cardigan.test`** from the build directory,
which will also run all of the tests for you.


[catch]: https://github.com/catchorg/Catch2
[catch-tutorial]: https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#writing-tests
[unit-tests]: https://github.com/camilne/scratch-cardigan/tree/master/test
