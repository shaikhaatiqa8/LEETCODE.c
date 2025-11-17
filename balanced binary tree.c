#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function: returns height if subtree is balanced, otherwise -1
int checkHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;   // left subtree not balanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;   // right subtree not balanced

    // If height difference > 1 → NOT balanced
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // return height of subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function to check if tree is balanced
int isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}
