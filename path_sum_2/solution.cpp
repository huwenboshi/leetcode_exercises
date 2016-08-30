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
    void helper(TreeNode *root, int sum,
            vector<vector<int> > &slns, vector<int> &cur_sln) {
        if(root == NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL && root->val==sum) {
            vector<int> root_sln(cur_sln);
            root_sln.push_back(root->val);
            slns.push_back(root_sln);
            return;
        }
        else if(root->left==NULL && root->right==NULL && root->val!=sum) {
            return;
        }
        cur_sln.push_back(root->val);
        helper(root->left, sum-root->val, slns, cur_sln);
        helper(root->right, sum-root->val, slns, cur_sln);
        cur_sln.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > slns;
        vector<int> cur_sln;
        helper(root, sum, slns, cur_sln);
        return slns;
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
    vector<vector<int> > slns = sol.pathSum(n1, 22);
    for(int i=0; i<slns.size(); i++) {
        for(int j=0; j<slns[i].size(); j++) {
            cout << slns[i][j] << " ";
        }
        cout << endl;
    }
}
