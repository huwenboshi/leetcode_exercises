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
    void helper(vector<TreeNode*>& level, bool dir, vector<vector<int> >& ans) {
        if(level.size() == 0)
            return;
        vector<int> level_vals;
        for(int i=0; i<level.size(); i++) {
            if(dir && level[i] != NULL)
                level_vals.push_back(level[i]->val);
            else if(!dir && level[level.size()-1-i] != NULL)
                level_vals.push_back(level[level.size()-1-i]->val);
        }
        if(!level_vals.empty())
            ans.push_back(level_vals);
        vector<TreeNode*> next_level;
        for(int i=0; i<level.size(); i++) {
            if(level[i] != NULL) {
                next_level.push_back(level[i]->left);
                next_level.push_back(level[i]->right);
            }
        }
        helper(next_level, !dir, ans);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        vector<TreeNode*> level;
        level.push_back(root);
        helper(level, true, ans);
        return ans; 
    }
};

int main() {
    TreeNode three(3);
    TreeNode nine(9);
    TreeNode two(20);
    TreeNode five(15);
    TreeNode seven(7);
    three.left = &nine;
    three.right = &two;
    nine.left = &five;
    nine.right = &seven;
    Solution sol;
    vector<vector<int> > ans = sol.zigzagLevelOrder(&three);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
