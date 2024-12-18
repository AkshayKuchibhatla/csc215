# Test-Driven Development for BDS C

This is a single-header library which implements tests to run on a BDS C compliler, a compiler from 1979 which incorporates a compact version of C to run on Intel 8080 and Zilog Z80 processors.

The library involves test cases, each defined by the `TEST_CASE()` function. Each test case can have one or more asserts, which are statements that pass if true and fail if false.

## Asserts

The different functions that incorporate asserts are as follows:

**`ASSERT(statement)`**

This assertion passes if the statement passed into the function is true, fails if it is false.

**`ASSERT_EQU(a,b)`**

This assertion passes if `a` and `b` equal each other, otherwise it fails. The parameters `a` and `b` can be of any type.

**`ASSERT_STR(str a,str b)`**

Similar to `ASSERT_EQU`, this assertion passes if `a` and `b` equal each other. The parameters `a` and `b` have to be strings.

## Genaral functions

**`START_TESTING(file)`**

Prints the filename passed to it and initializes the variables associated with testing.

**`END_TESTING`**

Finishes testing and prints the results.

**`TEST_CASE`**

Creates a test case which can be filled with assertions.

**Note:** A test only passes if all of its assertions pass.

## Example

For example, the file `tester.c`, linked [here](tester.c), prints out the following result:

```txt

        --- tested.c ---

        Basic asserts
        Assertion 1 passed.
        Assertion 2 passed.
        Assertion 3 failed.

        Assert equals
        Assertion 1 passed.
        Assertion 2 passed.
        Assertion 3 failed.

        Assert string
        Assertion 1 passed.
        Assertion 2 passed.
        Assertion 3 passed.

        Testing double function
        Assertion 1 passed.
        Assertion 2 passed.
        Assertion 3 failed.

        ====================================
        4 tests.
        1 passed,  3 failed.

        12 assertions.
        9 passed,  3 failed.
        ====================================

```
