#include <stdio.h>

typedef struct {
    int first;
    int second;
} pair_t;
pair_t random_key = {.first = 0x3333, .second = 0x6666};
//random_key.first = 0x3333;
//random_key.second = 0x6666;

//void print();
static void print();

void print() {
    printf("hello\n");
    printf("0x%x, 0x%x\n", random_key.first, random_key.second);
}
