#include <stdlib.h>
#include <stdio.h>

bool canJump(int* nums, int numsSize) {
    int i, step = nums[0];
    for(i=1; i<numsSize; i++) {
        step--;
        if(step < 0)
            return false;
        step = nums[i]>step ? nums[i] : step;
    }
    return true;
}

int main() {
    int nums[] = {2,3,1,1,4};
    printf("%d\n", canJump(nums, 5));

}
