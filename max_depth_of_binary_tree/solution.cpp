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
    int maxDepth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);

        return max_left > max_right ? 1+max_left : 1+max_right;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->right = p5;

    Solution sol;
    cout << sol.maxDepth(p1) << endl;

}
