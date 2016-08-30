#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum = nums[0];
        int ret_val = nums[0];

        for(int i=1; i<nums.size(); i++) {
           int tmp = max_sum+nums[i];
           max_sum = nums[i]>tmp ? nums[i] : tmp;
           ret_val = ret_val > max_sum ? ret_val : max_sum;
        }

        return ret_val;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(5);
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
}
