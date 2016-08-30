#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> num_cnt;
        for(int i=0; i<nums.size(); i++) {
            if(num_cnt.find(nums[i]) == num_cnt.end()) {
                num_cnt[nums[i]] = 0;
            }
            num_cnt[nums[i]]++;
            if(num_cnt[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    cout << sol.containsDuplicate(nums) << endl;
}
