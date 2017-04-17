#include <stdio.h>

static void a();
static void b();

void a()
{
    b();
    printf("func a\n");
}

void b()
{
    printf("func b\n");
}

int main() {
    a();
}
