#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_list(struct ListNode* head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *ptr1=head, *ptr2=head->next, *ptr3=head->next->next;
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

bool isPalindrome(struct ListNode* head) {
    int length = 0;
    struct ListNode *ptr = head;
    while(ptr != NULL) {
        length += 1;
        ptr = ptr->next;
    }
    if(length <= 1) {
        return true;
    }
    struct ListNode *first_half = head;
    ptr = head;
    for(int i=0; i<length/2-1; i++) {
        ptr = ptr->next;
    }
    struct ListNode *second_half = ptr->next;
    if(length % 2 != 0) {
        second_half = second_half->next;
    }
    ptr->next = NULL;
    second_half = reverseList(second_half);
    while(first_half != NULL && second_half != NULL) {
        if(first_half->val != second_half->val) {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
}



int main() {
    struct ListNode one; one.val = 1;
    struct ListNode two; two.val = 2;
    struct ListNode three; three.val = 3;
    struct ListNode four; four.val = 4;
    struct ListNode three2; three2.val = 3;
    struct ListNode two2; two2.val = 2;
    struct ListNode one2; one2.val = 1;
    one.next = &two;
    //two.next = &three;
    two.next = NULL;
    three.next = &four;
    four.next = &three2;
    three2.next = &two2;
    two2.next = &one2;
    one2.next = NULL;
    print_list(&one);
    printf("%d\n", isPalindrome(&one));
}
