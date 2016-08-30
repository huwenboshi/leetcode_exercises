#include <string>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool has_path(vector<vector<bool> >& in_dict, int cur_row,
                  int cur_col, int s_size,
                  vector<vector<bool> >& path_record) {
        for(int i=cur_col; i<s_size; i++)
            if(in_dict[cur_row][i] && i==s_size-1)
                return true;
        for(int i=cur_col; i<s_size; i++) {
            if(in_dict[cur_row][i]) {
                if(has_path(in_dict, i+1, i+1, s_size, path_record)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<bool> > in_dict;
        vector<vector<bool> > path_record;
        for(int i=0; i<s.size(); i++) {
            in_dict.push_back(vector<bool>(s.size(), false));
            path_record.push_back(vector<bool>(s.size(), false));
        }
        for(int i=0; i<s.size(); i++)
            for(int j=i; j<s.size(); j++)
                if(wordDict.find(s.substr(i,j-i+1)) != wordDict.end())
                    in_dict[i][j] = true;
        return has_path(in_dict, 0, 0, s.size(), path_record);
    }
};

int main() {
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    Solution sol;
    cout << sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaab", dict) << endl;
}
