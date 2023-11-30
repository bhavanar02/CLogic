#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* resArray = (int*)malloc(2 * sizeof(int));
    int bhavana = 2;
    returnSize = &bhavana;
    for (int i = 0; i <= numsSize; i++)
    {
        for (int j = i + 1; j <= numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                resArray[0] = i;
                resArray[1] = j;
                return resArray;
            }
        }
    }

}

int main(void)
{
    int nums[] = {3, 2, 4, 6};
    int arrCnt = 0;
    int* answer = twoSum(nums, 4, 8, &arrCnt);
    for (int i = 0; i <= 1; i++)
    {
        printf("%d", answer[i]);
    }
    printf("%d", arrCnt);
}