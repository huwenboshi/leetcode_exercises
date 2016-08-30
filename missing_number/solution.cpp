#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numSize) {
    int i, total = 0;
    for(i=0; i<numSize; total += nums[i], i++);
    return (nums[numSize-1]==numSize ? nums[numSize-1] : numSize)*(numSize+1)/2-total;
}

int main() {
    int* nums = (int*) malloc(3*sizeof(int));
    nums[0] = 0; nums[1] = 1; nums[2] = 3;
    int miss = missingNumber(nums, 3);
    printf("%d\n", miss);
}
