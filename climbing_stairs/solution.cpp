#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) {
            return 0;
        }
        int s1 = 0;
        int s2 = 1;
        for(int i=0; i<n-1; i++) {
            int tmp = s2;
            s2 = s1 + s2;
            s1 = tmp;
        }
        return s1+s2;
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairs(0) << endl;
}
