#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    
    bool isMatch(const char *s, const char *p) {
        
        if(s[0] == '\0' && (p[0] == '*' || p[0] == '\0')) {
            return true;
        }
        else if(s[0] == '\0' && p[0] != '*' && p[0] != '\0')  {
            return false;
        }

        if(p[0] != '?' && p[0] != '*') {
            if(p[0] == s[0]) {
                return isMatch(s+1, p+1);
            }
            return false;
        }
        else if(p[0] == '?') {
            return isMatch(s+1, p+1);
        }
        else if(p[0] == '*') {
            for(int i=0; ; i++) {
                if(isMatch(s+i, p+1)) {
                    return true;
                }
                else {
                    if(s[i] == '\0') {
                        return false;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("ab","a") << endl;
    cout << sol.isMatch("aa","aa") << endl;
    cout << sol.isMatch("aaa","aa") << endl;
    cout << sol.isMatch("aa", "*") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("ab", "?*") << endl;
    cout << sol.isMatch("aab", "c*a*b") << endl;
    cout << sol.isMatch("ab", "*a") << endl;
}
