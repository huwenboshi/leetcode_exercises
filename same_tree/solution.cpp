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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q != NULL) {
            return false;
        }
        if(p != NULL && q == NULL) {
            return false;
        }
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p->val != q->val) {
            return false;
        }
        bool is_left_same = isSameTree(p->left, q->left);
        bool is_right_same = isSameTree(p->right, q->right);
        return is_left_same && is_right_same;
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

    TreeNode *q1 = new TreeNode(1);
    TreeNode *q2 = new TreeNode(2);
    TreeNode *q3 = new TreeNode(3);
    TreeNode *q4 = new TreeNode(4);
    TreeNode *q5 = new TreeNode(5);

    q1->left = q2;
    q1->right = q3;
    q2->left = q4;
    q3->right = q5;

    Solution sol;
    cout << sol.isSameTree(p1, q1) << endl;

}
