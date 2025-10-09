#include "memory.h"
#include <stdlib.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    if (dst == src || length == 0) return dst;
    if (dst < src) {
        uint8_t *s = src;
        uint8_t *d = dst;
        for (size_t i = 0; i < length; ++i) {
            *(d + i) = *(s + i);
        }
    } else {
        /* copy backward to handle overlap when dst > src */
        uint8_t *s = src + length;
        uint8_t *d = dst + length;
        for (size_t i = 0; i < length; ++i) {
            *(d - 1 - i) = *(s - 1 - i);
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
    uint8_t *s = src;
    uint8_t *d = dst;
    for (size_t i = 0; i < length; ++i) {
        *(d + i) = *(s + i);
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    uint8_t *p = src;
    for (size_t i = 0; i < length; ++i) {
        *(p + i) = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
    uint8_t *p = src;
    for (size_t i = 0; i < length; ++i) {
        *(p + i) = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
    if (length <= 1) return src;
    uint8_t *start = src;
    uint8_t *end = src + (length - 1);
    while (start < end) {
        uint8_t tmp = *start;
        *start = *end;
        *end = tmp;
        ++start;
        --end;
    }
    return src;
}

int32_t * reserve_words(size_t length)
{
    return (int32_t *) malloc(length * sizeof(int32_t));
}

void free_words(int32_t * src)
{
    free((void *)src);
}
