#ifndef TEST_H
#define TEST_H

#include <assert.h>
#include <stdio.h>

#ifdef _WIN32
    #define TEST_RED    ""
    #define TEST_GREEN  ""
    #define TEST_YELLOW ""
    #define TEST_RESET  ""
#else
    #define TEST_RED    "\033[31m"
    #define TEST_GREEN  "\033[32m"
    #define TEST_YELLOW "\033[33m"
    #define TEST_RESET  "\033[0m"
#endif

#define TEST_SUITE(name) \
    printf("\n" TEST_YELLOW "=== Test Suite: %s ===" TEST_RESET "\n", name)

#define TEST_SKIP(msg) \
    do { \
        printf(TEST_YELLOW "⚠ SKIP" TEST_RESET ": %s\n", msg); \
    } while (0)

#define ASSERT_TRUE(expr, msg) \
    do { \
        if (expr) { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
        } else { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s\n", msg); \
        } \
        assert(expr); \
    } while (0)

#define ASSERT_FALSE(expr, msg) \
    do { \
        if (!(expr)) { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
        } else { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s\n", msg); \
        } \
        assert(!(expr)); \
    } while (0)

#define ASSERT_NULL(ptr, msg) \
    do { \
        if ((ptr) == NULL) { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
        } else { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is not NULL)\n", msg); \
        } \
        assert((ptr) == NULL); \
    } while (0)

#define ASSERT_NOT_NULL(ptr, msg) \
    do { \
        if ((ptr) != NULL) { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
        } else { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is NULL)\n", msg); \
        } \
        assert((ptr) != NULL); \
    } while (0)

#define ASSERT_EQUAL(a, b, msg) \
    do { \
        if ((a) == (b)) { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
        } else { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (%d != %d)\n", \
                   msg, (int)(a), (int)(b)); \
        } \
        assert((a) == (b)); \
    } while (0)

#endif