#include <stdio.h>

int rob(int* nums, int numsSize) {
    if(numsSize == 1) {
        return nums[0];
    }

    int cur_rob_fore = 0;
    int cur_skip_fore = 0;
    for(int i=0; i<numsSize-1; i++) {
        int new_rob_fore = cur_skip_fore+nums[i];
        int new_skip_fore = cur_rob_fore>cur_skip_fore ? cur_rob_fore : cur_skip_fore;
        cur_rob_fore = new_rob_fore;
        cur_skip_fore = new_skip_fore;
    }
    int max_fore = cur_rob_fore>cur_skip_fore ? cur_rob_fore : cur_skip_fore;

    int cur_rob_back = 0;
    int cur_skip_back = 0;
    for(int i=1; i<numsSize; i++) {
        int new_rob_back = cur_skip_back+nums[i];
        int new_skip_back = cur_rob_back>cur_skip_back ? cur_rob_back : cur_skip_back;
        cur_rob_back = new_rob_back;
        cur_skip_back = new_skip_back;
    }
    int max_back = cur_rob_back>cur_skip_back ? cur_rob_back : cur_skip_back;
    
    return max_fore>max_back ? max_fore : max_back;
}

int main() {
    int nums[5];
    nums[0] = 5;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 7;
    printf("%d\n", rob(nums, 5));
}
