#include <stdio.h>

void *myfunction() {
    static int x = 5;
    return (void *)&x;
}

int main() {
    printf("%p\n", myfunction());
    return 0;
}
