#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int num_char = s.size();
        bool *is_palindrome = new bool[num_char*num_char];
        for(int i=0; i<num_char; i++) {
            is_palindrome[i*num_char+i] = true;
        }
        for(int i=0; i<num_char; i++) {
            for(int j=i; j<num_char; j++) {
                if(j != i) {
                }
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abcbaeabc") << endl;
}
