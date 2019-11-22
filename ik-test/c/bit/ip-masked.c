#include <stdio.h>
#include <stdint.h>

#define VERIFY_DEPTH(depth) do {                                \
    if ((depth == 0) || (depth > 32))                           \
    {                                                           \
        fprintf(stderr, "Invalid depth (%u) at line %d",        \
            (unsigned)(depth), __LINE__);                       \
        return -1;                                              \
    }                                                           \
} while (0)

uint32_t depth_to_mask(uint8_t depth)
{
    VERIFY_DEPTH(depth);

    /* To calculate a mask start with a 1 on the left hand side and right
     *   * shift while populating the left hand side with 1's
     *       */
    return (int)0x80000000 >> (depth - 1);
}

int main()
{
    uint8_t depth = 32;
    for (depth = 1; depth <=32; depth++)
        printf("depth = %u, mask = 0x%x\n", depth, depth_to_mask(depth));

    return 0;
}
