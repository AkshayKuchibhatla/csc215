#include <stdio.h>

unsigned tests;
unsigned passedTests;
unsigned failedTests;

unsigned asserts;
unsigned passAsserts;
unsigned failedAsserts;

unsigned currentAssertNumber;
unsigned failedCurrentTest;

unsigned firstTest;

START_TESTING(file)
char* file; 
{
    tests = 0;
    passedTests = 0;
    failedTests = 0;

    asserts = 0;
    passAsserts = 0;
    failedAsserts = 0;

    failedCurrentTest = 0;
    currentAssertNumber = 0;
    firstTest = 1;
    printf("\n \033[36m---\033[0m %s \033[36m---\033[0m\n", file);
}

incFailPass() {
    if (!firstTest) {
        if (failedCurrentTest) {
            failedTests++;
        } else {
            passedTests++;
        }
    }
}

#define TEST_CASE(description)  printf("\n%s\n", description); tests++; incFailPass(); currentAssertNumber = 0; failedCurrentTest = 0; firstTest = 0;

ASSERT(boolExp) 
int boolExp; {
    asserts++;
    currentAssertNumber++;
    if (boolExp)
        PASS_CASE();
    else
        FAIL_CASE();
}

PASS_CASE() {
    passAsserts++;
    printf("\033[0;32mAssertion %d passed\033[0;37m.\n", currentAssertNumber);
}

FAIL_CASE() {
    if (!failedCurrentTest) {
        failedCurrentTest = 1;
        failedTests++;
    }
    printf("\033[0;31mAssertion %d failed\033[0;37m.\n", currentAssertNumber);
    failedAsserts++;
}

END_TESTING() {
    printf("\n====================================\n"); 
    (tests == 1) ?  printf("1 test.\n") : printf("%d tests.\n", tests);
    printf("\033[0;32m%d passed\033[0;37m, \033[0;31m %d failed\033[0;37m.", passedTests, failedTests);

    (asserts == 1) ? printf("\n\n1 assertion.\n") : printf("\n\n%d assertions.\n", asserts);
    printf("\033[0;32m%d passed\033[0;37m, \033[0;31m %d failed\033[0;37m.", passAsserts, failedAsserts);
    printf("\n====================================\n");
}