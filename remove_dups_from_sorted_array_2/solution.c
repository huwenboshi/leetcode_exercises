#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int i=0, j=0, buf=2;
    for(; j<numsSize; j++) {
        if(nums[i] != nums[j]) {
            i += 1;
            nums[i] = nums[j];
            buf = 2;
        }
        if(nums[i] == nums[j]) {
            buf -= 1;
            if(buf == 0) {
                i += 1;
                nums[i] = nums[i-1];
            }
        }
    }
    return (i+1)>j ? j : (i+1);
}

int main() {
    int nums[] = {1,1,1,1,3,3};
    int new_size = removeDuplicates(nums, 6);
    for(int i=0; i<new_size; i++) {
        printf("%d\n", nums[i]);
    }
}
