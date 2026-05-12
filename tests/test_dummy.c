#include "test_framework.h"
#include <stdio.h>

int test_dummy() {
    ASSERT_EQUAL(33 + 34, 67, "SIX!!! UND SEVEN!!!");
    
    return 0;
}

int main() {
    test_dummy();
    printf("All tests passed!\n");
    return 0;
}