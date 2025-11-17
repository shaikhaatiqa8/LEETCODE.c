#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return 0;   // no path possible

    // subtract current node's value from target
    targetSum -= root->val;

    // If it's a leaf node, check if final sum becomes 0
    if (root->left == NULL && root->right == NULL)
        return targetSum == 0;

    // Otherwise check left or right subtree
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
}
