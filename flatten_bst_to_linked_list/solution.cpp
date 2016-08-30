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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* ptr;
        for(ptr=root->left; ptr && ptr->right; ptr=ptr->right);
        if(ptr) {
            ptr->right = root->right;
            ptr->left = NULL;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

int main() {
    TreeNode one(1), two(2), three(3), four(4), five(5), six(6);
    one.left = &two; one.right = &five;
    two.left = &three; two.right = &four;
    five.right = &six;
    Solution sol;
    sol.flatten(&one);
    TreeNode* ptr = &one;
    while(ptr != NULL) {
        cout << ptr->val << endl;
        ptr = ptr->right;
    }
}
