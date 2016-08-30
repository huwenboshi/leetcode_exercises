#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int helper(TreeNode *root, int parent) {
        if(root == NULL) {
            return 0;
        }

        int cur = parent*10+root->val;
        int sum = helper(root->left, cur)+helper(root->right, cur);

        return sum == 0 ? cur : sum;
    }
    int sumNumbers(TreeNode *root) {
        return helper(root, 0);
    }
};

int main() {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution sol;
    cout << sol.sumNumbers(n1) << endl;
}
