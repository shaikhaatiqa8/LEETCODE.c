#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Counter for elements not equal to val
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}

int main() {
    // Test case 1
    int nums1[] = {3, 2, 2, 3};
    int val1 = 3;
    int numsSize1 = 4;
    
    int k1 = removeElement(nums1, numsSize1, val1);
    
    printf("Test case 1:\n");
    printf("k = %d\n", k1);
    printf("Modified array: ");
    for (int i = 0; i < k1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n\n");
    
    // Test case 2
    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int numsSize2 = 8;
    
    int k2 = removeElement(nums2, numsSize2, val2);
    
    printf("Test case 2:\n");
    printf("k = %d\n", k2);
    printf("Modified array: ");
    for (int i = 0; i < k2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");
    
    return 0;
}
