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
    bool helper(TreeNode *root, int &depth_left, int &depth_right) {
        if(root == NULL) {
            depth_left = depth_right = 0;
            return true;
        }

        int left_dl, left_dr;
        bool left_balanced = helper(root->left, left_dl, left_dr);

        int right_dl, right_dr;
        bool right_balanced = helper(root->right, right_dl, right_dr);

        depth_left = left_dl>left_dr ? 1+left_dl : 1+left_dr;
        depth_right = right_dl>right_dr ? 1+right_dl : 1+right_dr;

        int diff = depth_left-depth_right;
        diff = diff < 0 ? -diff : diff;
        
        return left_balanced && right_balanced && diff <= 1;
    }
    bool isBalanced(TreeNode *root) {
        int depth_left, depth_right;
        return helper(root, depth_left, depth_right);
    }
};

int main() {

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t4->left = t6;
    t4->right = t7;

    Solution sol;
    cout << sol.isBalanced(NULL) << endl;
}
