#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char tolower(char c) {
        if(c < 97) {
            return c+32;
        }
        return c;
    }
    bool isPalindrome(string s) {

        int ptr1 = 0;
        int ptr2 = s.size()-1;

        while(ptr1 <= ptr2) {
            
            // skip non alphas or numerics
            while((!isalpha(s[ptr1]) && !isdigit(s[ptr1]))
                  && ptr1 < s.size()) {
                ptr1++;
            }
            while((!isalpha(s[ptr2]) && !isdigit(s[ptr2]))
                  && ptr2 >= 0) {
                ptr2--;
            }

            if(ptr1 > ptr2) {
                return true;
            }

            // check if equal
            char c1 = tolower(s[ptr1]);
            char c2 = tolower(s[ptr2]);

            if(c1 == c2) {
                ptr1++;
                ptr2--;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;
    cout << sol.isPalindrome("1a2") << endl;
}
