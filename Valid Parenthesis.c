#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10000

bool isValid(char* s) {
    int len = strlen(s);
    // If string length is odd, it can't be valid
    if (len % 2 != 0) return false;
    
    char stack[MAX_SIZE];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        // If it's an opening bracket, push to stack
        if (current == '(' || current == '[' || current == '{') {
            // Check stack overflow
            if (top >= MAX_SIZE - 1) return false;
            stack[++top] = current;
        }
        // If it's a closing bracket
        else if (current == ')' || current == ']' || current == '}') {
            // If stack is empty, invalid
            if (top == -1) return false;
            
            char topChar = stack[top--];
            
            // Check if the closing bracket matches the last opening bracket
            if (current == ')' && topChar != '(') return false;
            if (current == ']' && topChar != '[') return false;
            if (current == '}' && topChar != '{') return false;
        }
    }
    
    // If stack is empty, all brackets were properly matched
    return top == -1;
}

// Test function
void testCases() {
    printf("Valid Parentheses Test Cases\n");
    printf("============================\n\n");
    
    char* testCases[] = {
        "()", "()[]{}", "(]", "([)]", "{[]}", "", "((()))", "([{}])", "(((",
        ")))", "([])", "{[()]}", "([)]", "{{{{}}}}", "[(])"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        bool result = isValid(testCases[i]);
        printf("Input: \"%s\"\n", testCases[i]);
        printf("Output: %s\n", result ? "true" : "false");
        printf("\n");
    }
}

// Interactive version
void interactiveMode() {
    printf("=== Interactive Mode ===\n");
    printf("Enter strings to check for valid parentheses (or 'exit' to quit):\n");
    
    char input[1000];
    
    while (1) {
        printf("> ");
        if (scanf("%s", input) != 1) break;
        
        if (strcmp(input, "exit") == 0) break;
        
        bool result = isValid(input);
        printf("Input: \"%s\"\n", input);
        printf("Output: %s\n", result ? "true" : "false");
        
        if (result) {
            printf("✓ Valid parentheses\n");
        } else {
            printf("✗ Invalid parentheses\n");
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
