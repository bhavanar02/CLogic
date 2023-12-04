#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i++] = nums[j];
        }
    }

    return i;
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}

int main(void) {
    int nums[] = {3, 2, 1, 7};
    int result = removeElement(nums, 4, 2);
    printArray(nums, result); // Print only the elements up to the new size
    printf("%d", result);

    return 0;
}