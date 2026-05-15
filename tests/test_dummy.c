#include "test_framework.h"
#include <stdio.h>

int test_dummy() {
    ASSERT_EQUAL(33 + 34, 67, "SIX!!! UND SEVEN!!!");
    
    return 0;
}

int main() {
    TEST_SUITE("DUmmy!!!");
    test_dummy();
    return 0;
}