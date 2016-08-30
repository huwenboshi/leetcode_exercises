#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int ptr1 = 0;
        int ptr2 = 1;
        while(ptr2 < nums.size()+1) {
            if(ptr2 < nums.size() && nums[ptr2]-nums[ptr2-1] == 1) {
                ptr2++;
            }
            else {
                char tmp[25];
                sprintf(tmp, "%d", nums[ptr1]);
                string st(tmp);
                sprintf(tmp, "%d", nums[ptr2-1]);
                string ed(tmp);
                if(st == ed) {
                    ranges.push_back(st);
                }
                else {
                    ranges.push_back(st+"->"+ed);
                }
                ptr1 = ptr2;
                ptr2++;
            }
        }
        
        return ranges;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    Solution sol;
    vector<string> ans = sol.summaryRanges(nums);
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
