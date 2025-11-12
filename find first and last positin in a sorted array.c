#include <stdio.h>

// Function to find first and last position of target
void searchRange(int* nums, int numsSize, int target, int* result) {
    // Initialize with -1,-1
    result[0] = -1;
    result[1] = -1;
    
    // If array is empty, return [-1,-1]
    if (numsSize == 0) {
        return;
    }
    
    // Find first occurrence
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Check if target exists at left position
    if (left < numsSize && nums[left] == target) {
        result[0] = left;
        
        // Find last occurrence
        right = numsSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[1] = right;
    }
}

int main() {
    // Test case 1
    int nums1[] = {5,7,7,8,8,10};
    int result1[2];
    searchRange(nums1, 6, 8, result1);
    printf("Input: [5,7,7,8,8,10], target=8\n");
    printf("Output: [%d, %d]\n\n", result1[0], result1[1]);
    
    // Test case 2
    int nums2[] = {5,7,7,8,8,10};
    int result2[2];
    searchRange(nums2, 6, 6, result2);
    printf("Input: [5,7,7,8,8,10], target=6\n");
    printf("Output: [%d, %d]\n\n", result2[0], result2[1]);
    
    // Test case 3
    int nums3[] = {};
    int result3[2];
    searchRange(nums3, 0, 0, result3);
    printf("Input: [], target=0\n");
    printf("Output: [%d, %d]\n\n", result3[0], result3[1]);
    
    // Test case 4
    int nums4[] = {1};
    int result4[2];
    searchRange(nums4, 1, 1, result4);
    printf("Input: [1], target=1\n");
    printf("Output: [%d, %d]\n", result4[0], result4[1]);
    
    return 0;
}
