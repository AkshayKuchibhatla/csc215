#include "bdsCtest.h"

int doubleA(a)
int a; {
    return a * 2;
}

main() {
    START_TESTING("tested.c");
    TEST_CASE("Testing something") {
        ASSERT(1 + 1 == 2);
        ASSERT(1 == 1);
    }

    TEST_CASE("Testing something else") {
        ASSERT(2 + 2 == 4);
        ASSERT(1 == 0);    
    }

    END_TESTING();
}