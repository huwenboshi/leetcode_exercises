#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int val = 0;
        int pow = 1;
        
        for(int i=s.size()-1; i>=0; i--) {
            val += pow*(s[i]-'A'+1);
            pow *= 26;
        }

        return val;
    }
};

int main() {
    Solution sol;
    cout << sol.titleToNumber("AB") << endl;
}
