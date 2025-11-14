#include <stdio.h>

// Method 1: Dynamic Programming (Bottom-up)
int climbStairs(int n) {
    if (n <= 2) return n;
    
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// Method 2: Space Optimized (Fibonacci-like)
int climbStairsOptimized(int n) {
    if (n <= 2) return n;
    
    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    
    return second;
}

// Method 3: Recursive with Memoization
int climbHelper(int n, int memo[]) {
    if (n <= 2) return n;
    if (memo[n] != 0) return memo[n];
    
    memo[n] = climbHelper(n - 1, memo) + climbHelper(n - 2, memo);
    return memo[n];
}

int climbStairsMemo(int n) {
    if (n <= 2) return n;
    
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = 0;
    
    return climbHelper(n, memo);
}

void printWays(int n) {
    printf("Ways to climb %d stairs:\n", n);
    
    if (n == 1) {
        printf("1. 1 step\n");
    } else if (n == 2) {
        printf("1. 1 step + 1 step\n");
        printf("2. 2 steps\n");
    } else if (n == 3) {
        printf("1. 1 step + 1 step + 1 step\n");
        printf("2. 1 step + 2 steps\n");
        printf("3. 2 steps + 1 step\n");
    }
}

void testCases() {
    printf("Climbing Stairs - Test Cases\n");
    printf("============================\n\n");
    
    int testCases[] = {1, 2, 3, 4, 5, 6, 10};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int n = testCases[i];
        int result1 = climbStairs(n);
        int result2 = climbStairsOptimized(n);
        int result3 = climbStairsMemo(n);
        
        printf("Input: n = %d\n", n);
        printf("Output: %d\n", result1);
        printf("Methods verification: DP=%d, Optimized=%d, Memo=%d\n", 
               result1, result2, result3);
        
        // Print detailed explanation for small n
        if (n <= 3) {
            printWays(n);
        } else {
            printf("Explanation: There are %d distinct ways to climb to the top.\n", result1);
            printf("Pattern: This follows Fibonacci sequence (F(%d) = F(%d) + F(%d))\n", 
                   n, n-1, n-2);
        }
        printf("\n");
    }
}

void interactiveMode() {
    printf("=== Interactive Mode ===\n");
    printf("Enter number of stairs (1-45, or 0 to exit):\n");
    
    int n;
    while (1) {
        printf("> ");
        if (scanf("%d", &n) != 1) break;
        
        if (n == 0) break;
        
        if (n < 1 || n > 45) {
            printf("Please enter a number between 1 and 45\n");
            continue;
        }
        
        int result = climbStairsOptimized(n);
        printf("Input: n = %d\n", n);
        printf("Output: %d\n", result);
        printf("There are %d distinct ways to climb %d stairs\n\n", result, n);
        
        // Show pattern for understanding
        if (n > 1) {
            printf("Pattern: ways(%d) = ways(%d) + ways(%d) = %d\n", 
                   n, n-1, n-2, result);
        }
    }
}

int main() {
    printf("CLIMBING STAIRS PROBLEM\n");
    printf("=======================\n");
    printf("You are climbing a staircase. It takes n steps to reach the top.\n");
    printf("Each time you can either climb 1 or 2 steps.\n");
    printf("Find how many distinct ways you can climb to the top.\n\n");
    
    // Run test cases
    testCases();
    
    // Run interactive mode
    interactiveMode();
    
    return 0;
}
