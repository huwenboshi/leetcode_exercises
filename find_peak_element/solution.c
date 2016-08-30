#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize) {
    int idx, low = 0, high = numsSize-1;
    while(low <= high) {
        idx = (high+low)/2;
        if(numsSize == 1)
            return 0;
        if(idx == 0 && nums[idx] > nums[idx+1])
            return idx;
        if(idx == numsSize-1 && nums[idx] > nums[idx-1])
            return idx;
        if((idx > 0 && nums[idx] < nums[idx+1] && nums[idx] > nums[idx-1]) || 
           (idx == 0 && nums[idx] < nums[idx+1]))
            low = idx+1;
        else if((idx < numsSize-1 && nums[idx] > nums[idx+1] && nums[idx] < nums[idx-1]) || 
                (idx >= numsSize-1 && nums[idx] < nums[idx-1]))
            high = idx-1;
        else if(idx > 0 && idx < numsSize-1 && nums[idx] < nums[idx+1] && nums[idx] < nums[idx-1])
            low = idx+1;
        else
            return idx;
    }
    return idx;
}

int main() {
    int nums[] = {2,1,2};
    int peak = findPeakElement(nums, 3);
    printf("%d\n", peak);
}
