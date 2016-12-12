#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int count = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[count++] = nums[i];
        }
    }

    while(count < numsSize) {
        nums[count++] = 0;
    }
}


int main()
{
    int numsSize = 7;
    int nums[7] = {4, 0, 5, 6, 0, 0, 8};
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    moveZeroes(nums, numsSize);
    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");


	return 0;
}
