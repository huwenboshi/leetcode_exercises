#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("abccce");
    strs.push_back("abdfdfdf");
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
}
