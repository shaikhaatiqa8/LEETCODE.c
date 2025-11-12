#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;      // Last element of nums1 (actual data)
    int j = n - 1;      // Last element of nums2
    int k = m + n - 1;  // Last position of nums1 (including space)
    
    // Merge from the end to avoid overwriting
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
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
    // Test case 1
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int m = 3, n = 3;
    
    printf("Before merging:\n");
    printf("nums1: "); printArray(nums1, m+n); printf("\n");
    printf("nums2: "); printArray(nums2, n); printf("\n");
    
    merge(nums1, 6, m, nums2, 3, n);
    
    printf("After merging:\n");
    printf("Result: "); printArray(nums1, m+n); printf("\n\n");
    
    // Test case 2
    int nums3[] = {4,5,6,0,0,0};
    int nums4[] = {1,2,3};
    m = 3, n = 3;
    
    printf("Before merging:\n");
    printf("nums1: "); printArray(nums3, m+n); printf("\n");
    printf("nums2: "); printArray(nums4, n); printf("\n");
    
    merge(nums3, 6, m, nums4, 3, n);
    
    printf("After merging:\n");
    printf("Result: "); printArray(nums3, m+n); printf("\n\n");
    
    // Test case 3 (nums2 empty)
    int nums5[] = {1,2,3};
    int nums6[] = {};
    m = 3, n = 0;
    
    printf("Before merging:\n");
    printf("nums1: "); printArray(nums5, m+n); printf("\n");
    printf("nums2: []\n");
    
    merge(nums5, 3, m, nums6, 0, n);
    
    printf("After merging:\n");
    printf("Result: "); printArray(nums5, m+n); printf("\n");
    
    return 0;
}
