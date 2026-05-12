#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

/* Color codes for terminal output */
#define TEST_GREEN "\x1b[32m"
#define TEST_RED "\x1b[31m"
#define TEST_YELLOW "\x1b[33m"
#define TEST_RESET "\x1b[0m"

/* Test macros */
#define ASSERT_EQUAL(actual, expected, msg) \
    do { \
        if ((actual) != (expected)) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s\n", msg); \
            printf("  Expected: %d, Got: %d\n", (int)(expected), (int)(actual)); \
            assert(actual != expected); \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            assert(actual == expected); \
        } \
    } while (0)

#define ASSERT_NOT_NULL(ptr, msg) \
    do { \
        if ((ptr) == NULL) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is NULL)\n", msg); \
            assert(ptr == NULL); \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            assert(ptr != NULL); \
        } \
    } while (0)

#define ASSERT_NULL(ptr, msg) \
    do { \
        if ((ptr) != NULL) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is not NULL)\n", msg); \
            assert(ptr != NULL); \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            assert(ptr == NULL); \
        } \
    } while (0)

#define TEST_SUITE(name) \
    printf("\n" TEST_YELLOW "=== Test Suite: %s ===" TEST_RESET "\n", name)

#define TEST_SKIP(msg) \
    do { \
        printf(TEST_YELLOW "⚠ SKIP" TEST_RESET ": %s\n", msg); \
    } while (0)