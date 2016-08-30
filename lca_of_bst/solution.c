#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *lca = root;
    struct TreeNode *p_next, *q_next;;
    while(lca != NULL) {
        if(p->val > lca->val)
            p_next = lca->right;
        else if(p->val == lca->val)
            p_next = lca;
        else 
            p_next = lca->left;
        if(q->val > lca->val)
            q_next = lca->right;
        else if(q->val == lca->val)
            q_next = lca;
        else
            q_next = lca->left;
        if(p_next != q_next)
            return lca;
        lca = p_next;
    }
    return lca;
}

int main() {
    struct TreeNode* six = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* two = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* eight = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* zero = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* four = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* seven = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* nine = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* three = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    struct TreeNode* five = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    six->val = 6;
    six->left = two;
    six->right = eight;
    
    two->val = 2;
    two->left = zero;
    two->right = four;

    eight->val = 8;
    eight->left = seven;
    eight->right = nine;

    zero->val = 0;
    zero->left = NULL;
    zero->right = NULL;

    four->val = 4;
    four->left = three;
    four->right = five;

    seven->val = 7;
    seven->left = NULL;
    seven->right = NULL;

    nine->val = 9;
    nine->left = NULL;
    nine->right = NULL;

    three->val = 3;
    three->left = NULL;
    three->right = NULL;

    five->val = 5;
    five->left = NULL;
    five->right = NULL;

    struct TreeNode* ans_node = lowestCommonAncestor(six,three,five);
    if(ans_node != NULL) {
        printf("%d\n", ans_node->val);
    }
    else {
        printf("NULL\n");
    }
}
