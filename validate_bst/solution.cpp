#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode* root, int* lower_bound, int* upper_bound) {
    if(root == NULL) return true;
    
    int lower_bound_left, upper_bound_left, lower_bound_right, upper_bound_right;
    bool bst_left = helper(root->left, &lower_bound_left, &upper_bound_left);
    bool bst_right = helper(root->right, &lower_bound_right, &upper_bound_right);
    
    if((root->right && root->val >= lower_bound_right) || (root->left && root->val <= upper_bound_left))
        return false;
    
    *upper_bound = root->right == NULL ? root->val : upper_bound_right;
    *lower_bound = root->left == NULL ? root->val : lower_bound_left;
    
    return bst_left && bst_right;
}

bool isValidBST(struct TreeNode* root) {
    int lower_bound, upper_bound;
    return helper(root, &lower_bound, &upper_bound);
}

int main() {
    struct TreeNode* zero = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* neg = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    
    neg->val = 1;
    neg->left = NULL;
    neg->right = NULL;

    zero->val = 1;
    zero->left = neg;
    zero->right = NULL;

    printf("%d\n", isValidBST(zero));
}
