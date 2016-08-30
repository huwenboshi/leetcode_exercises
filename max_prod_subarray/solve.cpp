#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int max3(int a, int b, int c) {
        int tmp = a > b ? a : b;
        return tmp > c ? tmp : c;
    }

    int min3(int a, int b, int c) {
        return -max3(-a, -b, -c);
    }

    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ret_val = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int max_prod_new = max3(nums[i], nums[i]*max_prod, nums[i]*min_prod);
            int min_prod_new = min3(nums[i], nums[i]*min_prod, nums[i]*max_prod);
            max_prod = max_prod_new;
            min_prod = min_prod_new;
            ret_val = ret_val > max_prod ? ret_val : max_prod;
        }

        return ret_val;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    Solution sol;
    cout << sol.maxProduct(nums) << endl;
}
