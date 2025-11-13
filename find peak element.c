#include <stdio.h>

// Binary search solution - O(log n) time complexity
int findPeakElement(int* nums, int numsSize) {
    if (numsSize == 1) return 0;
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is a peak
        int leftNeighbor = (mid > 0) ? nums[mid - 1] : -__INT_MAX__;
        int rightNeighbor = (mid < numsSize - 1) ? nums[mid + 1] : -__INT_MAX__;
        
        if (nums[mid] > leftNeighbor && nums[mid] > rightNeighbor) {
            return mid;
        }
        
        // If left neighbor is greater, search left half
        if (mid > 0 && nums[mid - 1] > nums[mid]) {
            right = mid - 1;
        }
        // Else search right half
        else {
            left = mid + 1;
        }
    }
    
    return -1; // Should never reach here for valid input
}

// Linear scan solution - O(n) time complexity (for reference)
int findPeakElementLinear(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int left = (i > 0) ? nums[i - 1] : -__INT_MAX__;
        int right = (i < numsSize - 1) ? nums[i + 1] : -__INT_MAX__;
        
        if (nums[i] > left && nums[i] > right) {
            return i;
        }
    }
    return -1;
}

// Helper function to print array
void printArray(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if (i < numsSize - 1) printf(", ");
    }
    printf("]");
}

int main() {
    // Test case 1: Example from problem
    int nums1[] = {1, 2, 3, 1};
    int size1 = 4;
    printf("Input: ");
    printArray(nums1, size1);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums1, size1));
    printf("Peak value: %d\n\n", nums1[findPeakElement(nums1, size1)]);
    
    // Test case 2: Multiple peaks
    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    int size2 = 7;
    printf("Input: ");
    printArray(nums2, size2);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums2, size2));
    printf("Peak value: %d\n\n", nums2[findPeakElement(nums2, size2)]);
    
    // Test case 3: Single element
    int nums3[] = {5};
    int size3 = 1;
    printf("Input: ");
    printArray(nums3, size3);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums3, size3));
    printf("Peak value: %d\n\n", nums3[findPeakElement(nums3, size3)]);
    
    // Test case 4: Two elements - increasing
    int nums4[] = {1, 2};
    int size4 = 2;
    printf("Input: ");
    printArray(nums4, size4);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums4, size4));
    printf("Peak value: %d\n\n", nums4[findPeakElement(nums4, size4)]);
    
    // Test case 5: Two elements - decreasing
    int nums5[] = {2, 1};
    int size5 = 2;
    printf("Input: ");
    printArray(nums5, size5);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums5, size5));
    printf("Peak value: %d\n\n", nums5[findPeakElement(nums5, size5)]);
    
    // Test case 6: All same elements (any index is valid)
    int nums6[] = {3, 3, 3, 3};
    int size6 = 4;
    printf("Input: ");
    printArray(nums6, size6);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums6, size6));
    printf("Peak value: %d\n\n", nums6[findPeakElement(nums6, size6)]);
    
    // Test case 7: Strictly increasing
    int nums7[] = {1, 2, 3, 4, 5};
    int size7 = 5;
    printf("Input: ");
    printArray(nums7, size7);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums7, size7));
    printf("Peak value: %d\n\n", nums7[findPeakElement(nums7, size7)]);
    
    // Test case 8: Strictly decreasing
    int nums8[] = {5, 4, 3, 2, 1};
    int size8 = 5;
    printf("Input: ");
    printArray(nums8, size8);
    printf("\n");
    printf("Peak element index: %d\n", findPeakElement(nums8, size8));
    printf("Peak value: %d\n\n", nums8[findPeakElement(nums8, size8)]);
    
    return 0;
}
