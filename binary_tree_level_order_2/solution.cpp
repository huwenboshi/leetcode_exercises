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
    void helper(const vector<TreeNode*> &cur_level,
            vector<vector<int> > &all_level_vals) {
        if(cur_level.size() == 0) {
            return;
        }

        vector<int> cur_level_vals;
        vector<TreeNode*> next_level;
        for(int i=0; i<cur_level.size(); i++) {
            if(cur_level[i] != NULL) {
                cur_level_vals.push_back(cur_level[i]->val);
                next_level.push_back(cur_level[i]->left);
                next_level.push_back(cur_level[i]->right);
            }
        }

        helper(next_level, all_level_vals);

        if(cur_level_vals.size() > 0) {
            all_level_vals.push_back(cur_level_vals);
        }
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > all_level_vals;
        vector<TreeNode*> cur_level;
        cur_level.push_back(root);
        helper(cur_level, all_level_vals);
        return all_level_vals;
    }
};

int main() {
    
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n20 = new TreeNode(20);
    TreeNode *n15 = new TreeNode(15);
    TreeNode *n7 = new TreeNode(7);

    n3->left = n9;
    n3->right = n20;
    n20->left = n15;
    n20->right = n7;

    Solution sol;
    vector<vector<int> > levels = sol.levelOrderBottom(n3);
    for(int i=0; i<levels.size(); i++) {
        for(int j=0; j<levels[i].size(); j++) {
            cout << levels[i][j] << " ";
        }
        cout << endl;
    }
}
