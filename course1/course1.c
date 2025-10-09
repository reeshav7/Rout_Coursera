#include "course1.h"
#include "platform.h"
#include "data.h"
#include "memory.h"
#include "stats.h"
#include <stddef.h>
#include <stdint.h>

static int8_t compare_uint8(uint8_t *a, uint8_t *b, size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        if (*(a + i) != *(b + i)) return -1;
    }
    return 0;
}

int8_t test_data1(void)
{
    uint8_t buf[64];
    uint8_t len = my_itoa(1234, buf, 10);
    int32_t val = my_atoi(buf, len, 10);
    if (val == 1234) {
        PRINTF("test_data1 PASS\\n");
        return 0;
    } else {
        PRINTF("test_data1 FAIL (got %d)\\n", val);
        return -1;
    }
}

int8_t test_data2(void)
{
    uint8_t buf[64];
    uint8_t len = my_itoa(-255, buf, 10);
    int32_t val = my_atoi(buf, len, 10);
    if (val == -255) {
        PRINTF("test_data2 PASS\\n");
        return 0;
    } else {
        PRINTF("test_data2 FAIL (got %d)\\n", val);
        return -1;
    }
}

int8_t test_memmove1(void)
{
    uint8_t src[8] = {1,2,3,4,5,6,7,8};
    uint8_t dst[8] = {0};
    my_memmove(src, dst, 8);
    if (compare_uint8(src, dst, 8) == 0) {
        PRINTF("test_memmove1 PASS\\n");
        return 0;
    } else {
        PRINTF("test_memmove1 FAIL\\n");
        return -1;
    }
}

int8_t test_memmove2(void) /* dst < src, end of dst overlaps start of src */
{
    uint8_t arr[10] = {0,1,2,3,4,5,6,7,8,9};
    /* src = arr+2 (values 2..7), dst = arr (will receive 2..7) */
    my_memmove(arr + 2, arr, 6);
    uint8_t expected0[6] = {2,3,4,5,6,7};
    if (compare_uint8(arr, expected0, 6) == 0) {
        PRINTF("test_memmove2 PASS\\n");
        return 0;
    } else {
        PRINTF("test_memmove2 FAIL\\n");
        return -1;
    }
}

int8_t test_memmove3(void) /* dst > src, start of dst overlaps end of src */
{
    uint8_t arr[10] = {0,1,2,3,4,5,6,7,8,9};
    /* src = arr (0..5), dst = arr+2 -> arr[2..7] should become 0..5 */
    my_memmove(arr, arr + 2, 6);
    uint8_t expected2[6] = {0,1,2,3,4,5};
    if (compare_uint8(arr + 2, expected2, 6) == 0) {
        PRINTF("test_memmove3 PASS\\n");
        return 0;
    } else {
        PRINTF("test_memmove3 FAIL\\n");
        return -1;
    }
}

int8_t test_memcopy(void)
{
    uint8_t src[6] = {10,20,30,40,50,60};
    uint8_t dst[6] = {0};
    my_memcopy(src, dst, 6);
    if (compare_uint8(src, dst, 6) == 0) {
        PRINTF("test_memcopy PASS\\n");
        return 0;
    } else {
        PRINTF("test_memcopy FAIL\\n");
        return -1;
    }
}

int8_t test_memset(void)
{
    uint8_t buf[6];
    my_memset(buf, 6, 0xAA);
    for (size_t i = 0; i < 6; ++i) {
        if (*(buf + i) != 0xAA) {
            PRINTF("test_memset FAIL\\n");
            return -1;
        }
    }
    my_memzero(buf, 6);
    for (size_t i = 0; i < 6; ++i) {
        if (*(buf + i) != 0) {
            PRINTF("test_memzero FAIL\\n");
            return -1;
        }
    }
    PRINTF("test_memset PASS\\n");
    return 0;
}

int8_t test_reverse(void)
{
    uint8_t buf[5] = {1,2,3,4,5};
    uint8_t expected[5] = {5,4,3,2,1};
    my_reverse(buf, 5);
    if (compare_uint8(buf, expected, 5) == 0) {
        PRINTF("test_reverse PASS\\n");
        return 0;
    } else {
        PRINTF("test_reverse FAIL\\n");
        return -1;
    }
}

/* course1: call all tests once */
int8_t course1(void)
{
    int errors = 0;
    errors += test_data1() != 0;
    errors += test_data2() != 0;
    errors += test_memmove1() != 0;
    errors += test_memmove2() != 0;
    errors += test_memmove3() != 0;
    errors += test_memcopy() != 0;
    errors += test_memset() != 0;
    errors += test_reverse() != 0;

    if (errors == 0) {
        PRINTF("All tests passed. course1() returning 0.\\n");
        return 0;
    } else {
        PRINTF("%d tests failed. course1() returning -1.\\n", errors);
        return -1;
    }
}
