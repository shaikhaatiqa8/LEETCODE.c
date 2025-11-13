#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    
    // First element is always 1
    row[0] = 1;
    
    // Use the combinatorial formula: C(rowIndex, i) = C(rowIndex, i-1) * (rowIndex - i + 1) / i
    for (int i = 1; i <= rowIndex; i++) {
        // Use long long to avoid integer overflow
        long long value = (long long)row[i - 1] * (rowIndex - i + 1) / i;
        row[i] = (int)value;
    }
    
    return row;
}

// Alternative solution using dynamic programming (more intuitive)
int* getRowDP(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    
    // Initialize all elements to 1
    for (int i = 0; i <= rowIndex; i++) {
        row[i] = 1;
    }
    
    // Build the row from the end to avoid overwriting values we need
    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
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
    int returnSize;
    
    // Test case 1: rowIndex = 3
    printf("Row index 3 (4th row):\n");
    int* result1 = getRow(3, &returnSize);
    printArray(result1, returnSize);
    printf("\n");
    free(result1);
    
    // Test case 2: rowIndex = 0
    printf("Row index 0 (1st row):\n");
    int* result2 = getRow(0, &returnSize);
    printArray(result2, returnSize);
    printf("\n");
    free(result2);
    
    // Test case 3: rowIndex = 1
    printf("Row index 1 (2nd row):\n");
    int* result3 = getRow(1, &returnSize);
    printArray(result3, returnSize);
    printf("\n");
    free(result3);
    
    // Test case 4: row index 4
    printf("Row index 4 (5th row):\n");
    int* result4 = getRow(4, &returnSize);
    printArray(result4, returnSize);
    printf("\n");
    free(result4);
    
    // Test case 5: row index 5
    printf("Row index 5 (6th row):\n");
    int* result5 = getRow(5, &returnSize);
    printArray(result5, returnSize);
    printf("\n");
    free(result5);
    
    return 0;
}
