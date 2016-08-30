#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            int val = digits[i]+carry;
            if(i == digits.size()-1)
                val += 1;
            ans.insert(ans.begin(), val%10);
            carry = val/10>0 ? 1 : 0;
        }
        if(carry > 0) {
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};

int main() {
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    Solution sol;
    vector<int> ans = sol.plusOne(digits);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
