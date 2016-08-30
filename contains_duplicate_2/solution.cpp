#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> num_pos;
        for(int i=0; i<nums.size(); i++) {
            if(num_pos.find(nums[i]) == num_pos.end())
                num_pos[nums[i]] = i;
            else {
                if(i-num_pos[nums[i]] <= k)
                    return true;
                num_pos[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int array[] = {1,2,3,4,2,5};
    vector<int> nums(array, array+6);
    cout << sol.containsNearbyDuplicate(nums, 7) << endl;;
}
