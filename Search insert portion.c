#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

int main() {
    // Test cases
    int nums1[] = {1, 3, 5, 6};
    int size1 = 4;
    int target1 = 5;
    printf("Array: [1, 3, 5, 6], Target: %d -> Position: %d\n", target1, searchInsert(nums1, size1, target1));
    
    int target2 = 2;
    printf("Array: [1, 3, 5, 6], Target: %d -> Position: %d\n", target2, searchInsert(nums1, size1, target2));
    
    int target3 = 7;
    printf("Array: [1, 3, 5, 6], Target: %d -> Position: %d\n", target3, searchInsert(nums1, size1, target3));
    
    int target4 = 0;
    printf("Array: [1, 3, 5, 6], Target: %d -> Position: %d\n", target4, searchInsert(nums1, size1, target4));
    
    return 0;
}
