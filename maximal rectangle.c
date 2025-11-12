#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to print matrix
void printMatrix(char** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate maximum area in histogram
int largestRectangleArea(int* heights, int size) {
    int* stack = (int*)malloc(size * sizeof(int));
    int top = -1;
    int maxArea = 0;
    
    for (int i = 0; i <= size; i++) {
        int currentHeight = (i == size) ? 0 : heights[i];
        
        while (top != -1 && currentHeight < heights[stack[top]]) {
            int height = heights[stack[top]];
            top--;
            
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            
            if (area > maxArea) {
                maxArea = area;
            }
        }
        stack[++top] = i;
    }
    
    free(stack);
    return maxArea;
}

// Main function to find maximal rectangle
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    
    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int));
    int maxArea = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        // Update heights array
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        
        // Calculate maximum area for current histogram
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    free(heights);
    return maxArea;
}

int main() {
    // Test case 1
    int rows = 3, cols = 5;
    char** matrix1 = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (char*)malloc(cols * sizeof(char));
    }
    
    // Initialize matrix with example values
    char data1[3][5] = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'}
    };
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = data1[i][j];
        }
    }
    
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, cols);
    
    int colSize1 = cols;
    int result1 = maximalRectangle(matrix1, rows, &colSize1);
    printf("Maximal Rectangle Area: %d\n\n", result1);
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    
    // Test case 2 - Single row
    rows = 1, cols = 5;
    char** matrix2 = (char**)malloc(rows * sizeof(char*));
    matrix2[0] = (char*)malloc(cols * sizeof(char));
    
    char data2[1][5] = {{'1','0','1','1','1'}};
    for (int j = 0; j < cols; j++) {
        matrix2[0][j] = data2[0][j];
    }
    
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows, cols);
    
    int colSize2 = cols;
    int result2 = maximalRectangle(matrix2, rows, &colSize2);
    printf("Maximal Rectangle Area: %d\n\n", result2);
    
    free(matrix2[0]);
    free(matrix2);
    
    // Test case 3 - Empty matrix
    rows = 0, cols = 0;
    char** matrix3 = NULL;
    int colSize3 = 0;
    int result3 = maximalRectangle(matrix3, rows, &colSize3);
    printf("Empty Matrix - Maximal Rectangle Area: %d\n", result3);
    
    return 0;
}
