#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<int,int> str_cnt;
        unordered_set<string> result_set;
        for(int i=0; i<s.size(); i++) {
            if(s.size()-i < 10) break;
            int key = 0;
            for(int j=0; j<10; j++) {
                switch(s[i+j]) {
                    case 'A':
                        key |= 0 << (10-j-1)*2;
                        break;
                    case 'C':
                        key |= 1 << (10-j-1)*2;
                        break;
                    case 'G':
                        key |= 2 << (10-j-1)*2;
                        break;
                    case 'T':
                        key |= 3 << (10-j-1)*2;
                        break;
                }
            }
            if(str_cnt.find(key) == str_cnt.end()) {
                str_cnt[key] = 0;
            }
            str_cnt[key]++;
            if(str_cnt[key] > 1) {
                result_set.insert(s.substr(i,10));
            }
        }
        for(auto it=result_set.begin(); it != result_set.end(); it++) {
            result.push_back(*it);
        }
        return result; 
    }
};

int main() {
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = sol.findRepeatedDnaSequences(s);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
}
