#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Both nodes are NULL - they are the same
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // One is NULL but the other isn't - they are different
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // Values are different - trees are different
    if (p->val != q->val) {
        return false;
    }
    
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Helper function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Test the function
int main() {
    // Test case 1: Same trees [1,2,3]
    struct TreeNode* p1 = newNode(1);
    p1->left = newNode(2);
    p1->right = newNode(3);
    
    struct TreeNode* q1 = newNode(1);
    q1->left = newNode(2);
    q1->right = newNode(3);
    
    printf("Test 1: %s\n", isSameTree(p1, q1) ? "true" : "false"); // Expected: true
    
    // Test case 2: Different structure
    struct TreeNode* p2 = newNode(1);
    p2->left = newNode(2);
    
    struct TreeNode* q2 = newNode(1);
    q2->right = newNode(2);
    
    printf("Test 2: %s\n", isSameTree(p2, q2) ? "true" : "false"); // Expected: false
    
    // Test case 3: Different values
    struct TreeNode* p3 = newNode(1);
    p3->left = newNode(2);
    p3->right = newNode(3);
    
    struct TreeNode* q3 = newNode(1);
    q3->left = newNode(5);  // Different value
    q3->right = newNode(3);
    
    printf("Test 3: %s\n", isSameTree(p3, q3) ? "true" : "false"); // Expected: false
    
    // Test case 4: Both NULL
    printf("Test 4: %s\n", isSameTree(NULL, NULL) ? "true" : "false"); // Expected: true
    
    // Test case 5: One NULL, one not NULL
    struct TreeNode* p5 = newNode(1);
    printf("Test 5: %s\n", isSameTree(p5, NULL) ? "true" : "false"); // Expected: false
    
    // Free memory
    free(p1->left); free(p1->right); free(p1);
    free(q1->left); free(q1->right); free(q1);
    free(p2->left); free(p2);
    free(q2->right); free(q2);
    free(p3->left); free(p3->right); free(p3);
    free(q3->left); free(q3->right); free(q3);
    free(p5);
    
    return 0;
}
