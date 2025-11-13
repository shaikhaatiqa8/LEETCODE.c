#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Start from the last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    
    // If we're here, it means all digits were 9 (e.g., 999 -> 1000)
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = 0;
    }
    return result;
}

// Helper function to print array
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]");
}

int main() {
    // Test case 1: [1,2,3] -> [1,2,4]
    int digits1[] = {1, 2, 3};
    int size1 = 3;
    int returnSize1;
    
    int* result1 = plusOne(digits1, size1, &returnSize1);
    
    printf("Input: ");
    printArray(digits1, size1);
    printf("\nOutput: ");
    printArray(result1, returnSize1);
    printf("\n\n");
    
    // Test case 2: [4,3,2,1] -> [4,3,2,2]
    int digits2[] = {4, 3, 2, 1};
    int size2 = 4;
    int returnSize2;
    
    int* result2 = plusOne(digits2, size2, &returnSize2);
    
    printf("Input: ");
    printArray(digits2, size2);
    printf("\nOutput: ");
    printArray(result2, returnSize2);
    printf("\n\n");
    
    // Test case 3: [9,9,9] -> [1,0,0,0]
    int digits3[] = {9, 9, 9};
    int size3 = 3;
    int returnSize3;
    
    int* result3 = plusOne(digits3, size3, &returnSize3);
    
    printf("Input: ");
    printArray(digits3, size3);
    printf("\nOutput: ");
    printArray(result3, returnSize3);
    printf("\n\n");
    
    // Free allocated memory
    if (result1 != digits1) free(result1);
    if (result2 != digits2) free(result2);
    if (result3 != digits3) free(result3);
    
    return 0;
}
