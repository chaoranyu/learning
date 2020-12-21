#include <stdio.h>

// Notice: The sequence of phototypes and definations are different.
// Priority values up to and including 100 are reserved for internal use.
void my_constructor_last(void) __attribute__((constructor(65535)));
void my_constructor3(void) __attribute__((constructor()));
void my_constructor2(void) __attribute__((constructor(65535)));
void my_constructor1(void) __attribute__((constructor(101))); // priority 65535

void my_destructor_last(void) __attribute__((destructor(65535)));
void my_destructor3(void) __attribute__((destructor()));
void my_destructor2(void) __attribute__((destructor(65535)));
void my_destructor1(void) __attribute__((destructor(101))); // priority 65535

void my_constructor1(void)  /* This is the 1st constructor */
{                           /* function to be called */
    printf("Called my_constructor1((101))\n");
}

void my_constructor2(void)  /* This is the 2nd constructor */
{                           /* function to be called */
    printf("Called my_constructor2(65535)\n");
}

void my_constructor3(void)  /* This is the 3rd constructor */
{                           /* function to be called */
    printf("Called my_constructor3()\n");
}

void my_constructor_last(void)  /* This is the last constructor */
{                               /* function to be called */
    printf("Called my_constructor_last(65535)\n");
}

void my_destructor1(void)  /* This is the reverse 1st destructor */
{                          /* function to be called */
    printf("Called my_destructor1((101))\n");
}

void my_destructor2(void)  /* This is the reverse 2nd destructor */
{                          /* function to be called */
    printf("Called my_destructor2(65535)\n");
}

void my_destructor3(void)  /* This is the reverse 3rd destructor */
{                          /* function to be called */
    printf("Called my_destructor3()\n");
}

void my_destructor_last(void)  /* This is reverse the last destructor */
{                              /* function to be called */
    printf("Called my_destructor_last(65535)\n");
}

int main(void)
{
    printf("Called main()\n");
}

