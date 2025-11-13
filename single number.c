#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    
    // XOR all numbers in the array
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    
    return result;
}

// Alternative solution (same approach, different variable naming)
int singleNumberAlternative(int* nums, int numsSize) {
    int single = 0;
    
    for (int i = 0; i < numsSize; i++) {
        single = single ^ nums[i];
    }
    
    return single;
}

int main() {
    // Test case 1: Example from problem
    int nums1[] = {2, 2, 1};
    int size1 = 3;
    printf("Input: [2, 2, 1]\n");
    printf("Output: %d\n\n", singleNumber(nums1, size1));
    
    // Test case 2: Example from problem
    int nums2[] = {4, 1, 2, 1, 2};
    int size2 = 5;
    printf("Input: [4, 1, 2, 1, 2]\n");
    printf("Output: %d\n\n", singleNumber(nums2, size2));
    
    // Test case 3: Single element
    int nums3[] = {5};
    int size3 = 1;
    printf("Input: [5]\n");
    printf("Output: %d\n\n", singleNumber(nums3, size3));
    
    // Test case 4: Larger array
    int nums4[] = {1, 3, 5, 3, 1, 7, 5};
    int size4 = 7;
    printf("Input: [1, 3, 5, 3, 1, 7, 5]\n");
    printf("Output: %d\n\n", singleNumber(nums4, size4));
    
    // Test case 5: Negative numbers
    int nums5[] = {-1, -1, -2, 3, 3};
    int size5 = 5;
    printf("Input: [-1, -1, -2, 3, 3]\n");
    printf("Output: %d\n\n", singleNumber(nums5, size5));
    
    // Test case 6: Mixed numbers
    int nums6[] = {10, 20, 30, 20, 10};
    int size6 = 5;
    printf("Input: [10, 20, 30, 20, 10]\n");
    printf("Output: %d\n\n", singleNumber(nums6, size6));
    
    return 0;
}
