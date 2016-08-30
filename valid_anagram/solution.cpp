#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26];
        for(int i=0; i<26; i++) record[i] = 0;
        for(int i=0; i<s.size(); i++) record[s[i]-'a']++;
        for(int i=0; i<t.size(); i++) record[t[i]-'a']--;
        for(int i=0; i<26; i++) if(record[i] !=0) return false;
        return true;
    }
};

int main() {
   Solution sol;
    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("rat", "car") << endl;
}
