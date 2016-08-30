#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        for(int sq_tot=n; sq_tot != 1; n=sq_tot, seen.insert(n)) {
            for(sq_tot=0; n>0; sq_tot += (n%10)*(n%10), n /= 10);
            if(seen.find(sq_tot) != seen.end())
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(2) << endl;
    cout << sol.isHappy(20) << endl;
    cout << sol.isHappy(19) << endl;
}
