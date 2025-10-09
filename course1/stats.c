#include "stats.h"
#include "platform.h"

void print_array(uint8_t *array, size_t length)
{
#ifdef VERBOSE
    uint8_t *p = array;
    for (size_t i = 0; i < length; ++i) {
        PRINTF("%u ", *(p + i));
    }
    PRINTF("\\n");
#endif
}
