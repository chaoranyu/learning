#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_CASE_NUM   15000000
#define LENGTH          0x1000000

//#define TEST_CASE_NUM   1048000
//#define LENGTH          0x100000

int indexFor(int h);
int indexFor2(int h);

inline int indexFor(int h) {
    h ^= (h >> 20) ^ (h >> 12);
    h ^= (h >> 7) ^ (h >> 4);
    return h & (LENGTH-1);
}
inline int indexFor2(int h) {
    h % (LENGTH-3);
}

long long get_cycle_count();
inline long long get_cycle_count() {
    long long hi, lo;  
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));  
    return ( (long long)lo)|( ((long long)hi)<<32 ); 
}  

void test_1();
void test_2a();
void test_2b();

int main()
{
//    test_1();
    test_2a();
    test_2b();

    return 0;
}

void test_1()
{
    int index;

    for (int i = 0; i < TEST_CASE_NUM; i++)
    {
        //srand(time(NULL)); //use current time as seed for random generator
        long long time = get_cycle_count();
        srand(time); //use current time as seed for random generator
        int random_variable = rand();
        //printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
        index = indexFor(random_variable);
        
        //printf("0x%x\t0x%x\t0x%x\n", random_variable, hash_value, index);
        //fprintf(stderr, "0x%x\t0x%x\t0x%x\n", random_variable, hash_value, index);
        fprintf(stderr, "%u\n", index);
        //fprintf(stderr, "0x%x\n", index);

        index = indexFor2(random_variable);
        fprintf(stdout, "%u\n", index);
    }
}

void test_2a()
{
    int index;
    int random_variable = 0x01020304;

    long long start = get_cycle_count();

    for (int i = 0; i < TEST_CASE_NUM; i++)
    {
        index = indexFor(random_variable);
    }

    long long end = get_cycle_count();
    printf("%llu\n", end-start);
}

void test_2b()
{
    int index;
    long long time = get_cycle_count();
    int random_variable = 0x04040404;

    long long start = get_cycle_count();

    for (int i = 0; i < TEST_CASE_NUM; i++)
    {
        index = indexFor2(random_variable);
    }

    long long end = get_cycle_count();
    printf("%llu\n", end-start);
}
