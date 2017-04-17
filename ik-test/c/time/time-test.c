#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    time_t result;

    result = time(NULL);
    printf("%s%ju secs since the Epoch\n",
        asctime(localtime(&result)),
        (uintmax_t)result);
    return(0);
}
