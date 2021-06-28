#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef i32 word;
typedef u32 uword;

typedef struct
{
	u32 len; /**< Number of elements in vector (NOT its allocated length). */
	u8 numa_id; /**< NUMA id */
	u8 vpad[3]; /**< pad to 8 bytes */
	u8 vector_data[0];  /**< Vector data . */
} vec_header_t;

#define _vec_find(v)    ((vec_header_t *) (v) - 1)
#define _vec_len(v) (_vec_find(v)->len)
#define vec_len(v)  ((v) ? _vec_len(v) : 0)

#define _v(var) _vec_##var

#define vec_add(V,E)            \
do {                            \
    word _v(l) = vec_len (V);   \
    V[_v(l)] = (E);             \
    _vec_len(V) += 1;           \
} while(0)

int main()
{
    void *v;
    vec_header_t *vh;
    int *vd, i;

	v = malloc(10 * sizeof(int) + sizeof(vec_header_t));
	if (!v)
	{
	 	printf("malloc failure\n");
		exit(1);
	}

	memset(v, 10 * sizeof(int) + sizeof(vec_header_t), 0);

    vh = (vec_header_t *)v;
    vd = (int *)(vh + 1);

    for (i = 0; i < 10; i++)
        vec_add(vd, i * i * i);

    for (i = 0; i < vec_len(vd); i++)
        printf("%2d  ", vd[i]);
    printf("\n");

    printf("sizeof(vec_header_t) = %lu\n", sizeof(vec_header_t));

    for (i = 0; i < vec_len(vh->vector_data); i++)
        printf("%2d  ", *((int *)vh->vector_data + i));
    printf("\n");

    for (i = 0; i < vec_len(vh->vector_data); i++)
    {
        int n = vh->vector_data[i*4+3] << 24
            | vh->vector_data[i*4+2] << 16
            | vh->vector_data[i*4+1] << 8
            | vh->vector_data[i*4];
        printf("%2d  ",  n);
    }
    printf("\n");

	return 0;
}
