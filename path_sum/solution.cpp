#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) {
            return false;
        }
        if(root->left == NULL && root->right == NULL && sum == root->val) {
            return true;
        }
        else if(root->left==NULL && root->right==NULL && sum != root->val) {
            return false;
        }

        bool has_left = hasPathSum(root->left, sum-root->val);
        bool has_right = hasPathSum(root->right, sum-root->val);

        return has_left || has_right;
    }
};

int main() {
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(8);
    TreeNode *n4 = new TreeNode(11);
    TreeNode *n5 = new TreeNode(13);
    TreeNode *n6 = new TreeNode(14);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(2);
    TreeNode *n9 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->right = n9;

    Solution sol;
    cout << sol.hasPathSum(NULL, 0) << endl;
}
