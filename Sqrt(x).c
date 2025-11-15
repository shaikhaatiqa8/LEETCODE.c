int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    
    int left = 1, right = x;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // To avoid overflow, use division instead of multiplication
        if (mid <= x / mid) {
            result = mid;      // mid is a potential answer
            left = mid + 1;    // try for a larger number
        } else {
            right = mid - 1;   // try for a smaller number
        }
    }
    
    return result;
}

// Test examples
#include <stdio.h>

int main() {
    printf("sqrt(4) = %d\n", mySqrt(4));  // Output: 2
    printf("sqrt(8) = %d\n", mySqrt(8));  // Output: 2
    printf("sqrt(1) = %d\n", mySqrt(1));  // Output: 1
    printf("sqrt(0) = %d\n", mySqrt(0));  // Output: 0
    printf("sqrt(16) = %d\n", mySqrt(16)); // Output: 4
    return 0;
}
