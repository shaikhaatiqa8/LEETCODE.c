#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if two trees are mirror images
int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL)
        return 1;   // both empty, symmetric

    if (left == NULL || right == NULL)
        return 0;   // one is empty, not symmetric

    // values must match AND children must be mirror
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main symmetric check
int isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;  // empty tree is symmetric
    return isMirror(root->left, root->right);
}
