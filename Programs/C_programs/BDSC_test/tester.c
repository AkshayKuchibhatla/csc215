#include "bdsCtest.h"

int doubleA(a)
int a; {
    return a * 2;
}

main() {
    int x;
    x = 1;

    START_TESTING("tested.c");
    TEST_CASE("Basic asserts") {
        ASSERT(1 + 1 == 2);
        ASSERT(1 == 1);
        ASSERT(1 == 0);
    }

    TEST_CASE("Assert equals") {
        ASSERT_EQU(1, 1);
        ASSERT_EQU(5 + 5, 10);
        ASSERT_EQU(3 * 2, 5);
    }

    TEST_CASE("Assert string") {
        ASSERT_STR("Hello", "Hello");
        ASSERT_STR("hello", "hello");
        ASSERT_STR("goodbye", "goodbye");
    }

    TEST_CASE("Testing double function") {
        ASSERT_EQU(doubleA(4), 8);
        ASSERT(doubleA(5) == 10);
        ASSERT(doubleA(x) == 20);
    }

    END_TESTING();
}