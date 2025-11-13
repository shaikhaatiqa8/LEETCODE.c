#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;
    
    for (int i = 0; i < numRows; i++) {
        // Each row has i+1 elements
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        
        // First and last elements of each row are always 1
        result[i][0] = 1;
        result[i][i] = 1;
        
        // Calculate inner elements for rows beyond the first two
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    
    return result;
}

// Helper function to print Pascal's Triangle
void printPascalTriangle(int** triangle, int numRows, int* columnSizes) {
    for (int i = 0; i < numRows; i++) {
        // Print leading spaces for pyramid shape
        for (int space = 0; space < numRows - i - 1; space++) {
            printf(" ");
        }
        
        // Print elements of the row
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

// Helper function to print in array format
void printAsArray(int** triangle, int numRows, int* columnSizes) {
    printf("[");
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", triangle[i][j]);
            if (j < columnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < numRows - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int numRows;
    int returnSize;
    int* returnColumnSizes;
    
    // Test case 1: 5 rows
    printf("Pascal's Triangle with 5 rows:\n");
    numRows = 5;
    int** result1 = generate(numRows, &returnSize, &returnColumnSizes);
    printPascalTriangle(result1, returnSize, returnColumnSizes);
    printf("\nArray format: ");
    printAsArray(result1, returnSize, returnColumnSizes);
    printf("\n");
    
    // Free memory for test case 1
    for (int i = 0; i < returnSize; i++) {
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes);
    
    // Test case 2: 1 row
    printf("Pascal's Triangle with 1 row:\n");
    numRows = 1;
    int** result2 = generate(numRows, &returnSize, &returnColumnSizes);
    printPascalTriangle(result2, returnSize, returnColumnSizes);
    printf("\nArray format: ");
    printAsArray(result2, returnSize, returnColumnSizes);
    printf("\n");
    
    // Free memory for test case 2
    for (int i = 0; i < returnSize; i++) {
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes);
    
    return 0;
}
