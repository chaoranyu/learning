#include <stdio.h>
#include <pthread.h>

int get_number(int flag)
{
    if (flag)
    {
        static int i = 0;
        i++;
        return i;
    }
    else
    {
        static int i = 0;
        i += 5;
        return i;
    }
}

void *child(void *args)
{
    printf("child: %d\n", get_number(1));
    printf("child: %d\n", get_number(1));

    return (void *)0;
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, child, "CHILD");
    pthread_join(t, NULL);

    printf("parent: %d\n", get_number(1));
    printf("parent: %d\n", get_number(1));

    return 0;
}
