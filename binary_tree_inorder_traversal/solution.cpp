#include <vector>
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
    void helper(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans; 
    }
};

int main() {
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    one.right = &two;
    two.left = &three;
    Solution sol;
    vector<int> ans = sol.inorderTraversal(&one);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
