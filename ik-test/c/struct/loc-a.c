#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t current;
    uint32_t previous;
    uint32_t updated;
} random_key_t;

static random_key_t g_key = {0x2017, 0x0629, 0};

int main()
{
    printf("0x%x\n", g_key.current); 

    return 0;
}
