#include <stdio.h>
#include <string.h>

// Method 1: Using standard library function
int strStr(char* haystack, char* needle) {
    char* result = strstr(haystack, needle);
    if (result == NULL) {
        return -1;
    }
    return result - haystack;
}

// Method 2: Manual implementation
int strStrManual(char* haystack, char* needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);
    
    // Edge cases
    if (needleLen == 0) return 0;
    if (haystackLen < needleLen) return -1;
    
    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i;
        }
    }
    
    return -1;
}

// Method 3: Using pointer arithmetic
int strStrPointer(char* haystack, char* needle) {
    if (*needle == '\0') return 0;
    
    char* h = haystack;
    char* n = needle;
    
    while (*h != '\0') {
        char* h_temp = h;
        char* n_temp = n;
        
        while (*n_temp != '\0' && *h_temp == *n_temp) {
            h_temp++;
            n_temp++;
        }
        
        if (*n_temp == '\0') {
            return h - haystack;
        }
        
        h++;
    }
    
    return -1;
}

void testCases() {
    printf("Find the Index of the First Occurrence in a String\n");
    printf("==================================================\n\n");
    
    // Test cases
    struct TestCase {
        char* haystack;
        char* needle;
        int expected;
    } testCases[] = {
        {"sadbutsad", "sad", 0},
        {"leetcode", "leeto", -1},
        {"hello", "ll", 2},
        {"aaaaa", "bba", -1},
        {"", "", 0},
        {"abc", "", 0},
        {"", "a", -1},
        {"mississippi", "issip", 4},
        {"a", "a", 0},
        {"abc", "abcd", -1}
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        char* haystack = testCases[i].haystack;
        char* needle = testCases[i].needle;
        int expected = testCases[i].expected;
        
        int result1 = strStr(haystack, needle);
        int result2 = strStrManual(haystack, needle);
        int result3 = strStrPointer(haystack, needle);
        
        printf("Test Case %d:\n", i + 1);
        printf("Haystack: \"%s\"\n", haystack);
        printf("Needle: \"%s\"\n", needle);
        printf("Expected: %d\n", expected);
        printf("Results - Library: %d, Manual: %d, Pointer: %d\n", 
               result1, result2, result3);
        
        // Verification
        if (result1 == expected && result2 == expected && result3 == expected) {
            printf("✓ All methods correct\n");
        } else {
            printf("✗ Some method failed\n");
        }
        
        // Additional explanation
        if (result1 != -1) {
            printf("Explanation: \"%s\" found at index %d in \"%s\"\n", 
                   needle, result1, haystack);
            
            // Show the string with highlighting
            printf("Visual: ");
            for (int j = 0; haystack[j] != '\0'; j++) {
                if (j >= result1 && j < result1 + strlen(needle)) {
                    printf("[%c]", haystack[j]);
                } else {
                    printf("%c", haystack[j]);
                }
            }
            printf("\n");
        } else {
            printf("Explanation: \"%s\" not found in \"%s\"\n", needle, haystack);
        }
        printf("\n");
    }
}

void interactiveMode() {
    printf("=== Interactive Mode ===\n");
    printf("Enter haystack and needle to find first occurrence\n");
    printf("Enter 'exit' for haystack to quit\n");
    
    char haystack[1000];
    char needle[1000];
    
    while (1) {
        printf("\nHaystack: ");
        if (scanf("%s", haystack) != 1) break;
        
        if (strcmp(haystack, "exit") == 0) break;
        
        printf("Needle: ");
        if (scanf("%s", needle) != 1) break;
        
        int result = strStrManual(haystack, needle);
        
        printf("Input: haystack = \"%s\", needle = \"%s\"\n", haystack, needle);
        printf("Output: %d\n", result);
        
        if (result != -1) {
            printf("Found at index %d\n", result);
            
            // Visual representation
            printf("String: ");
            for (int i = 0; haystack[i] != '\0'; i++) {
                if (i >= result && i < result + strlen(needle)) {
                    printf("[%c]", haystack[i]);
                } else {
                    printf("%c", haystack[i]);
                }
            }
            printf("\n");
            
            // Position indicator
            printf("Index:  ");
            for (int i = 0; haystack[i] != '\0'; i++) {
                if (i == result) {
                    printf("^");
                } else {
                    printf(" ");
                }
            }
            printf(" (starts at position %d)\n", result);
        } else {
            printf("Needle not found in haystack\n");
        }
    }
}

int main() {
    printf("FIND THE INDEX OF THE FIRST OCCURRENCE IN A STRING\n");
    printf("==================================================\n\n");
    
    // Run test cases
    testCases();
    
    // Run interactive mode
    interactiveMode();
    
    return 0;
}
