#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        
        // Check for overflow before actually multiplying
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        
        reversed = reversed * 10 + digit;
    }
    
    return reversed;
}

// Test the function
int main() {
    // Test cases
    printf("reverse(123) = %d\n", reverse(123));      // Output: 321
    printf("reverse(-123) = %d\n", reverse(-123));    // Output: -321
    printf("reverse(120) = %d\n", reverse(120));      // Output: 21
    printf("reverse(0) = %d\n", reverse(0));          // Output: 0
    printf("reverse(1534236469) = %d\n", reverse(1534236469)); // Output: 0 (overflow)
    
    return 0;
}
