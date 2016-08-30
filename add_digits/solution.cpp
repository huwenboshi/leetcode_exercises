#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num-9*((num-1)/9);
    }
};

int main() {
    Solution sol;
    cout << sol.addDigits(38) << endl;
}
