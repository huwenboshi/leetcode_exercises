#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> char_map1;
        unordered_map<char,char> char_map2;
        for(int i=0; i<s.size(); i++) {
            if(char_map1.find(s[i]) == char_map1.end())
                char_map1[s[i]] = t[i];
            else if(char_map1[s[i]] != t[i])
                return false;
            if(char_map2.find(t[i]) == char_map2.end())
                char_map2[t[i]] = s[i];
            else if(char_map2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("egg", "add") << endl;
    cout << sol.isIsomorphic("foor", "bar") << endl;
    cout << sol.isIsomorphic("paper", "title") << endl;
    cout << sol.isIsomorphic("ab", "aa") << endl;
}
