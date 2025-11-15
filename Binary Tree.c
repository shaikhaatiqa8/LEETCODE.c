#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    // First, calculate the size of the tree
    int getSize(struct TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }
    
    int size = getSize(root);
    int* result = (int*)malloc(size * sizeof(int));
    *returnSize = 0;
    
    // Recursive inorder traversal
    void traverse(struct TreeNode* node) {
        if (node == NULL) return;
        
        traverse(node->left);           // Visit left subtree
        result[(*returnSize)++] = node->val;  // Visit root
        traverse(node->right);          // Visit right subtree
    }
    
    traverse(root);
    return result;
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
    // Create the tree: [1, null, 2, 3]
    //     1
    //      \
    //       2
    //      /
    //     3
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);
    
    int returnSize;
    int* result = inorderTraversal(root, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");  // Expected: [1, 3, 2]
    
    // Free memory
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);
    
    return 0;
}
