#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0) {
            return "";
        }
        string title = "";
        while(n > 0) {
            n -= 1;
            char digit = 'A' + n % 26;
            title = digit+title;
            n /= 26;
        }
        return title;
    }
};

int main() {
    Solution sol;
    cout << sol.convertToTitle(52) << endl;
}
