#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, bool &have_p, bool &have_q, TreeNode **ans) {
        if(root == NULL)
            return;
       
        bool have_p_left = false, have_q_left = false;
        helper(root->left, p, q, have_p_left, have_q_left, ans);
        
        bool have_p_right = false, have_q_right = false;
        helper(root->right, p, q, have_p_right, have_q_right, ans);
        
        have_p = have_p_left || have_p_right || root == p;
        have_q = have_q_left || have_q_right || root == q;

        if(have_p && have_q && *ans == NULL)
            *ans = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool have_p = false, have_q = false;
        TreeNode* ans = NULL;
        helper(root, p, q, have_p, have_q, &ans);
        return ans;
    }
};

int main() {
    TreeNode* six = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* two = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* eight = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* zero = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* four = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* seven = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* one = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* three = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* five = (TreeNode*) malloc(sizeof(TreeNode));
   
    zero->val = 0;
    one->val = 1;
    two->val = 2;
    three->val = 3;
    four->val = 4;
    five->val = 5;
    six->val = 6;
    seven->val = 7;
    eight->val = 8;

    three->left = five; three->right = one;
    five->left = six; five->right = two;
    one->left = zero; one->right = eight;
    six->left = NULL; six->right = NULL;
    two->left = seven; two->right = four;
    zero->left = NULL; zero->right = NULL;
    eight->left = NULL; eight->right = NULL;
    seven->left = NULL; seven->right = NULL;
    four->left = NULL; four->right = NULL;

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(three, four, six);
    cout << lca->val << endl;
}
