#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int i, j;
    for(i=0, j=0; j<numsSize; j++) {
        if(nums[i] != nums[j]) {
            i = i+1;
            nums[i] = nums[j];
        }
    }
    return (i+1)>j ? j : (i+1);
}

int main() {
    int nums[] = {1,2,3,4,5};
    int new_size = removeDuplicates(nums, 5);
    for(int i=0; i<new_size; i++) {
        printf("%d\n", nums[i]);
    }
}
