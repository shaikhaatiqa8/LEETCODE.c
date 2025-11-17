#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to perform postorder traversal recursively
void postorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    
    // Traverse left subtree
    postorderHelper(root->left, result, index);
    // Traverse right subtree
    postorderHelper(root->right, result, index);
    // Visit root
    result[(*index)++] = root->val;
}

// Function to get the size of the tree
int getTreeSize(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = getTreeSize(root);
    int* result = (int*)malloc(*returnSize * sizeof(int));
    
    int index = 0;
    postorderHelper(root, result, &index);
    
    return result;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Test the code
int main() {
    // Create the tree from example: [1,null,2,3]
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);
    
    int returnSize;
    int* result = postorderTraversal(root, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");
    
    // Expected output: [3,2,1]
    
    // Free memory
    free(result);
    
    // Free tree nodes
    free(root->right->left);
    free(root->right);
    free(root);
    
    return 0;
}
