#include <string>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, bool> record;
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(wordDict.find(s) != wordDict.end())
            return true;
        for(int i=0; i<s.size()-1; i++) {
            string left_half = s.substr(0, i+1);
            string right_half = s.substr(i+1, s.size()-i-1);
            bool left_ok, right_ok;
            if(record.find(left_half) != record.end())
                left_ok = record[left_half];
            else {
                left_ok = wordBreak(left_half, wordDict);
                record[left_half] = left_ok;
            }
            if(record.find(right_half) != record.end())
                right_ok = record[right_half];
            else {
                right_ok = wordBreak(right_half, wordDict);
                record[right_half] = right_ok;
            }
            if(left_ok && right_ok)
                return true;
        }
        return false;
    }
};

int main() {
    unordered_set<string> wdict;
    wdict.insert("leet");
    wdict.insert("code");
    Solution sol;
    cout << sol.wordBreak("leetcode", wdict) << endl;
}
