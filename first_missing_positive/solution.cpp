#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int tot = 0, min_val = nums[0], max_val = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > 0) {
                max_val = nums[i]>max_val ? nums[i] : max_val;
                min_val = nums[i]<min_val ? nums[i] : min_val;
                tot += nums[i];
            }
        }
        int 
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(0);
    cout << sol.firstMissingPositive(nums1) << endl;
    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(-1);
    nums2.push_back(1);
    cout << sol.firstMissingPositive(nums2) << endl;

}
