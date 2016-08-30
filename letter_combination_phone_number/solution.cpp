#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> digit_alpha;
    Solution() {
        digit_alpha.push_back("");
        digit_alpha.push_back("");
        digit_alpha.push_back("abc");
        digit_alpha.push_back("def");
        digit_alpha.push_back("ghi");
        digit_alpha.push_back("jkl");
        digit_alpha.push_back("mno");
        digit_alpha.push_back("pqrs");
        digit_alpha.push_back("tuv");
        digit_alpha.push_back("wxyz");
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) {
            return result;
        }
        if(digits.size() == 1) {
            int num = digits[0]-'0';
            string alphas = digit_alpha[num];
            for(int i=0; i<alphas.size(); i++) {
                string tmp = "";
                tmp += alphas[i];
                result.push_back(tmp);
            }
            return result;
        }
        string sub_str = digits.substr(1,digits.size()-1);
        vector<string> sub_result = letterCombinations(sub_str);
        string cur_str = digit_alpha[digits[0]-'0'];
        if(cur_str.size() == 0) {
            return sub_result;
        }
        for(int i=0; i<cur_str.size(); i++) {
            for(int j=0; j<sub_result.size(); j++) {
                string tmp = sub_result[j];
                tmp = cur_str[i]+tmp;
                result.push_back(tmp);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> result = sol.letterCombinations("13");
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
}
