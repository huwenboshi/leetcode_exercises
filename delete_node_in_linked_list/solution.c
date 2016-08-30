#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    for(; node->next->next != NULL; node->val=node->next->val, node=node->next);
    node->val = node->next->val;
    node->next = NULL;
}

void print_list(struct ListNode* node) {
    struct ListNode* ptr = node;
    while(ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}

int main() {
    struct ListNode *one = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *two = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *three = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *four = (struct ListNode*) malloc(sizeof(struct ListNode));
    one->val = 1;
    two->val = 2;
    three->val = 3;
    four->val = 4;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;
    print_list(one);
    printf("\n");
    deleteNode(one);
    print_list(one);
}
