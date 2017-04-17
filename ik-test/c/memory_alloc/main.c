#include <stdio.h>

#include "ik_memory_allocator.h"

typedef struct test {
    int a;
    int b;
} test_t;

main() {
    /*
    int *p = NULL, *q = NULL;
    init_allocator(9, 4);

    get_buffer(&p);
    get_buffer(&q);
     
    *p = 0x12345678;
    *q = 0x87654321;

    printf("0x%x\t0x%x\n", *p, *q);

    free_buffer(&p);
    free_buffer(&q);
    //printf("0x%x\t0x%x\n", *p, *q);

    get_buffer(&p);
    get_buffer(&q);
    printf("0x%x\t0x%x\n", *p, *q);

    release_allocator();

    */

    test_t *test = NULL;
    init_allocator(3, sizeof(test_t));
    get_buffer(&test);
    test->a = 0x12123434;
    test->b = 0x56567878;
    printf("0x%x\t0x%x\n", test->a, test->b);
    free_buffer(&test);
    release_allocator();/* debug here, print memory */
}
