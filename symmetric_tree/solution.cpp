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
    bool helper(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) return true;
        if(node1 == NULL && node2 != NULL) return false;
        if(node1 != NULL && node2 == NULL) return false;
        if(node1->val != node2->val) return false;
        return (helper(node1->left, node2->right) &&
                helper(node1->right, node2->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left, root->right);
    }
};

int main() {
    TreeNode one(1), two_left(2), two_right(2),
             three_left(3), three_right(3),
             four_left(4), four_right(4);
    one.left = &two_left;
    one.right = &two_right;
    two_left.left = &three_left;
    two_left.right = &four_left;
    two_right.left = &four_right;
    two_right.right = &three_right;
    Solution sol;
    cout << sol.isSymmetric(&one) << endl;
}
