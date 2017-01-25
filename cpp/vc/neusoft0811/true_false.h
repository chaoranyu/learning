#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void tt();
void test26();

typedef struct tagLIST_t
{
	struct tagLIST_t *pNext;
	unsigned short element;
	unsigned char flag;
	unsigned long value;
}LIST_t;

typedef struct tagLIST2_t
{
	struct tagLIST2_t *pNext;
	unsigned long value;
	unsigned short element;
	unsigned char flag;
}LIST2_t;

typedef struct tagLIST3_t
{
	struct tagLIST3_t *pNext;
	unsigned short element;
	unsigned long value;
	unsigned char flag;
}LIST3_t;
