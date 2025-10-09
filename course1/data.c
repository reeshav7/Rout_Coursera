#include "data.h"
#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t *p = ptr;
    if (base < 2 || base > 16) {
        *p = '\\0';
        return 1;
    }
    if (data == 0) {
        *p++ = '0';
        *p = '\\0';
        return 2; /* '0' + null */
    }

    int is_negative = 0;
    int64_t v = data; /* use wider type to safely handle -2^31 */
    if (v < 0) {
        if (base == 10) {
            is_negative = 1;
        }
        v = -v;
    }

    uint8_t *start = p;
    while (v != 0) {
        int rem = (int)(v % base);
        if (rem >= 10) {
            *p++ = (uint8_t)('A' + (rem - 10));
        } else {
            *p++ = (uint8_t)('0' + rem);
        }
        v = v / base;
    }
    if (is_negative) {
        *p++ = '-';
    }

    /* reverse the characters in-place */
    uint8_t *end = p - 1;
    uint8_t *s = start;
    while (s < end) {
        uint8_t tmp = *s;
        *s = *end;
        *end = tmp;
        ++s;
        --end;
    }
    *p = '\\0';
    return (uint8_t)(p - ptr + 1); /* length including null terminator */
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    if (base < 2 || base > 16) return 0;
    uint8_t *p = ptr;
    int is_negative = 0;
    if (*p == '-') {
        is_negative = 1;
        ++p;
    }
    int32_t result = 0;
    uint8_t count = 0;
    while ((count < digits) && (*p != '\\0')) {
        uint8_t ch = *p;
        uint8_t val;
        if (ch >= '0' && ch <= '9') val = ch - '0';
        else if (ch >= 'A' && ch <= 'F') val = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f') val = ch - 'a' + 10;
        else break;
        result = result * (int32_t)base + (int32_t) val;
        ++p;
        ++count;
    }
    if (is_negative) result = -result;
    return result;
}
