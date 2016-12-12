#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main()
{
	int v[10] = {44, 5, 39, 88, 56, 21, 33, 1, 90, 45};
	qsort(v, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%2d ", v[i]);
	printf("\n");
	return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;
	if (left >= right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);

	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
