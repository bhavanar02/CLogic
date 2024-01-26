#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Start from the rightmost digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            // If the digit is less than 9, simply increment it and return the result
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        } else {
            // If the digit is 9, set it to 0 and continue with the next digit
            digits[i] = 0;
        }
    }
    
    // If all digits were 9, we need to add a new digit with value 1
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 0; i < digitsSize; i++) {
        result[i + 1] = digits[i];
    }
    
    *returnSize = digitsSize + 1;
    return result;
}