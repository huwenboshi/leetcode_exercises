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
    int minDepth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int min_left = minDepth(root->left);
        int min_right = minDepth(root->right);

        if(root->left == NULL) {
            return 1+min_right;
        }
        else if(root->right == NULL) {
            return 1+min_left;
        }
        return min_left < min_right ? 1+min_left : 1+min_right;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);

    p1->left = p2;
    //p1->right = p3;
    //p2->left = p4;
    //p3->right = p5;

    Solution sol;
    cout << sol.minDepth(p1) << endl;

}
