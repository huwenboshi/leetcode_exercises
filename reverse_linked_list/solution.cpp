#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *ptr1=head, *ptr2=head->next, *ptr3=head->next->next;
        ptr1->next = NULL;
        while(ptr3 != NULL) {
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3->next;
        }
        ptr2->next = ptr1;
        return ptr2;
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
    one.next = &two;
    two.next = &three;
    print_list(&one);
    cout << endl;
    Solution sol;
    print_list(sol.reverseList(&one));
}
