#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return a>b ? a : b;
    }
    int rob(vector<int> &num) {
        int cur_val_rob = 0;
        int cur_val_skip = 0;
        for(int i=0; i<num.size(); i++) {
            int new_val_rob = cur_val_skip + num[i];
            int new_val_skip = max(cur_val_rob, cur_val_skip);
            cur_val_rob = new_val_rob;
            cur_val_skip = new_val_skip;
        }
        return max(cur_val_rob, cur_val_skip);
    }
};

int main() {
    vector<int> num(3,0);
    num[0] = 1;
    num[1] = 3;
    num[2] = 1;
    
    Solution sol;
    cout << sol.rob(num) << endl;
}
