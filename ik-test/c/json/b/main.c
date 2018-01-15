#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_CASE_NUM   10000
#define LENGTH          10000000

static int hash(int h) {
    h ^= (h >> 20) ^ (h >> 12);
    return h ^ (h >> 7) ^ (h >> 4);
}

static int indexFor(int h, int length) {
    return h & (length-1);
}

long long get_cycle_count();
inline long long get_cycle_count() {
    long long hi, lo;  
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));  
    return ( (long long)lo)|( ((long long)hi)<<32 ); 
}  

int main()
{
    //计算key的hash值
    int hash_value;
    //计算key hash 值在 table 数组中的位置
    int index;

    for (int i = 0; i < TEST_CASE_NUM; i++)
    {
        //srand(time(NULL)); //use current time as seed for random generator
        long long time = get_cycle_count();
        srand(time); //use current time as seed for random generator
        int random_variable = rand();
        //printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
        hash_value = hash(random_variable);
        index = indexFor(hash_value, LENGTH);
        
        //printf("0x%x\t0x%x\t0x%x\n", random_variable, hash_value, index);

        int ddd = random_variable % LENGTH;
        printf("x%x\n", ddd);
    }

    return 0;
}
