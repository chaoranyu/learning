#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t current;
    uint32_t previous;
    uint32_t updated;
} random_key_t;

typedef struct {
    random_key_t random_key;
    uint32_t timestamp;
} syn_cookie_t;

static syn_cookie_t g_syn_cookie = {0x2017, 0x0, 0x0321, 0};

main()
{
    printf("0x%x\t0x%x\t0x%x\t0x%x\n", g_syn_cookie.random_key.current, g_syn_cookie.random_key.previous, g_syn_cookie.random_key.updated, g_syn_cookie.timestamp); 

}
