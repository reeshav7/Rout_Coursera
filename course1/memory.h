#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stddef.h>

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
uint8_t * my_memzero(uint8_t * src, size_t length);
uint8_t * my_reverse(uint8_t * src, size_t length);
int32_t * reserve_words(size_t length);
void free_words(int32_t * src);

#endif /* MEMORY_H */
