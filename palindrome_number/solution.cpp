#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int xin) {
        long long int x = xin;
        if(x < 0) {
            return false;
        }
        long long int x_tmp = x;
        long long int num_digit = 0;
        while(x_tmp > 0) {
            x_tmp /= 10;
            num_digit++;
        }
        long long int pow = 1;
        for(int i=0; i<num_digit-1; i++) {
            pow *= 10;
        }
        for(int i=0; i<num_digit/2; i++) {
            int digit_low = x % 10;
            int digit_high = x/pow;

            if(digit_low != digit_high) {
                return false;
            }
            x = (x-digit_high*pow-digit_low)/10;
            pow /= 100;
        }
        return true;
    }
};

int main() {
    Solution sol;
    //cout << sol.isPalindrome(5521255) << endl;
    cout << sol.isPalindrome(-2147483648) << endl;
}
