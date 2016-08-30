#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *l) {
    ListNode *ptr = l;
    while(ptr) {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}

class Solution {
public:

    ListNode* reverse_list(ListNode *head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;

        ptr1->next = NULL;

        while(ptr2) {
            ListNode *tmp = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
            ptr1->next = tmp;
        }

        return ptr1;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      
        ListNode *l1_rev = l1, *l2_rev = l2;
        ListNode *ans = NULL, *ptr = NULL;
        int carry = 0;
        
        while(l1_rev != NULL || l2_rev != NULL) {
           
            if(ptr == NULL) {
                ptr = new ListNode(0);
                ans = ptr;
            }
            else {
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }

            int digit1 = 0;
            if(l1_rev != NULL) {
                digit1 = l1_rev->val;
                l1_rev = l1_rev->next;
            }

            int digit2 = 0;
            if(l2_rev != NULL) {
                digit2 = l2_rev->val;
                l2_rev = l2_rev->next;
            }

            int sum = digit1 + digit2 + carry;

            if(sum >= 10) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            ptr->val = sum % 10;
        }

        if(carry == 1) {
            ptr->next = new ListNode(1);
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    ListNode l11 = ListNode(1);
    ListNode l12 = ListNode(5);
    //ListNode l13 = ListNode(3);
    l11.next = &l12;
    //l12.next = &l13;
    print_list(&l11);
    cout << endl;

    ListNode l21 = ListNode(2);
    ListNode l22 = ListNode(5);
    //ListNode l23 = ListNode(4);
    l21.next = &l22;
    //l22.next = &l23;
    print_list(&l21);
    cout << endl;

    ListNode *sum = sol.addTwoNumbers(&l11, &l21);
    print_list(sum);
}
