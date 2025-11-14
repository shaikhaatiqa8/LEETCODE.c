#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }
    
    // Single digit numbers are always palindromes
    if (x >= 0 && x < 10) {
        return true;
    }
    
    long long reversed = 0;
    int original = x;
    
    // Reverse the number
    while (x > 0) {
        reversed = reversed * 10 + (x % 10);
        x = x / 10;
    }
    
    // Check if reversed number equals original
    return (reversed == original);
}

int main() {
    // Test cases
    int test_cases[] = {121, -121, 10, 0, 12321, 12345, 9999, -101, 1234321};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Palindrome Number Check\n");
    printf("======================\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        int num = test_cases[i];
        bool result = isPalindrome(num);
        
        printf("Input: x = %d\n", num);
        printf("Output: %s\n", result ? "true" : "false");
        
        if (num >= 0) {
            printf("Explanation: %d reads as %d from left to right and ", num, num);
            if (result) {
                printf("from right to left.\n");
            } else {
                printf("%d from right to left. Therefore it is not a palindrome.\n", num);
            }
        } else {
            printf("Explanation: From left to right, it reads %d. ", num);
            printf("From right to left, it becomes %d-. Therefore it is not a palindrome.\n", -num);
        }
        printf("\n");
    }
    
    // Interactive version
    printf("=== Interactive Mode ===\n");
    printf("Enter a number to check if it's a palindrome (or -999 to exit): ");
    
    int user_input;
    while (scanf("%d", &user_input) == 1) {
        if (user_input == -999) {
            break;
        }
        
        bool result = isPalindrome(user_input);
        printf("Input: x = %d\n", user_input);
        printf("Output: %s\n", result ? "true" : "false");
        
        if (user_input >= 0) {
            if (result) {
                printf("✓ %d is a palindrome\n", user_input);
            } else {
                printf("✗ %d is not a palindrome\n", user_input);
            }
        } else {
            printf("✗ %d is not a palindrome (negative numbers are not palindromes)\n", user_input);
        }
        
        printf("\nEnter another number (or -999 to exit): ");
    }
    
    return 0;
}
