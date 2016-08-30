#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *ptr1 = head;
        for(int i=1; i<m-1; i++, ptr1=ptr1->next);
        ListNode *ptr2 = ptr1->next;
        ListNode *ptr3 = ptr2->next;
        ListNode *ptr4 = ptr3->next;
        for(int i=m; i<n; i++) {
            ptr3->next = ptr2;
            ptr3 = ptr4;
            ptr4 = ptr4->next;
        }
        ptr3->next = ptr2;
        ptr1->next = ptr3;
        return head;
    }
};

void print_list(ListNode* head) {
    while(head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main() {
    ListNode one(1);
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    ListNode five(5);
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    print_list(&one);
    cout << endl;
    Solution sol;
    print_list(sol.reverseBetween(&one, 2, 4));
}
