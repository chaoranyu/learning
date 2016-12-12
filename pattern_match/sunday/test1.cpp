#include <iostream>
#include <cstring>
using namespace std;

int sunday(const char* src, const char* des)
{
	int n, m, i, j;
	n = strlen(src);
	m = strlen(des);
	int *next = new int[256];
	for (i = 0; i < 256; i++)
		next[i] = m + 1;
	for (i = 0; i < m; i++)
		next[(unsigned char)des[i]] = m - i;

	for (i = 0; i < n - m + 1;)
	{
		for (j = 0; j < m; j++)
			if (src[i+j] != des[j])
				break;
		if (j == m)
			return i; // delete next[];
		i += next[(unsigned char)src[i+m]];
	}

	return -1;
}
int main()
{
	char src[] = "abcdacdaahfacabcdabcdeaa";
	char des[] = "abcde";
	cout << sunday(src, des) << endl;
	return 0;
}
