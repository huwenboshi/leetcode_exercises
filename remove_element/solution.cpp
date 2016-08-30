#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    
    int ptr1 = 0;
    int ptr2 = numsSize-1;
    int new_nums_size = numsSize;

    while(1) {
        while(ptr2 >= 0 && nums[ptr2] == val) {
            ptr2--;
            new_nums_size--;
        }
        while(ptr1 <= numsSize-1 && nums[ptr1] != val) {
            ptr1++;
        }
        if(ptr1 >= ptr2) break;
        nums[ptr1] = nums[ptr2];
        nums[ptr2] = val;
    }

    return new_nums_size;
}

int main() {
    int nums[] = {2,2};
    printf("%d\n", removeElement(nums, 2, 3));
    for(int i=0; i<0; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
