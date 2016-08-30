#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int atoi(string str) {

        // ignore white space
        int i = 0;
        while(isspace(str[i]) && i<str.size()) {
            i++;
        }

        // return 0 if string has only white spaces
        if(i >= str.size()) {
            return 0;
        }

        // check for sign
        int sign = 1;
        if(str[i] == '-') {
            sign = -1;
            i++;
        }
        else if(str[i] == '+') {
            i++;
        }

        // get as many digits as possible
        int j=i;
        while(isdigit(str[j]) && j<str.size()) {
            j++;
        }
        j--;

        // convert string to number
        int num = 0;
        int pow = sign*1;
        while(j >= i) {
            
            int digit = str[j]-'1'+1;
            int add = digit*pow;
            
            // check overflow
            if(digit != 0 && add/digit != pow) {
                return pow > 0 ? INT_MAX : INT_MIN;
            }

            // check overflow
            if(sign > 0 && add > INT_MAX-num) {
                return INT_MAX;
            }
            else if(sign < 0 && add < INT_MIN-num) {
                return INT_MIN;
            }

            num += add;

            if(j == i) {
                break;
            }
            
            // check overflow
            int next_pow = pow*10;
            if(next_pow/10 != pow) {
                return pow > 0 ? INT_MAX : INT_MIN;
            }
            pow = next_pow;

            // update pointer
            j--;
        }
        
        return num;
    }
};

int main() {
    Solution sol;
    cout << sol.atoi("-2147483647") << endl;
}
