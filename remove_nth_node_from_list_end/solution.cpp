#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* l) {
    while(l) {
        cout << l->val << endl;
        l = l->next;
    }
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for(int i=0; i<n-1; i++) {
            ptr2 = ptr2->next;
        }
        while(ptr2->next) {
            ptr0 = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2 = ptr1->next;
        if(ptr0 == NULL) {
            return ptr2;
        }
        ptr0->next = ptr2;

        return head;
    }
};

int main() {
    ListNode l(1);
    l.next = new ListNode(2);
    l.next->next = new ListNode(3);
    l.next->next->next = new ListNode(4);
    l.next->next->next->next = new ListNode(5);
    print_list(&l);
    cout << endl;
    Solution sol;
    print_list(sol.removeNthFromEnd(&l, 5));
}
