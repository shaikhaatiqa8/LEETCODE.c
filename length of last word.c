#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;
    
    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    
    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    
    return length;
}

// Alternative method using pointer arithmetic
int lengthOfLastWord2(char* s) {
    int len = 0;
    char* p = s + strlen(s) - 1;
    
    // Skip trailing spaces
    while (p >= s && *p == ' ') {
        p--;
    }
    
    // Count last word length
    while (p >= s && *p != ' ') {
        len++;
        p--;
    }
    
    return len;
}

void testCases() {
    printf("Length of Last Word - Test Cases\n");
    printf("================================\n\n");
    
    // Test cases
    char* testStrings[] = {
        "Hello World",
        "   fly me   to   the moon  ",
        "luffy is still joyboy",
        "a",
        "  abc  ",
        "  hello world  ",
        "single",
        "",
        "    ",
        "multiple    spaces   between   words"
    };
    
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);
    
    for (int i = 0; i < numTests; i++) {
        int result = lengthOfLastWord(testStrings[i]);
        printf("Input: \"%s\"\n", testStrings[i]);
        printf("Output: %d\n", result);
        
        // Additional explanation
        if (strlen(testStrings[i]) == 0) {
            printf("Explanation: Empty string\n");
        } else if (result > 0) {
            // Find and display the actual last word
            char* str = testStrings[i];
            int len = strlen(str);
            int end = len - 1;
            
            // Skip trailing spaces
            while (end >= 0 && str[end] == ' ') end--;
            
            int start = end;
            while (start >= 0 && str[start] != ' ') start--;
            
            // Extract last word for display
            char lastWord[100];
            strncpy(lastWord, &str[start + 1], end - start);
            lastWord[end - start] = '\0';
            
            printf("Explanation: The last word is \"%s\" with length %d\n", lastWord, result);
        } else {
            printf("Explanation: No words found\n");
        }
        printf("\n");
    }
}

void interactiveMode() {
    printf("=== Interactive Mode ===\n");
    printf("Enter strings to find length of last word (or 'exit' to quit):\n");
    
    char input[1000];
    getchar(); // Clear input buffer
    
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "exit") == 0) break;
        
        int result = lengthOfLastWord(input);
        printf("Input: \"%s\"\n", input);
        printf("Output: %d\n", result);
        
        if (result > 0) {
            // Find and display the actual last word
            int len = strlen(input);
            int end = len - 1;
            
            // Skip trailing spaces
            while (end >= 0 && input[end] == ' ') end--;
            
            int start = end;
            while (start >= 0 && input[start] != ' ') start--;
            
            // Extract last word for display
            char lastWord[100];
            strncpy(lastWord, &input[start + 1], end - start);
            lastWord[end - start] = '\0';
            
            printf("The last word is \"%s\" with length %d\n", lastWord, result);
        } else {
            printf("No words found in the string\n");
        }
        printf("\n");
    }
}

int main() {
    // Run test cases
    testCases();
    
    // Run interactive mode
    interactiveMode();
    
    return 0;
}
