#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_keep = 0;
        int max_skip = 0;
        int largest = nums[0];

        bool all_neg = true;


        for(int i=0; i<nums.size(); i++) {

            int tmp = nums[i]+max_keep;
            int max_keep_new = nums[i]>tmp ? nums[i] : tmp;
            int max_skip_new = max_keep>max_skip ? max_keep : max_skip;
            
            max_keep = max_keep_new;
            max_skip = max_skip_new;

            if(nums[i] > largest) {
                largest = nums[i];
            }
            if(nums[i] > 0) {
                all_neg = false;
            }
        }

        if(all_neg) {
            return largest;
        }

        return max_keep>max_skip ? max_keep : max_skip;
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
