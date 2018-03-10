#include <stdio.h>

int removeDuplicates(int nums[], int size) {
    if (size == 0) return 0;

    int i = 0;
    int j = 1;
    for (; j < size; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main()
{
    int nums[32] = { 0, 0, 1, 2, 3, 3 }; /* sorted array */
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    int n = removeDuplicates(nums, 6);

    for (i = 0; i < n; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    return 0;
}
