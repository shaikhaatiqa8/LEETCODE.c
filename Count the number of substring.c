#include <stdio.h>
#include <string.h>

int countSubstringsWithDominantOnes(char* s) {
    int n = strlen(s);
    int count = 0;
    
    // Try all possible substrings
    for (int i = 0; i < n; i++) {
        int ones = 0, zeros = 0;
        
        for (int j = i; j < n; j++) {
            // Update counts based on current character
            if (s[j] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            // Check if this substring has dominant ones
            if (ones >= zeros * zeros) {
                count++;
            }
        }
    }
    
    return count;
}

// Test with the example
int main() {
    char s[] = "00011";
    int result = countSubstringsWithDominantOnes(s);
    printf("Output: %d\n", result); // Should print 5
    return 0;
}
