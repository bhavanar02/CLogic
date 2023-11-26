#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize)
{
    int* cntArray = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++)
    {
        cntArray[i] = getElementCount(nums, numsSize, nums[i]);
    }

    int temp = 0;
    int tempIndex = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (cntArray[i] > temp)
        {
            temp = cntArray[i];
            tempIndex = i;
        }
    }

    free(cntArray); 
    return nums[tempIndex];
}

int getElementCount(int* nums, int numsSize, int elem)
{
    int cnt = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == elem)
        {
            cnt++;
        }
    }

    return cnt;
}

int main(void)
{
    int nums[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = majorityElement(nums, numsSize);
    printf("%d\n", res);

    return 0;
}
